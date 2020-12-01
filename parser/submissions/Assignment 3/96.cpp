#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n=0,m=0;
    cin>>n;
    cin>>m;

    vector<int> lcol(n);
    vector<int> lcol1(n);
    vector<int> a(n);
    vector<int> b(m);

    int i=0;
    for(i=0; i<n; i++){ cin>>a[i];}
    for(i=0; i<m; i++){cin>>b[i];}

    //computing last column L[i,m]
    if( a[n-1] == b[m-1] )  { lcol[n-1]=1 ;}
    else    { lcol[n-1] = -1 ;}

    for(i=n-2; i>=0; i--){
        if( a[i] == b[m-1] ) { lcol[i] = 1 ;}
        else    { if(lcol[i+1]==-1) {lcol[i] = -1;}
                  else  {lcol[i]=1+lcol[i+1];}
                }
    }

    //computing first column from last column. at this point lcol=L[i,m]
    int j=0,index=n-2;
    lcol1[n-1]=-1;
    for(j=m-2; j>=0; j--){
        for(i=index; i>=0; i--){
            if(a[i]==b[j])  {   if(lcol[i+1]==-1) {lcol1[i] = -1;}
                                else  {lcol1[i]=1+lcol[i+1];}
                            }
            else    {    if(lcol1[i+1]==-1) {lcol1[i] = -1;}
                        else  {lcol1[i]=1+lcol1[i+1];}
                    }
            if(lcol1[i]==-1){index=i;}
        }
        lcol = lcol1;
    }

    //computing min of L[i,0]
    int minindex=0;
    for(i=0; i<n; i++){
        if(lcol[i] <= lcol[minindex] && lcol[i]!=-1)   {minindex=i;}
    }

    cout<<lcol[minindex]<<" "<<minindex+1<<endl;
    return 1;
}
