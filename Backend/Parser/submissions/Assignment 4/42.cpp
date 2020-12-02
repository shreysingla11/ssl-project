//counter(n) creates n objects
//for ith object; numbering starts from i=0
#include<iostream>
#include<list>
#include<vector>
using namespace std;

class webpage
{
public:
	list<list<int> >::iterator it1;
	list<int>::iterator it2;
};

class counter
{
private:
	int n;
	list<list<int> > L;
	vector<webpage> v;
	list<list<int> >::iterator it0;//iterator for list of count = 0;zeroth list isn't being deleted
public:
	counter(int m){
		n = m;
		list<int> ltemp;
		ltemp.push_back(0);
		for(int i=0;i<n;i++){
			ltemp.push_back(i);
		}
		L.push_back(ltemp);
		list<list<int> >::iterator it = L.begin();
		list<int>::iterator it3 = ++(L.front().begin());
		for(int i=0;i<n;i++,it3++){
            webpage temp;
			temp.it1 = it;
			temp.it2 = it3;
			v.push_back(temp);
		}
		it0 = v[0].it1;
	}
	void increment(int i){
		list<list<int> >::iterator it3 = v[i].it1;
		list<list<int> >::iterator it5 = it3;
		list<int>::iterator it4 = v[i].it2;
		int count1 = (*it3).front();
		it5++;
		if(it3 == (--(L.end()))){
            list<int> ltemp;
            ltemp.push_back(count1+1);
            ltemp.push_back(i);
			L.push_back(ltemp);
		}
		else{
            if(((*(it5)).front()) != (count1+1)){
                list<int> ltemp;
                ltemp.push_back(count1+1);
                ltemp.push_back(i);
                L.insert(it5,ltemp);
            }
            else{
                (*(++it3)).push_back(i);
                it3--;
            }
		}
		v[i].it1 = (++it3);
		v[i].it2 = --(it3->end());
		it3--;
		list<int>::iterator it6;
		it6 = (*it3).begin();
		it6++;
		if(it6 == (--((*it3).end()))){
            if((*it3).front()!=0)
                L.erase(it3);
        }
		else{(*it3).erase(it4);}
		return;
	}
	void decrement(int i){
		list<list<int> >::iterator it1 = v[i].it1;
		list<int>::iterator it2 = v[i].it2;
        list<list<int> >::iterator it5 = it1;
		int count = (*it1).front();
		if((*(--it5)).front() != count-1){
			list<int> ltemp;
			ltemp.push_back((*it1).front()-1);
			ltemp.push_back(i);
			L.insert(it1,ltemp);
			v[i].it1 = (--it1);
			v[i].it2 = (--(*it1).end());
		}
		else{
			(*(--it1)).push_back(i);
			v[i].it1 = it1;
			v[i].it2 = (--(*it1).end());
		}
		//it1 points to 1 back
		it1++;
		list<int>::iterator it6;
		it6 = (*it1).begin();
		it6++;
		if(it6 == (--((*it1).end()))){
             if(it1->front()!=0){
                L.erase(it1);
            }
        }
		else{(*it1).erase(it2);}
		return;
	}
	void reset(int i){
		list<list<int> >::iterator it1 = v[i].it1;
		list<int>::iterator it2 = v[i].it2;
		if((*it1).front() == 0){return;}//count already = 0
        list<int>::iterator it6;
        it6 = (*it1).begin();
        it6++;
        if(it6 == (--((*it1).end()))){L.erase(it1);}
        else{(*it1).erase(it2);}
        (*it0).push_back(i);
        v[i].it1 = it0;
        v[i].it2 = --it0->end();
		return;
	}

	int count(int i){
		return (*(v[i].it1)).front();
	}

	int findMax(){
		list<list<int> >::iterator it1 = (--L.end());
		return (*it1).front();
	}

	int numMax(){
		return ((--L.end())->size()) -1;
	}

	void printMax(){
		list<list<int> >::iterator it1 = --(L.end());
		for(list<int>::iterator it2 = (++((*it1).begin()));it2 != (*it1).end();it2++){
			cout<<(*it2)<<endl;
		}
		return;
	}
};
