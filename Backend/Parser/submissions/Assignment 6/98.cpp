#include<iostream>
#include<cstring>
using namespace std;

int findblock(string s,int ind,int l){
    int count1=0,temp=ind;
    for (int i=ind + 2*l-1;i<=ind + 4*l-2;i++)
    {
        if (s[ind]==s[i])
        {
            ind++;
            count1++;
        }
        else
        {
            ind=temp;
            count1=0;
        }
        if (count1==l)
        {
            return (i-l+1);
        }
    }
    return -1;
}


int newblock(int l){
    return 2*l;
}

int checksub(string s,int l){
    int checkthis,numst,temp1,temp2,temp3,temp4,newl,min1=100000000,min2=100000000,flag=0;
    for (int i=0;i<s.length();i+=l)
    {
        if (findblock(s,i,l)==-1)
        {
            continue;
        }
        checkthis=findblock(s,i,l);
        temp1=i;
        temp2=checkthis;
        i--;
        checkthis--;
        numst=checkthis-i-1;
        while(i>0&&numst>0)
        {
            if (s[i]==s[checkthis])
            {
                numst--;
                i--;
                checkthis--;
            }
            else
            break;
        }
        temp3=i+1;
        temp4=checkthis+1;
        i=temp1+1;
        checkthis=temp2+1;
        while(checkthis<s.length()&&numst>0)
        {
            if (s[i]==s[checkthis])
            {
                numst--;
                i++;
                checkthis++;
            }
            else
            break;
        }
        if (numst==0)
        {
            if ((temp2-temp1)<min1)
            {
                min1=temp2-temp1;
                if (temp3<temp1)
                min2=temp3;
                else
                min2=temp1;
            }
            else if ((temp2-temp1)==min1&&temp3<min2)
            {
                min2=temp3;
            }
            flag=1;
        }

    }
    if (flag==1)
    {
        cout<<min1<<" "<<min2;
        return 0;
    }
    newl=newblock(l);
    if ((s.length()/newl)<1)
    {
        int a=0,b=0;
        cout<<a<<" "<<b;
        return 0;
    }
    checksub(s,newl);
}


int main(){

string s;
cin>>s;
checksub(s,1);
return 0;
}

