#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
	int n=0,i=0,j=0,tempNum=0;

	scanf("%d",&n);
	vector<vector<int> > friendsOf(n);
	vector<int> t_i(n);
	vector<int> n_i(n);
	vector<int> c_i(n);
	vector<int> going;
	vector<int> notGoing;

	for(i=0;i<n;i++)
	{
		scanf("%d",&t_i[i]);
		//cin>>t_i[i];
		scanf("%d",&n_i[i]);
		//cin>>n_i[i];
		for(j=0;j<n_i[i];j++)
		{
			scanf("%d",&tempNum);
			//cin>>tempNum;
		//	friendsWith[i].push_back(tempNum);
			friendsOf[tempNum].push_back(i);
		}
		if(t_i[i]==0)
		{
//			goingData[i] = 1;
			going.push_back(i);
		}
		else if(t_i[i]>n_i[i])
		{
//			goingData[i] = -1;
			notGoing.push_back(i);
		}
	}


	i=0;
	j=0;
	tempNum=0;

	while(i!=going.size())
	{
		for(j=0;j<friendsOf[going[i]].size();j++)
		{
			tempNum = (friendsOf[going[i]])[j];
			if(c_i[tempNum]!=t_i[tempNum])
			{
				c_i[tempNum]++;
				if(c_i[tempNum]==t_i[tempNum])
				{
					going.push_back(tempNum);
				}
			}
		}
		i++;
	}
	
	i=0;
	j=0;
	tempNum=0;

	while(i!=notGoing.size())
	{
		for(j=0;j<friendsOf[notGoing[i]].size();j++)
		{
			tempNum = (friendsOf[notGoing[i]])[j];
			if(t_i[tempNum]<=n_i[tempNum])
			{
				n_i[tempNum]--;
				if(t_i[tempNum]>n_i[tempNum])
				{
					notGoing.push_back(tempNum);
				}
			}
		}
		i++;
	}

	//cout<<"naveen"<<endl;
	cout<<going.size()<<" "<<n-notGoing.size()<<endl;

	return 0;

}
