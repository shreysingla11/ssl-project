#include<iostream>
#include<cstdio>
#include<limits>
#include<vector>
using namespace std;

class var
{
public:
	int m,n,temp;
	int **l;
	vector<int> a;
	vector<int> b;
	var()
	{
		cin>>n>>m;
		for(int i=0;i<n;i++)
		{
            cin>>temp;
			a.push_back(temp);
		}
		for(int i=0;i<m;i++)
		{
            cin>>temp;
			b.push_back(temp);
		}

		l=new int*[n];
		for(int i=0;i<n;i++)
		{
			l[i]=new int[m];
		}
    }

    int solve(int i,int j);
};


int main()
{
    var s;
    for(int j=(s.m)-1;j>=0;j--)
	{
		for(int i=(s.n)-1;i>=0;i--)
		{
			if(s.l[i][j]==0)
            s.solve(i,j);
		}
	}
	int min=std::numeric_limits<int>::max();
	int minindex;
	for(int i=0;i<s.n;i++)
	{
		if(s.l[i][0]<min && s.l[i][0]>0)
		{
			min=s.l[i][0];
			minindex=i;
		}
	}
	if(min!=std::numeric_limits<int>::max())
	{
		cout<<min<<" "<<minindex+1;
	}
	else
	{
		printf("infinity");
	}
	return 0;
}


int var::solve(int i,int j)
{
	if(l[i][j]!=0)
	{
		return l[i][j];
	}
	if(j==m-1)
	{
		if(i==n-1)
		{
			if(a[i]==b[j])
			{
				l[i][j]=1;
			}
			else
			{
				l[i][j]=std::numeric_limits<int>::max();
			}
			return l[i][j];
		}
		else
		{
			if(a[i]==b[j])
			{
				l[i][j]=1;
			}
			else
			{
				l[i][j]=1+solve(i+1,j);
			}
			return l[i][j];
		}
	}
	else if(i==n-1)
	{
		l[i][j]=std::numeric_limits<int>::max();
		return l[i][j];
	}
	else
	{
		if(a[i]==b[j])
		{
			l[i][j]=1+solve(i+1,j+1);
		}
		else
		{
			l[i][j]=1+solve(i+1,j);
		}
		return l[i][j];
	}

}
