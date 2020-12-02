#include <iostream>
using namespace std;

struct point{
	int x, y, num;
};

void line_input(int n, struct point R[], struct point B[]){
	for(int i=0; i<n; i++){
		cin >> R[i].x;
		cin >> R[i].y;
		R[i].num = i;
	}
	for(int i=0; i<n; i++){
		cin >> B[i].x;
		cin >> B[i].y;
		B[i].num = i;
	}
}

//For orientation of p,q and r (clockwise or anticlockwise)
//0 ---> p,q and r are collinear
//1 ---> p,q and r are clockwise
//2 ---> p,q and r are anticlockwise
int orientation(point p, point q, point r){
	int val = (q.y-p.y)*(r.x-q.x)-(q.x-p.x)*(r.y-q.y);
	
	if(val == 0) return 0;
	
	if(val == 1) return 1;
	else return 2;
}

bool check_intersect(struct point Ra, struct point Ba, struct point Rb, struct point Bb){
	int o1 = orientation(Ra,Ba,Rb);
	int o2 = orientation(Ra,Bb,Bb);
	int o3 = orientation(Rb,Bb,Ra);
	int o4 = orientation(Rb,Bb,Ba);
	
	if(o1 != o2 && o3 != o4) return true;//It means that the 2 lines intersect!
	else return false;
}
//There will be no other cases because we are given that no 3 points are collinear.

void num_swap(int* p, int* q){
	int tmp;
	tmp = *p;
	*p = *q;
	*q = tmp;
}

int main(){
	int N;
	cin >> N;
	int n = N/2;
	point redpt[n];
	point bluept[n];
	
	line_input(n,redpt,bluept);
	while(1){
		int count = 0;
		for(int i=0; i<n; i++){
			for(int j=i+1; j<n; j++){
				if(check_intersect(redpt[i],bluept[redpt[i].num],redpt[j],bluept[redpt[j].num])){
					num_swap(&redpt[i].num,&redpt[j].num);
					count++;
				}
			}
		}
		
		if(count == 0) break;
	}
	for(int i=0; i<n; i++){
		cout << i << " " << redpt[i].num << endl;
	}
}
