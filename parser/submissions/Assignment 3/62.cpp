#include <iostream>
#include <vector>
#define inf 2147483647
using namespace std;
void myfunc(vector<int> &a, vector<int> &b, int n, int m)
{
	vector<int> col(n+1);
	vector<int> coltemp(n+1);
	vector<int> l(n+1);
	int i, j, prev, min, index;
	if (a[n] == b[m])
	{
		col[n] = 1; 
	}
	else
	{
		col[n] = inf;
	}
	for (i = n-1; i >= 1; --i)
	{
		if (a[i] == b[m])
		{
			col[i] = 1;
		}
		else
		{
			if (col[i+1] == inf)
				col[i] = inf;
			else
				col[i] = 1+col[i+1];
		}
	}
	for (j = m-1; j >= 1; --j)
	{
		for (i = n; i >= j-1; --i)
		{
			if (i == n)
			{
				coltemp[i] = inf;
			}
			else if (a[i] == b[j])
			{
				if (col[i+1] == inf)
				{
					coltemp[i] = inf;
				}
				else
				{
					coltemp[i] = 1+col[i+1];
				}
			}
			else
			{
				if (coltemp[i+1] == inf)
				{
					coltemp[i] = inf;
				}
				else
				{
					coltemp[i] = 1+coltemp[i+1];
				}
			}
		}
		col = coltemp;
	}
	min = inf;
	index = 0;
	for (i = 1; i <= n; ++i)
	{
		if (col[i] < min)
		{
			min = col[i];
			index = i;
		}
	}
	if (min == inf)
		cout << "infinity" << endl;
	else
	{
		cout << min << " " << index << endl;
	}
}
int main()
{
	vector<int> a, b;
	int n, m, i, j, num;
	cin >> n >> m;
	a.push_back(0);
	b.push_back(0);
	for (i = 0; i < n; ++i)
	{
		cin >> num;
		a.push_back(num);
	}
	for (j = 0; j < m; ++j)
	{
		cin >> num;
		b.push_back(num);
	}
	myfunc(a, b, n, m);
	return 0;
}