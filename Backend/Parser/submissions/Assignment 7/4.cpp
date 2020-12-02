#include <iostream>
#include <map>
#include <set>
#include <cstdio>
using namespace std;

std::map<string, int> m;
std::map<int, set<string> > invm;
int errors;

void deposit(string name, int amount);
void withdraw(string name, int amount);
void open(string name);
void close(string name);
void print(int start, int end);
void add_to_set(int amount, string name);
void delete_from_set(int amount, string name);
int main()
{
	errors=0;
	char c;
	string s;
	int r;
	while(true)
	{
		cin>>c;
		switch(c)
		{
			case 'O' :	cin>>s;
						open(s);
						break;
			case 'C' :  cin>>s;
						close(s);
						break;
			case 'D' :  cin>>s;
						scanf("%d",&r);
						deposit(s,r);
						break;
			case 'W' :  cin>>s;
						scanf("%d",&r);
						withdraw(s,r);
						break;
			case 'P' :  scanf("%d",&r);
						int temp;
						scanf("%d",&temp);
						print(r,temp);
						break;
			default :   cout<<errors<<endl;
                        return 0;

		}
	}
	cout<<errors<<endl;
	return 0;
}

void open(string name)
{
	if(m.find(name) == m.end())
	{
		m[name] = 0;
		add_to_set(0, name);
	}
	else errors++;
}

void close(string name)
{
	map<string, int>::iterator it = m.find(name);
	if(it != m.end() && it->second == 0)
	{
		delete_from_set(m[name], name);
		m.erase(name);
	}
	else errors++;
}

void deposit(string name, int amount)
{
	map<string, int>::iterator it = m.find(name);
	if(it != m.end())
	{
		delete_from_set(it->second, name);
		it->second = it->second + amount;
		add_to_set(it->second, name);
	}
	else errors++;
}

void withdraw(string name, int amount)
{
	map<string, int>::iterator it = m.find(name);
	if(it != m.end() && it->second>=amount)
	{
		delete_from_set(it->second, name);
		it->second = it->second - amount;		//check fo -ve balance
		add_to_set(it->second, name);
	}
	else errors++;
}

void print(int start, int end)
{
	map<int, set<string> >::iterator it1 = invm.lower_bound(start);
	map<int, set<string> >::iterator it2 = invm.upper_bound(end);
	set<string>::iterator itset;
	for(; it1 != it2 ; it1++)
	{
		cout<<it1->first;
		for(itset=(it1->second).begin(); itset!=(it1->second).end(); itset++)
		{
			cout<<" "<<(*itset);
		}
		cout<<endl;
	}
}

void add_to_set(int amount, string name)
{
	invm[amount].insert(name);			// ? in case key doesn't exist
}

void delete_from_set(int amount, string name)
{
	map<int, set<string> >::iterator it = invm.find(amount);
	if(it != invm.end())
	{
		(it->second).erase(name);
		if ((it->second).empty())
		invm.erase(amount);
	}
}
