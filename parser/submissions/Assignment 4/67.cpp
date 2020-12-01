#include <iostream>
#include <cstdio>
#include <list>
#include <vector>
using namespace std;

typedef list<list<int > >::iterator itLofL;
typedef list<int >::iterator itL;

class counter
{
	vector<int > counts;
	list<list<int > > listOfList;
	vector<itLofL> listoflistIterator;
	vector<itL> listIterator;
	list<list<int > >::iterator itToZero;

public:

	counter(int n)
	{
		counts.resize(n);
		itL temp;
		//temp=innerlist.begin();
        list<int > innerlist;

		listIterator.resize(n);
		int i;
		for (i = 0; i < n; ++i)
		{
			innerlist.push_back(i);
		}

		listOfList.push_back(innerlist);
		listoflistIterator.resize(n,listOfList.begin());
		temp = listOfList.front().begin();

		for (i = 0; i < n; ++i)
		{
			listIterator[i]=temp;
			temp++;
			//cout<<"initial iter "<<*(listIterator[i])<<endl;
		}
		itToZero=listOfList.begin();

	}

	void increment(int i);
	void decrement(int i);
	void reset(int i);
	int count(int i);
	int findMax();
	int numMax();
	void printMax();

};

void counter::increment(int i)
{
	//shift element to next list
	counts[i]++;
	itLofL temp;
	temp = (listoflistIterator[i]);
	//cout<<"Count of "<<i<<": "<<counts[i]<<endl;
	(*(listoflistIterator[i])).erase((listIterator[i]));

	if (listoflistIterator[i] == (--listOfList.end()))
	{
		list<int > newList;
		newList.push_back(i);
		listOfList.push_back(newList);
		listIterator[i]=listOfList.back().begin();
		listoflistIterator[i]++;
		//cout<<"iter1 "<<*(listIterator[i])<<endl;
	}

	else
	{
		listoflistIterator[i]++;
		//cout<<"count  "<<counts[(*(listoflistIterator[i])).front()]<<endl;
		if (counts[(*(listoflistIterator[i])).front()] == counts[i])
		{
			(*(listoflistIterator[i])).push_back(i);
			listIterator[i]= --((*(listoflistIterator[i])).end());
			//cout<<"iter2 "<<*(listIterator[i])<<endl;
		}

		else
		{
			list<int > newList;
			newList.push_back(i);
			listOfList.insert(listoflistIterator[i],newList);
			listIterator[i]=(*(--listoflistIterator[i])).begin();
			//listoflistIterator[i]--;
			//cout<<"iter3 "<<*(listIterator[i])<<endl;
		}

	}

	if ((*temp).empty() && counts[i]-1 != 0)
	{
        //cout<<"delete"<<endl;
		listOfList.erase(temp);
	}


	return;
}

void counter::decrement(int i)
{
	//shift element to prev list
	counts[i]--;
	//cout<<"Count of "<<i<<": "<<counts[i]<<endl;
	itLofL temp;
	temp = listoflistIterator[i];

	(*(listoflistIterator[i])).erase((listIterator[i]));

	if (listoflistIterator[i] == itToZero && counts[i]==0)
		{
			(*(listoflistIterator[i])).push_back(i);
			listIterator[i]= --((*(listoflistIterator[i])).end());
		}
	else
	{
		if (listoflistIterator[i] == listOfList.begin())
		{
			list<int > newList;
			newList.push_back(i);
			listOfList.push_front(newList);
			listIterator[i]=listOfList.front().begin();
			listoflistIterator[i]--;
			//cout<<"iter1 "<<*(listIterator[i])<<endl;
		}

		else
		{
			listoflistIterator[i]--;
			if (counts[(*(listoflistIterator[i])).front()] == counts[i])
			{
				(*(listoflistIterator[i])).push_back(i);
				listIterator[i]= --((*(listoflistIterator[i])).end());
				//cout<<"iter2 "<<*(listIterator[i])<<endl;
			}

			else
			{
				list<int > newList;
				newList.push_back(i);
				listOfList.insert(++listoflistIterator[i],newList);
				listIterator[i]=(*(--listoflistIterator[i])).begin();
				//listoflistIterator[i]--;
				//cout<<"iter3 "<<*(listIterator[i])<<endl;
			}

		}
	}	

	//cout<<"size "<<(*temp).size()<<" counts "<<counts[i]+1<<endl;
	if ((*temp).empty() && counts[i]+1 != 0)
	{
		//cout<<"delete"<<endl;
		listOfList.erase(temp);
	}

	return;
}

void counter::reset(int i)
{
	//shift element to zero list
	if (counts[i] != 0)
	{
		counts[i]=0;
		itLofL temp;
		temp = listoflistIterator[i];
		(*(listoflistIterator[i])).erase((listIterator[i]));
		listoflistIterator[i]=itToZero;
		(*(listoflistIterator[i])).push_back(i);
		
		listIterator[i]= --((*(listoflistIterator[i])).end());

		if ((*temp).empty() )
		{
			//cout<<"delete"<<endl;
			listOfList.erase(temp);
		}
	}
	return;
}

int counter::count(int i)
{
	return counts[i];
}

int counter::findMax()
{
	//return count of first element of last list;
	itLofL temp = listOfList.end();
	temp--;
	if ((*temp).empty())
		temp--;
	return counts[(*temp).front()];
}

int counter::numMax()
{
	//return size of last list;
	itLofL temp = listOfList.end();
	temp--;
	if ((*temp).empty())
		temp--;
	return (*temp).size();
}
void counter::printMax()
{
	itLofL temp = listOfList.end();
	temp--;
	if ((*temp).empty())
		temp--;
	for (itL it = (*temp).begin() ; it!= (*temp).end() ; ++it)
	{
		printf("%d\n",*it);
	}
	return;
}