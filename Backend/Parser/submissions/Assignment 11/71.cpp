#include <iostream>
#include <cstdio>
#include <algorithm>
#include <unordered_map>
#include <bitset>

using namespace std;

bitset<45> of_char(char x) {
	int num = x - 'a';
	bitset<5> b(num);
	bitset<45> c;
	for (int i = 0; i < 45; i++) {
		c[i] = b[i / 9];
	}
	return c;
}

void generate_data(unordered_map<long long int, char> &data, bitset<45> curr, int iter, int count, char x) {
	if(data.find(curr.to_ullong()) == data.end())
		data[curr.to_ullong()] = x;

	if(count == 0) {
		return;
	}
	else if (iter == 44) {
		curr[iter] = 1 - curr[iter];
		count--;
		data[curr.to_ullong()] = x;
		return;
	}
	else {
		generate_data(data, curr, iter+1, count, x);
		curr[iter] = 1 - curr[iter];
		count--;
		generate_data(data, curr, iter+1, count, x);
	}
	return;
}

int main() {
	unordered_map<long long int, char> data;
	unordered_map<long long int, char>::iterator iter;
	
	long long int curr;
	bitset<45> temp;

	for(int i = 0; i < 26; i++) {
		temp = of_char('a' + i);
		generate_data(data, temp, 0, 4, 'a' + i);
	}

	int n;
	scanf("%d", &n);

	for(int i = 0; i < n; i++) {
		scanf("%lld", &curr);
		iter = data.find(curr);
		if (iter != data.end()) {
			printf("%c", iter->second);
		} else {
			printf("?");
		}
	}

	return 0;
}
