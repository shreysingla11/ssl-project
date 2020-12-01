#include <iostream>
#include <vector>
using namespace std;

class point
{
public:
	int xCord;
	int yCord;
	int index;
	point()
	{

	}
	void addPoint(int x, int y);
	double checkLorR (vector<point>redPoints, vector<point>bluePoints, int redP, int blueP);
	//void pairing (vector<point> &redPoints, vector<point> &bluePoints);

};

void pairing (vector<point> redPoints, vector<point> bluePoints);
bool checkRequalsB (int redP, int blueP, vector<point>redPoints, vector<point>bluePoints);

int main()
{
	int n;
	cin>>n;
	n=n/2;
	std::vector<point> redPoints;
	std::vector<point> bluePoints;

	for (int i = 0; i < n; ++i)
	{
		point newPoint;
		int x,y;
		cin>>x>>y;
		newPoint.addPoint(x,y);
		newPoint.index=i;
		redPoints.push_back(newPoint);
	}
	for (int i = 0; i < n; ++i)
	{
		point newPoint;
		int x,y;
		cin>>x>>y;
		newPoint.addPoint(x,y);
		newPoint.index=i;
		bluePoints.push_back(newPoint);
	}

	pairing(redPoints, bluePoints);

	return 0;
}

void point :: addPoint (int x, int y)
{
	xCord=x;
	yCord=y;
}

void pairing (vector<point> redPoints, vector<point> bluePoints)
{

    std::vector<point> leftRed;
    std::vector<point> leftBlue;
    std::vector<point> rightRed;
    std::vector<point> rightBlue;
    int randomPoint = 0;
	for (int i = 0; i < bluePoints.size() ; ++i)
	{
		if (checkRequalsB(randomPoint,i,redPoints,bluePoints))
		{
			cout<<redPoints[0].index<<" "<<bluePoints[i].index<<endl;

 			for (int j = 0; j < redPoints.size(); ++j)
 			{
 				if ( redPoints[j].checkLorR(redPoints, bluePoints, randomPoint, i) < 0 )
 				{
 					leftRed.push_back(redPoints[j]);
 				}
 				else if ( redPoints[j].checkLorR(redPoints, bluePoints, randomPoint, i) > 0 )
 				{
 					rightRed.push_back(redPoints[j]);
 				}
 				if ( bluePoints[j].checkLorR(redPoints, bluePoints, randomPoint, i) < 0 )
 				{
 					leftBlue.push_back(bluePoints[j]);
 				}
 				else if ( bluePoints[j].checkLorR(redPoints, bluePoints, randomPoint, i) > 0)
 				{
 					rightBlue.push_back(bluePoints[j]);
 				}
 			}
 			break;
 		}

 		if (i == bluePoints.size()-1)
 		{
 			randomPoint++;
 			i = 0;
 		}

	}

	if (leftRed.size()==1 && leftBlue.size()==1)
	{
		cout<<leftRed[0].index<<" "<<leftBlue[0].index<<endl;
	}
	if (rightRed.size()==1 && rightBlue.size()==1)
	{
		cout<<rightRed[0].index<<" "<<rightBlue[0].index<<endl;
	}
	if (leftRed.size()>1 && leftBlue.size()>1)
	{
		pairing(leftRed, leftBlue);
	}
	if (rightRed.size()>1 && rightBlue.size()>1)
	{
		pairing(rightRed, rightBlue);
	}

	return;
}

bool checkRequalsB (int redP, int blueP, vector<point>redPoints, vector<point>bluePoints)
{
	int countRed=0;
	int countBlue=0;
	for (int i = 0; i < redPoints.size(); ++i)
	{
		if ( redPoints[i].checkLorR(redPoints, bluePoints, redP, blueP) < 0 )
		{
			countRed++;
		}
	}
	for (int i = 0; i < bluePoints.size(); ++i)
	{
		if ( bluePoints[i].checkLorR(redPoints, bluePoints, redP, blueP) < 0 )
		{
			countBlue++;
		}
	}

	if (countRed!=countBlue)
	{
		return false;
	}
	else
	{
		return true;
	}
}

double point :: checkLorR (vector<point>redPoints, vector<point>bluePoints, int redP, int blueP)
{
	double result;
	result = ((yCord - redPoints[redP].yCord)*(bluePoints[blueP].xCord - redPoints[redP].xCord)) - ((xCord - redPoints[redP].xCord)*(bluePoints[blueP].yCord - redPoints[redP].yCord));
	return result;
}

