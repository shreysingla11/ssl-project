#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct point
{
    int x;
    int y;
    int id;
    char color;
    point()
    {
        x=0;
        y=0;
        color='n';
    }
    point(int xc,int yc,char col,int newid)
    {
        x=xc;
        y=yc;
        color=col;
        id=newid;
    }

};

struct line
{
    point first;
    point second;
    bool slopezero;
    bool slopeinfi;
    line(point f,point s)
    {
        first=f;
        second=s;
        slopezero=false;
        slopeinfi=false;
    }

    bool isaboveorleft(point t)
    {
        if(slopezero)
        {
            if(t.y>first.y)
            {
                return true;
            }
            else
            {
                return true;
            }
        }

        else if(slopeinfi)
        {
            if(t.x<first.x)
            {
                return true;
            }
            else
            {
                return false;
            }

        }
        else
        {
            //float slope=(float)(first.y-second.y)/(first.x-second.x);
            float val= (float)(second.x-first.x)*(t.x-first.x)-(second.y-first.y)*(t.y-first.y);

            if (val>0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
};


void compute(vector<point> &points,vector<int> &a )
{
    //first conside a base case;
    if(points.size()==2)
    {
        //base case this
        //cout<<"points size=2"<<endl;
        a.push_back(points[0].id);
        a.push_back(points[1].id);
       // cout<<"points are at index"<<points[0].id<<"-"<<points[1].id;
        return;
    }
    else if(points.size()==0)
    {
        //endcase
        return;
    }
    else
    {

//fix the first point in points ,x,roll over the rest array  and find if
        vector<point> onleft;
        vector<point> onright;
        bool foundline=false;
        int leninput=points.size();
        //separate the points by a line
        int i=0,j=0;
        for(i=0; i<leninput; i++)
        {
            //first element is the ith posiotion one
            for ( j=i+1; j<leninput; j++)
            {

                point s=points[j];
                //seconf elemnt is jthb element
                point f=points[i];//first point

                int leftreds=0,leftblues=0;
                int rightreds=0,rightblues=0;

                line temp(f,s);
                if(f.x-s.x==0)
                {
                    //cout<<"slope infi"<<endl;
                    temp.slopeinfi=true;
                }
                else if(f.y-s.y==0)
                {
                    //cout<<"slope zero"<<endl;
                    temp.slopezero=true;
                }

                for(int k=0; k<leninput&&(k!=i)&&(k!=j); k++)
                {
                    if(temp.isaboveorleft(points[k]))
                    {
                        if(points[k].color=='R')
                        {
                            leftreds++;
                        }
                        else
                        {
                            leftblues++;
                        }
                       // cout<<"onleft added"<<endl;
                        onleft.push_back(points[k]);
                    }
                    else
                    {
                        if(points[k].color=='R')
                        {
                            rightreds++;
                        }
                        else
                        {
                            rightblues++;
                        }
                       // cout<<"onright added"<<endl;
                        onright.push_back(points[k]);

                    }


                }
                //cout<<"leftblues"<<leftblues<<endl;
               // cout<<"leftreds"<<leftreds<<endl;
                //cout<<"rightblues"<<rightblues<<endl;
                //cout<<"rightreds"<<rightreds<<endl;

                if((leftreds==leftblues&&leftreds!=0)||(rightblues==rightreds&&rightblues!=0))
                {
                    foundline=true;
                    break;
                }
                else
                {
                    onleft.clear();
                    onright.clear();
                }


            }

            if(foundline)
            {
                break;
            }
        }
        if(foundline){
        a.push_back(points[i].id);
        a.push_back(points[j].id);
        compute(onleft,a);//go for next left
       // cout<<"size of onleft="<<onleft.size()<<endl;
       // cout<<"size of on right"<<onright.size()<<endl;
        compute(onright,a);//go for next right
      //  cout<<"points are at index"<<points[i].id<<"-"<<points[j].id<<endl;
        }
        else{
         //   cout<<"no point found"<<endl;
        }
        return;
    }
}


int main()
{
//first take thet input into a vector
    int twon,tempx,tempy;

    cin>>twon;
    vector<point> points;
    for(int i=0; i<twon; i++)
    {
        cin>>tempx>>tempy;
        point t;
        if(i<twon/2)
        {
            t=point(tempx,tempy,'R',i);
        }
        else
        {
            t=point(tempx,tempy,'B',i);
        }
        points.push_back(t);
        //cout<<t.id<<endl;
    }
    vector<int> a;

    compute(points,a);
    //print all the points;
   // cout<<"size of a is"<<a.size()<<endl;
    //cout<<"ansers are as follows"<<endl;
    for(int i=0; i<a.size()/2; i++)
    {
        cout<<a[i]<<" "<<a[i+1]<<endl;
    }
    //input taklejn now desighn the function

    return 0;
}

