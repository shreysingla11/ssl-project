#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int i,j,k,check=0;
    if(s.size()>460)
    {
        cout<<0<<' '<<0;
        return 0;
    }
    for(i=2; i<s.size()+1; i=i+2)
    {
        for(j=0; (j<s.size())&&(j+i<=s.size()); j++)
        {
            int r=0;
            for(k=j; k<(j+(i/2)); k++)
            {
                if(s[k]==s[k+i/2])
                {
                    r++;
                }
            }
            if(r==i/2)
            {
                check=1;
                break;
            }
        }
        if(check==1)
        {
            break;
        }
    }
    if(check==1)
    {
        cout<<i/2<<' '<<j;
    }
    if(check==0)
    {
        cout<<0<<' '<<0;
    }
    return 0;
}
