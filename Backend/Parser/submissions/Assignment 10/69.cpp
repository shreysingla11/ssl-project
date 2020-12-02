#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class distinct {
public:
	std::vector<int> seq;
	std::vector<int> l;
	int n, ln;
	vector<vector<int> > first;
	vector<vector<int> > prev1;
	vector<vector<int> > prev2;

	// 2**ln == n

	distinct(const vector<int> &v) {
		seq = v;
		n = v.size();
		l.resize(v.size());
		for(int i = 0; i < n; i++) {
			int j = i - 1;
			while(j >= 0) {
				if(seq[i] == seq[j])
					break;
				j--;
			}
			l[i] = j;
		}
		int temp = n;
		ln = 0;
		while(temp != 1) {
			temp = temp / 2;
			ln++;
		}
		
		//make arrays from 1 to ln

		temp = 1;
		for(int i = 1; i < ln + 1; i++) {
			int x = n / temp;
			std::vector<int> vec_temp;
			std::vector<int> vec_temp2(n);
			std::vector<int> vec_temp3(n);
			for(int j = 0; j < n; j++) {
				vector<int> count(temp);
				if(l[j] == -1) {
					count[j] = 0;
					vec_temp.push_back(0);
					continue;
				}
				else {
					int k = l[j]/x;
					int m_value = k*x + x/2;
					int l_value = k*x;
					int r_value = (k + 1)*x;
					if(l[j] > m_value) {
						count[j]++;
						for(int k = m_value; k >= r_value; k--) {
							if(l[k] == l[j]) {
								vec_temp2[j] = k;
							}
							else if(k == r_value) {
								vec_temp2[j] = -1;
							}
						}
						vec_temp3[j] = -1;
					}
					else {
						for(int k = m_value; k <= r_value; k++) {
							if(l[k] == l[j]) {
								vec_temp3[j] = k;
							}
							else if(k == r_value) {
								vec_temp3[j] = -1;
							}
						}
						vec_temp2[j] = -1;
					}
					vec_temp.push_back(count[j]);
				}
			}
			prev1.push_back(vec_temp2);
			prev2.push_back(vec_temp3);
			first.push_back(vec_temp);
			temp = 2*temp;
		}
		return;
	}

	int num_distinct(int i, int j) {
		return  j - i + 1 + query(i, j);
	}

};
