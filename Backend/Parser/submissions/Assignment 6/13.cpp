#include <bits/stdc++.h>
using namespace std;

struct square_info{
	int len;
	int pos;
};

square_info search_square(int l, string str){
	int n = str.length();
	int len = 2*l-1;
	int pos = 0;
	int k = l;
	
	while(len >= 2*l-1 && len <= 4*l-2){
	}
	
	for(int i=0, j=0; i<k, j<n; i++, j++){
		if(str[i] != str[l+j]){
			l = l+i;
			i = -1;
			j = j-1;
			k = l+i;
		}
	}
	
	square_info info;
	info.len = 0;
	info.pos = 0;
	return info;
}

vector<int> square_simple(string str){
	vector<int> info;
	int n = str.length();
	int len=1;
	string temp_str1;
	string temp_str2;
	while(len <= n/2){
		for(int j=0; j<n-len; j++){
			temp_str1 = str.substr(j, len);
			temp_str2 = str.substr(j+len, len);
			if(temp_str1 == temp_str2){
				info.push_back(j);
				info.push_back(len);
			}
		}
		len++;
	}
	return info;
}

int main(){
	string str;
	cin >> str;
	int n = str.length();
	int limit = log(n)/log(2);
//	square_info info[limit];
	int l=1, count=0;
	
	vector<int> inf(2*n);
	int pos_smallest = n+1;
	int len_smallest = n+1;
	inf = square_simple(str);
	int size = inf.size();
	inf.resize(size);
	for(int i=0; i<size; i=i+2){
		if(pos_smallest > inf[i])   pos_smallest = inf[i];
		if(len_smallest > inf[i+1]) len_smallest = inf[i+1];
	}
	if(pos_smallest == n+1 || len_smallest == n+1) cout << "0 " << "0" << endl;
	else cout << len_smallest << " " << pos_smallest << endl;
}
