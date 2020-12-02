#include <iostream>
#include <string>
#include <unordered_map>
#include <bitset>

using namespace std;

// long long convert(string )

bitset<45> generateBits(char c) {
	int i = c - 'a';
	bitset<5> cBits(i);
	string s = cBits.to_string();
	string t = "";
	for (int i=0; i<s.length(); i++) {
		for(int j=0; j<9; j++) {
			t+=s[i];
		}
	}
	bitset<45> newBits(t); 
	return newBits;
}

int main() {
	ios_base::sync_with_stdio(0);
	unordered_map<unsigned long long, char> myhash;
	
	for(char c = 'a'; c<='z'; c++) {
		bitset<45> currBits(generateBits(c));
		bitset<45> temp = currBits;

		for (int i=0; i<45; i++) {
			temp.flip(i);
			for(int j=i+1; j<45; j++) {
				temp.flip(j);
				for(int k=j+1; k<45; k++) {
					temp.flip(k);
					for(int l=k+1; l<45; l++) {
						temp.flip(l);
						myhash[temp.to_ullong()] = c;
						temp.flip(l);
					}
					temp.flip(k);
				}
				temp.flip(j);
			}
			temp.flip(i);
		}
		for (int i=0; i<45; i++) {
			temp.flip(i);
			for(int j=i+1; j<45; j++) {
				temp.flip(j);
				for(int k=j+1; k<45; k++) {					
					temp.flip(k);
					myhash[temp.to_ullong()] = c;
					temp.flip(k);
				}
				temp.flip(j);
			}
			temp.flip(i);
		}
		for (int i=0; i<45; i++) {
			temp.flip(i);
			for(int j=i+1; j<45; j++) {
				temp.flip(j);
				myhash[temp.to_ullong()] = c;
				temp.flip(j);
			}
			temp.flip(i);
		}
		for (int i=0; i<45; i++) {
			temp.flip(i);
			myhash[temp.to_ullong()] = c;
			temp.flip(i);
		}
		myhash[currBits.to_ullong()] = c;

	}

	int n;
	cin>>n; 
	unsigned long long in;
	for(int i=0; i<n; i++) {
		cin>>in;
		unordered_map<unsigned long long, char>::iterator it = myhash.find(in);
		if (it!=myhash.end()) {
			cout<<it->second;
		}
		else {
			cout<<'?';
		}
	}
	cout<<endl;



	return 0;
}