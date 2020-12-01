#include<iostream>
#include<cstdio>
#include<string>
#include<bitset>

using namespace std;

void comp(long long int &ll)
{
    //bitset< 45 > a;
    string a=bitset< 45 > (ll).to_string();
    //cout<<a<<endl;
    int x=0;
    bool b=true;
    int c1,c2;
    int val=0;
    c1=0;c2=0;
    for(int i=0;i<9 && b==true;i++)
    {
        if(a[i]=='0'){c1++;}
        else c2++;
    }
    x=x+min(c1,c2);
    //cout<<c1<<c2<<endl;
    if(x>4)b=false;
    else if(c2>c1) val=val+16;
    //cout<<val<<endl;
    c1=0;c2=0;
    for(int i=9;i<18 && b==true;i++)
    {
        if(b==false)break;
        if(a[i]=='0')c1++;
        else c2++;
    }
    x=x+min(c1,c2);
    if(x>4)b=false;

    else if(c2>c1) val=val+8;
    //cout<<val<<endl;
    c1=0;c2=0;
    for(int i=18;i<27 && b==true;i++)
    {
        if(b==false)break;
        if(a[i]=='0')c1++;
        else c2++;
    }
    x=x+min(c1,c2);
    if(x>4)b=false;
    else if(c2>c1) val=val+4;
    //cout<<val<<endl;
    c1=0;c2=0;
    for(int i=27;i<36 && b==true;i++)
    {
        if(b==false)break;
        if(a[i]=='0')c1++;
        else c2++;
    }
    x=x+min(c1,c2);
    if(x>4)b=false;
    else if(c2>c1) val=val+2;
    //cout<<val<<endl;
    c1=0;c2=0;
    for(int i=36;i<45 && b==true;i++)
    {
        if(b==false)break;
        if(a[i]=='0')c1++;
        else c2++;
    }
    x=x+min(c1,c2);
    if(x>4)b=false;
    else if(c2>c1) val=val+1;

    if(x>4) cout<<'?';
    else cout<<char(val+'a');
    //cout<<val;
}

int main()
{/*
    long long x=510000000;
    unordered_map<string , char> u_map;

    for(int i=1;i<=10000000;i++) comp(x);
*/
    int n;
    long long y;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&y);
        comp(y);
    }

}
