#include <iostream>
#include<list>
using namespace std;

int main ()
{

int n,m;
  cin>>n>>m;
int*first=new int (n),*second=new int(m);
for(int i=0;i<n; i++)
{

  cin>>first[i];
}
for(int i=0;i<n; i++)
{
  cin>>second[i];
}
 vector<int> current(n,-1)
 vector<int>computed(n,-1)
 if first (n-1) = seconnd (m-2)
 for (int i=n 2 i!=-1 i--)

 {
 if (first (i)=second (m-1))
 {
 current i= 1 if a_n == b_m otherwise it is 1+L[i+1,m], for 1 <= i < n;

current (i)=1; computed i++;
}
   computed =current;


cout (<<endl);
 for int i=o, i++;

if (int j=n,2;j>>1 j--)

 computed=current;
 current (n-1)=1;
 for int (i=n-2; i>-1; i++)
  {

 if (first(i)=second (j))

{
   if (computed (i+1)!=-1)
   {
   current i = 1 + computed (i+1)
  }
 else
      {
      current (i)=1;
     }
    }
    }
    int ans =current(0)


