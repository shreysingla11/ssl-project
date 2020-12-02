#include<iostream>
#include<vector>
using namespace std;

class distinct{
int *l;
vector<int> arr;
public:
distinct(vector<int> a){
int n=a.size();
arr.resize(n);
arr=a;
l= new int[n];
    for (int i=0;i<n;i++){
        l[i]=-1;
        for(int j=0;j<i;j++){
            if(a[i]==a[j]){
                l[i]=j;
            }
            else{}
        }
    }
}
int num_distinct(int i,int j){
    int k=0;
    if(j<arr.size()&&i>=0){
    if(i!=j){
    for(int m=i;m<j+1;m++){
        if(l[m]>=i){
        k++;
        }
    }
    return -i+j-k+1;}
    else{return 1;}
    }
    else{return -1;}
}
};

