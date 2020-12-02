#include<iostream>
#include<vector> 
using namespace std;
void minlength(vector<int>& w1,vector<int>& w2,int a,int b)
{	
	int c=a+1;
	int l=0;
	int s1=0;
	int s2=0;
	int s=0;
	vector<int> v;
	if(a<b){cout<<"infinity";}
	else{
	if(w1[a]==w2[b-1]&&a==1&&b==1){
		v.push_back(1);
	}
	else{
		v.push_back(a+1);
	}

	for(int p=0;p<a;p++)
	{
		if(w1[p]==w2[b-1]){
			s=s+1;
			break;
		}
		else{
			s=s+1;
		}
	}
	if(s==a){
		if(w1[a-1]==w2[b-1]){v.push_back(a);}
		else{v.push_back(a+1);}
	}

	while(s1<a && s2<b){
		if(w1[s1]==w2[s2]){
			l=l+1;
			s1=s1+1;
			s2=s2+1;
		}
		else{
			s1=s1+1;
			if(s2==0){
				l=0;
			}
			else if(s2==b-1&&s1==b){
				cout<<"infinity";
			}
			else{l=l+1;}
	}
}
	v.push_back(l);
	for (int p = 0; p < v.size(); p++)
		{
			if(v[p]<c){
				c=v[p];
			}
		}	
		if(c<a+1){
			cout<<c;
		}
		else{
			cout<<"infinity";
		}
	}
}
 int main()
{
	vector<int> v1;
	vector<int> v2;
	int m,n,x;
	cin>>n>>m;
	for(int p=0;p<n;p++){
		cin>>x;
		v1.push_back(x);
	}
	for (int p = 0; p < m; p++)
	{
		cin>>x;
		v2.push_back(x);
	}

	minlength(v1,v2,n,m);
	return 0;
}