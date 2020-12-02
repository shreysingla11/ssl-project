#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

int main(){
    map<string, int> p;
    map<int, set<string> >q;
    char ch;
    cin>>ch;
    string s;
    int illegal=0;
    int amt, maxi, mini;
    while (ch!='E'){
        switch(ch){
            case 'O':
                    cin>>s;
                    if (p.count(s)==0){
                        p[s]=0;
                        q[0].insert(s);
                    }
                    else
                        illegal++;
                    break;

            case 'D':
                    cin>>s;
                    cin>>amt;
                    if (p.count(s)==0)
                        illegal++;
                    else {
                        q[p[s]].erase(s);
                        if (q[p[s]].size()==0)
                            q.erase(p[s]);

                        p[s] = p[s]+amt;
                        q[p[s]].insert(s);
                    }
                    break;

            case 'C':
                    cin>>s;
                    if (p.count(s)==0)
                        illegal++;
                    else{
                        if (p[s]!=0)
                            illegal++;
                        else{
                            q[0].erase(s);
                            if (q[0].size()==0)
                                q.erase(0);
                            p.erase(s);
                        }
                    }
                    break;

            case 'W':
                    cin>>s;
                    cin>>amt;
                    if (p.count(s)==0)
                        illegal++;
                    else{
                        if (p[s]<amt)
                            illegal++;
                        else{
                            q[p[s]].erase(s);
                            if (q[p[s]].size()==0)
                                q.erase(p[s]);

                            p[s] = p[s]-amt;
                            q[p[s]].insert(s);
                        }
                    }
                    break;

                    //cin>>mini>>maxi;
            case 'P':
                    cin>>mini>>maxi;
                    map<int, set<string> >::iterator itlow, ithigh, temp;
                    itlow = q.lower_bound(mini);
                    ithigh = q.upper_bound(maxi);
                    for (temp=itlow; temp!=ithigh; ++temp){
                        cout<<temp->first<<" ";
                        set<string>::iterator it;
                        for (it = q[temp->first].begin(); it!= q[temp->first].end(); ++it)
                            cout<<*it<<" ";

                        cout<<endl;
                    }
                    break;
        }
        cin>>ch;
    }
        cout<<illegal<<endl;
}
