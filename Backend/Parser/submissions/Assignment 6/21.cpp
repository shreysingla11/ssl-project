#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin>>s;
    bool flag5=0;
    for (int l = 1; l < s.length(); l*=2)
    {
        int i=0;
        int j=l+i;
        bool flag =0;
        bool flag2 =0;
        bool flag3=0;
        bool flag4=0;
        for(int k =0; k<s.length()/l; k++)
        {i=k*l;
         j=(k+1)*l;

            while(j-i<=(3*l-1)&&j<s.length())
            {
                if(s[i]==s[j])
                {
                    i++;


                    j++;
                    if(i%l==0||l==1)
                    {
                        flag=1;
                        break;
                    }
                }
                else
                {
                    i=k*l;
                    if(s[i]==s[j])
                    {
                        i++;
                        j++;

                        if(i%l==0||l==1)
                    {
                        flag=1;

                        break;
                    }

                    }
                    else
                    {
                        j++;
                    }
                }
            }

            if(flag==1)
            {i=k*l;
             j-=l;
             int temp=j;
                while(j-1>=(k+1)*l&&i>=0)
                {
                    i--;
                    j--;
                    if(s[i]==s[j])
                    {
                        continue;
                    }
                    else
                    {
                        flag2=1;
                        break;
                    }
                }
                if(flag2==1)
                {
                    i=k*l+1;
                    j=temp+1;
                    while(i<temp&&j<s.length())
                    {
                        if(s[i]==s[j])
                        {
                            i++;
                            j++;

                        }
                        else
                        {
                            flag3=1;
                            break;
                        }
                    }
                }
                if(flag2==0)
                {
                    cout<<j-i<<" "<<i;
                    flag4=1;
                    break;
                }
                if(flag3==0)
                {
                    cout<<j-i<<" "<<k*l;
                    flag4=1;
                    break;
                }

            }


        }
    if(flag4==1)
    {flag5=1;break;}
    }
    if(flag5==0)
    cout<<"0 0";
}
