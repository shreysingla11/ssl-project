#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
using namespace std;
int main()
{
    int n,min=0,max=0;
    int nof;//no of friends for single node
    cin>>n;
    vector<bool> visited(n,false);
    vector<bool> visitednotg(n,false);
    queue<int>willgo;
    queue<int>willnotgo;
    vector< vector <int> > hisfris(n);
    vector< vector <int> > heisfris(n);
    vector<int> frisgoing(n,0);
    vector<int> frisnotgoing(n,0);
    vector<int> t(n);
    int temp;
    vector<int> vtemp;
    for(int i=0; i<n; i++)
    {
        scanf("%d",&t[i]);//cin>>t[i];
        scanf("%d",&nof);//cin>>nof;
        vtemp.resize(nof);
        if(t[i]==0)
        {
            willgo.push(i);
            visited[i]=true;
        }
        else if(t[i]>nof)
        {
            willnotgo.push(i);
            visitednotg[i]=true;
        }
        for(int j=0; j<nof; j++)
        {
            scanf("%d",&temp);//cin>>temp;
            vtemp[j]=temp;//.push_back(temp);
        }
        hisfris[i]=vtemp;
        frisnotgoing[i]=nof;
        vtemp.clear();
    }
    for(int i=0; i<n; i++)
    {
        int len=hisfris[i].size();
        for(int j=0; j<len; j++)
        {
            heisfris[hisfris[i][j]].push_back(i);
        }
    }

    //for(int i=0; i<n; i++)
    //{for(int j=0;j<heisfris[i].size();j++)
    // cout<<heisfris[i][j];
    //}


    while(!willgo.empty())
    {
        int inq=willgo.front();
        int len=heisfris[inq].size();
        for(int i=0; i<len; i++)
        {
            if(!visited[heisfris[inq][i]])
            {
                frisgoing[heisfris[inq][i]]++;
                if(t[heisfris[inq][i]]==frisgoing[heisfris[inq][i]])
                {
                    willgo.push(heisfris[inq][i]);
                    visitednotg[heisfris[inq][i]]=true;
                }
            }
        }
        willgo.pop();
        min=min+1;
    }
    while(!willnotgo.empty())
    {
        int inq=willnotgo.front();
        int len=heisfris[inq].size();
        for(int i=0; i<len; i++)
        {
            if(!visitednotg[heisfris[inq][i]])
            {
                frisnotgoing[heisfris[inq][i]]--;
                if(t[heisfris[inq][i]] > frisnotgoing[heisfris[inq][i]])
                {
                    willnotgo.push(heisfris[inq][i]);
                    visitednotg[heisfris[inq][i]]=true;
                }
            }
        }
        willnotgo.pop();
        max=max+1;
    }
    cout<<min<<" "<<n-max<<endl;
    return 0;
}
