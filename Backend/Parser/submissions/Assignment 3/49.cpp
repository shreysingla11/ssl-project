#include<iostream>
#include<vector>
#include<stdio.h>

using namespace std;


int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int* a = new int[n];
    int* b = new int[m];

    for(int p=0;p<n;p++){
        scanf("%d",&a[p]);
    }
    for(int p=0;p<m;p++){
     scanf("%d",&b[p]);
    }
    vector<int> prev(n);
    vector<int> pres(n);

    for(int j=m-1;j>=0;j--)
    {
        if(j<m-1){pres[n-m+j+1]=n+1;}
        for(int i=n-m+j;i>=0;i--)
        {
            if((i==n-1)&&(j==m-1))
            {
                pres[i] = 1;
            }
            else if((i<n-1)&&(j==m-1))
            {
                if(a[i]==b[m-1]){pres[i] = 1;}
                else{pres[i] = 1+pres[i+1];}
            }
            else if((i==n-1)&&(j<m-1))
            {
                pres[i] = n+1;
            }
            else
            {
                if(a[i]==b[j]){pres[i] = 1+prev[i+1];}
                else{pres[i] = 1+pres[i+1];}
            }
        }
        prev = pres;
    }

    int least=n+1,lessi = 0;

    for(int i=0;i<n;i++)
    {
        if(least>pres[i]){least = pres[i];lessi = i;}
    }

    if(least>n)
    {
        cout<<"infinity"<<endl;
    }
    else{
        cout<<least<<" "<<lessi+1<<endl;
    }

    return 0;

}
