#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	float w, u, v, t1, t2;
	//Input
	// n  -> no. of lanes
	// w  -> width of the lanes
	// u  -> the speed of ships
	// v  -> the speed of the ferry
	// t1 -> the ferry’s earliest start time
	// t2 -> the ferry’s latest start time
	cin >> n >> w >> u >> v >> t1 >> t2;
	string dir[n];
	float m[n], tmp1[n], tmp2[n];
	float l[n][100000], p1[n][100000], p2[n][100000];
	for(int i=0; i<n; i++){
		cin >> dir[i];
		cin >> m[i];
		for(int j=0; j<m[i]; j++){
			cin >> l[i][j];
			cin >> p1[i][j];
		}
	}
	
	//Time taken by the ferry to cross the strait ==>
	float t = (w*n)/v;
	
	//Positions of the ships at t1 time and t2 time ==>
	for(int i=0; i<n; i++){
		for(int j=0; j<m[i]; j++){
			if(dir[i] == "E"){
       			p1[i][j] = p1[i][j] + u*t1;
       			p2[i][j] = p1[i][j] + u*t2;
			}
       		else{
				p1[i][j] = p1[i][j] - u*t1;
				p2[i][j] = p1[i][j] - u*t2;
			}
		}
	}
	//Sorting it

	
	vector<float> start;
	vector<float> end;
	float temp1, temp2;
	for(int i=0; i<n; i++){
		for(int j=0; j<m[i]; j++){
			if(dir[i] == "E" && p1[i][j] > 0) break;
			else if(dir[i] == "W" && p1[i][j] < 0) break;
			else if(dir[i] == "E" && p1[i][j] <= 0){
				temp1 = -(p1[i][j]/u);
				if(temp1 >= t1 && temp1 <= t2) start.push_back(temp1);
				temp2 = -(p1[i][j]-l[i][j])/u;
				if(temp2 >= t1 && temp2 <= t2) end.push_back(temp2);
			}
			else if(dir[i] == "W" && p1[i][j] >= 0){
				temp1 = (p1[i][j]/u);
				if(temp1 >= t1 && temp1 <= t2) start.push_back(temp1);
				temp2 = (p1[i][j]+l[i][j])/u;
				if(temp2 >= t1 && temp2 <= t2) end.push_back(temp2);
			}
		}
	}

	for(int i=0; i<start.size(); i++){
		for(int j=i; j<start.size(); j++){
			if(start[i] < 0){
				if(start[j] < 0){
					if(-start[i] > -start[j]){
						float k = start[i];
						start[i] = start[j];
						start[j] = k;
						k = end[i];
						end[i] = end[j];
						end[j] = k;
					}
				}
				else{
					if(-start[i] > start[j]){
						float k = start[i];
						start[i] = start[j];
						start[j] = k;
						k = end[i];
						end[i] = end[j];
						end[j] = k;
					}
				}
			}
			else{
				if(start[j] < 0){
					if(start[i] > -start[j]){
						float k = start[i];
						start[i] = start[j];
						start[j] = k;
						k = end[i];
						end[i] = end[j];
						end[j] = k;
					}
				}
				else{
					if(start[i] > start[j]){
						float k = start[i];
						start[i] = start[j];
						start[j] = k;
						k = end[i];
						end[i] = end[j];
						end[j] = k;
					}
				}
			}
		}
	}
	
	float max = 0;
	for(int i=0; i<start.size()-1; i++){
		cout.precision(8);
		if(max < end[i+1]-start[i]-t) max = end[i+1]-start[i]-t;
	}
	cout << max << endl;
}
