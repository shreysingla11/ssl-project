#include <iostream>
using namespace std;

int length(int x,int y,int A[],int B[],int n,int m);

int main()
{
int n=0,i=0,m=0;
cin>>n>>m;
int* A = new int[n+1];
int* B = new int [m+1];
for(i=0;i<n;i++)
{
    cin>>A[i+1];
}
for(i=0;i<m;i++)
{
    cin>>B[i+1];

}

int* newcolumn=new int [n+1];

int* mini= new int[n];
for(int k=0;k<n;k++){
mini[k]=length(k+1,1,A,B,n,m);
if(mini[k]==0){cout<<mini[k]<<" "<<k-1<<endl;
                return 0;}


}
cout<<"infinite"<<endl;
return 0;
}

int length(int x,int y,int A[],int B[],int n,int m)
{
int store=0;
if((x==n)&&(y==m)){if(A[n]==B[m]){return 1;}else return -1;}
if((x==n)&&(y!=m)){return -1;}
if(y==m){if(A[x]==B[m]) return 1;
            else store= 1+length(x+1,m,A,B,n,m);
                if(store == -1) return -1;else return store;}

if (A[x] == B[y]){
store=1 + length(x+1,y+1,A,B,n,m);
if(store == -1) return -1;else return store;}
else {store = 1+ length(x+1,y,A,B,n,m);
if(store == -1) return -1;else return store;}

}
