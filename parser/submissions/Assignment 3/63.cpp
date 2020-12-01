#include<iostream>
#include<algorithm>
#include<vector>
#include<limits>
using namespace std;
class answer
{
  public:
  int n,m;
  int* a=new int;
  int* b=new int;
  int temp;
  int t= numeric_limits<int>::max();
  int column(int i,int j)
  {

    if((i==n)&&(j==m)){if(a[n-1]==b[m-1])return 1;
                       else{return t;}
                      }
    else if(j==m){if(a[i-1]==b[m-1]){return 1;}
                   else {temp=column(i+1,m);if(temp!=t)return 1+temp; }
                 }
    else if(i==n){return t;}
    else {if(a[i-1]==b[j-1]){temp=column(i+1,j+1);if(temp!=t)return 1+temp;}
          else {temp=column(i+1,j);if(temp!=t)return 1+temp;}
         }
  }
};
int main()
{
//while(1){
int i1=0,i2=0;answer p;
int t1;
vector<pair<int,int> > pairv;
pair<int,int> pairi;
cin>>p.n>>p.m;
while(i1<p.n)
{
cin>>p.a[i1];i1++;
}
while(i2<p.m)
{
cin>>p.b[i2];i2++;
}
i1=1;
while(i1<=(p.n-p.m))
{
  pairi.first = p.column(i1,1);
  pairi.second = i1;
  pairv.push_back(pairi);
  i1++;
}

sort(pairv.begin(),pairv.end());
if(pairv[0].first==p.t){cout<<"infinity"<<endl;return 0;}
cout<<pairv[0].first<<" "<<pairv[0].second<<endl;
//}
return 0;
}
