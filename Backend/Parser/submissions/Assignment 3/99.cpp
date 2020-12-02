#include <iostream>
#include <vector>
#define inf -1
using namespace std;
int n, m;
int L(int i, int j, vector<int> &n_i, vector<int> &m_i, vector<int> &curr, vector<int> &prev) {

	if (i==n && j==m) {
		if (n_i[i]==m_i[j]) {
			return 1;
		}
		else {
			return inf;
		}
	}
	else if (j==m) {
		if (n_i[i]==m_i[j]) {
			return 1;
		}
		else {
			if (prev[m]==inf) {
				return inf;
			}
			else {
				return 1+prev[m];
			}
		}
	}
	else if (i==n) {
		return inf;
	}
	else {
		if (n_i[i]==m_i[j]) {
			if (prev[j+1]==inf) {
				return inf;
			}
			else {
				return 1+prev[j+1];
			}
		}
		else {
			if (prev[j]==inf) {
				return inf;
			}
			else {
				return 1+prev[j];
			}
		}
	}
}

int main() {
	cin>>n>>m;

	vector<int> n_i(1);
	vector<int> m_i(1);
	int temp;
	for(int k=0; k<n; k++) {
		cin>>temp;
		n_i.push_back(temp);
	}
	for(int k=0; k<m; k++) {
		cin>>temp;
		m_i.push_back(temp);
	}
	if(n<m) {
		cout<<"infinity"<<endl;
		return 0;
	}
	vector<int> curr(m+1, -1);
	vector<int> prev(m+1, -1);
	vector<int> top(m+1);
	int t = 2;
	for (int i=n; i>0; i--) {
		t = 2;
		if ((m-n+i)>2) {
			t = m-n+i;
		}
		if (i<=m){
		curr[1] = L(i, 1, n_i, m_i, curr, prev);
		top[i] = curr[1];
	}
		for (int j=m; j>=t; j--) {
			curr[j] = L(i, j, n_i, m_i, curr, prev);

		}
		prev = curr;
	}
	int min = top[1];
	int min_i = 1;
	for (int i=2; i<=m; i++) {
		if (min == inf) {
			min = top[i];
			min_i = i;
		}
		else if (top[i]!=inf && top[i]<min) {
			min = top[i];
			min_i = i;
		}
	}

	if (min==inf) {
		cout<<"infinity"<<endl;
		return 0;
	}
	cout<<min<<" "<<min_i<<endl;
	return 0;
}