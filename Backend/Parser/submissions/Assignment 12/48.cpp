#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
    int guys;
    scanf("%d",&guys);
    //cin>>guys;
    vector<vector<int> > guy;
    guy.resize(guys);
    vector<int> threshold;
    threshold.resize(guys);
    vector<int> frnds_count;
    frnds_count.resize(guys);
    int count1=0,count2 = 0;
    queue<int> notGoing;
    queue<int> going;

    for(int i=0; i<guys; i++)
    {
        int t_i;
        int n_i;
        scanf("%d",&t_i);
        scanf("%d",&n_i);
        //cin>>t_i;
        //cin>>n_i;
        threshold[i] = t_i;
        frnds_count[i] = n_i;
        for(int j = 0; j<n_i; j++)
        {
            int frnd;
            scanf("%d",&frnd);
            //cin>>frnd;
            guy[frnd].push_back(i);
        }
        if(threshold[i]>frnds_count[i])
        {
            notGoing.push(i);
            count1++;
        }
        if(threshold[i]==0)
        {
            going.push(i);
            count2++;
        }
    }

    while(!notGoing.empty())
    {
        int k;
        k = notGoing.front();
        for(int i=0; i<guy[k].size(); i++)
        {
            int j=guy[k][i];
            if(frnds_count[j]>=threshold[j])
            {
                frnds_count[j]--;
                if(frnds_count[j]<threshold[j])
                {
                    notGoing.push(j);
                    count1++;
                }
            }
        }
        notGoing.pop();
    }
    while(!going.empty())
    {
        int k = going.front();
        for(int i=0;i<guy[k].size();i++)
        {
            int j=guy[k][i];
            if(threshold[j]!=0)
            {
                threshold[j]--;
                if(threshold[j]==0)
                {
                    going.push(j);
                    count2++;
                }
            }
        }
        going.pop();
    }
    int count3 = guys - count1;
    printf("%d %d\n",count2,count3);
    //cout<<count2<<" "<<count3;
    return 0;
}
