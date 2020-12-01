#include <iostream>
#include <map>
#include <set>
using namespace std;

int main() {

	// your code goes here
	map<string, int> nam_bal_map;
	map<string, int>::iterator nam_bal_it;
	map<int, set<string>> bal_nam_map;
	map<int, set<string>>::iterator bal_nam_it;

	// O,C,D,W,P
	
	string action, acc_name;
	int amount, low_bound, up_bound;
	int ill_count = 0;
	
	cin >> action;
	while(action != ""){
		if(action == "O"){
			cin >> acc_name;
			nam_bal_it = nam_bal_map.find(acc_name);
			if(nam_bal_it != nam_bal_map.end()){
				// Account already exists. Ignore input.
				ill_count++;
			}
			else{
				nam_bal_map[acc_name] = 0; // Open with zero balance.
				bal_nam_it = bal_nam_map.find(0);
				if(bal_nam_it == bal_nam_map.end()){
					// New account entry with zero balance.
					set<string> temp_set;
					temp_set.insert(acc_name);
					bal_nam_map[0] = temp_set;
				}
				else{
					// Enter in already existing set.
					bal_nam_it->second.insert(acc_name);
				}
			}
		}
		else if(action == "C"){
			cin >> acc_name;
			nam_bal_it = nam_bal_map.find(acc_name);
			if(nam_bal_it == nam_bal_map.end() || nam_bal_it->second>0){
				// Account doesn't exist or exists with non-zero balance.
				ill_count++;
			}
			else{
				// Closing account.
				nam_bal_map.erase(nam_bal_it);
				bal_nam_it = bal_nam_map.find(0);
				if(bal_nam_it->second.size() > 1){
					bal_nam_it->second.erase(acc_name);
				}
				else{
					bal_nam_map.erase(bal_nam_it);
				}
			}
		}
		else if(action == "D"){
			cin >> acc_name;
			cin >> amount;
			nam_bal_it = nam_bal_map.find(acc_name);
			if(nam_bal_it == nam_bal_map.end()){
				// Account doesn't exist. Illegal operation.
				ill_count++;
			}
			else{
				int temp = nam_bal_it->second;
				nam_bal_it->second += amount;
				bal_nam_it = bal_nam_map.find(temp);
				if(bal_nam_it->second.size() > 1){
					bal_nam_it->second.erase(acc_name);
				}
				else{
					bal_nam_map.erase(bal_nam_it);
				}
				bal_nam_it = bal_nam_map.find(temp+amount);
				if(bal_nam_it == bal_nam_map.end()){
					// New account entry with that balance.
					set<string> temp_set;
					temp_set.insert(acc_name);
					bal_nam_map[temp+amount] = temp_set;
				}
				else{
					// Enter in already existing set.
					bal_nam_it->second.insert(acc_name);
				}
			}
		}
		else if(action == "W"){
			cin >> acc_name;
			cin >> amount;
			nam_bal_it = nam_bal_map.find(acc_name);
			if(nam_bal_it == nam_bal_map.end() || nam_bal_it->second<amount){
				// Account doesn't exist or doesn't have enough balance.
				ill_count++;
			}
			else{
				int temp = nam_bal_it->second;
				nam_bal_it->second -= amount;
				bal_nam_it = bal_nam_map.find(temp);
				if(bal_nam_it->second.size() > 1){
					bal_nam_it->second.erase(acc_name);
				}
				else{
					bal_nam_map.erase(bal_nam_it);
				}
				bal_nam_it = bal_nam_map.find(temp-amount);
				if(bal_nam_it == bal_nam_map.end()){
					// New account entry with that balance.
					set<string> temp_set;
					temp_set.insert(acc_name);
					bal_nam_map[temp-amount] = temp_set;
				}
				else{
					// Enter in already existing set.
					bal_nam_it->second.insert(acc_name);
				}
			}
		}
		else if(action == "P"){
			cin >> low_bound;
			cin >> up_bound;
			map<int, set<string>>::iterator bal_nam_low = bal_nam_map.find(low_bound);
			map<int, set<string>>::iterator bal_nam_up = bal_nam_map.find(up_bound);
			for(bal_nam_it = bal_nam_low; bal_nam_it != bal_nam_up; ++bal_nam_it){
				set<string>::iterator set_it;
				string answer = "";
				for(set_it = bal_nam_it->second.begin(); set_it != bal_nam_it->second.end(); ++set_it){
					answer += " ";
					answer += *set_it;
				}
				cout << bal_nam_it->first << answer << endl;
			}
		}
		action = "";
		acc_name = "";
		cin >> action;
		if(action == "E") break;
	}

	cout << ill_count << endl;
	return 0;
}