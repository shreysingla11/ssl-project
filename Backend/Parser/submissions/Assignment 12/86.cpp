#include <iostream>
#include <vector>
#include <stack>
#include <cstdio>
using namespace std;
int main()
{
    int n,ti,nf,a,countmin=0,countmax=0;
    scanf("%d",&n);
    vector< vector<int> > v(n);
    vector< vector<int> > s(n);
    stack<int>  min,max;
    bool* b=new bool[n];
    bool* b1=new bool[n];
    for(int i=0; i<n; i++)
    {   b[i]=0;
        //b1[i]=0;
        scanf("%d",&ti);
        scanf("%d",&nf);
        s[i].push_back(ti);
        s[i].push_back(nf);
        if(ti>nf)
        {
            max.push(i);
            b[i]=1;
            countmax++;
        }
        else if(ti==0)
        {
            min.push(i);
            b[i]=1;
            countmin++;
        }
        for(int j=0; j<nf; j++)
        {
            scanf("%d",&a);
            v[a].push_back(i);
        }
    }
    while(!max.empty())
    {
        int i = max.top();
        max.pop();
        for(int j=0; j<v[i].size(); j++)
        {
            s[v[i][j]][1]--;
            if((s[v[i][j]][1]<s[v[i][j]][0])&&(b[v[i][j]]==0))
            {
                    max.push(v[i][j]);
                    b[v[i][j]]=1;
                    countmax++;
            }
        }
    }
    while(!min.empty())
    {
        int i = min.top();
        min.pop();
        for(int j=0; j<v[i].size(); j++)
        {
            s[v[i][j]][0]--;
            if((s[v[i][j]][0]==0)&&(b[v[i][j]]==0))
            {

                    min.push(v[i][j]);
                    b[v[i][j]]=1;
                    countmin++;

            }
        }
    }
    cout<<countmin<<" "<<n-countmax<<endl;
    return 0;
}
