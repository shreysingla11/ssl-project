#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

struct time_it {
	double value_;
	char s_or_e;
};

struct bytime {
    bool operator()(const time_it& lhs, const time_it& rhs) const
    {
        if(lhs.value_ < rhs.value_)
        	return lhs.value_ < rhs.value_;
        else if(lhs.value_ > rhs.value_)
        	return lhs.value_ < rhs.value_;
        else
        	return lhs.s_or_e > rhs.s_or_e;
    }
};

int main(){
	double n, w, v, u, t1, t2;
	cin >> n >> w >> u >> v >> t1 >> t2;
	char temp;
	int sign = 1, no_ships = 0;
	vector<time_it> ship_data;
	time_it temp_ship;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (temp == 'E') {
			sign = -1;
		}
		cin >> no_ships;
		for (int j = 0; j < no_ships; j++) {
			double length;
			cin >> length;
			double position;
			cin >> position;
			position = sign * position;
			temp_ship.value_ = position / u - i * w / v;
			temp_ship.s_or_e = 'S';
			ship_data.push_back(temp_ship);
			temp_ship.value_ = (position + length) / u - i * w / v;
			temp_ship.s_or_e = 'E';
			ship_data.push_back(temp_ship);
		}
		sign = 1;
	}

	sort(ship_data.begin(), ship_data.end(), bytime());

	// for (std::vector<time_it>::iterator i = ship_data.begin(); i < ship_data.end(); i++) {
	// 	cout << i->value_ <<"   "<< i->s_or_e << endl;
	// }

	double start_time = t1, end_time;
	double max_time = 0;
	int count = 0;
	for (std::vector<time_it>::iterator i = ship_data.begin(); i < ship_data.end(); i++) {
		if(i->s_or_e == 'S') {
			count++;
			if(count == 1) {
				end_time = i->value_ - w / v;
				if(end_time > t2)
					end_time = t2;
				if(end_time - start_time > max_time)
					max_time = end_time - start_time;
			}
		}
		else {
			count--;
			if(count == 0) {
				start_time = i->value_;
				if(start_time < t1) 
					start_time = t1;
			}
		}
	}

	if(t2 > start_time) {
		if(max_time < t2 - start_time)
			max_time = t2 - start_time;
	}

	cout << std::fixed << std::setprecision(8) << max_time << endl;

	return 0;
}
