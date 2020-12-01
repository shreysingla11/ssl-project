#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

void minwsq(string str,int n,int l,int &mlen,int &mpos)
{
    for(int bspos=0;bspos<n;bspos+=l)
    {
        bool comp=0;
        int b2spos[2]={-1,-1},b2stemp,z=0;
        for(int i=bspos,b2stemp=bspos+l;(i<bspos+l)&&(i<n)&&(b2stemp<=bspos+4*l-2)&&(b2stemp<n);)
        {
            for(int j=b2stemp;(j<=b2stemp+l)&&(j<n);i++,j++)
            {
                if(j==b2stemp+l)
                {
                    b2spos[z]=b2stemp;
                    z++;
                    i=bspos;
                    b2stemp=j;
                    //cout<<bspos<<" "<<l<<" "<<b2spos[z-1]<<endl;
                    break;
                }
                if(str[i]!=str[j])
                {
                    i=bspos;
                    if(i==bspos)b2stemp=j+1;
                    else b2stemp=j;
                    break;
                }
            }
        }

        for(z=0;z<2;z++)
        {
            if(b2spos[z]==-1)break;
            //for()



        }


    }
    return;
}



int main()
{
    string str;
    int n,mlen=0,mpos=0,l;
    getline(cin,str);
    n=str.length();
    for(l=1;l<=n/2;l=l*2)
    {
        if(mlen!=0)break;
        //minwsq(str,n,l,mlen,mpos);
    }

    cout<<mlen<<" "<<mpos;
    return 0;
}
