#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;


struct ship {
	double pos;
	bool front;

	ship(double p, bool f) {
		pos = p;
		front = f;
	}

};

bool op (ship* a, ship* b) {
	return (a->pos < b->pos);
}

int main() {

	ios_base::sync_with_stdio(0);
	double n, w, v_s, v_f, t1, t2;
	char dir;
	double dif = 0;
	int fac = 1;
	int n_l;
	double lij, pij;
	cin>>n>>w>>v_s>>v_f>>t1>>t2;

	vector<ship*> lanes;
	ship* temp;

	for (int i=0; i<n; i++) {
		cin>>dir;
		dif = (((i)*w)/v_f)*v_s;
		fac = 1;
		if (dir=='E') { fac = -1;}
		cin>> n_l;

		for (int j =0; j<n_l; j++) {
			cin>>lij>>pij;
			pij *= fac;
			pij -= dif;
			if ((pij+lij)>0){
				if (pij<0) {lij = lij + pij;pij = 0; }
				temp = new ship(pij - ((w/v_f)*v_s), true);
				lanes.push_back(temp);
				temp = new ship(pij+lij, false);
				lanes.push_back(temp);
			}
		}

	}

	sort(lanes.begin(), lanes.end(), op);

	double max_ans = 0, prev_pos = t1*v_s;
	bool zero = true;
	double count = 0, temp0 = 0;

	for (vector<ship*>::iterator it = lanes.begin(); it<lanes.end(); it++) {
		//cout<<(*it)->pos<<" "<<endl;
		if ((*it)->front == true) {
			count++;
		}
		else {
			count--;
		}
		if (count==1 && zero) {
			temp0 = (*it)->pos;
			
			if (temp0 > v_s*t1) {
				if (temp0 <= v_s*t2){
					if ((temp0 - prev_pos)>max_ans) {
						max_ans = temp0 - prev_pos;
						//cout<<"H"<<endl;
					}
				}
				else {
					if ((v_s*t2 - prev_pos)>max_ans) {
						max_ans = v_s*t2 - prev_pos;
					}
					break;
				}
			}
			zero = false;
		}
		if (count == 0) {
			zero = true;
			if ((*it)->pos/v_s > t1) {
			
			prev_pos = (*it)->pos;
			if (prev_pos > v_s*t2) {
				break;
			}
		}
		}
	}
	
	if (lanes.size() > 0) {
		temp = *(--lanes.end());
		temp0 = temp->pos;
		if (temp0 < v_s*t2) {
			
			if ((v_s*t2 - temp0)>max_ans) {
				max_ans = (v_s*t2 - temp0);
			}
		}
	}
	else {
		max_ans = t2 - t1;
	}
	max_ans = max_ans/v_s;
	printf("%.8f\n", max_ans);
	
}