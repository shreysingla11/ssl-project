#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct t{
    int val;
    int ind;
};
bool CompareBy(const t&a,const t&b){
    return a.val<b.val;
}

class distinct{

public:
    vector<t> a;
    vector<int> l;


    distinct(vector<int> in){
        t b;
        for(int i=0;i<in.size();i++){
            b.val=in[i];
            b.ind=i;
            a.push_back(b);
        }
        sort(a.begin(),a.end(),CompareBy);
        int n=a.size();

        l.resize(n);

        for(int i=0;i<n;i++){
            if(i==0) l[a[i].ind]=-1;
            else{
                if(a[i].val==a[i-1].val) {
                    l[a[i].ind]=a[i-1].ind;
                }
                else{
                    l[a[i].ind]=-1;
                }
            }
        }
    }
    int num_distinct(int i,int j){
        int co=0;
        for(int k=i+1;k<=j;k++){
            if(l[k]>i || l[k]==i) co++;
        }
        int dist=-i+j-co+1;
        cout<<dist<<endl;
    }
};

