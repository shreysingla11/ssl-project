#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	cin>>s;
	int len = s.length();
	int ind = 0, min_l = 0;
	//main loop
	for (int l=1; l<len; l=l*2) {

		//loop over blocks
		for (int i=0; i<len; i+=l) {			//not optimal

			//loop on 1 block
			for (int j=i, k=(i + 2*l - 1); j<(i+l) && k<=(i + 5*l - 2) && k < len && j < len; ) {
				
				
				if (s[j] == s[k]) {
					j++;
					k++;
					
				}
				else {
					
					if (j == i) {
						k++;
						
					}
					else {
					j = i;

					}
				}
				
				if (j == (i+l)) {
					//cout<<j<<endl;
					int a, b;
					a = j - l - 1;
					b = k - l - 1;
					bool matched = false;
					int w_i, w_l;
					if (k == j+1) {
						matched = true;
						w_l = 1;
						w_i = b;
					}
					while (b >= j && a >= 0) {
						if (s[a] == s[b]) {
							a--;
							b--;
						}
						else {
							break;
						}
						if (b==(j-1)) {
							matched = true;
							w_l = k - j;
							w_i = b + 1 - w_l;
						}
					}
					if (!matched) {
						int c = b;
						a = j;
						b = k;
						
						while (b <= len && a <= c) {
							if (s[a] == s[b]) {
								a++;
								b++;
							}
							else {
								break;
							}
							if (a==(c+1)) {
								matched = true;
								w_l = k - j;
								w_i = c + 1 - w_l;
							}
						}

					}
					if (matched) {
						if (ind == 0 && min_l == 0) {
							min_l = w_l;
							ind = w_i;
						}

						if (w_l < min_l) {
							min_l = w_l;
							ind = w_i;
						}
						else if (w_l == min_l) {
							if (w_i < ind) {
								ind = w_i;
							}
						}
						//cout<<matched<<endl;
					}
					else {
						j = i;
					}
					
				}



			}





		}



	}

	cout<<min_l<<" "<<ind<<endl;
	return 0;
}