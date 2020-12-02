#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	int size,l=1,initial,minlength,minpos,k,revk;
	bool breakloop;
	cin>>s;
	size=s.length();
	minlength = size+1;
	minpos=-1;
	while(4*l-2<=size)
	{
		for(int i=0;i<=size-3*l+1;i=i+l)
		{
			initial=i+2*l-1;
			k=0;
			while(true)
			{
				if(s[i+k]==s[initial+k])
				{
					k++;
				}                                                                                                            
				else 
				{
					k++;
					if(initial+k>i+4*l-2||initial+k+l>size)
					{
						break;
					}
					initial = initial+k;
					k=0;
				}
				if(k==l)
				{
					breakloop = false;
					if(i+k==initial)
					{
						if(k<minlength)
						{
							minlength = k;
							minpos = i;
							break;
						}
					}
					revk=1;
					while(i-revk>=0)
					{
						if(s[i-revk]==s[initial-revk])
						{
							revk++;
						}
						else
						{
							break;
						}
						if(i+l-1==initial-revk)
						{
							if(initial-i<minlength)
							{
								minlength = initial-i;
								minpos = i-revk+1;
							}
							break;
						}
					}
					if(i+l-1!=initial-revk)
					{
						while(initial+k<size)
						{
							if(s[i+k]==s[initial+k])
							{
								k++;
							}
							else
							{
								k++;
								if(initial+k>i+4*l-2||initial+k+l>size)
								{
									breakloop=true;
									break;
								}
								initial = initial+k;
								k=0;
								break;
							}
							if(i+k==initial-revk+1)
							{
								if(initial-i<minlength)
								{
									minlength = initial-i;
									minpos = i-revk+1;
								}
								break;
							}
						}
						if(breakloop)
						{
							break;
						}
					}
				}			
			}
		}
		if(minlength<size+1)
		{
			break;
		}
		l = 2*l;
	}
	if(minpos==-1)
	{
		minlength=0;
		minpos=0;
	}
	cout<<minlength<<" "<<minpos<<endl;
	return 0;
} 
