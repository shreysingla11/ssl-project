#include <bits/stdc++.h>
using namespace std;

extern double f(long long int i);

/*double f(int i, int p, int a, int b, int c, int d){
    return (p*(sin(a*i+b)+ cos(c*i+d)+2));
}

void scan(int& p, int& a, int& b, int& c, int& d){

    scanf("%d%d%d%d%d", &p, &a, &b, &c, &d);
}*/

int main(){

   // int p,a,b,c,d;
    //scan(p, a, b, c, d);
    long long int n;
    scanf("%lld", &n);
    //long long int pos_i, pos_j;
    double maxi, diff1=0.000000, diff2=0.000000, fprev;
     maxi= f(1);
     fprev=maxi;
    for(long long int i=2; i<=n; i++){
        double tmp = f(i);
        if (fprev > tmp){
            diff2 = max(fprev-tmp, diff2);

            }
        if(tmp <maxi){
            if (maxi-tmp > diff1){
                diff1=maxi-tmp;
            }

        }
        if(maxi<tmp){
            maxi=tmp;
        }
        fprev=tmp;
    }
    cout<<fixed<<diff1;
    cout<<endl<<fixed<<diff2<<endl;

}
