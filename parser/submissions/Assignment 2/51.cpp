#include<iostream>
using namespace std;

int eline_left(int b,int n, int A[],int B[],int C[],float xr[],float yr[],float xb[],float yb[]);
int eline_right(int b,int n, int A[],int B[],int C[],float xr[],float yr[],float xb[],float yb[]);

bool redleft_blueleft(float xr[], float yr[],int x, float xb[] ,float yb[], int y,int n,int A[], int B[],int C[]){
int redleft=0,blueleft=0;
int i,j;
float a,c;
a=(yb[y]-yr[x])/(xr[x]-xb[y]);
c=((xb[y]*yr[x])-(xr[x]*yb[y]))/(xr[x]-xb[y]);
for(i=0;i<n/2;i++){
if(A[i]==0){
if(a*xr[i]+yr[i]+c>0){
A[i]=0;
redleft++;
}
else{
A[i]=1;
}
}
}
for(i=0;i<n/2;i++){
if(B[i]==0){
if(a*xb[i]+yb[i]+c>0){
blueleft++;
B[i]=0;
}
else{
B[j]=1;
}
}
}
if(redleft==blueleft){
return redleft;
}
else{
return -1;
}
}
int eline_left(int b,int n, int A[],int B[],int C[],float xr[],float yr[],float xb[],float yb[]){
int i,j,k,l;
int*P=A;
int*Q=B;
int*R=C;
for(i=b;i<n/2;i++){
k=redleft_blueleft(xr,yr,b,xb,yb,i,n,P,Q,R);
if(k!=-1){
j=i;
break;
}
}
if(n>2){
for(i=b+1;i<n/2;i++){
if(A[i]==0){
b=i;
}
}
i=2*k;
l=n-2*(k+1);
if(i>0){
C[b]=eline_left(b,i,P,Q,R,xr,yr,xb,yb);}

for(i=b+1;i<n/2;i++){
if(A[i]==1){
b=i;
}
}
if(l>0){
C[b]=eline_right(b,l,P,Q,R,xr,yr,xb,yb);}
}
else{
C[b+1]=b+1-j;
}
return j;
}

int eline_right(int b,int n, int A[],int B[],int C[],float xr[],float yr[],float xb[],float yb[]){
int i,j,k;
int*P=A;
int*Q=B;
int*R=C;
for(i=b;i<n/2;i++){
k=redleft_blueleft(xr,yr,b,xb,yb,i,n,P,Q,R);
if(k!=-1){
j=i;
break;
}
}
if(n>2){
for(i=b+1;i<n/2;i++){
if(A[i]==0){
b=i;
}
}
i=2*k;
int l=n-2*(k+1);
if(i>0){
C[b]=eline_left(b,i,P,Q,R,xr,yr,xb,yb);}
for(i=b+1;i<n/2;i++){
if(A[i]==1){
b=i;
}
}
if(l>0){
C[b]=eline_right(b,l,P,Q,R,xr,yr,xb,yb);}}
else{
C[1+b]=1+b-j;
}
return j;
}




int main(){
int i,n;
float xr[2500],yr[2500],xb[2500],yb[2500],j;
cin>>n;
cout<<"\n";
if(n<2){
return -1;
}
int A[2500],B[2500],C[2500];
int*P=A,*Q=B,*R=C;
for(i=0;i<n/2;i++){
    cin>>xr[i];
    cin>>yr[i];
    cout<<"\n";
}

for(i=0;i<n/2;i++){
    cin>>xb[i];
    cin>>yb[i];
    cout<<"\n";
}
C[0]=eline_left(0,n,P,Q,C,xr,yr,xb,yb);
for(i=0;i<n/2;i++){
cout<<i<<" "<<C[i]<<"\n";
}
return 0;
}
