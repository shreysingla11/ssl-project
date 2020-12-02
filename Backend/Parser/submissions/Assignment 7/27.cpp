#include <iostream>
#include <set>
#include <map>
using namespace std;

int main(){
	char c;
	int iCount = 0;
	string name;
	int bal, amt, l, u;
	map<int, set<string> >::iterator li, ui, z;
	set<string>::iterator si;
	map<string, int> ab; 
	map<int, set<string> > ba;
	bool flag = 1;
	while(flag){
		cin >> c;
		switch(c){
			case 'O':
				cin >> name;
				if(ab.count(name)>0){ iCount++; break;}
				ab[name] = 0;
				ba[0].insert(name);
				break;
			case 'C':
				cin >> name;
				if(ab.count(name)==0){ iCount++; break; }
				bal = ab[name];
				if(bal!=0){ iCount++; break; }
				ab.erase(name);
				ba[bal].erase(name);
				if(ba[bal].size()==0) ba.erase(bal);
				break;
			case 'P':
				cin >> l >> u;
				li = ba.lower_bound(l);
				ui = ba.upper_bound(u+1);
				for(z = li; z!=ui; ++z){
					cout << z->first << " ";
					for(si = (z->second).begin(); si!= (z->second).end(); ++si){
						cout << *si << " ";
					}
					cout << endl;
				}
				break;
			case 'D':
				cin >> name;
				cin >> amt;
				if(ab.count(name)==0){ iCount++; break; }
				bal = ab[name];
				ab[name] += amt;
				ba[bal].erase(name);
				if(ba[bal].size()==0) ba.erase(bal);
				ba[bal+amt].insert(name);
				break;
			case 'W':
				cin >> name;
				cin >> amt;
				if(ab.count(name)==0){ iCount++; break; }
				bal = ab[name];
				if(bal-amt < 0){ iCount++; break;}
				ab[name] -= amt;
				ba[bal].erase(name);
				if(ba[bal].size()==0) ba.erase(bal);
				ba[bal-amt].insert(name);
				break;
			case 'E':
				flag = 0;
				break;
			default:
				cout << "some problem" << endl;
		}
	}
	cout << iCount << endl;
} 