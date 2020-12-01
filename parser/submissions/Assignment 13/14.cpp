#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstdio>
#include<climits>
using namespace std;
int main()
{
    int n,temp;
    scanf("%d",&n);
    vector<vector<int> > goodvec(n,vector<int>(n));
    vector<vector<int> > cvec(n,vector<int>(n));
    vector<vector<int> > labelvec(n,vector<int>(n*n-1));
    for(int i=0; i<n; i++)
    {
        labelvec[i][0]=INT_MAX;
    }
    if(n!=0)labelvec[0][0]=0;

    for (int i=0; i < n; i++)
    {
        for (int j=0; j < n; j++)
        {
            scanf("%d",&temp);
            if(temp<0)
            {
                goodvec[i][j]=1;
                cvec[i][j]=-temp;
            }
            else
            {
                goodvec[i][j]=-1;
                cvec[i][j]=temp;
            }
        }
    }
    // int **c= new int *[n];
    // for (int i=0; i < n; i++)
    // {
    //     c[i] = new int[n];
    // }
    // for (int i=0; i < n; i++)
    // {
    //     for (int j=0; j < n; j++)
    //     {
    //         scanf("%d",&c[i][j]);
    //     }
    // }
    // for (int i=0; i < n; i++)
    // {
    //     for (int j=0; j < n; j++)
    //     {
    //         printf("%d",cvec[i][j]);
    //     }
    //     printf("\n");
    // }
    // for (int i=0; i < n; i++)
    // {
    //     for (int j=0; j < n; j++)
    //     {
    //         printf("%d",goodvec[i][j]);
    //     }
    //     printf("\n");
    // }
    vector<vector<int> > main(n,vector<int>(n*n-1));
    vector<int> gnvec(n);for(int i=0;i<n;i++){cout<<gnvec[i]<<endl;}
    for(int i=0; i<n; i++)
    {
        main[1][0]=INT_MAX;
    }
    if(n!=0)main[0][0]=0;

    for(int i=0; i<n*n-2; i++)
    {
        for(int k=0; k<n; k++)
        {
            for(int j=0; j<n; j++)
            {
                //gnvec[]
                if(labelvec[k][i+1]!=INT_MAX && labelvec[j][i]+cvec[j][i] < labelvec[k][i+1])
                {
                    labelvec[k][i+1]=labelvec[j][i]+cvec[j][i];
                    gnvec[k]=gnvec[k]+goodvec[j][i];
                }
            }
        }
    }
//for(int i=0;i<n;i++){cout<<gnvec[i]<<endl;}
    // vector<int> label(n,INT_MAX);
    // if(n!=0)
    // {
    //     label[0]=0;
    // }
    // // for(int i=0;i<n;i++){cout<<label[i]<<endl;}
    // queue<int> goodnessq;
    // queue<int> q;
    // q.push(0);
    // while(!q.empty())
    // {
    //     int v=q.front();
    //     q.pop();

    // }


}
