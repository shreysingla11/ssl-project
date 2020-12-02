#include<iostream>
#include<vector>
using namespace std;
class point
{
public:
	int x;
	int y;
	int index;
	void initialise(int a,int b,int c);
};
void recurse(vector<point> redpoints, vector<point> bluepoints);
bool red_blueequal(int a,int b,vector<point> redpoints,vector<point> bluepoints);
int main()
{
	int i,n,x,y;
	cin>>n;
	n=n/2;
	vector<point> redpoints(n);
	vector<point> bluepoints(n);
	for(i=0;i<n;i++)
	{
		cin>>x>>y;
		redpoints[i].initialise(x,y,i);
    }
	for(i=0;i<n;i++)
	{
		cin>>x>>y;
		bluepoints[i].initialise(x,y,i);
    }
	recurse(redpoints,bluepoints);
	return 0;
}
void point :: initialise(int a, int b, int c)
{
	x=a;
	y=b;
	index=c;
}
void recurse(vector<point> redpoints, vector<point> bluepoints)
{
	//assume the arbitary point to be the first point in the array.
	int i,j,k;
	k=0;
	int x,y,ax,ay,bx,by;
	vector<point> newleftred,newrightred,newleftblue,newrightblue;
	for(i=0;i<redpoints.size();i++)
	{
		//first red point paired to ith blue point
		if(red_blueequal(k,i,redpoints,bluepoints))
		{
			//bluepoints[i].paired=true;
			cout<<redpoints[k].index<<" "<<bluepoints[i].index<<endl;
			ax=redpoints[k].x;
			ay=redpoints[k].y;
			bx=bluepoints[i].x;
			by=bluepoints[i].y;
			for(j=0;j<redpoints.size();j++)
			{
				x=redpoints[j].x;
				y=redpoints[j].y;
				if(x*(by-ay) + bx*ay < y*(bx-ax) + ax*by)
					newleftred.push_back(redpoints[j]);
				else if(x*(by-ay) + bx*ay != y*(bx-ax) + ax*by)
					newrightred.push_back(redpoints[j]);
				x=bluepoints[j].x;
				y=bluepoints[j].y;
				if(x*(by-ay) + bx*ay < y*(bx-ax) + ax*by)
					newleftblue.push_back(bluepoints[j]);
				else if(x*(by-ay) + bx*ay != y*(bx-ax) + ax*by)
					newrightblue.push_back(bluepoints[j]);
			}

			break;
		}
		if(i==redpoints.size()-1)
		{
			k++;
			i=-1;
		}
	}
	if(newleftred.size()==1 && newleftblue.size()==1)
		cout<<newleftred[0].index<<" "<<newleftblue[0].index<<endl;
	if(newrightred.size()==1 && newrightblue.size()==1)
		cout<<newrightred[0].index<<" "<<newrightblue[0].index<<endl;
	if(newleftred.size()>1 && newleftblue.size()>1)
		recurse(newleftred,newleftblue);
	if(newrightred.size()>1 && newrightblue.size()>1)
		recurse(newrightred,newrightblue);


	return;
}
bool red_blueequal(int a,int b,vector<point> redpoints,vector<point> bluepoints)
{
	int i;
	int x,y,ax,ay,bx,by;
	int leftred=0;
	int leftblue=0;
	ax=redpoints[a].x;
	ay=redpoints[a].y;
	bx=bluepoints[b].x;
	by=bluepoints[b].y;
	for(i=0;i<redpoints.size();i++)
	{
		x=redpoints[i].x;
		y=redpoints[i].y;
		if(x*(by-ay) + bx*ay < y*(bx-ax) + ax*by)
			leftred++;
		x=bluepoints[i].x;
		y=bluepoints[i].y;
		if(x*(by-ay) + bx*ay < y*(bx-ax) + ax*by)
			leftblue++;
	}
	if(leftblue==leftred)
		return true;
	else
		return false;
}
