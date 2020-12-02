#include<iostream>
using namespace std;
int main()
{

    string s;
    int n,l,p,q,i,l1,r1,l2,r2,y,c=0,cnt=0;
    cin>>s;
    n=s.length();
    for(l=1; l<n; l*=2)
    {
        p=2*l-1;
        q=2*p;


        for(int x=0; (x+1)*l<n; x++)
        {
            i=x*l;


                for(int j=0,y=l+j; (j<q)&&(y<=j+ 3*l-2)&&(y<n); j++,y++)
                {
                    if(s[i+j]==s[i+y])
                    {
                        c++;
                        cnt=c;
                        l1=i;
                        r1=i+j;
                        r2=i+y;
                        l2=r2-r1+l1;
                        if(l2==r1+1)
                        {
                            cout<<r1-l1+1<<" "<<l1;return 1;
                        }
                    }
                    else
                    {
                        j=-1;
                        c=0;
                    }
                }


                    for(; (l2>r1)&&(l1>0);)
                    {
                        if(s[l1-1]==s[l2-1])
                        {
                            l1--;
                            l2--;
                        }
                        else
                        {
                            break;
                        }
                        if(l2==r1+1)
                        {
                            cout<<r1-l1+1<<" "<<l1;return 1;
                        }
                    }
                     if(l2==r1+1)
                        {
                            cout<<r1-l1+1<<" "<<l1;return 1;
                        }






        }

    }
    cout<<"0 0";

    return 1;
}
