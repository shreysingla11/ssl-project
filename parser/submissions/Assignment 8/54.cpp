#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;


int main()
{
  int n,w,u,v,t1,t2;int tm1=0;
  cin>>n>>w>>u>>v>>t1>>t2;tm1=n;
  vector<pair<int,int> > init;
  //map<int,points> mp;
  //int cnt=1;
  //code for inputs
   while(tm1--)
   {
    char c;int nos=0;
    cin>>c;
    if(c=='E')
    {
    cin>>nos;int l,p,in=0,en=0;
    if(nos>1000){return 0;}
     while(nos--)
     {
         cin>>l>>p;
         en=-p;
         pair<int,int> temp;
         temp.first=in;
         temp.second=en;
        init.push_back(temp);
         in=en+l;
     }

    }
    else
    {

    cin>>nos;int l,p,in=0,en=0;
    if(nos>1000){return 0;}
     while(nos--)
     {
         cin>>l>>p;
         en=p;
        pair<int,int> temp;
         temp.first=in;
         temp.second=en;
        init.push_back(temp);
         in=en+l;
     }

    }

   }
sort(init.begin(),init.end());
    init.erase( unique( init.begin(),init.end() ), init.end() );
    vector<int> fin;
    vector<pair<int,int> >::iterator a=init.begin();a++;int i=1;
    while(a!=init.end())
    {
      fin.push_back(init[i].second-(*a).first);
      a++;i++;
    }
    int temp=fin[0];i=0;
    while(i<fin.size())
    {
      if(fin[i]>temp){temp=fin[i];}
      i++;
    }
    float f=temp*1.0/u-w*1.0/v;
    printf("%0.8f",f);


}
