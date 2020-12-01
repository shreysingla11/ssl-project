#include<iostream>
#include<string>
using namespace std;
int main()
{
    string a;
    int l=1,n,c1=0,c2=0,x=0,y=0;
    getline(cin,a);
    cout<<endl;
    n=a.size();


    for(l=1;l<n;l=l*2)
    {
        for(int i=0; i<n; i=i+l)
        {
            int k=i,p,p1,j;
            for(j=i+2*l-1; (j<=(i+5*l-2))&&(k<i+l); j++)
            {
                if((a[k]==a[j]))
                {
                    if(k==i)
                    {
                        p=j;
                    }
                    if((k<i+l-1))
                    {
                        k++;
                        continue;
                    }
                    }
                    else
                    {
                        if((k-i)<=(l-1))
                        {
                            k=i;
                        }
                        else
                        {
                            break;
                        }
                    }

            }
            int k1=i-1;
            p1=p-1;
            if((p1>=0)&&(k1>=0))
            {while(a[p1]==a[k1])
            {cout<<"ff";
                p1--;
                k1--;
                x++;
            }
            }
            int k2=i+l,p2=j+1;
            if((k2<n)&&(p2<n))
            {
            while((a[p2]==a[k2])&&(k2<=p1))
            {
                p2++;
                k2++;
                y++;
            }
            }
            cout<<(x+y+l)<<" "<<i;
            return 0;
        }
    }


    cout<<0<<" "<<0;
    return 0;
}

