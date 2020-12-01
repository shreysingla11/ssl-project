#include <iostream>
#include <vector>
using namespace std;

class Point {
	public:
	int x;
	int y;

	Point(int a, int b) {
		x = a;
		y = b;
	}
	//friend bool intersect(Point p1, Point p2, Point p3, Point p4);
};

bool intersect(Point p1, Point p2, Point p3, Point p4) {
	int a = p1.y - p2.y;
	int b = p2.x - p1.x;
	int c = -1*p1.x*a - p1.y*b;
	int pl3 = a*p3.x + b*p3.y + c;
	int pl4 = a*p4.x + b*p4.y + c;
	if (pl3 == 0 || pl4 == 0) {
		return true;
	}
	if (pl3 * pl4 < 0) {
		return true;
	}
	return false;

}


void recurse(vector<Point> &red, vector<Point> &blue, vector<int> &red_index, vector<int> &blue_index, int n) {
	if (n == 0) {
		return;
	}
	//cout<<n<<endl;
	vector<int> red_low;
	vector<int> blue_low;
	vector<int> red_high;
	vector<int> blue_high;
	vector<int> red_low_index;
	vector<int> red_high_index;
	Point p1(0, 0), p2(0, 0), p3(0, 0), p4(0, 0);
	p1 = red[red_index[0]];
	int count_r, count_b;
	for (int i = 0; i < n; i++) {
		p2 = blue[blue_index[i]];
		int a = p1.y - p2.y;
		int b = p2.x - p1.x;
		int c = -1*p1.x*a - p1.y*b;
		//cout<<"Hi"<<endl;
		for (int j = 0; j < n; j++) {

			if (j!=0) {
				p3 = red[red_index[j]];
				if(a*p3.x + b*p3.y + c < 0) {
					red_low.push_back(red_index[j]);
					red_low_index.push_back(j);
				}
				else {
					red_high.push_back(red_index[j]);
					red_high_index.push_back(j);
				}

			}
			if (j!=i) {
				p4 = blue[blue_index[j]];
				if(a*p4.x + b*p4.y + c < 0) {
					blue_low.push_back(blue_index[j]);
				}
				else {
					blue_high.push_back(blue_index[j]);
				}
			}
		}
		
		if (red_low.size() == blue_low.size()) {
			blue_index[0] = blue_index[i];
			
			break;
		}
		else {
			red_low.clear();
			red_high.clear();
			blue_low.clear();
			blue_high.clear();
			red_low_index.clear();
			red_high_index.clear();
			

		}
		//cout<<i<<endl;
	}
	//cout<<blue_index[0]<<endl;
	recurse(red, blue, red_low, blue_low, red_low.size());
	recurse(red, blue, red_high, blue_high, red_high.size());
	for (int i = 0; i < red_low_index.size(); i++) {
		blue_index[red_low_index[i]] = blue_low[i]; 
	}
	for (int i = 0; i < red_high_index.size(); i++) {
		blue_index[red_high_index[i]] = blue_high[i]; 
	}
	return;
}

int main() {
	vector<Point> red;
	vector<Point> blue;
	vector<int> red_index;
	vector<int> blue_index;
	int twice_n;
	cin>>twice_n;
	if (twice_n <= 0 || twice_n%2 != 0) {
		return -1;
	}
	if (twice_n == 2) {
		cout<<"0 0"<<endl;
		return 0;
	}
	int n = twice_n/2;
	int a, b;
	for (int i=0; i < n; i++) {
		cin>>a>>b;
		red.push_back(Point(a, b));
		red_index.push_back(i);
	}
	for (int i=0; i < n; i++) {
		cin>>a>>b;
		blue.push_back(Point(a, b));
		blue_index.push_back(i);
	}

	// a = 0;
	// b = 1;
	// bool term = false;
	// bool inters;
	// int temp;
	// while(!term) {

	// 	for (; b < n; b++) {

	// 		inters = intersect(red[red_index[a]], blue[blue_index[a]], red[red_index[b]], blue[blue_index[b]]);
	// 		if (inters) {
				
	// 			temp = blue_index[a];
	// 			blue_index[a] = blue_index[b];
	// 			blue_index[b] = temp;
	// 			a = -1;
	// 			break;
	// 		}
	// 		else {

	// 		}
	// 	}
	// 	if (a == n-2 && b == n) {
	// 		term = true;
	// 	}
	// 	else {
	// 		a++;
	// 		b = a+1;
	// 	}


	// }
	recurse(red, blue, red_index, blue_index, n);
	for (int i=0; i < n; i++) {
		cout<<red_index[i]<<" "<<blue_index[i]<<endl;
	}
return 0;
}

