//#include<iostream>
//#include<vector>
//#include<math.h>
//using namespace std;
//
//class distinct
//{
//    vector<int> l;
//    int n;
//    vector<vector<int> > first;
//    vector<vector<int> > second;
//    public:
//    distinct(vector<int> sequence)
//    {
//        n=sequence.size();
//        int d=log2(n); //depth
//        for(int i=0;i<n;i++)
//            l[i]=-1;
//        for(int i=0;i<n;i++)
//            for(int j=0;j<i;j++)
//                if(sequence[i]==sequence[j])
//                    l[i]=j;
//
//        vector<vector<int> > f(d);
//        vector<vector<int> > s(d);
//        first=f;
//        second=s;
//        first[0]=l; //second[0]=l;
//        for(int i=1;i<d;i++)
//        {
//            vector<int> a(n,0);
//            vector<int> b(n,0);
//            first[i]=a;
//            second[i]=b;
//            long power = 1;
//            first[i].resize(n);
//            vector<int> d(n,0);
//            vector<int> e(n,-1);
//            vector<int> f(n,-1);
//            for(int j=0;j<n;j++)
//            {
//                int k=l[j]*power/n;
//                if(l[j]>=k*n/power && l[j]<(k+1)*n/power)
//                {
//                    d[k]++;
//                    first[i][j]=d[k];
//                    second[i][j]=e[k];
//                    f[k]=j;
//                }
//                else
//                {
//                    first[i][j]=d[k];
//                    second[i][j]=f[k];
//                    e[k]=j;
//                }
//            }
//            power*=2;
//        }
//    }
//    int num_distinct(int low,int high)
//    {
//        if(low==high) return 1;
//        if(high<=n/2) return num_distinct(low,n/2);
//        if(low<=n/2)
//        {
//
//        }
//    }
//};

#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

class distinct
{
    vector<int> l;
    public:
    distinct(vector<int> sequence)
    {
        int n=sequence.size();
        vector<int> copy(n,0);
        l=copy;
        for(int i=0;i<n;i++)
            l[i]=-1;
        for(int i=0;i<n;i++)
            for(int j=0;j<i;j++)
                if(sequence[i]==sequence[j])
                    l[i]=j;
    }
    int num_distinct(int low,int high)
    {
        int result=high-low+1;
        for(int p=low;p<high;p++)
            if(l[p]>=low) result--;
        return result;
    }
};

