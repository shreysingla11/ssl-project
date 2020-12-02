#include<iostream>
#include<vector>
using namespace std;
struct point
{
	float x;
	float y;
	int k;
};
bool inter(point a,point b,point c,point d)
{
	float e=c.y-b.y-(b.y-a.y)/(b.x-a.x)*(c.x-b.x);
	float f=d.y-b.y-(b.y-a.y)/(b.x-a.x)*(d.x-b.x);
	float g=a.y-d.y-(d.y-c.y)/(d.x-c.x)*(a.x-d.x);
	float h=b.y-d.y-(d.y-c.y)/(d.x-c.x)*(b.x-d.x);
	if(e*f<0&&g*h<0)
	{
		return true;
	}
	else
	{
		return false;
	}

}
int main(int argc, char const *argv[])
{
	int n;
	int xx,yy;

	cin>>n;
	// float red[n/2][2];
	// float blue[n/2][2];
	int a[n/2][2];
	vector<point> red(n/2);
	vector<point> blue(n/2);
	for (int i = 0; i < n; ++i)
		{
			if (i<n/2)
			{
				cin>>xx;
				cin>>yy;
				red[i].x=xx;
				red[i].y=yy;
				red[i].k=i;
				a[i][0]=i;
				a[i][1]=i;

			}
			else
			{
				cin>>blue[i-n/2].x;
				cin>>blue[i-n/2].y;
				blue[i].k=i-n/2;
			}
		}
	for(int i=1;i<n/2;i++)
	{
		for(int j=i-1;j>=0;j--)
		{
			if(inter(red[a[i][0]],blue[a[i][1]],red[a[j][0]],blue[a[j][1]])==true)
			{
				int t=a[i][1];
				a[i][1]=a[j][1];
				a[j][1]=t;
				j=i;
			}
		}
	}
	for (int i = 0; i < n/2; ++i)
	{


			cout<<a[i][0]<<" "<<a[i][1]<<endl;

	}
	return 0;
}
