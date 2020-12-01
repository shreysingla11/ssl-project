#include<iostream>
#include<vector>
using namespace std;

class boolfunc{
private:
boolfunc *root;
int data;
int name;
boolfunc *left;
boolfunc *right;
public:
boolfunc(){}
~boolfunc();
boolfunc( boolfunc const &);
void operator+=(boolfunc const &);
void operator*=(boolfunc const &);
void operator~();
bool operator==(boolfunc const &);
void read();
void print();
void subst(int i, bool v);
};

void boolfunc::operator+=(boolfunc const & abcd){
if(this->name<=abcd.name){
if(abcd.name==this->name){
abcd.*left+=*(*this.left);
                          if(this->left>*(abcd.left).name){this.left=abcd.left;}
                          abcd.*right+=this->*right;
                          if(this->right>*(abcd.right).name){this.right=abcd.right;}
                          }
else{abcd.*left+=this->*root;
    if(this->root>*(abcd.left).name){this.left=abcd.left;}
     abcd.*right+=this->*root;
     if(this->root>*(abcd.right).name){this.right=abcd.right;}}
if(abcd.left)}//Write else
return;
}

void operator*=(boolfunc const &){

return;
}

void boolfunc::read(){
int a=0,b=0,c=0;
cin>>a;
vector<vector<int> > input;
vector<int> term;
for(int i=0;i<2*a;i++){
cin>>b;
term.resize(b);
for(int j=0;j<b;j++){
cin>>term[j];
}
input.push_back(term);
term.erase(term.begin(),term.end());
}
for(int i=0;;)
return;
}

int main(){
return 0;
}
