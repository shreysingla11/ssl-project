#include<iostream>
#include<vector>
#include<list>
using namespace std;

int main(){
//Initialization
int going=0,ngoing=0;
vector<vector<int> > members;
int no_of_members=0;
cin>>no_of_members;
members.resize(no_of_members);
vector<int> threshold;
threshold.resize(no_of_members);
vector<int> no_of_friends,what;
no_of_friends.resize(no_of_members);
what.resize(no_of_members);
vector<vector<int> > iskofriend;
iskofriend.resize(no_of_members);
for(int i=0,k=0;i<no_of_members;i++){
cin>>threshold[i];
cin>>k;
vector<int> friends;
friends.resize(k);
for(int j=0;j<k;j++){
int a = 0;
cin>>a;
friends[j]=a;
iskofriend[a].push_back(k);
}

members.push_back(friends);
no_of_friends[i]=friends.size();
cout<<"Friends values: "<<no_of_friends[i]<<endl;

cout<<"Size: "<<members[i].size()<<endl;
}
cout<<"no3"<<endl;
list<int> ligo,lingo,checker;

for(int i=0;i<no_of_members;i++){

what[i]=0;
cout<<"threshold: "<<threshold[i]<<endl;
}
//The main algorithm starts here
for(int i=0;i<no_of_members;i++){
if(threshold[i]==0){ligo.push_back(i);
                    going++;
                    cout<<"going: "<<i<<endl;
                    what[i]=1;}
else if(threshold[i]>no_of_friends[i]){lingo.push_back(i);
                                        cout<<"No of friends: "<<members[i].size()<<endl;
                                        cout<<"Not going: "<<i<<endl;
                                        ngoing++;
                                        what[i]=-1;}
}
while((ligo.size()!=0)||(lingo.size()!=0)){
while(ligo.size()!=0){
cout<<"no7"<<endl;
for(int j=0;j<iskofriend[ligo.front()].size();j++){
cout<<ligo.front()<<endl;

if(threshold[iskofriend[ligo.front()][j]]!=0){threshold[iskofriend[ligo.front()][j]]--;
checker.push_back(iskofriend[ligo.front()][j]);}
}
ligo.pop_front();
}
cout<<"no8"<<endl;
while(lingo.size()!=0){
for(int j=0;j<iskofriend[lingo.front()].size();j++){
cout<<lingo.front()<<endl;

{no_of_friends[iskofriend[lingo.front()][j]]--;
checker.push_back(iskofriend[lingo.front()][j]);}
}
lingo.pop_front();
}

for(int k=0;k<checker.size();k++){
if(threshold[k]==0){ligo.push_back(k);
                    going++;
                    what[k]=1;}
else if(threshold[k]>no_of_friends[k]){lingo.push_back(k);
                                        ngoing++;
                                        cout<<"Not going: "<<k<<" "<<endl;
                                        what[k]=-1;}
else{ngoing++;}
}
checker.erase(checker.begin(),checker.end());
}
int maximum=0,minimum=0;
cout<<"Not going: "<<ngoing<<endl;
minimum=going;
maximum=no_of_members-ngoing;
cout<<"Maximum: "<<maximum<<" Minimum: "<<minimum<<endl;
}
