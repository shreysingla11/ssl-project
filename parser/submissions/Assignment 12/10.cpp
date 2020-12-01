#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

struct node {
    int data;
    struct node* next;
};

int main() {
    int n;
    cin>>n;
    
    vector<int> mins(n, 0);
    vector<int> friendsLeft(n, 0);
    struct node* temp = new struct node();
    temp->data = -1;
    temp->next = NULL;
    vector<struct node*> predecs(n, temp);
    
    for(int i=0; i<n; i++) {
        int ti, ni;
        cin>>ti>>ni;
        mins[i] = ti;
        friendsLeft[i] = ni;
        for(int j=0; j<ni; j++) {
            int hi;
            cin>>hi;
            struct node* tmp = new struct node();
            tmp->data = i;
            tmp->next = predecs[hi];
            predecs[hi] = tmp;
        }
    }
    
    queue<int> finalStatuses;
    vector<bool> seenMovies(n, false);
    vector<bool> notSeenMovies(n, false);
    
    for(int i=0; i<n; i++) {
        if(mins[i]==0) {
            finalStatuses.push(i);
            seenMovies[i] = true;
        }
    }
    
    while(!finalStatuses.empty()) {
        struct node* mmm = predecs[finalStatuses.front()];
        while(mmm->data != -1) {
            if(!seenMovies[mmm->data] && !notSeenMovies[mmm->data]) {
                mins[mmm->data] = mins[mmm->data]-1;
                friendsLeft[mmm->data] = friendsLeft[mmm->data]-1;
                if(mins[mmm->data]==0) {
                    finalStatuses.push(mmm->data);
                    seenMovies[mmm->data] = true;
                }
            }
            mmm = mmm->next;
        }
        finalStatuses.pop();
    } 
    
    
    for(int i=0; i<n; i++) {
        if(mins[i]>friendsLeft[i]) {
            finalStatuses.push(i);
            notSeenMovies[i] = true;
        }
    }
    
    while(!finalStatuses.empty()) {
        struct node* mmm = predecs[finalStatuses.front()];
        while(mmm->data != -1) {
            if(!seenMovies[mmm->data] && !notSeenMovies[mmm->data]) {
                friendsLeft[mmm->data] = friendsLeft[mmm->data]-1;
                if(mins[mmm->data]>friendsLeft[mmm->data]) {
                    finalStatuses.push(mmm->data);
                    notSeenMovies[mmm->data] = true;
                }
            }
            mmm = mmm->next;
        }
        finalStatuses.pop();
    }
    
    int pakkaSeenMovies = 0;
    int pakkaNotSeenMovies = 0;
    for(int i=0; i<n; i++) {
        if(seenMovies[i]) {
            pakkaSeenMovies++;
        }
        if(notSeenMovies[i]) {
            pakkaNotSeenMovies++;
        }
    }
    
    cout << pakkaSeenMovies << " " << n - pakkaNotSeenMovies << endl;
    
	return 0;
}