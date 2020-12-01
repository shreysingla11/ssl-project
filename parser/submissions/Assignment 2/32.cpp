#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
class point
{
public:
    int x,y,index;
};
class Pair
{
public:
    point r,b;
};


bool intersect(Pair p,Pair q);
void condition(vector<Pair>&Vector,int n);


int main()
{
    int twoN;
    cin>>twoN;
//check for even
    point temp;

    int n=twoN/2;
    vector<point>blue(n);
    vector<point>red(n);
    vector<Pair>final(n);
    for(int i=0; i<n; i++)
    {
        cin>>red[i].x;
        cin>>red[i].y;
        red[i].index=i;

    }
    for(int i=0; i<n; i++)
    {
        cin>>blue[i].x;
        cin>>blue[i].y;
        blue[i].index=i;
    }
    for(int i=0; i<n; i++)
    {
        final[i].r=red[i];
        final[i].b=blue[i];
    }
    condition(final,n);

    cout<<endl;
    for(int i=0;i<n;i++){
    cout<< (final[i].r).index << " " << (final[i].b).index<<endl;
    }
}



bool intersect(Pair p,Pair q)
{
    if(   sqrt((((p.r).x)-((q.b).x))*(((p.r).x)-((q.b).x)) + (((p.r).y)-((q.b).y))*(((p.r).y)-((q.b).y))) + sqrt( (((p.b).x)-((q.r).x))*(((p.b).x)-((q.r).x)) + (((p.b).y)-((q.r).y))*(((p.b).y)-((q.r).y)) ) < sqrt((((p.r).x)-((p.b).x))*(((p.r).x)-((p.b).x)) + (((p.r).y)-((p.b).y))*(((p.r).y)-((p.b).y))) + sqrt( (((q.b).x)-((q.r).x))*(((q.b).x)-((q.r).x)) + (((q.b).y)-((q.r).y))*(((q.b).y)-((q.r).y)) ) )
    {
        return true;
    }
    else
    {
        return false;
    }
}

void condition(vector<Pair>&Vector,int n){
      point temp;
       for(int i=0;i<n;i++){
            if(intersect(Vector[i],Vector[i+1]))
        {
            temp =Vector[i].b;
            Vector[i].b=Vector[i+1].b;
            Vector[i+1].b=temp;
          condition(Vector,i+1);
       }
}
return;

}
