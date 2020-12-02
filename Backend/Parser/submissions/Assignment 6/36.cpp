#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int n=s.length();
    for(int l=1; l<=(n+2)/4; l*=2)
    {
        for(int i=0; i<n; i+=l)
        {
            int j=i+2*l-1;
            while(j<=i+4*l-2&&j+l-1<n)
            {
                int k=0;
                for(k=0; j+k<n&&s[i+k]==s[j+k]&&k!=l; k++)
                {

                }
                if(k==l)
                {
                    int right=-1,left=1;
                    for(;; right++)
                    {
                        if(right==j-i-l)
                        {
                            cout<<j-i<<" "<<i;
                            return 1;
                        }
                        if(s[i+l+right]!=s[j+l+right])
                        {
                            right--;
                            break;
                        }
                    }
                    for(; left<=j-i-l&&i-left>=0; left++)
                    {
                        if(j-left==i+l+right)
                        {
                            cout<<j-i<<" "<<i-left;
                            return 1;
                        }
                        if(s[j-left]!=s[i-left])
                        {
                            left--;
                            break;
                        }
                    }
                }
                if(k==0)
                {
                    k++;
                }
                j+=k;
            }
        }
    }
    cout<<0<<" "<<0;
}
