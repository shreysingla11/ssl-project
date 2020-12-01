#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<vector>

using namespace std;

class distinct
{
    public:
        struct node
        {
            node *next;
            vector<int> vec1;
            vector<int> vec2;
        };
        struct abc
        {
            int val;
            int i1;
            int i2;
        };
        node *nx=new node();
        node *nx1=new node();
        int xx,yy;
        int nn;
        vector<int> l;
        map<int,int> m;
        map<int,int>::iterator m_it;
        map<int,abc> map_1;
        map<int,abc>::iterator map_it;
        vector<vector<int> > vv1;
        vector<vector<int> > vv2;
        distinct(vector<int> &vec)
        {
            nn=vec.size();
            for(int i=0;i<nn;i++)
            {
                if(m.find(vec[i])==m.end())
                {
                    l.push_back(-1);
                    m[vec[i]]==i;
                }
                else
                {
                    l.push_back(m[vec[i]]);
                    m[vec[i]]=i;
                }
            }

            int t=0;
            int bb,ss=-1;
            int nnn=0;
            while(nnn<nn)
            {
                if(l[nnn]>=nn/2){t++;nx->vec2.push_back(ss);bb=nnn;}
                else {nx->vec2.push_back(bb);ss=nnn;}
                nx->vec1.push_back(t);
                nnn++;
            }
            nx->next=addnode(2);
        }

        node * addnode(int i)
        {
            map_1.clear();
            node *n=new node();
            //cout<<1<<"\n";
            if (pow(2,i)>nn)
            {
                return NULL;
            }
            //int x=n/(pow(2,i-1));
            int k;
            for(int j=0;j<nn;j++)
            {
                k=l[j]*pow(2,i-1)/nn;
                //cout<<3<<"\n";
                map_it=map_1.find(k);
                //cout<<7<<"\n";
                if(map_it!=map_1.end())
                {
                    if(l[j]>=(k*nn/pow(2,i-1))+(nn/pow(2,i)))
                    {
                        n->vec2.push_back(map_it->second.i1);
                        map_it->second.val++;map_it->second.i2=j;
                    }

                 else
                 {
                    n->vec2.push_back(map_it->second.i1);
                    map_it->second.i1=j;
                    }

                 n->vec1.push_back(map_it->second.val);
                 //cout<<6<<"\n";
                }

            else
                {
                 map_1[k].val=0;
                 map_1[k].i1=-1;
                 map_1[k].i2=-1;
                 //cout<<9<<"\n";
                 if(l[j]>=(k*nn/pow(2,i-1))+(nn/pow(2,i)))
                 {
                    n->vec2.push_back(map_1[k].i1);
                    map_1[k].val++;
                    map_1[k].i2=j;
                    }
                 else
                 {
                    n->vec2.push_back(map_1[k].i2);
                    map_1[k].i1=j;
                    }
                 //cout<<8<<"\n";
                 int tmp=map_1[k].val;
                 //cout<<5<<"\n";
                 n->vec1.push_back(tmp);

                 //cout<<7<<"\n";
                }
           //     cout<<5<<"\n";
            }
         n->next=addnode(i+1);
         return n;

        }

    int ans;
    int num_distinct(int i,int j)
    {
        ans=0;

        for(int k=i;k<=j;k++)
        {
            if(l[k]>=i) ans++;
        }
        return j-i+1-ans;
        /*
        int mid=nn/2;
        nx1=nx;
        if(i<mid)
        {
            ans=ans+nx1->vec1[j];
            if(j<mid) numDist(i,j,nx1->next,mid/2);
            else numDist(i,nx1->vec2[j],nx1->next,mid/2);
        }
        else
        {
            numDist(i,nx1->vec2[j],nx1->next,3*mid/2);
        }
        return j-i+1-ans;*/
    }

    void numDist(int i,int j,node * np,int mid)
    {/*
        if(j==-1) return ;
        if(np->next==NULL)
        {
            if(i<mid){ans=ans+np->vec1[j];}
            return ;
        }
        if(i<mid)
        {
            ans=ans+nx1->vec1[j];
            if(j<mid) numDist(i,j,nx1->next,mid/2);
            else numDist(i,nx1->vec2[j],nx1->next,mid/2);
        }
        else
        {
            numDist(i,nx1->vec2[j],nx1->next,3*mid/2);
        }*/
    }

};


