#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

extern double f (int k);

int main()
{
        int n;
        cin>>n;
        double fall=0;
        double fallrate=0;
        double max = f(1);
        double temp1,temp3;
        double temp2=max;
        for (int i=2;i<=n;i++) {
            temp1 = f(i);
            temp3 = temp2 - temp1;
            if(temp3>fallrate) {fallrate=temp3;}
            if(temp1>max) {max=temp1;}
            else if (max-temp1>fall) { fall=max-temp1; }
            temp2 = temp1;
        }
        cout<<std::fixed;
        cout<<setprecision(6)<<fall<<endl<<fallrate<<endl;

    return 0;
}

