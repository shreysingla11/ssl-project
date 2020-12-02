#include<iostream>
#include<map>
#include<set>
using namespace std;
int main()

{
    map<string,int> N2B;
    map<string,int>::iterator it;
    map<int, set<string> > B2S;
    map<int, set<string> >::iterator t;
    set<string> S;
    set<string>::iterator Si;

    char c;
    int b=0,d=0,ct=0;
    string s;
    bool flag=true;
    while(flag)
    {
        cin>>c;
        switch (c)
        {
        case 'O':
            cin>>s;
            it=N2B.find(s);
            if(it==N2B.end())
            {

                N2B[s]=0;
                B2S[0].insert(s);
            }
            else
            {
                ct++;
            }
            break;
        case 'D':
            cin>>s>>b;
            it=N2B.find(s);
            if(it!=N2B.end())
            {
                B2S[N2B[s]].erase(s);
                if(B2S[N2B[s]].empty()){B2S.erase(N2B[s]);}
                N2B[s]+=b;
                B2S[N2B[s]].insert(s);
            }
            else{ct++;}
            break;
        case 'W':
            cin>>s>>b;
            it=N2B.find(s);
            if(it==N2B.end())
            {
                ct++;
            }
            if(it!=N2B.end() && b>N2B[s])
            {
                ct++;
            }
            if(b<=N2B[s] && it!=N2B.end())
            {
                B2S[N2B[s]].erase(s);
                if(B2S[N2B[s]].empty()){B2S.erase(N2B[s]);}
                N2B[s]=N2B[s]-b;
                B2S[N2B[s]].insert(s);
            }
            break;
        case 'C':
            cin>>s;
            it=N2B.find(s);
            if(it==N2B.end())
            {
                ct++;
            }
            if(it!=N2B.end() && N2B[s]!=0)
            {
                ct++;
            }
            if(it!=N2B.end() && N2B[s]==0)
            {
                B2S[N2B[s]].erase(s);
                if(B2S[N2B[s]].empty()){B2S.erase(N2B[s]);}
                N2B.erase(s);
            }
            break;
        case 'P':
            cin>>b>>d;

            for(t=B2S.begin(); t!=B2S.end(); ++t)
            {
                if((t->first) >=b && (t->first) <=d)
                {
                    cout<< t->first<<" ";
                    S=t->second;
                    for(Si=S.begin(); Si!=S.end(); ++Si)
                    {
                        cout<<(*Si)<<" ";
                    }
                    cout<<endl;
                }

            }
            break;
        default:
            flag=false;

        }
    }

    cout<<ct<<endl;
    return 0;
}


