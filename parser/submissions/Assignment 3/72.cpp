#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main(){

    int m,n,x;
    cin>>n>>m;
    vector<int> a(n+1);
    vector<int> b(m+1);
    vector<double> c(n+1,0.5),d(n+1,0.5);
    a.push_back(0);
    b.push_back(0);


    for (int s=1; s<=n ; s++){
        cin>> a[s];

    }
    for (int s=1; s<=m ; s++){
        cin>> b[s];

    }

    if(a[n]==b[m]){d[n]=1;}

    for (int i=n-1; i>=1; i--){
        if(a[i]==b[m]){
            d[i]=1;
        }
        else{
            d[i]= 1 + d[i+1];
        }
    }

    //for(int q=1; q<=n ; q++){
    //    cout<<"initial d: " <<d[q] << endl;
    //}

    for(int j=m-1; j>=1 ; j--){

        for(int i=n-1; i>=1 ; i-- ){

            if(a[i]==b[j]){
                c[i] = d[i+1]+1;

            }
            else {
                c[i]=1+ c[i+1];
            }

        }

        d=c;
    }

    double mini=d[1];
    for(int r=1; r<=n ; r++){
        if(fmod(d[r],1.0)==0.0){
            if(d[r]<mini) { mini= d[r];}
        }
    }
    if(fmod(mini,1.0)==0){
        cout<<mini<<" ";

        for(int r=1; r<=n ; r++){
            if(mini==d[r]){cout<< r;}
        }
    }
    else {cout<<"infinity";}
    return 0;
}
