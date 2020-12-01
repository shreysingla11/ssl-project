#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;

void solution(string &s){
    bool worked = false;
    for(int l = 1;l<s.size();l*=2){
        int maxlength=s.size()+1,maxindex;
        for(int p=0;p<s.size();p+=l){
            //p is starting index

            //getting i2
            int i2 = -1,length = -1, firstindex = -1;
            for(int j=p+l,i=p;j<s.size();j++){
                if(i==p+l){
                    i2=j-l;
                    break;
                }
                if(s[i]==s[j]){
                    i++;
                }
                else{
                    if(j>=(p+4*l-2)){break;}
                    else{i=p;}
                }
            }
            //if i2==-1 no such occurance
            //else i1 is index of first occurance
            //i2 obtained

            if(i2!=-1){
                //finding length and firstindex if it exists
                //p is original i1,i2 is original i2
                int k1 = p,k2 = i2;
                while((s[k1]==s[k2])&&(k1>=0)){
                    if(k2==p+l){
                        length = i2-p;
                        firstindex = k1;
                        break;
                    }
                    k1--;k2--;
                }
                int k3 = p+l,k4 = i2+l;
                while((s[k3]==s[k4])&&(k4<s.size())){
                    if(k1==i2-1){
                        length = i2-p;
                        firstindex = p;
                        break;
                    }
                    k3++;k4++;
                }
                if(k3==(k2+1)){
                    length = k2-k1;
                    firstindex = k1+1;
                }
                //firstindex and length are properly stored
            }
            if(firstindex==-1){continue;}
            if((length<(2*l-1))||length>(4*l-2)){continue;}
            worked = true;
            if(maxlength>length){maxlength = length;maxindex = firstindex;}
        }
        if(worked){
            cout<<maxlength<<" "<<maxindex<<endl;
            return;
        }
    }
    cout<<"0 0"<<endl;
    return;
}



int main(){
    string s;
    cin>>s;
    solution(s);
    return 0;
}
