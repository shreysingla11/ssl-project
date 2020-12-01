#include <bits/stdc++.h>
using namespace std;

void int_to_int(long long int num, long long int &ans, long long int count){
	long long int rem;
	if(num <= 1){
		ans = ans + num*count;
		return;
	}
	rem = num%2;
	int_to_int(num/2, ans, count*10);
	ans = ans + rem*count;
	return;
}

int get_size(long long int t){
	int count = 0;
	long long int temp = t;
	while(temp > 0){
		temp = temp/10;
		count++;
	}
	return count;
}

int main(){
	int n;
	cin >> n;
	vector<long long int> arr(n);
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	long long int ans = 0;
	int count = 0;
	for(int i=0; i<n; i++){
		int_to_int(arr[i], ans, 1);
		arr[i] = ans;
	}
	for(int i=0; i<n; i++){
		long long int tmp = arr[i];
		int len = get_size(arr[i]);
	}
	for(int i=0; i<500000; i++){
		for(int j=0; j<1000; j++){}
	}
	cout << '?' << endl;
}
