#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    getline(cin,s);
    int size=s.size();
    for(int i=2; i*2<size; i=i*2)
    {
        int l=i;
        for(int k=0,j=0; j<size; k++)
        {
            int temp=0,count=0,countright=0,countleft=0;
            for(int m=0; m<l && (m+j+temp+2*l-1<j+4*l-2)&&(m+j+temp+2*l-1<size); m++)
            {
                if(count==0)
                {
                    m=0;
                }
                if(s[m+j]==s[m+j+temp+2*l-1])count++;//continue;
                else
                {
                    temp=m+1;
                    count=0;
                    continue;
                }

                if(count==l)
                {
                    ////////////////
                    //code for extending
                    int M=m;
                    for( ; m+j+temp+2*l-1<size&&m+j<M+j+temp+l-1; m++)
                    {   //cout<<"a;lkjhk"<<endl;
                        if(s[m+j]==s[m+j+temp+2*l-1])countright++;//continue;
                        else
                        {
                            break;
                        }
                    }
                    for( int n=1; j-n+temp+2*l-1>0; n++)
                    {   //cout<<"alkjhk"<<endl;
                        if(s[j-n]==s[j-n+temp+2*l-1])countleft++;//continue;
                        else
                        {
                            break;
                        }
                    }

                    if(countright+countleft==temp+l-1)
                    {
                        cout<<M+j-countleft-1<<" "<<l+countright+countleft<<endl;
                        return 0;
                    }
                }
                //
            }
            j=k*l;
        }
    }
}
