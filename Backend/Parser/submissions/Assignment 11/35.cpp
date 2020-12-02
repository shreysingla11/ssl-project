#include <iostream>
#include <unordered_map>
#include <math.h>
#include <vector>
using namespace std;
int main(){
	int i,j,k,l,w,x,y,z,count;
	char c;
	int t;
	long long temp;
	long long exact=0;
	long long error;
	long long final;
	char binary[5];
	int curr;
	long int powerTwo[46];
	powerTwo[0]=1;
	for(int i=1;i<=46;i++){
		powerTwo[i]=(powerTwo[i-1])*2;
		
	}
	
	unordered_map<long long,char> myMap;
	unordered_map<long long,char>::iterator it;
	vector<long long> myVector;

	for (w=1;w<=45;w++){
		for (x=w;x<=45;x++){
			for(y=x;y<=45;y++){
				for (z=y;z<=45;z++){
					error = 0;
					error = powerTwo[45-w];
					if(x!=w) error+=powerTwo[45-x];
					if(y!=x) error+=powerTwo[45-y];
					if(z!=y) error+= powerTwo[45-z];
					myVector.push_back(error);
				}
			}
		}
	}
	
		for (int i=0;i<26;i++){
			c = 'a'+i;
			exact = 0;
			count =i;
			for (j=4;j>=0;j--){
				binary[j]='0'+count%2;
				count/=2;
			}
			
			for(j=4;j>=0;j--){
				exact+= (binary[j]-'0')*powerTwo[36-9*j]*(powerTwo[9]-1);

			}

			
			myMap[exact] = c;
			for (int a=0;a<myVector.size();a++){
				final = (myVector[a])^exact;
				myMap[final]=c;
			}
			
			
		}
		cin>>t;
		for(int d=0;d<t;d++){
			cin>>temp;
			it = myMap.find(temp);
			if (it==myMap.end()){
				printf("?");
			}
			else{
				printf("%c",it->second );
			}
		}
		printf("\n");
	return 0;
}