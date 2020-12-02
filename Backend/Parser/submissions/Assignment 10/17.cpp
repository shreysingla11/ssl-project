#include<iostream>
#include<vector>
#include<map>
using namespace std;
class distinct
{
    int *A,*l;

    map <int,int> lvalue;

public:
    vector< vector<int> > ABC,ABD;
    distinct()
    {

    }
    distinct(vector<int> &a)
    {
        A=new int[a.size()];
        l=new int[a.size()];
        int logn=0,n=a.size();
        while(n>1)
        {
            logn++;
            n/=2;
        }
        for (int i=0; i<a.size(); i++)
        {
            A[i]=a[i];
            l[i]=-1;
            if(lvalue.find(a[i])!=lvalue.end())
            {
                l[i]=lvalue[a[i]];
                lvalue[a[i]]=i;
            }
            else
            {
                lvalue[a[i]]=i;
            }
        }
        //
        vector<int> c(a.size(),0);
        vector< vector<int> > AB(logn,c);
        ABC=AB;
        ABD=AB;
        int ax=1;
        n=a.size();
        for(int i=0; i<logn; i++)
        {
            vector<int> ofn(ax*2,0),max1(ax*2,-1);
            for(int j=0; j<a.size(); j++)
            {
                if(l[j]!=-1)
                    {
                    int k=(l[j])/(n/ax);
                    if(l[j]>=k*(n/ax)+(n/ax)/2&&l[j]<(k+1)*(n/ax))
                    {
                        ofn[2*k+1]++;
                        ABC[i][j]=ofn[2*k+1];
                        ABD[i][j]=max1[2*k];
                        max1[2*k+1]=j;
                    }
                    if(l[j]<k*(n/ax)+(n/ax)/2&&l[j]>=(k)*(n/ax))
                    {
                        ofn[2*k]++;
                        ABC[i][j]=ofn[2*k+1];
                        ABD[i][j]=max1[2*k+1];
                        max1[2*k]=j;

                    }
                }
                else
                {
                    ABC[i][j]=0;
                    ABD[i][j]=-1;
                }

                //


            }
            ax=ax*2;
        }
    }
    //function
    int num_distinct(int  i,int j)
    {
        int cnt=0;
        for(int ab=i; ab<=j; ab++)
        {
            if(l[ab]<i)
            {
                cnt++;
            }
        }
        return cnt;
    }
};
