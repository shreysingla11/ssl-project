#include <iostream>
#include <vector>
using namespace std;

class distinct
{
private:
	vector<int> b;
public:
	distinct( vector<int> &c )
	{
		int n;
		while( cin >> n )
		{
			c.push_back( n );
		}
	}
	int num_distinct( int i, int j )
	{
		int count = 0;
		for( int m = i; m < j; m++ )
		{
			for( int n = i; n < m; n++ )
			{
				if( b[ m ] == b[ n ] )
				{
					break;
				}
				if( m == n )
				{ 
					count = count + 1;
				}
			}
		}
		return count;
	}
};


