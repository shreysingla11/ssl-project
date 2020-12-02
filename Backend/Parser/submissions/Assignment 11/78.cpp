#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int p[5];
    p[0]=1;
    p[1]=2;
    p[2]=4;
    p[3]=8;
    p[4]=16;
    int n;
    scanf("%i",&n);
    long long int a;
    int current,zeros,ones,r,error;
    for(int i=0; i<n; i++)
    {
        cin>>a;
        r=0;
        error=0;
        for(int j=0; j<5; j++)
        {
            zeros=0;
            ones=0;
            current = a%512;
            a=a/512;
            for(int l=0; l<9; l++)
            {
                if(current%2==0)
                {
                    zeros++;
                }
                else
                {
                    ones++;
                }
                current=current/2;
            }
            if(zeros>ones)
            {
                error+=ones;
            }
            else
            {
                r+=p[j];
                error+=zeros;
            }
            if(error>4)
            {
                break;
            }
        }
        if(error>4)
            {
                printf("?");
            }
            else
            {
                char c;
                c=r+97;
                printf("%c",c);
            }
    }
    return 0;
}
