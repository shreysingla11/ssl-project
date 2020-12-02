#include <iostream>
#include <vector>
#include<stdio.h>
using namespace std;

int main()
{
    int m, n;
    vector < int > A(10000000);
    vector < int > B(100000);
    scanf("%d%d", &m, &n);
    int i, j;
    for(i=0; i<m; i++)
    {   scanf("%d", &j);
        A[i]=j;
    }
    for(i=0; i<n; i++)
    {   scanf("%d", &j);
        B[i]=j;
    }
    int k=0;
    int shlength=0, firstindex, fiindex=-1, length;
    while(k<(m-n))
    {   //cout<<A[k]<<B[0]<<endl;
        if(A[k]==B[0])
        {   i=firstindex=k;
            j=0;
            length=0;
            while(j<n&&i<=(m-n+j))
            {   if(A[i]==B[j])
                {   j++;}
                length++;
                i++;
            }
            if(i>(m-n+j)) {length=0;}
            //cout<<length<<shlength<<endl;
            if(shlength==0||(shlength>length&&length!=0))  {shlength=length; fiindex=firstindex+1;}
        }
        k++;
    }
    if(shlength==0) cout<<"infinity";
    else
    printf("%d %d", shlength, fiindex);
    return 0;
}
