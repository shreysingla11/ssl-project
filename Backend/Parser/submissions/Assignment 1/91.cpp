
#include<cstdio>
#include<cmath>

extern double f(int n);

int main()
   {
    int n;
    double fall=0;
    double temp,temp1;
    scanf("%d",&n);
    double fallr=0;
    double maxi=f(1);


    for (int i=1;i<=n;i++)
        {
         temp=f(i);
         if (temp>=maxi){maxi=temp;}
         else if ((maxi-temp)>=fall){fall=maxi-temp;}
         if(i>1){if ((temp1-temp)>=fallr){fallr=temp1-temp;};}
         temp1=temp;
        }

    printf("%.6lf\n",fall);
    printf("%.6lf\n",fallr);
    return 0;

   }
