#include<iostream>
#include<cstdio>
#include<set>
#include<map>
using namespace std;
struct lane{
    char dir;
    int numships;
    //set<pair<float,float> > intervals;
};
int main()
{   int n,i,j;
    double u,v,t1,t2,m;
    double start,end,p,w;

    map<double,int> intr;
    //Input

    cin>>n>>w>>u>>v>>t1>>t2;

    lane *l=new lane[n];

    int count_t1=0,count_t2=0;
    map<double,int>::iterator it_start=intr.end(),it_end=intr.end();
    //pair<map<double,int>::iterator,bool> ret;
    for(i=0;i<n;i++)
    {
        //cout<<"Inserting lane "<<i<<endl;
        cin>>l[i].dir;
        cin>>l[i].numships;
        //cout<<"Loop"<<endl;
        for(j=0;j<l[i].numships;j++)
        {
            cin>>m;
            cin>>p;
            if(l[i].dir=='E'){
                start=-p/u-(i+1)*w/v;
                end=(m-p)/u-i*w/v;}
            else if(l[i].dir=='W'){
                start=p/u-(i+1)*w/v;
                end=(m+p)/u-i*w/v;}
            //if(p<0)
              //  continue;
            //cout<<start<<"  "<<end<<endl;
            if(end<t1||start>t2)
                continue;
            else if(start<t1)
                {count_t1++;start=t1;}
            else if(end>t2)
                {count_t2++;end=t2;}
            /*ret = intr.insert (pair<float,int>(start,1) );
                if (ret.second==false) {
                    ret.first->second+=1;
                    }
            //intr[start]=1;
            //intr[end]=-1;
            ret = intr.insert (pair<float,int>(end,-1) );
                if (ret.second==false) {
                    ret.first->second-=1;
                    }*/
            if (intr.find(start)==intr.end())
                it_start=intr.insert(it_start,pair<double,int>(start,1));
            else
                intr[start]+=1;
            if (intr.find(end)==intr.end())
                it_end=intr.insert(it_end,pair<double,int>(end,-1));
            else
                intr[end]-=1;
            //(l[i].intervals).insert(pair<float,float>(start,end));
        }


        intr[t1]=count_t1;
        intr[t2]=-count_t2;
        //cout<<"Inserted lane "<<i<<endl;
        int count=0;
        double prev_val=0,max=0;
        for (map<double,int>::iterator iter=intr.begin(); iter!=intr.end(); ++iter)
        {
            if(prev_val){
                        if(max<(iter->first-prev_val))
                            max=iter->first-prev_val;
                        prev_val=0;
                        }
            if(iter->first!=t1&&!iter->second)
                continue;
            count+=iter->second;
            if(!count)
                {
                    prev_val=iter->first;
                }

                //cout << '(' << iter->first<<','<<iter->second<<')';
            }
            //cout<<endl;
            printf("%0.8f\n",max);
            }
        }
        //cout << '\n';

    //cout<<"initialized";

    ///////////////////////////////////

