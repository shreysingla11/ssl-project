#include<iostream>
#include<set>
#include<map>
#include<cstring>
using namespace std;

class bankaccount{
	map< string, int> cash;
	map< int , set<string> > names;
	int countill;
	public :
	bankaccount(){
		countill = 0;
	}
	void openacc(string str);
	void closeacc(string str);
	void deposit(string str,int amount);
	void withdraw(string str,int amount);
	void print(int start,int end);
	int showcount();
};

void bankaccount::openacc(string str){
	map<string,int>::iterator it;
	map< int , set<string> >::iterator take;
	set<string>::iterator here;
	it = cash.find(str);
	if (cash.count(str)==0)
	{
		cash[str] = 0;
		take = names.find(0);
		if (take == names.end())
		{
			set<string> temp;
			set<string>::iterator near;
			near = temp.end();
			temp.insert(near,str);
			names[cash[str]] = temp;
			return ;
		}
		here = (take->second).end();
		(take->second).insert(here,str);
	}
	else
	{
		countill++;
	}
	return;
}

void bankaccount::closeacc(string str){
	map<string,int>::iterator it;
	map<int , set<string> >::iterator take;
	set<string>::iterator here;
	it = cash.find(str);
	if (it != cash.end())
	{
		if (it->second != 0)
		{
			countill++;
			return;
		}
		take = names.find(0);
		here = (take->second).find(str);
		(take->second).erase(here);
		if ((take->second).empty())
		{
			names.erase(take);
		}
		cash.erase(it);
	}
	else
	{
		countill++;
	}
	return ;
}

void bankaccount::deposit(string str,int amount){
	map<string,int>::iterator it;
	map< int , set<string> >::iterator take;
	set<string>::iterator here;
	it = cash.find(str);
	if (amount == 0)
	{
		return ;
	}
	if (it != cash.end())
	{
		here = names[it->second].find(str);
		names[it->second].erase(here);
		if (names[it->second].empty())
		{
			take = names.find(cash[str]);
			names.erase(take);
		}
		cash[str] += amount;
		take = names.find(cash[str]);
		if (take == names.end())
		{
			set<string> temp;
			set<string>::iterator near;
			near = temp.end();
			temp.insert(near,str);
			names[cash[str]] = temp;
			return ;
		}
		here = (take->second).end();
		(take->second).insert(here,str);
	}
	else
	{
		countill++;
	}
}

void bankaccount::withdraw(string str,int amount){
	map<string,int>::iterator it;
	map< int , set<string> >::iterator take;
	set<string>::iterator here;
	it = cash.find(str);
	if (amount == 0)
	{
		return ;
	}
	if (it != cash.end())
	{
		if (cash[str]<amount)
		{
			countill++;
			return;
		}
		here = names[it->second].find(str);
		names[it->second].erase(here);
		if (names[it->second].empty())
		{
			take = names.find(cash[str]);
			names.erase(take);
		}
		cash[str] -= amount;
		take = names.find(cash[str]);
		if (take == names.end())
		{
			set<string> temp;
			set<string>::iterator near;
			near = temp.end();
			temp.insert(near,str);
			names[cash[str]] = temp;
			return ;
		}
		here = (take->second).end();
		(take->second).insert(here,str);
	}
	else
	{
		countill++;
	}
}

void bankaccount::print(int start,int end){
	map< int , set<string> >::iterator it;
	map< int , set<string> >::iterator till;
	set<string>::iterator here;
	set<string>::iterator there;
	it = names.lower_bound(start);
	till = names.upper_bound(end);
	while (it != till)
	{
		here = (it->second).begin();
		there = (it->second).end();
		if (here != there)
		{
			cout<<it->first;
		}
		while (here != there)
		{
			cout<<" "<<*here;
			here++;
		}
		it++;
		cout<<endl;
	}
}

int bankaccount::showcount(){
	return countill;
}


int main()
{
	char op;
	string str;
	int amount,start,end;
	bankaccount element;
	while (true)
	{
		cin>>op;
		if (op == 'O')
		{
			cin>>str;
			element.openacc(str);
		}
		else if (op == 'C')
		{
			cin>>str;
			element.closeacc(str);
		}
		else if (op == 'W')
		{
			cin>>str;
			cin>>amount;
			element.withdraw(str,amount);
		}
		else if (op == 'D')
		{
			cin>>str;
			cin>>amount;
			element.deposit(str,amount);
		}
		else if (op == 'P')
		{
			cin>>start>>end;
			element.print(start,end);
		}
		else
		{
			break;
		}
	}
	cout<<element.showcount()<<endl;
	return 0;
}
