#include <iostream>
#include <vector>

using namespace std;

int inf = 0;

int main() {
	int n, m;
	cin >> n >> m;
	inf = n + 1;

	vector<int> a(n), b(m);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}

	// vector <vector<int> > L(n, vector<int>(m));
	vector <vector<int> > temp(n, vector<int>(2));
	int col = 1;

	if (a[n-1] == b[m-1])
		temp[n-1][0] = 1;
	else
		temp[n-1][0] = inf;

	for (int i = n - 2; i >= 0; i--) {
		if (a[i] == b[m-1]) {
			temp[i][0] = 1;
		}
		else
			temp[i][0] = 1 + temp[i+1][0];
	}

	for (int j = m - 2; j >= 0; j--) {
		for (int i = n-1; i>=j; i--) {
			if (i == n-1)
				temp[i][col] = inf;
			else {
				if (a[i] == b[j])
					temp[i][col] = 1 + temp[i+1][1-col];
				else
					temp[i][col] = 1 + temp[i+1][col];
			}
		}
		col = 1 - col;
	}

	int result = inf;
	int result2;

	for (int i=0; i<n; i++) {
		if(temp[i][1-col] < result) {
			result = temp[i][1-col];
			result2 = i;
		}
	}

	if (result >= inf) {
		cout << "infinity" << endl;
	}
	else
		cout << result << " " << result2+1 << endl;

	return 0;
}
