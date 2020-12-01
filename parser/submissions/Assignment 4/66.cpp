#include <iostream>
#include <vector>
#include <list>

using namespace std;

class counter{
    private :
        vector <int> v;
        list < list<int> > L;
        vector < list < list<int> > ::iterator  > vIt;
        int n;
        list<int> newList;

    public:
        counter(int N){
            n=N;
            v.assign(N,0);
            list<int> li(N);
            int j=0;
            for(list<int>::iterator i=li.begin() ; i!= li.end() ; i++ ) { *i = j; j++; }
            L.push_back(li);
            vIt.assign(N,L.begin());
        }

        void decrement(int i){
            if(i<0 && i>=n){return;}
            v[i]--;
            (*vIt[i]).remove(i);
            if((*vIt[i]).empty()){ vIt[i]=L.erase(vIt[i]); }else{}

            if(vIt[i]!=(L.begin())){
                vIt[i]--;
				if( v[(*(vIt[i])).front() ] == ( v[i] ) ){
                    (*vIt[i]).push_back(i);
                }
                else{
					newList.clear();
					newList.push_back(i);
					L.insert(++vIt[i],newList);
					vIt[i]--;
                }
            }
            else{
                newList.clear();
                newList.push_back(i);
                L.push_front(newList);
                vIt[i]= L.begin();
            }
        }

        void increment(int i){
            if(i<0 && i>=n){return;}
            v[i]++;
            (*vIt[i]).remove(i);

            if((*vIt[i]).empty()){  vIt[i]=L.erase(vIt[i]);  vIt[i]--;} else{}

            if(vIt[i]!=(--L.end())){
                vIt[i]++;
                if( v[(*(vIt[i])).front() ] == ( v[i] ) ){
                    (*vIt[i]).push_back(i);
                }
                else{
                    newList.clear();
                    newList.push_back(i);
                    L.insert((vIt[i]),newList);
                    vIt[i]--;
                }
            }
            else{
                newList.clear();
                newList.push_back(i);
                L.push_back(newList);
                vIt[i]= --L.end();
            }
        }

        void reset(int i){
            if(i<0 && i>=n){return;}
            v[i]=0;
            (*vIt[i]).remove(i);
            if((*vIt[i]).empty()){
                 vIt[i]=L.erase(vIt[i]);
            }
            else{}

            vIt[i]=L.begin();

            if(   v[(L.begin())->front()]==0 ){
                (L.front()).push_back(i);

            }
            else{
                newList.clear();
                newList.push_back(i);
                L.push_front(newList);
            }
        }

        int count(int i){
            if(i<0 && i>=n){return -1;} //out of range
            return v[i];
        }

        int findMax(){
            return v[(L.back()).front()];
        }

        int numMax(){
            return (L.back()).size();
        }

        void printMax(){
            for(list<int>::iterator i= (L.back()).begin() ; i != (L.back()).end(); i++ ){
                cout<< *i <<endl;
            }
        }

};
