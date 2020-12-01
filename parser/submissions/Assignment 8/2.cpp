#include <iostream>
#include <vector>
#include <set>
using namespace std;

class interval{
public:
	double start;
	double end;
	bool operator<(const interval& x)const{
		if(end<x.start){
			return true;
		}
		return false;
	}
	bool operator>(const interval& x)const{
	if(start>x.end){
		return true;
	}
	return false;
}
};

void union_sets(set<interval> &interval_pain, interval temp){
	cout<<"hi"<<temp.start<<" "<<temp.end<<endl;
	std::set<interval>::iterator it = interval_pain.find(temp);
	std::set<interval>::iterator it1 = it;
	bool flag1 = true;
	bool flag2 = true;
	if(it == interval_pain.end()){
		interval_pain.insert(temp);
	}
	else{
		while(it->start > temp.start){
			if(it == interval_pain.begin()){
				flag1 = false;
				break;
			}
			it--;
			interval_pain.erase(it1);
			it1 = it;
		}
		if(it->end > temp.start){
			if(!flag1)
				int z =1;
			else	
				temp.start = it->start;
			it++;
			interval_pain.erase(it1);
		}

		while(it->end < temp.end){
			if(it == interval_pain.end()){
				flag2 = false;
				break;
			}
			it++;
			interval_pain.erase(it1);
			it1 = it;
		}
		if(it->start < temp.end){
			if(!flag2)
				int z =1;
			else	
				temp.end = it->end;
			interval_pain.erase(it);
		}
		interval_pain.insert(temp);
	}
	return;
}

double max_interval(set<interval> &interval_pain, int t1, int t2){
	cout<<"heyo"<<endl;
	std::set<interval>::iterator it = interval_pain.begin();
	std::set<interval>::iterator it_prev = interval_pain.begin();
	double max = it->start - t1;
	it++;
	while(it != interval_pain.end()){
		if (it->start-it_prev->end > max){
			max = it->start-it_prev->end;
		}
		it_prev=it;
		it++;
	}
	it--;
	if(t2 - it->end > max){
		max = t2 - it->end;
	}
	return max;
}

int main(){
	int n,w,u,v,t1,t2;
	cin>>n>>w>>u>>v>>t1>>t2;
	char dir;
	int numShips,l,p;

	set<interval> interval_pain;
	interval temp;
	for(int i=0;i<n;i++){
		cin>>dir;
		cin>>numShips;

		if(dir=='E'){

			for(int j=0;j<numShips;j++){
				cin>>l>>p;
				temp.start = -(i+1)*(w*1.0)/v - (p*1.0)/u;
				cout<<temp.start;				// do typecast here
				temp.end = -(i)*(w*1.0)/v - ((p-l)*1.0)/u;
				if(temp.start < t1 && temp.end < t2) 
					temp.start = t1;
				else if(temp.start > t1 && temp.end > t2)
					temp.end = t2;
				else if(temp.start < t1 && temp.end > t2)
					continue;
				union_sets(interval_pain, temp);
			}

		}
		else{

			for(int j=0;j<numShips;j++){
				cin>>l>>p;
				temp.start = -(i+1)*w*1.0/v + p*1.0/u;
				temp.end = -(i)*w*1.0/v + (p+l)*1.0/u;
				if(temp.start < t1 && temp.end < t2) 
					temp.start = t1;
				else if(temp.start > t1 && temp.end > t2)
					temp.end = t2;
				else if(temp.start < t1 && temp.end > t2)
					continue;
				union_sets(interval_pain, temp);
			}
		}

		cout<<max_interval(interval_pain,t1,t2)<<endl;
	}
}
