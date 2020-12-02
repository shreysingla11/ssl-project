#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

class Bank {
public:
	map<string, int> accounts;
	map<int, set<string> > balance;
	int invalid_op;

	Bank(){
		invalid_op = 0;
	}

	void open(const string &s) {
		if(accounts.find(s) != accounts.end()) {
			invalid_op++;
		}
		else {
			accounts[s] = 0;
			balance[0].insert(s);
		}
	}

	void close(const string &s) {
		if(accounts.find(s) == accounts.end()) {
			invalid_op++;
		}
		else if(accounts[s] > 0) {
			invalid_op++;
		}
		else {
			accounts.erase(s);
			balance[0].erase(s);
			if(balance[0].empty())
				balance.erase(0);
		}
	}

	void deposit(const string &s, const int &amount) {
		if(accounts.find(s) == accounts.end()) {
			invalid_op++;
		}
		else {
			balance[accounts[s]].erase(s);
			if(balance[accounts[s]].empty())
				balance.erase(accounts[s]);
			balance[accounts[s] + amount].insert(s);
			accounts[s] += amount;
		}
	}

	void withdraw(const string &s, const int &amount) {
		if(accounts.find(s) == accounts.end()) {
			invalid_op++;
		}
		else if(amount > accounts[s]) {
			invalid_op++;
		}
		else {
			balance[accounts[s]].erase(s);
			if(balance[accounts[s]].empty())
				balance.erase(accounts[s]);
			balance[accounts[s] - amount].insert(s);
			accounts[s] -= amount;
		}
	}

	void print(const int &a, const int &b) {
		map<int, set<string> >::iterator it = balance.lower_bound(a);
		if(it == balance.end()) {
			return;
		}
		else {
			while(it->first <= b) {
				cout << it->first;
				for(set<string>::iterator it2 = (it->second).begin();
					it2 != (it->second).end(); it2++) {
					cout << " " << *it2;
				}
				cout << endl;
				it++;
				if(it == balance.end())
					return;
			}
		}
	}
}; //Bank

int main() {
	Bank bank;
	while(1) {
		char s;
		cin >> s;

		if(s == 'E')
			break;

		else if(s == 'O') {
			string s;
			cin >> s;
			bank.open(s);
		}

		else if(s == 'C') {
			string s;
			cin >> s;
			bank.close(s);
		}

		else if(s == 'D') {
			string s;
			int amt;
			cin >> s >> amt;
			bank.deposit(s, amt);
		}

		else if(s == 'W') {
			string s;
			int amt;
			cin >> s >> amt;
			bank.withdraw(s, amt);
		}

		else if(s == 'P') {
			int a, b;
			cin >> a >> b;
			bank.print(a, b);
		}
	}

	cout << bank.invalid_op << endl;

} // int main()
