#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct array {
	int value;
	int index;
};

bool compare (array i,array j) { 
	if(i.value == j.value)
		return (i.index<j.index);
	return (i.value<j.value); }

struct node{
	vector <int> array1;
	vector <int> array2;
};

vector <int> combine(vector <int> parent) {

}

class distinct {

public:

distinct(vector <int> v) {
	
	int n = v.size();
	vector <int> l(n);
	l[0] = -1;
	vector <array> input(n);

	for (int i =0; i<n; i++){
		input[i].value = v[i];
		input[i].index = i;
	}

	sort (input.begin(), input.end(), compare);

	for (int i=1; i<n; i++) {
		if(input[i].value == input[i-1].value) l[input[i].index] = input[i-1].index;
		else l[input[i].index] = -1;
	}

	// for (int i=0; i<n; i++) {
	// 	cout<<l[i]<<' ';
	// }

	vector <node> level(log2(n));

	int base = 1;
	int count =0;
	cout<<log2(n)<<endl;
	for (int i=0; i<log2(n) - 1; i++) {
		level[i].array1.resize(n);
		level[i].array2.resize(n);
		
		for (int j=0; j< n; j++) {
			if (l[j] == -1) {
							// cout<<"hi"<<endl;
				level[i].array1[j] = 0;
				// cout<<level[i].array1[j]<<' ';
				continue;
			}
			int k = l[j]/(n/base);
			if ( l[j] >= k*n/base + n/(2*base) && l[j] < (k+1)*n/base ) {
				count++;
				level[i].array1[j] = count;
			}
			else level[i].array1[j] = count;
			// cout<<level[i].array1[j]<<' ';
		}
		cout<<endl;

	base = base*2;
	count = 0;

	}

	// for (int i=0; i<n; i++) {
	// 	cout<<level[0].array1[i]<<' ';
	// }

}

};
