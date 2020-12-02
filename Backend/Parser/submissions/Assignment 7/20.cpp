#include <iostream>
#include<fstream>
#include <set>
#include <map>
using namespace std;
int open(map<string,int> &m1,map<int, set<string> > &m2,set<int> &b, string s)
{
    if((m1.lower_bound(s))->second==m1[s])
    {
        m1[s]=0;
        m2[0].insert(s);

        if(b.count(0)==0)
        {
            b.insert(0);
        }
        return 0;
    }
    else
    return 1;
}
int close(map<string,int> &m1,map<int, set<string> > &m2,set<int> &b, string s)
{
    if(m2[m1[s]].find(s)==m2[m1[s]].end())
    {
            return 1;
    }
    else
    {
        m2[0].erase(s);
        m1.erase(s);
        if(m2[0].size()==0)
        {b.erase(0);}
        return 0;
    }
}
int deposit(map<string,int> &m1,map<int, set<string> > &m2,set<int> &b, string s, int amt)
{
    if(m2[m1[s]].find(s)==m2[m1[s]].end())
    {
        return 1;
    }
    else
    {
        if(m2[m1[s]].size()==1)
        {b.erase(m1[s]);
        m2.erase(m1[s]);}
        else
        {m2[m1[s]].erase(s);}
        m1[s]+=amt;
         if(m2[m1[s]].empty())
        {b.insert(m1[s]);}
        m2[m1[s]].insert(s);

        return 0;
    }
}
int withdraw(map<string,int> &m1,map<int, set<string> > &m2,set<int> &b, string s, int amt)
{
    if(amt>m1[s]||m2[m1[s]].find(s)==m2[m1[s]].end())
    {return 1;}
    else
    {
        if(m2[m1[s]].size()==1)
        {b.erase(m1[s]);m2.erase(m1[s]);}
        else {m2[m1[s]].erase(s);}
        m1[s]-=amt;
        if(m2[m1[s]].empty())
        {b.insert(m1[s]);}
        m2[m1[s]].insert(s);

        return 0;
    }
}
void print(map<string,int> &m1,map<int, set<string> > &m2,set<int> &b,int init, int fin)
{

    set<int>::iterator itb = b.lower_bound(init);
    set<int>::iterator ite = b.upper_bound(fin);

    for(;itb!=ite;itb++)
    {

        cout<<*itb<<" ";
        set<string>::iterator i=m2[*itb].begin();
        int n=m2[*itb].size();
        for(int j=0;j<n;j++)
        {

        if(j==n-1)
        {cout<<*i<<endl;i++;}

        else
        {
        cout<<*i<<" ";
        i++;
        }
        }
    }

    return;
}
int main()
{
    map<string,int> map1;
    map<int, set<string> > map2;
    set<int> bal;
    int counter=0;
    char c;
    string s1;
    int a1;
    int a2;

    while(true)
    {
        cin>>c;
        switch(c)
        {
         case 'O':
         cin>>s1;
         counter+=open(map1,map2,bal,s1);
         break;
         case 'C':
         cin>>s1;
         counter+=close(map1,map2,bal,s1);
         break;
         case 'D':
         cin>>s1>>a1;
         counter+=deposit(map1,map2,bal,s1,a1);
         break;
         case 'W':
         cin>>s1>>a1;
         counter+=withdraw(map1,map2,bal,s1,a1);
         break;
         case 'P':
         cin>>a1>>a2;
         print(map1,map2,bal,a1,a2);
         break;
         case 'E':
         cout<<counter<<endl;
         return 0;

        }
    }

}
