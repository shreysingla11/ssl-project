#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <list>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <algorithm>
# define fr(i,n) for(int i=0;i<n;i++)
# define fr1(i,n) for(int i=1;i<=n;i++)

using namespace std;

class distinct{


public:

class node{
public:
int val;
int i;
};


static bool compare(node i,node j){
if(i.val==j.val){
if(i.i<j.i)return true;
return false;
}
else{
if(i.val<j.val)return true;
return false;
}
}



int* l;
distinct(vector <int> inp){


int size1;
//obj* a;
size1=inp.size();
l=new int [size1];
vector <node> a;
a.resize(size1);

fr(i,size1){
a[i].val=inp[i];
a[i].i=i;
}

sort(a.begin(),a.end(),distinct::compare);

/**Initializing the l array**/
l[a[0].i]=-1;
fr1(i,size1-1){
if(a[i].val==a[i-1].val){
l[a[i].i]=a[i-1].i;
}
else{
l[a[i].i]=-1;
}
}

}

int num_distinct(int i,int j){
int k=0;
for(int p=i;p<=j;p++){
if(l[p]>=i)k++;
}
return (j-i+1-k);
}

};

