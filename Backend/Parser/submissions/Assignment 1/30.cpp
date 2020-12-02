#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

//Function
extern double f(int i);
//{
//    double answer;
//    int p = 307;
//    int a = 291;
//    int b = 768;
//    int c = 46;
//    int d = 232;
//
//    answer = p * (sin(a*i+b) + cos(c*i+d) + 2);
//    return answer;
//}

void maxfinder(int n)
{
    double maxfall_rate = f(1) - f(2);
    double curr_rate = f(1) - f(2);
    double maxfall =f(1) - f(2);
    double foobar1 = f(1)-f(2);
    for(int i=2 ; i< n ; i++)
    {

        //maxfall Rate will always be consecutive
        //because average derivative will always have
        //at least 1 smaller limit derivative with atleast the same value of derivative.
        // Hence for maxfall rate will be smallest
        if(maxfall_rate < curr_rate)
        {
            maxfall_rate = curr_rate;
        }
        // maxfall_rate part 1
        if(foobar1 > 0)
        {
            foobar1 = foobar1 + f(i) - f(i+1);
        }
        else
        {
            foobar1 = f(i) - f(i+1);
        }
        //Maxfall(n+1) = max(Maxfall(n),foobar1(n+1)
        if(maxfall < foobar1)
        {
            maxfall = foobar1;
        }
        //n = n + 1;
    }
    //Printing Stuff
    printf("%.6f\n",maxfall);
    printf("%.6f\n",maxfall_rate);
    
}

int main ()
{
    int n = 684128;
    if(n>1)
    {
        maxfinder(n);
    }
    else
    {
        printf("maxfall_rate Rate:0.000000\n");
        printf("maxfall_rate: 0.000000\n");
    }
}
