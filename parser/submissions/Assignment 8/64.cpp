#include <iostream>
#include <algorithm>
#include <cstdio>
#include <set>

using namespace std;

struct interval{
	double start;
	double end;
	bool operator<(const interval&b)const{
		if(end<b.start){
			return true;
		}
		return false;
	}
	interval(double x, double y):start(x),end(y){}
	interval():start(0),end(0){}
};

set<interval>::iterator prev_it(set<interval>::iterator it){
	return --it;
}
set<interval>::iterator next_it(set<interval>::iterator it){
	return ++it;
}

void merge_intervals(set<interval> &intervals, interval ship){
	set<interval>::iterator it = intervals.find(ship);
	if(it == intervals.end()){
		intervals.insert(ship);
	}
	else{

		set<interval>::iterator it1 = it;
		// it1--;
		double first,last;

		while(true){

			if((*it1).start < ship.start){
				if((*it1).end < ship.start){
					first = ship.start;
				}
				else{
					first = (*it1).start;
					if(it1!=it){
						intervals.erase(it1);
					}
				}
				break;
			}
			else{
					if(it1 == intervals.begin()){break;}
					it1--;
					if(it1!=it){
						intervals.erase(it1);
					}
					first = ship.start;
			}

		}
		while(it != intervals.end()){
			if((*it).end > ship.end){
				if((*it).start > ship.end){
					last = ship.end;
				}
				else{
					last = (*it).end;
					intervals.erase(it);
				}
				break;
			}
			else{
					it++;
					intervals.erase(prev_it(it));
					last = ship.end;
			}
		}
		//########
		interval temp(first,last);
		// if(intervals.find(temp) != intervals.end()){
		// 	// cout<<"ERROR"<<endl;
		// 	return;
		// }

		interval new_ship(first,last);
		intervals.insert(new_ship);

	}
	return;
}

double maximum(double a, double b){
	if(a>b) {
		return a;
	}
	else{
		return b;
	}
}

double find_max_gap(set<interval> intervals, double t1, double t2){
	set<interval>::iterator it = intervals.begin();
	double max_gap=0;
	// cout<<"Max : "<<max_gap<<"   ";
	double prev_end=t1;

	while(it!=intervals.end()){
		if((*it).end <= t1){

		}
		else{
			break;
		}
		it++;
	}

	if(it!=intervals.end()){
		if((*it).start <= t1){
			prev_end=(*it).end;
		}
		else{
			// cout<<"Max : "<<max_gap<<","<<(*it).start<<prev_end<<"    ";
			max_gap = maximum(max_gap,(*it).start - prev_end);
			prev_end=(*it).end;
		}
		it++;
	}

	while(it!=intervals.end()){
		if((*it).end < t2){
		// cout<<"Max : "<<max_gap<<","<<(*it).start<<prev_end<<"    ";
			max_gap = maximum(max_gap,(*it).start - prev_end);
			prev_end=(*it).end;
			it++;
		}
		else{
			if((*it).start < t2){
		// cout<<"Max : "<<max_gap<<","<<(*it).start<<prev_end<<"    ";
				max_gap = maximum(max_gap,(*it).start - prev_end);
				prev_end=(*it).end;
			}
			else{
		// cout<<"Max : "<<max_gap<<","<<(*it).start<<prev_end<<"    ";
				max_gap = maximum(max_gap,t2 - prev_end);
				prev_end=(*it).end;
			}
			it++;
			break;
		}
	}
	// cout<<endl;
	return max_gap;



}


void print_intervals(set<interval> intervals){
	set<interval>::iterator it = intervals.begin();
	while(it!=intervals.end()){
		// cout<<(*it).start<<","<<(*it).end<<"   ";
		it++;
	}
	// cout<<endl;
}

int main(){
	int n,w,u,v,t1,t2;
	cin>>n>>w>>v>>u>>t1>>t2;

	set<interval> intervals;
	interval temp(3,5);
	if(intervals.find(temp) != intervals.end()){
		// cout<<"ERROR"<<endl;
		return 0;
	}
	else{
		// cout<<"Works"<<endl;
	}
	for (int i = 0; i < n; ++i)
	{
		char dir;
		int num_ships, p, l;
		cin>>dir>>num_ships;

		double offset = -i*w/(u*1.0);

		for (int j = 0; j < num_ships; ++j)
		{
			cin>>l>>p;
			double interval_start;
			double interval_end;
			if (dir == 'E')
			{
				interval_start = -p/(v*1.0) - (w/(u*1.0));
				interval_end = -(p-l)/(v*1.0);
			}
			else{
				interval_start = p/(v*1.0) - (w/(u*1.0));
				interval_end = (p+l)/(v*1.0);
			}
			interval_start += offset;
			interval_end += offset;
			if( interval_start <= t1){
				interval_start = t1;
			}
			if( interval_end >= t2){
				interval_end = t2;
			}
			if(interval_end >= interval_start){
				interval new_ship(interval_start, interval_end);
				merge_intervals(intervals,new_ship);
			}
			// print_intervals(intervals);
		}
		// cout<<"Next_lane"<<endl;

		double output = find_max_gap(intervals,t1,t2);
		printf("%.8f\n",output);
	}



	return 0;
}
