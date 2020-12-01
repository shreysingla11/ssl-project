#include<iostream>
#include<set>
#include<map>

using namespace std;

int main()
{

map<string, int> acc_name;
map<string, int>:: iterator it;
map<int, set<string> >acc_number;
char ch;
int count=0;
string name;
int temp=0;
int lower=0;
int upper=0;
int num;
bool flag=true;
while(1){

cin>>ch;
switch (ch){
    case 'O': cin>>name;
                it=acc_name.find(name);
                if(it != acc_name.end())
                {count ++;}
                else
                {
                acc_name[name]=0;
                acc_number[0].insert(name);
                }

            break;
    case 'C':
                cin>>name;
                it=acc_name.find(name);
                if(it != acc_name.end())
                {
                if(acc_name[name]!=0)
                    {count++;}
                else
                    {
                    set<string>::iterator it2;
                    it2=acc_number[0].find(name);
                    acc_number[0].erase(it2);
                    acc_name.erase(it);
                    }
                }
                else
                {count++;}

            break;
    case 'D':
            cin>>name;
            cin>>num;
            it=acc_name.find(name);
            if(it == acc_name.end())
            {count ++;}
            else
            {
            temp=acc_name[name];
            acc_name[name]+=num;
            set<string>::iterator it2;
            it2=acc_number[temp].find(name);
            acc_number[temp].erase(it2);
            acc_number[acc_name[name]].insert(name);
            }
            break;
    case 'W':
            cin>>name;
            cin>>num;
            it=acc_name.find(name);
            if(it == acc_name.end())
            {count ++;}
            else if(acc_name[name]-num < 0 )
            {count++;}
            else
            {
            temp=acc_name[name];
            acc_name[name]-=num;
            set<string>::iterator it2;
            it2=acc_number[temp].find(name);
            acc_number[temp].erase(it2);
            acc_number[acc_name[name]].insert(name);
            }
            break;
    case 'P':
            cin>>lower;
            cin>>upper;
            for(int i=lower;i<=upper;i++)
                {
                if(!acc_number[i].empty())
                    {
                    set<string>:: iterator it2;
                    it2=acc_number[i].begin();
                    cout<<i;
                    while(it2!=acc_number[i].end())
                        {
                        cout<<" "<<*it2;
                        it2++;
                        }
                    cout<<"\n";
                    }
                }
            break;
    case 'E':
            flag=false;
            break;

    }
if(flag==false)break;
}

cout<<count;
return 0;
}
