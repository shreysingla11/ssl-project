#include<iostream>
#include<unordered_map>
using namespace std;

void ch(int* A,int i)
{
if(A[i]==0){A[i]=1;return;}
if(A[i]==1){A[i]=0;return;}

}

void change(int * A, int r)
{

int c[5];
c[0]=0;c[1]=0;c[2]=0;c[3]=0;c[4]=0;
int i=4;
while(r!=0)
{
c[i]=r%2;
r=r/2;
i--;
}
for(i=0;i<5;i++)
{
for(int j=9*i;j<9*i+9;j++)
{
A[j]=c[i];
}
}
return ;
}

long long int convert(int * A)
{

long long int x=1,s=0;
for(int i=44;i>=0;i--)
{
s+=A[i]*x;
x=x*2;
}
return s;
}
int main()
{
unordered_map<long long int,char> mymap ;

int A[45];
char c=97;
for(int z=0;z<26;z++)
{
c=97+z;
change(A,z);

long long int x;
x=convert(A);

mymap[x]=c;



for(int i=0;i<45;i++)
{
ch(A,i);
x=convert(A);
mymap[x]=c;
ch(A,i);
}

for(int i=0;i<45;i++)
{
for(int j=i+1;j<45;j++)
{
ch(A,i);
ch(A,j);
x=convert(A);
//cout<<convert(A);
//cout<<x<<endl;
mymap[x]=c;
ch(A,i);
ch(A,j);
}

}


for(int i=0;i<45;i++)
{
for(int j=i+1;j<45;j++)
{
for(int k=j+1;k<45;k++)
{
ch(A,i);
ch(A,j);
ch(A,k);


x=convert(A);
mymap[x]=c;
ch(A,i);
ch(A,j);
ch(A,k);
}
}
}

for(int i=0;i<45;i++)
{
for(int j=i+1;j<45;j++)
{
for(int k=j+1;k<45;k++)
{
for(int l=k+1;l<45;l++)
{
ch(A,i);
ch(A,j);
ch(A,k);
ch(A,l);

x=convert(A);
mymap[x]=c;
ch(A,i);
ch(A,j);
ch(A,k);
ch(A,l);
}
}
}
}

}

int n;
cin>>n;

for(int i=0;i<n;i++)
{
long long int x;
cin>>x;
unordered_map<long long int,char>::const_iterator got = mymap.find (x);

  if ( got == mymap.end() )
   {cout << "?";}
   else
{cout<<mymap[x];}
}
cout<<endl;
return 0;
}


