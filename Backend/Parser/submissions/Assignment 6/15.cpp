#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
    int l=0,i=0,j=0,index=0,tempIndex1=0,tempIndex2=0,length=0,reqIndex=0;
    bool flag1=false,flag2=false,flag3=false;
    string a;
    cin>>a;
    for(l=1; l<=((a.length()+2)/4); l=l*2)
    {
        for(i=0; i<(((a.length()/l)-2)*l); i=i+l)
        {
            index = i;
            for(j=i+l; j<=i+(4*l)-2;)
            {
                flag1=false;
                if(a[index]==a[j])
                {
                    //check
                    flag1=false;
                    for(tempIndex1=i,tempIndex2=j;tempIndex1-i<l; tempIndex1++,tempIndex2++)
                    {
                        if((a[tempIndex1+1]!=a[tempIndex2+1])||(tempIndex2+1==a.length()))
                        {
                            if(tempIndex1==i+l-1)
                            {
                                flag1=true;
                                break;
                            }
                            else
                            {
                                break;
                            }
                        }

                    }
                    if(flag1==true)
                    {
                        break;
                    }
                    j=tempIndex2+1;
                }
                else
                {
                    j++;

                }
            }
            if(flag1==true)
            {
                flag2 = true;
                for(int k=1; k<=(j-tempIndex1)/2.; k++)
                {
                    if ((a[tempIndex2+k]!= a[tempIndex1+k])&&(a[j-k]!=a[i-k]))
                    {
                        flag2 = false;
                    }

                }
            }
            if(flag2==true)
            {
                break;
            }
        }
        if(flag2==true)
        {
            length = j-i;
            if(a[tempIndex1+1]==a[i+1-j+tempIndex1])
            {
                reqIndex = i+1-j+tempIndex1;
            }
            else
            {
                reqIndex = i;
            }
            break;
        }
        else
        {
            length = 0;
            reqIndex = 0;
        }
    }
    printf("%d %d",length,reqIndex);
    cout<<endl;
    return 0;
}
