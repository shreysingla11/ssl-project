// 140050035
// v yashwanth reddy
// assignment 1

#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

extern double f (long long i);

//  recursive solution - consuming too much of
//  stack memory for large values of n - giving seg fault

/*
double maxfall (int x)
    {
        if (x==1)
            {return 0;}
        else
            {   double max=0;
                if (max<maxfall(x-1))  {max=maxfall(x-1);}
                if (max<newfall(x))    {max=newfall(x);}
                return max;
            }
    }
double maxf (int x)
    {
        if (x==1)
            {return f(1);}
        else
            {
                if (maxf(x-1)>f(x)) {return maxf(x-1);}
                else {return f(x);}
            }
    }

double newfall (int x)
    {
        if (x==1)
            {return 0;}
        else
            {return maxf(x-1)-f(x);}
    }

*/

//  Iterative solution

int main()
    {
        int n;
        cout<<"enter n.."<<endl;
        cin>>n;
        double maxfall=0,maxf=f(1);
        int i=1;
        for (i;i<n;i++)
            {
                if (maxfall<maxf-f(i+1))
                    {
                        maxfall=maxf-f(i+1);
                    }
                if (maxf<f(i))
                    {
                        maxf=f(i);
                    }
            }
        printf("%6f",maxfall);
        return 0;
    }

