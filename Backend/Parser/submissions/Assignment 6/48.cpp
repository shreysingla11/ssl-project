#include<iostream>
#include<string>

using namespace std;

int main(){
string s; //Given string
int lss=0,pos=0; //lss is length of shortest square string and pos earliest position of this string
int blocks=0;
cin>>s;
int n=s.size();//n is the length of the given string

int l,i=0,j=0;

for(l=1;l!=n;l=l*2){
    blocks=(n/l);// dividing the string into blocks of size l

        while(i<l){
            if(s[i]!=s[l+i]){
                for(j=i+2*l-1;j!=i+4*l-2;j++){
                    i=0;
                    if(s[i]!=s[j]){
                        break;
                    }
                    else{
                        i++;
                    }
                }

            }
            else{
                i++;
            }
        }
}
return 0;
}
