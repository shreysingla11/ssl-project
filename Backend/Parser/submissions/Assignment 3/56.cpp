#include <iostream>
using namespace std;
int main(){
    int m,n;
    int iReq;
    cout<<"Give the two sizes : "<<endl;
    cin>>n>>m;
    if(n<m || n<2 || m<1){
        cout<<"the first set must be larger than the second one"<<endl;
        return -1;
    }
    int mini = n+1;
    iReq = n+1;
    int A[n], B[m], L[n][2];//using a n x 2 matrix to make it reduce space
    cout<<"give the elements of the first sequence :"<<endl;
    for(int var=0; var<n; var++){
        cin>>A[var];
    }
    cout<<"give the elements of the second sequence :"<<endl;
    for(int var=0; var<m; var++){
        cin>>B[var];
    }

    if(A[n-1]==B[m-1]){L[n-1][1] = 1;}
    else{L[n-1][1] = n + 1;}

    for(int a=1 ;a<n;a++){
        if(A[n-a-1]==B[m-1]){L[n-a-1][1]=1;}
        else{L[n-a-1][1] = 1 + L[n-a][1];}
    }

    for(int j=m-2;j>=0;j--){
        for(int i=n-1;i>=0;i--){
            if(i>(n+j-m)){              //for removing the cases where first set is smaller than the considered second set
                L[i][0] = n + 1;        //assigning them infinity
            }
            else{
                if(A[i]==B[j]){
                    L[i][0] = 1 + L[i+1][1];
                }
                else{
                    L[i][0] = 1 + L[i+1][0];
                }
            }
        }
        for(int swapL=0;swapL<n;swapL++){
            L[swapL][1] = L[swapL][0];
        }
    }

    for(int mnm=n-m; mnm >= 0; mnm--){
        if(L[mnm][0]<=mini){
            mini=L[mnm][0];
            if(A[mnm]==B[0]){iReq=mnm;}
        }
    }

    if(mini>n){cout<<"infinity"<<endl;return 0;}
    else{cout<<mini<<" "<<iReq+1;}
    return 0;
}
