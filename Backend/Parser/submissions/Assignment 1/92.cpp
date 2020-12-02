#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
using namespace std;

extern double f( int n );

int main()
{
	int n;  
	vector<double> f2;
	cin >> n;
	f2.resize(n);
	for (int i = 0; i < n; i++)
	{
		//Storing the values of the given function in the vector f2 of type "double"
		f2[ i ] = f(i);
	}
	//Variables declared for storage of maximum falls in the given data
	double max_fall = 0.000000;
	double fall = 0.000000;
	int max_value_index = 0;
	int j = 1;
	int i_fall = 0;
	int j_fall = 0;
	double slope_fall = 0.000000;
	double slope_fall1 = 0.000000;
	while( j < n )
	{//To calculate the maximum fall
		if( f2[ j ] > f2[ max_value_index ] )
		{
			max_value_index = j; 
		}
		else if( f2[ j ] < f2[ max_value_index ] )
		{
			fall = f2[ max_value_index ] - f2[ j ];
			if( fall > max_fall )
			{ 
				max_fall = fall; 
			}	
		}
		j++;
	}
	max_value_index=0;
	int x = 1;
	while( x < n )
	{// For calculating the Maximum fall rate 
		if( f2[ x ] > f2[ max_value_index ] )
		{
			max_value_index = x; 
		}
		else if( f2[ x ] < f2[ max_value_index ] )
		{
			i_fall = max_value_index;
			j_fall = x;
			if( (j_fall - i_fall) != 0 )
			{
				slope_fall1 = ( (f2[ i_fall ] - f2[ j_fall ]) / ( j_fall - i_fall ) );
				if( slope_fall1 > slope_fall )
				{ 
					slope_fall = slope_fall1; 
					
				}
			}	
			
		}
		x++;
	}
	printf("%f",max_fall);
	cout << endl;
	printf("%f",slope_fall);
	cout << endl;
}
