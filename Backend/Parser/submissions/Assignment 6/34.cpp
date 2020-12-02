# include <iostream>
# include <string.h>
using namespace std;

void func(int &l, string str, int &index, int &length)
{
    int n= str.size();
    int ib=0,i=0,j=0,count=0,ir=0,jr=0,right=0,left=0,il=0,jl=0;
    int temp=0;

    for(ib=0; ib<=n-l; ib+=l)
    {
        i=0,j=0,count=0,ir=0,jr=0,right=0,left=0,il=0,jl=0;
        temp=0;
        count=0;
        j=ib+2*l-1;
        if(j>n-l)
        {

            l=l*2;
            func(l,str,index,length);
            break;
        }
        else
        {

        //cout<<"4"<<endl;
            for (i=ib; i<ib+l;)
            {   //cout<<"5"<<endl;

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
                        i=ib;
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
                //block matched
                for(int right=0;right<=l;right++)
                {
                    if (str[i+right]==str[j+right])
                    {

                    }
                    else
                    {
                        ir=i+right-1;
                        jr=j+right-1;
                        break;
                    }
                }
                for(int left=0;left<=l;left++)
                {
                    if (str[i-l-left]==str[j-l-left])
                    {

                    }
                    else
                    {
                        il=i-l-left+1;
                        jl=j-l-left+1;
                        break;
                    }
                }
                if (ir==jl)
                {
                    //it is square
                    index=il;
                    length=jl-il;
                    //cout<<index<<" "<<length;
                    return;
                }
                else
                {

                }
            }
            else
            {
                //move to next block
            }
        }
    }
    if (length==0)
    {
        l=2*l;
        if (l<n)
        {
            func(l,str,index,length);
        }
        else
        {
            return;
        }
    }
}

int main()
{
    string str;
    //str is a pointer & will behave like an array
    cin>>str;
    int index=0, length=0,l=1;
    func(l,str,index,length);
    cout<<index<<" "<<length;
    return 0;
}
