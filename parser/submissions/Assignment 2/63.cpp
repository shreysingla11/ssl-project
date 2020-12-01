#include <iostream>
#include <vector>

using namespace std;

class point{
	friend bool intersect(point,point);
	public: int x,y;
	point(){
		x=y=0;
	}
	point(int a, int b){
		x=a; y=b;
	}
	void update(int a, int b){
		x=a; y=b;
		return;
	}
	point operator+(point &B){
		return point(x+B.x,y+B.y);
	}
	point operator-(point &B){
		return point(x-B.x,y-B.y);
	}
	point operator-(float k){
		return point(k*x,k*y);
	}
};

bool intersect(point A, point B, point C, point D){
	float a1 = B.x - A.x; float b1 = -(D.x - C.x);
	float c1 = B.y - A.y; float d1 = -(D.y - C.y);

	float p = C.x - A.x; float q = C.y -A.y;

	float det = a1*d1 - c1*b1;

	if (det = 0) return 0;


	float t = (d1*p - b1*q)/det;
	float u = (-p*c1 + q*a1)/det;

	if (t>=0 && t<=1 && u>=0 && u<=1)
		{return true;}
	else {return false;}
}

void split_set(vector<point> X, vector<int> points,vector<int> &A,vector<int> &B){
	//size of X must be even.
	// first half represent red points.
	for (int i=1; i<points.size(); i++){
		X[points[i]] = X[points[i]] - X[points[0]];
	}

	int m = points[points.size()/2];

	int *W = new int[points.size()];
	for (int i=1; i<points.size(); i++){
	//second point isnow fixed
		int reds=0; int blues =0;

		for (int k=0; k<points.size(); k++){
			W[k] = X[points[i]].x*X[points[k]].y - X[points[i]].y*X[points[k]].x;
		}

		bool color = (i < m) ;
		// true ==> red
		// false ==> blue

		for (int k=0; k<points.size(); k++){
			if ( W[k] >= 0){
				if ( k<m ) {reds++;}
				else {blues++;}
			}
		}

		if (color){
			if (reds-blues == -2){
			for (int k=0; k<points.size(); k++){
				if ( W[k] >= 0 ){
					A.push_back(points[k]);
				}
				else{
					B.push_back(points[k]);
					
				}
			}
			return;
			}
		}
			
		if (reds == blues && reds!=0 && reds !=points.size()/2 ){
			for (int k=0; k<points.size(); k++){
				if ( W[k] > 0 ){
					A.push_back(points[k]);
				}
				else{
					B.push_back(points[k]);
					
				}
			}
			return;
		}
//		if ( reds==blues && blues!=0
//			 && reds!=0 ){
//
//			for (int k=0; k<points.size(); k++){
//				if ( W[k] >= 0 ){
//					A.push_back(points[k]);
//					cout<<"hi";
//				}
//				else{
//					B.push_back(points[k]);
//					
//				}
//			}
//			return;
//		}


	}

	return;
}

void FIND(vector<point> X, vector<int> points,int matching[]) {

	if (points.size() == 0){
		return;
	}
	if (points.size() == 2){
		matching[points[0]]=points[1];
		return;
	}
	if (points.size() == 4){
		if ( intersect(X[points[0]],X[points[2]],X[points[1]],X[points[3]]) ){
			matching[points[0]]=points[3];
			matching[points[1]]=points[2];
			return;
		}
		else{
			matching[points[0]]=points[2];
			matching[points[1]]=points[3];
			return;
		}
	}
	vector<int> A,B;
	split_set(X,points,A,B);
	FIND(X,A,matching);
	FIND(X,B,matching);

	return;
}

int main(){
	int n; cin>>n; n = n;
	point tmp(0,0);
	vector<point> X(n);
	int a,b;
	n=n/2;
	for (int i=0; i<n+n; i++){
		cin>>a>>b; X[i].update(a,b);
	}
	// red points are static.
	// i.e indices represent those of red
	int *matching = new int[n];
	vector<int> points(2*n,0);
	for (int i=0; i<2*n; i++){
		points[i]=i;
	}
	vector<int> A,B;
	split_set(X,points,A,B);
//	cout<<A.size()<<" "<<B.size()<<endl;
//	for (int i=0; i<A.size(); i++){cout<<X[A[i]].x<<" "<<X[A[i]].y<<endl;}
//	for (int i=0; i<B.size(); i++){cout<<X[B[i]].x<<" "<<X[B[i]].y<<endl;}
	FIND(X,points,matching);

	for (int i=0; i<n; i++){
		cout<<i<<" "<<matching[i]-n<<endl;
	}

	return 0;
}
