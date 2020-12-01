#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node {
	int i;
	int val;
	node(int a, int b) {
		i = a;
		val = b;
	}
};

bool lessthan(node* a, node* b) {
	if (a->val < b->val) {
		return true;
	}
	else if (a->val == b->val) {
		if (a->i < b->i) {
			return true;
		}
	}
	return false;
}

class distinct {

	vector<node*> input;
	vector<int> l;
	int n;
	vector<vector<int> > vv;
	vector<int> vi;
	vector<int> vk;
	vector<int> vtemp;
	vector<int> vmtemp;

public:
	distinct(vector<int> v) {
		n = v.size();
		for(int i=0; i<v.size(); i++) {
			input.push_back(new node(i, v[i]));
		}
		sort(input.begin(), input.end(), lessthan);
		l.resize(v.size());
		l[input[0]->i] = -1;
		for(int i=1; i<input.size(); i++) {
			if (input[i]->val == input[i-1]->val) {
				l[input[i]->i] = input[i-1]->i;
			}
			else {
				l[input[i]->i] = -1;
			}
		}
		// for(int i=0; i<v.size(); i++) {
		// 	cout<<l[i]<<endl;
		// }

		vi.resize(n);
		vk.resize(n);
		vtemp.resize(n);
		vmtemp.resize(n);
		int p;
		for(int i=n/2; i!=0; i/=2) {

			for(int j=0; j<n; j++) {
				vi[j] = vk[j] = 0;
				vmtemp[j] = -1;
				vtemp[j] = 0;
			}
			
			for(int j=0; j<n; j++) {
				if (l[j]!= -1) {
					p = l[j]/i;
					vtemp[p] = vtemp[p] + 1;
					vmtemp[p] = j;
					if (p%2==0) {
						vi[j] = vtemp[p+1];
						vk[j] = vmtemp[p+1];
					}
					else {
						vi[j] = vtemp[p];
						vk[j] = vmtemp[p-1];
					}
				}
				else {
					vi[j] = 0;
					vk[j] = -1;
				}
			}

			vv.push_back(vi);
			vv.push_back(vk);
// 			for(int i=0; i<v.size(); i++) {

// 			cout<<vi[i];
// 		}
// cout<<endl;
// for(int i=0; i<v.size(); i++) {

// 			cout<<vk[i];
// 		}
// cout<<endl;

		}

		// for(int i=0; i<v.size(); i++) {

		// 	cout<<vv[0][i]<<vv[1][i]<<endl;
		// }


	}


	int num_distinct(int i, int j) {

		int p, q;
		p = 0;
		q = n;
		int ii, jj;
		ii = i;
		jj = j;

		int ans = 0;
		int c = 0;
		if (j<i) {
			
			return 0;
		}
		if (j==i) {
			//cout<<1<<endl;
			return 1;
		}
		if (l[j] == -1) {
			for (int m=j; m>=i; m++) {
				if (m==i || l[m]!=-1) {
					j = m;
					break;
				}
			}
		}
		while(q!=p+1) {
			if (i<=((q+p)/2)) {
				if (l[j]< ((q+p)/2)) {
					if (vv[2*c+1][j]!=-1) {
						ans += vv[2*c][vv[2*c+1][j]];
					}
				}
				else {
					ans += vv[2*c][j];
				}
				
			}

			if (i<((q+p)/2)) {
				if (l[j]>= ((q+p)/2)) {
					if (vv[2*c+1][j]!=-1) {
					j = vv[2*c+1][j];
				}
				}
				q = (q+p)/2;
				
				

			}
			else {
				if (l[j]< ((q+p)/2)) {
					if (vv[2*c+1][j]!=-1) {
					j = vv[2*c+1][j];
				}
				}
				p = (q+p)/2;
				
			}

		c++;			//cout<<ans<<endl;
		}
		if(ans!=0) {
			ans++;
		}
		//cout<<<<endl;




		return jj-ii+1-ans;
	}





};


