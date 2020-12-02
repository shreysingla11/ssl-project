#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int main(){
	int n;
	string s;
	cin>>s;
	n=s.size();
	for(int l=1;l<n/2;l++)
	{	
		for(int p=0;p<n-2*l+1;p++)
		{
			for(int p1=0;p1<l;p1++)
			{	
				if(s[p+p1]==s[p+l+p1]){
				
					if(p1==l-1)
					{	
						cout<<l<<" "<<p;
						goto lab;
					}
					else{ 
							break;
					}
				}
				
			}
		}
	}

	cout<<0<<" "<<0;

	lab:

	return 0;
}