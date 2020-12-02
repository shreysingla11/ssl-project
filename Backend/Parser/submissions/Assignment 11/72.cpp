#include<iostream>
#include<bitset>
#include <unordered_map>

using namespace std;

int main() {

    unordered_map<bitset<45>,int> h;

    bitset<45>repr;
    bitset<45>err;

    bitset<5>binrep;

    int i,j,k,l,m;

    for(i=0; i<26; i++) {
        binrep=bitset<5>(i);
        for(j=0;j<5;j++) {
            for(k=0;k<9;k++) {
                repr[j*9+k]=binrep[j];
            }
        }

    h[repr]=i;

        for(j=0;j<45;j++) {
            err=repr;
            err.flip(j);
            h[err]=i;
            for(k=j+1;k<45;k++) {
                err.flip(k);
                h[err]=i;
                for(l=k+1;l<45;l++) {
                    err.flip(l);
                    h[err]=i;
                    for(m=l+1;m<45;m++) {
                        err.flip(m);
                        h[err]=i;
                        err.flip(m);
                    }
                    err.flip(l);
                }
                err.flip(k);
            }
            err.flip(j);
        }
    }

    int n;
    cin>>n;

    long long int temp;
    char d;

    for(i=0;i<n;i++){
        cin>>temp;

        bitset<45> x=bitset<45>(temp);

        if(h.count(x)==0){
            cout<<"?";
        }

        else {
            d=h[x]+97;
            cout<<d;
        }
    }

    return 0;
}
