# include <iostream>
#include <string>

using namespace std;

//continuation after first match is found
void match(int i1, int i2, int n, string S, int &w, int &val){
    int i=i1;
    int j=i2;
    for(;(i<i2);i++,j++){
        if(S[i]!=S[j] || j==n){val=-1;w=j;return;}
    }
    val=1;return;
};

//returns the position of substring of size l which forms a square
void scanfirst(int s0, int s1, int l, int n, int &c, string S){
    int val = 0;
    int w = 0;
    if((s1-s0)>=((2*l)+1) || s1>(n-1)){
        return;
    }
    if(S[s0]==S[s1]){
            match(s0,s1,n,S,w,val);
            if(val==1){
                c=-10;
                cout<<(s1-s0)<<" "<<s0<<endl;
                return;
            }else{
                scanfirst(s0,w,l,n,c,S);
                //using w instead of s1 thus making this O(n)
                //no need to search for elements alredy matched
            }
    }else{
        scanfirst(s0,s1+1,l,n,c,S);
    }
    return;
};

//increases the l to 2l
void ofSize(int l, int n, int &c, string S){
    if(l>=((n/2)+1)){cout<<"0 0"<<endl;return;}
    for(int i=0;i<n-l;i++){
        scanfirst(i,l+i,l,n,c,S);
        if(c==-10){return;}
    }
    ofSize((2*l),n,c,S);
    return;
};

int main(){

    int c=0;
    string inp = "";
    getline(cin, inp);
    int n = inp.size();

    ofSize(1,n,c,inp);

return 0;
}

