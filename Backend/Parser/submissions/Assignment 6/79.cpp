#include<iostream>

using namespace std;

int main() {

string s;
cin>>s;
int n;
n=s.size();
int l=1,i,j;
bool found=true;
int spos=0,neq=0,neq2=0,fpos,len=0,pos=0;
    for(l=1;l<n;l=l*2) {
        for(j=1;j<=n/l;j++) {
            spos=l*j;
            for(i=0;i<l&&spos<=((4*l)-2);i++) {
                spos=spos+i;
                if(s[i]==s[spos]) {
                neq=neq+1;
                }
                else {
                neq=0;
                i=0;
                }
                if(neq==l) {
                fpos=spos+1-l;
                    for(int k=l*j;k<fpos;k++) {
                        int m=1;
                        if(s[k]==s[spos+m]) {
                            neq2=neq2++;
                            }
                        else {break;}
                        m++;
                        fpos=0;
                        }
                if(neq2==fpos-l) {found=true;}
                neq=0;
                }
            }
        }
    }

if (found==true) {
cout<<len<<" "<<pos;
    }
return 0;
}
