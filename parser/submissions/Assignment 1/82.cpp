#include <iostream>;
#include <cstdio>;
#include <cmath>;
using namespace std;
extern f(int i);
/*double fun(int n)
{
    int i =1;
    double r = (f(i)-f(n))/n-i;
    for(i=2;i<n;i++)
    {
        if(r<(f(i)-f(n))/n-i){r = (f(i)-f(n))/n-i;}
    }
    return r;
}*/
int main()
{
    int n;
    cin>>n;
    if(n<2)
    {
        cout<<"n should be greater than 2";
        return 0;
    }
    double r=f(1)-f(2),s=f(1);
    int k=2;
    while(k!=n)
    {
        if(f(k)>s)
        {
            s = f(k);
        }
        if((s-f(k+1))>r)
        {
            r = s-f(k+1);
        }
        k++;
    }
    /*double r1=f(1)-f(2);
        k = 2;
        while(k!=n)
        {
            if(r1<fun(k+1))
            {r1 = fun(k+1);}
            k++;
        }*/
    if(r<0)
    {
        r = 0;
        // r1 = 0;
    }
    printf("%6f",r);
    cout<<endl;
//printf("%6f",r1);
    return 0;
}
