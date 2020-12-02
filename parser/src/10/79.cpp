#include <iostream>
#include <vector>
using namespace std;
/*class Node
{
public:
int *vec;
int *vec1;
Node *next;
};*/
class distinct
{
 public:
 //Node *root;
 vector<vector<int> > L;
 vector<int> l;
distinct(vector<int> input)
{
  vector<int> temp(input.size(),-1);
  l=temp;
   for(int i=0;i<input.size();i++)
	 {
       for(int j=i-1;j>=0;j--)
       {
        if(input[j]==input[i])
        {
        	l[i]=j;
        	break;
        }
       }
   }
       int n=input.size();
       L.resize(n);
       for(int i=0;i<n;i++)
       {
       	L[i].resize(n);
       }

      for(int i=0;i<n;i++)
      {
      	for(int j=0;j<n;j++)
      	{
      	if(j<=i)
      	{
      		L[i][j]=0;

      	}
      	else
      	{
      		if(l[j]>=i)
      		{
      			L[i][j]=L[i][j-1]+1;
      		}
      		else
      		{
      			L[i][j]=L[i][j-1];
      		}

      	}


      }

	 }


}
int num_distinct(int i,int j)
{
	/*int count=0;
 for(int a=i+1;a<=j;a++)
 {
    if(l[a]>=i){count++;}
 }*/

return j-i+1-L[i][j];}

};

int main()
{
vector<int> input(8);
for(int i=0;i!=8;i++)
{
	cin>>input[i];
}
distinct s(input);
int i,j;
for(int a=1;a<5;a++)
{
cin>>i>>j;
cout<<s.num_distinct(i,j)<<endl;
}
return 0;
}
