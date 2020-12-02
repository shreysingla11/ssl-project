#include<iostream>
#include<vector>
using namespace std;

class distinct
{
public:
    vector<int> s,l;
    distinct(vector<int> v)
    {
        s=v;
        int n=s.size();
   vector<vector<int > > p,q;
        for(int i=0; i<n; i++)
        {
            int counts=-1;
            for(int j=0; j<i; j++)
            {
                if(s[j]==s[i])
                {
                    counts=j;
                }
            }
            l.push_back(counts);
        }

 /*
 for(int i=n/2;i>=1;i=i/2){

  vector<int> a,b;
        for(int j=0;j<n;j++){
        int m=0,c=0;
        for(int k=0;k<2^(i-1);k++){
        if(((k*n)/2^(i-1)<=l[j])&&(((k+1)*n)/2^(i-1)>l[j])){m=k;}
        }
         for(int k=0;k<j;k++){
          if(((m*n)/2^(i-1)+n/(2^i) <=l[j])&&(((m+1)*n)/(2^(i-1))>l[j])){c++;}
        }
        a.push_back(c);
        }
        p.push_back(a);

        for(int j=0;j<n;j++){
        int m=0,c=0,k1=0,k2=0;
        for(int k=0;k<2^(i-1);k++){
        if(((k*n)/(2^(i-1))+n/(2^i)<=l[j])&&(((k+1)*n)/(2^(i-1))>l[j])){m=k;}
        }
         for(int k=j-1;k>=0;k++){
         if(k1!=1){
          if(((m*n)/2^(i-1) <=l[k])&&((m*n)/2^(i-1)+n/2^i >l[k])){c=k;k1++;break;}
          }
          if(k2!=1){
          if(((m*n)/2^(i-1)+n/2^i <=l[k])&&(((m+1)*n)/2^(i-1)>l[k])){c=k;k2++;}
          }
        }
        b.push_back(c);
        }
        q.push_back(b);
    }
    */
     }

    int num_distinct(int i,int j)
    {int x=0;
    for(int k=0;k<=j;k++){
    if(l[k]>=i){x++;}
    }
    return j-i+1-x;
    }
};

