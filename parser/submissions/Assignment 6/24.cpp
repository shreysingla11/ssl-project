#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    getline(cin,s);
    int index=0,length=(s.length());
    int l=1;
    for (l=1; l<s.length(); l*=2)
    {
        for(int m=1; m*l-1<s.length(); m++)
        {
            int k = (m-1)*l;
            int index1 = ((m+1)*l)-1;
            if(index1 < s.length())
            {
                for(k=(m-1)*l; ((k<(m*l)&&(index1<s.length()))); k++)
                {
                    if(s[k] == s[index])
                    {
                        index1++;
                        continue;
                    }
                    else
                    {
                        if(index1<(((m+3)*l)-2))
                        {
                            k = (m-1)*l-1;
                            continue;
                        }
                        else
                            break;
                    }
                    if(k==(m*l))
                    {
                        int i=0,j=0,r=0;
                        for( i=index1-l-1; i>((m*l)-1); i--)
                        {
                            if(((m-2)*l+i-index1)>=0)
                            {
                                if(s[i]==s[((m-2)*l+i-index1)])
                                {
                                    continue;
                                }
                                else
                                {
                                    r=((m-2)*l+i-index1);
                                    for( j=(m*l); j<i+1; j++)
                                    {
                                        if((index1+j-(m*l))<s.length())
                                        {
                                            if(s[j]==s[index1+j-(m*l)])
                                            {
                                                continue;
                                            }
                                            else
                                            {
                                                break;
                                            }
                                        }

                                    }
                                    if(j==(i+1))
                                        i=((m*l)-1);

                                }

                            }
                            else
                            {
                                for( j=(m*l); j<i+1; j++)
                                {
                                    if((index1+j-(m*l))<s.length())
                                    {
                                        if(s[j]==s[index1+j-(m*l)])
                                        {
                                            continue;
                                        }
                                        else
                                        {
                                            break;
                                        }
                                    }

                                }

                                if(j==i+1)
                                    i=((m*l)-1);
                            }
                        }
                        if(i==(m*l-1))
                        {
                            if(length>((index1+j-(m*l)-1)-r))
                            {
                                length = (index1+j-(m*l)-1)-r;
                                index=r;
                            }
                        }

                    }






                }









            }









        }





    }
    if(length==s.length())
    { length =0; index=0;}
    cout<<length<<endl;
    cout<<index<<endl;
return 0;
}
