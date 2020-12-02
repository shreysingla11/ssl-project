#include<cmath>
#include<cstdio>


extern double f(int i);
/*{
int p=72,a=90,b=242,c=453,d=236;
    return p*(sin(a*i+b) + cos(c*i+d) + 2);
}*/

void fall(int n)
{
    int i=2;
    double fal=0,maxi=f(1),falrate=0,first=maxi,sec;
    while(i<=n)
    {
        sec=first;
        first=f(i);
        if(first>=maxi){maxi=first;}
        if(fal<maxi-first){fal=maxi-first;}
        if(sec-first>falrate){falrate=sec-first;}
        i++;
    }
    printf("%.6f\n",fal);
    printf("%.6f\n",falrate);
}

int main()
{
    int n;
    scanf("%d",&n);
    fall(n);
}
