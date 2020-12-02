#include<iostream>
#include<vector>
#include<limits>
#include<cmath>
#include<fstream>
using namespace std;
ofstream outfile;
//const int INF=abs(std::numeric_limits<int>::max());
const int INF=10000001;
int n,m;
vector<int> a,b;
int Recurse(int i,int j)
	{
		if(i==n&&j==m&&a[i]==b[j])
            {
            //outfile<<"for i="<<i<<"j="<<j<<"a[i]=b[j]="<<a[i]<<endl;
			return 1;
			}
		else if(j==m&&a[i]==b[j])
            {
                //outfile<<"j==m&a[i]==b[j]"<<"j=m="<<j<<"a[i]="<<a[i]<<"returning 1"<<endl;
                return 1;
            }
        else if(j==m)
            {
            //outfile<<"j==m&a[i]==b[j] with j="<<j<<"a[i]="<<a[i]<<"i and j="<<i<<" "<<j<<" 1+Recurse(i+1,m)"<<endl;
			return(1+Recurse(i+1,m));
			}
		else if(i==n)
            {
            //outfile<<"returning inf for i="<<i<<endl;
			return INF;
			}
		else if(a[i]==b[j])
            {
            //outfile<<"a[i]=b[j]="<<a[i]<<"for i="<<i<<" 1+Recurse(i+1,j+1"<<endl;
            return(1+Recurse(i+1,j+1));
            }
		else
            {
            //outfile<<"default i="<<i<<"j="<<j<<" 1+Recurse(i+1,j)"<<endl;
			return(1+Recurse(i+1,j));
			}

	}
	int main()
	{
        //ifstream infile;
        //infile.open("input2.txt");

        //outfile.open("output.txt");
		int input;
		cin>>n>>m;

		a.resize(n+1);
		b.resize(m+1);
		for(int i=1;i<=n;i++)
		{
			cin>>input;
			a[i]=input;
		}
		for(int j=1;j<=m;j++)
		{
			cin>>input;
			b[j]=input;
		}

		vector<int> result;
		int min;
		int min_index=1;


		result.resize(n+1);
		min=Recurse(1,1);
		for(int i=2;i<=n-m+1;i++)
		{
			int res=Recurse(i,1);
			if(res>INF)
			{
                break;
			}
			//cout<<res<<"at i="<<i<<endl;
			if(res<min)
			{
				min=res;
				min_index=i;
			}
			else if(res==min&&min_index>i)
			{
                min_index=i;
			}
		}
		if(min>n)
		cout<<"infinity"<<endl;
		else
		{
		cout<<min<<" "<<min_index<<endl;
		}

	}
