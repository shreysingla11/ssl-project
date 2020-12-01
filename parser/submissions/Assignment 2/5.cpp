#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > red,blue;

int getslopenum(vector<int> &v,vector<vector<int> > &red,vector<vector<int> > &blue)
{
  return ((blue[v[1]][1]-red[v[0]][1]));
}

int getslopedinom(vector<int> &v,vector<vector<int> > &red,vector<vector<int> > &blue)
{
  return ((blue[v[1]][0]-red[v[0]][0]));
}

float getintercept(vector<int> &v,vector<vector<int> > &red,vector<vector<int> > &blue,int slopenum,int slopedinom)
{ if(slopedinom==0){return 0;}
  else
  {float slope=slopenum/slopedinom;
   return red[v[0]][1]-(slope*red[v[0]][0]);
   }
}

bool isintersecting(vector<int> &v,vector<int> &u,vector<vector<int> > &red,vector<vector<int> > &blue)
{
  float c[2],temp[4];
  int slopenum[2],slopedinom[2];

  slopenum[0]=getslopenum(v,red,blue);
  slopedinom[0]=getslopedinom(v,red,blue);
  slopenum[1]=getslopenum(u,red,blue);
  slopedinom[1]=getslopedinom(u,red,blue);

  c[0]=getintercept(v,red,blue,slopenum[0],slopedinom[0]);
  c[1]=getintercept(u,red,blue,slopenum[1],slopedinom[1]);

 if(slopedinom[0]!=0){
  temp[0]=red[v[0]][1]-(slopenum[0]/slopedinom[0])*red[v[0]][0]-c[0];
  temp[1]=red[v[1]][1]-(slopenum[0]/slopedinom[0])*red[v[1]][0]-c[0];
  }
  else
  {
    temp[0]=-red[v[0]][0];
    temp[1]=-red[v[1]][0];
  }
  if(slopedinom[1]!=0){
  temp[2]=red[u[0]][1]-(slopenum[1]/slopedinom[1])*red[u[0]][0]-c[1];
  temp[3]=red[u[1]][1]-(slopenum[1]/slopedinom[1])*red[u[1]][0]-c[1];}
  else
  {
    temp[2]=-red[u[0]][0];
    temp[3]=-red[u[1]][0];
     }

  if(temp[0]*temp[1]>0&&temp[2]*temp[3]>0) return true;

  else return false;
}

void getcorrectpairing(vector<vector<int> > &pairs,vector<vector<int> > &red,vector<vector<int> > &blue,int n)
{
   int temp,temp_2;
   for(int i=0;i<n-1;i++)
   {
      temp_2=pairs[i][1];
      for(int j=i+1;j<n;j++)
      {
        if(isintersecting(pairs[i],pairs[j],red,blue))
        {
          temp=pairs[i][1];
          pairs[i][1]=pairs[j][1];
          pairs[j][1]=temp;
          break;
        }
      }
      if(pairs[i][1]!=temp_2) getcorrectpairing(pairs,red,blue,n);
   }

   return;
}

int main()
{
    int N;
    cin>>N;
    int n=N/2;
    vector<vector<int> > red(n),blue(n),pairs(n);
    cout<<endl;

    for(int i=0;i<n;i++)
    {vector<int> v(2,0);
     red[i]=v;
      cin>>red[i][0];
      cin>>red[i][1];
    }


    for(int j=0;j<n;j++)
    { vector<int> u(2,0);
      blue[j]=u;
      cin>>blue[j][0];
      cin>>blue[j][1];

    }

    for(int k=0;k<n;k++)
    { vector<int> w(2,0);
      pairs[k]=w;
      pairs[k][0]=k;
      pairs[k][1]=k;
    }

    getcorrectpairing(pairs,red,blue,n);



    cout<<"correct pairing is : "<<endl;

    for(int l=0;l<n;l++)
    {
      cout<<"("<<pairs[l][0]<<"  "<<pairs[l][1]<<")"<<endl;
    }

    return 0;
}
