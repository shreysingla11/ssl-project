#include <iostream>
#include <vector>
#include <list>
#include <cstdio>

using namespace std;

struct obj {
	int value;
	int index;
	list<list<obj> >::iterator branch;
	obj() {
		value = 0;
		index = 0;
	}
	obj(int v, int i) {
		value = v;
		index = i;
	}
};
class counter{

	//member variables
	int n;
	list<list<obj> > mainList;
	vector<list<obj>::iterator > mainVec;
	int maxVal;//stores findMax
	//int maxNum;//stores numMax
	list<list<obj> >::iterator zeroList;
	list<list<obj> >::iterator maxList;

public:
	//Constructor
	counter(int num) {
		n = num;
		list<obj> initial(n);
		mainList.push_back(initial);
		int i = 0;
		for (list<obj>::iterator it = (mainList.begin())->begin(); i<n; i++, it++) {
			mainVec.push_back(it);
			it->index = i;
			it->branch = mainList.begin();
		}
		maxVal = 0;
		//maxNum = n;
		maxList = mainList.begin();
		zeroList = mainList.begin();
	}

	//member functions

	void increment(int i) {
		list<list<obj> >::iterator b = mainVec[i]->branch;
		b++;

		if(b == mainList.end()) {
			list<obj> add(1);
			mainList.push_back(add);
			b = mainList.end();
			b--;
			list<obj>::iterator it = b->begin();
			it->value = (mainVec[i]->value)+1;
			it->index = i;
			it->branch = b;
			mainVec[i]->branch->erase(mainVec[i]);
			if (mainVec[i]->branch->begin() == mainVec[i]->branch->end()) {
				list<list<obj> >::iterator x = mainVec[i]->branch;
				if(x == zeroList) {
					if (mainVec[i]->value >= 0) {
						if(x!=mainList.begin()) {
							x--;
							zeroList = x;
						}
						else {
							zeroList = ++x;
						}
						
					}
					else if (mainVec[i]->value < 0) {
						x++;
						if(x!=mainList.end()) {
							zeroList = x;
						}
						else {
							zeroList = --x;
						}
					}
				}
				mainList.erase(mainVec[i]->branch);
			}
			mainVec[i] = b->begin();
			maxVal = it->value;
			//maxNum = 1;
			maxList = b;
		}
		else if(b->begin()->value == mainVec[i]->value+1) {
			
			obj ins(mainVec[i]->value+1, i);
			ins.branch = b;

			b->push_back(ins);
			list<obj>::iterator c = b->end();
			c--;

			mainVec[i]->branch->erase(mainVec[i]);
			if (mainVec[i]->branch->begin() == mainVec[i]->branch->end()) {

				list<list<obj> >::iterator x = mainVec[i]->branch;
				if(x == zeroList) {
					if (mainVec[i]->value >= 0) {
						if(x!=mainList.begin()) {
							x--;
							zeroList = x;
						}
						else {
							zeroList = ++x;
						}
						
					}
					else if (mainVec[i]->value < 0) {
						x++;
						if(x!=mainList.end()) {
							zeroList = x;
						}
						else {
							zeroList = --x;
						}
					}
				}

				mainList.erase(mainVec[i]->branch);
			}
			mainVec[i] = c;
			b++;
			// if (b == mainList.end()) {
			// 	//maxNum++;
			// }
		}
		else {

			list<obj> add(1);
			mainList.insert(b, add);
			b--;
			list<obj>::iterator it = b->begin();
			it->value = (mainVec[i]->value)+1;
			
			it->index = i;
			it->branch = b;
			mainVec[i]->branch->erase(mainVec[i]);
			if (mainVec[i]->branch->begin() == mainVec[i]->branch->end()) {

				list<list<obj> >::iterator x = mainVec[i]->branch;
				if(x == zeroList) {
					if (mainVec[i]->value >= 0) {
						if(x!=mainList.begin()) {
							x--;
							zeroList = x;
						}
						else {
							zeroList = ++x;
						}
						
					}
					else if (mainVec[i]->value < 0) {
						x++;
						if(x!=mainList.end()) {
							zeroList = x;
						}
						else {
							zeroList = --x;
						}
					}
				}
				mainList.erase(mainVec[i]->branch);
			}
			mainVec[i] = b->begin();
		}

		if (mainVec[i]->value == 0) {
			zeroList = mainVec[i]->branch;
		}

	}

	void decrement(int i) {
		list<list<obj> >::iterator b = mainVec[i]->branch;
		if(b == mainList.begin()) {
			list<obj> add(1);
			mainList.push_front(add);
			b = mainList.begin();
			list<obj>::iterator it = b->begin();
			it->value = (mainVec[i]->value)-1;
			it->index = i;
			it->branch = b;
			mainVec[i]->branch->erase(mainVec[i]);
			// if (mainVec[i]->branch == maxList) {
			// 	maxNum--;
			// }
			if (mainVec[i]->branch->begin() == mainVec[i]->branch->end()) {
				list<list<obj> >::iterator x = mainVec[i]->branch;
				if(x == zeroList) {
					if (mainVec[i]->value >= 0) {
						if(x!=mainList.begin()) {
							x--;
							zeroList = x;
						}
						else {
							zeroList = ++x;
						}
						
					}
					else if (mainVec[i]->value < 0) {
						x++;
						if(x!=mainList.end()) {
							zeroList = x;
						}
						else {
							zeroList = --x;
						}
					}
				}
				mainList.erase(mainVec[i]->branch);
				if (mainVec[i]->branch == maxList) {
				maxVal = it->value;
				//maxNum = 1;
				maxList = b;
			}
			}
			mainVec[i] = b->begin();
			
		}
		else{
		b--;
		if(b->begin()->value == mainVec[i]->value-1) {
			
			obj ins(mainVec[i]->value-1, i);
			ins.branch = b;

			b->push_back(ins);
			list<obj>::iterator c = b->end();
			c--;
			
			mainVec[i]->branch->erase(mainVec[i]);
			// if (mainVec[i]->branch == maxList) {
			// 	maxNum--;
			// }
			if (mainVec[i]->branch->begin() == mainVec[i]->branch->end()) {
				list<list<obj> >::iterator x = mainVec[i]->branch;
				if(x == zeroList) {
					if (mainVec[i]->value >= 0) {
						if(x!=mainList.begin()) {
							x--;
							zeroList = x;
						}
						else {
							zeroList = ++x;
						}
						
					}
					else if (mainVec[i]->value < 0) {
						x++;
						if(x!=mainList.end()) {
							zeroList = x;
						}
						else {
							zeroList = --x;
						}
					}
				}
				mainList.erase(mainVec[i]->branch);
				if (mainVec[i]->branch == maxList) {
				maxVal = ins.value;
				//maxNum = b->size();
				maxList = b;
			}

			}
			mainVec[i] = c;

		}
		else {
			b++;
			list<obj> add(1);
			mainList.insert(b, add);
			b--;
			list<obj>::iterator it = b->begin();
			it->value = (mainVec[i]->value)-1;
			
			it->index = i;
			it->branch = b;
			mainVec[i]->branch->erase(mainVec[i]);
			// if (mainVec[i]->branch == maxList) {
			// 	maxNum--;
			// }
			if (mainVec[i]->branch->begin() == mainVec[i]->branch->end()) {
				list<list<obj> >::iterator x = mainVec[i]->branch;
				if(x == zeroList) {
					if (mainVec[i]->value >= 0) {
						if(x!=mainList.begin()) {
							x--;
							zeroList = x;
						}
						else {
							zeroList = ++x;
						}
						
					}
					else if (mainVec[i]->value < 0) {
						x++;
						if(x!=mainList.end()) {
							zeroList = x;
						}
						else {
							zeroList = --x;
						}
					}
				}
				mainList.erase(mainVec[i]->branch);
				if (mainVec[i]->branch == maxList) {
				maxVal = it->value;
				//maxNum = 1;
				maxList = b;
			}
			}
			mainVec[i] = b->begin();


		}


		}

		if (mainVec[i]->value == 0) {
			zeroList = mainVec[i]->branch;
		}


	}

	void reset(int i) {
		
		list<obj> add(0);
		obj temp(0, i);

		int zero = zeroList->begin()->value;

		if (zero == 0) {
			temp.branch = zeroList;
			zeroList->push_back(temp);

		}
		else {
			if (zero<0) {zeroList++;}
			mainList.insert(zeroList, add);
			zeroList--;
			temp.branch = zeroList;
			zeroList->push_back(temp);
		}
		list<obj>::iterator c = zeroList->end();
		c--;
		list<list<obj> >::iterator z = mainList.end();
		z--;
		list<list<obj> >::iterator b = mainVec[i]->branch;
		b++;
		//cout<<z->begin()->value<<endl;
		if(b == mainList.end()) {
			
			b--;
			mainVec[i]->branch->erase(mainVec[i]);
			if (mainVec[i]->branch->begin() == mainVec[i]->branch->end()) {
				b--;
				mainList.erase(mainVec[i]->branch);
				maxVal = b->begin()->value;
				//maxNum = b->size();
				maxList = b;
			}
			else {
				//maxNum--;
			}
			mainVec[i] = c;
			
		}
		else {

			if (zeroList == z) {

				mainVec[i]->branch->erase(mainVec[i]);
				if (mainVec[i]->branch->begin() == mainVec[i]->branch->end()) {
					mainList.erase(mainVec[i]->branch);
				}
				maxVal = 0;
				//maxNum = z->size();
				maxList = z;
				mainVec[i] = c;

			}
			else {
				mainVec[i]->branch->erase(mainVec[i]);
				if (mainVec[i]->branch->begin() == mainVec[i]->branch->end()) {
					mainList.erase(mainVec[i]->branch);
				}
				mainVec[i] = c;
			}

		}

	}


	int count(int i) {
		if(i < n && i>=0) {
			return mainVec[i]->value;
		}
		else {
			cout<<"Something is Wrong:from count"<<endl;
			return -1;
		}

	}

	int findMax() {
		return maxVal;
	}

	int numMax() {
		return maxList->size();
	}

	void printMax() {
		list<obj>::iterator it = maxList->begin();
		for (int i=0; it!=maxList->end(); i++, it++) {
			printf("%d ", it->index);
		}
		cout<<endl;
	}



};

