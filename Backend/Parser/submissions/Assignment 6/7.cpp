#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string a;
    cin>>a;
    //cout<<a<<endl;
    int n=a.length();
    //abcdefghijklcout<<n<<endl;
    int index=n+1;
    int length=0;

    for(int k=1;k<=n/2;k++)
    {
       //if(k%10==0)cout<<k;
       for(int i=0;i<=(n-2*k);i++)
       {
          for(int j=i;j<i+k;j++)
          {
             if(a[j]!=a[j+k]) break;

             else
             {
               if(j==(i+k-1))
               {
                 index=i;
                 length=k;
                 break;
               }
             }
          }

          if(index==i) break;

       }

       if(length==k) break;

    }

    if(index>n) cout<<0<<"  "<<0;
    else cout<<length<<"  "<<index;
    return 0;
}
