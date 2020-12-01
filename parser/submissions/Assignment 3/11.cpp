#include <iostream>
#include <vector>

#define INF 1<<30

using namespace std;

int main () {
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for (int i=0; i<n; i++)
		cin >> a[i];

	for (int j=0; j<m; j++)
		cin >> b[j];
	
	vector<vector<int> > L(n+1, vector<int>(m+1, INF));
	L[n][m] = 0;
	for (int i=n-1; i>=0; i--) {
		L[i][m] = 0;
		for (int j=0; j<m; j++)
			if (a[i] == b[j])
				L[i][j] = L[i+1][j+1] + 1;
			else
				L[i][j] = L[i+1][j] + 1;
	}

	int start = 0;
	for (int i=1; i<n; i++)
		if (L[i][0] < L[start][0])
			start = i;

	if (L[start][0] >= INF)
		cout << "infinity\n";
	else
		cout << L[start][0] << ' ' << start + 1 << endl;
	return 0;
}
