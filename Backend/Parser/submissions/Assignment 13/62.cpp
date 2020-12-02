#include<iostream>
using namespace std;
#include<queue>
#include<vector>
#include<cstdio>
#include<cmath>
struct graph
{
    int id;
    int goodness;
    graph(){}
    graph(int i, int j)
    {
        id=i;
        goodness=j;
    }
};
struct node
{
    vector<int> label;
    vector<bool> qpresent;
    node(int n)
    {
        for(int i=0; i<4*n+1;i++)
        {
            label.push_back(INFINITY);
            qpresent.push_back(false);
        }
    }
};
vector<node> myvector;
queue<graph> que;
int main()
{
    graph* entr;
    graph temp;
    int n;
    scanf("%d",&n);
    vector<vector<int> >c;
    c.resize(n);
    for(int y=0; y<n;y++)
    {
        c[y].resize(n);
    }
    for(int i=0; i<n;i++)
    {
        for(int j=0; j<n; j++)
        {
            int x;
            scanf("%d",&x);
                c[i][j]=x;
        }
    }
    node* a;
    int r=0;
    while(r<n)
    {
        a=new node(n);
        myvector.push_back(*a);
        r++;
    }
    entr= new graph(0,2*n);
    int m;
    myvector[0].label[2*n]=0;
    myvector[0].qpresent[2*n]=true;
    que.push(*entr);
    while(!que.empty())
    {
        temp=que.front();
        int i=0;
        while(i<n)
        {
            if(c[temp.id][i]<0)
            {
                if(myvector[temp.id].label[temp.goodness]-c[temp.id][i]<myvector[i].label[temp.goodness+1] && (temp.goodness+1<=(4*n)))
                {
                   myvector[i].label[temp.goodness+1]= myvector[temp.id].label[temp.goodness]-c[temp.id][i];
                   if(myvector[i].qpresent[temp.goodness+1]==false)
                   {
                        entr=new graph(i,temp.goodness+1);
                        myvector[i].qpresent[temp.goodness+1]=true;
                        que.push(*entr);
                   }
                }
            }
            else
            {
                if(myvector[temp.id].label[temp.goodness]+c[temp.id][i]<myvector[i].label[temp.goodness-1] && (temp.goodness-1>=0))
                {
                   myvector[i].label[temp.goodness-1]= myvector[temp.id].label[temp.goodness]+c[temp.id][i];
                   if(myvector[i].qpresent[temp.goodness-1]==false)
                   {
                        entr=new graph(i,temp.goodness-1);
                        myvector[i].qpresent[temp.goodness-1]=true;
                        que.push(*entr);
                   }
                }
            }
            i++;
        }
        que.pop();
        myvector[temp.id].qpresent[temp.goodness]=false;
    }
    int s=0;
    while(s<n)
    {
        m=-1;
        int alpha =-2;
        for(int j=2*n;j<4*n+1;j++)
        {
            if(myvector[s].label[j]>2000000000)
                continue;
            if(m==-1)
            {
                m=myvector[s].label[j];
                continue;
            }
            int beta=-2;
            if(m>myvector[s].label[j])
            {
                m=myvector[s].label[j];
                continue;
            }
        }
        if(m==-1) printf("infinity\n");
        else printf("%d\n",m);
        s++;
    }
    return 0;
}
