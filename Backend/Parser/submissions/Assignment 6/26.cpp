#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    string s;
    int len=0,first=0;
    cin>>s;
    if(s.size()>460)
    {
        cout<<"0 0";
        return 0;
    }
    for(int length=1;length<=s.size()/2;length++)
    {
        for(int fchar=0;fchar<s.size()-2*length+1;fchar++)
        {
            for(int pos=fchar;pos<fchar+length;pos++)
            {
                if(s[pos]!=s[pos+length])
                {
                    break;
                }
                else if(pos+1 == fchar+length)
                {
                    len=length;
                    first=fchar;
                    break;
                }
                else
                {
                    continue;
                }
            }
            if(len!=0)
            {
                break;
            }
        }
        if(len!=0)
            {
                break;
            }
    }
    cout<<len<<" "<<first;
    return 0;
}

