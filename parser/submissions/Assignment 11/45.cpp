#include <iostream>
#include<string>
#include<bitset>
#include<cstdio>
#include<cstdlib>
#include <unordered_map>

using namespace std;
typedef unordered_map<long long int,char> bitmap;

long long int finalAnswer(string s)
{
    long long int i=0;
    for(int j=0;j<45;j++)
    {
        i=i*2 + (s[j]-'0');
    }
};
int main ()
{
    bitmap mymap;
    string temp;
    char letter;
    letter = 'a';
    long long int answer;
    for(int i=0;i<26;i++)
    {
        string required = "";
        bitset<5> a(i);
        string s =a.to_string();
        for(int j=0;j<5;j++)
        {
            for(int k=0;k<9;k++)
            {
                required+=s[j];

            }
        }
        answer=finalAnswer(required);
        mymap[answer]=letter;
        for(int l=0;l<45;l++)
        {
            for(int m=l+1;m<45;m++)
            {
                for(int n=m+1;n<45;n++)
                {
                    for(int p=n+1;p<45;p++)
                    {
                        temp = required;

                        if(temp[p]=='0')
                        {
                            temp[p]='1';
                        }
                        else
                        {
                            temp[p]='0';
                        }
                        if(temp[n]=='0')
                        {
                            temp[n]='1';
                        }
                        else
                        {
                            temp[n]='0';
                        }
                        if(temp[m]=='0')
                        {
                            temp[m]='1';
                        }
                        else
                        {
                            temp[m]='0';
                        }
                        if(temp[l]=='0')
                        {
                            temp[l]='1';
                        }
                        else
                        {
                            temp[l]='0';
                        }
                        answer=finalAnswer(temp);
                        mymap[answer]=letter;
                    }
                }
            }
        }
        for(int l=0;l<45;l++)
        {
            for(int m=l+1;m<45;m++)
            {
                for(int n=m+1;n<45;n++)
                {

                        temp = required;
                        if(temp[n]=='0')
                        {
                            temp[n]='1';
                        }
                        else
                        {
                            temp[n]='0';
                        }
                        if(temp[m]=='0')
                        {
                            temp[m]='1';
                        }
                        else
                        {
                            temp[m]='0';
                        }
                        if(temp[l]=='0')
                        {
                            temp[l]='1';
                        }
                        else
                        {
                            temp[l]='0';
                        }
                        answer=finalAnswer(temp);
                        mymap[answer]=letter;

                }
            }
        }
        for(int l=0;l<45;l++)
        {
            for(int m=l+1;m<45;m++)
            {
                        temp = required;
                        if(temp[m]=='0')
                        {
                            temp[m]='1';
                        }
                        else
                        {
                            temp[m]='0';
                        }
                        if(temp[l]=='0')
                        {
                            temp[l]='1';
                        }
                        else
                        {
                            temp[l]='0';
                        }
                        answer=finalAnswer(temp);
                        mymap[answer]=letter;


            }
        }
        for(int l=0;l<45;l++)
        {
            temp = required;

            if(temp[l]=='0')
            {
                temp[l]='1';
            }
            else
            {
                temp[l]='0';
            }
            answer=finalAnswer(temp);
            mymap[answer]=letter;
        }
        letter++;
    }


    int n;
    cin>>n;
    for(int p=0;p<n;p++)
    {
        long long int input;
        cin>>input;
        unordered_map<long long int,char>::iterator got = mymap.find(input);
        if(got==mymap.end())
        {
            printf("?");
            //cout<<"?"<<endl;
        }
        else
        {
        printf("%c",got->second);
            //cout<<got->second<<endl;
        }
    }
    return 0;
}
