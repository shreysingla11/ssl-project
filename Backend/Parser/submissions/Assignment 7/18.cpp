#include<iostream>
#include<map>
#include<set>
#include<string>
using namespace std;
map<string , int > bal ;
map<int,set<string> > range;
int illegal = 0;
void O(string name);
void C(string name);
void D(string name ,int addition);
void W(string name ,int reduction);
void P(int start ,int end1);
int main()
{

    string character , name ;
    int addition , reduction ,start ,end1;
  while(true)
  {
    cin>>character;
  if(character=="O")
  {
      cin>>name;
      O(name);
  }
  if(character=="D")
  {
      cin>>name;
      cin>>addition;
      D(name,addition);
  }
  if(character=="C")
  {
      cin>>name;
      C(name);
  }

  if(character=="W")
  {
      cin>>name;
      cin>>reduction;
      W(name , reduction);
  }
  if(character=="P")
  {
      cin>>start;
      cin>>end1;
      P(start, end1);
  }
  if(character=="E")
  {
    break;
  }

  }
  cout<<illegal<<endl;
    return 0;
}


void O(string name)
{
    if(bal.find(name)==bal.end())
    {
        bal[name]=0;
        range[bal[name]].insert(name);
    }
    else
    {
        illegal++;
    }
    return ;
}
void D(string name , int addition)
{
    if(bal.find(name)==bal.end())
    {
        illegal++;
    }
    else
    {
        range[bal[name]].erase(name);
        if(range[bal[name]].begin()==range[bal[name]].end())
        {
            range.erase(bal[name]);
        }
        bal[name]+=addition;
        range[bal[name]].insert(name);
    }
       return ;
}
void C(string name)
{
    if(bal.find(name)==bal.end()||bal[name]!=0)
    {
        illegal++;
    }
    else
    {
        range[bal[name]].erase(name);
        if(range[bal[name]].begin()==range[bal[name]].end())
        {
            range.erase(bal[name]);
        }
        bal.erase(name);
    }
    return ;
}
void W(string name , int reduction)
{
    if(bal.find(name)==bal.end()||bal[name]<reduction)
    {
        illegal++;
    }
    else
    {
        range[bal[name]].erase(name);
        if(range[bal[name]].begin()==range[bal[name]].end())
        {
            range.erase(bal[name]);
        }
        bal[name]-=reduction;
        range[bal[name]].insert(name);
    }
       return ;
}
void P(int start ,int end1)
{
    while (start<=end1)
    {
         set<string> :: iterator  it ;
         it=range[start].begin();
        if(range[start].begin()==range[start].end())
        {
            ;
        }
        else
        {
            cout<<start<<" ";
            while(it!=range[start].end())
            {
                cout<<*it<<" ";
                it++;
            }
            cout<<endl;
        }

        start++;
    }


    return ;
}
