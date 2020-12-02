#include<iostream>

using namespace std;
bool square(string s, int st , int coin , int &len, int siz)
{
    if(st+len==coin)
    {
        return 1;
    }
    if(coin+len<siz)
    {
        return 0;
    }
    int k,c;
    k=st+len;
    c=coin+len;
    if (s[k]==s[c])
    {
        len++;
        square(s,st,coin,len,siz);
    }

}

int main()
{

    string sg;
    cin>>sg;
    int n;
    int k=0;
     int z=0;
    n=sg.size();
    int l,i,j;
    for(l=1; l<n; l=l*2)
    {
        for (j=0; j<n; j=j+l)
        {
            string s1;
            s1=sg.substr(j,l);
               for(i=j+l;i<j+3*l-2; i++)
            {string s2;
            s2=sg.substr(i,l);
            int t;
            t=l;
            if(s1==s2){
             cout<<i;
            if(square(sg,j,i,t,n))
                    {
                        cout<<t;
                        cout<<j;
                        break;
                    }
                    else{cout<<k<<" "<<z<<endl;}

                   }
            }

        }
    }











}
