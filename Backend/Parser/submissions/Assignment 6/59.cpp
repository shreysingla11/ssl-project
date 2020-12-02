#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int length=10;
    int n= s.length();
    int startindex = 0;
    int l=1;

        for(int j=2; j<3; j=j+l)
        {
            startindex = 0;
            int p=l;
            int x=j+l;
            for(int k=j; x<=j+(4*l)-1 && x<n;)
            {
                int i=0;
                if(k<x)
                {
                    if(s[k]==s[p+k])
                    {
                        cout<<"asdfgh"<<endl;
                        k++;
                    }
                    else if(s[j]==s[p+k])
                    {
                        cout<<"sdfghj"<<endl;
                        p=p+k;
                        x=p;
                        k=j;
                    }
                    else
                    {
                        cout<<"sdgjhjk"<<endl;
                        p=p+k;
                        x=p+1;
                        k=j;
                    }
                }
                cout<<k<<endl;
                cout<<p<<endl;
                if(k==x)
                {
                    if(x-j<=length)
                    {
                        startindex = j;
                        length=x-j;
                        i=-1;
                    }
                }
                if(i==-1)
                {
                    break;
                }
            }

        }
    cout<<startindex<<endl;
    cout<<length<<endl;
}
