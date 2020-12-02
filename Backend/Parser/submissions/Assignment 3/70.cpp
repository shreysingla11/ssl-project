#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
#include<stdio.h>

using namespace std;

vector< int > L;
vector<int> line;
vector<int> s1;
vector<int> s2;
int n,m,mini=INT_MAX;
int main()
{
    int temp,index=-1,k;
    scanf("%d", &n);
    scanf("%d", &m);
    for (int i =0;i<n;i++)
    {
        scanf("%d", &temp);
        s1.push_back(temp);
    }
    for(int i=0;i<m;i++)
    {
        scanf("%d", &temp);
        s2.push_back(temp);
    }
    for(int i=0;i<m-1;i++)
    {
        L.push_back(INT_MAX);
    }
    if(s1[n-1]==s2[m-1])
    {
        L.push_back(1);
    }
    else
    {
        L.push_back(INT_MAX);
    }
     if(L[m-1]==INT_MAX)
        k=1;
    else
        k=0;
    for(int i=n-2;i>=0;i--)
    {
        for(int j=0;j<m;j++)
        {   if(j<=i&&(n-i+j-k)>m-1){
            if(j==m-1)
            {
                if(s1[i]==s2[j])
                    L[m-1]=1;
                else
                    L[m-1]=(L[m-1]==INT_MAX)?INT_MAX:L[m-1]+1;
            }
            else
            {
                if(s1[i]==s2[j])
                {
                    L[j]=(L[j+1]==INT_MAX)?INT_MAX:L[j+1]+1;
                }
                else
                {
                    L[j]=(L[j]==INT_MAX)?INT_MAX:L[j]+1;
                }
            }
                        if(L[j]==INT_MAX)
                        n--;

            }
        }
        if(mini>=L[0]&&L[0]!=INT_MAX)
        {
            mini=L[0];
            index=i;
        }
    }
    if(index==-1)
    {
        printf("infinity\n");
    }
    else
    {
        printf("%d %d\n",mini,index+1);
    }

}
