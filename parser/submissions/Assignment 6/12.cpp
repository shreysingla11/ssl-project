#include<iostream>
#include<string>
using namespace std;
int main()
{
 string A; int Count=0;
 cin>>A;
 int n=A.length();
 double l;
for(l=1;l<n;l++)
    {
        for(double i=0.0;i<((n*1.0)/l);i++)
        {
        if(A.substr(i,l)==A.substr(i+l,l))
          {
           Count=Count+1;
           cout<<l<<" "<<i<<endl;
           break;
          }

        }

    }
//cout<<Count<<endl;
if(Count==0){cout<<"0 0";}
return 0;
}
