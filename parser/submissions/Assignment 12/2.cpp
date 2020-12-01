#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;
//in desktop
class node{
public:
 int name;
 int t_i;
 int f;
 int goinfr,notgoinfr;
 vector<int>listf;
 vector<bool>are_frnds;
 node(){goinfr = 0;notgoinfr=0;}
           };

int main(){

queue<node*>remnodes;
queue<node*> willgo;
queue<node*> wontgo;
int N;
int t,fr,x;
cin>>N;
node* newnode;
for(int i = 0;i<N;i++){
      newnode = new node ;
       cin>>t>>fr;
       newnode->name = i;
       newnode ->t_i = t;
       newnode ->f   = fr;
       newnode->are_frnds.resize(N);
       for(int j = 0 ;j<fr ; j++){//pushing all friends into list
                    cin>>x;
                newnode->listf.push_back(x);
                newnode->are_frnds[x] = 1;
                                     }
       //put the nodes accordingly in one of 3 stacks

       if(t == 0){willgo.push(newnode);}
       else {if(t>fr){wontgo.push(newnode);}
             else {remnodes.push(newnode);}
             }

                          }

//min max computing algorithm
node* p , *q ;
int go,ntgo,rem_frnds,key,finalgo,pushed;finalgo = 0;
 while(!willgo.empty()){
          p = willgo.front();key = p->name;
          rem_frnds = remnodes.size();
          for(int i =0 ; i<rem_frnds;i++){//iterate over his friends to update going friends
                   q = remnodes.front();pushed = 0;
                   if(q->are_frnds[key]){q->goinfr = q->goinfr +1;}
                    if(q->goinfr >= q->t_i){//if he is now going
                                 willgo.push(q);
                                 pushed = 1;
                                  remnodes.pop();
                                               }

                   if(pushed == 0){remnodes.pop();
                                   remnodes.push(q);
                                    }

                                            }
         willgo.pop();
         finalgo = finalgo+1;
                         }

 //notgoing
 int finalntgo = 0;
  while(!wontgo.empty()){
          p = wontgo.front();key = p->name;
          rem_frnds = remnodes.size();
          for(int i =0 ; i<rem_frnds;i++){//iterate over his friends to update not going friends
                   q = remnodes.front();pushed = 0;
                   if(q->are_frnds[key]){q->notgoinfr = q->notgoinfr +1;}
                    if(q->t_i > q->f - q->notgoinfr){//if he is now going
                                 wontgo.push(q);
                                 pushed = 1;
                                  remnodes.pop();
                                               }

                   if(pushed == 0){remnodes.pop();
                                   remnodes.push(q);
                                    }

                                            }
         wontgo.pop();
         finalntgo = finalntgo+1;
                         }



cout<<finalgo<<" "<<N-finalntgo;
cout<<endl;
return 0 ;
                }
