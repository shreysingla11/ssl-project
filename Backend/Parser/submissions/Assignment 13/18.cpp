#include<iostream>
#include<stdio.h>
#include<queue>
#include<cmath>
#include<limits.h>
#include<utility>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int *A = new int[n*n];
    int *distance = new int[(2*n+1)*n];
    bool *inqueue = new bool[(2*n+1)*n];
    //input
    int i=0;
    while(i!=n)
    {
        int j=0;
        while(j!=n)
        {
            scanf("%d",&A[i*n+j]);
            j++;
        }
        i++;
    }
    //
    //initialization distances
    int l=0;
    while(l!=n)
    {
        int j=0;
        while(j!=2*n+1)
        {
            distance[l*(2*n+1)+j]=INT_MAX;
            inqueue[l*(2*n+1)+j]=false;
            j++;
        }
        l++;
    }
    distance[n]=0;
    //
    queue<pair<int,int> > q;
    q.push(make_pair(0,n));
    inqueue[n]=true;
    //entire queue
    while(!q.empty())
    {
        pair<int,int> k=q.front();
        q.pop();
        inqueue[(k.first)*(2*n+1)+(k.second)]=false;
        //all predecessors of u
        int i=0;
        while(i<n)
        {
            //required goodness
            int good=k.second;
            while(good<=k.second)
            {
                if (A[k.first*(n)+i]<0)
                {
                    if (distance[k.first*(2*n+1)+good] - A[k.first*(n)+i] < distance[i*(2*n+1)+good+1])
                    {
                        //update
                        distance[i*(2*n+1)+good+1] = distance[k.first*(2*n+1)+good] - A[k.first*(n)+i];
                        if (!inqueue[i*(2*n+1)+good+1])
                        {
                            q.push(make_pair(i,good+1));
                            inqueue[i*(2*n+1)+good+1]=true;
                        }
                    }
                }
                else
                {
                    //cout<<k.second<<" "<<k.first<<" "<<i<<endl;
                    if (distance[k.first*(2*n+1)+good] + A[k.first*(n)+i] < distance[i*(2*n+1)+good-1])
                    {
                        //update
                        distance[i*(2*n+1)+good-1] = distance[k.first*(2*n+1)+good] + A[k.first*(n)+i];
                        if (!inqueue[i*(2*n+1)+good-1])
                        {
                            q.push(make_pair(i,good-1));
                            inqueue[i*(2*n+1)+good-1]=true;
                        }
                    }
                }
                good++;
            }
            i++;
        }
    }
    int p=0;

    while(p!=n)
    {
        int min=INT_MAX;
        int good=n;
        while(good<=2*n)
        {
            if(min>distance[p*(2*n+1)+good])
            {
               min=distance[p*(2*n+1)+good];
            }
            good++;
        }
        if(min==INT_MAX)
        {
            printf("%s\n","infinity");
        }
        else
        {
            printf("%d\n",min);
        }
        p++;
    }

    /*
    while(p!=n)
    {
        int j=0;
        while(j!=2*n+1)
        {
            cout<<distance[p*(2*n+1)+j]<<" ";
            j++;
        }
        cout<<endl;
        p++;
    }
    */
}
