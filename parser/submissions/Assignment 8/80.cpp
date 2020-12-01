#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
vector<double> findinter(vector<double> &A,vector<double> &B)
{
    vector<double> R;
    int i=0,j=0;
    while(i<A.size() && j<B.size())
    {
        if(A[i]<B[j])
        {
            if(A[i+1]<B[j])
            {
                i=i+2;
                continue;
            }
            if(A[i+1]>B[j])
            {
                if(A[i+1]<B[j+1])
                {
                    R.push_back(B[j]);
                    R.push_back(A[i+1]);
                    i=i+2;
                }
                else
                {
                    R.push_back(B[j]);
                    R.push_back(B[j+1]);
                    j=j+2;
                }
            }
        }
        else
        {
            if(B[j+1]<A[i])
            {
                j=j+2;
                continue;
            }
            if(B[j+1]>A[i])
            {
                if(B[j+1]<A[i+1])
                {
                    R.push_back(A[i]);
                    R.push_back(B[j+1]);
                    j=j+2;
                }
                else
                {
                    R.push_back(A[i]);
                    R.push_back(A[i+1]);
                    i=i+2;
                }
            }
        }
    }
    return R;
}
int main()
{
    int n,w,u,v,T1,T2;
    cin>>n>>w>>u>>v>>T1>>T2;
    vector<vector<double> >A(n);
    for(int i=0; i<n; i++)
    {
        char d;
        cin>>d;
        if(d=='E')
        {
            int m;
            cin>>m;
            vector<double> L(m);
            vector<double> P(m);
            if(m!=0)
            {
            for(int j=0; j<m; j++)
            {
                cin>>L[j]>>P[j];
                P[j]=-P[j];
            }
            double endp=0;
            for(int j=m-1; j>=0; j--)
            {
                double t=(i*w*1.0)/v;
                double t1=(endp/u)-t;
                double t2=(P[j]*1.0)/u-(w*1.0)/v-t;
                endp=L[j]+P[j];
                if(t1<=t2 && !(t1<T1 && t2<T1) && !(t1>T2 && t2>T2))
                {
                    if(t1<T1 && t2>T1)
                    {
                        A[i].push_back(T1);
                        A[i].push_back(t2);
                    }
                    else
                    {
                        if(t1<T2 && t2>=T2)
                        {
                            A[i].push_back(t1);
                            A[i].push_back(T2);
                        }
                        else
                        {
                            A[i].push_back(t1);
                            A[i].push_back(t2);
                        }
                    }
                }

            }
            double t=(i*w*1.0)/v;
            double t1=(endp/u)-t;
            if(t1<T2)
            {
                A[i].push_back(t1);
                A[i].push_back(T2);
            }
            }
            else
            {
                A[i].push_back(T1);
                A[i].push_back(T2);
            }

            /*for(int k=0; k<A[i].size(); k++)
            {
                cout<<A[i][k]<<" ";
            }*/
        }
        if(d=='W')
        {
            int m;
            cin>>m;
            double endp=0;
            if(m!=0)
            {
                for(int j=0; j<m; j++)
                {
                    double l,p;
                    cin>>l>>p;
                    double t=(i*w*1.0)/v;
                    double t1=(endp/u)-t;
                    double t2=(p*1.0)/u-(w*1.0)/v-t;
                    endp=l+p;
                    if(t1<=t2 && !(t1<T1 && t2<T1) && !(t1>T2 && t2>T2))
                    {
                        if(t1<T1 && t2>T1)
                        {
                            A[i].push_back(T1);
                            A[i].push_back(t2);
                        }
                        else
                        {
                            if(t1<T2 && t2>=T2)
                            {
                                A[i].push_back(t1);
                                A[i].push_back(T2);
                            }
                            else
                            {
                                A[i].push_back(t1);
                                A[i].push_back(t2);
                            }
                        }
                    }
                }
                double t=(i*w*1.0)/v;
                double t1=(endp/u)-t;
                if(t1<T2)
                {
                    A[i].push_back(t1);
                    A[i].push_back(T2);
                }

            }
            else
            {
                A[i].push_back(T1);
                A[i].push_back(T2);
            }
            /*for(int k=0; k<A[i].size(); k++)
            {
                cout<<A[i][k]<<" ";
            }*/
        }

    }
    vector<double>I;
    double maxi=0;
    I=findinter(A[0],A[0]);
    for(int i=0; i<I.size(); i=i+2)
    {
        if((I[i+1]-I[i])>maxi)
            maxi=I[i+1]-I[i];
    }
    printf("%.8f\n",maxi);
    for(int i=1; i<n; i++)
    {
        maxi=0;
        I=findinter(A[i],I);
        for(int i=0; i<I.size(); i=i+2)
        {
            if((I[i+1]-I[i])>maxi)
                maxi=I[i+1]-I[i];
        }
        printf("%.8f\n",maxi);
    }
}
