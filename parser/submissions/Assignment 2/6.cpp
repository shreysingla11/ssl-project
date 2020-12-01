#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct point
{
	int x,y,id;

};

bool checksign(point p, double m, double c)
{
	if((p.y-m*p.x+c)>0)
		return true;
	else
		return false;
}

bool check(int k, int pos, vector<point>& red, vector<point>& blue)
{
	int rright=0, bright=0;
	if((blue[pos].x-red[k].x)==0)
	{
		for(int i=0;i<red.size();i++)
		{
			if(i!=k)
			{
				if(red[i].x>red[k].x)
				{
					rright++;
				}
			}
		}
		for(int i=0;i<blue.size();i++)
		{
			if(i!=pos)
			{
				if(blue[i].x>red[k].x)
				{
					bright++;
				}
			}
		}
	}
	else
	{
		double m = (blue[pos].y-red[k].y)*1.0/(blue[pos].x-red[k].x);
		double c = m*(red[k].x)-red[k].y;

		for(int i=0;i<red.size();i++)
		{
			if(i!=k)
			{
				if(checksign(red[i],m,c))
				{
					rright++;
				}
			}
		}
		for(int i=0;i<blue.size();i++)
		{
			if(i!=pos)
			{
				if(checksign(blue[i],m,c))
				{
					bright++;
				}
			}
		}
	}
	if(rright==bright)
		return true;
	else
		return false;
}
 
void createvectors(int k, int pos, vector<point> &red, vector<point> &blue, vector<point> &r1, vector<point> &r2, vector<point> &b1, vector<point> &b2)
{
	if((blue[pos].x-red[k].x)==0)
	{
		for(int i=0;i<red.size();i++)
		{
			if(i!=k)
			{
				if(red[i].x>red[k].x)
				{
					r1.push_back(red[i]);
				}
				else
				{
					r2.push_back(red[i]);
				}
			}
		}
		for(int i=0;i<blue.size();i++)
		{
			if(i!=pos)
			{
				if(blue[i].x>red[k].x)
				{
					b1.push_back(blue[i]);
				}
				else
				{
					b2.push_back(blue[i]);
				}
			}
		}
	}
	else
	{
		double m = (blue[pos].y-red[k].y)/(blue[pos].x-red[k].x);
		double c = m*(red[k].x)-red[k].y;

		for(int i=0;i<red.size();i++)
		{
			if(i!=k)
			{
				if(checksign(red[i],m,c))
				{
					r1.push_back(red[i]);
				}
				else
				{
					r2.push_back(red[i]);
				}
			}
		}
		for(int i=0;i<blue.size();i++)
		{
			if(i!=pos)
			{
				if(checksign(blue[i],m,c))
				{
					b1.push_back(blue[i]);
				}
				else
				{
					b2.push_back(blue[i]);
				}
			}
		}
	}
}

void makepair(vector<point>& red, vector<point>& blue,int A[])
{
	if(red.size()==1)
	{
		A[red[0].id]=blue[0].id;
		return;
	}
	vector<point> r1,r2,b1,b2;
	for(int k=0;k<red.size();k++)
	{
		for(int i=0;i<blue.size();i++) 
		{
			if(check(k,i,red,blue))
			{
				A[red[k].id]=blue[i].id;
				createvectors(k,i,red,blue,r1,r2,b1,b2);
				makepair(r1,b1,A);
				makepair(r2,b2,A);
				return;
			}
		}
	}
}

int main()
{
	int n, *A;
	point p;
	vector<point>red,blue;
	cin>>n;
	n=n/2;
	A = new int [n];
	for(int i=0;i<n;i++)
	{
		cin>>p.x>>p.y;
		p.id=i;
		red.push_back(p);	
	}
	for(int i=0;i<n;i++)
	{
		cin>>p.x>>p.y;
		p.id=i;
		blue.push_back(p);
	}
	makepair(red,blue,A);
	for(int i=0; i<n; i++)
	{
		cout<<i<<" "<<A[i]<<endl;
	}

	return 0;
}