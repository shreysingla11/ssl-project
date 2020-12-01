#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
extern double givenequation(double i);
/*double gradient(int i,int j)
{
    return (givenequation(i)-givenequation(j))/(j-i);
}
*/
int main()
{
    double r=0,s=givenequation(1),i=1,n;
    cout<<"The value of n is";
    cin>>n;
    while(i<n)
    {
        if(r<(s-givenequation(i+1)))
        {
            r=(s-givenequation(i+1));
        }
        if(s<givenequation(i))
        {
            s=givenequation(i);
        }
       /* j=i;
        while(j<n)
        {
            k=gradient(i,j+1);
            if(rate<k)
            {
                rate=k;
            }
            j++;
        }*/
        i++;
    }
    printf("%6f\n",r);
    //printf("%6f\n",rate);
    return 0;
}
