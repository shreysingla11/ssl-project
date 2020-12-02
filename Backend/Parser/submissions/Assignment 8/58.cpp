#include<iostream>
#include<vector>
#include<set>
#include<list>
#include<cstdio>

using namespace std;

class interval{
public:
	float t1,t2;
	interval (float a, float b){
		t1=a; t2=b;
	}
};

bool compareInterval(interval L, interval R){  
	return (L.t1 < R.t2)? true: false; 
}

class point{
public:
	float t;
	bool k;
	//0 for start, 1 for end
	point(float T, bool K){
		t=T; k=K;
	}
};

bool comparePoint(point L, point R){  
	if (L.t < R.t) return true;
	else if (R.t <L.t) return false;
	else return !L.k; 
}

int main(){
	int n,w,u,v,t1,t2;
	cin>>n>>w>>u>>v>>t1>>t2;
	float lag = w/(v+0.0), clag=0.0;
	list<interval> A;
	list<point> B;
	point tmp1(0,false), tmp2(0,false);
	char d; int size,l,p;
	for (int i=0; i<n; i++){
		cin>>d;
		cin>>size;
		for (int j=0; j<size; j++){
			cin>>l>>p;
			float start = p/(u+0.0), end = (p+l)/(u+0.0);
			if (d=='W'){}
			if (d=='E'){
				float k=start;
				start = -end; end = -k;
			}
			start -= (clag+lag); end -= clag; 
			// if (end < t1 ) {continue;}
			// if (start > t2) {continue;}
			// A.push_back(interval(start,end));
			tmp1.t=start; tmp1.k=false;
			tmp2.t=end; tmp2.k=true;
			B.push_back(tmp1);
			B.push_back(tmp2);
		}
		clag += lag;
	}
	B.sort(comparePoint);
	list<point>::iterator it =B.begin();
	int count=0;
	float last=t1, max=0;
	while (it != B.end() && last < t2){
		if (count ==0){
			if ((it->t)-last > max) {max = (it->t)-last;}
		}
		if (it->k) {count--;}
		else{count++;}
		// if (count==0 && !(it->k)){
		// 	if ((it->t - last) > max) {max = (it->t - last);}
		// }
		// if (!(it->k)) {count++;}
		// else {count--;}
		
		// if (it->t >last) {last = it->t;}
		// cout<<(it->t);
		// if (it->k) cout<<"O"; else cout<<"C";
		// cout<<endl;
		
		if (it->t >last) last = it->t;
		it++;
	}
	if ((t2 - last) > max) {max = (t2 - last);}
	printf("%.8f\n",max);
	return 0;
}