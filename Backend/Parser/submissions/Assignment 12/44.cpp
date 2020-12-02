#include<iostream>
#include<vector>
#include<stdio.h>
#include<list>
#include<string>
#include<sstream>
//program to find min and max possible people going to the movie
using namespace std;
int main(){
	int n;
	//cout<<"Enter total no of people \n";
	cin>>n;
	vector<int> definite_rsvp;
	vector<int> definite_not_rsvp;
	vector<int> threshold;
	vector<int> friends_with[n]; //outgoing relations //not needed to be present
	vector<int> friends_of[n]; //incoming relations
	vector<int> friends_rsvp;
	vector<int> indefinite_friends_rsvp;
	vector<int> n_friends_with;
	vector<int> n_friends_of;
	int definite_rsvp_n,definite_not_rsvp_n,indefinite_rsvp_n;
	definite_rsvp_n = 0;
	definite_not_rsvp_n = 0;
	indefinite_rsvp_n = 0;
	string input;
	//cout<<"Enter details of i'th person \n";;
    cin.ignore();
    for(int i=0;i<n;i++){
        n_friends_of.push_back(0);
    }
	for(int i=0;i<n;i++){
        getline(cin, input);
        //cout<<input;
        stringstream stream(input);
        int p,q;
        stream >> p;
        threshold.push_back(p);
        if(threshold[i] == 0){
            definite_rsvp.push_back(i);
            definite_rsvp_n+=1;
        }
        stream >> p;
        n_friends_with.push_back(p);
        indefinite_friends_rsvp.push_back(p);
        if(n_friends_with[i]<threshold[i]){
            definite_not_rsvp.push_back(i);
            definite_not_rsvp_n+=1;
        }
        for(int j=0;j<p;j++){
            stream >> q;
            friends_with[i].push_back(q);
            friends_of[q].push_back(i);
            n_friends_of[q]+=1;
        }
        friends_rsvp.push_back(0);
	}
    int max_rsvp,id,old;
    max_rsvp=0;
    bool check;
    //recursing through the definite_rsvp friends to fish for others
    for(int i=0;i<definite_rsvp_n;i++){
        for(int j=0;j<n_friends_of[definite_rsvp[i]];j++){
            id = friends_of[definite_rsvp[i]][j];
            if(friends_rsvp[id]>=threshold[id]){
                check = false;
            }
            else{
                check = true;
            }
            friends_rsvp[id]+=1;
            if(friends_rsvp[id]>=threshold[id] && check){
                definite_rsvp.push_back(id);
                definite_rsvp_n+=1;
            }
        }
    }
    //min_rsvp == definite_rsvp
    for(int i=0;i<definite_not_rsvp_n;i++){
        for(int j=0;j<n_friends_of[definite_not_rsvp[i]];j++){
            id = friends_of[definite_not_rsvp[i]][j];
            if(indefinite_friends_rsvp[id]>=threshold[id]){
                check = true;
            }
            else{
                check = false;
            }
            indefinite_friends_rsvp[id]-=1;
            if(indefinite_friends_rsvp[id]<threshold[id] && check){
                definite_not_rsvp.push_back(id);
                definite_not_rsvp_n+=1;
            }
        }
    }
    indefinite_rsvp_n = n-definite_not_rsvp_n;
    cout<<definite_rsvp_n<<" "<<indefinite_rsvp_n<<"\n";
	return 1;
}
