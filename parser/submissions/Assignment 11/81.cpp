#include<iostream>
//#include<unordered_map>
#include<vector>
using namespace std;

int main(){
    int n,temp;
    long long int num;
    bool bin[45];
    vector<char> v;
    cin>>n;
    //n=10000000;
    for(int i=0;i<n;i++){
        cin>>num;
        //num = i;
        long int p=1;
        for(int j=0;j<45;j++){
            bin[44-j]=num%2;
            num = num/2;
        }
        int none,nchan=0;
        p=1;
        temp=0;
        for(int j=44;j>0;j=j-9){
            none = 0;
            for(int k=j;k>j-9;k--){
                none = none + bin[k];
            }
            if(none>4){
                nchan = 9-none+nchan;
                temp = temp+p;
            }
            else{
                nchan = nchan+none;
            }
            p = p*2;
        }
        if(nchan>4){v.push_back('?');}
        else{
            if(temp<0||temp>25){v.push_back('?');}
            else{v.push_back('a'+temp);}
        }
    }
    for(int i=0;i<n;i++){
        cout<<v[i];
    }
return 0;
}
