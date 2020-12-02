#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int n;
    int stop=0;
    n=s.size();
//4l-2
    for(int l=1; 4*l-2<=n; l*=2)
    {
        if(stop==1){break;}
        int p=n/l;
        //this loop gaurd is right.but changing it
        for(int k=0; k<p; k++)
        {
        if(stop==1){break;}
            int i=l*k;
            int count=0;
            int j=2*l-1+i;
//i less than k*l+l
            while((j-i<=4*l-2)&&(i<k*l+l))

            {

//if(i==l*k+1){break;}

                if(s[i]==s[j])
                {
                    i++;
                    j++;
                    count++;
                }

                else
                {
                    if(i!=l*k)
                    {
                        i=l*k;
                    }
                    else
                    {
                        j++;
                    }
                    count=0;
                }


            }
//i--;j--;
//length of loop is j-i if exists.
//remaining length j-i-l;
            int len=j-i,bc=0,fc=0;
//used i again
            if(count==l)
            {
                if(k>0)
                {
                    for(int a=k*l-1; a>k*l-l; a--)
                    {
                        if(s[a]==s[len+a])
                        {
                            bc++;
                        }
                        else
                        {
                            break;
                        }
                    }
                }

                for(int a=k*l+l; a<k*l+l+len-l; a++)
                {
                if(len+a<n){
                    if(s[a]==s[len+a])
                    {
                        fc++;
                    }
                    else
                    {
                        break;
                    }
                    }
                }

                if(bc+fc+l==len)
                {
                    cout<<len<<" "<<k*l-bc;stop=1;
                }

            }


        }
//big loop
    }

if(stop==0){cout<<0<<" "<<0;}
    return 0;
}
