#include <iostream>
#include <bitset>
#include <algorithm>
#include <unordered_map>
#include <cstdio>

using namespace std;


unordered_map< long long int , char> myMap;

bitset<45> char_to_bitset(char c) {
	long long int k = c - 'a';
	bitset<5> b1(k);
	bitset<45> b2(0);
	for(int i=0; i<5; i++) {
		for(int j=0;j<9;j++){
			b2[i*9 + j] = b1[i];
		}
	}
	return b2;
}

void corrupt_string_store(char c, bitset<45> s, int start, int allowed_errors) {
	
	long long int a = s.to_ullong();
	myMap[a] = c;

	if(allowed_errors == 0) {
		return;
	}
	if(start == 44){
		s.flip(start);
		a = s.to_ullong();
		myMap[a] = c;
	}
	else {
		corrupt_string_store(c,s,start+1,allowed_errors);
		s.flip(start);
		a = s.to_ullong();
		myMap[a] = c;
		corrupt_string_store(c,s,start+1,allowed_errors-1);
	}

	return;
}


void initialize_map(unordered_map<long long int , char>&myMap){
	for(int i = 0; i < 26; i++) {
		corrupt_string_store('a' + i,char_to_bitset('a' + i),0,4);
	}
}

int main(){


	// while(true) {
	// 	char chr;
	// 	cin>>chr;
	// 	cout<<cout<<char_to_bitset(chr)<<endl;
	// }
	initialize_map(myMap);

	int N;
	long long int k = 0;
	cin>>N;
	while(N>0) {
		scanf("%lld",&k);
		unordered_map< long long int , char> :: iterator it = myMap.find(k);
		if(it == myMap.end()){
			putchar('?');
		}
		else {
			putchar(it->second);
		}
		N--;
	}
	return 0;
}