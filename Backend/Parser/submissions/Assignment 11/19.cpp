#include<iostream>
#include<unordered_map>
#include<map>
#include<vector>
#include<string>
#include<cstdio>
using namespace std;
typedef unordered_map<long long int,char> stringmap;
char man(char c)
{
    if(c=='0')
    {
        return '1';
    }
    else
    {
        return '0';
    }
}
string tostring(int a)
{
    string s(45,'0');

    int l=44;
    while(a!=0)
    {
        int r=a%2;
        if(r==1)
        {
            int j=l;
            while(j!=l-9)
            {
                s[j]='1';
                j--;
            }
        }
        l=l-9;
        a=a/2;
    }
    return s;
}
long long int binary(int a)
{
    long long int s=511;
    long long int x=1;
    long long int y=0;
    while(a!=0)
    {
        int r=a%2;
        y=y+r*x*s;
        x=x*(s+1);
        a=a/2;
    }
    return y;
}
long long int binary(string s)
{
    long long int y=0;
    int i=0;
    while(i!=45)
    {
        if(s[i]=='1')
        {
            y=y*2;
            y=y+1;
        }
        else
        {
            y=y*2;
        }
        i++;
    }
    return y;
}
void perm(stringmap& A,int a,char c)
{
    int i,j,k,m;
    string s=tostring(a);
    string n;
    for(i=0; i<45; i++)
    {
        for(j=i+1; j<45; j++)
        {
            for(k=j+1; k<45; k++)
            {
                for(m=k+1; m<45; m++)
                {
                    n=s;
                    n[i]=man(s[i]);
                    n[j]=man(s[j]);
                    n[k]=man(s[k]);
                    n[m]=man(s[m]);
                    A[binary(n)]=c;
                }
                n=s;
                n[i]=man(s[i]);
                n[j]=man(s[j]);
                n[k]=man(s[k]);
                A[binary(n)]=c;
            }
            n=s;
            n[i]=man(s[i]);
            n[j]=man(s[j]);
            A[binary(n)]=c;
        }
        n=s;
        n[i]=man(s[i]);
        A[binary(n)]=c;
    }
    return ;
}
int main()
{
    int n;
    cin>>n;
    stringmap tree;
    int k=0;
    while(k!=26)
    {
        tree[binary(k)]=char(int('a')+k);
        perm(tree,k,char(int('a')+k));
        k++;
    }
    long long int *A=new long long int[n];
    int i=0;
    while(i!=n)
    {
        scanf("%lld",&A[i]);
        if(tree.count(A[i])==1)
        {
            printf("%c",tree[A[i]]);
        }
        else
        {
            printf("?");
        }
        i++;
    }
}
