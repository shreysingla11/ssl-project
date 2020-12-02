#include <vector>
#include <stack>
#include <cstdio>

using namespace std;

class node
{
public:
	int index;
	int n_friends;
	int t_i;
	int n_friends_going;
	int n_friends_notgoing;
	int pred_f;
	bool visited;
	node()
	{
		n_friends_going=0;
		n_friends_notgoing=0;
		pred_f=0;
		visited=false;
	}
	vector<int> pred;
	vector<int> friends;
};

int main()
{
	int n,a,b,temp;
	int tot_going,tot_not_go;
	scanf("%d",&n);
	//cin>>n;
	vector<node> guys(n);
	stack<int> def_going;
	stack<int> def_not_going;
	tot_going=tot_not_go=0;
	for (int i=0;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		guys[i].index=i;
		guys[i].t_i=a;
		guys[i].n_friends=b;
		guys[i].friends.resize(b);
		if (a > b && !guys[i].visited)
		{
			def_not_going.push(i);
			guys[i].visited=true;
			tot_not_go++;
		}
		else if (a==0 && !guys[i].visited)
		{
			def_going.push(i);
			guys[i].visited=true;
			tot_going++;
		}
		for (int j=0;j<b;j++)
		{
			scanf("%d",&temp);
			guys[i].friends[j]=temp;
			guys[temp].pred.push_back(i);
			guys[temp].pred_f++;
		}
	}
	while(!def_going.empty())
	{
		temp=def_going.top();
		def_going.pop();
		for (int i=0;i<guys[temp].pred_f;i++)
		{
			guys[guys[temp].pred[i]].n_friends_going++;
			if (guys[guys[temp].pred[i]].n_friends_going >= guys[guys[temp].pred[i]].t_i && !guys[guys[temp].pred[i]].visited)
			{
				def_going.push(guys[temp].pred[i]);
				guys[guys[temp].pred[i]].visited=true;
				tot_going++;
			}
		}
	}
	while(!def_not_going.empty())
	{
		temp=def_not_going.top();
		def_not_going.pop();
		for (int i=0;i<guys[temp].pred_f;i++)
		{
			guys[guys[temp].pred[i]].n_friends_notgoing++;
			if (guys[guys[temp].pred[i]].n_friends_notgoing > guys[guys[temp].pred[i]].n_friends - guys[guys[temp].pred[i]].t_i  && !guys[guys[temp].pred[i]].visited)
			{
				def_not_going.push(guys[temp].pred[i]);
				guys[guys[temp].pred[i]].visited=true;
				tot_not_go++;
			}
		}
	}
	printf("%d"" ""%d\n",tot_going,n-tot_not_go);
	return 0;
}
