#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>
using namespace std;


std::pair<float,int> sortarr(float C[],int length){
std::pair<float,int> res;
int i;
res.first=C[0];
res.second=0;
for(i=0;i<length;i++)
{   if(C[i]<res.first){
        res.first=C[i];
        res.second=i;
    }

}
return res;
}


float computeL(int A[],int B[],int n,int m,int i,int j){
float result;
float inf = std::numeric_limits<float>::infinity();
if(i<1||i>n)
{
    cout<<"invalid value of i";
    result=-10;
    return result;
}
if(j<1||j>m)
{
    cout<<"invalid value of j";
    result=-10;
    return result;
}

if((i==n)&&(j==m)){
if(A[n]==B[m]){result=1;return result;}
else{result=inf;return result;}
}
else{
if(j==m){
if(A[i]==B[m]){result=1;return result;}
else{result=1+computeL(A,B,n,m,i+1,m);return result;}

}
if(i==n){
result=inf;return result;
}

if(A[i]==B[j]){
result=1+computeL(A,B,n,m,i+1,j+1);
}
else{
result=1+computeL(A,B,n,m,i+1,j);
}
}
return result;
}

int main(){

//vector<int> seq_a,seq_b;
float inf = std::numeric_limits<float>::infinity();
int n,m;
int i;
int result1,result2;
int *a,*b;
float *c;

a = new int[n+1];
b = new int[m+1];
c = new float[n+1];

//input
cin>>n>>m;

for(i=1;i<n+1;i++)
{
    cin>>a[i];
}
for(i=1;i<m+1;i++)
{
    cin>>b[i];
}

//input over


c[0]=n+1;
for(i=1;i<n+1;i++){
c[i]=computeL(a,b,n,m,i,1);
}
std:pair<float,int> result;
result=sortarr(c,n+1);

if((result.second==0)||(result.first==inf)){
    cout<<"infinity";
    return -1;
}

cout<<result.first<<" "<<result.second;
//sorts c in increasing order
//sort(c,c+n+1);
//cout<<c[0];
/*output
cout<<result1<<" "<<result2;
*/
return 0;
}
