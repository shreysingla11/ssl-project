#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
typedef unordered_map<long long,char> MAP;

string toString(long long integer)
{
    string bitstring(45,'0');
    int index=44;
    while(index>=0 && integer>0)
    {
        if(integer%2==0)
            bitstring[index]='0';
        else bitstring[index]='1';
        integer/=2; index--;
    }
    return bitstring;
}

long long toInt(string bitstring)
{
    long long integer=0,power=1;
    for(int i=bitstring.length()-1;i>=0;i--)
    {
        if(bitstring[i]=='1')
            integer+=power;
        power*=2;
    }
    return integer;
}

long long get_codeword(int i)
{
    int t=i;
    long long code=0;
    long long power=1;
    while(t>0)
    {
        if(t%2==1)
            code+=511*power;
        power*=512;
        t=t/2;
    }
    return code;
}

char flip(char bit_val)
{
    if(bit_val=='0') return '1';
    else return '0';
}

MAP mymap;

void set_ints_for_char()
{
    for(int m=0;m<26;m++)
    {
        char c=m+'a';
        long long codeword=get_codeword(m);
        string s=toString(codeword);
        string temp=s;
        ::mymap[codeword]=c;
        int i,j,k,l;
        for(i=0;i<45;i++)
        {
            temp=s;
            flip(temp[i]);
            ::mymap[toInt(temp)]=c;
            for(j=i+1;j<45;j++)
            {
                temp=s;
                flip(temp[i]); flip(temp[j]);
                ::mymap[toInt(temp)]=c;
                for(k=j+1;k<45;k++)
                {
                    temp=s;
                    flip(temp[i]); flip(temp[j]); flip(temp[k]);
                    ::mymap[toInt(temp)]=c;
                    for(l=k+1;l<45;l++)
                    {
                        temp=s;
                        flip(temp[i]); flip(temp[j]);
                        flip(temp[k]); flip(temp[l]);
                        ::mymap[toInt(temp)]=c;
                    }
                }
            }
        }
    }
}

int main()
{
    int n;
    cin>>n;
    set_ints_for_char();

//    for(int i=0;i<26;i++)
//    {
//        char c=i+'a';
//        long long codeword = get_codeword(i);
//        set_ints_for_char(mymap,codeword,c);
//    }

    long long int query;
    for(int i=0;i<n;i++)
    {
        cin>>query;

        if(mymap.count(query)==0)
            cout<<"?";
        else
            cout<<mymap[query];
    }
    return 0;
}
