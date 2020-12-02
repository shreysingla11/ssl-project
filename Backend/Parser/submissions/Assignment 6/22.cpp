#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    string s;
    getline(cin,s);
    int l=1;
    int length = 0;
    int first = 0;
    while(s.size()>2*l-1)
    {
        length = 0;
        first = 0;
        int n=0;
        int x=0;
        int y=0;
        int z=0;
        int start=0;
        int a;
        int b;
        int k=0;
        int size=s.size();
        while(n!=size/l -2)
        {
            y = n*l-1;
            first = n*l;
            length = l;
            x = n*l+2*l-1;
            b = n*l+2*l-1;
            a=n*l;
            start=0;
            while(b<=(n*l+4*l-2) && (a!=n*l+l))
            {
                while((a-n*l)<l && s[a]==s[x])
                {
                    if(a==n*l)
                    {
                        b=x;
                    }
                    a++;
                    x++;
                }
                if(a==n*l)
                {
                    x++;
                    b=x;
                    continue;
                }
                if(a-n*l==l)
                {
                    x--;
                    break;
                }
                else
                {
                    a=n*l;
                    b=x;
                }
            }

            if(b==(n*l+4*l-2)+1)
            {
                n++;
                continue;
            }
            z = x-l;

            while(length<=4*l-2)
            {
                if(start==0 && z!=n*l+l-1)
                {
                    if(y!=-1)
                    {
                        if(s[y]==s[z])
                        {
                            length++;
                            first--;
                            y--;
                            z--;
                        }
                        else
                        {
                            y=n*l+l;
                            z=x+1;
                            start=1;
                        }
                    }
                    else
                    {
                        y=n*l+l;
                        z=x+1;
                        start=1;
                    }
                }

                else if(start==0)
                {
                    break;
                }

                else if(start==1 && z!=size)
                {
                    if(y==x-l+1)
                    {
                        break;
                    }
                    else
                    {
                        if(s[y]==s[z])
                        {
                            length++;
                            y++;
                            z++;
                        }
                        else
                        {
                            length=0;
                            first=0;
                            break;
                        }
                    }
                }
            }
            if(length!=0)
            {
                break;
            }
            n++;
        }
        if(length!=0)
        {
            break;
        }
        l=l*2;
    }
    cout<<length<<" "<<first;
}
