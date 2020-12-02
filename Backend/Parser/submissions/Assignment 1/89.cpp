#include<iostream>
#include<vector>
#include<cstdio>
#include<math.h>
using namespace std;
extern double f(int a);
int main()
{
    int i=1;
    long int n;
    double Max=0,maxSlope=0;
    vector<int>LocalMax;
    vector<int>LocalMin;
    cin>>n;
    if(n==1)
    {
        printf("%.6f",Max);
        cout<<endl;
        printf("%.6f",maxSlope);
        return 0;
    }
    while(i<=n-1)
    {
        while(f(i)<=f(i+1))
        {
            i++;
            if(i==n)break;
        }
        if(i!=n)
        {
            LocalMax.push_back(i);
            i++;
            if(i==n)
            {
                LocalMin.push_back(n);
                break;
            }
            while(f(i)>=f(i+1))
            {
                i++;
                if(i==n) break;
            }
            LocalMin.push_back(i);
            i++;
        }
    }
    vector<int>::iterator it1;
    vector<int>::iterator it2;
    for(it1=LocalMax.begin(); it1!=LocalMax.end(); ++it1)
    {
        for(it2=LocalMin.begin(); it2!=LocalMin.end(); ++it2)
        {
            if(*it1<*it2)
            {
                double a=f(*it1)-f(*it2);
                if(Max<a)
                {
                    Max=a;
                }
                if(maxSlope<(a/(*it2-*it1)))
                {
                    maxSlope=a/(*it2-*it1);
                }
            }
        }
        LocalMin.erase (LocalMin.begin()+0);
    }
    printf("%.6f",Max);
    cout<<endl;
    printf("%.6f",maxSlope);
    return 0;
}
