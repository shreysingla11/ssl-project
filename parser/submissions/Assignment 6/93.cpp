#include<iostream>
using namespace std;
bool lsquare(string s,int l,int n,int start);
bool square(string s,int l,int n);
int main()
{
    string s;
    int n,l;
    cin>>s;
    n=s.size();
    for(l=1; l<n; l=l*2)
    {
        if(square(s,l,n-1)==true)
        {
            break;
        }
    }
    if(l>=n)
    {
    cout<<"0"<<" "<<"0"<<endl;
    }
//cout<<minLen<<" "<<minPos<<endl;
    return 0;
}
bool lsquare(string s,int l,int n,int start)
{
    int start1=start,start2=start+l,i;
    bool b=false;
    while((start2<=(4*l-2+start1))&&(start2<=(n-l+1)))
    {
        cout<<"HI "<<l<<endl;
        for(i=0; i<l; i++)
        {
            if(s[start1+i]==s[start2+i])
            {
                continue;
            }
            else
            {
                start2=start2+i+1;  //
                break;
            }
        }
        if(i==l)
        {
            //cout<<"HI "<<l<<endl;
            int j,k;
            for(j=l; j<start2-start1; j++)
            {
                if(start2+j>n)
                {
                b=true;
                //start2=n+3;
                //cout<<"HI "<<l<<endl;
                break;
                }
                if(s[start1+j]==s[start2+j])
                {
                    continue;
                }
                else
                {
                    start2=start2+j;
                    break;
                }
            }
            if(j==start2-start1)
            {
                cout<<j<<" "<<start1<<endl;
                return true;
            }
            for(k=1; k<=start2-start1-l; k++)
            {
                //cout<<"HI "<<l<<endl;
                if(start1-k<0)
                {
                //cout<<"HI "<<l<<endl;
                start2=start2+l;
                break;
                }
                //cout<<s[start1-k]<<s[start2-k]<<endl;
                if(s[start1-k]==s[start2-k])
                {
                    //cout<<"HI "<<l<<endl;
                    continue;
                }
                else
                {
                    break;
                }
            }
            if(k==start2-start1-l+1)
            {
                cout<<(start2-start1)<<" "<<(start1-k+1)<<endl;
                return true;
            }
            if(b==true)
            {
            return false;
            }
        }
    }
    if((start2>(4*l-2+start1))||(start2>(n+3-4*l)))
    {
    return false;
    }
}
bool square(string s,int l,int n)
{
    for(int start=0; start<=n-2*l+1; start=start+l)
    {
        //cout<<"HI"<<endl;
        if(lsquare(s,l,n,start)==true)
        {
            return true;
        }
    }
    //cout<<"HI "<<l<<endl;
    return false;
}
