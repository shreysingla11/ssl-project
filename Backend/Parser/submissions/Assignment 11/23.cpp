#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long long int num;
    int rem,count1=0,count0=0,errors=0,dec=0,i,j,p,q,pow[5]= {1,2,4,8,16};
    char a[45];
    string result="";
    for(i=0; i<n; i++)
    {
        cin>>num;
        for(j=0; j<45; j++)
        {
            rem=num%2;
            num/=2;
            if(rem==0)
            {
                a[j]='0';
            }
            else
            {
                a[j]='1';
            }
        }
        for(p=0; p<5; p++)
        {
            for(q=0; q<9; q++)
            {
                if(a[9*p+q]=='0')
                {
                    count0++;
                }
                else
                {
                    count1++;
                }
            }
            if(count1>count0)
            {
                dec+=pow[p];
                errors+=(9-count1);
            }
            else
            {
                errors+=(9-count0);
            }
            count1=0;
            count0=0;
        }
        if(errors>4 ||dec>25)
        {
            result+='?';
        }
        else
        {
            char p;
            p='a'+dec;
            result+=p;
        }
        errors=0;
        dec=0;
    }
    cout<<result;
    return 0;
}
