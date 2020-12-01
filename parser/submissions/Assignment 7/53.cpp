#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<string.h>
using namespace std;
void print(map<string,int>acc,int x,int y)
{ map<int, set<string> > groups;
        map<string,int>::iterator it1;
        map<int, set<string> >::iterator it;
        set<string>::iterator it2;
        string string1;
        int int1 =0;
        for(it1=acc.begin(); it1!=acc.end(); it1++)
        {       int1=it1->second;
                string1= it1->first;
                groups[int1].insert(string1);
        }
        for(it=groups.begin();it->first!=x;it++)
        {
          }
    while(it->first<=y)
    {
       cout<<it->first<<' ';
       for(it2=it->second.begin();it2!=it->second.end();it2++)
         {
           cout<<*it2<<' ';
           }
           cout<<endl;

       }
       return ;
   }
void update1(map<string,int>acc,string s,char x,int &count1,int v)
{map<string,int>::iterator it=acc.find(s);
  if(x=='w')
    {
       if(it!=acc.end()&&acc[s]>v){ acc[s]=acc[s]-v;
                              return;}
       else{count1++;
              return;}
   }


       if(it!=acc.end()){ acc[s]=acc[s]+v;
                              return;}
       else{count1++;
              return;}


   }



void update(map<string,int>acc,string s,char x,int& count1)
{ map<string,int>::iterator it=acc.find(s);
  if(x=='O'){
    if(it==acc.end()){
    acc[s]=0;
    return;}
    else{count1++;
          return;}
    }
    if(acc[s]==0){acc.erase(it);
                   return;}
    count1++;
    return;

    }
int main(){
map<string,int>acc;
char x;
string s1;
int i1,i2;
int i=0,count1=0;
while(true)
{
  cin>>x;
  if(x=='E'){break;}
  if(x=='O'||x=='C')
      {cin>>s1;
         update(acc,s1,x,count1);
         continue;}
  if(x=='D'||x=='W')
      {cin>>s1;
          cin>>i1;
         update1(acc,s1,x,count1,i1);
         continue;}
    if(x=='P')
      {
         cin>>i1;
         cin>>i2;
    print(acc,i1,i2);
         continue;}

}
cout<<count1;
return 0;
}


