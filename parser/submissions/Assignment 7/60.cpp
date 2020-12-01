#include<iostream>
#include<map>
#include<set>
#include<string>
using namespace std;
int main(){
            map<string,int> accname_bal;
            map<int, set<string> > bal_names;
            set<string> x;
            set<string>::iterator it;
            string a;int i=0;
            for(int i=0;;){getline(cin,a);i++;if(a[0]=='E')break;x.insert(a);}
            it=x.begin();
            for(it=x.begin();it!=x.end();it++){



                   string b=*it;
                     b=&b[0]+2;





                if((*it)[0]=='O'){accname_bal[b]=0;bal_names[0].insert(b);}
                if((*it)[0]=='C'){accname_bal.erase(b);}
                if((*it)[0]=='D'){}
                if((*it)[0]=='W'){}
                if((*it)[0]=='P'){}
                cout<<*(bal_names[0].begin())<<endl;
                 ////delete a;

                    }

            }
