#include<iostream>
#include<bitset>
#include <unordered_map>
#include<fstream>
using namespace std;


int main(){
unordered_map<bitset<45>,int>mymap;
bitset<45>fbin;
bitset<45>err;
bitset<5>binary;
int i,j,k,l,m;
for( i=0;i<26;i++){
    binary=bitset<5>(i);
    for(j=0;j<5;j++){
        for(k=0;k<9;k++){
            fbin[j*9+k]=binary[j];
        }
    }
    mymap[fbin]=i;
    for(j=0;j<45;j++){
        err=fbin;
        err.flip(j);
        mymap[err]=i;
        for(k=j+1;k<45;k++){
            err.flip(k);
            mymap[err]=i;
            for(l=k+1;l<45;l++){
                err.flip(l);
                mymap[err]=i;
                for(m=l+1;m<45;m++){
                    err.flip(m);
                    mymap[err]=i;
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
char d;
cin>>n;
long long int temp;
for(i=0;i<n;i++){
cin>>temp;
bitset<45> x=bitset<45>(temp);
if(mymap.count(x)>0){
d=mymap[x]+97;
cout<<d;
}
else{cout<<"?";}
}
return 0;


}
