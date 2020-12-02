#include <iostream>
#include <map>
#include <set>
#include <string>
std::map<std::string, int> balance;
std::map<int, std::set<std::string> > cust;
void deposit(std::string name, int amount);
void withdraw(std::string name, int amount);
void open(std::string name);
void close(std::string name);
void print(int start, int ends);
int illegal=0;
using namespace std;
int main()
{
	char input;
	string name_input;
	int amount_input,start_input,end_input;
	bool flag=true;
	while(flag)
	{
		cin>>input;
		switch(input)
		{
		case 'D' :
		{
			cin>>name_input>>amount_input;
			deposit(name_input,amount_input);
			break;
		}
		case 'W' :
		{
			cin>>name_input>>amount_input;
			withdraw(name_input,amount_input);
			break;
		}
		case 'O' :
		{
			cin>>name_input;
			open(name_input);
			break;
		}
		case 'C' :
		{
			cin>>name_input;
			close(name_input);
			break;
		}
		case 'P' :
		{
			cin>>start_input>>end_input;
			print(start_input,end_input);
			break;
		}
		case 'E' :
		{
			flag=false;
			break;
		}
		}
	}
	cout<<illegal<<endl;
	return 0;
}

void deposit(string name, int amount)
{
	map<string, int> :: iterator cust_name;
	std::map<int, std::set<std::string> > :: iterator bal_it;
	cust_name=balance.find(name);
	if(cust_name==balance.end())
	{
		illegal++;
		return;
	}
	else
	{
		cust[cust_name->second].erase(name);
		if(cust[cust_name->second].empty())
		{
			bal_it=cust.find(cust_name->second);
			cust.erase(bal_it);
		}
		balance[name]+=amount;
        cust[cust_name->second].insert(name);
	}
	return;
}

void withdraw(string name, int amount)
{
	map<string, int> :: iterator cust_name;
	std::map<int, std::set<std::string> > :: iterator bal_it;
	cust_name=balance.find(name);
	if(cust_name==balance.end())
	{
		illegal++;
		return;
	}
	else
	{

		if(balance[name] >= amount)
		{
			cust[cust_name->second].erase(name);
			if(cust[cust_name->second].empty())
			{
				bal_it=cust.find(cust_name->second);
				cust.erase(bal_it);
			}
			balance[name]-=amount;
			cust[cust_name->second].insert(name);
		}
		else
		{
			illegal++;
			return;
		}
	}
	return;
}

void open(string name)
{
	map<string, int> :: iterator cust_name;
	cust_name=balance.find(name);
	if(cust_name!=balance.end())
	{
		illegal++;
		return;
	}
	else
	{
		balance[name]=0;
		cust[0].insert(name);
	}
	return;
}

void close(string name)
{
	map<string, int> :: iterator cust_name;
	std::map<int, std::set<std::string> > :: iterator bal_it;
	cust_name=balance.find(name);
	if(cust_name==balance.end())
	{
		illegal++;
		return;
	}
	else
	{
		if(balance[name]==0)
		{
			cust[cust_name->second].erase(name);
			if(cust[cust_name->second].empty())
			{
				bal_it=cust.find(cust_name->second);
				cust.erase(bal_it);
			}
			balance.erase(cust_name);
		}
		else
		{
			illegal++;
			return;
		}
	}
	return;
}

void print(int start, int ends)
{
	std::set<std::string> :: iterator temp;
	std::map<int, std::set<std::string> > :: iterator it_low,it_high,it;
	it_low=cust.lower_bound(start);
	it_high=cust.upper_bound(ends);
	for(it=it_low;it!=it_high;it++)
	{
		cout<<it->first;
		for(temp=it->second.begin();temp!=it->second.end();temp++)
			cout<<" "<<*temp;
		cout<<endl;
	}
	return;
}
