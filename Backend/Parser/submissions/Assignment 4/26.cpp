#include <cstdio>
#include <iostream>
#include <vector>
#include <list>
using namespace std;

//check spellings

class counter{
	vector<int> counts; // count of the ith object
	vector<list<int>::iterator> pToObject; // pointer to ith object
	vector< list< list<int> >::iterator > pToList; // pointer to list in which ith object is there.
	list< list<int> > LISTS;
	list< list<int> >::iterator ZEROLIST;
	
	public:
	counter(int n){
		list<int> newList;
		for(int i=0; i<n; i++) newList.push_back(i);
		LISTS.push_back(newList);
		ZEROLIST = LISTS.begin();
		
		counts.resize(n, 0);
		pToObject.resize(n);
		pToList.resize(n, ZEROLIST);
		int i = 0;
		for(list<int>::iterator it = ZEROLIST->begin(); it != ZEROLIST->end(); ++it){
			pToObject[i] = it;
			i++;
		}
	}


	void increment(int i){
		counts[i]++;
		pToList[i]->erase(pToObject[i]);
		list< list<int> >::iterator orig = pToList[i];
		list< list<int> >::iterator next = ++pToList[i];
		if(next == LISTS.end()){
			list<int> newList;
			newList.push_back(i);
			LISTS.push_back(newList);
		}
		else{
			int j;
			if(next == ZEROLIST) j = 0;
			else j = counts[next->front()]; // assumed that empty lists don't exists
			if(j==counts[i]){
				next->push_back(i);
			}
			else{
				list<int> newList;
				newList.push_back(i);
				LISTS.insert(next, newList);
			}
		}
		pToList[i] = orig;
		++pToList[i];
		if(orig->empty() && orig!=ZEROLIST){
			LISTS.erase(orig);
		}
		pToObject[i] = pToList[i]->end();
		--pToObject[i];
	}

	void decrement(int i){
		counts[i]--;
		pToList[i]->erase(pToObject[i]);
		list< list<int> >::iterator orig = pToList[i];
		if(orig == LISTS.begin()){
			list<int> newList;
			newList.push_back(i);
			LISTS.push_front(newList);
		}
		else{
			list< list<int> >::iterator next = --pToList[i];
			int j;
			if(next == ZEROLIST) j = 0;
			else j = counts[next->front()]; // assumed that empty lists don't exists
			if(j==counts[i]){
				next->push_back(i);
			}
			else{
				list<int> newList;
				newList.push_back(i);
				LISTS.insert(orig, newList);
			}
		}
		pToList[i] = orig;
		--pToList[i];
		if(orig->empty() && orig!=ZEROLIST){
			LISTS.erase(orig);
		}
		pToObject[i] = pToList[i]->end();
		--pToObject[i];
	}

	int count(int i){
		return counts[i];
	}
	
	void reset(int i){
		counts[i] = 0;
		pToList[i]->erase(pToObject[i]);
		list< list<int> >::iterator orig = pToList[i];
		
		pToList[i] = ZEROLIST;
		ZEROLIST->push_back(i);
		pToObject[i] = pToList[i]->end();
		--pToObject[i];
		
		if(orig->empty() && orig!=ZEROLIST){
			LISTS.erase(orig);
		}
	}
	
	int findMax(){
		list< list<int> >::iterator temp = LISTS.end();
		--temp;
		if(temp == ZEROLIST && ZEROLIST->size() == 0) --temp;
		return counts[temp->front()];
	}

	int numMax(){
		list< list<int> >::iterator temp = LISTS.end();
		--temp;
		if(temp == ZEROLIST && ZEROLIST->size() == 0) --temp;
		return temp->size();
	}

	void printMax(){
		list< list<int> >::iterator temp = LISTS.end();
		--temp;
		if(temp == ZEROLIST && ZEROLIST->size() == 0) --temp;
		for(list<int>::iterator it = temp->begin(); it != temp->end(); ++it){
			printf("%d\n", *it); 
		}
	}
};
/*
int main(){
	counter govind(5);
	govind.decrement(3);
	govind.decrement(1);
	govind.decrement(0);
	govind.decrement(4);
	govind.decrement(2);
	for(int i=0; i<5; i++){
		cout << govind.count(i) << " ";
	}
	cout << endl;
	cout << govind.findMax() << endl;
	cout << govind.numMax() << endl;
	govind.printMax();
	//cout << govind.LISTS.size() << endl;
	cout << "-------------" << endl;
	govind.increment(3);
	govind.decrement(3);
	cout << govind.findMax() << endl;
	govind.printMax();
	govind.increment(2);
	cout << "--- "<<endl;
	govind.increment(0);
	cout << "--- "<<endl;
	govind.increment(4);
	cout << "--- "<<endl;
	govind.increment(4);
	cout << "--- "<<endl;
	cout << govind.findMax() << endl;
	cout << "--- "<<endl;
	govind.printMax();
	cout << govind.numMax() << endl;
	govind.reset(3);
	for(int i=0; i<5; i++){
		cout << govind.count(i) << " ";
	}
	cout <<endl;
}

// remove main
*/
