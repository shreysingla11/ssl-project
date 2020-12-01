#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    cin>>s;
    //cout<<"1";
    int n=s.length();
    int l1,l2,r1,r2;
    //cout<<n;
    bool flag2=true;
    bool flag3=true;
    for(int l=1; l<n; l*=2)
    {
        //cout<<"1";
        int a=2*l-1,b=2*a;
        bool flag1=true;
        for(int x=0; x<n/l; x++)
        {
            for(int i=x*l; i<(x+1)*l && i<n; i++)
            {
                if(flag1==false)
                {
                    if(s[i]==s[r2+1])
                    {
                        //matched hence check further
                        r2++;
                        r1++;
                    }
                    else
                    {
                        if(r2-l2+1<=b && r2-l2+1>=a)
                        {
                            //cout<<r2-l2<<" "<<l1<<endl;
                            flag2=false;
                            x++;//skip the block
                            flag3=false;
                        }
                    }
                }
                for(int p=l; p<3*l-2 && flag1 && p+i<n; p++)
                {
                    if(s[i]==s[p+i])
                    {
                        flag1=false;
                        l1=i;
                        r1=i;
                        l2=p+i;
                        r2=p+i;
                    }
                }
                if(flag1==true)
                {
                    if(r2-l2+1<=b && r2-l2+1>=a)
                    {
                        //cout<<r2-l2<<" "<<l1<<endl;
                        flag2=false;
                        x++;//skip the block
                        flag3=false;
                    }
                }
            }
        }
    }
    if(flag3==true)
    {
        cout<<"0 0"<<endl;
    }
    else
    {
        cout<<r2-l2+1<<" "<<l1+1<<endl;
    }
    return 0;
}
