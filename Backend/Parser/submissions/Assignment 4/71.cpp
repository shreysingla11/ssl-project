# include <iostream>
# include <list>
# include <vector>
# include <cstdio>
using namespace std;

struct mainNode
{
	mainNode(int i)
	{
		numElements = 0;
		count = i;
	}
	int numElements;
	int count;
	list<int> subList;
};

struct pairx
{
    pairx(list<mainNode> ::iterator x, list<int> ::iterator y)
    {
        mainIterator = x;
        subListIterator = y;
    }
	list<mainNode> ::iterator mainIterator;
	list<int> ::iterator subListIterator;
};

list<int>::iterator prev(list<int>::iterator x);
list<int>::iterator next(list<int>::iterator x);
list<mainNode>::iterator prev(list<mainNode>::iterator x);
list<mainNode>::iterator next(list<mainNode>::iterator x);

class counter{

	int N;
	list <mainNode> mainList;
	vector <pairx> iteratorPair;
	list <mainNode>:: iterator zeroIterator;

public:
    counter(int n)
	{
		N = n;

		// create a newNode to push_back into the main list
		mainNode tempNode(0);
		mainList.push_back(tempNode);
		zeroIterator = mainList.begin();

		for (int i = 0; i < N; ++i)
		{
			// increase numberof elements in the node.
			mainList.back().numElements++;
			mainList.back().subList.push_back(i);
			// the iteratosublist contains the iterator for each element in the sublist itself
			// as tempnode sublist is being added, tempnode.sublist.end() changes, thus we pb those
			iteratorPair.push_back(pairx(prev(mainList.end()),prev(mainList.back().subList.end())));
		}
	}

	void increment(int i);
	void decrement(int i);
	void reset(int i);
	int findMax();
	int numMax();
	void printMax();
	int count(int i);
};

void counter::increment(int i)
{
	list<mainNode> :: iterator currIterator = iteratorPair[i].mainIterator;
	int currCount = (*currIterator).count;

	// the if-else block ensure that there is a node after the current one with count = currcount +1
	if(currIterator == prev(mainList.end()))	// if this is the last iterator
	{
		mainNode tempNode(currCount + 1);
		mainList.push_back(tempNode);
	}
	else 	// there exists another next mainNode
	{
		if ( (*(next(currIterator))).count != currCount + 1)	// the next node is not currcoutn+1
		{
			mainNode tempNode(currCount + 1);
			mainList.insert(next(currIterator), tempNode);
		}
	}

	// inserting the new element in the next node
	(*(next(currIterator))).subList.push_back(i);
	(*(next(currIterator))).numElements++;

	// deleting the original element
	(*currIterator).subList.erase(iteratorPair[i].subListIterator);
	(*currIterator).numElements--;

	iteratorPair[i].subListIterator = prev((*next(currIterator)).subList.end());
	iteratorPair[i].mainIterator = ++currIterator;
	// if node is empty ,remove it
	if((*prev(currIterator)).numElements == 0)
		if(prev(currIterator) != zeroIterator)
			mainList.erase(prev(currIterator));

}
void counter::decrement(int i)
{
	list<mainNode> :: iterator currIterator = iteratorPair[i].mainIterator;
	int currCount = (*currIterator).count;

	// the if-else block ensure that there is a node after the current one with count = currcount +1
	if(currIterator == mainList.begin())// if this is the last iterator
	{
		mainNode tempNode(currCount - 1);
		mainList.push_front(tempNode);
	}
	else 	// there exists another next mainNode
	{
		if ( (*(prev(currIterator))).count != currCount - 1)	// the next node is not currcoutn+1
		{
			mainNode tempNode(currCount - 1);
			mainList.insert(currIterator, tempNode);
		}
	}

	// inserting the new element in the next node
	(*(prev(currIterator))).subList.push_back(i);
	(*(prev(currIterator))).numElements++;

	// deleting the original element
	(*currIterator).subList.erase(iteratorPair[i].subListIterator);
	(*currIterator).numElements--;

	iteratorPair[i].subListIterator = prev((*prev(currIterator)).subList.end());
	iteratorPair[i].mainIterator = --currIterator;
	// if node is empty ,remove it
	if((*next(currIterator)).numElements == 0)
		if(next(currIterator) != zeroIterator)
			mainList.erase(next(currIterator));
}
void counter::reset(int i)
{
	list<mainNode> :: iterator currIterator = iteratorPair[i].mainIterator;

	// the if-else block ensure that there is a node after the current one with count = currcount +1
	if((*currIterator).count != 0)
	{
		(*zeroIterator).numElements++;
		(*zeroIterator).subList.push_back(i);

		(*currIterator).subList.erase(iteratorPair[i].subListIterator);
		(*currIterator).numElements--;
		if((*currIterator).numElements == 0)
		{
			mainList.erase(currIterator);
		}
		iteratorPair[i].mainIterator = zeroIterator;
		iteratorPair[i].subListIterator = prev((*zeroIterator).subList.end());
	}
}
int counter::findMax()
{
	return (*prev(mainList.end())).count;
}
int counter::numMax()
{
	return (*prev(mainList.end())).numElements;
}
void counter::printMax()
{
	for (list<int>:: iterator t=(*prev(mainList.end())).subList.begin() ; t != (*prev(mainList.end())).subList.end(); t++)
	{
		printf("%d\n",*t);
	}
}
int counter::count(int i)
{
	return (*(iteratorPair[i].mainIterator)).count;
}
list<int>::iterator prev(list<int>::iterator x)
{
	list<int>::iterator y;
	y = --x;
	x++;
	return y;
}
list<int>::iterator next(list<int>::iterator x)
{
	list<int>::iterator y;
	y = ++x;
	x--;
	return y;
}
list<mainNode>::iterator prev(list<mainNode>::iterator x)
{
	list<mainNode>::iterator y;
	y = --x;
	x++;
	return y;
}
list<mainNode>::iterator next(list<mainNode>::iterator x)
{
	list<mainNode>::iterator y;
	y = ++x;
	x--;
	return y;
}
