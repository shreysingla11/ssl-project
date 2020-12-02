#include <iostream>
#include <set>
#include <map>
#include <string>
using namespace std;
class account
{
	map<string, int> name;
	map<int, set<string> > balance;
	int invalid;
public:
	account()
	{
		invalid = 0;
	}
	void open(string &s)
	{
		if (name.find(s) != name.end())
		{
			++invalid;
			return;
		}
		name[s] = 0;
		balance[0].insert(s);
	}
	void close(string &s)
	{
		if (name.find(s) == name.end())
		{
			++invalid;
			return;
		}
		if (name[s] != 0)
		{
			++invalid;
			return;
		}
		balance[name[s]].erase(s);
		if (balance[name[s]].empty())
		{
			balance.erase(name[s]);
		}
		name.erase(s);
	}
	void deposit(string &s, int &value)
	{
		if (name.find(s) == name.end())
		{
			++invalid;
			return;
		}
		int newval = value+name[s];
		balance[name[s]].erase(s);
		if (balance[name[s]].empty())
		{
			balance.erase(name[s]);
		}
		balance[newval].insert(s);
		name[s] = newval;
	}
	void withdraw(string &s, int &value)
	{
		if (name.find(s) == name.end())
		{
			++invalid;
			return;
		}
		int newval = name[s]-value;
		if (newval < 0)
		{
			++invalid;
			return;
		}
		balance[name[s]].erase(s);
		if (balance[name[s]].empty())
		{
			balance.erase(name[s]);
		}
		balance[newval].insert(s);
		name[s] = newval;
	}
	void print(int &low, int &high)
	{
		map<int, set<string> > :: iterator it;
		set<string> :: iterator setit;
		it = balance.lower_bound(low);
		if (it == balance.end())
		{
			return;
		}
		while (it->first <= high)
		{
			cout << it->first;
			for (setit = (it->second).begin(); setit != (it->second).end(); ++setit)
			{
				cout << " " << *setit;
			}		
			cout << endl;		
			++it;
			if (it == balance.end())
				break;
		}
	}
	int retInvalid()
	{
		return invalid;
	}
};
int main()
{
	account A;
	string s;
	char ch;
	int val1, val2;
	cin >> ch;
	while (ch != 'E')
	{	
		switch(ch)
		{
			case 'O': 
				cin >> s;
				A.open(s);
				break;
			case 'C': 
				cin >> s;
				A.close(s);
				break;
			case 'D': 
				cin >> s >> val1;
				A.deposit(s, val1);
				break;
			case 'W': 
				cin >> s >> val1;
				A.withdraw(s, val1);
				break;
			case 'P': 
				cin >> val1 >> val2;
				A.print(val1, val2);
				break;
		}
		cin >> ch;
	}
	cout << A.retInvalid() << endl;
	return 0;
}