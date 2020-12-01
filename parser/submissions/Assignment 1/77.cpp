#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;

//declaring functions
extern double f(int n);

int main()
{
    //  defining max fall and max fallrate
    double fall = 0,fallrate = 0;

    int n = 0;
    cout << "Provide the value on n:"<<endl;
    cin >> n;

    // defining max and current variables
    int maxindex = 0;
    double maxvalue = 0,curr_fall = 0,curr_fallrate = 0;
    for (int count = 1; count <= n; count++)
    {

        double curr_value = f(count);
        // Update current maximum
        if (curr_value > maxvalue)
            {maxvalue = curr_value;
             maxindex = count;}

        // Update maximum fall
        curr_fall = (maxvalue - curr_value);
        if (curr_fall > fall)
            {fall = curr_fall;
             }

        //update maximum fall rate
        curr_fallrate = (maxvalue - curr_value) / (count - maxindex);
        if (curr_fallrate > fallrate)
            {fallrate = curr_fallrate;}
    }
    printf("%.6f \n",fall);
    printf("%.6f \n",fallrate);
    return 0;
}


