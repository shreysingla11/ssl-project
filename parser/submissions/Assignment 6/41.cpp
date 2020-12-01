#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int n=s.length();
    for(int l = 1; l<=(n+2)/4; l*=2) //check for l equality cindn
    {
        //cout<<"1"<<endl;
        for(int i=0; i<n; i+=l)//look limit of i
        {
            //cout<<"2"<<endl;
            int j = i+2*l-1;
            for(; j<=i+4*l-2&&j+l-1<n;)
            {
                //cout<<"3"<<endl;
                int k = 0;
                for(; k<l&&j+k<n; k++)
                {
                    //cout<<"4"<<endl;
                    if(s[i+k]!=s[j+k])
                    {
                        if(k==0)
                        {
                            j=j+1;
                            break;
                        }
                        j=j+k;
                        break;
                    }
                    else
                    {
                        //skip
                    }
                }
                if(k==l)
                {
                    //cout<<"pooka"<<i<<j<<k<<l<<endl;
                    int right=-1;
                    for(;; right++)
                    {
                        if(right==j-i-l)
                        {
                            //cout<<"pokakush"<<endl;
                            cout<<j-i<<" "<<i<<endl;
                            return 0;
                        }
                        //cout<<"pokkaaa"<<endl;
                        if(s[i+l+right]!=s[j+l+right])
                        {
                            right--;
                            break;
                        }
                    }
                    int left=1;
                    //cout<<"dcfbdhfef"<<endl;
                    for(; left<=j-i-l&&(i-left)>=0; left++)
                    {
                        if(i+l+right==j-left)
                        {
                            //cout<<"lanjamunda2"<<endl;
                            cout<<j-i<<" "<<i-left;
                            return 0;
                        }
                        //cout<<"pokkaaaggg"<<endl;
                        if(s[i-left]!=s[j-left])
                        {
                            left--;
                            break;
                        }
                    }
                    j=j+k;
                }//increment j

            }
        }
    }
    cout<<0<<" "<<0<<endl;
    return 0;
}
