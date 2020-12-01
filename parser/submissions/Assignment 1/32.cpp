#include<iostream>
#include<math.h>
#include<cstdio>
using namespace std;
extern double func(int x);
int main()
{
    int n;
    cin>>n;
    double *M;
    M=new double [n/2];

    double *m;
    m=new double [n/2];
    double *M_m;
    M_m=new double [n/2];
    double *Slope;
    Slope=new double [n/2];
    int Mind=0,mind=0;
    int temp=0;
    double Max=0;
    double maxSlope=0;
    for(int i=1; i<n; i++)
    {
        if(temp%2==0&&func(i)>=func(i+1))
        {
            M[Mind]=func(i);
            temp++;
            Mind++;
        }
        else
        {
            if(temp%2==1&&func(i)<=func(i+1))
            {
                m[mind]=func(i);
                temp++;
                mind++;
            }
        }
    }
    if(func(n-1)>func(n))
    {
        m[mind]=func(n);
        mind++;
    }else {}
    cout<<"Mind"<<Mind<<endl;
    cout<<"mind"<<mind<<endl;

    //for(int i=0;i<Mind;i++){cout<<"Mind"<<Mind<<"   "<<"i"<<i<<"    "<<M[i]<<endl;}
   //for(int i=0;i<mind;i++){cout<<"mind"<<mind<<"   "<<"i"<<i<<"    "<<m[i]<<endl;}
    for(int i=0; i<Mind; i++)
    {
        M_m[i]=0;Slope[i]=0;
        for(int j=i; j<mind; j++)
        {
            if((M[i]-m[j]>M_m[i]))
            {//cout<<"dfghj"<<endl;
                M_m[i]=M[i]-m[j];
            }
            if(Slope[i]<(M[i]-m[j])/(j-i)){Slope[i]=(M[i]-m[j])/(j-i);}
            if((M[i]-m[j]>M_m[i]))
            {//cout<<"dfghj"<<endl;
                M_m[i]=M[i]-m[j];
            }
            if(Slope[i]<(M[i]-m[j])/(j-i)){Slope[i]=(M[i]-m[j])/(j-i);}
        }
    }
    for(int i=0; i<Mind; i++)
    {
        if(M_m[i]>Max)
        {//cout<<"sdhj"<<endl;
            Max=M_m[i];
        }
        if(Slope[i]>maxSlope){
        maxSlope=Slope[i];
        }
    }
    printf("%.6f",Max);
    printf("%.6f",maxSlope);
}


