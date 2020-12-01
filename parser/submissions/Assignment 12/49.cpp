#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    vector<int> thresh(n);
    vector<int> thr1(n);
    vector<int> num_friend(n);
    //vector<vector<int> > fd(n);
    vector<vector<int> > invfd(n);
    vector<bool> vb(n,false);
    vector<bool> vc(n,false);
    vector<int> go;
    vector<int> cancel;

    int a,b,c;
    int i=0,j=0;
    while(i<n)
    {
        scanf("%d%d",&a,&b);
        thresh[i]=a;
        thr1[i]=a;
        num_friend[i]=b;
        if(a==0){go.push_back(i);vb[i]=true;}
        else if(b<a){ cancel.push_back(i);vc[i]=true;}
        j=0;

        while(j<b)
        {
            scanf("%d",&c);
            //fd[i].push_back(c);
            invfd[c].push_back(i);
            j++;
        }
        i++;
    }

    i=0;
    int gs=go.size();
    while(i<gs)
    {
        for(int k=0;k<invfd[go[i]].size();k++)
        {
            if(vb[invfd[go[i]][k]]==false)
            {
                thresh[invfd[go[i]][k]]--;
                if(thresh[invfd[go[i]][k]]<=0){go.push_back(invfd[go[i]][k]);gs++;vb[invfd[go[i]][k]]=true;}
            }
        }
        i++;
    }

    i=0;
    int cs=cancel.size();
    while(i<cs)
    {
        for(int k=0;k<invfd[cancel[i]].size();k++)
        {
            if(vc[invfd[cancel[i]][k]]==false)
            {
                thr1[invfd[cancel[i]][k]]++;
                if(thr1[invfd[cancel[i]][k]]>num_friend[invfd[cancel[i]][k]]){cancel.push_back(invfd[cancel[i]][k]);cs++;vc[invfd[cancel[i]][k]]=true;}
            }
        }
        i++;
    }
    int xx=go.size();
    int yy=cancel.size();
    printf("%d %d\n",xx,n-yy);
}
