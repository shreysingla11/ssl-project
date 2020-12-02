#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
extern double f(long long int n);
int main()
{
    long long n;
    cin>>n;
    double m_f=0,m_f_r=0;

    //calculate m_f
    double l_counter=f(1), r_counter=f(n);
    long long l=1,r=n,lc=1,rc=n;
    while(l<=r)
    {
        if(f(l)>l_counter)
        {
            l_counter=f(l);
            lc=l;
        }
        else
        {
            if(m_f<l_counter-f(l))
                m_f=l_counter-f(l);
        }

        if(f(r)<r_counter)
        {
            r_counter=f(r);
            rc=r;
        }
        else
        {
            if(m_f<f(r)-r_counter)
                m_f=f(r)-r_counter;
        }
        if(m_f<l_counter-r_counter)
            m_f=l_counter-r_counter;
        l++;
        r--;
    }

    //calculate m_f_r
    if(m_f!=0)
    {
        m_f_r=m_f/(rc-lc);
        l=1;r=n;lc=1;rc=n;l_counter=f(1);r_counter=f(n);
        for(int i=1;i<n;i++)
        {
            if(m_f_r<(f(i)-f(i+1)))
                m_f_r=f(i)-f(i+1);
        }
    }
    //print stuff
    printf("%.6f",m_f);
    cout<<endl;
    printf("%.6f",m_f_r);
    cout<<endl;
    return 0;
}
