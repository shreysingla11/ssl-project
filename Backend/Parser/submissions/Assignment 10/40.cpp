#include<iostream>
#include<algorithm>
#include<vector>
#include <cmath>
using namespace std;

class input1{
public:
    int value;
    int index;
};

bool cmp(input1 a,input1 b){
    if(a.value==b.value){return a.index < b.index;}
    else{return a.value < b.value;}
}

class distinct{
public:
    vector<input1> I;
    vector<int> L;

    distinct(vector<int> &A){
        int l = A.size();
        I.resize(l);
        L.resize(l,0);
        for(int i=0;i<l;i++){
            input1 temp;
            temp.index = i;
            temp.value = A[i];
            I[i] = temp;
        }
        sort(I.begin(),I.end(),cmp);
        L[0] = -1;
        for(int i=1;i<l;i++){
            if(I[i-1].value==I[i].value){
                L[I[i].index] = I[i-1].index;
            }
            else{L[I[i].index] = -1;}
        }




    }

    int num_distinct(int i,int j){
        int l = L.size();
        int count1 = 0;
        for(int k=i;k<j;k++){
            if(L[k]==-1){count1++;}
        }
        return count1;
    }

};
