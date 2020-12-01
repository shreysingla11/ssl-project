#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>
using namespace std;
struct pai
{
    int g;
    int data;
};
int main()
{

    int N;
    cin>>N;
    vector<vector<int> > mat(N, vector<int>(N,1));

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin>>mat[i][j];
        }
    }

    vector<vector<int> >good;

    for(int g=1; g<=2*N+1; g++)
    {
        vector<int>v2;
        (good).push_back(v2);
        for(int w=0; w<N; w++)
        {
            if(w==0)
            {
                (((good.back())).push_back(0));
            }
            else
            {
                (((good.back())).push_back(INT_MAX));
            }
        }
    }

    queue<pai> q;
    pai p;
    p.g=N;
    p.data=0;
    q.push(p);
    while(!q.empty())
    {
        for(int i=0; i<N; i++)
        {
            if(mat[q.front().data][i]>0)
            {
                if(mat[q.front().data][i] + good[q.front().g][q.front().data] < good[q.front().g - 1][i])
                {
                    good[q.front().g - 1][i] = mat[q.front().data][i] + good[q.front().g][q.front().data];
                    pai p;
                    p.data=i;
                    p.g=q.front().g - 1;
                    q.push(p);
                }
            }

            if(mat[q.front().data][i]<0)
            {
                if(-mat[q.front().data][i] + good[q.front().g][q.front().data] < good[q.front().g + 1][i])
                {
                    good[q.front().g + 1][i] = -mat[q.front().data][i] + good[q.front().g][q.front().data];
                    pai p;
                    p.data=i;
                    p.g=q.front().g + 1;
                    q.push(p);
                }
            }
        }
        q.pop();
    }
    for(int j=0;j<N;j++){
    int mi=INT_MAX;
    for(int i=N;i<=2*N+1;i++){
            if(good[i][j]<mi){mi=good[i][j];}
        }
        cout<<mi<<endl;
    }
}
