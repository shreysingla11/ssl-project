#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int m,n;
	cin>>n>>m;
	int k=m-2;
	int mini,s;
	vector<int> a(n),b(m);
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	for (int i = 0; i < m; ++i)
	{
		cin>>b[i];
	}
	vector<int> c(n),d(n);
	if(a[n-1]==b[m-1])
	{
		d[n-1]=1;
	}
	else
	{
		d[n-1]=-1;
	}
	for (int i = n-2; i >k; --i)
	{
		if (a[i]==b[m-1])
		{
			d[i]=1;
		}
		else
		{
			if(d[i+1]==-1){
				d[i]=-1;
			}
			else{
				d[i]=1+d[i+1];
			}
		}
	}
	while(k>=0){
		c[n-1]=-1;mini=-1;
		for(int i=n-2;i>=k;i--){
			if(a[i]==b[k]){
				if(d[i+1]==-1){
					c[i]=-1;
				}
				else{
					c[i]=1+d[i+1];
				}
			}
			else{
				if(c[i+1]==-1){
					c[i]=-1;
				}
				else{
					c[i]=1+c[i+1];
				}
			}
			if(k==0){
			if(mini==-1){
				mini=c[i];
				s=i+1;
			}
			else if(c[i]<mini&&c[i]!=-1){
				mini=c[i];
				s=i+1;
			}
		}
		}
		k--;
		d=c;

	}
	if(mini!=-1){
	cout<<mini<<" "<<s;
}
	else{
		cout<<"infinity";
	}
	return 0;
}
