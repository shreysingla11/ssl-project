#include<cstdio>
#include<cmath>

//int p,a,b,c,d;
extern double func(int i);
/*{return p * (sin(a*i+b) + cos(c*i+d) + 2);}*/

int main()
{


    int n;
    //scanf("%d %d %d %d %d",&p,&a,&b,&c,&d);
    scanf("%d",&n);
    double maxfall=0,maxelement=0,element,maxfallrate=0,prevelement;
    for(int i =1;i<=n;i++)
        {
            element = func(i);
            if((maxelement-element)>maxfall)maxfall=maxelement-element;
            if(element>maxelement){maxelement=element;}

            if(i>1){if(prevelement-element>maxfallrate)maxfallrate = prevelement-element;}
            prevelement =element;

        }
        printf("%.6lf\n%.6lf\n",maxfall,maxfallrate);


return 0;

}
