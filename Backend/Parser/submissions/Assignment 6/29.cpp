#include<iostream>
#include<string>

using namespace std;
int main()
{
	string s;
	int flength=0,findex=0,templength=0;
	int ch;
	cin>>s;
	int len = s.length();
	for(int l=1;2*l-1<len;l=l*2)
	{   //cout<<l<<endl;
		for(int temp=0;temp<len/l;temp++)
		{   //cout<<"temp"<<temp<<endl;
			for(int i=temp*l,j=temp*l;i<=(temp*l+4*l+2)&&l+i<len;i++)
			{
                //cout<<"i"<<i<<endl;
				if(s[j]==s[l+i])
				{
                    //cout<<"a"<<endl;
					j++;
				}
				else
				{
					j=temp*l;
				}
				if(j==temp*l+l)			//main code...Match found(checking further)
				{
                    //cout<<"insideif"<<endl;
					if(flength>l+i-j+1||flength==0)		//Asuming match and assigning length btw i and j at that pt
					{
						templength=l+i-j+1;
					}
					else
					{
						break;
					}
					int it=i+1+l;
					int jt=j;
					while(true)
					{
						if(jt==i+1)		//over while looking front itself
						{
							ch=2;break;
						}
						else if(it==len)		//reached end of array
						{
							ch=1;break;
						}

						else			//Actual checking starts
						{
							if(s[jt]==s[it])		//checking nxt no
							{
								jt++;it++;
							}
							else
							{
								ch=3;break;		//no match in forward==>check backward
							}
						}
					}
					if(ch==2)
					{
						//sucess
					}
					int jt1=j-l-1;
					it=i;
					while(true)
					{
						if(it==jt-1)		//success in backward
						{
							ch=2;break;
						}
						else if(jt1<0)		//array short while going back before traversing the rem part
						{
							ch=1;break;
						}
						else
						{
							if(s[jt1]==s[it])
							{
								jt1--; it--;
							}
							else
							{
								ch=3;break;
							}
						}
					}
					if(ch==2)		//sucess both forward and backward
					{
						flength=templength;
						findex=jt1+1;
						//cout<<"flength"<<flength<<endl;
						break;
					}
					else
					{
						templength=0;
						break;
					}
				}
			}
		}
		if(flength!=0)
		{
			break;
		}
		//cout<<"end"<<endl;
	}
	cout<<flength<<" "<<findex;
	return 0;
}
