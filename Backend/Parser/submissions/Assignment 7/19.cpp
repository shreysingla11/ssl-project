#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
    map<string,int>A;
    //map<int,string>T;
    map<int, set<string> >B;
    //map<set<string>, int >C;
    //map<int,set<string> >D;
    set<string>allnames;
    set<string>::iterator it2;
    vector<int>allbal;
    vector<int>::iterator it;
    set<int>bal;
    set<int>::iterator it1;
    //vector<set<string> >names;
    int n=0;
    char c;
    string s;
    int i;
    int count1=0;
    while(c!='E')
    {
        cin>>c;
        if(c=='O')
        {
            cin>>s;
            if(allnames.find(s)!=allnames.end())
            {
                count1++;
            }
            else
            {
                allnames.insert(s);
                allbal.push_back(0);
                A[s]=allbal[n];
                n++;

                if(bal.find(A[s])==bal.end())
                {
                    bal.insert(A[s]);
                    it1=bal.find(A[s]);
                    set<string>temp;
                    temp.insert(s);
                    B[*it1]=temp;
                }
                else
                {
                    it1=bal.find(A[s]);
                    B[*it1].insert(s);
                }
            }
        }
        if(c=='D')
        {
            cin>>s;
            cin>>i;
            if(allnames.find(s)==allnames.end())
            {
                count1++;
            }
            else
            {
                B[*bal.find(A[s])].erase(s);
                A[s]=A[s]+i;
                if(bal.find(A[s])==bal.end())
                {
                    bal.insert(A[s]);
                    it1=bal.find(A[s]);
                    set<string>temp;
                    temp.insert(s);
                    B[*it1]=temp;
                }
                else
                {
                    it1=bal.find(A[s]);
                    B[*it1].insert(s);
                }
            }
        }
        if(c=='W')
        {
            cin>>s;
            cin>>i;
            if(allnames.find(s)==allnames.end())
            {
                count1++;
            }
            else
            {
                if(A[s]<i)
                {
                    count1++;
                }
                else
                {
                    B[*bal.find(A[s])].erase(s);
                    A[s]=A[s]-i;
                    if(bal.find(A[s])==bal.end())
                    {
                        bal.insert(A[s]);
                        it1=bal.find(A[s]);
                        set<string>temp;
                        temp.insert(s);
                        B[*it1]=temp;
                    }
                    else
                    {
                        it1=bal.find(A[s]);
                        B[*it1].insert(s);
                    }
                }
            }
        }
        if(c=='P')
        {
            int x,y;
            cin>>x;
            cin>>y;
            it1=bal.begin();
            while(it1!=bal.end())
            {

                if(*it1>=x&&*it1<=y)
                {
                    //B[*it1];
                    it2=B[*it1].begin();
                    if(it2!=B[*it1].end())
                    {cout<<*it1<<" ";}
                    while(it2!=B[*it1].end())
                    {
                        cout<<*it2<<" ";
                        it2++;
                    }
                }
                it1++;
                if(it1!=bal.end())
                {cout<<endl;}
            }
        }
        if(c=='C')
        {
            cin>>s;
            if(allnames.find(s)==allnames.end())
            {
                count1++;
            }
            else
            {
                if(A[s]!=0)
                {
                    count1++;
                }
                else
                {
                    allnames.erase(s);
                    it = find (allbal.begin(), allbal.end(), A[s]);
                    allbal.erase(it);
                    B[*bal.find(A[s])].erase(s);
                }
            }
        }
    }
    cout <<count1;
    return 0;
}
