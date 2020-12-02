#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;
int main()
{
    string s;
    char temp;
    int rep;
    //getting the input of the string for check
    //cout<<"Enter the string which is to be checked for patterns \n";
    /*
    rep = scanf("%c",&temp);
    while(rep >= 1)
    {
        s+=temp;
        rep = scanf("%c",&temp);
    }
    */
    cin>>s;
    //cout<<s<<"\n";
    int length = s.length();
    //cout<<s.length()<<"\n";
    int min_len=0;
    int min_pos=0;

    //loop running along for each length

    for(int l=1; l<length; l*=2)
    {
        //n is the no of blocks

        int n = (length/l);

        //loop running along for each ordered block except the last one

        //k is the kth block for which other substrings are checked

        for(int k=1; k<n; k++)
        {
            //loop running to check the non-ordered matching blocks within the range

            int i = ((k-1)*l),j = (2*l -1 + i);

            while(i<(k*l) && j<length  && i<length)
            {
                if(s[i]==s[j])
                {
                    i++;
                    j++;
                    //cout<<"match \n";
                }
                else if((s[i]!=s[j]) && i==(k-1)*l)
                {
                    j++;
                    //cout<<"mismatch-1\n";
                    if(j>(4*l-2)+((k-1)*l))
                    {
                        break;
                    }
                }
                else
                {
                    i = 0;
                    //cout<<"mismatch-2\n";
                    if(j>(4*l-2)+((k-1)*l))
                    {
                        break;
                    }
                }
            }

            if(i==k*l)
            {
                //call the func to check the substrings
                //cout<<"found a match \n";
                j = j-1;
                int j_start = j-l+1;
                int j_end = j;
                int i_start = (k-1)*l;
                int i_end = (k*l)-1;

                while(i_start>=0 && j_start>i_end)
                {
                    if(s[i_start]==s[j_start])
                    {
                        i_start--;
                        j_start--;
                    }
                    else
                    {
                        break;
                    }
                }

                i_start++;
                j_start++;
                //cout<<"i-start:"<<i_start<<" j-start:"<<j_start<<"\n";

                while(i_end<j_start && j_end<=((4*l)-2)+j_start-1)
                {
                    if(s[i_end]==s[j_end])
                    {
                        i_end++;
                        j_end++;
                    }
                    else
                    {
                        break;
                    }
                }

                i_end--;
                j_end--;

                if(i_end==j_start-1)
                {
                    if((min_pos==0 && min_len==0) || min_len>(i_end-i_start+1))
                    {
                        min_len = (i_end-i_start+1);
                        min_pos = i_start;
                    }
                }
            }
        }

        if(!(min_pos==0 && min_len==0))
        {
            break;
        }
    }

    cout<<min_len<<" "<<min_pos<<"\n";
    return 1;
}
