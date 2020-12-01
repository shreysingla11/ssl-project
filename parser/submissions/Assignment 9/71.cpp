#include <iostream>
#include <list>
#include <queue>
#include <vector>

using namespace std;

class boolfunc{


public:
int x_num=0;
boolfunc* left;
boolfunc* right;

boolfunc(){
//node* yo=new node();
//cout<<yo->x_num;
};
~boolfunc(){};

void create(int x){
x_num=x;
left=new boolfunc;
(*left).x_num=0;
right=new boolfunc;
(*right).x_num=-1;
return;
}


bool operator==(boolfunc const & t2){
/**COMPARISION OPERATOR**/
if(x_num!=t2.x_num)return false;
if(x_num==0){if(t2.x_num==0)return true;
return false;
}
if(x_num==-1){if(t2.x_num==-1)return true;
return false;
}
return ((*left)==(*t2.left))&&((*right)==(*t2.right));
}

void operator=(boolfunc const & t2){
/**ASSIGNMENT OPERATOR**/
x_num=t2.x_num;
if(x_num==-1||x_num==0){
return;
}

if(left!=NULL)delete left;
if(right!=NULL)delete right;

left=new boolfunc;
right=new boolfunc;
(*left)=(*t2.left);
(*right)=(*t2.right);

return;
}

void operator+=(boolfunc const & t2){
/**OR Operator**/

/**BASE CASE**/

if(x_num==-1){
return;
}
if(x_num==0){
x_num=t2.x_num;
left=t2.left;
right=t2.right;
return;
}

if(t2.x_num==-1){
(*this)=t2;
return;
}
if(t2.x_num==0){
return;
}

/**CASE 1**/
if(x_num==t2.x_num){
(*left)+=(*t2.left);
(*right)+=(*t2.right);
return;
}
/**CASE 2**/
if(x_num<t2.x_num){
(*left)+=t2;
(*right)+=t2;
return;
}
/**CASE 3**/
if(x_num>t2.x_num){
//cout<<t2.left->x_num<<"PO"<<endl;
boolfunc* temp=new boolfunc;
(*temp).create(t2.x_num);
(*(*temp).left)=(*this);
(*(*temp).right)=(*this);
(*(*temp).left)+=(*(t2.left));
(*(*temp).right)+=(*(t2.right));
(*this)=(*temp);
delete temp;
return;
}

}


void creater(boolfunc * curr,list < queue<int> > & o,int x){

/**assuming x is present**/
(*curr).create(x);
list < queue<int> > l;
int i=0;
for(list < queue<int> > :: iterator it=o.begin();it!=o.end();it++){
if((*it).front()==-x){
(*it).pop();
l.push_back((*it));
o.erase(it);
it=o.begin();
for(int j=0;j<i-1;j++){
it++;
}
}
i++;
}
//list < queue<int> > r;
}


void read(){

int x,n_terms,n_lit;
queue <int>* q;
list < queue<int> > o;

cin>>n_terms;
while(n_terms--){
cin>>n_lit;
q=new queue <int>;
while(n_lit--){
cin>>x;
q->push(x);
}
o.push_back((*q));
delete q;
}
cout<<o.back().size()<<endl;
creater(this,o,1);
}




};

int main()
{

boolfunc x1;
x1.x_num=2;
x1.left=new boolfunc();
x1.left->x_num=0;
x1.right=new boolfunc();
x1.right->x_num=-1;


boolfunc x2;
x2.x_num=1;
x2.left=new boolfunc();
x2.left->x_num=0;
x2.right=new boolfunc();
x2.right->x_num=-1;
boolfunc x3;

x3.create(1);
x3=x1;
x1+=x2;
x1=(*x1.left);

x1.read();
//cout<<x1.x_num<<endl;
//cout<<x1.left->x_num<<endl;
//cout<<x1.right->x_num<<endl;
//cout<<(x1==x3)<<endl;

    return 0;

}








class node{
public:
int x_num;
/**for leaf node x_num=0 or -1**/
node* left;
node* right;

node(int num=0,node* lp=NULL,node* rp=NULL){
x_num=num;
left=lp;
right=rp;
}

};

