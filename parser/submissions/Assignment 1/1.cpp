#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
extern double f(int q);
int main()
{
 int k,n;
 double maxi,fall,fallrate,maxfallrate;
maxi=f(0);
maxfallrate=fallrate;
cin>>n;
fall=fallrate=0.0;

for(k=1;k<n;k++)
{
  double g=f(k);

    if(g>=maxi)
      {
        maxi=g;
      }
    else
       {fall=max(fall,maxi-g);}

      fallrate=f(k+1)-f(k);

   if
      (fallrate>=maxfallrate)
      {
      maxfallrate=fallrate;
      }

}
  cout<<fall<<endl;
   cout<<maxfallrate;
  return 0;
}

extern double f(int k)
{
 double q;
 q= 42* (sin(1*k+23) + cos(4*k+8) + 2);
return q;
}

