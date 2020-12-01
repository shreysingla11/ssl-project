#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int t1,t2;

void lane(vector<pair<double, int> >& v){
		double a = 0.0;
		int current = 0;
		sort(v.begin(), v.end());
		for(int i=0; i+1< v.size();i++){
			current +=v[i].second;
			if(v[i].first < t1) continue;
			if(v[i+1].first > t2) continue;
			if(current == 0){
				a = max(a, v[i+1].first - v[i].first);
			}
	}
	printf("%.8lf\n", a);
}

int main(){
	int width,vs,vf,n;
	//double arr[n];
	vector<pair<double, int> > arr[n];
	while(cin>> n >> width >> vs >> vf >> t1 >> t2){
		vector<pair<double, int> > v;
		v.push_back(make_pair(t1,0));
		v.push_back(make_pair(t2,0));
		for(int p=0;p<n;p++){
			char direction;
			cin >> direction;
			int m;
			cin >> m;
			int l,P ;
			for(int i=0;i<m;i++){
				cin>>l>>P;
				if(direction == 'W')P = -P;
				v.push_back(make_pair(-P/(double)vs - (p+1)*width/(double)vf, 1));
				v.push_back(make_pair((-P+l)/(double)vs - i*width/(double)vf, -1));
			}
			vector<pair<double, int> > a = v;
			arr[p] = a;

		}

		/*	for(int i=0;i<n;i++)
			{
				cout<< "if the number of lanes was";
				cout<< i+1 << " ";
				cout<< setprecision(8) << arr[i] <<endl;
			}*/
		//printf("\n");
		//for(int i=0;i<n;i++){
		//	printf("if the number of lanes was %d %.8lf\n", i+1, arr[i]);
		//}
				for(int i=0;i<n;i++){
					cout<<"If the number of lanes was"<<" "<<i+1<< " ";
					lane(arr[i]);
				}

		}
	}






