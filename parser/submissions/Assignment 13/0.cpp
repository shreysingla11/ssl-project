#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>
using namespace std;
/*
void func(int good)
{

}
*/
int main()
{
    int n;
    cin>>n;
    int G[n][n];
    int S[4*n][n];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>G[j][i];
        }
    }
    int A[n];
    int min=0;
    cout<<min;
    for(int j=1; j<n; j++)
    {
        for(int i=0; i<2*n; i++)
        {
            for(int k=0; k<n; k++)
            {
                if(G[k][j]<0)
                {
                    if(min>((S[i+1][k])+abs(G[k][j])))
                    {
                        min=S[i+1][k]+abs(G[k][j]);
                    }
                }
                else
                {
                    if(min>((S[i-1][k])+abs(G[k][j])))
                    {
                        min=S[i-1][k]+abs(G[k][j]);
                    }
                }

            }
        }
    //cout<<min<<endl;
    int a = rand()%n;
    cout<<a<<endl;
    }
}
