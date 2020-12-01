#include <iostream>
#include <vector>
#include <list>
#include <utility>

using namespace std;

class counter 
{
	private:
	vector<int> count_val;
	list<list<int> > listOfCounts;
	vector<pair<list<list<int> >::iterator, list<int>::iterator> > pos;
	
	list<list<int> >::iterator it1;
	list<int>::iterator it2;
	
	
	public:
	counter(int);
	
	void increment(int);
	void decrement(int);
	void reset(int);
	int count(int);
	int findMax();
	int numMax();
	void printMax();		
};	

counter::counter (int n)
{
	//count_val.assign(n,0);
	for(int i=0; i<n; i++) count_val.push_back(0);
	//	pos.assign(n);
	//	listOfCounts.assign(1);
	
	list<int> countl;
	for(int i=0; i<n; i++) countl.push_back(i);
	listOfCounts.push_back(countl);
	
	//~ list<list<int> >::iterator it1;
	//~ list<int>::iterator it2;
	it1 = listOfCounts.begin();
	it2 = (*it1).begin();
	pair <list<list<int> >::iterator, list<int>::iterator> * temp;
	temp = new pair <list<list<int> >::iterator, list<int>::iterator>;
	
	for(;it2!=(*it1).end(); it2++)
	{
		*temp = make_pair(it1,it2);
		pos.push_back(*temp);	
	}
}

void counter::increment(int i)
{
	count_val[i] = count_val[i] + 1;
	
	it2 = (pos[i]).second;
	it1 = (pos[i]).first;
	
	if((*it1).size()==1)
	{
		it1 = listOfCounts.erase(it1);	
	}
	else it1++;
	
	if(it1==listOfCounts.end())
	{	
		list<int> tmp;
		listOfCounts.insert(it1,tmp);
		it1--;
		(*it1).push_back(i-1);
		it2 = (*it1).begin();
		
		pair <list<list<int> >::iterator, list<int>::iterator> temp;
		temp = make_pair(it1,it2);
		pos[i] = temp;	
	}
	else
	{
		it2 = (*it1).begin();
		if(*it2 == count_val[i])
		{
			(*it1).push_back(i-1);
			it2 = (*it1).end();
			it2--;
			
			pair <list<list<int> >::iterator, list<int>::iterator> temp;
			temp = make_pair(it1,it2);
			pos[i] = temp;	
		}
		else
		{
			list<int> tmp;
			listOfCounts.insert(it1,tmp);
			it1--;
			(*it1).push_back(i-1);
			it2 = (*it1).begin();
		
			pair <list<list<int> >::iterator, list<int>::iterator> temp;
			temp = make_pair(it1,it2);
			pos[i] = temp;	
		} 	
	}	
	
	
}

void counter::decrement(int i)
{
	count_val[i] = count_val[i] - 1;
	it1 = (pos[i]).first;
	it2 = (pos[i]).second;
	
	if((*it1).size()==1)
	{
		it1 = listOfCounts.erase(it1);	
	}
	
	it1--;
	it2 = (*it1).begin();
	if(*it2 == count_val[i])
	{
		(*it1).push_back(i-1);
		it2 = (*it1).end();
		it2--;
		pair <list<list<int> >::iterator, list<int>::iterator> temp;
		temp = make_pair(it1,it2);
		pos[i] = temp;	
	}
	else
	{
		it1++;
		
		list<int> tmp;
		listOfCounts.insert(it1,tmp);
		it1--;
		(*it1).push_back(i-1);
		it2 = (*it1).begin();
		
		pair <list<list<int> >::iterator, list<int>::iterator> temp;
		temp = make_pair(it1,it2);
		pos[i] = temp;
	}
		
}

void counter::reset(int i)
{
	count_val[i] = 0;
	it1 = (pos[i]).first;
	it2 = (pos[i]).second;
	if((*it1).size()==1)
	{
		it1 = listOfCounts.erase(it1);
	}
	
	it1 = listOfCounts.begin();
	it2 = (*it1).begin();
	if(*it2==0)
	{
		(*it1).push_back(i-1);
		it2 = (*it1).end();
		it2--;
		pair <list<list<int> >::iterator, list<int>::iterator> temp;
		temp = make_pair(it1,it2);
		pos[i] = temp;	
	}
	else
	{
		list<int> tmp;
		listOfCounts.insert(listOfCounts.begin(),tmp);
		it1 = listOfCounts.begin();
		(*it1).push_back(i-1);
		it2 = (*it1).begin();
		
		pair <list<list<int> >::iterator, list<int>::iterator> temp;
		temp = make_pair(it1,it2);
		pos[i] = temp;	
	}
			
}

int counter::count(int i)
{
	return count_val[i];	
}

int counter::findMax()
{
	it1 = listOfCounts.end();
	it1--;
	it2 = (*it1).begin();
	
	return count_val[*it2];
}

int counter::numMax()
{
	it1 = listOfCounts.end();
	it1--;

	return it1->size();	
}

void counter::printMax()
{
	it1 = listOfCounts.end();
	it1--;
	it2 = (*it1).begin();
	
	for(;it2!=(*it1).end(); it2++)
	{
		cout<< (*it2) <<endl;	
	}	
}

//~ int main()
//~ {	
	//~ int n,m;
	//~ cin>>n>>m;
	//~ class counter instance(n);
	
	//~ for(int i=0; i<m; i++)
	//~ {
		//~ char q;
		//~ int x;
		//~ cin>>q;
		//~ cout<<q<<endl;
		//~ switch(q)
		//~ {
			//~ case 'i':
				//~ cin>>x;
				//~ instance.increment(x);
				//~ break;
			//~ case 'd':
				//~ cin>>x;
				//~ instance.decrement(x);
				//~ break;
			//~ case 'r':
				//~ cin>>x;
				//~ instance.reset(x);
				//~ break;
			//~ case 'c':
				//~ cin>>x;
				//~ cout<<"count "<<instance.count(x)<<endl;
				//~ break;
			//~ case 'f':
				//cin>>x;
				//~ cout<<"find max "<<instance.findMax()<<endl;
				//~ break;
			//~ case 'n':
				//cin>>x;
				//~ cout<<" num "<<instance.numMax()<<endl;
				//~ break;
			//~ case 'p':
				//cin>>x;
				//~ instance.printMax();
				//~ break;
		//~ }
	//~ }
	//~ for(int i=0; i<10; i++) 
	//~ {
		//~ cout<<instance.count(i)<<endl;
		//~ instance.increment(i);
	//~ }
	
	//~ for(int i=0; i<10; i++) 
	//~ {
		//~ instance.increment(i);
		//~ cout<<instance.count(i)<<endl;
	//~ }
	//~ cout<<endl;
	//~ for(int i=0; i<10; i++) 
	//~ {
		//~ instance.decrement(i);
		//~ cout<<instance.count(i)<<endl;
	//~ }
	
	//~ for(int i=0; i<=10; i+=2) 
	//~ {
		//~ instance.reset(i);
		//~ cout<<instance.count(i)<<endl<<instance.count(i+1)<<endl;
	//~ }
	
//~ //	cout<<"max
	//~ return 0;	
//~ }
