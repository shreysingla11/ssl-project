#include<iostream>
#include<vector>
#include<map>
#include<list>
using namespace std;
class distinct
{
public:
    vector<int> a;
    vector<int> l;
    vector< vector<int> > a1;
    vector< vector<int> > a2;
    int n;
    distinct(vector<int> b)
    {
        a=b;
        map<int,int> mp;
        n=a.size();
        vector< int> t1(0,n);
        vector< int> t2(0,n);
        for(int m=0; m<n; m++)
        {
            if(mp.count(a[m])>0)
            {
                l[m]=mp[a[m]];
                mp[a[m]]=m;
            }
            else
            {
                mp[a[m]]=m;
                l[m]=-1;
            }
        }
        int siz=1,siz1=n;
        while(siz1!=1)
        {
        vector<int> interval(0,siz);
        for(int j=0;j<n;j++)
        {
        if(l[j]==-1){t1[j]=0;continue;}
         int k=l[j]*siz/n;
         if(l[j]>=(k*n/siz + n/(2*siz))){interval[k]++;}
        }
        //t1[j]=interval[k];
        siz*=2;
        siz1=siz1/2;
        }
    }

    int num_distinct(int i,int j)
    {
        int k;
        int result=j-i+1;

        k=5;
        result=result-k;
        return result;
    }
};
