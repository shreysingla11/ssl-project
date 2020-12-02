#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
using namespace std;

int main()
{
    vector<vector<int> > G;
    vector<int> t_i;
    vector<int> nfg;
    vector<int> npg;
   // vector<int> n_i;
    vector<int> status;
    vector<int> qstatus;
    queue<int> q;

    int n,i,j,t,temp_t_i,temp_n_i,temp_f;

   // cin>>t;
    scanf("%d",&t);

    G.resize(t);

    for(i=0; i<t; i++)
    {
       // cin>>temp_t_i>>temp_n_i;
       scanf("%d",&temp_t_i);
       scanf("%d",&temp_n_i);
        t_i.push_back(temp_t_i);
     //   n_i.push_back(temp_n_i);
        nfg.push_back(0);
        npg.push_back(temp_n_i);
        status.push_back(0);
        qstatus.push_back(0);

        for(j=0; j<temp_n_i; j++)
        {
            //cin>>temp_f;
            scanf("%d",&temp_f);
            G[temp_f].push_back(i);
        }
    }


    for(i=0; i<t; i++)
    {
        if(t_i[i]<=0)
        {
            q.push(i);
            qstatus[i]=1;
            status[i]=1;
            continue;
        }
        if(t_i[i]>npg[i])
        {
            q.push(i);
            qstatus[i]=1;
            status[i]=2;
            continue;
        }
    }

    int gc=0,ngc=0;

    while(!q.empty())
    {
        int num=q.front();
        if(status[num]==1)
        {
            int nofn=G[num].size();
            for(i=0; i<nofn; i++)
            {
                nfg[G[num][i]]++;
            }
            for(i=0; i<nofn; i++)
            {
                if((t_i[G[num][i]]<=nfg[G[num][i]])&&(qstatus[G[num][i]]==0))
                {
                    qstatus[G[num][i]]=1;
                    status[G[num][i]]=1;
                    q.push(G[num][i]);
                }
            }
            qstatus[num]=2;
            q.pop();
            gc++;
        }
        else
        {
        int nofn=G[num].size();
        for(i=0; i<nofn; i++)
            {
                npg[G[num][i]]--;
            }

            for(i=0; i<nofn; i++)
            {
                if((t_i[G[num][i]]>npg[G[num][i]])&&(qstatus[G[num][i]]==0))
                {
                    qstatus[G[num][i]]=1;
                    status[G[num][i]]=2;
                    q.push(G[num][i]);
                }
            }
            qstatus[num]=2;
            q.pop();
            ngc++;
        }
    }

    //cout<<gc<<" "<<(t-ngc)<<endl;
    printf("%d %d\n",gc,(t-ngc));

    return 0;
}
