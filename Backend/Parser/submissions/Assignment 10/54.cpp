#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class distinct
{
	int n;
	vector<int> a;
	vector<int> l;
	vector<vector<int> > level1;
	vector<vector<int> > level2;
	vector<int> first_level;
public:
	distinct(vector<int> &v)
	{
		a = v;
		n = a.size();
		make_lvector();
		initialize_arrays();
	}
	void make_lvector()
	{
		int i, j;
		l.push_back(-1);
		for (i=1; i<a.size(); ++i)
		{
			for (j=i-1; j>=0; --j)
			{
				if (a[j] == a[i])
				{
					l.push_back(j);
					break;
				}
			}
			if (l.size() < i+1)
				l.push_back(-1);
		}
		for (i=0; i<a.size(); ++i)
		{
			level1.push_back(vector<int>(a.size()));
			level2.push_back(vector<int>(a.size()));
		}
	}
	void initialize_arrays()
	{
		int i, j, k, index = -1;
		int power;
		vector<int> temp(n);
		vector<int> maxtemp1(n+1);
		vector<int> maxtemp2(n+1);
		for (j=0; j<n; ++j)
		{
			if (l[j] != -1)
			{
				index = j;
			}
			if (l[j] == -1)
			{
				level2[1][j] = index;
			}
		}
		for (i=1; i <= 1+log2(n); ++i)
		{
			power = (int)pow(2, i-1);
			// cout << power << endl;
			for (j=0; j < n; ++j)
			{
				temp[j] = 0;
				maxtemp1[j] = maxtemp2[j] = -1;
			}
			for (j=0; j < n; ++j)
			{
				if (l[j] == -1)
				{
					if (j > 0)
						level1[i][j] = level1[i][j-1];
					else
						level1[i][j] = 0;
					// cout << level1[i][j] << " ";
					continue;
				}

				k = floor(float(l[j]*power/n));
				if (l[j] >= k*(n/power) + (n/(2*power)))
				{	
					++temp[k];
					level2[i][j] = maxtemp1[k];
					if (maxtemp2[k] < j)
						maxtemp2[k] = j;
				}
				else
				{
					level2[i][j] = maxtemp2[k];
					if (maxtemp1[k] < j)
						maxtemp1[k] = j;
				}
				level1[i][j] = temp[k];
				// cout << level1[i][j] << " ";
			}
		}	
	}
	int num_distinct(int i, int j)
	{
		int i_orig = i, j_orig = j; 
		int lev = 1, temp = n, p = 0, q = temp, sum = 0;
		while (temp > 1)
		{
			// // cout << "hey" << endl;
			if (i < temp/2 && l[j] < temp/2)
			{
				// // cout << "hey1" << endl;
				if (lev == 1 && l[j] == -1)
				{
					j = level2[lev][j];
				}
				q = q - temp/2;
				sum += level1[lev][j];
			}
			else if (i < temp/2 && l[j] >= temp/2)
			{
				// cout << "hey2" << endl;
				q = q - temp/2;
				j = level2[lev][j];
				sum += level1[lev][j];
				// cout << level1[lev][j] << endl;
			}
			else if (i >= temp/2 && l[j] >= temp/2)
			{
				// cout << "hey3" << endl;
				p = p + temp/2;
			}
			else
			{
				// cout << "hey4" << endl;
				p = p + temp/2;
				j = level2[lev][j];
			}
			++lev;
			temp = q-p;
		}
		return j_orig-i_orig+1-sum;
	}
};