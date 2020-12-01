#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <map>
#include <cstdio>

using namespace std;

int main()
{
	double n,w,u,v,t1,t2,length,start,time_lane,var,size,counts,max_interval;
	double a,b;
	char temper;
	std::multimap<double, char> map;
	std::multimap<double, char>::iterator it1,it2;
	cin>>n>>w>>u>>v>>t1>>t2;
	int n_ships;
	time_lane=w/v;
	


	for (int i = 0; i < n; ++i)
	{
		/* code */
		cin>>temper;
		if(temper=='E')
		{
			cin>>n_ships;
			for (int j = 0; j < n_ships; ++j)
			{
				/* code */
				cin>>length>>start;
				if(start < 0)
				{
                    var=-start;
					a=var/u - i*time_lane;
					// temp.status=true;
					// points.push_back(temp);
					b=(var + length)/u - i*time_lane;
					// temp.status=false;
					// points.push_back(temp);
					if(a<=t2 && b>=t1)
					{
						if(a<t1)
							a=t1;
						if(b>t2)
							b=t2;
						map.insert(std::pair<double,char>(a,'a'));
						map.insert(std::pair<double,char>(b,'b'));
					}
				}
				else if(start > 0 && start-length < 0)
				{
					a=(length-start)/u - i*time_lane;
					if(a<=t2 && a>=t1)
					{
						map.insert(std::pair<double,char>(t1,'a'));
						map.insert(std::pair<double,char>(a,'b'));
					}
				}
			}
		}
		else if(temper=='W')
		{
			cin>>n_ships;
			for (int j = 0; j < n_ships; ++j)
			{
				/* code */
				cin>>length>>start;
				if(start > 0)
				{
                    var=start;
					a=var/u - i*time_lane;
					// temp.status=true;
					// points.push_back(temp);
					b=(var + length)/u - i*time_lane;
					// temp.status=false;
					// points.push_back(temp);
					if(a<=t2 || b>=t1)
					{
						if(a<t1)
							a=t1;
						if(b>t2)
							b=t2;
						map.insert(std::pair<double,char>(a,'a'));
						map.insert(std::pair<double,char>(b,'b'));
					}
				}
				else if(start < 0 && start-length > 0)
				{
					a=(start-length)/u - i*time_lane;
					if(a<=t2 && a>=t1)
					{
						map.insert(std::pair<double,char>(t1,'a'));
						map.insert(std::pair<double,char>(a,'b'));
					}
				}
			}
		}
	}
	max_interval=map.begin()->first - t1;
	counts=0;
	for(it1=map.begin();it1!=map.end();it1++)
	{
		if(it1->second=='a')
			counts++;
		else if(it1->second=='b')
			counts--;
		if(counts==0)
		{
			it2=it1;
			it2++;
			if(it2!=map.end())
				max_interval=max(max_interval,it2->first - it1->first);
			else
				max_interval=max(max_interval,t2-it1->first);
		}

	}
	//cout<<max_interval<<endl;
	if(max_interval > time_lane)
		max_interval=max_interval-time_lane;
	printf("%0.8f\n",max_interval);

	return 0;
}

