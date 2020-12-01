#include<iostream>
#include<vector>
#include <stack>
#include<stdio.h>
using namespace std;

int main()
{
    int n,top,s=0,r=0,temp;
    stack<int> first;
    stack<int> second;
    scanf("%d",&n);
    int *t=new int[n];
    int *ni=new int[n];

    vector<vector<int> > b(n);
    vector<int> v(n,0);
    vector<int> w(n,0);
    vector<bool> bl(n,false);



    for(int i=0; i<n; i++)
    {

        scanf("%d %d",&t[i],&ni[i]);
        if(t[i]==0)
        {
            s++;
            first.push(i);
            bl[i]=true;
        }

        for(int j=0; j<ni[i]; j++)
        {

            scanf("%d",&temp);
            b[temp].push_back(i);
        }
    }


    while (!first.empty())
    {
        top=first.top();
        first.pop();
        for(int k=0; k<b[top].size(); k++)
        {
            v[b[top][k]]++;


            if((t[b[top][k]]<=v[b[top][k]])&&(bl[b[top][k]]==false))
            {
                first.push(b[top][k]);
                bl[b[top][k]]=true;
                s++;
            }

        }

    }

    for(int i=0; i<n; i++)
    {
        bl[i]=false;
        if(t[i]>ni[i])
        {
            r++;
            second.push(i);
            bl[i]=true;
        }
    }
    while(!second.empty())
    {
        top=second.top();
        second.pop();
        for(int k=0; k<b[top].size(); k++)
        {
            ni[b[top][k]]--;


            if((t[b[top][k]]>ni[b[top][k]])&&(bl[b[top][k]]==false))
            {
                second.push(b[top][k]);
                bl[b[top][k]]=true;
                r++;
            }

        }
    }

    cout<<s<<" "<<n-r<<endl;

    return 0;
}
