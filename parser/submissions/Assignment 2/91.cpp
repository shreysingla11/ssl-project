#include <iostream>
using namespace std;

//Simple Method

//Class to store the details of each given points X-coordinate Y coordinate
class details_point
{
	public:
	int x;
	int y;

	details_point()
	{
	}
};
//As we have to return the indices of the points which are non intersecting, we define a class to store indices of such points
class ans_pairing
{	
	public:
	int R_ind;
	int B_ind;
	ans_pairing()
	{
	}
};
//Fuction to check whether two points are on the same side for a non-intersecting case
int points_on_opp_side( details_point A, details_point B, details_point C, details_point D )
{
	int X1, Y1, X2, Y2;
	int sol = 1;	

	X1 = A.x;  Y1 = A.y;
	X2 = B.x;  Y2 = B.y;
	int cond1, cond2;
	cond1 = C.y*(X2 - X1) + C.x*(Y1 - Y2) + Y1*(X1 - X2) + X1*(Y2- Y1);
	cond2 = D.y*(X2 - X1) + D.x*(Y1 - Y2) + Y1*(X1 - X2) + X1*(Y2- Y1);
	if( (cond1*cond2) > 0 ) sol = 0;
	
	X1 = C.x;  Y1 = C.y;
	X2 = D.x;  Y2 = D.y;
	cond1 = A.y*(X2 - X1) + A.x*(Y1 - Y2) + Y1*(X1 - X2) + X1*(Y2- Y1);
	cond2 = B.y*(X2 - X1) + B.x*(Y1 - Y2) + Y1*(X1 - X2) + X1*(Y2- Y1);
	if( (cond1*cond2) > 0 ) sol = 0;
	
	

	return sol;
} 

int main()
{
	int p, n; // p is the total number of points && n number of red and n number of blue points
	cin >> p;
	n = p/2;

	details_point P_red[ n ];
	details_point P_blue[ n ];

	for( int i = 0; i < n; i++ )
	{
		cin >> P_red[ i ].x;
		cin >> P_red[ i ].y;
		
	}
	for( int j = 0; j < n; j++ )
	{
		cin >> P_blue[ j ].x;
		cin >> P_blue[ j ].y;
		
	}
		
	ans_pairing match[ n ];
	for( int k = 0; k < n; k++ )
	{
		match[ k ].R_ind = k;
		match[ k ].B_ind = k; 
	}
	while( true )
	{
		int final_ans = 1; int a;
		for( a = 0; a < n; a++ )
		{
			for( int b = 1; b < n; b++ )
			{
				if( points_on_opp_side( P_red[ match[ a ].R_ind ], P_blue[ match[ a ].B_ind ], P_red[ match[ b ].R_ind ], P_blue[ match[ b ].B_ind]) == 1 )
				{
					final_ans = 0;
					int tmp;
					tmp = match[ a ].B_ind;
					match[ a ].B_ind = match[ b ].B_ind;
					match[ b ].B_ind = tmp;				
				}		
			}
		}
		if( final_ans == 0 || a == n ) break;
	}
	for( int l = 0; l < n; l++ )
	{
		cout << match[ l ].R_ind << " " << match[ l ].B_ind << endl;
	}

}
