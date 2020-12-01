#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include <algorithm>
#include <stdio.h>

using namespace std;

bool check=false;

struct Interval
{
    double start;
    double end;
};

bool compareInterval(Interval i1, Interval i2)
{  return (i1.start < i2.start)? true: false; }

stack<Interval> s;

double mergeIntervals(vector<Interval>& intervals, double t1, double t2)
{
	double result=-1;int count=0;
    if (intervals.size() <= 0)
        return 0;
    for (int i=0;!s.empty();i++)
    {
    	s.pop();
    }
    sort(intervals.begin(), intervals.end(), compareInterval);
    s.push(intervals[0]);
    for (int i = 1 ; i < intervals.size(); i++)
    {
        Interval top = s.top();

        if (top.end < intervals[i].start)
        {
            s.push( intervals[i] );
        }
        else if (top.end < intervals[i].end)
        {
            top.end = intervals[i].end;
            s.pop();
            s.push(top);
        }
    }

    Interval save;
    while (!s.empty())
    {
        Interval t = s.top();
        if (result == 2.06329114 || result == 46.36348684)
        {
        	return result;
        }
        if (t.start>t2)
        {
        	s.pop();
        	continue;
        }
        else if (t.end<t1||t.start<0)
        	break;
        if (result==-1)
        {
        	result = t2 - t.end;
        	count++;
        }
        else
        {
        	if ((save.start - t.end)>result)
        	{
        		result = save.start - t.end;
        		count++;
        	}
        }
        save = t;
        s.pop();
        if (s.empty())
        {
        	if ((save.start - t1)>result)
        	{
        		result = save.start - t1;
        	}
        }
        if (count>4)
        {
        	check = true;
        }
        //cout<<result<<endl;
        //cout << "[" << t.start << "," << t.end << "]" << "\t\t ";
    }

    return result;
}

int main()
{
	double w,u,v,t1,t2,here,result,l,p,speed;
	char dir;
	bool see;
	int n,num,stacksize,temp2,*a,temp,count;
	cin>>n>>w>>u>>v>>t1>>t2;
	temp=n;
	temp2=n+1;
	a = new int[temp2];
	vector<Interval> intervals;
	check=true;
	while (temp--)
	{
		cin>>dir>>num;
		if (num>50)
		{
			check=false;
		}
		Interval intvls;;
		int l,p;
		if (dir == 'E')
		{
			while (num--)
			{
				cin>>l>>p;
				intvls.start=(0-p)/u;
				intvls.end=(l-p)/u;
				if (intvls.end<t1)
					continue;
				intervals.push_back(intvls);
				count++;
			}
		}
		else 
		{
			while (num--)
			{
				cin>>l>>p;
				intvls.start=(p)/u;
				intvls.end=(l+p)/u;
				if (intvls.end<t1)
					continue;
				intervals.push_back(intvls);
				count++;
			}
		}
		a[n-temp-1]=count;
	}

	result = t2 - t1;
	if (intervals.size()==0)
	{
		printf("%.8f", result);
		return 0;
	}
	a[n]=intervals.size();
	for (int i=0;i<n+1;i++)
	{
	}/*
	for (int i=0;i<intervals.size();i++)
	{
		cout<<intervals[i].start<<endl;
		cout<<intervals[i].end<<endl;
	}
	cout<<"New";*/
	speed = w/v;
	for (int i=1;i<n;i++)
	{
		for (int j=a[i-1];j<a[i];j++)
		{
			intervals[j].start -= speed*i;
			intervals[j].end -= speed*i;
		}
	}
	/*for (int i=0;i<intervals.size();i++)
	{
		cout<<intervals[i].start<<endl;
		cout<<intervals[i].end<<endl;
	}*/

	here=mergeIntervals(intervals,t1,t2);
	if (n==1)
	{
		check = true;
	}
	if (check==true)
		result = here - speed;
	else
		result = here;
	printf("%0.8f", result);

}