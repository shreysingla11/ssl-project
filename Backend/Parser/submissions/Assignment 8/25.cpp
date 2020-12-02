#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <set>
#include <algorithm>
using namespace std;

double max(double a, double b){ return (a>b)?a:b; }
double min(double a, double b){ return (a<b)?a:b; }

struct TimeIvt{
	double start, end;
	TimeIvt(double x, double y){start = x; end = y;}
	bool operator<(TimeIvt const &a) const { return start < a.start ; };
};

int main(){
	int n, mi;
	double w, u, v, t1, t2;
	double l, p;
	double ss, ee;
	char direction;
	set<TimeIvt> times;
	set<TimeIvt>::iterator it, it2;
	scanf("%d%lf%lf%lf%lf%lf\n", &n, &w, &u, &v, &t1, &t2);
	t2 = t2 + w/v;
	for(int i=0; i<n; i++){
		cin >> direction;
		scanf("%d", &mi);
		for(int j=0; j<mi; j++){
			scanf("%lf%lf", &l, &p);
			if(direction == 'E') p*=-1;
			ss = p/u - i*w/v;
			ee = (p+l)/u - i*w/v;
			it = times.lower_bound(TimeIvt(ss, ee));
			if(it!=times.begin()) it--;
			else{ it=times.end();}
			if(it==times.end()){
				//cout <<"yesssss";
				it = times.begin();
				it2 = it;
			}
			else{
				if(it->end >= ss){
					//cout <<"yesmmm"<<endl;
					ss = it->start;
					it2 = it;
					it++;
				}
				else{
					//cout <<"yeswww";
					it++;
					it2 = it;
				}
			}
			while(it!=times.end() && it->start <= ee){
				//cout <<"yesddd";
				ee = max(ee, it->end);
				it++;
			}
			if(it!=it2){ //cout <<"yes"; 
			times.erase(it2, it);}
			times.insert(TimeIvt(ss, ee));
			//for(it=times.begin(); it!=times.end(); it++) cout << it->start << " " << it->end << endl;
			//	cout << "*****"<<endl;
		}
		//for(it=times.begin(); it!=times.end(); it++) cout << it->start << " " << it->end << endl;
		double d = -10;
		it = times.begin();
		double endbuffer = t1;
		while(it!=times.end() && endbuffer<=t2){
			while(endbuffer > it->start && it!=times.end()){
				endbuffer = max(endbuffer, it->end);
				it++;
			}
			if(it!=times.end()){
				double t =  min(it->start, t2) - endbuffer;
				d = max(d, t);
				endbuffer = it->end;
				it++;
			}
		}
		if(t2 > endbuffer) d = max(d, t2 - endbuffer);
		printf("%.8lf\n", d - w/v);
	}
	return 0;
}
