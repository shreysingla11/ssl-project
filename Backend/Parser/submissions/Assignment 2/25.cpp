#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct Line{
	//ax+by+c
	int a;
	int b;
	int c;
	Line(int x, int y, int z){a=x; b=y; c=z;}
	int side(int x, int y){return ((a*x+b*y+c)>0)?1:-1;}
};

struct point{
	int id;
	int pointId;
	int x;
	int y;
	char color;
	point(int a, int b, int i, char c){
		x=a; y=b; id=i; color=c;
	}
};


void solve(vector<point*> arr){
	int n = arr.size();
	if(n==0) return;
	//cout << n << endl;
	//for(int i=0; i<n; i++) cout << arr[i]->id <<arr[i]->color <<" ";
	//cout << endl;
	// fixed first point
	// j other trial point
	int i = 0;
	int j;
	int score = 10000000;
	int scorePoint;
	bool both=0;
	int balance1 = 0, balance2 = 0;
	int panic=0;
	bool len1=0, len2=0;
	for(j=1; j<n; j++){
		//if(arr[j]->color == arr[i]->color) continue;
		Line l( arr[i]->y -arr[j]->y, arr[j]->x - arr[i]->x, arr[i]->x*arr[j]->y - arr[i]->y*arr[j]->x);
		int tempScore = 0;
		balance1 = 0; balance2 = 0;
		len1 = 0; len2 = 0;
		for(int k=1; k<n; k++){
			if(k==j) continue;
			int z = l.side(arr[k]->x, arr[k]->y);
			if(z>0){
				//cout<<"yes"<<k<<endl; 
				balance1 += (arr[k]->color =='r')?1:-1;
				len1=1;
			}
			else{
				balance2 += (arr[k]->color =='r')?1:-1;
				len2=1;
			}
			tempScore += z;
		}
		tempScore = abs(tempScore);
		if(tempScore < score && (balance1==0 && balance2==0)){
			score = tempScore;
			scorePoint = j;
			both = 1;
			//cout<<balance1<<balance2<<"f"<<endl;
		}
		if(!both && len1!=0 && len2!=0){
			if(balance1==0) panic = 1;
			else if(balance2==0) panic = 2;
			scorePoint = j;
		}
		//cout << j << ":" << balance <<endl;
		//cout<<both<<endl;
	}
	
	j = scorePoint;
	if(both){
		// draw line between point i and j
		//cout<<"sss"<<scorePoint<<endl;
		arr[i]->pointId = arr[j]->id;
		arr[j]->pointId = arr[i]->id;
	}
	
	Line l( arr[i]->y -arr[j]->y, arr[j]->x - arr[i]->x, arr[i]->x*arr[j]->y - arr[i]->y*arr[j]->x);
	
	// solve the others
	vector<point*> a, b;
	if(both){
		for(int k=1; k<n; k++){
			if(k==j) continue;
			if(l.side(arr[k]->x, arr[k]->y) > 0){
				a.push_back(arr[k]);
			}
			else{
				b.push_back(arr[k]);
			}
		}
	}
	else{
		for(int k=0; k<n; k++){
			//if(k==j) continue;
			int z = l.side(arr[k]->x, arr[k]->y);
			if(z>0){
				a.push_back(arr[k]);
			}
			else if(z<0){
				b.push_back(arr[k]);
			}
			else if(panic == 1){
				b.push_back(arr[k]);
			}
			else{
				a.push_back(arr[k]);
			}
		}
	}
	solve(a);
	solve(b);
	return;
}

int main(){
	int n, x, y;
	scanf("%d", &n);
	n /= 2;
	vector<point*> arr(2*n);
	for(int i=0; i<n; i++){
		scanf("%d%d", &x, &y);
		arr[i] = new point(x, y, i, 'r');
	}
	for(int i=n; i<2*n; i++){
		scanf("%d%d", &x, &y);
		arr[i] = new point(x, y, i-n, 'b');
	}
	solve(arr);
	for(int i=0; i<2*n; i++){
		if(arr[i]->color == 'r'){
			printf("%d %d\n", arr[i]->id, arr[i]->pointId);
		}
	}
	return 0;
}
