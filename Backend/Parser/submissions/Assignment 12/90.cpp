#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class node {
    public:
        int i;
        int t_i;
        int n_i;
        int frnds_going;
        int* frnds;
        vector<int> mates;
        bool pushed;
};


int main() {
    int n; cin>>n;
    node* person = new node[n];
    // taking inpput and storing into array of nodes
    for(int i=0; i<n; i++) {
        person[i].i=i;
        cin>>person[i].t_i;
        cin>>person[i].n_i;
        int* tempfrnds = new int[person[i].n_i];
        for(int j=0; j<person[i].n_i; j++) {
            cin>>tempfrnds[j];
        }
        person[i].frnds=tempfrnds;
        person[i].frnds_going=0;
        person[i].pushed=false;
    }
    // inserting mates i.e predecesors
    for(int i=0; i<n; i++) {
        for(int j=0; j<person[i].n_i; j++) {
            person[(person[i].frnds[j])].mates.push_back(i);
        }
    }
    // adding elements into stack
    stack<int> minstack;
    for(int i=0; i<n; i++) {
        if( person[i].t_i==0 ) {
            minstack.push(i);
        }
    }
    stack<int> maxstack;
    for(int i=0; i<n; i++) {
        if( person[i].t_i>person[i].n_i ) {
            maxstack.push(i);
        }
    }

    int i,minval=0;
    while ( !minstack.empty() ) {
        i = minstack.top();                              //cout<<"stack element inspected and removed : "<<i<<endl;
        minstack.pop();
        person[i].pushed=true;minval++;
        if( person[i].t_i<=person[i].frnds_going ) {    //cout<<i<<"t_1,frnds_going = "<<person[i].t_i<<" , "<<person[i].frnds_going<<endl;
            for (vector<int>::iterator iter = person[i].mates.begin(); iter != person[i].mates.end(); ++iter) {
                if( person[*iter].frnds_going<person[*iter].n_i ) {
                    person[*iter].frnds_going++;
                    //cout<<*iter<<" "<<person[*iter].frnds_going<<endl;
                }
                if( person[*iter].frnds_going>=person[*iter].t_i && !person[*iter].pushed ) {
                    minstack.push(*iter);
                    //cout<<"push : "<<*iter<<endl;
                }
            }
        }
    }
    //resetting pushed values to false
    for(int i=0; i<n; i++) {
        person[i].pushed=false;
    }

    int maxval=0;
    while ( !maxstack.empty() ) {
        i = maxstack.top();                              //cout<<"stack element inspected and removed : "<<i<<endl;
        maxstack.pop();
        person[i].pushed=true;maxval++;//cout<<maxval<<" "<<i<<endl;
        if( person[i].t_i>person[i].n_i ) {    //cout<<i<<"t_1,frnds_going = "<<person[i].t_i<<" , "<<person[i].frnds_going<<endl;
            for (vector<int>::iterator iter = person[i].mates.begin(); iter != person[i].mates.end(); ++iter) {
                //if( person[*iter].n_i > 0 ) {
                    person[*iter].n_i--;
                    //*cout<<*iter<<" "<<person[*iter].frnds_going<<endl;
                //}
                if( person[*iter].t_i>person[*iter].n_i && !person[*iter].pushed ) {
                    maxstack.push(*iter);//cout<<*iter<<endl;
                    //cout<<"push : "<<*iter<<endl;
                }
            }
        }
    }
    cout<<minval<<" "<<(n-maxval)<<endl;
    return 0;
}

