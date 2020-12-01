#include<iostream>
#include<vector>
#define f 100000
using namespace std;
void grid(vector<vector<int> > l,vector<int> a,vector<int> b,
int &col,int &m,int &n ,int &ct)
{if(col==0){return;}
col--;
ct++;
int row;
if(ct==1){
for(row=m-ct;row>=0;row--)
{if(row==m-ct){
  if(a[row]==b[col]){l[row][col]=1;};
  }
  else{l[row][col]=l[row+1][col]+1;}
  };
  grid(l,a,b,col,m,n,ct);
  }
while(ct<=n&&ct!=1)
{for(row=m-ct;row>=0;row--)
{
  if(a[row]==b[col])
     {l[row][col]=l[row+1][col+1]+1;}
       else{l[row][col]=l[row+1][col]+1;}}
        if(ct!=n){grid(l,a,b,col,m,n,ct);}
        }
        return ;}
int main()
{int m,n;
cin>>m>>n;
if(n>m){cout<<f;
return 0;}
vector<int> a(m);
vector<int> b(n);
vector<int> d(m,f);
vector<vector<int> > l(n,vector<int>(d));
int i=0,col=n;
for(i=0;i<m;i++)
{
  cin>>a[i];}

for(i=0;i<n;i++)
{
  cin>>b[i];}
  int ct=0;
  grid(l,a,b,col,m,n,ct);
  int game=l[0][0];
  int index=0;
  for(i=1;i<m;i++)
  {if(l[i][0]<game)
  {
   game=l[i][0];
   index=++i;};
   };
   cout<<game<<' '<<index;


  return 0;
  }



