#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
  int n;
  int power[5] = {1,2,4,8,16};
  cin>>n;
  for(int i=0;i<n;i++)
  {
     long long int temp;int x=512,answer=0,count_of_errors=0;
     cin>>temp;
     for(int j=0;j<5;j++)
     {
      int a =(temp%x),sum=0,min;
        while(a>=1)
     {
       sum+=(a%2);
       a/=2;
     }
     if(sum>=5)
     {
      min=9-sum;
      answer+=power[j];
     }
     else
     {
      min=sum;
      
     }
      count_of_errors+=min;
      if(count_of_errors>4) break;
      temp/=x;
      }
     char c = ((count_of_errors>4||answer>=26)?'?':(97+answer));
     printf("%c",c);

   }

      return 0;

  }

