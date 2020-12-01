#include<iostream>
#include<map>
#include<set>
using namespace std;

int main()
{
    char ch;
    string s;
    int m,n,wrong=0;
    map<string,int> bal;
    set<string> names;
    map<int,set<string> > freq;
    map<int,set<string> >:: iterator it,it2;
    set<string>:: iterator it1;
    bool flag=true;
    while(flag)
    {
        cin>>ch;
        switch(ch)
        {
        case 'O':
        {
            cin>>s;
            if(bal.count(s)==0)
            {
                bal[s]=0;
                freq[0].insert(s);
            }
            else
            {
                wrong++;
            }
        }
        break;
        case 'C':
        {
            cin>>s;
            if(bal.count(s)!=0)
            {
                if(bal[s]==0)
                {
                    freq[0].erase(s);
                    bal.erase(s);
                    if(freq[0].size()==0)
                    {
                        freq.erase(0);
                    }
                }
                else
                {
                    wrong++;
                }
            }
            else
            {
                wrong++;
            }
        }
        break;
        case 'D':
        {
            cin>>s>>n;
            if(bal.count(s)!=0)
            {
                freq[bal[s]].erase(s);
                if(freq[bal[s]].size()==0)
                {
                    freq.erase(bal[s]);
                }
                bal[s]+=n;
                freq[bal[s]].insert(s);
            }
            else
            {
                wrong++;
            }
        }
        break;
        case 'W':
        {
            cin>>s>>n;
            if(bal.count(s)!=0)
            {
                if(bal[s]>=n)
                {
                    freq[bal[s]].erase(s);
                    if(freq[bal[s]].size()==0)
                    {
                        freq.erase(bal[s]);
                    }
                    bal[s]-=n;
                    freq[bal[s]].insert(s);
                }
                else
                {
                    wrong++;
                }
            }
            else
            {
                wrong++;
            }
        }
        break;
        case 'P':
        {
            cin>>m>>n;
            if(m<=n)
            {
                for(it=freq.lower_bound(m); it!=freq.upper_bound(n); ++it)
                {
                    cout<<it->first<<" ";
                    for(it1=it->second.begin(); it1!=it->second.end(); ++it1)
                    {
                        if(++it1==it->second.end())
                        {
                            --it1;
                            cout<<*it1;
                        }
                        else
                        {
                            --it1;
                            cout<<*it1<<" ";
                        }
                    }
                    cout<<endl;
                }
            }
        }
        break;
        default :
        {
            flag=false;
        }
        break;
        }
    }
    cout<<wrong;
    cout<<endl;
    return 0;
}
