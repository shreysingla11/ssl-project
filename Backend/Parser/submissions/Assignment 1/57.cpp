#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
//int p, a, b, c, d;
extern double f(int n);
//double f(int n)
//{
//    return p * (sin(a*n+b) + cos(c*n+d) + 2);
//}
int main()
{
    int n, i, maxindex;
    double max, fallmax, fallratemax, res, tempfall, tempfallrate, prev;
    fallmax = fallratemax = 0.0;
    //cin>>p>>a>>b>>c>>d;
    cin>>n;
    prev = max = f(1);
    for (i = 2;i <= n; ++i)
    {
        res = f(i);
        if (res > max)
        {
            max = res;
        }
        else
        {
            tempfall = max - res;
            if (prev > res)
            {
                tempfallrate = prev - res;
                if (tempfallrate > fallratemax)
                {
                    fallratemax = tempfallrate;
                }
            }
            if (tempfall > fallmax)
            {
                fallmax = tempfall;
            }
        }
        prev = res;
    }
    printf("%.6f \n", fallmax);
    printf("%.6f \n", fallratemax);
    return 0;
}
