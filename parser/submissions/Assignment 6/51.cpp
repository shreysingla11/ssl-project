#include<iostream>
#include<cstdio>
#include<vector>
#include<string>

using namespace std;

bool compare(int i,int j)
{
    if(i==j) return true;
    else return false;
}

int main()
{
    string a;
    cin>>a;
   /* int len=a.length();
    int l,length;
    int i,j;
    bool r;
    /*while(l<=(len+2)/4 && r==false)
    {
        int i=0;
        bool t=true;
        while(i<len/l)
        {
            if(compare(a[i],a[2*l-1+i]) && i%(len/l)==0 && 2*l+i<=len)
        }
    }
    */
    /*
    for(l=1;l<=(len+2)/4;l=l*2)
    {
        for(int k=0;k<len/l;k++)
        {
            r=true;
            i=k*l;
            j=i+2*l-1;
            while(i<=k*l+l-1 && i<len && j<len)
            {
                if(a[i]==a[j]){i=i++;j++;}
                else if (i==0 && j+1<=i*l+4*l-2){j++;}
                else if (j+1<i*l+4*l-2) {i=k*l;}
                else {r=false;break;}
            }
        }
            length=l;
            if(r==true)
            {
                int s=j-l;
                i=k*l;
                bool q=true;;
                while(s-1>=0 && i-1>=0 )
                {
                    if(a[s-1]==a[i-1]){length++;s--;i--;}
                    else {break;}
                }
                s=j-1;
                i=k*l+l-1;
                q=true;
                while(s+1<=len && i+1<=len )
                {
                    if(a[s+1]==a[i+1]){length++;s++;i++;}
                    else {break;}
                }
            }

    }
    cout<<length;
*/cout<<"0 0"<<endl;
}
