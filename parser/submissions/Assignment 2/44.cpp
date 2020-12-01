#include<iostream>
#include<vector>
#include<utility>
#include<stdio.h>
using namespace std;
bool check_intersection(pair<int,int>,pair<int,int>,pair<int,int>,pair<int,int>);
int main()
{
    vector<std::pair<int,int> > r,b,data;
    int n,x,y;
    cin>>n; cout<<"\n";
    n = n/2;
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&x,&y);
        r.push_back(make_pair(x,y));
    }
    //cout<<"got a\n";
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&x,&y);
        b.push_back(make_pair(x,y));
    }
    //cout<<"got b\n";
    for(int i=0;i<n;i++)
    {
        data.push_back(make_pair(i,i));
    }
    //cout<<"done 1\n";
    bool p,q = true;
    int temp;
    for(int i=0;i<n-1;i++)
    {
        q = true;
        while(q)
        {
            for(int j=i;j<n;j++)
            {
                p = check_intersection(r[data[i].first],b[data[i].second],r[data[j].first],b[data[j].second]);
                if(p)
                {
                    temp = data[i].second;
                    data[i].second = data[j].second;
                    data[j].second = temp;
                    break;
                }
            }
            if(p == false)
                q = false;
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%d %d \n",data[i].first,data[i].second);
    }
    return 1;
}


bool check_intersection(pair<int,int> r1,pair<int,int> b1,pair<int,int> r2,pair<int,int> b2)
{
    float m1,m2,x,y;
    if(b1.first != r1.first)
    {
        m1 = (b1.second-r1.second)/(b1.first-r1.first);
        if(b2.first != r2.first)
        {
            m2 = (b2.second-r2.second)/(b2.first-r2.first);
            if(m1 == m2)
            {
                return false;
            }
            else
            {
                x = ((r1.second-r2.second)-(m1*r1.first)+(m2*r2.first))/(m2-m1);
                y = ((m2*r1.second)-(m1*r2.second)+((m1*m2)*(r2.first-r1.first)))/(m2-m1);
                if((r1.first-x)*(x-b1.first)<0)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
        else
        {
            x = r2.first;
            y = m1*(x-r1.first)+r1.second;
            if((r1.first-x)*(x-b1.first)<0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    else
    {
        x = r1.first;
        if(b2.first != r2.first)
        {
            m2 = (b2.second-r2.second)/(b2.first-r2.first);
        }
        else
        {
            return false;
        }
        y = m2*(x-r2.first)+r2.second;
        if((r1.first-x)*(x-b1.first)<0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
















