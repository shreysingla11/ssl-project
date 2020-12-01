#include<iostream>
#include<vector>
#include<cstdio>
#include<queue>
#include<cmath>
using namespace std;
struct node
{
    int val;
    vector<int> label;
    vector<bool> qgood;
    node(int id,int n)
    {
        int i=0;
        val=id;
        for(i=0; i<(4*n+1); i++)
        {
            label.push_back(INFINITY);
            qgood.push_back(false);
        }
    }
};

struct element
{
    int id,g;
    element(int i, int gd)
    {
        id=i;
        g=gd;
    }
    element()
    {

    }
};


int main()
{
    int n,i,j,a;
    cin>>n;
    vector<vector<int> > C;
    C.resize(n);
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%d",&a);
            C[i].push_back(a);
        }
    }
    node* b;
    vector<node> kapil;
    for(i=0; i<n; i++)
    {
        b=new node(i,n);
        kapil.push_back(*b);
    }

    queue<element> q;
    element* ele;
    element temp;

    kapil[0].label[2*n]=0;
    kapil[0].qgood[2*n]=true;
    ele=new element(0,2*n);
    q.push(*ele);
    while(!q.empty())
    {
        temp=q.front();
        for(i=0; i<n; i++)
        {
            if(C[temp.id][i]<0)
            {
                if(((kapil[temp.id].label[temp.g]-C[temp.id][i])<kapil[i].label[temp.g+1])&&((temp.g+1)<=4*n))
                {
                    kapil[i].label[temp.g+1]=(kapil[temp.id].label[temp.g]-C[temp.id][i]);
                    if(kapil[i].qgood[temp.g+1]==false)
                    {
                        kapil[i].qgood[temp.g+1]=true;
                        ele=new element(i,temp.g+1);
                        q.push(*ele);
                    }
                }
            }
            else
            {

                if(((kapil[temp.id].label[temp.g]+C[temp.id][i])<kapil[i].label[temp.g-1])&&((temp.g-1)>=0))
                {
                    kapil[i].label[temp.g-1]=(kapil[temp.id].label[temp.g]+C[temp.id][i]);
                    if(kapil[i].qgood[temp.g-1]==false)
                    {
                        kapil[i].qgood[temp.g-1]=true;
                        ele=new element(i,temp.g-1);
                        q.push(*ele);
                    }
                }
            }
        }
        q.pop();
        kapil[temp.id].qgood[temp.g]=false;

    }
    int m;
    for(i=0; i<n; i++)
    {
        m=-1;
        for(j=2*n; j<(4*n+1); j++)
        {
            if(kapil[i].label[j]>2000000000)
            {
                continue;
            }
            if(m==-1)
            {
                m=kapil[i].label[j];
                continue;
            }
            if(m>kapil[i].label[j])
            {
                m=kapil[i].label[j];
                continue;
            }

        }
        if(m!=-1)
        {cout<<m<<endl;}
        else{
        cout<<"infinity"<<endl;
        }
    }

    return 0;
}
