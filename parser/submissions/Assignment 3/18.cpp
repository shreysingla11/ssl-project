#include <iostream>
#include <vector>

using namespace std;

void get_column_zero(vector<int>& a,vector<int>& b,vector<int>& column,int c,int & min,int & pos)
{
	int n = a.size(),m = b.size(),tmp;
//	if(c<0) return;
	if(c == m-1)
	{
		if(a[n-1] == b[m-1]) 
		{
			column[n-1] = 1;	
		}
		else
		{
			column[n-1] = 0;	
		}
		
		for(int i=n-2; i>=0; i--)
		{
			if(a[i]==b[m-1])
			{
				column[i] = 1;
			}
			else if(column[i+1] == 0)
			{
				column[i] = 0;		
			}
			else
			{
				column[i] = 1 + column[i+1];	
			}
		}
	}
	else
	{
		if(m-1 > c)
		{
			tmp = column[n-1];
			column[n-1] = 0;		
		}
		for(int i=n-2; i>=0; i--)
		{
			if(a[i] == b[c])
			{
				if(tmp==0)
				{
					tmp = column[i];
					column[i] = 0;
				}
				else
				{
					int t = tmp;
					tmp = column[i];
					column[i] = t + 1;
					
					if(min == 0)
					{
						min = column[i];
						pos = i+1;	
					}
					else
					{ 
						if(min >= column[i])
						{
							min = column[i];
							pos = i+1;	
						}
					}		
				}	
			}
			else
			{
				if(column[i+1]==0)
				{
					tmp = column[i];
					column[i] = 0;	
				}
				else
				{
					tmp = column[i];
					column[i] = column[i+1] + 1;
					
					if(min == 0)
					{
						min = column[i];
						pos = i+1;	
					}
					else
					{ 
						if(min >= column[i])
						{
							min = column[i];
							pos = i+1;	
						}
					}	
				}	
			} 	
		}
	}
	if(c==0) return;
	else
	{
		min = 0;
		pos = 0;
		get_column_zero(a,b,column,c-1,min,pos);
	}		
}




int main()
{
	int n, m,temp;
	cin>>n>>m;
	vector <int> a,b;
	
	for(int i=0; i<n; i++)
	{
		cin>>temp;
		a.push_back(temp);	
	}
	for(int i=0; i<m; i++)
	{
		cin>>temp;
		b.push_back(temp);	
	}
	
	int min=0, pos=0;
	
	vector<int> column(n);
	get_column_zero(a,b,column,m-1,min,pos);
	
	if(min) cout<<min<<" "<<pos;
	else cout<<"infinity"; 
	

return 0;	
}
