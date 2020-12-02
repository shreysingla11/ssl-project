#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
extern double f(int i);
int main()
{
    double maxFall=0,maxRateFall=0;
    double maxTillI=f(0),maxI=0;
    int n;
    cin>>n;
//for(int i=0;i<n;i++)
//{
//    double fi=f(i),fj;
//    for(int j=i+1;j<n;j++){
//    fj=f(j);
//    if(fi >= fj){
//    double dif=fi-fj;
//    if(dif>maxFall){
//    maxFall=dif;
//    }
//    dif=dif*1.0/(j-i);
//    if(dif>maxRateFall){
//    maxRateFall=dif;
//    }
//    }
//    }
//}
    for(int i=1; i<n; i++)
    {
        double fi=f(i);
        if(fi>=maxTillI)
        {
            maxTillI=fi;
            maxI=i;

            continue;
        }
        if((maxTillI-fi)>maxFall)
        {
            maxFall=maxTillI-fi;
        }
        if(i<10000){
        int j=i-1;
        double presentBest=0,fj,dif;
        while(j>=maxI)
        {
            fj=f(j);
            dif=(fj-fi)*1.0/(j-i);
            if(dif>presentBest)
            {
                presentBest=dif;
            }
            j--;
        }
        if(presentBest>maxRateFall)
        {
            maxRateFall=presentBest;
        }
}
    }
    printf("%f  %f",maxFall,maxRateFall);

//cout<<maxFall<<"  "<<maxRateFall;
}
