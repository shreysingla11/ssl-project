#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class node
{
public:
int number;
int nf;
int t_i;
int nf_going;
int nf_notgoing;
int prenum;
bool visited;
node(){
nf_going=0;
nf_notgoing=0;
prenum=0;
visited=false;
}
vector<int> pred;
vector<int> succ;
};

int main()
{
int n,a,b,t;
int min,max;
cin>>n;
vector<node> users(n);
queue<int> go;
queue<int> ngo;
min=0;
max=n;
int i=0;
while(i<n){
cin>>a>>b;
users[i].number=i;
users[i].t_i=a;
users[i].nf=b;
users[i].succ.resize(b);
if (a > b && !users[i].visited){
	ngo.push(i);
	users[i].visited=true;
	max--;
}
else if (a==0 && !users[i].visited){
	go.push(i);
	users[i].visited=true;
	min++;
}
int j=0;
while(j<b){

	cin>>t;
	users[i].succ[j]=t;
	users[t].pred.push_back(i);
	users[t].prenum++;
	j++;
}
++i;
}
while(!go.empty()){
t=go.front();
go.pop();
for (int i=0 ; i<users[t].prenum ; ++i){
	users[users[t].pred[i]].nf_going++;
	if (users[users[t].pred[i]].nf_going >= users[users[t].pred[i]].t_i){
		if ( !users[users[t].pred[i]].visited){
			go.push(users[t].pred[i]);
			users[users[t].pred[i]].visited=true;
			min++;
		}
	}
}
}
while(!ngo.empty()){
t=ngo.front();
ngo.pop();
for (int i=0 ; i<users[t].prenum ; ++i){
	users[users[t].pred[i]].nf_notgoing++;
	if (users[users[t].pred[i]].nf_notgoing > users[users[t].pred[i]].nf - users[users[t].pred[i]].t_i){
		if (!users[users[t].pred[i]].visited){
			ngo.push(users[t].pred[i]);
			users[users[t].pred[i]].visited=true;
			max--;
		}
	}
}
}
cout<<min<<" "<<max<<endl;
return 0;
}
