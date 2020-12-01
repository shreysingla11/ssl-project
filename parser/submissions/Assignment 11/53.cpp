#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <bitset>
#include <unordered_map>
using namespace std;
long long int strtoint(string s)
{
    long long int i=0;
    for(int j=0;j<45;j++)
    {
         i = 2*i + (s[j]-'0');
    }
    return i;
}
typedef unordered_map<long long int,char> bitmap;

int main ()
{
    bitmap mymap;
    //bitmap::hasher fn = mymap.hash_function();
    char c = 'a';
    for(int i=0; i<26; i++)
    {
        std::bitset<5> bit (i);
        string s = bit.to_string();
        string actual = "";
        for(int x=0; x<5; x++)
        {
            for(int k=0; k<9; k++)
            {
                actual = actual + s[x];
            }
        }
        long long int newans= strtoint(actual);
        newans = strtoint(actual);
        mymap[newans] = c;
        //unsigned long long int ans = strtoull(actual,NULL,2);
        //cout<<actual<<endl;
        for(int x=0; x<45; x++)
        {
                for(int y=x+1; y<45; y++)
            {
                for(int z=y+1; z<45; z++)
                {
                    for(int w=z+1; w<45; w++)
                    {
                        string temp = actual;
                        long long int myans;
                        if(actual[w]=='0')
                        {
                            temp[w]='1';
                        }
                        else
                        {
                            temp[w]='0';
                        }
                        //cout<<temp<<endl;
                        //myans = strtoint(temp);
                        //mymap[myans] = c;
                        //mymap.insert (make_pair<long long int,string>(myans,c)); // move insertion
                        if(actual[z]=='0')
                        {
                            temp[z]='1';
                        }
                        else
                        {
                            temp[z]='0';
                        }
                        //myans = strtoint(temp);
                        //mymap[myans] = c;
                        //cout<<temp<<endl;
                        if(actual[y]=='0')
                        {
                            temp[y]='1';
                        }
                        else
                        {
                            temp[y]='0';
                        }
                        //myans = strtoint(temp);
                        //mymap[myans] = c;
                        //cout<<temp<<endl;
                        if(actual[x]=='0')
                        {
                            temp[x]='1';
                        }
                        else
                        {
                            temp[x]='0';
                        }
                        myans = strtoint(temp);
                        mymap[myans] = c;
                        //cout<<temp<<endl;
                    }
                }
            }
        }
        for(int x=0; x<45; x++)
        {
                for(int y=x+1; y<45; y++)
            {
                for(int z=y+1; z<45; z++)
                {
                        string temp = actual;
                        long long int myans;
                        if(actual[z]=='0')
                        {
                            temp[z]='1';
                        }
                        else
                        {
                            temp[z]='0';
                        }
                        //myans = strtoint(temp);
                        //mymap[myans] = c;
                        //cout<<temp<<endl;
                        if(actual[y]=='0')
                        {
                            temp[y]='1';
                        }
                        else
                        {
                            temp[y]='0';
                        }
                        //myans = strtoint(temp);
                        //mymap[myans] = c;
                        //cout<<temp<<endl;
                        if(actual[x]=='0')
                        {
                            temp[x]='1';
                        }
                        else
                        {
                            temp[x]='0';
                        }
                        myans = strtoint(temp);
                        mymap[myans] = c;
                        //cout<<temp<<endl;
                }
            }
        }
        for(int x=0; x<45; x++)
        {
                for(int y=x+1; y<45; y++)
            {
                        string temp = actual;
                        long long int myans;
                        if(actual[y]=='0')
                        {
                            temp[y]='1';
                        }
                        else
                        {
                            temp[y]='0';
                        }
                        //myans = strtoint(temp);
                        //mymap[myans] = c;
                        //cout<<temp<<endl;
                        if(actual[x]=='0')
                        {
                            temp[x]='1';
                        }
                        else
                        {
                            temp[x]='0';
                        }
                        myans = strtoint(temp);
                        mymap[myans] = c;
                        //cout<<temp<<endl;
            }
        }
        for(int x=0; x<45; x++)
        {
                        string temp = actual;
                        long long int myans;
                        //cout<<temp<<endl;
                        if(actual[x]=='0')
                        {
                            temp[x]='1';
                        }
                        else
                        {
                            temp[x]='0';
                        }
                        myans = strtoint(temp);
                        mymap[myans] = c;
                        //cout<<temp<<endl;
        }
        c++;
    }
    int n;
    cin>>n;
    for(int p=0;p<n;p++)
    {
    long long int input;
    cin>>input;
 unordered_map<long long int,char>::iterator got = mymap.find(input);

  if ( got == mymap.end() )
    printf("?");
  else
    printf("%c",got->second);
    }
    /*for (auto& b: mymap)
    std::cout << b.first << ": " << b.second << std::endl;*/
}
