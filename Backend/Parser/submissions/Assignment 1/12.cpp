#include<iostream>
#include<math.h>
#include<iomanip>
#include<stdio.h>
using namespace std;
extern double f (int i);
int main()
{
double max=0,max1=0,fall=0,rate=0;int i,j,n;

cout<<"total no of elements in the sequence:" ;
cin>>n;
for(i=1;i<n+1;i++)
{
    for(j=i+1;j<n+1;j++)
    {
        if(f (i)>= f (j))
            {fall=f (i)-f (j);
             rate=fall/(j-i);
            }

        if (max<fall){max=fall;}

        if(max1<rate){max1=rate;}

    }

}
printf("%0.6f",max);//max indicates the maximum value of fall in the sequence
cout<<endl;
printf("%0.6f",max1);//max1 indicates the maximum rate over all the falls
}

