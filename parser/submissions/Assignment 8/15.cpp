#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

struct node{
	float st,et;
	};
	
bool comp(node n1, node n2)	{
	if(n1.st == n2.st)
		return n1.et < n2.et;
	return n1.st < n2.st;
	};

void cannot_launch(float & st, float & et, int l, int p, char d, int ln, int w, int u, int v)
{
	if(d == 'W')
	{
		float tmp = p;
		st = tmp/u;
		tmp = l;
		et = l/u;
		tmp = ln;
		
		tmp = tmp*w/v;
		
		st = st-tmp;
		et = st+et;
		tmp = w;
		tmp = tmp/v;
		st = st-tmp; 
	}
	else
	{
		float tmp = p;
		st = tmp*(-1)/u;
		tmp = l;
		et = l/u;
		tmp = ln;
		
		tmp = tmp*w/v;
		
		st = st-tmp;
		et = st+et;	
		tmp = w;
		tmp = tmp/v;
		st = st-tmp;
	}	
}

float interval(vector<node> & vec, float & a, float & b, int t1, int t2)
{
	vector<node>::iterator it1,it2;
	float d=0;
	
	it1 = vec.begin();
	it2 = vec.begin();
	it2++;
	while(it2 != vec.end())
	{
		if(it1->et < it2->st) 
		{
			if(d < (it2->st - it1->et) && t1 <= it1->et && t2 >= it2->st)
			{
				a = it1->et;
				b = it2->st;
				d = b-a;
			}		
		}
		
		it1++;
		it2++;	
	}
	
	return d;	
}




int main()
{
	int n,w,u,v,t1,t2;
	cin>>n>>w>>u>>v>>t1>>t2;
	
	char dir[n];
	int m[n];
	vector<vector<int> > ships;
	vector<int> temp;
	int l,p;
	
	for(int i=0; i<n; i++)
	{
		cin>>dir[i];
		cin>>m[i];
		
		temp.clear();
		for(int j=0; j<m[i]; j++)
		{
			cin>>l>>p;
			temp.push_back(l);
			temp.push_back(p);	
		}
		
		ships.push_back(temp);	
	}
	
	vector <node> vec;
	node tmp;
	float st, et;
	//cout<<endl;
	for(int i=0; i<n; i++)
	{
	
		for(int j=0; j<m[i]; j++)
		{
			cannot_launch(tmp.st,tmp.et,ships[i][2*j],ships[i][2*j+1],dir[i],i,w,u,v);
			vec.push_back(tmp);	
		}
	}
	
	sort(vec.begin(),vec.end(),comp);
	float result,a=0,b=0;
	result = interval(vec,a,b,t1,t2);
	
	printf("%0.8f",result);
	//cout<<result;
	
	return 0;	
}
