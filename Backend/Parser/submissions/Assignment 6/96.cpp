#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	cin >> s;
	char c[ s.size() ];
	for( int i = 0; i < s.size(); i++ )
	{
		c[ i ] = s[ i ];
	}
	int l = 1;
	int index = 0;
	int str_len = 0;
	int exit = 0;
	while( l < s.size() && exit != 1 )
	{
		for( int len = (2*l - 1); len <= (4*l - 2); len++ )  
		{
			for( int i = 0; i < s.size(); i++ )
			{
				if( i + 2*len > s.size() )
				{ 		
					break;
				}
				else if( s.substr( i, len ) == s.substr( i + len, len ) )
				{
					index = i;
					str_len = len;
					exit = 1;
					break;
				}
			}
			if( exit == 1 ) break;
		}
		l = l * 2;
	}
	cout << str_len << " " << index << endl;
}
