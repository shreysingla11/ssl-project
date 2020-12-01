#include <iostream>
#include <string>
using namespace std;
bool kthbox(string s,int n,int l,int k){
    bool b=false;
    int i=k*l;int j=k*l+l;int p,q;
    while(j<=3*l-2+k*l&&!b&&j<n){

        if(s[i]!=s[j]){j++;}
        else{
            p=i;q=j;
            while(p < (k*l+l) && p < n && q<n){
                if(s[p]!=s[q]){
                break;
                p=i;

                            }
                else{
                    p++;
                    q++;

                    if(p==k*l+l){b=true;}
                    }
            }
        }
    }
    if(b==false){return false;}
    else{
        int lol=l;
        while(s[p]==s[q]){p++;q++;lol++;}
        p=i-1;q=j-1;
        while(s[p]==s[q]){p--;q--;lol++;}
        cout<<lol<<' '<<p+1;
        return true;
    }
}
int main(){
    string s;
    cin>>s;
    int n;
    n=s.length();
    kthbox(s,n,2,1);
    return 0;
}
