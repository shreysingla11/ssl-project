#include<iostream>
#include<stdio.h>
#include<set>
#include<map>
#include<string.h>
#include<cstdlib>

using namespace std;



int main(){
    string name;
    int bal;
    int amt;
    int illegal=0;
    int first,last;
    int i=0;
    set<string>::iterator it;
    map<string,int> a;
    map<int,set<string> > b;
    char ch;
    while(1){
    cin>>ch;
    switch(ch){
    case 'O':
        bal = 0;
        cin>>name;
        if(a.find(name) != a.end()){
            illegal++;
        }
        else{
        a.insert(pair<string,int> (name,bal));
        b[a[name]].insert(name);
        }
        break;

    case 'C':
        cin>>name;
        if((a.find(name) != a.end()) && (a[name]==0)){
        b[a[name]].erase(name);
        a.erase(name);
        }
        else{
        illegal++;
        }
        break;

    case 'D':
        cin>>name;
        cin>>amt;
        if(a.find(name) != a.end()){
            a[name]=a[name]+amt;
            b[a[name]].insert(name);
            b[a[name]-amt].erase(name);

        }
        else{
            illegal++;
        }
        break;

    case 'W':
        cin>>name;
        cin>>amt;
        if((a.find(name) != a.end()) && (amt>a[name])){
            illegal++;
        }
        else{
            a[name]=a[name]-amt;
            b[a[name]].insert(name);
            b[a[name]+amt].erase(name);
        }
        break;

    case 'P':
        cin>>first;
        cin>>last;

        if((i>=first) && (i<=last)){
            it = b[i].begin();
            it++;
            cout<<*it<< " "<<a[*it]<<endl;
        }
        break;

    case 'E':
        cout<<illegal<<endl;
        exit(1);

    default:
        cout<<"Invalid Operation"<<endl;

}
}



return 0;
}








