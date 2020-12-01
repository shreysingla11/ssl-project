#include<iostream>
#include<string>
using namespace std;
string s;
int len=0;
bool value=true;

int blockfound(int index, int l)
{

    int j=(2*l-1);
    while(j<=(3*l-1))
    {
        int k=0;
        for(k=0;(k<l) && (k + index + j<len);k++)
        {
            if ( s[index+k]!=s[index+j+k] )
            {
              value=false;
              break;
            }
            if(k==(l-1))
            {
              return j+index;
            }
        }
        if(value==false)
        {
            j=j+k+1;
        }
    }
    return -1;
}

int main()
{
int lengthofsquare=0;
int positionofsquare=0;
cin >> s ;
len=s.length();
cout<<endl;
int i=1;

for(int l=1;l< ((len+4)/8 +1);l=l*2)
{
    //cout<<"a"<<endl;
    for(i=0;i<len/l;i++)
    {
        //cout<<"b"<<endl;
        if(blockfound(i*l,l)>0)
        {
            //cout<<"c"<<endl;
            int loweroffirst=i*l;
            int lowerofsecond=blockfound(i*l,l);
            int j=1;
            while((lowerofsecond-j)>=(loweroffirst+l))
            {
                //cout<<"d"<<endl;
                if(s[loweroffirst-j]!= s[lowerofsecond-j])
                {
                    break;
                }
                j++;
            }
            j--;
            if( (lowerofsecond-j)==(loweroffirst+l) )
            {
                //cout<<"e"<<endl;
                lengthofsquare=j+l;
                positionofsquare=loweroffirst-l;
                cout<<j + l<<" "<<loweroffirst-l+1<<endl;
                return 0;
            }
            j=1;
            while(lowerofsecond > loweroffirst + l + j - 1)
            {
                //cout<<"f"<<endl;
                if(s[loweroffirst + l + j - 1]!= s[lowerofsecond + l + j - 1])
                {
                    break;
                }
                j++;
            }
            j--;
            if( (lowerofsecond-1)==(loweroffirst + l + j - 1) )
            {
                //cout<<"g"<<endl;
                lengthofsquare=j+l;
                positionofsquare=loweroffirst;
                cout<<j + l<<" "<<loweroffirst<<endl;
                return 0;
            }
        }
        //cout<<"hi"<<endl;
    }
}
cout<<"0 0"<<endl;
return 0;
}
