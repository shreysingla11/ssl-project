#include <iostream>
#include <cstdio>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class point {
public:
	int id, x, y;
	string color;
	float slope;

	point(){
		id = 0;
		x = 0;
		y = 0;
		slope = 0;
	}

	point(int idx, int a, int b, string s) {
		id = idx;
		x = a;
		y = b;
		color = s;
		slope = 0;
	}

	void print() {
		cout << x <<" " << y <<endl;
	}
};

bool theta_comp (point i,point j) {
	return (i.slope < j.slope);
}

void printvector(std::vector<point> &points) {
	cout << "Vector of size " <<points.size() <<endl;
	for(int i = 0; i < points.size(); i++) {
		cout << points[i].x <<" " << points[i].y <<" "<< points[i].color<<endl;
	}
	return;
}

void divide(vector<point> &points) {
	point center = points[0];
	int length = points.size();
	vector<point> left, right;

	if (length == 0) {
		return;
	}

	else if (length == 2) {
		if (points[0].color == "red") {
			printf("%d %d\n", points[0].id, points[1].id);
		} else {
			printf("%d %d\n", points[1].id, points[0].id);
		}
		return;
	}

	else {
		for (int i = 0; i < length; i++) {
			if (points[i].x < center.x)
				center = points[i];
		}
		for (int i = 0; i < length; i++) {
			if (points[i].x == center.x) {
				if (points[i].y > center.y) {
					points[i].slope = 30000;
				} else if (points[i].y < center.y) {
					points[i].slope = -30000;
				} else {
					points[i].slope = 40000;
				}
			}
			else {
				points[i].slope = (1.0 * points[i].y - center.y)/(1.0 * points[i].x - center.x);
			}
		}

		std::sort(points.begin(), points.end(), theta_comp);
		
		points.erase(points.end());
		

		int noofredleft = 0;
		int noofblueleft = 0;

		point edge;

		// cout<<"Points"<<endl;
		// printvector(points);
		//cout<<center.color<<"         "<<points[0].color<<endl;

		for (int i = 0; i < length - 1; i++) {
			if (center.color != points[i].color && noofredleft == noofblueleft) {
				edge = points[i];
				right.insert(right.begin(), points.begin() + i + 1, points.end());
				// cout<<"That was right" <<endl;
				// printvector(right);
				// cout<<"That was right" <<endl;
				break;
			} else {
				left.push_back(points[i]);
				// cout<<"That was left" <<endl;
				// printvector(left);
				// cout<<"That was left" <<endl;
				points.erase(points.begin() + i);
				//printvector(points);
				//cout<<"That was points" <<endl;
				if(points[i].color == "blue")
					noofredleft++;
				else
					noofblueleft++;
				/*if (noofleft >= length/2 - 1) {*/

					//cout<<i<<endl;
				/*} else {
					left.push_back(points[i]);
					points.erase(points.begin() + i);
					noofleft++;
				}*/
			}
		}
        if (center.color == "red") {
            printf("%d %d\n", center.id, edge.id);
        } else {
            printf("%d %d\n", edge.id, center.id);
        }

		// cout<<"left"<<endl;
		// printvector(left);
		// cout<<"right"<<endl;
		// printvector(right);
  //       if(left.size()!=0)
  //       	divide(left);
  //       if(right.size()!=0)
  //       	divide(right);
        return;
	}
}

int main() {
	int twon, temp_x, temp_y;
	cin >> twon;
	int n = twon/2;
	std::vector<point> points(twon);
	for (int i = 0; i < n; i++) {
		cin>>temp_x;
		cin>>temp_y;
		points[i] = point(i, temp_x, temp_y, "red");
	}
	for (int i = 0; i < n; i++) {
		cin>>temp_x;
		cin>>temp_y;
		points[n + i] = point(i, temp_x, temp_y, "blue");
	}
	divide(points);
	return 0;
}
