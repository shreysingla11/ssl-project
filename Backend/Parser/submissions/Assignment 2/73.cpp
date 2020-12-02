# include <iostream>
# include <algorithm>
# include <vector>
# define vp vector<point>
using namespace std;
struct point{
	int x,y;
	int selfindex;

    point (){}

	point(int inx, int iny, int inself)
	{
		selfindex = inself;
		x = inx;
		y = iny;
	}
};
struct anspair{
	int red,blue;
	anspair(int x, int y)
	{
		red = x;
		blue = y;
	}
};
vector<anspair> ans;
bool LorR(point &rp, point &bp, point &cp);
void solveRecursive(vp &redpts,vp &bluepts);
bool sameNumberDivision(vp &redpts, vp &bluepts, point &rp, point &bp);
bool sameNumberDivision2(vp &redpts, vp &bluepts, point &rp, point &bp);
void divide(vp &redpts, vp &bluepts, point &rp, point &bp, vp &blueL, vp &redL, vp &blueR, vp &redR);
void divide2(vp &redpts, vp &bluepts, point &rp, point &bp, vp &blueL, vp &redL, vp &blueR, vp &redR);

int main()
{
	int N, tempx, tempy;
	cin>>N;
	N = N/2;
	point tp;
	vp bluepts,redpts;

	for (int i = 0; i < N; ++i)
	{
		cin>>tempx>>tempy;
		tp = point(tempx, tempy, i);
		redpts.push_back(tp);
	}
	for (int i = 0; i < N; ++i)
	{
		cin>>tempx>>tempy;
		tp = point(tempx, tempy, i);
		bluepts.push_back(tp);
	}
	solveRecursive(redpts, bluepts);
	for (int i = 0; i < N; ++i)
		cout<<ans[i].red<<" "<<ans[i].blue<<endl;
	return 0;
}
void solveRecursive(vp &redpts,vp &bluepts)
{
	bool wasabove = false;

	point randomPoint = redpts[0];
	point connectPoint;
	vp blueL, redL, redR, blueR;

	for (int i = 0; i < bluepts.size(); ++i)
	{
		connectPoint = bluepts[i];
		if(sameNumberDivision(redpts, bluepts, randomPoint, connectPoint))
		{
			wasabove = true;
			ans.push_back(anspair(randomPoint.selfindex, connectPoint.selfindex));
			divide(redpts, bluepts, randomPoint, connectPoint, blueL, redL, blueR, redR);
			if(redL.size() != 0)
				solveRecursive(redL, blueL);
			if(redR.size() != 0)
				solveRecursive(redR, blueR);
			break;
		}
	}
	if(!wasabove)
	{
		for (int i = 0; i < redpts.size(); ++i)
		{
			if(!(redpts[i].x == randomPoint.x && redpts[i].y == randomPoint.y))
			{
				connectPoint = redpts[i];
				if(sameNumberDivision2(redpts, bluepts, randomPoint, connectPoint))
				{
					divide2(redpts, bluepts, randomPoint, connectPoint, blueL, redL, blueR, redR);
					if(redL.size() != 0)
						solveRecursive(redL, blueL);
					if(redR.size() != 0)
						solveRecursive(redR, blueR);
					break;
				}
			}
		}
	}
}
bool sameNumberDivision(vp &redpts, vp &bluepts, point &rp, point &bp)
{
	int N = redpts.size();
	int nRedR = 0, nBlueR = 0;
	for (int i = 0; i < N; ++i)
	{
		if(!(bluepts[i].x == bp.x && bluepts[i].y == bp.y))
			if(LorR(rp, bp, bluepts[i]))
				nBlueR++;
	}
	for (int i = 0; i < N; ++i)
	{
		if(!(redpts[i].x == rp.x && redpts[i].y == rp.y))
			if(LorR(rp, bp, redpts[i]))
				nRedR++;
	}
	if(nRedR == nBlueR)
		return true;
	return false;
}
bool sameNumberDivision2(vp &redpts, vp &bluepts, point &rp, point &bp)
{
	int N = redpts.size();
	int nRedR = 0, nBlueR = 0, nBlueL = 0, nRedL = 0;
	for (int i = 0; i < N; ++i)
	{
		if(LorR(rp, bp, bluepts[i]))
			nBlueR++;
		else
			nBlueL++;
	}
	for (int i = 0; i < N; ++i)
	{
		if(!(redpts[i].x == rp.x && redpts[i].y == rp.y) && !(redpts[i].x == bp.x && redpts[i].y == bp.y))
		{
			if(LorR(rp, bp, redpts[i]))
				nRedR++;
			else
				nRedL++;
		}
	}
	if((nRedR == nBlueR) || (nBlueL == nRedL))
		return true;
	return false;
}
void divide(vp &redpts, vp &bluepts, point &rp, point &bp, vp &blueL, vp &redL, vp &blueR, vp &redR)
{
	int N = redpts.size();
	for (int i = 0; i < N; ++i)
	{
		if(!(bluepts[i].x == bp.x && bluepts[i].y == bp.y))
		{
			if(LorR(rp, bp, bluepts[i]))
				blueR.push_back(bluepts[i]);
			else
				blueL.push_back(bluepts[i]);
		}
	}
	for (int i = 0; i < N; ++i)
	{
		if(!(redpts[i].x == rp.x && redpts[i].y == rp.y))
		{
			if(LorR(rp, bp, redpts[i]))
				redR.push_back(redpts[i]);
			else
				redL.push_back(redpts[i]);
		}
	}
}
void divide2(vp &redpts, vp &bluepts, point &rp, point &bp, vp &blueL, vp &redL, vp &blueR, vp &redR)
{
	int N = redpts.size();
	for (int i = 0; i < N; ++i)
	{
		if(LorR(rp, bp, bluepts[i]))
			blueR.push_back(bluepts[i]);
		else
			blueL.push_back(bluepts[i]);
	}
	for (int i = 0; i < N; ++i)
	{
		if(!(redpts[i].x == rp.x && redpts[i].y == rp.y) && !(redpts[i].x == bp.x && redpts[i].y == bp.y))
		{
			if(LorR(rp, bp, redpts[i]))
				redR.push_back(redpts[i]);
			else
				redL.push_back(redpts[i]);
		}
	}
	if(redR.size() == blueR.size())
	{
		redL.push_back(rp);
		redL.push_back(bp);
	}
	else
	{
		redR.push_back(rp);
		redR.push_back(bp);
	}
}
bool LorR(point &rp, point &bp, point &cp) //L is false , R is true
{
	float factor;
	if(rp.x == bp.x)
	{
		if(cp.x > rp.x)
			return true;
		else
			return false;
	}
	else
	{
		factor = cp.y - rp.y - (cp.x - rp.x)*((bp.y - rp.y)/(bp.x - rp.x));
		if(factor > 0)
			return true;
		else
			return false;
	}
}
