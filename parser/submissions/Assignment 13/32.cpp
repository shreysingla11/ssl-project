#include <iostream>
#include <limits.h>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int** C=new int*[n];
    int** S=new int*[n];
    for(int i=0;i<n;i++)
    {
        C[i]=new int[n];
        S[i]=new int[2];
        S[i][0]=INT_MAX;
        S[i][1]=0;
        for(int j=0;j<n;j++)
        {
            cin>>C[i][j];
        }
    }
    S[0][0]=0;

    while(true)
    {
        bool b=0;
        for(int v1=0;v1<n;v1++)
        {
            for(int v2=0;v2<n;v2++)
            {
                if(v1==v2)continue;
                int xx = ( C[v1][v2] > 0 ) ? 1 : -1;
                if(S[v1][0]+abs(C[v1][v2]) < S[v2][0] && S[v1][1]+xx<=0 )
                {
                    b=1;
                    S[v2][0] = S[v1][0]+abs(C[v1][v2]);
                    ( C[v1][v2] > 0 ) ? S[v2][1]=S[v1][1]+1 : S[v2][1]=S[v1][1]-1;
                }
            }
        }
        if(!b)break;
    }

    for(int i=0;i<n;i++)cout<<S[i][0]<<endl;


    return 0;
}
