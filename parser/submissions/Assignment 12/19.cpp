#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    std::vector<int> t;
    std::vector<int> num;
    std::vector<std::vector<int> >friends;

    int n;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
    	int temp;
    	cin>>temp;
    	t.push_back(temp);
    	cin>>temp;
    	num.push_back(temp);

    	std::vector<int> v;
    	for (int j = 0; j < num.back(); ++j)
    	{
            int temp2;
            cin>>temp2;
    		v.push_back(temp2);

    	}

    	friends.push_back(v);


    }


    std::vector<std::vector<int> > friends2(n);
    for (int i = 0; i < n; ++i)
    {
    	/* code */
    	for (std::vector<int>::iterator it = friends[i].begin();it!= friends[i].end();it++)
    	{

                /* code */
    		friends2[*it].push_back(i);
    	}
    }

    std::vector<int> thres(n);
    for (int i = 0; i < n; ++i)
    {
    	/* code */
    	thres[i]=t[i];
    }
    int min=0;
    queue<int> q;
    vector<bool> visited(n,0);
    for (int i = 0; i < n; ++i)
    {
    	/* code */
    	if (t[i]==0)
    	{
    		/* code */
    		q.push(i);
    		visited[i]=1;
    		min++;
    	}

    }
    while(!q.empty())
    {
    	int k = q.front();
		for (std::vector<int>::iterator it = friends2[k].begin();it!= friends2[k].end();it++)
    	{

    		/* code */
    		thres[*it]--;
    		if(thres[*it]==0)
    		{
                if(!visited[*it])
    			{q.push(*it);
    			min++;
    			visited[*it]=1;}
    		}
    	}
        q.pop();
    }

    std::vector<int> nump(n);
    for(int i=0;i<n;i++)
    {
        nump[i]=num[i];
    }


    queue<int> q2;
    int max = n;

    for (int i = 0; i < n; ++i)
    {
    	/* code */
    	if(t[i]>num[i])
    	{

    		q2.push(i);
    		visited[i]=1;
    		max--;

    	}
    }

    while(!q2.empty())
    {
    	int k =q2.front();
    	for (std::vector<int>::iterator i = friends2[k].begin(); i != friends2[k].end(); ++i)
    	{
    		nump[*i]--;
    		if(nump[*i]<t[*i])
    		{
                if(!visited[*i])
    			{q2.push(*i);
    			max--;
    			visited[*i]=1;}
    		}
    	}
    	q2.pop();
    }

    cout<< min << " " << max <<endl;
}
