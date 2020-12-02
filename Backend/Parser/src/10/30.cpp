#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class distinct
{
	std::vector<int> given;
	std::vector<int > l;
	std::vector<std::vector<int> > array1;
	std::vector<std::vector<int> > array2;
	int n;
	void create_array1(int power2)
	{
		int k;
		if(n*2 <= power2)
		{
			return;
		}
		else
		{
			std::vector<int > v1(n,-1);
			std::vector<int > v2(n,-1);
			std::vector<int > temp(power2,0);
			std::vector<int > index2(power2*2,-1);
			for (int j = 0; j < n; ++j)
			{
				if(l[j] >=0)
				{
					k = l[j]/(n/power2);
					if(l[j] >= k*n/power2 + n/(power2*2))
					{
						temp[k]++;
						v1[j] = temp[k];
						v2[j] = index2[2*k +1];
						index2[2*k+1] = j;
					}
					else
					{
						v1[j] = temp[k];
						v2[j] = index2[2*k];
						index2[2*k] = j;
					}
				}
				else
				{
					v1[j] = 0;
					v2[j] = -1;
				}
			}
			array1.push_back(v1);
			array2.push_back(v2);
			power2 = power2*2;
			create_array1(power2);
			return;
		}
	}

public:
	distinct(std::vector<int > &v)
	{
		given = v;
		n = v.size();
		// L created
		for (int i = 0; i < n; ++i)
		{
			l.push_back(-1);
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = i - 1 ; j >=0; --j)
			{
				if(v[j]==v[i])
				{
					l[i] = j;
					break;
				}
			}
		}
		//Store the level arrays
		create_array1(1);
		print(l);
		for (int i = 0; i < array1.size(); ++i)
		{
			print(array1[i]);
		}
	}
	int num_distinct(int i , int j)
	{
		int count = 0;
		int level = 0;
		int half = n/2;
		int totlev = array1.size();

		for(int power = 4; power > n; power = power * 2)
		{
			if (i < half)
			{
				count += array1[level][j];
				if ( l[j] >= half)
				{
					j = array2[level][j];
				}
				if(j == -1)
				{
					break;
				}
				half -= n /power;
				level++;
			}
			else if(i > half)
			{
				if(l[j] < half)
				{
					j = array2[level][j];
				}
				if(j == -1)
				{
					break;
				}
				half += n/power;
				level++;
			}
			else
			{
				if (array1[level][j] > 0)
				{
					count += array1 [level][j];
					break;
				}
			}
		}
		return count;
	}
};
