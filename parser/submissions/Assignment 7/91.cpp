#include <iostream>
#include <set>
#include <map>
#include <string>

using namespace std;

int main() {
	int illegal = 0;
	map<string, int> m;
	map<int, set<string> > ms;
	map<string, int>::iterator mit;
	map<int, set<string> >::iterator msit;
	set<string>::iterator sit;
	int l, k;

	string temp;
	
	while(true) {
		cin>>temp;
		if (temp=="O") {
			cin>>temp;
			mit = m.find(temp);
			if (mit != m.end()) {
				illegal++;
			}
			else {
				m[temp] = 0;
				(ms[0]).insert(temp);
			}
		}
		else if (temp=="C") {
			cin>>temp;
			mit = m.find(temp);
			if (mit == m.end()) {
				illegal++;
			}
			else if (mit->second != 0) {
				illegal++;
			}
			else {
				m.erase(mit);
				msit = ms.find(0);
				msit->second.erase(temp);
				if((msit->second.empty())) {
					ms.erase(msit);
				}
			}
		}
		else if (temp=="D") {
			cin>>temp;
			cin>>l;
			mit = m.find(temp);
			if (mit == m.end()) {
				illegal++;
			}
			else {
				msit = ms.find(mit->second);
				msit->second.erase(temp);
				if((msit->second.empty())) {
					ms.erase(msit);
				}
				(*mit).second += l;
				(ms[mit->second]).insert(temp);
			}
		}
		else if (temp=="W") {
			cin>>temp;
			cin>>l;
			mit = m.find(temp);
			if (mit == m.end()) {
				illegal++;
			}
			else if (mit->second < l) {
				illegal++;
			}
			else {
				msit = ms.find(mit->second);
				msit->second.erase(temp);
				if((msit->second.empty())) {
					ms.erase(msit);
				}
				(*mit).second -= l;
				(ms[mit->second]).insert(temp);
			}
		}
		else if (temp=="P") {
			cin>>l>>k;
			msit = ms.lower_bound(l);
			for ( ; msit != ms.end(); msit++) {
				if (msit->first > k) {
					break;
				}
				if (!(msit->second.empty())) {
					cout<<msit->first;
					for (sit = msit->second.begin(); sit != msit->second.end(); sit++ ) {
						cout<<" "<<*sit;
					}
					cout<<endl;
				}
			}
		}
		else if (temp=="E") {
			break;
		}
	}

	cout<<illegal<<endl;
	return 0;
}