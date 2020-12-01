#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int n;
    n=s.length();
    int k=0;
    int start1;
    int start2;
    int extendin2;
    int extendin1;
    int extendout1;
    int extendout2;
    for(int l=1; l<=(n+2)/4; l=l*2)
    {
        for(start1=0; start1<=n-(2*l); start1=start1+l)
        {
            start2=start1+2*l-1;

            for(; start2<=start1+4*l-2; start2=start2+k)
            {
                for(k=0; k<l; k++)
                {
                    if(s[start1+k]!=s[start2+k])
                    {
                        break;
                    }
                }

                if(k==l)
                {
                    for((extendin2=start2),(extendout1=start1);(extendin2>=start1+l)&&(extendout1>=0);(extendin2--),(extendout1--))
                    {
                        if(s[extendin2]!=s[extendout1])
                        {

                            extendin2++;
                            extendout1++;
                            break;

                        }
                    }
                    if(extendout1<0)
                    {

                            extendin2++;
                            extendout1++;
                    }
                    for((extendin1=start1+l-1),(extendout2=start2+l-1);(extendin1<extendin2)&&(extendout2<=n-1);(extendin1++),(extendout2++))
                    {

                        if(s[extendin1]!=s[extendout2])
                        {
                            extendin1--;
                            extendout2--;
                            break;
                        }
                    }
                    if(extendout2==n)
                    {

                            extendin1--;
                            extendout2--;
                    }
                    if((extendin1==extendin2)||(start1+l==start2))
                    {
                        cout<<(start2-start1)<<" "<<start1;
                        return 1;
                    }

                }
                else
                {
                    if(k==0)
                    {
                        k++;
                    }
                }
            }

        }
    }
    cout<<"0 0";
    return 0;
}

