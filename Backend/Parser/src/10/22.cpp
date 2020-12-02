#include<iostream>
#include<vector>
using namespace std;
class distinct
{
 int *A,*l;

public:
distinct(vector<int> &v)
 {
   int n=v.size();
   A=new int[n];
   l=new int[n];
   for(int i=0;i<n;i++)
    {
      A[i]=v[i];
    }
    for(int i=0;i<n;i++)
     {
         l[i]=-1;
      for(int j=i-1;j>=0;j--)
        {
         if(A[j]==A[i])
         {
           l[i]=j;
           break;
         }
        }
     }






 }
 int num_distinct(int i,int j)
  {
   int result = j-i+1;
   int k=0;
   for(int a=i;a<j+1;a++)
     {
      if(l[a]>=i) k++;
     }
  return result-k;
  }
};

