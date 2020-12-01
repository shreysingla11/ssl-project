#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <string>
using namespace std;

void open(string account,map<string,int> &balance,map<int, set<string> > &accountMap,set<int> &sortedBalance,set<string> &accountNames,int &invalid)
{
	if(accountNames.count(account)!=0)
	{
		invalid++;
		return;
	}
	else
	{
		accountNames.insert(account);
		balance[account]=0;
		sortedBalance.insert(0);
		accountMap[0].insert(account);
	}
}

void close(string account,map<string,int> &balance,map<int, set<string> > &accountMap,set<int> &sortedBalance,set<string> &accountNames,int &invalid)
{
	if(accountNames.count(account)!=0)
	{
		invalid++;
		return;
	}
	else if (balance[account]!=0)
	{
		invalid++;
		return;
	}
	else
	{
		if(accountMap[0].size()==1)
		{
			accountMap.erase(0);
			sortedBalance.erase(0);

		}
		else
		{
			accountMap[0].erase(account);
		}
		balance.erase(account);
		accountNames.erase(account);
	}
}

void deposit(string account,int amount,map<string,int> &balance,map<int, set<string> > &accountMap,set<int> &sortedBalance,set<string> &accountNames,int &invalid)
{
	if(accountNames.count(account)==0)
	{
		invalid++;
		return;
	}
	else
	{
		if(accountMap[balance[account]].size()==1)
		{
			sortedBalance.erase(balance[account]);
			accountMap.erase(balance[account]);
		}
		else
		{
			accountMap[balance[account]].erase(account);
		}
		balance[account]=balance[account]+amount;
		sortedBalance.insert(balance[account]);
		accountMap[balance[account]].insert(account);
		return;
	}
}

void withdraw(string account,int &amount,map<string,int> &balance,map<int, set<string> > &accountMap,set<int> &sortedBalance,set<string> &accountNames,int &invalid)
{
	if(accountNames.count(account)==0)
	{
		invalid++;
		return;
	}
	else if (balance[account]<amount)
	{
		invalid++;
		return;
	}
	else
	{
		if(accountMap[balance[account]].size()==1)
		{
			sortedBalance.erase(balance[account]);
			accountMap.erase(balance[account]);
		}
		else
		{
			accountMap[balance[account]].erase(account);
		}
		balance[account]=balance[account]-amount;
		sortedBalance.insert(balance[account]);
		accountMap[balance[account]].insert(account);
		return;
	}
}

void print (int start,int end,map<int, set<string> > &accountMap,set<int> &sortedBalance)
{
	set<int>::iterator it=sortedBalance.lower_bound(start);
    set<int>::iterator it1=sortedBalance.upper_bound(end);
	set<string>::iterator it2;
	while(it!=it1)
	{
		it2 = accountMap[*it].begin();
		cout<<*it;
		for(;it2!=accountMap[*it].end();++it2)
		{
			cout<<" "<<*it2;
		}
		cout<<endl;

		++it;
		if(it==sortedBalance.end())
		{
			return;
		}
	}
}

int main()
{
	char letter;
	string input;
	map<string,int> balance ;
	map<int, set<string> > accountMap;
	set<int> sortedBalance;
	set<string> accountNames;
	int invalid=0,n1=0,n2=0;
	while(1)
	{
		cin>>letter;
		if((letter=='E')||(letter=='e'))
		{
			cout<<invalid<<endl;
			break;
		}
		else if(letter=='O')
		{
			cin>>input;
			open(input,balance,accountMap,sortedBalance,accountNames,invalid);
		}
		else if(letter=='C')
		{
			cin>>input;
			close(input,balance,accountMap,sortedBalance,accountNames,invalid);
		}
		else if(letter=='W')
		{
			cin>>input>>n1;
			withdraw(input,n1,balance,accountMap,sortedBalance,accountNames,invalid);
		}
		else if(letter=='D')
		{
			cin>>input>>n1;
			deposit(input,n1,balance,accountMap,sortedBalance,accountNames,invalid);
		}
		else if(letter=='P')
		{
			cin>>n1>>n2;
			print(n1,n2,accountMap,sortedBalance);
		}
	}
	return 0;

}
