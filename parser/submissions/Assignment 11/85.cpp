#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

typedef unordered_map<long long int,char> maptype;

void convertstr(int& keyval, int* keystr){
    int binval;
    int value=keyval;
    for(int i=4;i>=0;i--){
        binval=value%2;
        value=(value-binval)/2;
        keystr[i]=binval;
    }
};
void generatestr(int* keystr, string& keystring){
    for(int i=0; i<5; i++){
        for(int j=0; j<9; j++){
            if(keystr[i]==0){keystring.append("0");}
            if(keystr[i]==1){keystring.append("1");}
        }
    }
};
void convertlong(string& keystring, long long int& key){
    long long int value=1;
    key=0;
    for(int i=44; i>=0; i--){
        if(keystring[i]==1){key+=value;}
        value*=2;
    }
};
void flip(char a){
    if(a==0){a=1;}
    if(a==1){a=0;}
};


void adderrors(maptype& mymap, string& keystring, char val){
    string temp;
    long long int key1;
    int i=0,j=0,k=0,l=0;
    for(i=0;i<45;i++){
        for(j=i+1;i<45;i++){
            for(k=j+1;i<45;i++){
                for(l=k+1;i<45;i++){
                    temp=keystring;
                    flip(temp[l]);
                    flip(temp[k]);
                    flip(temp[j]);
                    flip(temp[i]);
                    convertlong(temp,key1);
                    mymap.insert( {key1,val} );
                }
                flip(temp[k]);
                flip(temp[j]);
                flip(temp[i]);
                convertlong(temp,key1);
                mymap.insert( {key1,val} );
            }
            flip(temp[j]);
            flip(temp[i]);
            convertlong(temp,key1);
            mymap.insert( {key1,val} );
        }
        flip(temp[i]);
        convertlong(temp,key1);
        mymap.insert( {key1,val} );
    }

};

int main() {
    maptype mymap;
    char val = 'a'; int keyval = 0;
    int* keystr = new int[5];
    string keystring;
    long long int key;

    while(keyval<26){
        convertstr(keyval,keystr);
        generatestr(keystr,keystring);
        //cout<<keystring<<endl;
        convertlong(keystring,key);
        mymap.insert( {key,val} );
        adderrors(mymap,keystring,val);
        keyval++;val++;
    }
    int n; cin>>n;
    long long int x;
    for(int i=0;i<n;i++){
        cin>>x;
          try {
    cout<<mymap.at(x);
  }
  catch (const std::out_of_range& oor) {
    cout<<"?";
  }

    }
}
