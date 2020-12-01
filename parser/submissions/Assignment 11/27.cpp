#include<iostream>
#include<string>
#include<cstdio>
using namespace std;


int main()
{
    long long int n;
   // cin>>n;
   scanf("%i",&n);
    int B[5];
    B[0]=1;
    B[1]=2;
    B[2]=4;
    B[3]=8;
    B[4]=16;


 int tot=0,c0=0,c1=0,sum=0;
    for(int i=0; i<n; i++)
    {long long int A;
        //cin>>A;
        scanf("%i",&A);
        tot=0;
        sum=0;
        for(int p=0; p<5; p++)
        {
            int k=0;
            c0=0;
            c1=0;
            k=A%512;
            for(int q=0; q<9; q++)
            {
                if(k%2==1)
                {
                    c1++;
                }
                else
                {
                    c0++;
                }
                k=k/2;
            }
            if(c0>c1)
            {
                tot=tot+c1;
            }
            if(c0<c1)
            {
                sum=sum+B[p];
                tot=tot+c0;
            }
            A=A/512;
        }
        if(tot>4)
        {
            cout<<"?";
        }
        else
        {
            char c = 97+sum;
            printf("%c",c);
        }
    }

    return 0;
}

