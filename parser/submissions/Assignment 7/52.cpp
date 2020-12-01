#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

int main ()
{
    map<string,int> Acc;
    map<int, set<string> > Bal;
    map<int, set<string> >::iterator itb;
    set< string > myset;
    set< string >::iterator its;
    string c,name;
    char c1;
    int val,pval,vals,err=0;
    int val1,val2;

    while(cin>>c1){

        switch(c1) {
            case 'O' :
                cin>>name;
                if(Acc.count(name)>0){err++;}
                else{Acc[name]=0;Bal[0].insert(name);}
                break;
            case 'C' :
                cin>>name;
                if(Acc.count(name)<=0){err++;}
                else{if(Acc[name]!=0){err++;}
                else{Acc.erase(name);Bal[0].erase(name);}}
                if(Bal[0].size()==0){Bal.erase(0);}
                break;
            case 'D' :
                cin>>name>>val;
                if(Acc.count(name)<=0){err++;}
                else{pval=Acc[name];vals=pval;pval=pval+val;Acc[name]=pval;
                    Bal[vals].erase(name);Bal[Acc[name]].insert(name);
                }
                if(Bal[vals].size()==0){Bal.erase(vals);}
                break;
            case 'W' :
                cin>>name>>val;
                if(Acc.count(name)<=0){err++;}
                else{if(Acc[name]<val){err++;}
                    else{pval=Acc[name];vals=pval;pval=pval-val;Acc[name]=pval;
                    Bal[vals].erase(name);Bal[Acc[name]].insert(name);}
                }
                if(Bal[vals].size()==0){Bal.erase(vals);}
                break;
            case 'P' :
                cin>>val1>>val2;
                for (itb=Bal.begin(); itb!=Bal.end(); ++itb){
                    if(itb->first>=val1 && itb->first<=val2){
                    cout << itb->first;
                    for (its=Bal[itb->first].begin(); its!=Bal[itb->first].end(); ++its){
                        cout << ' ' << *its;}
                    cout<<endl;}
                }
                break;
            default :
                break;
        }
    }
    cout<<err<<endl;

    return 0;
}

