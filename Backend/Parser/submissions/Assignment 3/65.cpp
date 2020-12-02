#include<iostream>
#include<vector>
//#include<limit.h>
using namespace std;
int m(vector<int> &a,vector<int> &b,int &i,int &j,int &k,int &l){if(a.back()==b.back()&&i==k-1&&j==l-1) return 1;
                                                                if(a.back()!=b.back()&&i==k-1&&j==l-1) return l+k;
                                               if(a[i]==b.back()&&j==l-1) return 1;
                                               else
                                               {if(a[i]!=b.back()&&j==l-1){i=i+1;return 1+m(a,b,i,j,k,l);} }
                                               if(a[i]==b[j]){i=i+1;j=j+1; return 1+m(a,b,i,j,k,l);}

                                               if(a[i]!=b[j]){i=i+1; return 1+m(a,b,i,j,k,l);}

                                               }
int main(){string c;vector<int> a,b;
        getline(cin,c);
        int j=0,k=0,l=0;
            while(c[j]!=' '){
            k=10*k+c[j]-48;
            j++;}
            j++;
            while(c[j]!='\0'){
            l=10*l+c[j]-48;
            j++;}
        j=0;
        int i=0;
        getline(cin,c);
            while(c[j]!='\0'){
            while(c[j]!=' '){a.push_back(0);
            a[i]=a[i]*10+c[j]-48;
            j++;
            }
            i++;
            j++;
            }
        j=0;i=0;
        getline(cin,c);
            while(c[j]!='\0'){
            while(c[j]!=' '){b.push_back(0);
            b[i]=b[i]*10+c[j]-48;
            j++;
            }
            i++;
            j++;
            }
        i=j=0;int minm=k+1;int y=0;
           for(i=0;i<k;i++){int u=i;int v=j;if(a[i]!=b[0])continue;int x=m(a,b,i,j,k,l);i=u;j=v;
            if(x<minm)
            {minm=x;y=u+1;}

            }
             if(minm!=k+1)cout<<minm<<" "<<y<<endl;
             else cout<<"infinity"<<endl;
return 0;
            }
