#include <iostream>
#include <set>
#include <iomanip>
using namespace std;
class interval
{
public:
	double start,end;
	bool operator <(const interval& Interv) const
	{
		if(end< Interv.start)
			return true;
		else
			return false;
	}
};


int main()
{
	std::ios::sync_with_stdio(false);
	cout<<std::fixed;
	int n,w,u,v,t1,t2,m,l,p;
	set<interval> compunion;
	std::set<interval>::iterator it,equiv;
  	std::pair<std::set<interval>::iterator,bool> ret;
	interval I;
	// int l[100000];
	// int p[100000];
	// int numinterval;
	int factor;
	double tf,d,a1,a2,max,prev,diff;
	//vector<double> intervals;
	char dir;
	cin>>n>>w>>u>>v>>t1>>t2;
	tf = (1.0*w)/v;
	d = 1.0*u*tf;
	for(int i=0;i<n;i++)
	{
		cin>>dir>>m;
		if(dir=='E')
			factor=1;
		else
			factor=-1;
		for(int j=0;j<m;j++)
		{
			cin>>l>>p;
			p*=factor;		
			a1=(-d-p)/u-i*tf;
			a2=1.0*(-p+l)/u-i*tf;
			//intervals[numinterval]=(-d-p)/u;
			// if(a1<=t1&&a2>=t2)
			// {
			// 	/*intervals[numinterval]=t1;
			// 	intervals[numinterval+1]=t2;*/
			// 	I.start=t1;
			// 	I.end=t2;
			// 	//numinterval++;
			// 	//break;
			// }
			// else if(a1<=t1&&a2>=t1&&a2)
			// {
			// 	/*intervals[intervalindex]=a1;
			// 	intervals[intervalindex+1]=t2;
			// 	intervalindex++;*/
			// 	I.start=t1;
			// 	I.end=a2; 
			// 	//break;
			// }
			// else if(a1<=t2&&a2>=t2)
			// {
			// 	/*intervals[intervalindex]=a1;
			// 	intervals[intervalindex+1]=a2;
			// 	intervalindex++;*/
			// 	I.start=a1;
			// 	I.end=t2;
			// }
			// else if(a1>=t1&&a2<=t2)
			// {
			// 	I.start=a1;
			// 	I.end=a2;
			// }
			// else
			// {
			// 	continue;
			// }

			I.start=a1;
			I.end=a2;
			if(I.start<t1)
				I.start=t1;
			if(I.end>t2)
				I.end=t2;
			if(I.start>I.end)
				continue;
			ret = compunion.insert(I);
			if(ret.second ==false)
			{
				equiv = ret.first;
				a1=equiv->start;
				a2=equiv->end;
				while(true)
				{	
					it=equiv;
					it++;
					if(it==compunion.end())
					{
						break;
					}
					if((!(I<*it))&&(!(*it<I)))
					{
						if(it->start<a1)
						{
							a1=it->start;
						}
						if(it->end>a2)
						{
							a2=it->end;
						}
						compunion.erase(it);
					}
					else
					{
						break;
					}
				}
				while(true)
				{	
					if(equiv==compunion.begin())
						break;
					it=equiv;
					it--;
					if((!(I<*it))&&(!(*it<I)))
					{
						if(it->start<a1)
						{
							a1=it->start;
						}
						if(it->end>a2)
						{
							a2=it->end;
						}
						compunion.erase(it);
					}
					else
					{
						break;
					}
				}
				compunion.erase(equiv);
				if(I.start>a1)
				{
					I.start=a1;
				}
				if(I.end<a2)
				{
					I.end=a2;
				}
				compunion.insert(I);
			}
		}
		prev=t1;
		max=0;
		for(it=compunion.begin();it!=compunion.end();it++)
		{
			diff=it->start-prev;
			if(diff>max)
			{
				max=diff;
			}
			prev = it->end;
		}
		if(t2-prev>max)
		{
			max=t2-prev;
		}
		cout<<setprecision(8)<<max<<endl;

	}
	return 0;
}