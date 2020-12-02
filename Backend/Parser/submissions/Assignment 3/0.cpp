#include<iostream>
# include<string.h>
# include<stdio.h>
using namespace std;
int scs( char *A, char *B, int n, int m );//scs means shortest common subscript



int main()
{


  char A[] = "1 2 2 1 2 1"; // put n numbers here
  char B[] = "1 1";  //put m numbers here

  int n = strlen(A);
  int m= strlen(B);


cout<<"length of shortest common subscript is  "<<  scs(A,B,n,m);


return 0;
}
int scs (char *A, char *B, int n, int m )
{
   int L[n+1][m+1];
   int i, j;


   for (i=0; i<=n; i++)
   {
     for (j=0; j<=m; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;

       else if (A[i-1] == B[j-1])
         L[i][j] = L[i-1][j-1] + 1;

       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }


   return L[n][m];
}



int max(int p, int q)
{
    return (p>q)? p : q;
}



