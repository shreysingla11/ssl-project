#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<limits.h>

using namespace std;

vector< vector<int> > w;
//vector< vector<int> > oldvec,newvec;
int INF = INT_MAX;

struct vt
{
    int num;
    vector<int> label;
    vector<bool> is_good;
    vt(int s)
    {
         label.resize(4*s+1,INF);
        is_good.resize(4*s+1, false);
    }
};
struct in_q
{
    int q_num;
    int good;
};
queue<in_q> q;
vector<vt> v;
int main()
{
    int n,temper;
    vector<int> temp_vec;
    cin>>n;
    //v.resize(n*n*n,vector<vector<int> >(n, vector<int>(4*n+1,INF)));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d", &temper);
            temp_vec.push_back(temper);
        }
        w.push_back(temp_vec);
        temp_vec.clear();
    }

    vt temp_vt(n);
    for(int i=0;i<n;i++)
    {
        temp_vt.num = i;
        v.push_back(temp_vt);
    }

    in_q v1;
    v1.q_num = 0;
    v1.good = 2*n;
    v[0].is_good[2*n] = true;
    v[0].label[2*n] = 0;
    q.push(v1);


    while(!q.empty())
    {
        in_q temp = q.front();
        for(int i=0;i<n;i++)
        {
            if(w[temp.q_num][i] < 0)
            {
                if(temp.good<4*n && v[temp.q_num].label[temp.good] - w[temp.q_num][i] < v[i].label[temp.good + 1])
                {
                    v[i].label[temp.good + 1] = v[temp.q_num].label[temp.good] - w[temp.q_num][i];
                    if(!v[i].is_good[temp.good + 1])
                    {
                        v[i].is_good[temp.good + 1] = true;
                        in_q temp2;
                        temp2.q_num = i;
                        temp2.good = temp.good + 1;
                        q.push(temp2);
                    }
                }
            }
            if(w[temp.q_num][i] > 0)
            {
                if(temp.good>0 && v[temp.q_num].label[temp.good] + w[temp.q_num][i] < v[i].label[temp.good - 1])
                {
                    v[i].label[temp.good - 1] = v[temp.q_num].label[temp.good] + w[temp.q_num][i];
                    if(!v[i].is_good[temp.good - 1])
                    {
                        v[i].is_good[temp.good - 1] = true;
                        in_q temp2;
                        temp2.q_num = i;
                        temp2.good = temp.good - 1;
                        q.push(temp2);
                    }
                }
            }
        }
        v[temp.q_num].is_good[temp.good] = false;
        q.pop();
    }

    //cout<<"hello"<<endl;
    for(int i=0;i<n;i++)
    {
        int asd = INF;
        for(int j=2*n;j<4*n+1;j++)
        {
            asd = min(asd,v[i].label[j]);
        }
        if(asd>=1999999999)
        {
            printf("infinity\n");
        }
        else
            printf("%d\n", asd);
    }
    return 0;
}
