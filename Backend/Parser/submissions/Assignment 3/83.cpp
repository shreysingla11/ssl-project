#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int main() {

long int n,m;
cin>>n>>m;
if(n<m) {cout<<"infinity"<<endl;}
else {
	vector<int> A(n),B(m);
	int min,minIn;
	vector<int> L(n);
	vector<int> L1(n);
	for (int i=0;i<n;i++) {
            L[i]=-1;
//            L1[i]=-1;
    }
//    cout<<L[0][0];
 	for(int i=0;i<n;i++) {
		cin>>A[i];
	}
	for(int i=0;i<m;i++) {
		cin>>B[i];
	}
    minIn=n;
    bool check = false;
	for(int j=m-1;j>=0;j--) {
		for(int i=minIn-1;i>=0;i--) {
			if (j==m-1) {
				if(A[i]==B[j]) {
					L[i] = 1;
					if(check == false) minIn=i;
					check = true;
				}
				else {
					if(L[i+1]!=-1 && i!=n-1) {
						L[i] = 1 + L[i+1];
					}
                    else {L[i]=-1;}
				}
			}
			else {
			if(A[i]==B[j]) {
				L[i] = 1 + L1[i+1];
				if(check == false) minIn=i;
				check = true;
			}
			else {
				if(L[i+1]!=-1 && i!=n-1) {
					L[i] = 1 + L[i+1];
				}
				else {L[i]=-1;}
			}
			}
		}
		check = false;
		for(int a=0;a<n;a++) {
            L1[a] = L[a];
            //L[a] = -1;
            //cout<<L1[a]<<endl;
		}
		L[minIn] = -1;
	}
//	for(int i=0;i<n;i++) {
//        for(int j=0;j<m;j++ ) {
//            cout<<L[i][j]<<" ";
//        }
//        cout<<endl;
//   }
	min = L1[0];
	minIn=1;
    for(int i=0;i<n;i++) {
        if(L1[i]==-1) break;
        if(L1[i]==0) {check = true; cout<<"infinity"<<endl; break;}
        else{
            if(L1[i]<min) {min = L1[i]; minIn = i+1;}
        }
    }
    if(check == false)cout<<min<<" "<<minIn<<endl;
 }
return 0;
}

