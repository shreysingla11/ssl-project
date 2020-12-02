#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
vector<double> inter(vector<double> a,vector <double> b)
{
    vector <double> x;
    int u=0,v=0;double max1=0;
    while(u<a.size()&&v<b.size())
    {
        if(a[u]<=b[v])
        {
            if(a[u+1]<b[v])
            {
                u+=2;
                continue;
            }
            else
            {
                x.push_back(b[v]);
                if(b[v+1]<a[u+1])
                {
                    x.push_back(b[v+1]);
                    v+=2;
                    continue;
                }
                else
                {
                    x.push_back(a[u+1]);
                    u+=2;
                    continue;
                }

            }

        }

        //

        if(b[v]<a[u])
        {
            if(b[v+1]<a[u])
            {
                v+=2;
                continue;
            }
            else
            {
                x.push_back(a[u]);
                if(a[u+1]<b[v+1])
                {
                    x.push_back(a[u+1]);
                    u+=2;
                    continue;
                }
                else
                {
                    x.push_back(b[v+1]);
                    v+=2;
                    continue;
                }

            }
        }
    }
    int xy=0;
    while(xy<x.size())
    {
       if(max1<x[xy+1]-x[xy])
       {
            max1=x[xy+1]-x[xy];
       }
        xy+=2;
    }
    printf("%0.8f \n",max1);
    return x;

}
int main()
{
    int N,nship,j=0;
    double w,v,u,t1,t2,len,pos,temp=0;
    char EW;
    cin>>N>>w>>u>>v>>t1>>t2;
    vector< vector <double> > space(N);
    while(j<N)
    {
        cin>>EW>>nship;
       // vector<double > space[j];
        temp=0;

        if(EW=='E')
        {
            int A[nship];
            int B[nship];
            int x=nship;
            while(x>0)
            {

                cin>>len>>pos;
                A[x-1]=len;
                B[x-1]=-pos;
                x--;

            }
            while(x<nship)
            {

                double strt =temp/u-j*(w/v);
                double end1 =B[x]/u-w/v-j*(w/v);
                temp=A[x]+B[x];
                if(strt<=end1)
                {
                    if(strt>=t1&&end1<=t2)
                    {
                        space[j].push_back(strt);
                        space[j].push_back(end1);
                    }
                    if(strt<t1&&end1>t1)
                    {
                        if(end1<t2)
                        {
                            space[j].push_back(t1);
                            space[j].push_back(end1);
                        }
                        else
                        {
                            space[j].push_back(t1);
                            space[j].push_back(t2);
                        }
                    }
                    if(strt>t1&&end1>t2)
                    {
                        space[j].push_back(strt);
                        space[j].push_back(t2);
                    }
                }
                x++;
            }



            if(temp/u-j*(w/v)<t2)
            {
                if(temp/u-j*(w/v)>t1){
                 space[j].push_back(temp/u-j*(w/v));
                }else{
                space[j].push_back(t1);
                }
                space[j].push_back(t2);
            }
        }




        if(EW=='W')
        {
            while(nship>0)
            {
                double strt =temp/u-j*(w/v);
                cin>>len>>pos;
                double end1 =pos/u-w/v-j*(w/v);
                temp=len+pos;
                if(strt<=end1)
                {
                    if(strt>=t1&&end1<=t2)
                    {
                        space[j].push_back(strt);
                        space[j].push_back(end1);
                    }
                    if(strt<t1&&end1>t1)
                    {
                        if(end1<t2)
                        {
                            space[j].push_back(t1);
                            space[j].push_back(end1);
                        }
                        else
                        {
                            space[j].push_back(t1);
                            space[j].push_back(t2);
                        }
                    }
                    if(strt>t1&&end1>t2)
                    {
                        space[j].push_back(strt);
                        space[j].push_back(t2);
                    }
                }
                nship--;
            }

            if(temp/u-j*(w/v)<t2)
            {
                if(temp/u-j*(w/v)>t1){
                 space[j].push_back(temp/u-j*(w/v));
                }else{
                space[j].push_back(t1);
                }
                space[j].push_back(t2);
            }


        }

        j++;
    }


    //Question main
    int ij=1;
    vector<double> ans;
    ans=inter(space[0],space[0]);
    while(ij<N)
    {
        ans=inter(ans,space[ij]);
        ij++;
    }


    return 0;
}
