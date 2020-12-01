
#include<iostream>
#include<string>
using namespace std;


int main()
{
string s;
cin>>s;
int l=1;
int n=s.length();
bool get=false;
int min_length=1e09;
int min_pos=1e09;
    for(;l<=n;l*=2)
    {

        for(int block_num=0;block_num<=n/l;block_num++)
        {
                int start=block_num*l;
                int second_block_start=start+2*l-1;
                bool compare=false;
                for(int j=0;j<l&&second_block_start<=(start+4*l-2)&&(second_block_start+j)<n;)
                {

                if(s[start]!=s[second_block_start])
                second_block_start++;
                else
                {
                    if(s[start+j]!=s[second_block_start+j])
                    {
                    second_block_start=second_block_start+j;
                    j=0;
                    }
                j++;
                }
                    if(j==l)
                    {
                    compare=true;
                    break;
                    }
                }
            if(compare==true)
                {
                //cout<<"x";
                int flag=0;
                int first_left=start;
                int first_right=start+l-1;
                int second_left=second_block_start;
                int second_right=second_block_start+l-1;
                while(1)
                {
                    if(s[first_left]!=s[second_left])
                    {
                    //cout<<"a";
                    flag=1;
                    break;
                    }
                    if(s[first_right]!=s[second_right])
                    {
                    //cout<<"b";
                    flag=2;
                    break;
                    }
                    if(first_right==second_left)
                    {
                   // cout<<"c";
                    flag=3;
                    break;
                    }
                    if(first_right+1==second_left)
                    {
                    //cout<<"d";
                    flag=4;
                    break;
                    }
                first_left--;
                second_left--;
                first_right++;
                second_right++;

                }
                if(flag==1)
                    {
                        for(int k=0;k<=(second_left-first_right);k++)
                            if(s[first_right+k]!=s[second_right+k])
                            {
                            break;
                            }
                    flag=4;
                    }
                if(flag==2)
                    {
                        for(int k=0;k<=(second_left-first_right);k++)
                            if(s[first_left-k]!=s[second_left-k])
                            {
                            break;
                            }
                    flag=4;
                    }

                if(flag==4)
                    {
                        if(start<min_pos)
                            min_pos=start;
                        if((second_right-first_left)/2<min_length)
                            min_length=(second_right-first_left)/2;

                    get=true;
                    }


                }


        }
    if(get==true)
    break;
    }
cout<<min_length<<" "<<min_pos;
}
