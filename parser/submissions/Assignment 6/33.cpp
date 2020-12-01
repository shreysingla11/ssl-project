#include <iostream>
#include <string>

using namespace std;

string a;
bool comparat=false;

int block_eq(int block_no, int l)
{
	int curr_pos =0;
	int index=0;
	int s=0;
	for(int j = 2*l -1; j< 4*l -1; j++)
	{
		curr_pos=0;
		comparat= false;
		s =block_no*l;
		for(curr_pos=0; curr_pos< l  && (s+j+ curr_pos<a.length()) ; curr_pos++)
		{
			if(a[s+curr_pos]==a[s+j+curr_pos])
			{
				if(!comparat)
				{
					comparat=true;
					index =j+s;
				}
			}
			else
			{
				comparat =false;
				j = j+ curr_pos;
				break;
			}
		}
		if(comparat)
		{
			break;
		}
	}
	if(!comparat)
	{
		return -1;
	}
	else
	{
		return index;
	}
}

int main()
{
	cin>>a;
	int square_indx=0;
	int sqsize=0;
	int index=0;
	bool found= false;
	int n = a.length();
	bool x_comparat=true;
	int back_counter = 0;
	int front_counter = 0;
	for(int l = 1; (l<=(n+4)/8) && (!found);l*=2)
	{
		int index=0;
		for(int i=0;i <n/l;i++)
		{
			x_comparat=true;
			index = block_eq(i,l);
			if(index>=0)
			{
				if(index-back_counter== i*l +l)
				{
					found = true;
					sqsize = l+ back_counter;
					square_indx = i*l - back_counter;
					break;
				}				
				for(back_counter=0;((index-back_counter)>=i*l+l) &&(x_comparat) &&(i*l-back_counter>=0);back_counter++)
				{
					// cout<<"j"<<index<<l<<i<<back_counter<<found<<x_comparat<<endl;
					if(a[i*l-back_counter]==a[index-back_counter])
					{
						x_comparat = true; 
					}
					else
					{
						x_comparat=false;
					}
				}
				back_counter--;
				// cout<<"l"<<index<<back_counter<<l<<i<<found<<x_comparat<<endl;
				square_indx = i*l - back_counter;
				for(front_counter=0;((index-back_counter)>i*l+l+front_counter) &&(x_comparat) && ((i*l+l+front_counter)<a.length());front_counter++)
				{
					// cout<<"k"<<index-back_counter<<i*l +l +front_counter+1<<found<<endl;
					if(index-back_counter== i*l +l +front_counter+1)
					{
						found = true;
						sqsize = l+ back_counter+front_counter+1;
						break;
					}
				}
			}
			if(found)
			{
				break;
			}
		}
	}
	if(found)
	{
		cout<<sqsize<<" "<<square_indx<<endl;
	}
	else
	{
		cout<<"0 0"<<endl;
	}
	return 0;
	
}