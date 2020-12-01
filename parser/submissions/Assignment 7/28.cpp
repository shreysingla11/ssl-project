#include<iostream>
#include<cstdio>
#include<map>
#include<set>
#include<vector>
#include<iterator>
using namespace std;

class bank
{
public:
	map<string,int> m;
	map<int,set<string> >p;
	map<int,set<string> >::iterator it1;
	map<string,int>::iterator it;
	int error;
	bank()
	{
	error=0;
	}

	void open(string s);
	void deposit(string s,int n);
	void withdraw(string s,int n);
	void close(string s);
	void print(int min,int max);
};

struct ltstr
{
  bool operator()(int s1, int s2)
  {
    return (s1<=s2);
  }
};

int main()
{
	bank b;
	char  ch;
	string name;
	int bal,min,max;
	while(true)
    {
        cin>>ch;
        switch (ch)
        {
            case 'O' :cin>>name;
            b.open(name);
            break;
            case 'C' :cin>>name;
            b.close(name);
            break;
            case 'D' :cin>>name>>bal;
            b.deposit(name,bal);
            break;
            case 'W' :cin>>name>>bal;
            b.withdraw(name,bal);
            break;
            case 'P' :cin>>min>>max;
            b.print(min,max);
            break;
            case 'E' :cout<<b.error;
            return 0;
            break;
        }
    }
}


void bank::open(string s)
{
	if (m.find(s)==m.end())					//if not already present add account
	{
		m[s]=0;
		p[0].insert(s);
	}
	else
	{
		error++;
	}
}

void bank::close(string s)
{

	it = m.find(s);
    if (it != m.end())						//if present
    {
    	if(m[s]==0)
    	{
    		m.erase (it);
    		p[0].erase(s);
    		if(p[0].size()==0)
			p.erase(m[s]);
    	}
    	else								//Balance !=0
    	{
    		error++;
    	}
    }
    else									//Not present
    {
    	error++;
    }
}


	void bank::deposit(string s,int n)
	{

		if(m.find(s)!=m.end())				//Account already exists
		{
			p[m[s]].erase(s);
			if(p[m[s]].size()==0)
			p.erase(m[s]);
			m[s]=m[s]+n;
			p[m[s]].insert(s);

		}
		else
		{
			error++;
		}
	}
	void bank::withdraw(string s,int n)
	{
		if(m.find(s)!=m.end())				//Account exists
		{
			if(m[s]>=n)
			{
				p[m[s]].erase(s);
				if(p[m[s]].size()==0)
                p.erase(m[s]);
				m[s]=m[s]-n;
				p[m[s]].insert(s);
			}
			else							//Balance not sufficient
			{
				error++;
			}
		}

		else				//Account not present
		{
			error++;
		}
	}

	void bank::print(int min,int max)
	{
		it1=p.begin();
		while(it1!=p.end())
		{
			if(it1->first >=min&& it1->first<=max)
			{
				cout<<it1->first<<" ";
				copy(it1->second.begin(), it1->second.end(), ostream_iterator<string>(cout, " "));
				cout<<endl;
				it1++;
			}
		}
	}
