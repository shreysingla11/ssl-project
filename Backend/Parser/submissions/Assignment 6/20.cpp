#include<iostream>
#include<cstring>
using namespace std;
int find(string &A,int l,int &len,int &index)
{
    int index1=0,index2=0;
    len=0;int temp1=0,temp3=0;
    bool flag=false;
    int num=A.length()/l;
    for(int i=0; i<num-1; i=i+l)
    {
        int q=i;
        int p=i+l;
        index1=i;
        index2=p;
        //cout<<i<<endl;
        while(p<=i+3*l-1&&q<=i+l-1)
        {

            if(A[q]==A[p])
            {
                if(q+1==i+l||p==i+3*l-1)
                {
                    flag=true;
                    index1=i;
                    index2=p-l+1;
                    if(p!=i+3*l-1){len=l;}
                    break;
                }
                p++;
                q++;
            }
            else
            {
                q=i;
                p++;
            }

        }
        if(flag==true)
        {
            temp1=index1;
            int temp2=index2;
            temp3=index1+l-1;
            int temp4=index2+l-1;
            //len=temp3-temp1;
            //cout<<temp1<<temp2<<temp3<<temp4<<endl;
            while(true)
            {
                if(temp1==0)
                {
                    break;
                }
                if(temp2==temp1+l-1)
                {
                    break;
                }
                if(A[temp1-1]==A[temp2-1])
                {
                    len++;
                    temp1--;
                    temp2--;
                }
                else{break;}
            }
            while(true)
            {
                if(temp3+1==temp2)
                {
                    break;
                }
                if(temp4==temp2+4*l-3)
                {
                    break;
                }
                if(A[temp3+1]==A[temp4+1])
                {
                    len++;
                    temp3++;
                    temp4++;
                }else{break;}

            }
            break;
        }
    }

    index=temp1;
    return flag;
}
int main()
{
    string A;
    cin>>A;
    int len=0,index=0,l=1;
    while(l<A.length())
    {
        bool temp=find(A,l,len,index);
        if(temp==false)
        {
            //cout<<"l"<<l<<endl;
            l=l*2;
        }
        else
        {
            break;
        }
    }
    cout<<len<<" "<<index;
}


