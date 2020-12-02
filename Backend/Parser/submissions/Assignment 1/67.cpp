

#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

double f(int );


int main() {

    int i=2,j,k=2;
    double maximum= f(1);
    double maximumFall=(f(2)-f(1));
    if(maximumFall< (f(1)-f(2))){maximumFall=(f(1)-f(2));  }
    int n=0;
    double resultfall=0;
    double resultrate=0;

        cout<<"enter n: \n";
        cin >> n;// n>=2 given
        //for fall
        while (i<=n){
            if( f(i-1)> maximum ) { maximum=f(i-1);}


            if ( (maximum-f(i))>=resultfall ){
                resultfall = maximum - f(i) ;
            }

        i++;
        }// fall ends


    //for rate of fall
        while (k<n){
            if( (f(k)-f(k-1)) > maximumFall ) {maximumFall = (f(k)-f(k-1)) ;}
            if( (f(k+1)-f(k)) > maximumFall ) {maximumFall = (f(k+1)-f(k)) ;}
            k++;
        }

    printf("%s %0.6f \n","the maximum fall is :",resultfall);
    printf("%s %0.6f \n","the maximum fall rate is :",maximumFall);

return 0;}

