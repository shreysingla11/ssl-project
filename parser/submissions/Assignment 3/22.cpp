#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;


int main()
{
	int n,m;
	cin>>n;
	cin>>m;
	std::vector<int> A(n);
	std::vector<int> B(m);
	std::vector<int> values(n,n+1);
	vector<int> temp(n,n+1);

	int a = n+1;
	int ind = n;
	for (int i = 0; i < n; ++i)
	{
		/* code */
		cin>>A[i];
	}
	for (int i = 0; i < m; ++i)
	{
		/* code */
		cin>>B[i];
	}
	for(int i=n-1; i>=0; i--)
	{ bool flag=false;

	 if(A[i]==B[m-1])
	 {
        values[i]=1;

	 }
    else
    { if(i==n-1)
        values[i]=n+1;
        else
        values[i]=values[i+1]+1;
    }


	}
	for(int j=m-2; j>=0; j--)
	{
      for(int i=n-1; i>=0; i--)
      {
        if(i==n-1)
        {
            temp[i]=n+1;
        }
        else if(A[i]==B[j])
         {
            temp[i]=1+values[i+1];

         }
         else
         {
         temp[i]=1+temp[i+1];
         }


      }
       for(int k=0; k<n; k++)
        {
        values[k]=temp[k];

        }


	}
	for(int i=0; i<n; i++)
	{

        if(values[i]<a)
        {a=values[i];
        ind=i;}
	}

	if(a>=A.size()+1)
	{cout<<"INFINITY "<<ind+1;}
	else
	{cout<<a<<" "<<ind+1;}


	return 0;
}
