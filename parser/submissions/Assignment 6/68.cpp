#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
using namespace std ;
string in;
int acstart1,acstart2;
int start1,start2;
bool flagi=0;
int mini=INT_MAX;
void square_match(int beg,int l)
{   int count=0;int j,i;//mini=INT_MAX;
    for(j=beg;j<(beg+2*l-1) && j<in.length();)
    {
     for(i=beg+2*l-1;i<=(beg+3*l-1)&&i<in.length();i++)
    {

        if(in[j]==in[i])
        {   count=0;
            start1=j;
            start2=i;
            //cout<<"sdfgv"<<endl;
            while(j<in.length()&&i<in.length()&&in[j]==in[i])
            {

                i++;j++;
                count++;
                //cout<<"sdfgv"<<endl;
                if(count==l)
                {////////
                    int len=2*l-1;
            if(start2==start1+2*l-1)
            {   mini=len;
                acstart1=start1;
                acstart2=start2;
                flagi=1;
                //cout<<start1<<" "<<start2<<endl;
                return;
            }
            else
            {   int ini1=start1,ini2=start2;int flag2=0;
                for(int i=2*l-1;i<=4*l-2;i++)
                {
                    while(ini1>0&&ini2>0)
                    {
                        if(in[--ini1]==in[--ini2])
                        {   len++;
                            if(ini2==start1+l)
                            {
                                flag2=1;
                                break;
                            }
                        }
                        else
                            break;

                    }
                    if(flag2==1)
                    {   if(mini>len)
                        {
                        mini=len;
                        acstart1=ini1;
                        acstart2=ini2;
                        flagi=1;
                        }
                        beg=beg+2*l-1;
                        j=beg;
                        break;
                       // cout<<ini1<<" "<<ini2<<endl;
                       // exit(0);
                    }
                    start1+=l;
                    start2+=l;
                    //cout<<start1<<start2<<endl;
                    while(start2<=in.length()-1&&start1<=in.length()-1)
                    {
                        if(in[start1++]==in[start2++])
                        {   len++;
                            if(start1==ini2)
                            {
                                flag2=1;
                                break;
                            }
                        }
                        else
                            break;
                    }
                     if(flag2==1)
                    {
                    if(mini>len)
                        {
                        mini=len;
                        acstart1=ini1;
                        acstart2=ini2;
                        flagi=1;
                        }
                          beg=beg+2*l-1;
                        j=beg;
                        break;
                       // cout<<ini1<<" "<<ini2<<endl;
                       // exit(0);
                    }
                }
            }
                }
            }
            j=start1;
        }
    }
    beg=beg+l;
    j=beg;
    i=beg+2*l-1;
    }
}
int main()
{
    cin>>in;
   // cout<<in.length()<<endl;
    bool flag=0;
    for(int l=1;l<in.length();l*=2)
    {
        square_match(0,l);
        //cout<<"sdg"<<endl;
        if(flagi=1)
        {   //cout<<"sdgf"<<endl;
            if(mini==INT_MAX)
            {
            mini=0;
            acstart1=0;
            }
            if(mini!=0)
            {
            cout<<mini<<" "<<acstart1;
            break;
            }
        }

    }
    if(mini==INT_MAX)
    {
    cout<<mini<<" "<<acstart1;
    }


}

