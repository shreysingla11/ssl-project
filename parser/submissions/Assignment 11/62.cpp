#include<iostream>
#include<bitset>
#include<string>
#include <unordered_map>

using namespace std;


int main()
{
    unordered_map<bitset<45>,char>bmap;
    //string mainstr = temp.to_string();
    //cout<<str<<endl;
    char a[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','\0'};
for(int p=0;p<26;p++)
{
    bitset<45>mainb;
    if(p==0)
    {
        int x=0;
        mainb=bitset<45>(x);
        bmap[x]='a';
    }
    else if(p==1)
    {
        int x=511;
        mainb=bitset<45>(x);
        bmap[x]='b';
    }
    else if(p==2)
    {
        long long int x=261632;
        mainb=bitset<45>(x);
        bmap[x]='c';
    }
    else if(p==3)
    {
        long long int x=262143;
        mainb=bitset<45>(x);
        bmap[x]='d';
    }
    else if(p==4)
    {
        long long int x=133955584;
        mainb=bitset<45>(x);
        bmap[x]='e';
    }
    else if(p==5)
    {
        long long int x=133956095;
        mainb=bitset<45>(x);
        bmap[x]='f';
    }
    else if(p==6)
    {
        long long int x=134217216;
        mainb=bitset<45>(x);
        bmap[x]='g';
    }
    else if(p==7)
    {
        long long int x=134217727;
        mainb=bitset<45>(x);
        bmap[x]='h';
    }
    else if(p==8)
    {
        long long int x=68585259008;
        mainb=bitset<45>(x);
        bmap[x]='i';
    }
    else if(p==9)
    {
        long long int x=68585259519;
        mainb=bitset<45>(x);
        bmap[x]='j';
    }
    else if(p==10)
    {
        long long int x=68585520640;
        mainb=bitset<45>(x);
        bmap[x]='k';
    }
    else if(p==11)
    {
        long long int x=68585521151;
        mainb=bitset<45>(x);
        bmap[x]='l';
    }
    else if(p==12)
    {
        long long int x=68719214592;
        mainb=bitset<45>(x);
        bmap[x]='m';
    }
    else if(p==13)
    {
        long long int x=68719215103;
        mainb=bitset<45>(x);
        bmap[x]='n';
    }
    else if(p==14)
    {
        long long int x=68719476224;
        mainb=bitset<45>(x);
        bmap[x]='o';
    }
    else if(p==15)
    {
        long long int x=68719476735;
        mainb=bitset<45>(x);
        bmap[x]='p';
    }
    else if(p==16)
    {
        long long int x=35115652612096;
        mainb=bitset<45>(x);
        bmap[x]='q';
    }
    else if(p==17)
    {
        long long int x=35115652612607;
        mainb=bitset<45>(x);
        bmap[x]='r';
    }
    else if(p==18)
    {
        long long int x=35115652873728;
        mainb=bitset<45>(x);
        bmap[x]='s';
    }
    else if(p==19)
    {
        long long int x=35115652874239;
        mainb=bitset<45>(x);
        bmap[x]='t';
    }
    else if(p==20)
    {
        long long int x=35115786567680;
        mainb=bitset<45>(x);
        bmap[x]='u';
    }
    else if(p==21)
    {
        long long int x=35115786568191;
        mainb=bitset<45>(x);
        bmap[x]='v';
    }
    else if(p==22)
    {
        long long int x=35115786829312;
        mainb=bitset<45>(x);
        bmap[x]='w';
    }
    else if(p==23)
    {
        long long int x=35115786829823;
        mainb=bitset<45>(x);
        bmap[x]='x';
    }
    else if(p==24)
    {
        long long int x=35184237871104;
        mainb=bitset<45>(x);
        bmap[x]='y';
    }
    else if(p==25)
    {
        long long int x=35184237871615;
        mainb=bitset<45>(x);
        bmap[x]='c';
    }
    for(int i=0;i<45;i++)
    {
        bitset<45> temp = mainb;
        temp.flip(i);
        bmap[temp]=a[p];
        for(int j=i+1;j<45;j++)
        {
            temp.flip(j);
            bmap[temp]=a[p];
            for(int k=j+1;k<45;k++)
            {
                temp.flip(k);
                bmap[temp]=a[p];
                for(int l=k+1;l<45;l++)
                {
                    temp.flip(l);
                    bmap[temp]=a[p];
                    temp.flip(l);
                }
                temp.flip(k);
            }
            temp.flip(j);
        }
        temp.flip(i);
    }
}
int n;
long long int num;
//cin<<n;
/*for(int as=0;as<n;as++)
{
     cin<<num;
    unordered_map<bitset<45>,char>::const_iterator got=bmap.find(bitset(num));
    if(got==bmap.end())
    {
        cout<<"?";
    }
    else
    {
        cout<<bmap->second;
    }

}*/
cin>>n;
for(int x=0;x<n;x++)
{
cin>>num;
char d;
bitset<45>abd = bitset<45>(num);
if(bmap.count(abd)>0)
{
    //d=bmap[abd]+97;
    cout<<bmap[abd];
}
else
{
    cout<<"?";
}

}

}
