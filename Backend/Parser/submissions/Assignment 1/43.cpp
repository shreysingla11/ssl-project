#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

extern double f(int n);

void max_fall (int n)
{
    double maxfall=0,temp=0,vi=0;
    for (int i=1;i<n;i++)
    {
        vi=f(i);
        for (int j=i+1;j<=n;j++)
        {
            temp=vi-f(j);
            if (temp>maxfall)
            {
                maxfall = temp;
            }
            continue;
        }
    }
    cout << setprecision(16) << maxfall << endl;
    return;
}

int main()
{
    int n;
    cin >> n;
    max_fall(n);
    return 0;
}
