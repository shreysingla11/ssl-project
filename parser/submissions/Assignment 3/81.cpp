#include<iostream>
#include<fstream>
#include<vector>
#include<limits>

using namespace std;

int main() {
int n,m;
cin>>n>>m;
vector<int> a,b;
a.reserve(n); b.reserve(m);
int i,j;

for(i=0;i<n;i++) {
cin>>j;
a.push_back(j);
    }

for(i=0;i<m;i++) {
cin>>j;
b.push_back(j);
    }

float L[n][m];

if(a[n-1]==b[m-1]) {L[n-1][m-1]=1;}
else {L[n-1][m-1]=numeric_limits<float>::infinity();}

for(i=n-2;i>=0;i--) {
    if(a[i]==b[m-1]) {L[i][m-1]=1;}
    else {L[i][m-1]=1+L[i+1][m-1];}
    }

for(j=m-2;j>=0;j--){
    L[n-1][j]=numeric_limits<float>::infinity();
    }

for(i=n-2;i>=0;i--){
    for(j=m-2;j>=0;j--) {
        if (a[i]==b[j]) {L[i][j]=1+L[i+1][j+1];}
        else {L[i][j]=1+L[i+1][j];}
    }
}

float mini=L[0][0]; int index=0;

for(i=1;i<n-1;i++) {
    if (L[i][0]<mini) {mini=L[i][0]; index=i+1;}
    }

if(mini==numeric_limits<float>::infinity()) cout<<"infinity";
else cout<<mini<<" "<<index;

return 0;
}
