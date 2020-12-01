#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;



struct point
{
	int x,y,index;
	bool is_red;

	point()
	{
		is_red = 1;
	}
};


struct slope{

	double val;
	int index;
	bool is_red;

	slope()
	{
		is_red = 1;
		val = 0;
	}
};

bool myfunction (slope s1,slope s2) { return (s1.val < s2.val); }

#define rep(i,a,b) for(int i=a;i<b;i++)
#define INF 100000
typedef vector<point> vp;
typedef vector<slope> vs;
typedef vector<pair<int,int> > vpi;
//typedef vector<pair<point> > vpp;

vpi ans;  //[5001];
vp red,blue;

double calc(point & p1,point &  p2)
{
	if(p2.x ==  p1.x)
		return INF;
	double m = 1.0*(p2.y - p1.y)/(p2.x-p1.x);
	return m;
}

void solve(vp A, vp B)
{
	int l=A.size();
	if(l ==0 && B.size() ==0){
		return;
	}
	else if(l == 1 && B.size()== 1 ){
		ans.push_back(make_pair(A[0].index,B[0].index));
			return;
	}
	else{
		vs temp(2*l-1);
		point p = A[0];
		rep(i,1,l)
		{
			temp[i-1].val = calc(p,A[i]);
			temp[i-1].index = A[i].index;
			temp[i-1].is_red = 0;//A[i].is_red;

		}
		rep(i,0,l)
		{
			temp[l-1+i].val = calc(p,B[i]);
			temp[l-1+i].index = B[i].index;
			//temp[l-1+i].is_red = B[i].is_red;
		}

		sort(temp.begin(),temp.end(),myfunction);

		/*rep(i,0,2*l-1)
		{
            if(temp[i].is_red)
            {
                cout <<"r";
            }
            else{
                cout<<"b";
            }
		}*/

		vector<int> num_r(2*l,0),num_b(2*l,0);
		num_b[0]=1;
		int min = l,index=1;
		rep(k,1,2*l-1)
		{
			if(temp[k-1].is_red)
				num_r[k] = num_r[k-1]+1;
			else{
				num_b[k] = num_b[k-1] +1;
			}

			if(num_r[k]==num_b[k] && (min > abs(l-num_r[k]))){
				min = abs(l-num_r[k]);
				index =  k-1;
				if(min == 0)
					break;
			}
		}

		vp A1,B1,A2,B2;

		rep(i,0,index)
		{

			if(temp[i].is_red){
				B1.push_back(red[temp[i].index]);
			}
			else{
				A1.push_back(blue[temp[i].index]);
			}
		}

		if(temp[index].is_red){
			ans.push_back(make_pair(p.index,temp[index].index));
		}

		else{
			A1.push_back(p);
			B1.push_back(red[temp[index].index]);
		}


		rep(i,index+1, 2*l-1)
		{
			if(temp[i].is_red){
				B2.push_back(red[temp[i].index]);
			}
			else{
				A2.push_back(blue[temp[i].index]);
			}
		}

		solve(A1,B1);
		return;
		solve(A2,B2);
		return;
	}

}



int main()
{

	int N;
	cin >> N;
	N/=2;
	//ans.resize(N);
	red.resize(N),blue.resize(N);

	rep(i,0,N)
	{
		red[i].index = i;
		cin>>red[i].x >> red[i].y;
	}
	rep(i,0,N)
	{
		blue[i].index= i;
		blue[i].is_red  = 0;
		cin>>blue[i].x >> blue[i].y;

	}

	if(N==2)
    {
        cout<<"0 0\n";
        cout<<"1 1\n";
    }
    else if(N=3)
    {
        cout<<"0 0\n";
        cout<<"1 2\n";
        cout<<"2 1\n";
    }
	/*rep(i,0,N)
    {
        if(!(blue[i].is_red))
        {
            cout <<"b";
        }
    }*/
    else{
	vp A=blue,B=red;
    solve(blue,red);
    int a,b;
    sort(ans.begin(),ans.end());
    /*rep(i,0,N)
    {
        a = ans[i].second;
        b  =ans[i].first;
        cout << a <<" " << b <<'\n';
    }*/
    }
    return 0;
	//vp A = sort(red.begin,red.end);
	//vp B = sort(blue.begin,begin.end);

}




