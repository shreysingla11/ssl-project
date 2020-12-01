#include<iostream>
#include<string>
#include<map>
#include<set>
using namespace std;
void open(string s, map<string,int>&A, map<int, set<string> >&B, int&invalid)
{
    if(A.find(s) != A.end())
    {
        invalid++;
        return ;
    }
    A[s] = 0;
    B[0].insert(s);
    return;
}
void close(string s, map<string,int>&A, map<int, set<string> >&B, int&invalid)
{
    if(A.find(s) == A.end() || A[s] != 0)
    {
        invalid++;
        return ;
    }
    map<string,int>::iterator it;
    set<string>::iterator iter;
    iter = B[A[s]].find(s);
    B[A[s]].erase(iter);
    if(B.find(A[s]) == B.end())
    {
        B.erase(A[s]);
    }
    it = A.find(s);
    A.erase(it);
    return;
}
void deposit(string s, map<string,int>&A, map<int, set<string> >&B, int&invalid, int&a)
{
    if(A.find(s) == A.end())
    {
        invalid++;
        return;
    }
    B[A[s]].erase(s);
    if(B.find(A[s]) == B.end())
    {
        B.erase(A[s]);
    }
    A[s] = A[s]+a;
    B[A[s]].insert(s);
    return;
}
void withdraw(string s, map<string,int>&A, map<int, set<string> >&B, int&invalid, int&a)
{
    if(A.find(s) == A.end() || A[s] < a)
    {
        invalid++;
        return;
    }
    B[A[s]].erase(s);
    if(B.find(A[s]) == B.end())
    {
        B.erase(A[s]);
    }
    A[s] = A[s]-a;
    B[A[s]].insert(s);
    return;
}
void print(map<string,int>&A, map<int, set<string> >&B, int&a, int&b)
{
    set<string>::iterator iter;
    map<int,set<string> >::iterator it;
    for(it=B.begin(); it!=B.end(); it++)
    {
        if((it->first>=a) && (it->first<b))
        {
            cout<<it->first<<" ";
            for(iter=it->second.begin(); iter!=it->second.end(); iter++)
            {
                cout<<*iter<<" ";
            }
            cout<<endl;
        }
    }
    return;
}
int main()
{
    map<string,int> A;
    map<int, set<string> > B;
    set<string> S;
    int invalid = 0;
    char i;
    string s;
    int a;
    int b;
    cin>>i;
    while(i != 'E')
    {
        switch(i)
        {
        case 'O':
            cin>>s;
            open(s,A,B,invalid);
            break;
        case 'C':
            cin>>s;
            close(s,A,B,invalid);
            break;
        case 'D':
            cin>>s;
            cin>>a;
            deposit(s,A,B,invalid,a);
            break;
        case 'W':
            cin>>s;
            cin>>a;
            withdraw(s,A,B,invalid,a);
            break;
        case 'P':
            cin>>a;
            cin>>b;
            print(A,B,a,b);
            break;
        }
        cin>>i;
    }
    cout<<invalid<<endl;
    return 0;
}
