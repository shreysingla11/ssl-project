#include <iostream>
#include <list>
#include <vector>
#include <cstdio>
using namespace std;

class counter {

	list<list<int> > Hub;
	list<list<int> >::iterator itCount;
	list<int>::iterator itPos;
	vector<list< list<int> >::iterator> Count;
	list<list<int> >::iterator it0;
	vector<list <int>::iterator> Pos;
	vector<int> PageCount;
	vector<int> NumCount;

public:
	counter(int x) {

        Hub.push_back(list<int>());
        itCount=Hub.begin();
        (*itCount).push_back(x);
        itPos = (*itCount).begin();
		for(int i=0;i<x;i++) {
            Count.push_back(itCount);
            		        //cout<<"hi"<<endl;
            (*itCount).push_back(i);
            //cout<<(*itPos)<<endl;
            Pos.push_back(++itPos);
            PageCount.push_back(0);
            //cout<<(*Pos[i])<<" "<<endl;

		}
		it0=itCount;
	}

	void increment(int i) {

    //NumCount[PageCount[i]]--;
    PageCount[i]++;
    Count[i]++;
    itCount=Count[i];
    Count[i]--;
    if(itCount==Hub.end()) {
        Hub.push_back(list<int>());
        //NumCount.push_back(0);
        Count[i]++;
        (*Count[i]).push_back(0);
        Count[i]--;
        (*(Count[i])).erase(Pos[i]);
        (*(*Count[i]).begin())--;
        if ((*(*Count[i]).begin())==0) {
            if(Count[i]==Hub.begin() && Hub.begin()!=it0) {
                Count[i]++;
                Hub.pop_front();
            }
            else Count[i]++;
        }
        else Count[i]++;
        (*Count[i]).push_back(i);
        Pos[i]=(*Count[i]).end();
        Pos[i]--;
    }
    else{
    //cout<<"hi"<<endl;
        (*(Count[i])).erase(Pos[i]);
        (*(*Count[i]).begin())--;
        if ((*(*Count[i]).begin())==0) {
            if(Count[i]==Hub.begin() && Hub.begin()!=it0) {
                Count[i]++;
                Hub.pop_front();
            }
            else Count[i]++;
        }
        else Count[i]++;
       /* if((*Count[i]).size()==1 && PageCount[i]!=1) {
        itCount = Count[i];
        Count[i]++;
        Hub.erase(itCount);
        }*/
        (*Count[i]).push_back(i);
        Pos[i]=(*Count[i]).end();
        Pos[i]--;
        //cout<<*Pos[i]<<endl;
	}
	(*(*Count[i]).begin())++;
    //cout<<PageCount[i]<<" "<<(*(*Count[i]).begin())<<endl;

	}

	void decrement(int i) {

    //NumCount[PageCount[i]]--;
    PageCount[i]--;
    if(Count[i]==Hub.begin()) {
        Hub.push_front(list<int>());
        //NumCount.push_back(0);
        Count[i]--;
        (*Count[i]).push_back(0);
        Count[i]++;
        (*(Count[i])).erase(Pos[i]);
        (*(*Count[i]).begin())--;
        if ((*(*Count[i]).begin())==0) {
            itCount = Hub.end();
            itCount--;
            if(Count[i]==itCount && itCount!=it0) {
                Count[i]--;
                Hub.pop_back();
            }
            else Count[i]--;
        }
        else Count[i]--;
        (*Count[i]).push_back(i);
        Pos[i]=(*Count[i]).end();
        Pos[i]--;
    }
    else{
    //cout<<"hi"<<endl;
        (*(Count[i])).erase(Pos[i]);
        (*(*Count[i]).begin())--;
        if ((*(*Count[i]).begin())==0) {
            itCount = Hub.end();
            itCount--;
            if(Count[i]==itCount && itCount!=it0) {
                Count[i]--;
                Hub.pop_back();
            }
            else Count[i]--;
        }
        else Count[i]--;
       /* if((*Count[i]).size()==1 && PageCount[i]!=1) {
        itCount = Count[i];
        Count[i]++;
        Hub.erase(itCount);
        }*/
        (*Count[i]).push_back(i);
        Pos[i]=(*Count[i]).end();
        Pos[i]--;
        //cout<<*Pos[i]<<endl;
	}
	(*(*Count[i]).begin())++;
    //cout<<PageCount[i]<<" "<<(*(*Count[i]).begin())<<endl;

	}

    void reset(int i) {

        (*(*Count[i]).begin())--;
        (*(Count[i])).erase(Pos[i]);
        if ((*(*Count[i]).begin())==0) {
            itCount = Hub.end();
            itCount--;
            if(Count[i]==itCount && itCount!=it0) {
                Count[i]--;
                Hub.pop_back();
            }
            else {
                if(Count[i]==Hub.begin() && Hub.begin()!=it0) {
                Count[i]++;
                Hub.pop_front();
            }
            }
        }
        Count[i]=it0;
        (*Count[i]).push_back(i);
        Pos[i]=(*Count[i]).end();
        Pos[i]--;
        PageCount[i]=0;
        (*(*Count[i]).begin())++;
        //cout<<PageCount[i]<<" "<<(*(*Count[i]).begin())<<endl;

    }

    int count(int i) {
        return PageCount[i];
    }

    int findMax() {
        itCount = Hub.end();
        itCount--;
        while((*(*itCount).begin())==0) itCount--;
        itPos = (*itCount).begin();
        itPos++;
        return PageCount[*itPos];
    }

    int numMax() {
        itCount = Hub.end();
        itCount--;
        while((*(*itCount).begin())==0) itCount--;
        return ((*itCount).size()-1);
    }

    void printMax() {
        itCount = Hub.end();
        itCount--;
        while((*(*itCount).begin())==0) itCount--;
        list<int> :: iterator k=(*itCount).begin();
        k++;
        for(;k!=(*itCount).end();k++) {
            cout<<*k<<endl;
        }
    }

};
