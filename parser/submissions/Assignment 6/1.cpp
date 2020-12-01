#include<iostream>
#include<string>

using namespace std;

int main()
{
    int n,i,k,l,temp=0,m=1;
    string S;

    cin>> S;
    n=S.length();

    for (l=1; l<=n/2; l++)
    {
        for (i=0; i<=(n-2*l+1); i++)
        {
            for(k=i; k<(i+l); k++)
            {
                if(S[i]==S[i+l])
                { }
                else
                {
                    break;
                }
            }

            if (k==i+l)
            {
                temp=0;
                m=0;
                break;
            }
            else
            {
                temp=1;
            }
        }
        if(m==0)break;
    }

     if(temp==0)
    {
        cout<<l<<" "<<i;
    }
    else
    {
        cout<<"0 0";
    }
    return 0;
}




