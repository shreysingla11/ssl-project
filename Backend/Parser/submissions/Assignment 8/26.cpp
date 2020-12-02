#include <iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<vector>

using namespace std;
int main()
{
	double l,p,temp,w,n,u,v,t1,t2,no,error1,error2;
	char dir;
	vector<pair<double,double> >inter;
	cin>>n>>w>>u>>v>>t1>>t2;
	for(double i=0.0;i<n;i++)
	{
		cin>>dir>>no;
		for(double j=0.0;j<no;j++)
		{
			cin>>l>>p;
			if(!((dir=='E' && p+l>=0) || (dir=='W' && p+l<=0)))
			{
				if(!((dir=='E' && p>=0) || (dir=='W' && p<=0)))
				{
					p=abs(p);
				}
				temp=(p/u)-(i*w/v);
				inter.push_back(make_pair(temp-(w/v),temp+l/u));
			}
		}
	}
	sort(inter.begin(),inter.end());
	double max=0.0;
	inter.push_back(make_pair(t2,t1));
	
	if(inter.size()==1)
	{
		max=t2-t1;
	}
	for(double i=1.0;i<inter.size();i++)
	{
        error1=0.0;error2=0.0;
        if(t1>inter[i-1].second)
        {
            error1=t1-inter[i-1].second;
        }
        if(t2<inter[i].first)
        {
            error2=inter[i].first-t2;
        }

		temp=inter[i].first-inter[i-1].second-error1-error2;
		if(max<temp)
		{
			max=temp;
		}
	}
	printf("%.8f",max);

}
