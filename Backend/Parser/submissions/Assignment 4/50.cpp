#include<iostream>
#include<list>
#include<vector>
using namespace std;
struct pg{

};
class counter{
	int n;
	list< list<int> > Main;
	list< list<int> >::iterator i;
	list< list<int> >::iterator q;
	vector<list< list<int> >::iterator> MainList;
	vector<list<int> :: iterator> Inside;
	list<int> :: iterator l;
	vector<int> c;
public:
	counter(int x){
		n=x;
		list<int> :: iterator m;
		Main.push_back(list<int>());
		i=Main.begin();
        i->push_back(0);
        q=i;
		for(int j=0;j<n;j++){
			MainList.push_back(i);
			i->push_back(j);
			if(j==0){
				m=++(i->begin());
				Inside.push_back(m);
			}
			else{
			Inside.push_back(++m);
			}

			c.push_back(0);

		}
	}
	void increment(int a){
	if(a<n){
		c[a]++;

		++MainList[a];
		if(MainList[a]==Main.end()){
            MainList[a]--;
			Main.push_back(list<int>());
			MainList[a]++;
			MainList[a]->push_back(c[a]);
			MainList[a]->push_back(a);
			MainList[a]--;
			MainList[a]->erase(Inside[a]);
			l=++(MainList[a]->begin());
			if(l==MainList[a]->end() && (*(MainList[a]->begin())!=0))
			{
			MainList[a]=Main.erase(MainList[a]);
			}
			else{
			MainList[a]++;}
			Inside[a]=MainList[a]->begin();
			Inside[a]++;
		}
		else{
            if(*(MainList[a]->begin())-c[a]>0){
                MainList[a]=Main.insert(MainList[a],list<int>());
                MainList[a]->push_back(c[a]);
            }

			MainList[a]->push_back(a);
			MainList[a]--;
			MainList[a]->erase(Inside[a]);
//			cout<<MainList[a]->size()<<endl;
			l=++(MainList[a]->begin());
			if(l==MainList[a]->end() && (*(MainList[a]->begin())!=0))
			{
			MainList[a]=Main.erase(MainList[a]);

			}
			else{
			MainList[a]++;
			}
			Inside[a]=(MainList[a]->end());
			Inside[a]--;
		}

}
	}
	void decrement(int a){
	if(a<n){
		c[a]--;
		if (MainList[a]==Main.begin())
		{
			Main.push_front(list<int>());
			MainList[a]--;
			MainList[a]->push_back(c[a]);
			(MainList[a])->push_back(a);
			MainList[a]++;
			MainList[a]->erase(Inside[a]);
			l=++(MainList[a]->begin());
			if(l==MainList[a]->end() && (*(MainList[a]->begin())!=0))
			{
			MainList[a]=Main.erase(MainList[a]);
			}
       	 	MainList[a]--;
			Inside[a]=((MainList[a])->end());
			Inside[a]--;
		}
		else{
        MainList[a]--;
        if(*(MainList[a]->begin())-c[a]<0){
            MainList[a]++;
            MainList[a]=Main.insert(MainList[a],list<int>());
            MainList[a]->push_back(c[a]);
        }
		(MainList[a])->push_back(a);
		MainList[a]++;
		MainList[a]->erase(Inside[a]);
		l=++(MainList[a]->begin());
		if(l==MainList[a]->end() && (*(MainList[a]->begin())!=0))
			{
			MainList[a]=Main.erase(MainList[a]);
			}
        MainList[a]--;
		Inside[a]=((MainList[a])->end());
		Inside[a]--;
	}
}

	}
	void reset(int a){
		c[a]=0;
		MainList[a]->erase(Inside[a]);
		l=++(MainList[a]->begin());
		if(l==MainList[a]->end() && (*(MainList[a]->begin())!=0))
			{
			MainList[a]=Main.erase(MainList[a]);
			}
		q->push_back(a);
		MainList[a]=q;
		Inside[a]=(q->end());
		Inside[a]--;
	}
	int count(int a){
		return c[a];
	}
	int findMax(){
		i=Main.end();
		i--;
        if((i)->size()-1==0){
        i--;}
		return *(i->begin());
	}
	int numMax(){
        i=Main.end();
        i--;
        if((i)->size()-1==0){
        i--;}
		return ((i)->size()-1);
	}
	void printMax(){
        i=Main.end();
        i--;
        if((i)->size()-1==0){
        i--;}
		list<int> :: iterator p=++(i->begin());
		for(;p!=(i)->end();p++){
            cout<<*p<<endl;
		}

	}
};

