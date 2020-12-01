#include<iostream>
#include<vector>

using namespace std;
struct Point
{
	int x,y;
};
bool onSegment(Point p, Point q, Point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
       return true;

    return false;
}

// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r)
{
    // See 10th slides from following link for derivation of the formula
    // http://www.dcs.gla.ac.uk/~pat/52233/slides/Geometry1x1.pdf
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;  // colinear

    return (val > 0)? 1: 2; // clock or counterclock wise
}

// The main function that returns true if line segment 'p1q1'
// and 'p2q2' intersect.
bool isIntersecting(Point p1, Point q1, Point p2, Point q2)
{
    // Find the four orientations needed for general and
    // special cases
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    // General case
    if (o1 != o2 && o3 != o4)
        return true;

    // Special Cases
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;

    // p1, q1 and p2 are colinear and q2 lies on segment p1q1
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;

    // p2, q2 and p1 are colinear and p1 lies on segment p2q2
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;

     // p2, q2 and q1 are colinear and q1 lies on segment p2q2
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;

    return false; // Doesn't fall in any of the above cases
}
int main()
{
int n,x,y;
cin>>n;
int size=n/2;
Point red[2500];
Point blue[2500];
for(int i=0;i<size;i++)
{
	cin>>x>>y;
	red[i].x=x;
	red[i].y=y;
}
for(int i=0;i<size;i++)
{
	cin>>x>>y;
	blue[i].x=x;
	blue[i].y=y;
}
int blueindex[2500];
for(int i=0;i<size;i++)
{
    blueindex[i]=i;
}
Point newblue[2500];
newblue[0]=blue[0];
for(int i=1;i<size;i++)
{
	newblue[i]=blue[i];
	if(isIntersecting(newblue[i],red[i],newblue[i-1],red[i-1]))
	{
		int j=i;
		//cout<<"i="<<i<<endl;
		do
		{
            //cout<<"j="<<j<<endl;
			Point tempblue=newblue[j];
			newblue[j]=newblue[j-1];
			newblue[j-1]=tempblue;
			int tempnum;
			tempnum=blueindex[j];
			blueindex[j]=blueindex[j-1];
			blueindex[j-1]=tempnum;
			j--;
		}
		while(j>=1&&isIntersecting(newblue[j],red[j],newblue[j-1],red[j-1]));
	}
}
for(int i=0;i<size;i++)
{
	cout<<i<<" "<<blueindex[i]<<endl;
}
}

