#include <iostream>
#include <set>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;


class ships{
    public :
        char direction;
        int length;
        int coordinate;
        int lane;
};
class pairs {
    public :
        double point;
        char se;
        int collisions;
        pairs(){
            point = 0;
            se='a';
            collisions=0;
        }
};
bool compare(pairs a, pairs b){
    return a.point<b.point;
}
int main() {
    int n,w,u,v,t1,t2;
    vector<ships> S;
    cin>> n>> w>> u>> v>> t1>> t2;
    vector<int> M(n,0); // ships in each lane
    vector<pairs> A; // all ships
    double tend,tstart;
    ships tempShip;
    pairs tempPair;
    for (int i=0; i<n ; i++){
        cin>>tempShip.direction>>M[i];
        tempShip.lane= i;
        for (int j=0; j<M[i]; j++){
            cin>>tempShip.length>>tempShip.coordinate;
            S.push_back(tempShip);
            if(tempShip.direction=='E' ){
                tend= double(double(abs((tempShip.coordinate))+tempShip.length)/double(u) )- double( double(tempShip.lane*w)/double(v) );
                tstart= double( double(abs(tempShip.coordinate))/double(u) ) -double( double((tempShip.lane+1)*w)/double(v) ) ;
                tempPair.point = tstart; tempPair.se = 's'; A.push_back(tempPair);
                tempPair.point = tend; tempPair.se = 'e'; A.push_back(tempPair);
            }
            if(tempShip.direction=='W' ){
                tend = double ( double(tempShip.coordinate+tempShip.length)/double(u) ) - double(  double(tempShip.lane*w)/double(v) );
                tstart   = double ( double(tempShip.coordinate)/double(u) ) - double( double((tempShip.lane+1)*w)/double(v) ) ;
                tempPair.point = tstart; tempPair.se = 's'; A.push_back(tempPair);
                tempPair.point = tend; tempPair.se = 'e'; A.push_back(tempPair);
            }
        }
    }

    sort (A.begin(), A.end(), compare);
    double max=0;
    double d;
    A[0].collisions=1;
    for (int i =1; i<A.size() ; i++){
        if (A[i].se=='s'){A[i].collisions=A[i-1].collisions+1;}
        if (A[i].se=='e'){A[i].collisions=A[i-1].collisions-1;}
        A.back().collisions=-1;
        if(A[i].collisions==0){
            if(A[i].point<double(t2) && A[i].point > double(t1) ){
                d = A[i+1].point - A[i].point;
                if(d > max){ max = d ; }
            }
        }
        if (A[0].point >double(t1)) {max= (A[0].point-double(t1) > max) ? (A[0].point-double(t1)) : max ; }
        if (A.back().point < double(t2)) {max= (double(t2) -A.back().point > max) ? (double(t2)- A.back().point) : max ; }

    }
    printf("%7.8f" , max) ;
return 0;}
