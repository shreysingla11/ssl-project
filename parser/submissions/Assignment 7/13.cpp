#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<sstream>
using namespace std;
vector<string> st;
string temp;
vector<string>::iterator it;
class bank
{
map<string,int> acname;
map<int, set<string> > range;
int iocount;

public:

void open(string s);
void close(string s);
int deposit(string s,int i);
int withdraw(string s,int i);
void print(int x, int y);
void illegaloperations();
bank();
};

bank::bank()
{
    iocount=0;
}

void bank::illegaloperations()
{
if (iocount==0) {cout<<iocount;}
else cout<<--iocount<<endl;

}


void bank::open(string s)
{
if (acname.count(s)==1)
{iocount=iocount+1;}
else
 {
 acname[s]=0;
 range[0].insert(s);
 }

}

void bank::close(string s)
{
if(acname.count(s)==0 || acname[s]!=0)
{
iocount=iocount+1;
}
else
{
acname.erase(s);
range[0].erase(s);
}
}

int bank::deposit(string s, int i)
{
if(acname.count(s)==0)
{
iocount=iocount+1;
}
else
{
range[acname[s]].erase(s);
acname[s]=acname[s]+i;
range[acname[s]].insert(s);
}

}
int bank::withdraw(string s, int i)
{
if(acname.count(s)==0 || acname[s]<i)
{
iocount=iocount+1;
}
else
{
range[acname[s]].erase(s);
acname[s]=acname[s]-i;
range[acname[s]].insert(s);
}

}

void bank::print(int x, int y)
{
map<int, set<string> >:: iterator low;
map<int, set<string> >:: iterator high;
map<int, set<string> >:: iterator presnt;
set<string>:: iterator currstr;
low=range.lower_bound(x);
high=range.lower_bound(y);

for(presnt=low;presnt!=high;presnt++)
{
stringstream convert;
convert << presnt->first;
temp=convert.str();
st.push_back(temp);
for(currstr=(presnt)->second.begin();currstr!=presnt->second.end();currstr++)
{
it=st.end();
it--;
*(it)+=" ";

*(it)+=*(currstr);

}

}



}


int main()
{
bank canara;
string name; char x; int n,i,j;
while(cin)
{
cin>>x;
if(x=='O')
{
cin>>name;
canara.open(name);
}
if(x=='C')
{
cin>>name;
canara.close(name);
}
if(x=='D')
{
cin>>name>>n;
canara.deposit(name,n);
}
if(x=='W')
{
cin>>name>>n;
canara.withdraw(name,n);
}
if(x=='P')
{
cin>>i>>j;
canara.print(i,j);
}
if(x=='E'){break;}

}

for(vector<string>::iterator it=st.begin();it!=st.end();it++){cout<<*it<<endl;}

canara.illegaloperations();

return 0;

}
