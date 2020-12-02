//140050002 july30,2015
#include<iostream>
#include<vector>
using namespace std;

class point{
public:
	int x,y,id;
};
//v3:red point on left side
//v4:red point on right side
//v5:blue point on left side
//v6:blue point on right side
void pointDivide(point r,point l,std::vector<point> &v1,std::vector<point> &v2,std::vector<point> &v3,std::vector<point> &v4,std::vector<point> &v5,std::vector<point> &v6){
	int n = v1.size();
	if(r.x == l.x){
		for(int i=0;i<n;i++){
			if(v1[i].x < r.x){v3.push_back(v1[i]);}
			else{v4.push_back(v1[i]);}
			if(v2[i].x < r.x){v5.push_back(v2[i]);}
			else{v6.push_back(v2[i]);}
		}
		return;
	}
	double m = ((l.y)-(r.y))/((l.x-(r.x)));
	double c = r.y - (m*(r.x));
	for(int i=0;i<n;i++){
		if((v1[i].y)>((m*(v1[i].x))+c)){v3.push_back(v1[i]);}
		if((v1[i].y)<((m*(v1[i].x))+c)){v4.push_back(v1[i]);}
		if((v2[i].y)>((m*(v2[i].x))+c)){v5.push_back(v2[i]);}
		if((v2[i].y)<((m*(v2[i].x))+c)){v6.push_back(v2[i]);}
	}
	return;
}

//assuming size of v1>0;0<=i<v.size()
point chooseR(std::vector<point> &v1,int i){
	return v1[i];
}

point findB(point r,std::vector<point> &v1,std::vector<point> &v2){
	int n = v2.size();
	for(int i=0;i<n;i++){
		int nrl = 0,nbl = 0;
		if(v2[i].x == r.x){
			for(int j=0;j<n;j++){
				if(v1[j].x < r.x){nrl++;}
				if(v2[j].x < r.x){nbl++;}
			}
		}
		else{
			double m = ((v2[i].y)-(r.y))/((v2[i].x-(r.x)));
			double c = r.y - (m*(r.x));
			for(int j=0;j<n;j++){
				if(v1[j].y > ((m*(v1[j].x))+c)){nrl++;}
				if(v2[j].y > ((m*(v2[j].x))+c)){nbl++;}
			}
		}
		if(nbl == nrl){return v2[i];}
	}
	point p1;
	p1.id = -1;
	return p1;
}

void solution(vector<point>& v1,vector<point>& v2){
    if(v1.size()==0){return;}
	if(v1.size()==1){
		cout<<v1[0].id<<" "<<v2[0].id<<"\n";
		return;
	}
	else{
		point r,l;
		l.id = -1;
		for(int i = 0;(l.id<0)&&(i<(v1.size()));i++){
            r = chooseR(v1,i);
            l = findB(r,v1,v2);
		}
		std::vector<point> v3;
		std::vector<point> v4;
		std::vector<point> v5;
		std::vector<point> v6;
		pointDivide(r,l,v1,v2,v3,v4,v5,v6);
		cout<<r.id<<" "<<l.id<<"\n";
		solution(v3,v5);
		solution(v4,v6);
		return;
	}
}

int main(){
	int n;
	cin>>n;
	vector<point> v1;
	vector<point> v2;
	point temp;
	int temp1;
	char temp2;
	for(int i=0;i<(n/2);i++){
		cin>>temp1;
		temp.x = temp1;
		cin>>temp1;
		temp.y = temp1;
		temp.id = i;
		v1.push_back(temp);
	}
	for(int i=0;i<(n/2);i++){
		cin>>temp1;
		temp.x = temp1;
		cin>>temp1;
		temp.y = temp1;
		temp.id = i;
		v2.push_back(temp);
	}
	solution(v1,v2);
	return 0;
}

