#include <iostream>
#include <cstring>
using namespace std;

bool flag=false;
int length=0;
int start=0;
bool find_square(string &s, int l);
void extend(int start1, int start2, int i, string &s);
int main(){

string s;
cin>>s;
int l=1;
for(l; l<s.length(); l*=2){
	if(find_square(s,l)){
		break;
	}
}
cout<<length<<" "<<start<<endl;;
return 0;

}

bool find_square(string &s, int l){
int start1 = 0;
int start2 = 2*l-1;
int i=0;
for(i; i<l && start2<s.length(); i++){
	if(s[start1+i]!=s[start2+i]){
		start2 = start2+i+1;
		i=-1;
		if (start2>start1+4*l-2){
			start1=start1+l;
			start2=start1+l;
		}
		continue;
	}
	else if(i==l-1){
		extend(start1,start2,i,s);
		i=-1;
		start1=start1+l;
		start2=start1+l;
	}
}
return flag;
}

void extend(int start1, int start2, int i, string &s){
	int end1=start1+i;
	int end2=start2+i;
	for(start1; start2>end1+1 && start1>0;){
		if(s[start1-1]!=s[start2-1]){
			break;
		}
		else {
			start1--;
			start2--;
		}
	}
	for(end1; end1<start2-1 && end2<s.length()-1;){
		if(s[end1+1]!=s[end2+1]){
			break;
		}
		else{
			end1++;
			end2++;
		}
	}
	if(end1==start2-1){
		if(end1-start1+1<length || length == 0){
			length = end1-start1+1;
			start = start1;
		}
		if(end1-start1+1==length){
			if (start1<start) start=start1;
		}
		flag = true;
	}
}
