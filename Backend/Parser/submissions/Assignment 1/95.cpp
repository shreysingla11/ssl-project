#include <iostream>
#include <cmath>
#include <cstdio>
# define fr(i,n) for(int i=0;i<n;i++);
# define fr1(i,n) for(int i=1;i<n;i++);
# define fr2(i,n) for(int i=2;i<n;i++);

using namespace std;
//int p,a,b,c,d,n;
extern double f(int i);
//{
//  double ans;
//    if(i==1)ans=10;
//    if(i==2)ans=7;
//    if(i==3)ans=1;
//    if(i==4)ans=4;
//    if(i==5)ans=11;
//    if(i==6)ans=3;
//    if(i==7)ans=5;
//////    //else ans= 0;
////double ans= p * (sin(a*i+b) + cos(c*i+d) + 2);
//   return ans;
//};


int main()
{
    /**DECLARATIONS**/
    double latest,curr_max,curr_min,glo_max,fall,but_one,max_slope;

    /**INITIALISATIONS**/
    //cin>>p>>a>>b>>c>>d>>n;
    int n;
    cin>>n;
    fall=0;
    max_slope=0;
    curr_max=f(1);
    curr_min=curr_max;
    glo_max=curr_max;
    latest=f(1);

    for(int i=2; i<=n; i++)
    {
        /**CODE for calculating max_fall**/
        but_one=latest;
        latest=f(i);
        if(latest<=curr_min)
        {
            curr_min=latest;
            curr_max=glo_max;
            fall=curr_max-curr_min;
        }
        else
        {

            if((glo_max-latest)>fall)
            {
                curr_min=latest;
                curr_max=glo_max;
                fall=curr_max-curr_min;
            }
            if(glo_max<latest)glo_max=latest;
        }

        /**CODE for calculating max_fall_Slope**/
        if((but_one-latest)>max_slope)max_slope=but_one-latest;

    }
   // std::cout.precision(6);
    //cout<<fall<<endl;
    //cout<<max_slope<<endl;
    printf("%.6f",fall);
    cout<<endl;
    printf("%.6f",max_slope);
    cout<<endl;
    return 0;
}
