#include <iostream>
#include <vector>
#include <list>
#include <cstdio>
using namespace std;
class counter
{
	int n;
	vector<int> counts;
	list<list<int> > list_list;
	vector<list<int>::iterator> listin;
	vector<list<list<int> >::iterator> listout;
	list<list<int> >::iterator zero_pos;
public:
	counter(int i)
	{
		int j;
		n=i;
		counts.resize(n);
		listin.resize(n);
		list<int> temp;
		list_list.push_back(temp);
		for(j=0;j<n;j++)
		{
			(list_list.front()).push_back(j);
			listin[j]=prev((list_list.front()).end());
		}
		listout.resize(n,list_list.begin());
		zero_pos=list_list.begin();
	}
	void increment(int i);
	void decrement(int i);
	void reset(int i);
	int count(int i);
	int findMax();
	int numMax();
	void printMax();
	list<list<int> >::iterator next(list<list<int> >::iterator x);
	list<list<int> >::iterator prev(list<list<int> >::iterator x);
	list<int>::iterator next(list<int>::iterator x);
	list<int>::iterator prev(list<int>::iterator x);
};
void counter::increment(int i)
{
    int j;
	list<int>::iterator temp;
	list<int> var;
	list<list<int> >::iterator temp2;
	(*listout[i]).erase(listin[i]);
	temp2=listout[i];
	if(listout[i]!=prev(list_list.end()))
	{
		if(next(listout[i])!=zero_pos)
		{
			if(counts[(*next(listout[i])).front()]==counts[i]+1)
			{
				listout[i]++;
				(*listout[i]).push_back(i);
				listin[i]=prev((*listout[i]).end());
			}
			else
			{
				list_list.insert(next(listout[i]),var);
				listout[i]++;
				(*listout[i]).push_back(i);
				listin[i]=(*listout[i]).begin();
			}
		}
		else
		{
			if(counts[i]==-1)
			{
				listout[i]++;
				(*listout[i]).push_back(i);
				listin[i]=prev((*listout[i]).end());
			}
			else
			{
				list_list.insert(next(listout[i]),var);
				listout[i]++;
				(*listout[i]).push_back(i);
				listin[i]=(*listout[i]).begin();
			}
		}
	}
	else
	{
		list_list.push_back(var);
		(list_list.back()).push_back(i);
		listout[i]++;
		listin[i]=(*listout[i]).begin();
	}
	if((*temp2).empty() && counts[i]!=0)
	{
		list_list.erase(temp2);
    }
	counts[i]++;
	return;
}
void counter::decrement(int i)
{
    int j;
	list<int>::iterator temp;
	list<int> var;
	list<list<int> >::iterator temp2;
	(*listout[i]).erase(listin[i]);
	temp2=listout[i];
	if(listout[i]!=list_list.begin())
	{
		if(prev(listout[i])!=zero_pos)
		{
			if(counts[(*prev(listout[i])).front()]==counts[i]-1)
			{
				listout[i]--;
				(*listout[i]).push_back(i);
				listin[i]=prev((*listout[i]).end());
			}
			else
			{
				list_list.insert(listout[i],var);
				listout[i]--;
				(*listout[i]).push_back(i);
				listin[i]=(*listout[i]).begin();
			}
		}
		else
		{
			if(counts[i]==1)
			{
				listout[i]--;
				(*listout[i]).push_back(i);
				listin[i]=prev((*listout[i]).end());
			}
			else
			{
				list_list.insert(listout[i],var);
				listout[i]--;
				(*listout[i]).push_back(i);
				listin[i]=(*listout[i]).begin();
			}
		}
	}
	else
	{
		list_list.push_front(var);
		(list_list.front()).push_back(i);
		listout[i]--;
		listin[i]=(*listout[i]).begin();
	}
	if((*temp2).empty() && counts[i]!=0)
		list_list.erase(temp2);
	counts[i]--;
	return;
}
void counter::reset(int i)
{
	if(counts[i]==0)
		return;
	else
	{
		list<list<int> >::iterator temp2;
		temp2=listout[i];
		(*listout[i]).erase(listin[i]);
		listout[i]=zero_pos;
		(*zero_pos).push_back(i);
		listin[i]=(*zero_pos).end();
		listin[i]--;
		if((*temp2).empty() && counts[i]!=0)
		{
			list_list.erase(temp2);
        }
		counts[i]=0;
	}
	return;
}
int counter::count(int i)
{
	return counts[i];
}
int counter::findMax()
{
	if(prev(list_list.end())==zero_pos && (*zero_pos).empty())
		return counts[(*prev(prev(list_list.end()))).front()];
	else
		return counts[(list_list.back()).front()];
}
int counter::numMax()
{
	if(prev(list_list.end())==zero_pos && (*zero_pos).empty())
		return (*prev(prev(list_list.end()))).size();
    else
    {
        return (list_list.back()).size();
    }
}
void counter::printMax()
{
	list<int>::iterator temp;
	if(prev(list_list.end())==zero_pos && (*zero_pos).empty())
	{
		for(temp = (*prev(prev(list_list.end()))).begin() ; temp!=(*prev(prev(list_list.end()))).end() ; temp++)
		{
			printf("%d\n",*temp);
		}

	}
	else
	{
		for(temp = (list_list.back()).begin() ; temp!=(list_list.back()).end() ; temp++)
		{
			printf("%d\n",*temp);
		}
	}
	return;
}
list<list<int> >::iterator counter::next(list<list<int> >::iterator x)
{
	list<list<int> >::iterator y;
	y=x;
	y++;
	return y;
}
list<list<int> >::iterator counter::prev(list<list<int> >::iterator x)
{
	list<list<int> >::iterator y;
	y=x;
	y--;
	return y;
}
list<int>::iterator counter::next(list<int>::iterator x)
{
	list<int>::iterator y;
	y=x;
	y++;
	return y;
}
list<int>::iterator counter::prev(list<int>::iterator x)
{
	list<int>::iterator y;
	y=x;
	y--;
	return y;
}