#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int n=s.length();
	int l=1;
	int i,j,l1,l2,r1,r2,temp;
	bool right,left,ans;
	ans=false;
	while(l<=(n + 2)/4 && !ans)
	{
		i=0;
		while(i<=(n - l - (n%l)) && !ans)
		{
			temp=i;
			j=i+l;
			while(j<=temp+4*l-1 && !ans)
			{
				if(s[i]==s[j])
				{
					l1=l2=i;
					r1=r2=j;
					right=true;
					left=true;
					while(r1-l2!=1 && (left || right))
					{
						if(l1==0)
							left=false;
						if(r2==(n-1))
							right=false;
						if(l1!=0 && left)
						{
							if(s[l1-1]==s[r1-1])
							{
								l1--;
								r1--;
							}
							else
								left=false;
						}
						if(r2!=(n-1) && right)
						{
							if(s[l2+1]==s[r2+1])
							{
								l2++;
								r2++;
							}
							else
								right=false;
						}
					}
					if(r1-l2==1)
					{
						//termination case
						ans=true;
					}
					else
					{
						i=temp;
						j=r2+1;
					}
				}
				else
				{
					j++;
				}
			}
			i=i+l;
		}

		l=l*2;
	}
	if(ans)
		cout<<l2-l1+1<<" "<<l1<<endl;
	else
		cout<<"0 0"<<endl;
	return 0;
}
