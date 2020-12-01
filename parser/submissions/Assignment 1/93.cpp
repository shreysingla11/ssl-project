#include <iostream>

using namespace std;

extern double f(int i);

int main() {
	cout.setf(ios::fixed,ios::floatfield);
    cout.precision(6);
	int n;
	cin>>n;
	if (n == 0 || n == 1) {
		cout<<0.000000<<endl;
		cout<<0.000000<<endl;
		return -1;
	}
	double max = f(1);
	double maxrate = 0;
	double maxfall = 0;
	double val;
	double prev = max;
	for (int i = 1; i < n; i++) {
		val = f(i+1);
		if (val >= max) {
			max = val;
		}
		else {
			if ((max - val) > maxfall) {
				maxfall = max - val;
			}
			if ((prev - val)>maxrate) {
				maxrate = prev - val;
			}
		}
		prev = val;
	}
	cout<<maxfall<<endl;
	cout<<maxrate<<endl;
	return 0;
}