#include<iostream>
#include<cmath>
#include<iomanip>
/*Fall computes in o(n) fallrate is o(n^2)*/
using namespace std;


extern double num(long long int n);


int main()
{
    long long int n;
    cin>>n;

    double fall=0.0,rate=0.0,temp=0.0;

    for(long long int i=0;i<n;i++)
    {
        double first=num(i),second=num(i+1);
        if (first-second > temp + first-second) {temp = first-second;}
        else{temp = temp + first-second;}
        if (temp > fall) {fall = temp;}

    }
    cout<<fixed;
    cout<<setprecision(6)<<fall<<endl;
    //Fall rate is output in n^2 order
    /*double fallrate=0.0,temprate=0.0;
    for(int i=1;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(num(i)>num(j))
            {
                temprate = (num(i)-num(j))/(j-i);
                if(fallrate<temprate) {fallrate=temprate;}
            }
        }
    }*/
    //cout<<setprecision(6)<<fallrate<<endl;
    return 0;
}
