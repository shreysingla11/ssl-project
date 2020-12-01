#include <iostream>
#include <string>

using namespace std;

void update_curr_block(string &s, int a, int b, int c, int d, int &minindex, int &minlength) {
	int i = a, j = c;
	int n = s.length();
	while(1) {
		if(i == 0 && i == a) {
			break;
		}
		if(i == 0 && i != a) {
			if(s[i] == s[j]) {
				break;
			}
			else {
				i++;
				j++;
				break;
			}
		}
		if(s[i] == s[j]) {
			i--;
			j--;
		}
		else {
			i++;
			j++;
			break;
		}
	}
	int p = b, q = d;
	//cout << p << " " << q <<endl;
	while(p < j - 1) {
		if(q == n - 1 && q == d) {
			break;
		}
		if(q == n - 1 && q != d) {
			if(s[p] == s[q]) {
				break;
			}
			else {
				q--;
				p--;
				break;
			}
		}
		if(s[p] == s[q]) {
			p++;
			q++;
		}
		else {
			p--;
			q--;
			break;
		}
	}
	if(p == j -1) {
		if(s[p] != s[q]) {
			q--;
			p--;
		}
	}
	//cout << p << " " << q <<endl;
	if(p == j -1 && j-i == q-p) {
		int length = j-i;
		int index = i;
		if(length < minlength) {
			//cout << a << " " << b << " " << c << " " << d << endl;
			//cout << i << " " << p << " " << j << " " << q << endl;
			minlength = length;
			minindex = index;
		}
	}
	return;
}


int main() {
	string s;
	cin >> s;
	int minindex, minlength = s.length()+1;
	int n = s.length();
	for(int l = 1; l < n; l = l * 2) {
		for(int block_start = 0; block_start < n - l; block_start = block_start + l) {
			for(int k = block_start, j = block_start + 2*l - 1; 
				j <= block_start + 4*l - 2 && k < block_start + l && k < n;) {
				if(s[k] == s[j]) {
					k++;
					j++;
				}
				else {
					if(k == block_start) {
						j++;
					}
					else {
						k = block_start;
					}
				}
				if(k == block_start + l) {
					update_curr_block(s, block_start, block_start + l - 1, j - l, j - 1, minindex, minlength);
					// cout << "Match " << block_start << " " <<  block_start + l - 1 << 
					// 	" " << j - l << " " << j - 1<<endl;
					k = 0;
					j++;
				}			
			}
		}
	}
	if(minlength == s.length() + 1)
		cout << 0 << " " << 0 <<endl;
	else
		cout << minlength << " " << minindex <<endl;
	return 0;
}