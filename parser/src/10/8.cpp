#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

class distinct
{
	vector<int> l;
	vector<vector<int> > arrays1;
	vector<vector<int> > arrays2;
	vector<int> distinctarray;
	int n;
	int numlevel;
public:
	distinct(vector<int> A)
	{
		n = A.size();
		int temp = n;
		numlevel =0;
		while(temp>1)
		{
			numlevel++;
			temp/=2;
		} 
		numlevel++;
		map<int,int> mymap;
		l.resize(n,0);
		for(int i=0; i<n; i++)
		{
			if(mymap.count(A[i])>0)
			{
				l[i]=mymap[A[i]];
				mymap[A[i]]=i;
			}
			else
			{
				l[i]=-1;
				mymap.insert(std::pair<int,int>(A[i],i));
			}
		}
		int maxdistinct=-1;
		distinctarray.resize(n,-1);
		for(int i=0;i<n;i++)
		{
			if(l[i]==-1)
			{
				distinctarray[i]=maxdistinct;
			}
			else
			{
				maxdistinct = i;
			}
		}
		vector<int> array1(n,0);
		vector<int> array2(n,0);
		int count1 = 0;
		int maxless1 = -1, maxgreater1 = -1;
		for(int i=0;i<n;i++)
		{
			if(l[i]>=n/2)
			{
				count1++;
				array2[i]=maxless1;
				maxgreater1 = i;
			}
			else
			{
				array2[i]=maxgreater1;
				maxless1 = i;
			}
			array1[i]=count1;
		}
		arrays1.push_back(array1);
		arrays2.push_back(array2);
		vector<int> count,maxgreater,maxless;
		int k,powiminus1;
		for(int i = 2; i <= numlevel;i++)
		{
			powiminus1 = pow(2,i-1);
			count.clear();
			count.resize(powiminus1,0);
			maxless.clear();
			maxless.resize(powiminus1,-1);
			maxgreater.clear();
			maxgreater.resize(powiminus1,-1);
			for(int j=0;j<n;j++)
			{
				if(l[j]<0)
					continue;
				k = l[j]*powiminus1/n;
				if((l[j]-k*n/powiminus1) >= n/(2*powiminus1))
				{
					count[k]++;
					array2[j]=maxless[k];
					maxgreater[k] = j;
				}
				else
				{
					array2[j]=maxgreater[k];
					maxless[k] = j;
				}
				array1[j] = count[k];
			}
			arrays1.push_back(array1);
			arrays2.push_back(array2);
			
		}
	}
	int num_distinct(int i,int j)
	{
		int ans1 = j-i+1;
		int ans=0;
		int mid = n/2;
		if(i>j)
			return 0;
		if(i==j)
			return 1;
		if(l[j]==-1)
		{
			j = distinctarray[j];
		}
		if(j==-1)
		{
			return(ans1);
		}
		for(int x = 0;x<numlevel;x++)
		{
			if(i==mid)
			{
				ans+= arrays1[x][j];
				break;
			}
			else if(i>mid)
			{
				if(l[j]<mid)
				{
					j = arrays2[x][j];
				}
				if(j==-1)
				{
					break;
				}
				mid = mid + n/pow(2,x+2);
			}
			else
			{
				ans = ans + arrays1[x][j];
				if(l[j]>=mid)
				{
					j=arrays2[x][j];
				}
				if(j==-1)
				{
					break;
				}
				mid = mid - n/pow(2,x+2);
			}
		}
		return(ans1-ans);
	}
};