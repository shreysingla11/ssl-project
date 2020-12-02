#include<iostream>
using namespace std;

class Point{
	public:
	int x;
	int y;
	int index;
	Point(){}
};

class Pairing{
	public:
	int a;
	int b;
	Pairing(){}
};


bool is_intersect(Point a,Point b,Point c,Point d){
	bool ans = true;
	
	int x1=a.x;
	int x2=b.x;
	int y1=a.y;
	int y2=b.y;
	int val1 = c.y*(x2-x1)+c.x*(y1-y2)+y1*(x1-x2)+x1*(y2-y1);
	int val2 = d.y*(x2-x1)+d.x*(y1-y2)+y1*(x1-x2)+x1*(y2-y1);
	
	if(val1 * val2  > 0)ans = false;
	
	
	x1=c.x;
	x2=d.x;
	y1=c.y;
	y2=d.y;
	val1 = a.y*(x2-x1)+a.x*(y1-y2)+y1*(x1-x2)+x1*(y2-y1);
	val2 = b.y*(x2-x1)+b.x*(y1-y2)+y1*(x1-x2)+x1*(y2-y1);
	
	if(val1 * val2  > 0)ans = false;
	
	return ans;
}


int main(){
	int n_2;
	cin>>n_2;
	int n=n_2/2;
	Point red[n];
	Point blue[n];
	int a,b;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		red[i].x = a;
		red[i].y = b;
		red[i].index = i;
	}
	for(int i=0;i<n;i++){
		cin>>a>>b;
		blue[i].x = a;
		blue[i].y = b;
		blue[i].index = i;
	}
	
	Pairing bond[n];
	for(int i=0;i<n;i++){
		bond[i].a=i;
		bond[i].b=i;
	}
	
	while(true){
		bool check=true;
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				if(is_intersect(red[bond[i].a],blue[bond[i].b],red[bond[j].a],blue[bond[j].b])){
					//~ cout<<"hoho"<<endl;
					check=false;
					int tmp = bond[i].b;
					bond[i].b=bond[j].b;
					bond[j].b=tmp;
				}
			}
		}
		 
		if(check)break;
	}
	
	for(int i=0;i<n;i++){
		cout<<bond[i].a<<" "<<bond[i].b<<endl;
	}
	
}
