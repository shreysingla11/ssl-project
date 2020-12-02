#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    long int n;
    cout<<"Give n:";
    cin>>n;
    double fun[n];
    //fun[i] stores the value of f(i+1)
    double maxfall=0;// gives maximum fall
    double maxfallrate=0;// gives maximum rate of fall

    for(long int i=0; i<n-1; i++)
    {
        for(long int j=i+1; j<n; j++)
        {
            if(fun[i]>fun[j])
            {
                if(maxfall<(fun[i]-fun[j]))
                {
                    maxfall=fun[i]-fun[j];
                }
                if(maxfallrate<((fun[i]-fun[j])/(j-i)))
                {
                    maxfallrate=((fun[i]-fun[j])/(j-i));
                }
            }
        }
    }

    printf("%.6f",maxfall);
    cout<<endl;
    printf("%.6f",maxfallrate);

    return 0;
}

