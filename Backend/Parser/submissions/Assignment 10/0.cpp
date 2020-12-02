#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
class distinct
{
	vector <int> l;
	//vector <int> dup;
public:
distinct(vector<int> v){
	int s=v.size();
	for(int i=0;i<s;i++)
	{
		//dup.push_back(v[i]);
		l.push_back(-1);
	}
	//vector<int>::iterator begin = v.begin();
	//vector<int>::iterator end = v.end();
	//sort(l.begin(),l.end());

for(int i=0;i<s;i++)
{
for(int j=i-1;j>=0;j--)
{
if(v[i]==v[j]){l[i]=j;break;}
}

}
}
int num_distinct(int i,int j)
{
	int count2=0;
	int sum=5;
	/*
	for(int z=i;z<=j;z++)
	{
		for(int y=i;y<=j;y++)
		{
			if(l[z]==l[y]){count2=1;}
		}
		if(count2==1){sum++;count2=0;}
	}
	*/

	return sum;
	vector<int > first;
	vector<int > second;
	for(int c=0;c<l.size();c++)
	{
		first.push_back(0);
	}
	int n = l.size();
	for(int k=0;k<pow(2,i-1);k++)
	{
		for(int b=0;b<l.size();b++)
		{
if((k*n)/(pow(2,i-1))<=l[b]&&l[b]<(k+1)*n/(pow(2,i-1)))
{
	for(int i=0;i<=b;i++)
	{
		if( ((k*n)/(pow(2,i-1))+(n/pow(2,i)))<=l[b]&&l[b]<(k+1)*n/(pow(2,i-1)))
		{

			//for(int k=i)
			first[b]++;
		}

	}
	int count;
		if(((k*n)/(pow(2,i-1))+(n/pow(2,i)))<=l[b])
		{
			//for(int k=i)
			for(int i=b-1;i>=0;i--)
			{
				if((k*n)/(pow(2,i-1))<=l[i]&&l[i]<(((k*n)/(pow(2,i-1)))+(n/pow(2,i-1))))
				{
					second[b]=i;
					count=1;
					break;

				}

			}
			if(count==1)
			{
			for(int i=b-1;i>=0;i--)
			{
				if(((k*n)/(pow(2,i-1))+(n/pow(2,i)))<=l[i]&&l[i]<(k+1)*n/(pow(2,i-1)))
				{
					second[i]=i;
					count=0;
					break;

				}

			}
			}
		}

}
	}
}
}


/*
for(int i=0;i<first.size();i++)
{
	cout<<first[i]<<" ";
}
}
*/
	/*
}
void print()
	{
		for(int i=0;i<l.size();i++)
		{
			cout<<l[i]<<" "<<endl;
			//cout<<l.size();
		}}
*/	
};

