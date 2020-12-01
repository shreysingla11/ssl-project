#include <iostream>
#include <vector>
#include <list>

using namespace std;

class counter{
    private:
        long n;

        vector<long> page;
        long maxAtt;
        list< list<long> > order;

        vector<list< list<long> >::iterator> point;

        vector<list<long>::iterator> position;

    public:
    counter(long n1){
        n=n1;

        maxAtt = 0;

        for(long i=0;i<n;i++){page.push_back(0);}

        list<long> l;
        for(long j=0;j<n;j++){
            l.push_back(j);
        }
        for(list<long>::iterator pt = l.begin(); pt!=l.end(); ++pt){
            position.push_back(pt);
        }

        order.push_back(l);
        list< list<long> >::iterator it = order.begin();
        point.push_back(it);
    }

    void increment(long i){
        (*point[page[i]]).remove(i);
        if((*point[page[i]]).size()==0){(*point[page[i]]).clear();}
        page[i]++;
        if(page[i]>maxAtt){
            list<long> l;
            l.push_back(i);
            order.push_back(l);
            list< list<long> >::iterator iit = order.begin();
            advance(iit,order.size()-1);
            point.push_back(iit);
            maxAtt+=1;
        }
        else{
            (*point[page[i]]).push_back(i);
        }
        list<long>::iterator iitt = (*point[page[i]]).begin();
        advance(iitt,(*point[page[i]]).size()-1);
        position[i]=iitt;
        return;
    }

    void decrement(long i){
        if(page[i]<=0){page[i]=0;}
        else{
            (*point[page[i]]).remove(i);
            if((*point[page[i]]).size()==0){(*point[page[i]]).clear();}

            page[i]--;
            (*point[page[i]]).push_back(i);
            list<long>::iterator idtt = (*point[page[i]]).begin();
            advance(idtt,(*point[page[i]]).size()-1);
            position[i]=idtt;

        }
        return;
    }

    void reset(long i){
        if(page[i]<=0){page[i]=0;}
        else{
            (*point[page[i]]).remove(i);
            if((*point[page[i]]).size()==0){(*point[page[i]]).clear();}

            (*point[0]).push_back(i);
            list<long>::iterator irtt = (*point[0]).begin();
            advance(irtt,(*point[0]).size()-1);
            position[i]=irtt;
            page[i]=0;
        }
        return;
    }

    long count(long i){
        return page[i];
    }

    long findMax(){
        long maxCount=0;
        for(long j=0;j<n;j++){
            if(page[j]>maxCount){maxCount=page[j];}
        }
        return maxCount;
    }

    long numMax(){
        long var = findMax();
        return (*point[var]).size();
    }

    void printMax(){
        long var = findMax();
        list<long>::iterator ipt2 = (*point[var]).begin();
        for (; ipt2 != (*point[var]).end(); ++ipt2)
            {cout << ' ' << *ipt2;}
        return;
    }
};

