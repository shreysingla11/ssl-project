#include <stdio.h>
#include <vector>
#include <stack>
using namespace std;
int main()
{
    int n,yes=0,no=0,temp;
    scanf ("%d",&n);
    stack<int> yup;
    stack<int> nah;
    vector<int> bud(n);
    vector<int> dub(n);
    vector<bool> visit(n,false);
    vector<bool> revisit(n,false);
    int *t=new int[n];
    int *f=new int[n];
    int **adj=new int*[n];
    vector<vector<int> > rev(n);
    for(int i=0;i<n;i++)
    {
        scanf ("%d",&t[i]);
        scanf ("%d",&f[i]);
        if(t[i]==0)
        {
            yup.push(i);
            visit[i]=true;
            yes++;
        }
        if(t[i]>f[i])
        {
            nah.push(i);
            revisit[i]=true;
            no++;
        }
        adj[i]=new int[f[i]];
        dub[i]=f[i];
        for(int j=0;j<f[i];j++)
        {
            scanf ("%d",&adj[i][j]);
            rev[adj[i][j]].push_back(i);
        }
    }
    while(!yup.empty())
    {
        temp=yup.top();
        yup.pop();
        for(int k=0;k<rev[temp].size();k++)
        {
            bud[rev[temp][k]]++;
            if(bud[rev[temp][k]]>=t[rev[temp][k]] && !visit[rev[temp][k]])
            {
                yup.push(rev[temp][k]);
                visit[rev[temp][k]]=true;
                yes++;
            }
        }
    }
    while(!nah.empty())
    {
        temp=nah.top();
        nah.pop();
        for(int k=0;k<rev[temp].size();k++)
        {
            dub[rev[temp][k]]--;
            if(dub[rev[temp][k]]<t[rev[temp][k]] && !revisit[rev[temp][k]])
            {
                nah.push(rev[temp][k]);
                revisit[rev[temp][k]]=true;
                no++;
            }
        }
    }
    printf ("%d %d\n",yes, n-no);
    return 0;
}
