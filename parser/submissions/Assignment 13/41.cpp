#include<iostream>
#include<stdio.h>
#include<string.h>
#include<limits.h>
#define INFINITY INT_MAX

using namespace std;


int main(){
int n;
cin>>n;
int dist[n];
int C[n][n];
string E[n][n];


for(int i=0;i<n;i++)
{
    if(i==0) dist[i]=0;
    else dist[i]= INFINITY;
}

for(int i=0;i<n;i++)
{
    for(int j=0;j<n;j++)
    {
        cin>>C[i][j];

        if(C[i][j] > 0){
        E[i][j] = "bad";
        }
        else if(C[i][j] < 0){
        C[i][j] = -C[i][j];
        E[i][j] = "good";
        }
    }

}


for(int j=0;j<n;j++)
{
int sum[j],goodc[j],badc[j];
string walk[j];
for(int i=0;i<j;i++)
{
    sum[i] = 0;
    goodc[i] =0;
    badc[i] = 0;
}
    for(int a=0;a<j;a++)
    {
        sum[j]=sum[j]+C[a][a+1];
        if(E[a][a+1] == "good") goodc[j]++;
        else if (E[a][a+1] == "bad") badc[j]++;
    }

    if(goodc[j]>=badc[j]) walk[j] = "good";
    if(E[0][j] == "good" && C[0][j]>=sum[j])
    {
        dist[j]=C[0][j];
    }
    else if(E[0][j] == "good" && C[0][j]<sum[j] && walk[j] == "good")
    {
        dist[j]=sum[j];
    }
    else
    {
        walk[j] = "no such walk";
    }

     if(walk[j] != "no such walk")
    {
        cout<<"infinity"<<endl;
    }
    else
    {
        cout<<dist[j]<<endl;
    }

}

return 0;
}
