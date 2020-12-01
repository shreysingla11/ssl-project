#include<iostream>
using namespace std;

class counter {
int	* obj;
int n;
public:
	counter(int m){
		obj=new int(m);
		for(int i=0;i<m;i++){
			obj[i]=0;
		}
		n=m;
	}
	counter(){}
	
void increment(int i){
	obj[i]++;
}
void decrement(int i){
	obj[i]--;
}
void reset(int i){
	obj[i]=0;
}
int count(int i){
	return obj[i];
}
int findMax(){
	int max=0;
	for(int i=0;i<n;i++) {
	
	if (obj[i]>max) max=obj[i];	
		}
		return max;
}
int numMax(){
	int enter=0;
	for (int i=0;i<n;i++) {
		if(obj[i]==findMax()) enter++;
		}
		return enter;
}

void printMax(){
	for (int i=0;i<n;i++) {
		if(obj[i]==findMax()) {
			cout<<i<<endl;
			
			}
		}
}
	
	
	
};


