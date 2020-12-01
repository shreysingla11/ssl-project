#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

int findMatch(string S, int l, int k){
	int n = S.length();
	int start = l*k;
	int end = l*k+l; //open interval
	int match = start + 2*l-1;
	while (match+l-1<n && match <=start+4*l-2){
		int k=0;
		while (k<l){
			if (S[start+k]==S[match+k]){ k++; }
			else { break; }
		}
		if (k==l){
			return match;
		}
		else{
			if(k==0){match++;}
			else {match = match+k;}
		}
	}
	return -1;
}

int main(){
	string S; cin>>S;
	int n = S.length();
	int l=1;
	for ( ; 2*l<=n; l*=2){
		int numblocks = n/l;
		int smallestsize=-1,index=-1;
		for (int k=0; k<numblocks; k++){
			int match = findMatch(S,l,k);
			if (match==-1) {continue;}
			if (smallestsize!=-1 && match - l*k >= smallestsize) {continue;}
			int back=1;
			while (S[match-back-1]==S[l*k-back-1] && l*k-match>=0 && match-back>l*k+l-1){
				back++;
			}
			back--;
			//now l+back number of elements have been matched
			int front = 1;
			while (S[l*k+l-1+front]==S[match+l-1+front] && match+l-1+front<n && l*k+l-1+front<match-back){
				front++;
			}
			front--;
			if (back+front==match-l*k-l){
				//square found
				if (smallestsize==-1 || match-l*k <smallestsize){
					smallestsize=match-l*k;
					index = l*k - back;
				}
			}
		}
		if (smallestsize>0){
			printf("%d %d", smallestsize,index);
			break;
		}
	}
	if (2*l>n){
		printf("%d %d",0,0);
	}
	return 0;
}