#include <iostream>
#include <vector>

using namespace std;

class distinct
{
	vector<int> l;
	int size;
public:
	//constructor
	distinct(vector<int> input)
	{
		size=input.size();
		l.resize(size,-1);
		for(int i=0;i<size;i++)
		{
			for(int j=i+1;j<size;j++)
			{
				if(input[j]==input[i])
				{
					l[j]=i;
					break;
				}
			}
		}
	}

	int num_distinct(int i, int j)
	{
		int k=0;
		for(int a=i;a<=j;a++)
		{
			if(l[a] >= i)
				k++;
		}
		return j-i+1-k;
	}

};
