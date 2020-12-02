#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
# define fr(i,n) for(int i=0;i<n;i++)
# define fr1(i,n) for(int i=1;i<n;i++)
//# define fr2(i,n) for(int i=2;i<n;i++);

using namespace std;

class point
{
public:
    int x,y;
    int index;
};

class Pair
{
public:
    int red_ind;
    int blue_ind;
};


double slope(point a,point b) /**INPUT VERIFIED**/
{
    double ans=(a.y-b.y)/(a.x-b.x);
    return ans;
}

int sign(Pair line,point p,vector <point>* red,vector <point>* blue)
{
    int x=p.x;
    int y=p.y;
    int a=red->at(line.red_ind).x;
    int b=red->at(line.red_ind).y;
    int c=blue->at(line.blue_ind).x;
    int d=blue->at(line.blue_ind).y;

    double temp=((c-a)*(y-b))-((d-b)*(x-a));
    if(temp>0)return 1;
    if(temp<0)return -1;
    return 0;
}


void recurse(vector <point>* red,vector <point>* blue,Pair* &pairs,int &pair_size,int n)
{
    /**red and and blue must contain ONLY those
    points which are there in this reccursion **/
    /**PRECONDITION SIZE OF RED AND BLUE MUST BE SAME**/

    /**BASE CASE**/
    if(red->size()==0)return;

    if(red->size()==1)
    {
        /**pair_size has the total number of pairs computed**/
        pairs[pair_size].red_ind=red->at(0).index;
        pairs[pair_size].blue_ind=blue->at(0).index;
        pair_size++;
        return;
    }


    int rcount,bcount;

    Pair line;
    line.red_ind=0;
    vector <point>* c1red;
    vector <point>* c1blue;
    vector <point>* c2red;
    vector <point>* c2blue;
    c1red=new vector <point>;
    c1blue=new vector <point>;
    c2red=new vector <point>;
    c2blue=new vector <point>;


    fr(i,n)
    {
        c1red->resize(0);
        c2red->resize(0);
        c1blue->resize(0);
        c2blue->resize(0);

        line.blue_ind=i;

        rcount=0;

        fr(j,red->size())
        {
            /**red[0] should not be included in the following**/
            if(j==0)continue;
            if(sign(line,red->at(j),red,blue)>0)
            {
                rcount++;
                c1red->push_back(red->at(j));
            }
            else
            {
                c2red->push_back(red->at(j));
            }
        }


        bcount=0;

        fr(j,blue->size())
        {
            /**blue->at(i) should not be included in the following**/
            if(j==i)continue;

            if(sign(line,blue->at(j),red,blue)>0)
            {
                bcount++;
                c1blue->push_back(blue->at(j));
            }
            else
            {
                c2blue->push_back(blue->at(j));
            }

        }

        if(rcount==bcount)
        {
            pairs[pair_size].red_ind=red->at(0).index;
            pairs[pair_size].blue_ind=blue->at(i).index;
            pair_size++;
            break;
        }

    }
    delete red;
    delete blue;


    recurse(c1red,c1blue,pairs,pair_size,n);
    recurse(c2red,c2blue,pairs,pair_size,n);

    return;
}


int main()
{
    /**DECLARATIONS**/
    int two_n,n,x,y,pair_size;
    //bool done;

    Pair* pairs;
    vector <point>* red;
    vector <point>* blue;
    red=new vector <point>;
    blue=new vector <point>;
    /**INITIALISATIONS**/
    cin>>two_n;
    n=two_n/2;
    red->resize(n);
    blue->resize(n);
    //cout<<n<<endl;
    /**CREATING ARRAY OF RED AND BLUE POINTS**/
    //red=new point[n];
    //blue=new point[n];
    /**CREATING ARRAY FOR STORING THE PAIRS**/
    pairs=new Pair[n];

    /**INPUT OF RED POINTS**/
    fr(i,n)
    {
        cin>>x>>y;
        red->at(i).x=x;
        red->at(i).y=y;
        red->at(i).index=i;
    }

    /**INPUT OF BLUE POINTS**/
    fr(i,n)
    {
        cin>>x>>y;
        blue->at(i).x=x;
        blue->at(i).y=y;
        blue->at(i).index=i;
    }

    /**INPUT VERIFIED**/

    pair_size=0;
    recurse(red,blue,pairs,pair_size,n);

    /**OUTPUT**/
    fr(i,n)
    {
        cout<<pairs[i].red_ind<<" "<<pairs[i].blue_ind<<endl;
    }


    return 0;
}
