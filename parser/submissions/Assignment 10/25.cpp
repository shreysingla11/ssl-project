#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class distinct
{
	vector<int> a;
	vector<int> l;
	vector<vector<int> > L;
	//vector<vector<int> > k;
	void create_levels(vector<vector<int> > &m,vector<vector<int> > &k,int n)
	{
		if(n==0)
			return;
		vector<int> m0,k0;
		int largestkgreater=-1;
		int largestkless=-1;
		m0.push_back(0);
		k0.push_back(-1);
		for(int jt=1;jt<n;jt++)
			if(l[jt]>=n/2)
				{
					m0.push_back(m0.back()+1);
					largestkgreater=jt;
					k0.push_back(largestkless);					
				}
			else
				{

					m0.push_back(m0.back());
					k0.push_back(largestkgreater);
					largestkless=jt;
				}
		m.push_back(m0);
		k.push_back(k0);
		create_levels(m,k,n/2);
		return;
	}
public:
	distinct(vector<int> init)
	{
		a=init;
		int it,jt,n=init.size();
		vector<pair<int,int> > ab;
		for(it=0;it<n;it++)
			{
				ab.push_back(pair<int,int> (init[it],it));
			}
		sort(ab.begin(),ab.end());
		l=vector<int> (init.size(),-1);
		for(it=1;it<n;it++)
		{	
			if(ab[it].first==ab[it-1].first){
				l[ab[it].second]=ab[it-1].second;
			}
		}
		vector<int> l1;
		for(int i=0;i<n;i++)
		{
			l1.push_back(0);
			for(int j=i;j<n;j++)
			{
				if(l[j]>=i)
					l1.push_back(l1.back()+1);
				else
					l1.push_back(l1.back());
			}
			L.push_back(l1);
			l1.clear();
		}
		//create_levels(m,k,n);
	}
	int num_distinct(int,int);
};
int distinct::num_distinct(int i,int j)
{
	int k1=0;
	for(int it=i;it<=j;it++)
		if(l[it]>=i)
			k1++;
	if(i>j) 
		return -1;
	int k=L[i][j-i+1];
	/*for(int it=0;it<L.size();it++)
		cout<<l[it]<<" ";
	cout<<endl;
	for(int jt=0;jt<L[i].size();jt++)
	{
	for(int it=0;it<a.size();it++)
		cout<<m[jt][it]<<" ";
	cout<<"\t";
	for(int it=0;it<a.size();it++)
		cout<<k[jt][it]<<" ";
	cout<<endl;
	}*/
	k=j-i+1-k;
	return k;
}
/*int main()
{
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(1);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(1);
	vec.push_back(5);
	vec.push_back(3);
	distinct v(vec);
	cout<<v.num_distinct(1,7)<<endl;
}*/