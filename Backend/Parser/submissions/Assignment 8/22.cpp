#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<stdio.h>
#include<fstream>
using namespace std;
long double n,w,u,v,t1,t2;
ifstream infile("input1.txt");
class ship
    {
        public:
        long double length;
        long double start;
    };
bool myfunc(ship a, ship b)
    {
        return(a.start<b.start);

    }
class lane
    {
        public:
        vector <ship> L;
        char dir;

      lane laneform(long double num)
        {

           long double m;
           char d;
           cin>>d>>m;
           dir=d;
           L.resize(m);

          if(dir=='E')
           {
           for(int i=0;i<m;i++)
            {
                cin>>L[i].length>>L[i].start;
                L[i].start=(L[i].start)+t1*u;
                L[i].start=(-L[i].start)/u+(num*w/v);
                L[i].length=(L[i].start)+(L[i].length)/u;
               // cout<<L[i].start<<" "<<L[i].length<<endl;
            }
            }
            if(dir=='W')
           {
           for(int i=0;i<m;i++)
            {
                cin>>L[i].length>>L[i].start;
                L[i].start=(L[i].start)-t1*u;
                L[i].start=(L[i].start)/u+(num*w/v);
                L[i].length=(L[i].start)+(L[i].length)/u;
              //  cout<<L[i].start<<" "<<L[i].length<<endl;

            }

        }
         return(*this);

}
void printlane()
    {

        //cout<<dir<<endl;
        for(int i=0;i<L.size();i++)
            {
                //cout<<L[i].start<<" "<<L[i].length<<"  ";
            }
        //cout<<endl;
    }
    };
int main()
{

    cin>>n>>w>>u>>v>>t1>>t2;
    ////cout<<"n="<<n<<" w="<<w<<"u="<<u<<"v="<<v<<"t1="<<t1<<"t2="<<t2<<endl;
    vector <lane> main;
    main.resize(n);
    for(int i=0;i<n;i++)
        {
            lane l;
            ////cout<<"laneform i="<<i<<endl;
            main[i]=l.laneform(i);
            ////cout<<"here";
           // l.printlane();
        }
   vector <ship> result;
    for(int i=0;i<n;i++)
        {
            result.insert(result.end(),main[i].L.begin(),main[i].L.end());
        }
   sort(result.begin(),result.end(),myfunc);
    long double maxt=0;
    ////cout<<"result\n";
   // for(int i=0;i<result.size();i++)
       // {
       //     //cout<<result[i].start<<" "<<result[i].length<<endl;
       // }
    for(int i=0;i<result.size()-1;i++)
        {
            if(result[i].length>result[i+1].start)
                {
                    //cout<<"continue"<<result[i].length<<" >"<<result[i+1].start<<endl;
                    continue;
                }
            else
                {
                    //cout<<"else"<<result[i].length<<" >"<<result[i+1].start<<endl;
                    long double maxl=result[i+1].start-result[i].length;
                    //cout<<"maxl"<<maxl<<endl;
                    if(maxl>maxt)
                        {
                            maxt=maxl;
                            //cout<<maxt<<"=maxt\n";

                        }
                }
        }
        ////cout<<"diff"<<(n*(w/v))<<endl;
        long double comp1=-t1+result[0].start;
        long double comp2=t2-result[result.size()-1].length;
        if(comp1>maxt&& comp1>comp2)  {  printf("%.8Lf",(comp1-n*(w/v)));   ////cout<<(comp1-n*(w/v));
        }
        else if(comp2>maxt&&comp2>comp1)  {  printf("%.8Lf",(comp2-n*(w/v)));////cout<<(comp2-n*(w/v));
        }
        else{  printf("%.8Lf",(maxt-n*(w/v)));////cout<<(maxt-n*(w/v));
        }
}
/*
3 100 5 10 0 100
E 2 100 -300 50 -100
W 3 10 60 50 200 200 400
E 1 100 -300
*/
