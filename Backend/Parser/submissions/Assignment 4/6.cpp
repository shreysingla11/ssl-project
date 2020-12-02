#include <iostream>
#include <cstdio>
#include <vector>
#include <list>
using namespace std;

class counter
{
	int n;
	vector<int> visitcount;
	vector<list<int>::iterator> webpagepointer;
	vector<list< list<int> >::iterator > curlistpointer;
	list< list<int> >::iterator zerolistpointer;
	list< list<int> > sortedlists;
public:
	counter(int size)
	{
		list<int> l1;
		list<int>::iterator it;
		n=size;
		visitcount.resize(n,0);
		webpagepointer.resize(n);
		sortedlists.push_back(l1);
		for(int i=0;i<n;i++)
		{
			sortedlists.front().push_back(i);
			it = sortedlists.front().end();
			webpagepointer[i] = --it;
		}
		curlistpointer.resize(n,sortedlists.begin());
		zerolistpointer = sortedlists.begin();
	}
	
	void reset(int i)
	{
		list<int>::iterator it;
		if(visitcount[i]!=0)
		{
			visitcount[i] = 0;
			(*curlistpointer[i]).erase(webpagepointer[i]);
			if((*curlistpointer[i]).empty())
			{
				sortedlists.erase(curlistpointer[i]);
			}
			(*zerolistpointer).push_back(i);
			curlistpointer[i]=zerolistpointer;
			it = (*zerolistpointer).end();
			webpagepointer[i]=--it;
		}
	}

	void increment(int i)
	{
		list<int> newlist;
		list<int>::iterator it;
		if(visitcount[i]==-1)
		{
			reset(i);
			return;
		}
		visitcount[i]++;
		(*curlistpointer[i]).erase(webpagepointer[i]);
		if((*curlistpointer[i]).empty() && visitcount[i]!=1)
		{
			curlistpointer[i] = sortedlists.erase(curlistpointer[i]);
		}
		else
		{
			curlistpointer[i]++;
		}
		if(curlistpointer[i]==sortedlists.end())
		{
			curlistpointer[i] = sortedlists.insert(curlistpointer[i], newlist);
		}
		else if(visitcount[(*curlistpointer[i]).front()]!=visitcount[i])
		{
			curlistpointer[i] = sortedlists.insert(curlistpointer[i], newlist);
		}
		(*curlistpointer[i]).push_back(i);
		it = (*curlistpointer[i]).end();
		webpagepointer[i] = --it;
	}

	void decrement(int i)
	{
		list<int> newlist;
		list<int>::iterator it;
		if(visitcount[i]==1)
		{
			reset(i);
			return;
		}
		visitcount[i]--;
		(*curlistpointer[i]).erase(webpagepointer[i]);
		if((*curlistpointer[i]).empty() && visitcount[i]!=-1)
		{
			curlistpointer[i] = sortedlists.erase(curlistpointer[i]);
		}
		if(curlistpointer[i]==sortedlists.begin())
		{
			curlistpointer[i] = sortedlists.insert(curlistpointer[i], newlist);
		}
		else
		{
			curlistpointer[i]-- ;
			if(visitcount[(*curlistpointer[i]).front()]!=visitcount[i])
			{
				curlistpointer[i]++;
				curlistpointer[i] = sortedlists.insert(curlistpointer[i], newlist);
			}
		}
		(*curlistpointer[i]).push_back(i);
		it = (*curlistpointer[i]).end();
		webpagepointer[i]=--it;
	}

	int count(int i)
	{
		return visitcount[i];
	}

	int findMax()
	{
		list< list<int> >::iterator lastlistpointer = sortedlists.end();
		lastlistpointer--;
		int maxmindex;
		if((*lastlistpointer).empty())
		{
			lastlistpointer--;
		}
		maxmindex = (*lastlistpointer).front();
		return visitcount[maxmindex];
	}

	int numMax()
	{
		list< list<int> >::iterator lastlistpointer = sortedlists.end();
		lastlistpointer--;
		if((*lastlistpointer).empty())
		{
			lastlistpointer--;
		}
		return (*lastlistpointer).size();
	}

	void printMax()
	{
		list< list<int> >::iterator lastlistpointer = sortedlists.end();
		lastlistpointer--;
		list<int>:: iterator it;

		if((*lastlistpointer).empty())
		{
			lastlistpointer--;
		}

		for(it=(*lastlistpointer).begin();it!=(*lastlistpointer).end();it++)
		{
			printf("%d\n",*it);
		}
	}
};
