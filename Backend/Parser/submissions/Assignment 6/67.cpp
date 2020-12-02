#include<iostream>
#include<tgmath.h>
#include<vector>

using namespace std;

int main()
{
    //Input
    string st;
    cin>>st;
    int n=st.length();
    bool found=false;
    int s_len=1, pos=0;

    //Process
    for(int l=1;l<=n/2 && !found;l*=2)
    {
        //Making blocks
        vector<string> s((n/l)+1);
        for(int i=0;i<n/l;i++)
        {
            s[i]=st.substr(i*l,l);
        }
        s[n/l]=st.substr((n/l)*l);

        //Searching for overlap
        for(int i=0;i<(n/l) && !found;i++)
        {
            string block=s[i];
            int block_pos=0;
            int j=l*(i+1);
            int cur=j;
            while(block_pos<l && st[j]!='\0' && j<=l*(i+1)+(3*l-2))
            {
                if(block[block_pos]==st[j])
                    block_pos++;
                else
                {
                    block_pos=0;
                    cur=j+1;
                }
                j++;
            }

            //If block exists
            if(block_pos==l)
            {
                int temp_block_begin=i*l;
                int temp_str_begin=cur;
                int temp_block_end=l*(i+1);
                int temp_str_end=j;
                while(temp_block_begin>=0 && temp_str_begin>=temp_block_end && st[temp_block_begin]==st[temp_str_begin])
                {
                    temp_block_begin--;temp_str_begin--;
                }
                temp_block_begin++;temp_str_begin++;
                if(temp_str_begin==temp_block_end && st[temp_block_begin]==st[temp_str_begin])
                {
                    found=true;
                    s_len=temp_block_end-temp_block_begin;
                    pos=temp_block_begin;
                }

                while(temp_block_end<temp_str_begin && st[temp_str_end]!='\0' && st[temp_block_end]==st[temp_str_end])
                {
                    temp_block_end++;temp_str_end++;
                }
                if(temp_str_begin==temp_block_end && !found && st[temp_str_end-1]==st[temp_block_end-1])
                {
                    found=true;
                    s_len=temp_block_end-temp_block_begin;
                    pos=temp_block_begin;
                }
            }

        }

    }

    //Output
    if(!found)
        cout<<"0 0"<<endl;
    else
        cout<<s_len<<" "<<pos<<endl;

    return 0;
}
