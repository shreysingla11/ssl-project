#include <iostream>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int count=0;
    int count2=0;
    int l=1;
    for(int i=0; i<s.size(); i++)
    {
        l=1;count=0;
        for(int j=0; j<l+1&&2*l-1<s.size()&&(i+j+l)<s.size(); j++)
            {

            if(s[i+j]==s[i+l+j])
            {
                count++;
            }
            if(s[i+j]!=s[i+l+j])
            {
                l=l*2;
                j=-1;
                count=0;
            }
            if(count==l){cout<<l<<" "<<i<<endl;count=0;count2=1;}
            }
    }
    if(count2==1){cout<<"0 0";}
}

