#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int c[n][n];

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>c[i][j];
        }
    }
    int r[2*n+1][n*n][n];
    for(int i=0; i<2*n+1; i++)
    {
        for(int j=0; j<n*n; j++)
        {
            for(int k=0; k<n; k++)
            {
                r[i][j][k]=INT_MAX;
            }
        }

    }

    r[0][0][0]=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n*n-1; j++)
        {
            for(int k=0; k<2*n+1; k++)
            {


                for(int t=0; t<n; t++)
                {
                    if(c[t][j]>0)
                    {
                        if(k<=n-1)
                        {
                            int check=r[k+1][j][t]+c[t][j];
                            if(check<r[k][j+1][i])
                            {
                                r[k][j+1][i] = check;
                            }
                        }

                        if(k=n+1)
                        {
                            int check=r[0][j][t]+c[t][j];
                            if(check<r[k+1][j+1][i])
                            {
                                r[k][j+1][i] = check;
                            }
                        }
                    }
                }


            }

        }

    }


    return 0;
}
