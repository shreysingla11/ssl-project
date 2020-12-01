#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int n;
    n=s.size();
    int l=1;
    while(n>2*l-1)
   {
        int k=0;
        while(k+2*l<=n)
        {
            int i=k,j=k+l;
            bool possible=false;
            while((j-i<=4*l-2)&&(i<k+l)&&(j<n))
            {
                if(s[i]==s[j])
                {
                    i++;
                    j++;
                }
                else
                {
                    if(i!=k)
                    {
                        i=k;
                    }
                    else
                    {
                        j++;
                    }
                }
            }

            if (i==k+l)
            {   //cout<<"going"<<i<<k<<j<<endl;
                int a=1,b=0;
                int m=j-l;
                if(m==i)
                {
                cout<<l<<" "<<k;
                return 2;
                }
                while(a+b+l<=4*l-1)
                {   if((k-a>=0)&&(j+b<n))
                    {
                    if((s[k-a]==s[m-a])&&(s[i+b]==s[j+b]))
                    {
                         a++;b++;
                    }
                    else if(s[i+b]==s[j+b])
                    {
                        b++;
                    }
                    else if(s[k-a]==s[m-a])
                    {
                        a++;
                    }
                    else break;
                   }
                   else if(k<a)
                   {
                   if(s[i+b]==s[j+b])
                    {
                        b++;
                    }
                    else break;

                   }
                   else if(j+b>=n)
                   {

                   if(s[k-a]==s[m-a])

                    {
                        a++;
                    }

                    else break;

                   }

                   else break;

                }
                if(i+b==m-a+1)
                {
                    cout<<l+a+b-1<<" "<<k-a+1<<endl;
                    return 1;
                }

            }
            k+=l;
        }
       l*=2;
    }

    cout<<0<<" "<<0<<endl;
    return 0;
}
