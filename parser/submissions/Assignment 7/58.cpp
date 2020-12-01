#include<iostream>
#include<set>
#include<map>
using namespace std;

int main()
{
map<string,int> name;
map<string,int>::iterator namei;
map<int,set<string> > bal;
int noi=0;
while(1)
{
char opt;
cin>>opt;
switch(opt){
 case 'O':
    {
     string nam;
     cin>>nam;
     namei=name.find(nam);
     if(namei!=name.end())
     {
     noi++;
     }
     else{name[nam]=0;bal[0].insert(nam);}
     break;
     }
 case 'W':
     {
      string nam;int num=0;
      cin>>nam;
      cin>>num;
      namei=name.find(nam);
      if(namei!=name.end())
        {
        if(num>=0)
        {
         if(name[nam]>=num)
          {bal[name[nam]].erase(nam);
          if(bal[name[nam]].empty()){bal.erase(name[nam]);}
          name[nam]-=num;
          bal[name[nam]].insert(nam);}
         else{noi++;}
        }
        else{noi++;}
        }
        else{noi++;}
        break;
     }
case 'D':
     {
      string nam;int num=0;
      cin>>nam;
      cin>>num;
      namei=name.find(nam);
      if(namei!=name.end())
      {
       if(num>=0)
       {bal[name[nam]].erase(nam);
        if(bal[name[nam]].empty()){bal.erase(name[nam]);}
        name[nam]+=num;
        bal[name[nam]].insert(nam);}
       else{noi++;}
      }
      else{noi++;}
      break;
     }
 case 'C':
     {
     string nam;
     cin>>nam;
     namei=name.find(nam);
     if(namei!=name.end())
     {
      if(name[nam]>0)
      {noi++;}
      else{
      bal[name[nam]].erase(nam);
      if(bal[name[nam]].empty()){bal.erase(name[nam]);}
      name.erase(nam);
      }
     }
     else{noi++;}
     break;
     }

 case 'P':
  {
   int a=0,b=0;
   cin>>a>>b;
   map<int,set<string> >::iterator lower,upper,t1;
   set<string>::iterator t;
   lower=bal.lower_bound(a);
   upper=bal.upper_bound(b);
   if(lower->first < bal.begin()->first){lower=bal.begin();}

   if(lower->first<a)
   {
    lower++;
   }
      while(lower!=upper)
      {
         t=(lower->second).begin();
         if(a<=lower->first<=b){
          cout<<lower->first<<" ";
          while(t!=(lower->second).end())
          {

          cout<<(*t)<<" ";
          t++;
          }
          cout<<endl;}
          lower++;
          }
   break;
  }
 case 'E':
   cout<<noi<<endl;return 0;
  }
}
return 0;
}
