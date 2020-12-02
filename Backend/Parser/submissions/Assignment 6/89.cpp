#include<iostream>
#include<string>

using namespace std;

int main(){
string s;
cin>>s;
int l=1,n,tl;
n=s.length();
string sub;
for(l=1;l<n;l=l*2){
    int pos=0;
    //cout<<l<<endl;
    for(pos=0;pos<n;pos=pos+l){
        //cout<<"pos"<<pos<<endl;
        int ind1,ind2=0;
        ind1=pos;
        int j=2*l+pos-1;
        while(j<=(pos+(4*l)-2)){
            //cout<<"j"<<j<<" "<<pos+4*l-2<<endl;
            int k=pos;
            for(k=pos;k<pos+l;k++){
                //cout<<"k"<<k<<endl;
                if(s[k]!=s[j+k-pos]){
                    j=j+k-pos+1;
                    break;
                }
            }
            if(k==pos+l){
                break;
            }
        }
        if(j<=pos+4*l-2){
            ind2=j;
            tl=ind2-ind1;
            int stop1,stop2,p,q;
            //cout<<ind1<<"  "<<ind2<<"  "<<tl<<endl;
            for(p=ind1;p<ind2;p++){
                if((p+ind2-ind1)>=n){
                    stop1=p-1;
                    break;
                }
                if(s[p]!=s[p+ind2-ind1]){
                    stop1=p-1;
                    break;
                }
            }
            if(p==ind2){
                stop1=p-1;
            }
            //cout<<"stop1 "<<stop1<<endl;
            for(q=ind2;q>stop1;q--){
                if((q-ind2+ind1)>=n){
                    stop2=q+1;
                    break;
                }
                if(s[q]!=s[q-ind2+ind1]){
                    stop2=q+1;
                    break;
                }
            }
            if(q==stop1){
                stop2=stop1+1;
            }
            //cout<<"stop2 "<<stop2<<endl;
            if(stop1+1==stop2){
                cout<<tl<<" "<<ind1<<endl;
                return 0;
            }
        }
    }
    //cout<<l<<"HI"<<endl;
}
cout<<"0"<<" "<<"0"<<endl;
return 0;
}
