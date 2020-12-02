#include<iostream>
#include<vector>
#include<string>
using namespace std;


int g(int it1,int it2,vector<char> &a,int l)
{
   // cout<<"g called"<<it1<<" "<<it2<<endl;
    int t=-1,ti=-1,tj=-1;
    int n=a.size()-1;
    int i,j;
    i=it1-1;
    j=it2-1;
    for(i=it1-1; (i>0)&&(j>=(it1+l));)
    {
        if(a[i]==a[j])
        {
            i--;
            j--;
        }
        else
        {
            break;
        }
    }

    i++;
    j++;

    //cout<<i<<" "<<j<<endl;

    ti=i;
    tj=j;
    i=it1+l;
    j=it2+l;
    for(; (i<tj)&&(j<=n);)
    {
        if(a[i]==a[j])
        {
            i++;
            j++;
        }
        else
        {
            break;
        }

    }
    //cout<<i<<" "<<j<<endl;
    if(i==tj)
    {
        t=ti;
    }
    return t;

}


bool f(vector<char> &a,int &l,int &m,int &index)
{
    bool flag=false;
    int n=a.size()-1;
    m=n+10;
    index=n+10;
    int i,it1,it2;

    for(i=1; (i+l)<=n; i=i+l)
    {
      //  cout<<" begins "<<i<<endl;
        it1=i;
        it2=i+l;

        for(it2=i+l; (it2<=n)&&(it2<(i+(4*l)-1));)
        {
        //    cout<<a[it1]<<" "<<a[it2]<<" "<<endl;
            if(it1==i)
            {
                if(a[it1]==a[it2])
                {
                    it1++;
                    it2++;
                }
                else
                {
                    it2++;
                }
            }
            else
            {
                if(a[it1]==a[it2])
                {
                    it1++;
                    it2++;
                }
                else
                {
                    it1=i;
                }
            }

            if(it1==(i+l))
            {
                if((it2-it1)<=m)
                {
                    int uv=g(i,it2-l,a,l);
                    if((uv!=(-1)))
                    {
                        flag=true;
                        if((uv<=index)&&((it2-it1)==m))
                        {
                            index=uv;
                        }
                        if((it2-it1)<m)
                        {
                            index=uv;
                            m=(it2-it1);

                        }
                    }
          //          cout<<m<<" check "<<index<<endl;
                    it1=i;
                }
            }
        }


    }

    return flag;

}


int main()
{
    int n;
    string s;
    vector<char> a;
    cin>>s;
    a.resize(s.size()+1);
    int b;
    b=s.size();
    int i;
    for(i=0; i<b; i++)
    {
        a[i+1]=s[i];
    }
    n=a.size()-1;
    int m=n+10,index=n+10,l=3;
    l=1;
    bool temp;
    while(l<=(n/2))
    {
        temp=f(a,l,m,index);
        if(temp==true)
        {

            break;
        }
        l=2*l;
    }
    if(m<n)
    {
        cout<<m<<" "<<index-1<<endl;
    }
    else
    {
        cout<<"0 0"<<endl;
    }
    return 0;

}
