#include <iostream>
#include <vector>
#include <list>
using namespace std;

class counter {
private:
    list<list<int> > l;
    list<int> l_count;
    int n;
    vector<int> v_count;
    vector<list<list<int> >::iterator> v_iterator;

    counter(int a){
        n=a;
        l_count.push_back(0);
    }

public:
    void increment(int i){
        v_count[i]++;
        list<list<int> >::iterator it1=l.begin();
        list<int>::iterator it2;
        for(it2=l_count.begin(); it2!=l_count.end(); it1++,it2++){
            if(*it2==v_count[i]-1){
                (*it1).erase(v_iterator[i]);
                if(*it1.size()==0){l.erase(it1);}
            };
            if(*it2==v_count[i]){break;};
        }
        if(it2==l_count.end()){
            l_count.push_back(v_count[i]);
            list<int> temp;
            temp.push_back(i);
            l.push_back(temp);
            temp.pop_back();
            v_iterator[i]=(l.back()).end()-1;
        }
        else {
            (*it1).pushback(i);
            v_iterator(i)=(*it1).end()-1;
        }
        return;
    }

    void decrement(int i){
        v_count(i)--;
        list<list<int> >::iterator it1=l.back();
        list<int>::iterator it2;
        for(it2=l_count.end()-1; it2>=l_count.begin(); it1--,it2--;){
            if(*it2==v_count(i)+1){
                (*it1).erase(v_iterator(i));
                if(*it1.size()==0){l.erase(it1);}
                };
            if(*it2==v_count(i)){break;};
        }
        (*it1).pushback(i);
        v_iterator(i)=(*it1).end()-1;
        return;
    }

    void reset(int i){
        v_count(i)=0;
        if(l_count.front()==0){
            (l.front()).push_back(i);
            v_iterator(i)=(l.front()).end()-1;
        }
    }

    int count(int i){
        return v_count(i);
    }

    int findMax(){
        return l_count.back();
    }

    int numMax(){
        return (l.back()).size();
    }

    printMax(){
        list<int>::iterator it;
        for(it=(l.back()).begin(); it!=(l.back()).end(); it++;){
            cout<<*it<<endl;
        }
        return;
    }
};






