#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int main(){
    map< string, int> A;
    map< int, set< string > > B;

    string operation;
    string accName;
    int amount;
    int minRange;
    int maxRange;
    int illegal=0;
    map< int, set< string > >::iterator minIterator;
    map< int, set< string > >::iterator maxIterator;
    while(true){
        cin>>operation;
        if(operation=="O"){
            cin>> accName;

            if ( A.find(accName) == A.end() ) {
                A[accName]=0;
                B[0].insert(accName);
            }
            else {
                illegal++;
            }
        }

        if(operation=="C"){
            cin>> accName;

            if ( A.find(accName) == A.end() ) {
                illegal++;
            }
            else {
                if(A[accName]==0){
                    B[ A[accName] ].erase(accName);
                    A.erase(accName);
                }
                else{
                    illegal++;
                }
            }
        }

        if(operation=="D"){
            cin>> accName;
            cin>> amount;
            if ( A.find(accName) == A.end() ) {
                illegal++;
            }
            else {
                B[ A[accName] ].erase(accName);
                A[accName]=A[accName] + amount;
                B[ A[accName] ].insert(accName);
            }
        }

        if(operation=="W"){
            cin>> accName;
            cin>> amount;

            if ( A.find(accName) == A.end() ) {
                illegal++;
            }
            else {
                if(amount<= A[accName]){
                    B[ A[accName] ].erase(accName);
                    A[accName]=A[accName]- amount;
                    B[ A[accName] ].insert(accName);
                }
                else{
                    illegal++;
                }
            }
        }

        if(operation=="P"){
            cin>> minRange;
            cin>>maxRange;
            minIterator=B.end();
            for( map< int, set<string> >::iterator it=B.begin(); it!= B.end(); it++ ){
                if(it->first >= minRange){minIterator=it; break;}
            }
            maxIterator=B.end();
            for( map< int, set<string> >::iterator it=B.begin(); it!= B.end(); it++ ){
                if(it->first > maxRange){ maxIterator=it; break;}
            }

            for( map< int, set<string> >::iterator it=minIterator; it!= maxIterator; it++ ){
                if(!B[it-> first].empty()){
                    cout<< it-> first << " ";
                    for(set<string>::iterator iter= B[it->first].begin(); iter!=B[it->first].end(); ++iter) {
                        cout<< *iter << " ";
                    }
                    cout<<endl;
                }
            }
        }

        if(operation=="E"){
            break;
        }

    }

    cout<<illegal;
return 0;}
