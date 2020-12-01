#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <list>
#include <string>
#include <map>
//#include <unordered_map>
#include <queue>
#include <set>
#include <stack>
#include <algorithm>
# define fr(i,n) for(int i=0;i<n;i++)
# define fr1(i,n) for(int i=1;i<=n;i++)
# define ll long long int
# define frl(i,n) for(ll i=0;i<n;i++)
# define frl1(i,n) for(ll i=1;i<=n;i++)

using namespace std;

class node{
public:
bool in_q;
bool in_r;
ll th,def_go,def_no;
ll n_frs;
queue <node*> prs;

};


int main(){
/**DECLARATIONS**/
ll n,th,n_frs,fr,ans,c_max_a;
node* ppl;
node* curr;
node* pred;
queue <node*> q;
queue <node*> r;
/**INITIALIZATIONS**/
ans=0;
c_max_a=0;
cin>>n;
ppl=new node[n];
frl(i,n){
ppl[i].def_go=0;
ppl[i].def_no=0;
ppl[i].in_q=false;
ppl[i].in_r=false;
cin>>th;
ppl[i].th=th;
cin>>n_frs;
ppl[i].n_frs=n_frs;
if(th==0){
q.push(&ppl[i]);
ppl[i].in_q=true;
ans++;
}
if(th>n_frs){
r.push(&ppl[i]);
ppl[i].in_r=true;
c_max_a++;
}
frl(j,n_frs){
cin>>fr;
ppl[fr].prs.push(&ppl[i]);
}
}

/**FINDING MIN **/
while(!q.empty()){
curr=q.front();
q.pop();
while(!curr->prs.empty()){
pred=curr->prs.front();
curr->prs.pop();
pred->def_go++;
if((!pred->in_q)&&(pred->def_go>=pred->th)){
q.push(pred);
pred->in_q=true;
ans++;
}
}
}

/**FINDING MAX **/
while(!r.empty()){
curr=r.front();
r.pop();
while(!curr->prs.empty()){
pred=curr->prs.front();
curr->prs.pop();
pred->def_no++;
if((!pred->in_r)&&((pred->n_frs)-(pred->def_no))<pred->th){
r.push(pred);
pred->in_r=true;
c_max_a++;
}
}
}

cout<<ans<<" "<<n-c_max_a<<endl;

return 0;
}

