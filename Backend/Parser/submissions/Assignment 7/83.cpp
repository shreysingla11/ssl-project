
#include<iostream>
#include<map>
#include<set>
#include<string>
#include<fstream>
using namespace std;



int main()
{



    map<string,int> x;
    map<int, set<string> > y;


    char c;
    string s;
    int n,m;
    int ill=0;
    set<string>::iterator it1;
    map<int ,set<string> >::iterator it2,it3;
    int i,j;


    for(; cin>>c;)
    {

        if(c=='O')
        {
            cin>>s;
            if(x.count(s)!=0)
            {
                ill++;

            }
            else
            {
                x[s]=0;
                y[0].insert(s);
            }

            continue;
        }
        if(c=='C')
        {
            cin>>s;


            if(x.count(s)==0)
            {
                ill++;

            }
            else
            {
                if(x[s]!=0)
                {
                    ill++;
                }
                else
                {
                    x.erase(s);
                    y[0].erase(s);
                    if(y[0].size()==0)
                    {
                        y.erase(0);
                    }
                }

            }

            continue;
        }
        if(c=='D')
        {
            cin>>s;

            cin>>n;
            if(x.count(s)==0)
            {
                ill++;
            }
            else
            {
                m=x[s];
                x[s]=m+n;
                y[m].erase(s);
                if(y[m].size()==0)
                {
                    y.erase(m);
                }
                y[m+n].insert(s);
            }


            continue;
        }
        if(c=='W')
        {
            cin>>s;

            cin>>n;
            if(x.count(s)==0)
            {
                ill++;
            }
            else
            {
                m=x[s];
                if(n<=m)
                {

                    x[s]=m-n;
                    y[m].erase(s);
                    if(y[m].size()==0)
                    {
                        y.erase(m);
                    }
                    y[m-n].insert(s);
                }
                else
                {
                    ill++;

                }
            }

            continue;
        }
        if(c=='P')
        {

            cin>>m>>n;
            it2=y.lower_bound(m);
             it3=y.end();


            for(;(it2!=it3);)
            {

                     if((it2->first)>n)
                    {
                    break;
                    }

                    cout<<it2->first<<" ";
                    it1=it2->second.begin();
                    for(; it1!=it2->second.end(); it1++)
                    {
                        cout<<*it1<<" ";

                    }
                    cout<<endl;
                    it2++;


            }

            continue;
        }
        if(c=='E')
        {
        break;
        }
    }
    cout<<ill<<endl;
    return 0;
}
