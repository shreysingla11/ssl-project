#include <iostream>
#include <vector>
using namespace std;

int INF;

int shortestSub(int p, int q, vector<int> *A, vector<int> *B,vector<vector<int> > &L )
{
    //cout<<"ap "<<(*A)[p]<<" bq "<<(*B)[q]<<endl;
		if ((*A)[p]==(*B)[q])
		{
			if (q==((*B).size() -1))
			{
				L[p][q]=1;
				return 1;
			}
			if (p==(*A).size()-1)
			{
				return INF;
			}
			if (L[p+1][q+1]==0)
			{
				L[p][q]= 1 + shortestSub(p+1, q+1, A, B, L);
			}
			else
			{
				L[p][q]= 1+ L[p+1][q+1];
			}
			return L[p][q];
		}
		else
		{
			if (p==(*A).size()-1)
			{
				return INF;
			}
			if (p==((*A).size() -1) && q==((*B).size() -1))
			{
				return INF;
			}
			if (L[p+1][q]==0)
			{
				L[p][q] = 1 + shortestSub(p+1, q, A, B, L);
			}
			else
			{
				L[p][q] = 1 + L[p+1][q];
			}
			return L[p][q];
		}
}

int main()
{
	int n,m;

	cin>>n>>m;
	INF=n+1;
	vector<int> A(n);
	vector<int> B(m);

	for (int i = 0; i < n; ++i)
	{
		cin>>A[i];
	}
	for (int j = 0; j < m; ++j)
	{
		cin>>B[j];
	}

	vector<vector<int> > L(n,vector<int> (m));
	int temp;
	int minIndex=INF;
	int min=INF;
	for (int p = 0; p < n; ++p)
	{
        //cout<<"p "<<p<<endl;
        if(A[p]==B[0])
        {
			temp=shortestSub(p, 0, &A, &B, L);
			//cout<<"temp "<<temp<<endl;
			if (min>temp)
			{
				min=temp;
				minIndex=p;
			}
        }
	}
	cout<<min<<" "<<minIndex+1<<endl;
	return 0;
}
