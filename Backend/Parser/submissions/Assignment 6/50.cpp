#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int l,i,j,k,index,p,q;
    int n=s.size();
    int a,b;
    for(l=1; l<n; l=l*2)
    {
        for(index=0;index<n;index+=l)
        {
            for(i=index,j=index+2*l-1; (i<l+index)&&(j<index+5*l-2)&&(j<n);j++)
            {
                if(s[i]==s[j])
                {
                    i=i+1;
                }
                else
                {
                    i=index;
                }
            }

            if(i==l+index)
            {

               for(p=index-1,q=j-l-1;(p>0)&&(q>=i);)
               {
                    if(s[p]==s[q])
                    {
                        p--;
                        q--;
                    }
                    else
                    {

                        break;
                    }
               }
               if(q!=i)
               {
                    for(a=i,b=j;a<=q&&b<n;a++,b++)
                    {
                        if(s[a]==s[b]){}
                        else{break;}
                    }
               }
               if(a==j-l)
               {
                cout<<j-i<<" "<<index;
                return 0;
               }

            }
            else
            {
                //Nothing to be done
            }
        }
    }
    cout<<0<<" "<<0;
    return 0;
}

