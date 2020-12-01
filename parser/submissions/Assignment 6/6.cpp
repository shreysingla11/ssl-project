#include<iostream>
#include<string>
using namespace std;

void next_block(int l, string &s, int &pos, int &len, bool &found)
{
    int n=s.length();
    int min_length = n;
    int first_pos;
    int no_of_blocks=n/l;
    for(int k=0;k<no_of_blocks;k++)
    {//for each block, find a second occurence
        int i=k*l, j=i+2*l-1;
        while( i<(k+1)*l && j<=(4*l-2)+k*l && i<n && j<n )
        {
            if( s[i]==s[j] )
            {
                i++;j++;
            }
            else if( (s[i]!=s[j]) && i==k*l)
                j++;
            else
                i=0;
        }
        if(i==(k+1)*l) //process the matched blocks
        {   //blocks matched
            int lower_pos1,lower_pos2;
            int upper_pos1,upper_pos2;
            int begin1=k*l;
            int begin2=j-l;
            //Going backwards
            int b=0;
            while( b<3*l-2 && begin1-b>=0 ) // careful
            {
                if( s[begin1-b] == s[begin2-b] )
                    b++;
                else
                    break;
            }
            lower_pos1 = begin1-b+1;
            lower_pos2 = begin2-b+1;
            //Going forwards
            int f=1;
            while( begin1+l-1+f < lower_pos2 && begin2+f+l-1<n )   //careful
            {
                if( s[begin1+f+l-1] == s[begin2+f+l-1] )
                    f++;
                else
                    break;
            }
            if(f==lower_pos2-begin1-l+1)
            {   //word found
                found=true;
                int wordlen=lower_pos2-lower_pos1;
                if(min_length>wordlen)
                {
                    min_length = wordlen;
                    first_pos = lower_pos1;
                }
                else if(min_length==wordlen)
                {
                    if(first_pos>lower_pos1)
                        first_pos=lower_pos1;
                }
                else
                    continue;
            }
        }
    }
    pos=first_pos;
    len=min_length;
}

int main()
{
    string s;
    bool f=false;
    int pos=0,len=0;
    cin>>s;
    int n = s.length();
    int l=1;
    while(l<n)
    {

        next_block(l,s,pos,len,f);
        if(f==true)
        {
            cout<<len<<" "<<pos;
            break;
        }
        else
            l=l*2;
    }
    if(f==false)
        cout<<0<<" "<<0;
    return 0;
}
