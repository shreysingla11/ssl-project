#include <iostream>
#include <iomanip>

using namespace std;

extern double f(int i);

int main() {
	int n;
	cin >> n;

	double maxfall = 0;
	double maxfall_rate = 0;
	double curr_rate = 0;

	double first = f(n);
	double max1 = first;
	double min1 = first;
	double curr = first;
	double prev = first;

	while (n != 1) {
		n = n - 1;
		curr = f(n);
		if (curr > prev) {
			maxfall = (maxfall > curr - min1 ? maxfall : curr - min1);
			max1 = (max1 > curr ? max1 : curr);
		}
		if (curr < prev) {
			min1 = (min1 < curr ? min1 : curr);
		}
		curr_rate = curr - prev;
		if (curr_rate > maxfall_rate) {
			maxfall_rate = curr_rate;
		}
		prev = curr;
	}

	cout << fixed << setprecision(6) << maxfall << endl << maxfall_rate <<endl;
	return 0; 
}
