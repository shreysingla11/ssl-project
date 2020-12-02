#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct time_interval
{
	double start;
	double end;
};

bool myfunc(time_interval t1,time_interval t2)
{
	return t1.start < t2.start;
}

struct ship
{
	double l;
	double p;
	time_interval find_forbidden(int &u,char &bound)
	{
		time_interval* t;
		t = new time_interval;
		if(bound=='E')
		{
			t->start = 0 - (double)p/u;
			t->end = t->start + (double)l/u;

		}
		else if(bound == 'W')
		{
			t->start = (double)p/u;
			t->end = t->start + (double)l/u;
		}
		return *t;
	}
};

struct lane
{
	int m;
	ship * l_ship;
	char bound;
	int lane_no;
	
	void input(int no)
	{
		cin>> bound>>m;
		lane_no = no;
		if(m>0)
		{
			l_ship = new ship[m];
			for (int i = 0; i < m; ++i)
			{
				cin>>l_ship[i].l>>l_ship[i].p;
			}
		}
	}
};

double max_time_interval(std::vector<lane> strait, int u, double time_cross, double t1, double t2)
{
	std::vector<time_interval> v;
	time_interval* ti;
	bool(*fn_pt)(time_interval,time_interval) = myfunc;
	std::set<time_interval,bool(*)(time_interval,time_interval)> sixth (fn_pt);

	for (int i = 0; i < strait.size(); ++i)
	{
		for (int j = 0; j < strait[i].m; ++j)
		{
			ti = new time_interval;
			*ti = strait[i].l_ship[j].find_forbidden(u, strait[i].bound);
			if(ti->start >=0)
			{
				ti->start -= strait[i].lane_no* time_cross;
				ti->end -= strait[i].lane_no* time_cross;
				if(!(ti->start <0) || !(ti->end < 0))
				{
					if(ti->start<=t2)
					{
						if(ti->end>=t1)
						{
							if(ti->start < t1)
							{
								ti->start =t1;
							}
							v.push_back(*ti);
						}
					}
				}
			}
		}
				


	}

	std::sort (v.begin(),v.end(),myfunc);
	double diff= 0;
	double max_end=v[0].end;
	int i = 1;
	for (; i < v.size(); ++i)
	{
		if(v[i-1].end>max_end)
		{
			max_end = v[i-1].end;
		}
		if(max_end < v[i].start)
		{
			// cout<<" 1 \t "<<v[i].start - max_end<<"\t"<<max_end<<"\t"<<v[i].start<<endl;
			if(diff < v[i].start - max_end)
			{
				diff = v[i].start - max_end;
			}
		}
	}
	if(t2 - max_end > diff)
	{
		return t2 - max_end;
	}
	if(v[0].start -t1 > diff)
	{
		return v[0].start -t1;
	}
	return diff-time_cross ;
}

int main(int argc, char const *argv[])
{
	int n, w, u,v, t1,t2;
	cin>>n>>w>>u>>v>>t1>>t2;
	double diff = 0;	
	double time_cross = (double)w/v;
	lane* lanes;
	std::vector<lane> strait;
	for (int i = 0; i < n; ++i)
	{
		lanes = new lane;
		lanes->input(i);
		strait.push_back(*lanes);
	}
	diff = max_time_interval(strait,u,time_cross,t1,t2);
	printf("%.8f\n",diff);
	return 0;
}