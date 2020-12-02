# include <iostream>
# include <set>
# include <map>
# include <string>
# include <cstdio>
using namespace std;

int numIllegal = 0;
map< string, int > accountBalance;
map< string, int > :: iterator accountIterator;
map< int , set< string > > accountsWithBalance;

void open(string accountName)
{
	if(accountBalance.count(accountName) == 1)	// already exists
		numIllegal++;
	else
	{
		accountBalance[accountName] = 0;
		accountsWithBalance[0].insert(accountName);
	}
}
void close(string accountName)
{
	if(accountBalance.count(accountName) == 0)	// doesn't exist
		numIllegal++;

	else
	{	
		int currAccountBalance = accountBalance[accountName];

		if(currAccountBalance != 0)		// non zero account closure
		{	
			numIllegal++;
			return;
		}

		accountsWithBalance[currAccountBalance].erase(accountName);

		if(accountsWithBalance[currAccountBalance].size() == 0)
		{
			accountsWithBalance.erase(currAccountBalance);
		}
		accountBalance.erase(accountName);
	}
}
void deposit(string accountName, int amount)
{
	if(accountBalance.count(accountName) == 0)	// doesn't exist
	{
		numIllegal++;
		return;
	}
	int currAccountBalance = accountBalance[accountName];

	accountsWithBalance[currAccountBalance].erase(accountName);
	if(accountsWithBalance[currAccountBalance].size() == 0)
	{
		accountsWithBalance.erase(currAccountBalance);
	}


	accountsWithBalance[currAccountBalance + amount].insert(accountName);
	accountBalance[accountName] += amount;
}
void withdraw(string accountName, int amount)
{
	if(accountBalance.count(accountName) == 0)	// doesn't exist
	{
		numIllegal++;
		return;
	}

	int currAccountBalance = accountBalance[accountName];

	if(currAccountBalance < amount)
	{
		numIllegal++;
		return;
	}

	accountsWithBalance[currAccountBalance].erase(accountName);

	if(accountsWithBalance[currAccountBalance].size() == 0)
	{
		accountsWithBalance.erase(currAccountBalance);
	}

	accountsWithBalance[currAccountBalance - amount].insert(accountName);
	accountBalance[accountName] -= amount;
}
void printAccounts(int ranged, int rangeu)
{	
	map< int , set< string > > :: iterator accountIteratorL;
	map< int , set< string > > :: iterator accountIteratorU;

	accountIteratorL = accountsWithBalance.lower_bound(ranged);
	accountIteratorU = accountsWithBalance.upper_bound(rangeu);

	for( ; accountIteratorL != accountIteratorU; accountIteratorL++)
	{	
		printf("%d", accountIteratorL->first);
		for(set< string > :: iterator iter = (accountIteratorL->second).begin(); iter != (accountIteratorL->second).end(); ++iter)
		{
		    cout<<" "<<*iter;
		}
		printf("\n");
	}

}

int main()
{
	char order = 'C';
	string accountName;
	int amount, ranged, rangeu;

	// taking all input 
	while(true)
	{
		scanf("%c", &order);
		if(order == 'E')
			break;

		switch(order)
		{
			case 'O':
				cin>>accountName;
				open(accountName);
				break;
			case 'C':
				cin>>accountName;
				close(accountName);
				break;
			case 'D':
				cin>>accountName;
				scanf("%d", &amount);
				deposit(accountName, amount);
				break;
			case 'W':
				cin>>accountName;
				scanf("%d", &amount);
				withdraw(accountName, amount);
				break;
			case 'P':
				scanf("%d %d", &ranged, &rangeu);
				printAccounts(ranged, rangeu);
				break;
		}
	}
	printf("%d\n", numIllegal);
	return 0;
}