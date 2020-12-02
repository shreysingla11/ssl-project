#include <iostream>
#include<iomanip>
#include <math.h>

using namespace std;

extern double f (long int i);

int main()
{
    int p,a,b,c,d;
    long int n;
    double fall, fall_max, fall_rate, fall_rate_max;

    fall=0;fall_max=0;fall_rate=0;fall_rate_max=0;

    cin>>n;

    long int i;

    double max_element = f(1);
    double fi,fnext;

    fnext=f(1);

    for(i=1;i<=n;i++)
    {
        fi = fnext;
        fnext=f(i+1);

        if((n==2)&&(fnext>fi))
        {
            break;
        }

        if((max_element - fi) > fall_max)
        {
            fall_max = max_element - fi;
        }

        if(fi > max_element)
        {
            max_element = fi;
        }

        if(i!=n)
        {
        fall_rate = (fi-fnext);
        }

        if (fall_rate > fall_rate_max)
        {
            fall_rate_max = fall_rate;
        }
    }

    std::cout << std::fixed;
    std::cout << std::setprecision(6);

    cout<<"Maximum fall = "<<fall_max<<endl;
    cout<<"Maximum rate of fall = "<<fall_rate_max<<endl;


    return 0;
}
