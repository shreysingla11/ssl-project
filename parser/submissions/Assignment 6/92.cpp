#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

std::pair<int,int> sq_free(string s)
{
    int a,b,i,j,k,l,n;
    int begorend_w,begorend_w2;
    bool flag_for,flag_back;
    int occur_w;
    n=s.length();
    a = 0;
    b = 0;

    std::pair<int,int> result;
    l=1;

            for(l=1,i=0,j=0,k=l;l<n ; )
            {
                occur_w = 0;

                if(j>=n){l=2*l;j=0;i=0;k=l;continue;}

                if(i == j+l)
                {
                    //extend both sides
                    occur_w++;
                    begorend_w = j;
                    begorend_w2 = k-l;
                    if( (begorend_w2 - begorend_w)<2l-1)
                    {
                        i = j; k = begorend_w2+1;
                       if(occur_w == 2)
                       {    j = j+l;
                            i = j;
                            k = l+j;
                            continue;
                       }
                       continue;
                    }

                    flag_for = true;
                    for( i = begorend_w + l , k = begorend_w2+l; i<begorend_w2 ; i++,k++ )
                    {
                        if( s[i] != s[k] )
                        {
                            flag_for = false;break;
                        }

                    }

                    if(flag_for)
                    {
                        a = begorend_w2 - begorend_w;
                        b = begorend_w;
                        result.first = a;
                        result.second = b;
                        return result;
                    }

                    flag_back = true;
                    for( i = begorend_w + l , k = begorend_w2+l; k>begorend_w ; i--,k-- )
                    {
                        if( s[i] != s[k] )
                        {
                            flag_back = false;break;
                        }

                    }

                    if(flag_back){
                        a = begorend_w2 - begorend_w ;
                        b = 2*begorend_w + l + 1 - begorend_w2 ;
                        result.first = a;
                        result.second = b;
                        return result;
                    }
                    else
                    {
                        j = j+l;
                        i = j;
                        k = l+j;
                        continue;
                    }

                }
                if(k == j+4l-1)
                {   j = j+l;
                    i = j;
                    k = l+j;

                    continue;
                    //move on the next block
                }

                if( s[i] == s[k] )
                {
                    i++; k++;

                }
                else
                {
                    if(i == j){ k++;}
                    else
                    {
                        k = k+i; i = j;
                    }
                }

            } //inner loop

         //outer loop

        result.first = a;
        result.second = b;

        return result;

} //function end

int main()
{
    string s;
    std::pair<int,int> ans;
    //input
    cin>>s;

    ans = sq_free(s);

    //output
    cout<<ans.first<<" "<<ans.second;
    return 0 ;
}
