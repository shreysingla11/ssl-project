#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str;
    cin>>str;
    int n=str.size();
    int l=1;
    for(l=1;(4*l)-2<n;l=2*l)
    {
        int p=n%l;
        if(p==0){;}
        else
        {
            int B[p];
            for(int i=0;i<p;i++)
            {
                B[i]=str[n-p+i];
            }
        }
        int m=n-l+1;
        int A[m][l];
        for(int i=0;i<m;i++)
        {
            for(int k=0;k<l;k++)
            {
                A[i][k]=str[i+k];
            }
        }
        int s=0,t=0;
        for(int i=0;i<m;i++)
        {
            for(s=0,t=((i+1)*l);(s<l)&&(t<((i*s)+(4*l)-2));)
            {

                if(A[i][s]==str[t])
                {
                    s++;
                    t++;
                    if(s==l)
                    {
                        int a=1,c=0;
                        int b=t-1;
                        while((str[((i*l)-c)]==str[b-l])&&((i*l)-c>-1))
                        {
                            c--;
                            b--;
                        }
                        while((str[(i+1)*l+a]==str[t])&&(((i+1)*l+a)!=b-l+1))
                        {
                            a++;
                            t++;
                        }
                        if((((i+1)*l+a)==b-l+1))
                        {
                            cout<<" w starts at "<<((i*l)-c+1)<<endl;
                            cout<<" length "<<b-(((i+1)*l)-c);
                            return 0;
                        }
                    }
                }
                if(A[i][s]!=str[t])
                {
                    s=0;
                    t++;

                }
            }
        }
    }
}
