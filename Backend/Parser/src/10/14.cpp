
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class distinct
{
public:

class node{
public:
int index;
int value;
node(){
index=-1;
value=0;
}
};

static bool func(node i,node j){
if(i.value==j.value){
if(i.index<j.index){
return true;
}
else{
return false;
}
}
else{
if(i.value<j.value){
return true;
}
else{
return false;
}
}
};
    vector <int> A;///stores the array values
    vector <node> V;
    vector <int> l;
   // list < vector <int> > L;
   //vector <int> l1;
   //int n;
    distinct(vector <int> B)
    {
    //n=B.size();
///constructor function
        A.resize(B.size());
         V.resize(B.size());
        for(int i=0; i<A.size(); i++)
        {
            A[i]=B[i];
            V[i].index = i;
            V[i].value = B[i];
        };
        sort(V.begin(),V.end(),distinct::func);
        l.resize(V.size());
        l[0]=-1;

        for(int i=1;i<V.size();i++){
        if(V[i-1].value==V[i].value){
        l[V[i].index]= V[i-1].index;

        }
        else{
        l[V[i].index]=-1;
        }

        }
       /* for(int i=0;i<l.size();i++){
        cout<<l[i]<<" ";
        }
        cout<<endl;*/

    };
int num_distinct(int i, int j){
int k=0;
for(int p=i;p<=j;p++)
{
if(l[p]>=i){
k++;
}
}
return (j-i+1-k);


};

};
/*
int main()
{
    vector <int> test(8);
    test[0]=1;
    test[1]=2;
    test[2]=1;
    test[3]=3;
    test[4]=2;
    test[5]=1;
    test[6]=1;
    test[7]=3;
    distinct D=distinct(test);
    int n;
    cout<<"give n"<<endl;
    cin>>n;

int i;
int j;
for(int k=0;k<n;k++){
cout<<"give i,j"<<endl;
cin>>i>>j;
cout<<"ans: "<<D.num_distinct(i,j)<<endl;
}

//cout<<D.A[7]<<endl;
    return 0;
}*/
