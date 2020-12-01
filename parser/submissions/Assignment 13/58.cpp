#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
//vector<vector<int> > graph;
//vector<vector<vector<int> > > app;
//queue<int> l;
//int max=INT_MAX;
//int main()
//{
//    int n,temp;
//    scanf("%d",&n);
//    vector<int> t;
//    for(int i=0;i<n;i++)
//    {
//        t.clear();
//        for(int j=0;j<n;j++)
//        {
//            scanf("%d",&temp);
//            t.push_back(temp);
//        }
//        graph.push_back(t);
//    }
//    app.resize(n,vector<vector<int> >(n,vector<int>(2*n+1,max)));
//    for(int i=0;i<2*n+1;i++)
//    {
//        app[0][0][i]=0;
//    }
//    int i=0;
//    int ch=0;
//     int check=0;
//    while(check)
//    {
//
//        for(int j=0;j<n;j++)
//        {
//            for(int k=0;k<=2*n;k++)
//            {
//
//            }
//        }
//
//    }
//
//
//}

struct node
{
    int n;
    vector<int> l;
    vector<bool> godn;
    node (int s){
    l.resize(4*s+1,INFINITY);
    godn.resize(4*s+1,false);
    }
};
struct queuew
{
    int go;
    int no;
};
   queuew v;
vector<node> proc;

vector<vector<int> > graph;

queue<queuew> q;

vector<queuew> maint;
vector<int> t(5,4);
     queuew t2 ;
int a=5,b=6,c=9,d=5;
int main()
{
    int n,temp;
    scanf("%d",&n);
    vector<int> t;
    for(int i=0;i<n;i++)
    {
        t.clear();
        for(int j=0;j<n;j++)
        {
            scanf("%d",&temp);
            t.push_back(temp);
        }
        graph.push_back(t);
    }
    node t4(n);
    for(int i=0;i<n;i++)
    {
        t4.n=i;
        proc.push_back(t4);
    }
    proc[0].godn[2*n] =true;
    proc[0].l[2*n] = 0;
    //cout<<"dgfsdfg"<<endl;

    v.go = 2*n;
    v.no = 0;
    q.push(v);
    int x,y,z=5;
    while(!q.empty())
    {
        queuew t1 = q.front();
        for(int i=0;i<n;i++)
        {
            if(graph[t1.no][i]<0)
            {
                if(t1.go<4*n && proc[t1.no].l[t1.go] - graph[t1.no][i] < proc[i].l[t1.go + 1] )
                {
                    proc[i].l[t1.go+1] = proc[t1.no].l[t1.go]-graph[t1.no][i];
                    if(proc[i].godn[t1.go+1]==false)
                    {
                        proc[i].godn[t1.go+1]=true;

                        t2.no = i;
                        t2.go = t1.go+1;
                        q.push(t2);

                    }

                }

            }
             if(graph[t1.no][i]>0)
            {

                if(t1.go>0 && proc[t1.no].l[t1.go] + graph[t1.no][i] < proc[i].l[t1.go - 1] )
                {
                    proc[i].l[t1.go-1] = proc[t1.no].l[t1.go]+graph[t1.no][i];
                    if(proc[i].godn[t1.go-1]==false)
                    {
                        proc[i].godn[t1.go-1]=true;

                        t2.no = i;
                        t2.go = t1.go-1;
                        q.push(t2);

                    }

                }

            }


        }
        proc[t1.no].godn[t1.go] = false;
        q.pop();

    }
    int fgnkjg[55];
    for(int i=0;i<n;i++)
    {
        int small = INFINITY;
        for(int j=2*n;j<4*n+1;j++)
        {
            small = min(small,proc[i].l[j]);
        }
        if(small>=200000000)
            printf("infinity\n");
        else
            printf("%d\n",small);
    }

}
