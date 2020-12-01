#include <iostream>
#include <bitset>
#include <cstring>
#include <algorithm>
#include <unordered_map>
using namespace std;
long long int toint(string bitstring, int len)
{
    long long int tempint;
    long long int num=0;
    for(int i=0; i<len; i++)
    {
        tempint=bitstring[i]-'0';
        num |= (1<<(len-1-i))*tempint;
    }
    return num;
}

int main()
{
    unordered_map <string, char> m;
    long long int input;
    char a='a';
//string s;
    for(int i=0; i<26; i++,a=a+1)
    {
    //cout<<"1"<<endl;
        string s;
        string final;
        int k=i;
        for(int j=0; j<5; j++)
        {
            if(k%2)
            {
                s=s+'1';
            }
            else
            {
                s=s+'0';
            }
            k=k/2;
        }
        reverse(s.begin(),s.end());
//cout<<s<<endl;
        for(int i=0; i<5; i++)
        {
            for(int j=0; j<9; j++)
            {
                final=final+s[i];
            }
        }
        //if(i==1){cout<<final<<endl;}
//cout<<toint(final,45)<<endl;
//if(final=="00000000000000000000000000000000000000000111111111"){cout<<"Done"<<endl;}
        //m.insert({final,a});
m[final]=a;
        for(int i=0; i<45; i++)
        {
            if(final[i]=='0')
            {
                final[i]='1';
            }
            else
            {
                final[i]='0';
            }
            m[final]=a;
            for(int j=i+1; j<45; j++)
            {
                if(i!=j)
                {
                    if(final[j]=='0')
                    {
                        final[j]='1';
                    }
                    else
                    {
                        final[j]='0';
                    }
                    m[final]=a;
                    for(int k=j+1; k<45; k++)
                    {
                        if(i!=k&&j!=k)
                        {
                            if(final[k]=='0')
                            {
                                final[k]='1';
                            }
                            else
                            {
                                final[k]='0';
                            }
                            m[final]=a;;

                            for(int l=k+1; l<45; l++)
                            {
                                if(i!=l&&j!=l&&k!=l)
                                {
                                    if(final[l]=='0')
                                    {
                                        final[l]='1';
                                    }
                                    else
                                    {
                                        final[l]='0';
                                    }
                                    m[final]=a;;
                                    if(final[l]=='0')                                    if(final[l]=='0')
                                    {
                                        final[l]='1';
                                    }
                                    else
                                    {
                                        final[l]='0';
                                    }
                                }
                            }
                            if(final[k]=='0')
                            {
                                final[k]='1';
                            }
                            else
                            {
                                final[k]='0';
                            }
                        }

                    }
                    if(final[j]=='0')
                    {
                        final[j]='1';
                    }
                    else
                    {
                        final[j]='0';
                    }
                }

            }
            if(final[i]=='0')
            {
                final[i]='1';
            }
            else
            {
                final[i]='0';
            }


        }


    }
    int n;
cin>>n;
for(int i=0;i<n;i++)
{
cin>>input;
string test;
string test2;
long long int temp =input;
while(temp!=0)
{
if(temp%2){test=test+'1';}
else{test=test+'0';}
temp=temp/2;
}
//cout<<test<<endl;
reverse(test.begin(),test.end());
//cout<<test<<endl;

int a = test.size();
for(int i=0;i<45-a;i++)
{
test2=test2+'0';
}
for(int i=45-a,k=0;i<45;i++,k++)
{
test2=test2+test[k];
}
//bitset bits(input);
//test = bits.to_string();
//cout<<test2;
//cout<<test2.size()<<endl;
//cout<<test2<<endl;
unordered_map<string,char>::iterator g=m.find(test2);
if(g==m.end())
{cout<<"?";}
else{cout<<(g->second);}
}
}
