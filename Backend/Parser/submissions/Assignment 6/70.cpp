# include <iostream>
# include <string.h>
using namespace std;

void squares(int l, string str, int &index, int &length)
{
    //cout<<"1"<<endl;
    int n= str.size();
    int block=0,i=0,j=0,count=0,ir=0,jr=0,right=0,left=0,il=0,jl=0;
    int temp=0;

    for(block=0; block<n-l-1; block+=l)
    {
        temp=0;
        count=0;
        j=block+2*l-1;
        if(j>n-l)
        {
            l=l*2;
            squares(l,str,index,length);
            break;
        }
        else
        {
            for (i=block; i<block+l;)
            {
                if(j<=4*l-2)
                {
                    if(str[i]==str[j])
                    {
                        count++;
                        i++;
                        j++;
                        temp=0;
                    }
                    else
                    {
                        count=0;
                        i=block;
                        if (temp==0)
                        {
                            temp=1;
                        }
                        else
                        {
                            j++;
                        }
                    }
                }
                else
                {
                    break;
                }
            }

            if (count==l)
            {

                for(int right=0;right<=l;right++)
                {

                    if (str[i+right]!=str[j+right])
                    {
                        ir=i+right-1;
                        jr=j+right-1;
                        break;
                    }
                }
                for(int left=0;left<=l;left++)
                {
                    if (str[i-l-left]!=str[j-l-left])
                    {
                        il=i-l-left+1;
                        jl=j-l-left+1;
                        break;
                    }
                }
                if (ir==jl)
                {
                    index=il;
                    length=jl-il;
                    return;
                }
            }

        }
    }
    if (length==0)
    {
        l=2*l;
        if (l<n)
        {
            squares(l,str,index,length);
        }
        else
        {
            return;
        }
    }
}

int main()
{
    string s;
    cin>>s;
    int index=0, length=0,l=1;
    squares(l,s,index,length);
    cout<<index<<" "<<length;
    return 0;
}
