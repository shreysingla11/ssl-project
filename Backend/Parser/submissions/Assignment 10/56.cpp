#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
using namespace std;

class distinct{

	std::vector<int> l;

public:

	distinct(std::vector<int> v)
	{

		l.resize(v.size(),-1);
		map<int,int> lastseen;

		for (int i = 0; i < v.size(); ++i)
		{
			if(lastseen.count(v[i]))
			{
				l[i] = lastseen[v[i]]; 
			}
			else {
				l[i] = -1;
			}
			lastseen[v[i]] = i;
		}

	}

	int num_distinct(int i, int j)
	{

	}

	void print()
	{
		for (int i = 0; i < l.size; ++i)
		{
			/* code */
			cout << l[i] << " ";
		}
	}
};

int main()
{
	int [] A = {1,2,1,3,2,1,1,3};
	std::vector<int> v(A,A+8);
	distinct A(v);
	A.print();
	return 0;
}