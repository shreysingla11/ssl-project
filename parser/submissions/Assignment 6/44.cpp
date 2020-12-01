#include <iostream>
#include <vector>
using namespace std;

vector<char> s;
int n;
int in,len;

bool g(int i,int j,int l){
  //ranges are (i,i+l-1) (j,j+l-1)
  int k1,k2,h1,h2;
  k1=i-1;
  k2=j-1;
  while(k1>=1 && k2>i+l-1){
    if(s[k1]==s[k2]){
      k1--;
      k2--;
    }
    else{
       break;
    }
  }

  h1=i+l;
  h2=j+l;
  while(h2<=n && h1<=k2){
    if(s[h1]==s[h2]){
       h1++;
       h2++;
    }
    else{
       break;
    }
  }

  if(h1>k2){
     int tmpi=k1+1;
     int tmplen=j-i;

     if(tmplen<len){
       len=tmplen;
       in=tmpi;
     }

     if(tmplen==len&& tmpi<in){
       in=tmpi;
     }

     return true;
  }
  else{
    return false;
  }

}


void f(int l){
  int j,k;
  for(int i=0;i*l+1<=n;i++){
     j=i*l+1;
     k=i*l+l+1;

     while(k <= i*l+4*l-1 && k<=n){
        if(s[j]!=s[k]){
          k++; continue;
        }
        else{
          j++; k++;
          if(j<=i*l+l && k<=n){
            while(s[j]==s[k]){
              j++; k++;
              if(j==i*l+l+1 || k>n){
                break;
              }
            }
          }

          if(j==i*l+l+1){
             bool flag=g(i*l+1,k-l,l);
             if(flag==true){
               k=n+1;
             }
             else{
                j=i*l+1;
                k=k-l+1;
             }
          }
          else{
             j=i*l+1;
          }

        }

     }

  }
  return ;
}

int main(){
  string str;
  cin>>str;
  n=str.size();
  s.resize(n+1);

  in=-1; len=n+7;
  for(int i=1;i<=n;i++){
     s[i]=str[i-1];
  }

/*
  {///////// testing ///////////
  int l;
  cin>>l;
  f(l);
  cout<<in<<" "<<len;
  //////// testing ///////////
  }
*/

  int l=1;
  while(l<=n/2){
    f(l);
    if(in!=-1){
       cout<<len<<" "<<in-1;
       break;
    }
    l*=2;
  }

  if(in==-1){
    cout<<0<<" "<<0;
  }


  return 0;
}

