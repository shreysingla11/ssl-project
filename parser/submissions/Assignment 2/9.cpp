#include <iostream>
#include <vector>

using namespace std;

bool isSameSide(int x1, int y1, int M, int x3, int y3, int x4, int y4) {

	if(((M*(x3-x1)-(y3-y1)) > 0) && ((M*(x4-x1)-(y4-y1))>0)){
		return true;
	}
	else if(((M*(x3-x1)-(y3-y1)) < 0) && ((M*(x4-x1)-(y4-y1)) < 0)){
		return true;
	}
	else{
		return false;
	}
}


bool isIntersect(vector<int> P1, vector<int> P2, vector<int> P3, vector<int> P4){

	int x_1=P1[0];
	int y_1=P1[1];

	int x_2=P2[0];
	int y_2=P2[1];
	
	int x_3=P3[0];
	int y_3=P3[1];
	
	int x_4=P4[0];
	int y_4=P4[1];


	float M1=(float)(y_2-y_1)/(float)(x_2-x_1);
	if((x_2-x_1)==0){
		M1=100000;
	}

	float M2=(float)(y_4-y_3)/(float)(x_4-x_3);

	if((x_4-x_3)==0){
		M2=100000;
	}

	if(M1==M2){
		//not intersect
		return false;

	}

	else{

		if( (isSameSide(x_1, y_1, M1, x_3, y_3, x_4, y_4)==true) || (isSameSide(x_3, y_3, M2, x_1, y_1, x_2, y_2)==true) ) {
			// cout<<"on same side"<<endl;
			return false;
			//not intersect;
		} 
		else{
			// cout<<"not on same side"<<endl;
			return true;
			//intersect;
		}
	}
}


int main(){

	int Num;
	cin>>Num;

	vector<vector<int> > RedPoints;
	vector<vector<int> > BluePoints;


	for(int i=0; i<Num/2; i++){
		vector<int> Point;
		int x,y;
		cin>>x>>y;
		Point.push_back(x);
		Point.push_back(y);
		RedPoints.push_back(Point);

	}

// cout<<"RedPpints"<<endl;
// for(int i=0; i<RedPoints.size(); i++){
// 	cout<<RedPoints[i][0]<<" "<<RedPoints[i][1]<<endl;
// }

	for(int i=0; i<Num/2; i++){
		vector<int> Point;
		int x,y;
		cin>>x>>y;
		Point.push_back(x);
		Point.push_back(y);
		BluePoints.push_back(Point);

	}


// cout<<"BluePpints"<<endl;
// for(int i=0; i<RedPoints.size(); i++){
// 	cout<<BluePoints[i][0]<<" "<<BluePoints[i][1]<<endl;
// }

// cout<<endl;

	//assining 0-0, 1-1,...  that is the initaal arbitary matching
	vector<vector<int> > Pairs(Num/2, vector<int>(2,0));
	for(int i=0; i<Num/2; i++){
		Pairs[i][0]=i;
		Pairs[i][1]=i;
	}

// cout<<"Pair size:" <<Pairs.size()<<endl;
// for(int i=0; i<Pairs.size(); i++){
// 		cout<<Pairs[i][0]<<" "<<Pairs[i][1]<<endl;
// 	}

// cout<<endl;




	for(int i=1; i<Num/2; i++){
		for(int k=0; k<i; k++){

			// cout<<i<<" "<<k<<endl;
			// cout<<Pairs[i][0]<<" "<<Pairs[i][1]<<" "<<Pairs[k][0]<<" "<<Pairs[k][1]	<<endl;
			if(isIntersect(RedPoints[Pairs[i][0]], BluePoints[Pairs[i][1]], RedPoints[Pairs[k][0]], BluePoints[Pairs[k][1]])==true){
				int temp=Pairs[k][1];
				Pairs[k][1]=Pairs[i][1];
				Pairs[i][1]=temp;
				// cout<<"intersect"<<endl;
			} 

		}
		// cout<<endl<<endl;
	}



// cout<<endl<<"Pairs"<<endl;
	for(int i=0; i<Pairs.size(); i++){
		cout<<Pairs[i][0]<<" "<<Pairs[i][1]<<endl;
	}



	return 0;
}