#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
struct node
{
    int t;
    int m;
    int count;
    int ncount;
    vector<int> ifr;
    vector<int> fr;
    bool go;
    bool ngo;
    node()
    {
        t=0;
        m=0;
        count=0;
        ncount=0;
        go=false;
        ngo=false;
    }
};
int main()
{
    int i,n,p,q,r,j;
    scanf("%d",&n);
    node* temp;
    vector<node> mynodes;
    vector<int> going;
    vector<int> ngoing;
    for(i=0;i<n;i++)
    {
        temp=new node;
        scanf("%d",&(temp->t));
        scanf("%d",&(temp->m));
        for(j=0;j<temp->m;j++)
        {
            scanf("%d",&p);
            temp->fr.push_back(p);
        }
        if(temp->t==0) {temp->go=true;going.push_back(i);}
        if(temp->t>temp->m) {temp->ngo=true;ngoing.push_back(i);}
        mynodes.push_back(*(temp));
    }
    int minc=going.size();
    int maxc=going.size();
    for(i=0;i<n;i++)
    {
        for(j=0;j<mynodes[i].m;j++)
        {
            mynodes[mynodes[i].fr[j]].ifr.push_back(i);
        }
    }
    i=minc-1;
    vector<int> myvec=going;
    while(myvec.size()!=0)
    {
        temp=&(mynodes[myvec[i]]);
        myvec.pop_back();
        i--;
        q=0;
        for(j=0;j<temp->ifr.size();j++)
        {
            if(mynodes[temp->ifr[j]].go==false&&mynodes[temp->ifr[j]].ngo==false)
            {
                mynodes[temp->ifr[j]].count++;
                if(mynodes[temp->ifr[j]].count>=mynodes[temp->ifr[j]].t)
                {
                    mynodes[temp->ifr[j]].go=true;
                    myvec.push_back(temp->ifr[j]);
                    going.push_back(temp->ifr[j]);
                    q++;
                }
            }
        }
        i=i+q;
        minc+=q;
    }
    r=ngoing.size();
    myvec=ngoing;
    i=r-1;
    while(myvec.size()!=0)
    {
        temp=&(mynodes[myvec[i]]);
        i--;
        myvec.pop_back();
        q=0;
        for(j=0;j<temp->ifr.size();j++)
        {
            if(mynodes[temp->ifr[j]].go==false&&mynodes[temp->ifr[j]].ngo==false)
            {
                mynodes[temp->ifr[j]].ncount++;
                if(mynodes[temp->ifr[j]].m-mynodes[temp->ifr[j]].ncount<mynodes[temp->ifr[j]].t)
                {
                    mynodes[temp->ifr[j]].ngo=true;
                    myvec.push_back(temp->ifr[j]);
                    ngoing.push_back(temp->ifr[j]);
                    q++;
                }
            }
        }
        i=i+q;
        r+=q;
    }
    maxc=n-r;
    printf("%d %d",minc,maxc);
    return 0;
}
