#include<iostream>
#include<string>
#include<cstdio>

using namespace std;

int main()
{
    string s;
    int i=0;
    cin>>s;
    int j=s.length();
    int x=0,y=0,z=0,l=1,temp=j,temp2=0,c=0,p=0,m=0,d=0;
    if(j<100000)
    {   x=1;z=0;
            while(x<j)
    {
        y=0;
        while(y<j-x)
        {
            z=y;

            while(z<y+x&&z+x<j)
            {
                if(s[z]==s[z+x])
                {
                    z++;
                    if(z==y+x)
                    {
                        cout<<x<<" "<<y<<endl;
                        return 0;
                    }
                }
                else
                {
                    break;
                }
            }
            y++;

        }
        x++;


    }

    cout<<0<<" "<<0<<endl;
    }
    else{
    while(l<j)
    {

        z=l;
        y=0;
        x=0,p=j,c=0,d=0;
        m=0;
        while(y<z&&y+z<j)
        {
            if(s[y]==s[y+z])
            {
                 y++;
                  if(y==z)
                {

                    if(temp>z)
                    {
                        temp=z;
                        temp2=c;
                    }
                    c=0;
                    x++;
                    y=l*x;
                    z=l;
                    m=2;
                    continue;

                }
                if(p==y)
                {
                    p=0;
                    if(temp>z)
                    {
                        temp=z;
                        temp2=c;
                    }
                    c=0;
                    x++;
                    y=l*x;
                    z=l;
                    m=2;
                    continue;
                }


            }
            else
            {

                if(y==l*x)
                {
                    if(z>=4*l-2+l*x)
                    {
                        x++;
                        y=l*x;
                        z=l;
                        c=y;
                    }
                    else
                    {
                        z++;
                    }
                }
                else
                    {
                    if(y==l*x+l&&z==y+1)
                    {
                        x++;
                        y=l*x;
                        z=l;
                    }
                    if(y>l*x+l)
                    {
                          y=y+l*x+1-z;
                          c=y;
                          p=l*x;
                    }
                    else
                    {
                        if(y<=l*x+l&&y>l*x)
                        {
                            z=y+z;
                            y=l*x;
                        }
                        else
                        {
                            x++;
                            y=l*x;
                            z=l;
                        }
                    }

                }

            }
        }
        l*=2;
        if(m==2)
        {
            break;
        }
    }

    cout<<temp<<" "<<temp2;}

    return 0;
}
