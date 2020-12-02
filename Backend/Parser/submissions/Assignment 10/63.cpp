#include <iostream>   
#include <vector>
#include <map>

using namespace std;

class distinct
{
	std::vector<int> larray;
public:
	distinct( std::vector<int> v)
	{
		int size = v.size();
		larray.resize(size,-1);
		std::map<int, int> valIndex;
		for (int i = 0; i < size; ++i) //create l array
		{
			if (valIndex.find(v[i]) == valIndex.end())
			{
				valIndex[v[i]] = i;
			}
			else
			{
				larray[i] = valIndex[v[i]];
				valIndex[v[i]] = i;
			}
			/*for (int j = i+1; j < larray.size(); ++j)
			{
				if (v[j] == v[i])
				{
					larray[j]=i;
					break;
				}
			}*/
		}
	}

	int num_distinct(int start, int end)
	{
		int k = 0;
		for (int q = start; q <= end; ++q)
		{
			if (larray[q] >= start)
			{
				k++;
			}
		}
		return end - start + 1 - k;	
	}
};