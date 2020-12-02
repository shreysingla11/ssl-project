#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

void update ( int* m, int r)
{
int d[5];
d[0]=0;d[1]=0;d[2]=0;d[3]=0;d[4]=0;
int i=4;
while(r!=0)
    {
    d[i]=r%2;
    r=r/2;
    i--;
    }
for(i=0;i<5;i++)
{
    for(int j=9*i;j<9*i+9;j++)
    {
    m[j]=d[i];
    }
}
return ;
}

long long int change(int * m)
{
long long int p =0;

for(int i=44;i>=0;i--)
    {
    long long int s=1;
    p=p+ m[i]*s;
    s=s*2;
    }
return p;
}

void construct(int * m, int i)
{
if(m[i]==1){m[i]=0;return;}
if(m[i]==0){m[i]=1;return;}
}

int main()
{

unordered_map<long long int,char> maps;
long long int p;
int m[45];
char a = 97;

for(int r=0;r<26;r++)
{
a=97+r;
update(m,r);
p=change(m);
maps[p]=a;

    for(int i=0;i<45;i++)
    {
        construct(m,i);
        p=change(m);
        maps[p]=a;
        construct(m,i);
    }

    for (int i=0;i<45;i++)
    {
        for(int j=i+1;j<45;j++)
        {
            construct(m,i);
            construct(m,j);
            p=change(m);
            maps[p]=a;
           construct(m,i);
           construct(m,j);
        }
    }

    for (int i=0;i<45;i++)
    {
        for(int j=i+1;j<45;j++)
        {
            for(int k=j+1;k<45;k++)
            {
                construct(m,i);
                construct(m,j);
                construct(m,k);
                p=change(m);
                maps[p]=a;
                construct(m,i);
                construct(m,j);
                construct(m,k);
            }
        }
    }

    for (int i=0;i<45;i++)
    {
        for(int j=i+1;j<45;j++)
        {
            for(int k=j+1;k<45;k++)
            {
                for(int l=k+1;l<45;l++)
                {
                    construct(m,i);
                    construct(m,j);
                    construct(m,k);
                    construct(m,l);
                    p=change(m);
                    maps[p]=a;
                    construct(m,i);
                    construct(m,j);
                    construct(m,k);
                    construct(m,l);
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
        unordered_map<long long int , char>::const_iterator Find = maps.find(x);
        if(Find !=maps.end())
        {
        cout<<maps[x];
        }
        else cout<<"?";
    }
cout<<endl;
return 0;
}
