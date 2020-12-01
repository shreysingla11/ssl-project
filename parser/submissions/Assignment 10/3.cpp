#include <iostream>
#include <vector>
using namespace std;

class distinct
{
private:
	vector<int> d;
public:


	distinct( vector<int> &v )
	{
		int n;
		while( cin >> n )
		{
			v.push_back( n );
		}
		
		d = v;
	}
	
	
	
	int num_distinct( int m, int n )
	{
		int countall = 0;
		int count = 0;
		for(int i = m; i<=n;i++)
		{
			for(int j=i+1; j<n;j++){
				if(d[i] == d[j]) count++;
			}
		}
		
	countall = n - m -count + 1;
	return countall;
}
};


