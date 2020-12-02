#include <iostream>
#include <limits>
#include <stdlib.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int vertex[n];
    int edge[n][n];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>edge[i][j];

        }

    }
    ///initialisation of input data

    int infi = numeric_limits<int>::max();
    int s[n][2*n + 1];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<2*n+1; j++)
        {

            s[i][j]=infi;
            //cout<<s[i][j]<<" ";
        }
        //cout<<endl;

    }
    s[0][0+n]=0;

    for(int i=1; i<n*n+1; i++)
    {

        for(int u=0; u<n; u++)
        {
        for(int v=0; v<n; v++)
        {
        if(edge[u][v]<0)///edge is good
         {
         for(int k=-n;k<n+1;k++){
         if(s[u][k+n]!=infi){
            if(s[u][k+n]+abs(edge[u][v])  < s[v][k+n+1]){
            s[v][k+n+1]=s[u][k+n]+abs(edge[u][v]);
            }}
         }
         }
         else{///edge is bad
        for(int k=-n;k<n+1;k++){
        if(s[u][k+n]!=infi){
            if(s[u][k+n]+abs(edge[u][v])  < s[v][k+n-1]){
            s[v][k+n-1]=s[u][k+n]+abs(edge[u][v]);
            }}
         }

         }
        }
        }
    }
  /*     for(int i=0; i<n; i++)
    {
        for(int j=0; j<2*n+1; j++)
        {


            cout<<s[i][j]<<" ";
        }
        cout<<endl;

    }*/
    int temp_min=infi;
    for(int i=0; i<n; i++)
    {temp_min=infi;
        for(int j=n; j<2*n+1; j++)
        {
        //cout<<s[i][j]<<" ";
        if(s[i][j]<temp_min){
        temp_min=s[i][j];
        }

        }
        //cout<<endl;
        if(temp_min==infi){
        cout<<"infinity"<<endl;
        }
        else{
        cout<<temp_min<<endl;}
    }
    return 0;
}
