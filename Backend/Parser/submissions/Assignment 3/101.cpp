#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
# define fr(i,n) for(int i=0;i<n;i++)
# define fr1(i,n) for(int i=1;i<=n;i++)


using namespace std;

int main()
{
	/* code */
	int n,m,i,j,o;
	int* a;
	int* b;
	int* nex_col;
	int* curr_col;
	cin>>n>>m;
	if(m>n)cout<<"infi"<<endl;
	a=new int[n+1];
	b=new int [m+1];
	nex_col=new int[m+1];
	curr_col=new int[m+1];
	fr1(i,n){
		cin>>a[i];
	}

	fr1(i,m){
		cin>>b[i];
		nex_col[i]=n+10;
		curr_col[i]=n+10;

	}


if(a[n]==b[m]){
curr_col[m]=1;
nex_col[m]=1;}
else{nex_col[m]=n+10;
curr_col[m]=n+10;}

j=m;
i=n-1;
o=0;
//cout<<"i "<<i<<"j "<<j<<"ans "<<curr_col[j]<<endl;
while(j!=0){

if(j==m){
			if(a[i]==b[m]){
				curr_col[m]=1;
			}
			else{
					//cout<<"nex "<<nex_col[m]+1<<endl;
				curr_col[m]=nex_col[m]+1;
			
			}
		}
		else{
if (a[i]==b[j])
{
curr_col[j]=nex_col[j+1]+1;
}

else{
	curr_col[j]=nex_col[j]+1;
}
}
//cout<<"i "<<i<<"j "<<j<<"ans "<<curr_col[j]<<endl;

if(curr_col[j]>=n){
	o++;
for(int k=j;k<=m;k++){
					nex_col[k]=curr_col[k];
				}
i--;
j=m+1;
}
j--;
}
if(curr_col[1]>=n)cout<<"infinity"<<endl;
else{
	cout<<curr_col[1]<<" "<<i<<endl;
}

	return 0;
}
