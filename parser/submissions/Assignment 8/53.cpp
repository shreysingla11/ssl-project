#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;
struct point
{
	double time;
	char position;
	point()
	{
		time = 0.0;
		position = 'S';
	}
	point(double t, char ch)
	{
		time = t;
		position = ch;
	}
};
bool lessthan(point x, point y)
{
	if (x.time < y.time)
	{
		return true;
	}
	else if (x.time > y.time)
	{
		return false;
	}
	return x.position > y.position;
}
int main()
{
	int n, w, u, v, t1, t2, i, m, a, b, j, count;
	double t_ferry, start_time, end_time, max, res;
	vector<double> l, p;
	vector<point> intervals;
	char ch;
	cin >> n >> w >> u >> v >> t1 >> t2;
	t_ferry = 0.0;
	for (i=0; i<n; ++i)
	{
		cin >> ch >> m;
		l.clear();
		p.clear();
		for (j=0; j<m; ++j)
		{
			cin >> a >> b;
			if (ch == 'E')
			{
				b = -b;
			}
			l.push_back((double)a);
			p.push_back((double)b);
			start_time = (double)p[j]/u - t_ferry;
			end_time = (double)(p[j]+l[j])/u - t_ferry;
			intervals.push_back(point(start_time, 'S'));
			intervals.push_back(point(end_time, 'E'));
		}
		t_ferry = (i+1)*((double)w/v);
	}
	sort(intervals.begin(), intervals.end(), lessthan);
	// for (vector<point> :: iterator it = intervals.begin(); it != intervals.end(); ++it)
	// {
	// 	cout << it->time << " " << it->position << endl; 
	// }
	start_time = t1;
	max = 0.0;
	count = 0;
	vector<point> :: iterator it;
	for (it = intervals.begin(); it != intervals.end(); ++it)
	{
		if (it->position == 'S')
		{
			// cout << "in S" << endl;
			if (count == 0)
			{
				// cout << "in count = 0" << endl;
				end_time = it->time - (double)w/v;
				if (end_time > t2)
				{
					end_time = t2;
				}
				res = (end_time - start_time);	
				if (max < res)
				{
					max = res;
				}
			}
			++count;
		}
		else if (it->position == 'E')
		{
			--count;
			if (count == 0)
			{
				start_time = it->time;
				if (start_time < t1)
					start_time = t1;
			}
		}
		// cout << count << endl;
	}
	if (t2 > start_time)
	{
		res = (t2 - start_time);
		if (max < res)
		{
			max = res;
		}
	}
	printf("%.8f\n", max);
	return 0;
}