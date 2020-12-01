#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

extern double fun(int n);
/*{
    double value=0;
    //value=sin(3*n+5);
    value=100*(sin(432*n+406)+cos(867*n+60)+2);
    return value;

}*/


int main()
{
    //
    int n,i,j;
   //bool isfall=false;
    double max_fall=0;
    double max_rate=0;
    cout<<"input the value of n"<<endl;
    cin>>n;
    //here n is range of i and j to check
    for(i=1;i<n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            //isfall=(fun(i)>=fun(j));
            if((fun(i)>=fun(j))==true)
            {
                if((fun(i)-fun(j))>max_fall){
                max_fall=fun(i)-fun(j);
                }
                else{};
                if((fun(i)-fun(j)/j-i)>max_rate)
                {
                    max_rate=(fun(i)-fun(j))/(j-i);
                }
                else{};


            }



        }

    }

    //if(isfall==true)
    //{
    cout<<"maxfall           "<<setprecision(9)<<max_fall<<endl;
    cout<<"max rate           "<<setprecision(9)<<max_rate<<endl;
    //}
    return 0;
    }

