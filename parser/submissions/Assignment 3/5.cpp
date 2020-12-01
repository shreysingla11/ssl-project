#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;
//using global variables
vector<int> seq1;
vector<int> seq2;
vector<vector<int> > arr;
int inf;
int recurse(int a, int b);
int main()
{
	int n,m,i,mins,index,temp;
	index=-1;
	cin>>n>>m;
	inf=n+1;
	mins=n+5;
	seq1.resize(n);
	seq2.resize(m);
	for(i=0;i<n;i++)
		cin>>seq1[i];
	for(i=0;i<m;i++)
		cin>>seq2[i];
	arr.resize(n);
	for(i=0;i<n;i++)
		arr[i].resize(m);
	for(i=0;i<n-m+1;i++)
	{
        if(seq1[i]==seq2[0])
        {
            temp=recurse(i,0);
            if(temp<mins)
            {
            	mins=temp;
            	index=i;
            }
        }
    }
    if(index!=-1)
		cout<<mins<<" "<<index+1<<endl;
	else
		cout<<"infinity"<<endl;
	return 0;
}
int recurse(int a, int b)
{
	int temp;
    if((a-b)>=(arr.size()-arr[0].size()+1))
        return inf;
	if(seq1[a]==seq2[b])
	{
		if((b+1)==arr[0].size())
		{
			arr[a][b]=1;
			return 1;
		}
		if(arr[a+1][b+1]!=0)
		{
			if(arr[a+1][b+1]==inf)
				arr[a][b]=inf;
			else
				arr[a][b]=1+arr[a+1][b+1];
		}
		else
		{
			temp=recurse(a+1,b+1);
			if(temp==inf)
				arr[a][b]=inf;
			else
				arr[a][b]=1+temp;
		}
		return arr[a][b];
	}
	else
	{
		if((b+1==arr[0].size()) && (a+1==arr.size()))
		 	return inf;
		if(arr[a+1][b]!=0)
		{
			if(arr[a+1][b]==inf)
				arr[a][b]=inf;
			else
				arr[a][b]=1+arr[a+1][b];
		}
		else
		{
			temp=recurse(a+1,b);
			if(temp==inf)
				arr[a][b]=inf;
			else
				arr[a][b]=1+temp;
		}
		return arr[a][b];
	}
}
