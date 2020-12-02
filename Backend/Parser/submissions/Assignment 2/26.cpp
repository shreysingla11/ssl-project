#include<iostream>
#include<vector>
using namespace std;


class lines
{
	vector<vector<int> > blue;
	vector<vector<int> > red;
	vector<int> pair;
	int index,n;
public:
	bool solve();
	bool check(int entry);
	bool checkinter(int i,int entry);

	void input()
	{
        index=0;
		cin>>n;
		n=n/2;
		int a,b;
		vector<int> v;
		for(int i=0;i<n;i++)
		{
			cin>>a>>b;
			v.push_back(a);
			v.push_back(b);
			red.push_back(v);
		}
		for(int i=0;i<n;i++)
		{
			cin>>a>>b;
			v.push_back(a);
			v.push_back(b);
			blue.push_back(v);
		}
	};
	void output()
	{
		for(int i=0;i<n;i++)
		{
			cout<<i<<" "<<pair[i]<<"\n";
		}
	};

}l;



int main()
{
    l.input();
    if(l.solve())
    l.output();
    return 0;
}

bool lines::solve()
{
	if(index==n)
	{
		return true;
	}
	int entry = 0;
	while(entry<n)
	{
		if(check(entry))
		{
            pair.push_back(entry);
			index++;
			if(solve())
			{
				return true;
			}
			pair.pop_back();
		}
		entry++;
	}
	index--;
	return false;
}



bool lines::check(int entry)
{
	for(int i=0;i<index;i++)
	{
		if(pair[i]==entry)
		{
			return false;
		}
	}
	for(int i=0;i<index;i++)
	{
		if(checkinter(i,entry))
		{
			return false;
		}
	}
	return true;
}

bool lines::checkinter(int i,int entry)
{
  int x1= red[index][0]- red[i][0];
  int y1 = red[index][1] - red[i][1];
  int x2= blue[entry][0]- red[i][0];
  int y2 = blue[entry][1]- red[i][1];


  int x3= red[index][0]- blue[pair[i]][0];
  int y3 = red[index][1] - blue[pair[i]][1];
  int x4= blue[entry][0]- blue[pair[i]][0];
  int y4 = blue[entry][1]- blue[pair[i]][1];

  int x5= red[i][0]- red[index][0];
  int y5 = red[i][1] - red[index][1];
  int x6= blue[pair[i]][0]- red[index][0];
  int y6 = blue[pair[i]][1]- red[index][1];


  int x7= red[i][0]- blue[entry][0];
  int y7 = red[i][1] - blue[entry][1];
  int x8= blue[pair[i]][0]- blue[entry][0];
  int y8 = blue[pair[i]][1]- blue[entry][1];

  int det1 = x1*y2 - x2*y1;
  int det2 = x3*y4 - x4*y3;
  int det3 = x5*y6 - x6*y5;
  int det4 = x7*y8 - x8*y7;


  if(det1*det2<=0||det3*det4<=0)
  {
  	return false;
  }
  else
  {
  	return true;
  }
}


