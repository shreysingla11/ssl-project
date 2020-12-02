#include <iostream>
#include <algorithm>
#include <map>
#include <cstdio>
using namespace std;

int main()
{
	int n,w,u,v,t1,t2;
	cin>>n>>w>>u>>v>>t1>>t2;
	double cross1lane = w/u;
	std::multimap<double, char> ships;

	int i=0;
	char direction;
	int m;
	int length, position;
	double start, end;
	while (i < n)
	{
		cin>>direction;
		cin>>m;

		if (direction == 'E')
		{
			while (m != 0)
			{
				cin>>length>>position;
				if (position <= 0)
				{

					start = ((max(0,-position))/v) - (i*cross1lane);
					end = (((-position) + length)/v) - (i*cross1lane);
					if(start<=t2 && end>=t1)
					{
						if(start<t1)
						{
							start=t1;
						}
						if(end>t2)
						{
							end=t2;
						}
						ships.insert(std::pair<double,char>(start,'s'));
						ships.insert(std::pair<double,char>(end,'e'));
					}
				}
				else if (position > 0 && position -length <0)
				{
					start = ((length - position)/v) - (i*cross1lane);
					if(start<=t2 && start>=t1)
					{
						ships.insert(std::pair<double,char>(t1,'s'));
						ships.insert(std::pair<double,char>(start,'e'));
					}
				}

				m--;
			}
		}

		else
		{
			while (m != 0)
			{
				cin>>length>>position;
				if (position >= 0)
				{

					start = ((max(0,position))/v) - (i*cross1lane);
					end = (((position) + length)/v) - (i*cross1lane);
					if(start<=t2 || end>=t1)
					{
						if(start<t1)
						{
							start=t1;
						}
						if(end>t2)
						{
							end=t2;
						}
						ships.insert(std::pair<double,char>(start,'s'));
						ships.insert(std::pair<double,char>(end,'e'));
					}
				}
				else if (position < 0 && position -length > 0)
				{
					start = ((length - position)/v) - (i*cross1lane);
					if(start<=t2 && start>=t1)
					{
						ships.insert(std::pair<double,char>(t1,'s'));
						ships.insert(std::pair<double,char>(start,'e'));
					}
				}

				m--;
						}
		}

		i++;
	}
	int count;
	std::multimap<double, char>::iterator iter,iter2;
	double maxInterval;
	for(iter=ships.begin();iter!=ships.end();iter++)
	{
		if(iter->second=='s')
		{
			count++;
		}
		else if(iter->second=='e')
		{
			count--;
		}
		if(count==0)
		{
			iter2=iter;
			iter2++;
			if(iter2!=ships.end())
				maxInterval=max(maxInterval,iter2->first - iter->first);
			else
				maxInterval=max(maxInterval,t2-iter->first);
		}

	}
	maxInterval=maxInterval - cross1lane;
	printf("%0.8f\n",maxInterval);

	return 0;
}
