#include<iostream>
#include<cstdio>
#include<vector>
#include<stack>

using namespace std;

class movie
{
	public:
		int t;
		int no;
		vector<int>FriendList;
		bool inlist;
    movie()
    {
    inlist=false;
    t=0;no=0;}

};



int main()
{
	vector<movie>f;
	int n,tempCount,tempt,fn,temp;
	vector<int>sucess,notsucess;
	scanf("%d",&n);
	f.resize(n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&tempt);
		scanf("%d",&tempCount);
		f[i].t = tempt;
		f[i].no = tempCount;

		for(int j=0;j<tempCount;j++)
		{
			scanf("%d",&fn);
			f[fn].FriendList.push_back(i);
		}
	}

for(int i=0;i<n;i++)
	{
		if(f[i].t==0)
		{
			sucess.push_back(i);
			f[i].inlist=true;
		}
		else if(f[i].t > f[i].no)
		{
			notsucess.push_back(i);
			f[i].inlist=true;
		}
	}

	for(int i=0;i<notsucess.size();i++)
	{
		temp = f[notsucess[i]].FriendList.size();
		for(int j=0;j<temp;j++)
		{if(!f[f[notsucess[i]].FriendList[j]].inlist)
			{f[f[notsucess[i]].FriendList[j]].no--;
				if(f[f[notsucess[i]].FriendList[j]].t > f[f[notsucess[i]].FriendList[j]].no)
				{notsucess.push_back(f[notsucess[i]].FriendList[j]);
                f[f[notsucess[i]].FriendList[j]].inlist=true;
				}
			}
		}
	 }

	for(int i=0 ; i<sucess.size() ; i++)
	{temp = f[sucess[i]].FriendList.size();
		for(int j=0;j<temp;j++)
		{if(!f[f[sucess[i]].FriendList[j]].inlist)
			{f[f[sucess[i]].FriendList[j]].no--;
                f[f[sucess[i]].FriendList[j]].t--;
            if(f[f[sucess[i]].FriendList[j]].t == 0)
            {sucess.push_back(f[sucess[i]].FriendList[j]);
            f[f[sucess[i]].FriendList[j]].inlist=true;
            }
        }
    }
	}


	printf("%d %d",sucess.size(), n-notsucess.size());
	return 0;
}


