
#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>b;i--)
#define s(n) scanf(" %d",&n)


int INF;

vector<vector<int> > mat;

void func(vector<int> & a,vector<int> & b)
{
    int n=a.size(),m= b.size();
	mat[1][n-1] = (a[n-1]== b[m-1])?1:INF;
	rrep(i,n-2,-1)
	{
		mat[1][i] = (a[i]==b[m-1])?1:(1+mat[1][i+1]);
	}
	int k=0,t=n-2;
	rrep(j,m-1,0)
	{
        k=0;
		rrep(i,t,j-2)
		{
			if(a[i]==b[j-1]){
                if(k==0){
                    t=i;
                    k++;
                }
				mat[0][i] = 1 + mat[1][i+1];
			}
			else{
				if(i==n-2)
					mat[0][i] =INF;
				else
					mat[0][i] = mat[0][i+1] +1;
			}
		}
		rep(i,0,n-1)
		{
			mat[1][i] = mat[0][i];
		}
		mat[1][n-1] = INF;
	}
}





int main()
{
	int n,m;
	s(n);
	s(m);
	vector<int> a(n),b(m);
	INF = n+1;
	mat.resize(2);
	rep(i,0,2)
	{
		mat[i].resize(n);
	}
	rep(i,0,n)
	{
		s(a[i]);
	}
	rep(i,0,m)
	{
		s(b[i]);
	}
	func(a,b);
	int  min = INF, ind = -1;
	rep(i,0,n-m+1)
	{
		if(min > mat[0][i])
		{
			min = mat[0][i];
			ind =i+1;
		}
	}
	if(min <INF )
	printf("%d %d\n",min, ind);
    else
    printf("infinity\n");
	return 0;

}



