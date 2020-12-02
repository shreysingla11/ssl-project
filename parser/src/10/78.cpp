#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

class distinct{
  public:
    static vector<int> l;
    int n;
    class node{
       public:
        vector<int> a;
        vector<int> b;
        node(){
            a.resize(l.size());
            b.resize(l.size());
        }
    };
    vector<node> tree;
    distinct(){;}
    distinct(vector<int> v){
        n=v.size();
        for(int p=0;p<n;p++){
            l.push_back(-1);
            for(int q=0;q<p;q++){
                if(v[p]==v[q]){l[p]=q;}
            }
        }

        node temp;
        int b1,b2,b3;
        int k,i=1;
        int ta=-1,tb=-1;
        while(pow(2,i)<=n){
            ta=0;tb=-1;
            k = n/pow(2,i-1);
            b1 = k*n/pow(2,i-1);
            b3 = b1 + n/pow(2,i);
            b2 = (k+1)*n/pow(2,i-1);
            if(l[0]>=b1&&l[0]<b2){
                    if(l[0]>=b3){
                        temp.a[0] = 1;
                    }
                    else{
                        temp.a[0] = 0;
                    }
                }
            for(int p=1;p<n;p++){
                if(l[p]>=b1&&l[p]<b2){
                    if(l[p]>=b3){
                        temp.a[p] = temp.a[p-1]+1;
                    }
                    else{
                        temp.a[p] = temp.a[p-1];
                    }
                }
            }
            temp.b[0] = -1;
            if(l[0]>=b3&&l[0]<b2){tb = 0;}
            else if(l[0]>=b1&&l[0]<b3){ta = 0;}
            for(int p=1;p<n;p++){
                if(l[p]>=b3&&l[p]<b2){
                    temp.b[p] = ta;
                    tb = p;
                }
                else{
                    temp.b[p] = tb;
                    if(l[p]>=b1&&l[p]<b3){
                        ta = p;
                    }
                }
            }
            tree.push_back(temp);
            i=i+1;
        }
        return;
    }
    int getk(int tt, int ti, int tj){
            int k=0;
            if(ti<=n/pow(2,tt)){
                k = k+tree[tt].a[tj];
            }
            if(ti<n/pow(2,tt)){
                k = k + getk(tt+1,ti,n/pow(2,tt)-1);
            }
            else if(ti>n/pow(2,tt)){
                k = k + getk(tt+1,ti,n/pow(2,tt-1)-1);
            }
            return k;
        }
    int num_distinct(int i, int j){
        int k=0;
        int t=0;
        if(i<=n/2){
                k = k+tree[0].a[j];
            }
        //for(int t=1;t<tree.size();t++){
            if(i<n/2){
                k = k + getk(t+1,i,n/2-1);
            }
            else if(i>n/2){
                k = k + getk(t+1,i,n-1);
            }
        //}
    }

};

