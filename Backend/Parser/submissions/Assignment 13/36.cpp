#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<utility>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    int ** c = new int * [n];
    for(int i = 0; i<n; i++)
    {
        c[i] = new int [n];
        for(int j = 0; j<n; j++)
        {
            scanf("%d", &c[i][j]);
        }
    }
    int ** a = new int * [n];
    vector<vector< bool > > inq(n);
    for(int i = 0; i<n; i++)
    {
        a[i] = new int [2*n+1];
        for(int j = 0; j<2*n+1; j++)
        {
            inq[i].push_back(false);
            a[i][j] = -1;
        }
    }
    a[0][n] = 0;
    inq[0][n] = true;
    queue< pair<int,int> > q;
    q.push(make_pair(0,n));
    pair <int,int > v;
    int g;
    int vertex;
    while(!q.empty())
    {
        v = q.front();
        vertex = v.first;
        g = v.second;
        q.pop();
        inq[vertex][g] = false;
        //cout<<vertex<<" "<<g<<endl;
        //cout<<"hirtrgyi"<<endl;
        for(int i = 0; i<n; i++)
        {

            if(c[vertex][i]<0)
            {
                //if(g+1<2*n+1)
                //{
                    if(a[i][g+1] == -1)
                    {
                        a[i][g+1] = a[vertex][g]-c[vertex][i];
                       // if(inq[i][g+1]==false)
                        //{

                            q.push(make_pair(i,g+1));
                            inq[i][g+1] = true;
                        //}
                    }
                    else if(a[vertex][g]-c[vertex][i]<a[i][g+1])
                    {
                        a[i][g+1] = a[vertex][g]-c[vertex][i];
                       if(inq[i][g+1]==false)
                        {
                            q.push(make_pair(i,g+1));
                            inq[i][g+1] = true;
                        }
                    }
                //}
            }
            if(c[vertex][i]>0)
            {
                //if(g-1>-1)
                //{
                    if(a[i][g-1] == -1)
                    {
                        a[i][g-1] = a[vertex][g]+c[vertex][i];
                        //if(inq[i][g-1]==false)
                        //{
                            q.push(make_pair(i,g-1));
                            inq[i][g-1] = true;
                        //}
                    }
                    else if(a[vertex][g]+c[vertex][i]<a[i][g-1])
                    {
                        a[i][g-1] = a[vertex][g]+c[vertex][i];
                        if(inq[i][g-1]==false)
                        {
                            q.push(make_pair(i,g-1));
                            inq[i][g-1] = true;
                        }
                    }
                //}
            }
        }
    }

    int answer;
    for(int i=0; i<n; i++)
    {
        int j=n;
        for(; j<2*n+1; j++)
        {
            if(a[i][j]!=-1)
            {
                break;
            }
        }
        if(j==2*n+1)
        {
            printf("infinity\n");
        }
        else
        {
            answer=a[i][j];
            for(int k=j+1; k<2*n+1; k++)
            {
                if(a[i][k]<answer&&a[i][k]!=-1){
                    answer=a[i][k];
                }
            }
            printf("%d\n",answer);
        }
    }
}
