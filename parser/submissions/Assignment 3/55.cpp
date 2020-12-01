#include<iostream>
#include<limits>
using namespace std;

int m,n;
int infinity=std::numeric_limits<int>::max();

int L(int i, int j,int l[][2],int A[],int B[]){
int L[m];
int a=i-1,b=j-1;
for(int k=0;k<m;k++){L[k]=l[k][0];}
if(a==n-1&&j<m-1){return infinity;}
else if(a<n-1&&b<m-1){
    if(A[a]==B[b]){
            return 1+L[b+1];}
    else{return L[b];}
}
else if(a==n-1&&b==m-1){
    if(A[a]==B[b]){return 1;}
    else{return infinity;}
}
else if(a<n-1&&b==m-1){if(A[a]==B[b]){return 1;}
else{return L[b];}}

}

int main(){
int i,j,mi,tem,least;
cin>>n>>m;cout<<"\n";
int a[n],b[m],l[m][2];
for(i=0;i<n;i++){cin>>a[i];}cout<<"\n";
for(i=0;i<m;i++){cin>>b[i];}cout<<"\n";
mi=infinity;
tem=mi;
l[0][1]=infinity;
for(i=n;i>0;i--){
    for(j=m;j>0;j--){l[j-1][1]=L(i,j,l,a,b);}
    for(j=m-1;j>=1;j--){l[j][0]=l[j][1];}
    if(i>1){tem=L(i-1,1,l,a,b);}
    if(n-i>=m-1){
        if(mi>tem){mi=tem;least=i;}
        }
        l[0][0]=tem;
        }
if(mi<infinity){
cout<<mi+1<<" "<<least-1;}
else{cout<<"infinity";}
return 0;
}
