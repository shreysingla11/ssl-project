#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
char analyze(vector<bool> ret)
{

    int a=0,b=0;
    int A[5];
    int err=0;;
    for(int i=0; i<9; i++)
    {
        if(ret[i]==0)
        {
            a++;
        }
        if(ret[i]==1)
        {
            b++;
        }
    }
    if(a>b)
    {
        err+=b;
        A[0]=0;
    }
    if(b>a)
    {
        err+=a;
        A[0]=16;
    }
    a=0;
    b=0;

    for(int i=9; i<18; i++)
    {
        if(ret[i]==0)
        {
            a++;
        }
        if(ret[i]==1)
        {
            b++;
        }
    }
    if(a>b)
    {
        err+=b;
        A[1]=0;
    }
    if(b>a)
    {
        err+=a;
        A[1]=8;
    }
    a=0;
    b=0;
    for(int i=18; i<27; i++)
    {
        if(ret[i]==0)
        {
            a++;
        }
        if(ret[i]==1)
        {
            b++;
        }
    }
    if(a>b)
    {
        err+=b;
        A[2]=0;
    }
    if(b>a)
    {
        err+=a;
        A[2]=4;
    }
    a=0;
    b=0;
    for(int i=27; i<36; i++)
    {
        if(ret[i]==0)
        {
            a++;
        }
        if(ret[i]==1)
        {
            b++;
        }
    }
    if(a>b)
    {
        err+=b;
        A[3]=0;
    }
    if(b>a)
    {
        err+=a;
        A[3]=2;
    }
    a=0;
    b=0;
    for(int i=36; i<45; i++)
    {
        if(ret[i]==0)
        {
            a++;
        }
        if(ret[i]==1)
        {
            b++;
        }
    }
    if(a>b)
    {
        err+=b;
        A[4]=0;
    }
    if(b>a)
    {
        err+=a;
        A[4]=1;
    }
    a=0;
    b=0;
    if(err>4)
    {
        return '?';
    }
    else
    {
    int sum=0;
        for(int i=0; i<5; i++)
        {
            sum+=A[i];
        }
       sum+=97;
       return sum;
    }
}
int main()
{
    int n;
    long long int *A;
    char *res;
    cin>>n;
    A= new long long int[n];
    res = new char[n];
    for(int i=0; i<n; i++)
    {
        cin>>A[i];
        long long int x=A[i];
        vector<bool> ret;
        while(x)
        {
            if (x&1)
                ret.push_back(1);
            else
                ret.push_back(0);
            x>>=1;
        }
        while(ret.size()!=45)
        {
            ret.push_back(0);
        }
        reverse(ret.begin(),ret.end());
        res[i]=analyze(ret);
    }
    for(int i=0;i<n;i++)
    {cout<<res[i];}
return 0;
}
