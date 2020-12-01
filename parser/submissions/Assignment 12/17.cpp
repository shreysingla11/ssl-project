#include<iostream>
#include<vector>
#include<stack>
#include<cstdio>
using namespace std;
int main()
{
	int N;
    scanf("%d",&N);
    stack<int>  wg;
    stack<int> wng;
    vector<vector<int> > Network(N);
    for(int i=0;i<N;i++)
    {
       	Network[i].push_back(0);
    	Network[i].push_back(0);
    	Network[i].push_back(0);
    	Network[i].push_back(0);

    }
    for(int i=0;i<N;i++)
    {
    	int t_i,n_i;
    	scanf("%d%d",&t_i,&n_i);
    	Network[i][1]=t_i;
    	Network[i][2]=t_i;
    	Network[i][3]=n_i;
    	int a=-1;
    	if(t_i==0)
    	{
    		wg.push(i);
    		Network[i][0]=1;
    	}
    	else
        {
    		if(t_i>n_i)
    		{
    			wng.push(i);
    			Network[i][0]=1;
    		}
        }
    	for(int j=0;j<n_i;j++)
    	{
    		scanf("%d",&a);
    		Network[a].push_back(i);
    	}


    }
    //
    int temp=-1,min=0,max=N;
    while(wg.size()!=0)
    {
    	temp=wg.top();
    	wg.pop();
    	min++;
    	for(int i=4;i<Network[temp].size();i++)
    	{
    		Network[Network[temp][i]][2]--;
    		if(Network[Network[temp][i]][2]==0 && Network[Network[temp][i]][0]!=1)
    		{
    			wg.push(Network[temp][i]);
    			Network[Network[temp][i]][0]=1;
    		}
    	}

    }
    while(wng.size()!=0)
    {
    	temp=wng.top();
    	wng.pop();
    	max--;
    	for(int i=4;i<Network[temp].size();i++)
    	{
    		Network[Network[temp][i]][3]--;
    		if(Network[Network[temp][i]][3]<Network[Network[temp][i]][1] && Network[Network[temp][i]][0]!=1)
    		{
    			wng.push(Network[temp][i]);
    			Network[Network[temp][i]][0]=1;
    		}
    	}
    }
    printf("%d %d\n",min,max);
    return 0;
}