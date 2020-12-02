#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <queue>
#include <cstdio>
using namespace std;

class node {

public:

int t_i;
int n_i;
int is_going;

node(int t, int n) {
    t_i = t;
    n_i = n;
    is_going = -1;
}

node () {}

};

int main() {

int number,going,notgoing;
going = 0;
notgoing = 0;
scanf("%d",&number);
vector <node> PersonList;
vector < vector<int> > Predessor(number);

queue <int> Going;
queue <int> NotGoing;

for (int i=0;i<number;i++) {
    int t,n;
    scanf("%d",&t);
    scanf("%d",&n);

    PersonList.push_back(node(t,n));

    if(t==0) {
        PersonList[i].is_going = 1;
        Going.push(i);
    }
    else if(t>n) {
        PersonList[i].is_going = 0;
        NotGoing.push(i);
    }

    while(n != 0) {
        int succ;
        scanf("%d",&succ);
        Predessor[succ].push_back(i);
        n--;
    }
}

/*for(int i=0;i<number;i++) {
    for (vector<int>::iterator it = Predessor[i].begin() ; it != Predessor[i].end(); ++it) {
        cout<<*it<<' ';
    }
    cout<<endl;
}*/

while (!Going.empty()) {
    vector<int>::iterator it = Predessor[Going.front()].begin();
    for (;it != Predessor[Going.front()].end(); ++it) {
    if(PersonList[(*it)].is_going == -1) {
        PersonList[ (*it) ].t_i--;
        PersonList[ (*it) ].n_i--;
        if (PersonList[ (*it) ].t_i == 0) {
            PersonList[ (*it) ].is_going = 1;
            Going.push(*it);
        }
        }
    }
    Going.pop();
    going++;
}

while (!NotGoing.empty()) {
    vector<int>::iterator it = Predessor[NotGoing.front()].begin();
    while(it != Predessor[NotGoing.front()].end())
    {
    if(PersonList[(*it)].is_going == -1) {
        PersonList[ (*it) ].n_i--;
        if (PersonList[ (*it) ].t_i > PersonList[ (*it) ].n_i) {
            PersonList[ (*it) ].is_going = 0;
            NotGoing.push(*it);
        }
        }
    ++it;
    }
    NotGoing.pop();
    notgoing++;
}

printf("%d %d",going,number - notgoing);

return 0;
}
