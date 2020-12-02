#include <iostream>
using namespace std;
int INF;
void getMat (int &temp, int a[], int b[], int** l, int n, int m);
void getCol(int j, int &temp, int a[], int b[], int** l, int n, int );
int main()
{
    int n,m;
    int *a, *b, **l;
   // int k=0;
    int temp;
    cin>>n>>m;
    temp=n-1;
    INF = n+1;
    a = new int[n];
    b = new int[m];
    l = new int*[n];
    for (int i=0; i<n; i++){
        l[i]=new int[2];
    }
    for (int i=0; i<n; i++){
        cin>>a[i];
    }
    for (int i=0; i<m; i++){
        cin>>b[i];
    }
    getMat(temp,a,b,l,n,m);
    int min=l[0][0];
    int index=0;
    for(int i=0; i<=temp; i++){
        if(l[i][0]<min) {min=l[i][0]; index=i;}
    }
    cout<<min<<" "<<(index+1);
    return 0;
}

void getMat (int &temp, int a[], int b[], int** l, int n, int m){
    int j;
    for( j=m-1; j>=0; j--){
        getCol(j,temp,a,b,l,n,m);
        for (int i=n-1; i>=0; i--){
            l[i][1]=l[i][0];
        }

    }
    return;
}

void getCol(int j, int &temp, int a[], int b[], int** l, int n, int m){
    bool flag = true;
    if(j==m-1){
        for(int i=n-1; i>=j; i--){
            if(i==n-1){
                if(a[i]==b[j]) l[i][0]=1;
                else l[i][0]=INF;
            }
            else if(a[i]==b[j]) l[i][0]=1;
                 else l[i][0]=1 + l[i+1][0];
        }
    }
    else{
        for(int i=temp; i>=j; i--){
            if(i==n-1) l[i][0]=INF;
            else if(a[i]==b[j]){
                        l[i][0]=1 + l[i+1][1];
                        if (flag){ flag=false; temp = i;}
                }
                 else l[i][0]=1 + l[i+1][0];
        }
    }
    return;
}
