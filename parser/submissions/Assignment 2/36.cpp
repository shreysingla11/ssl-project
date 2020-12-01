#include<iostream>
using namespace std;
double slope(int x1,int y1,int x2,int y2){
return (y2-y1)/(x2-x1);
}

}
int main(){
int n,x,m;
cin>>n;
n=x/2;
int R[n][2];
int B[n][2];
for(int i=0;i<n;i++){
cin>>R[i][0]>>R[i][1];
}
for(int i=0;i<n;i++){
cin>>B[i][0]>>B[i][1];
}
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        for(int p=i+1;p<n;p++){
            for(int q=0;q<n;q++){
                if(slope(R[p][0],R[p][1],B[q][0],B[q][1])==slope(R[i][0],R[i][1],B[j][0],B[j][1])){
                    m=slope(R[p][0],R[p][1],B[q][0],B[q][1];
                    goto lab;
                }
            }
        }

    }
}
lab:
cout<<p+1<<" "<<q+1;
cout<<i+1<<" "<<j+1;





return 0;
}
