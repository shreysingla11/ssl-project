#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Ship{
	public:
		int length; int position;
	void setu(int,int);
	//Ship(int a,int b);
	//~Ship();
	bool operator < (const Ship& str) const{
		return (position < str.position);
		}
	
	};
	
void Ship::setu(int a,int b){
	length = a;
	position = b;
	}
	
//Ship::~Ship(){}
int get_min(int *A, int n){
	int j = A[0];
	for(int i=1;i<n;i++){
		if (A[i] < j) j= A[i];
		//cout<<j<<endl;
		}
	return j;
	}
	

int main(){
int lane, width, spd_s, spd_f, ti, tf;
int ship_num, pos, len;
int desx,desy;
float divi=0;
string s;
int count=0;
Ship des;
vector<Ship> vec;
cin >> lane;cin >> width;
cin >> spd_s; cin >> spd_f;
cin >> ti; cin >> tf;
divi= width/spd_f;
for(int i=0;i<lane;i++){
	cin >> s;
	//cout<<s<<endl;
	cin >> ship_num;
	count = count + ship_num;
	if (s[0]=='W'){
		for(int j=0;j<ship_num; j++){
			cin >> desx; cin >> desy;
			des.setu(desx,(desy-(divi * spd_s * i)));
			vec.push_back(des);
			//cout << "W" <<endl;
			}
		}
	else {
		for(int j=0;j<ship_num; j++){
			cin >> desx; cin >> desy;
			des.setu(desx,((-desy)-(divi * spd_s * i)));
			//des.setu(desx,desy);
			vec.push_back(des);
		}
	}
}

sort(vec.begin(),vec.end());
//for (int i =0; i<6; i++){
	//cout<<vec[i].position<<endl;
	//}

int A[10000];
vector<int> B;
//cout<<count<<endl;
for (int k =0; k<count; k++){
	A[0]= vec[k].position;
	//cout<<A[0];
for (int i =0; i<k; i++){
	
	A[i+1]= vec[k].position-(vec[i].position + vec[i].length);
	//cout<<" "<<A[i+1];
	}
	B.push_back(get_min(A,k+1));
	//cout<<endl;
}
sort(B.begin(),B.end());
//cout<<B[0]<<" "<<B[1]<<" "<<B[2]<<endl;
reverse(B.begin(),B.end());
float jou = (B[0]/spd_s)-(width/spd_f); 
cout << jou << endl;
}
