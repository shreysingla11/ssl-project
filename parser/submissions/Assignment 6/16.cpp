#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str;
    getline(cin,str);
    int n=str.size();
    bool ans=false,first,last;
    int ff,fl,bf,bl;
    for(int l=1; l<((n+2)/4); l=l*2)
    {
        int p=0;

        while(p<(n-l-n%l) && !ans)
        {
            int temp=p;
            int q=p+1;
            while(q<(4*l-1) && !ans)
            {
                if(str[p]==str[q])
                {
                    ff=p;
                    fl=ff;
                    bf=q;
                    bl=bf;
                    first=true;
                    last=true;
                    for(int i=p,j=q; i-j!=1;)
                    {
                        if(first ||last)
                        {
                            break;
                        }
                        if(bl<(str.size()-1))
                        {
                            if(str[fl+1]==str[bl+1])
                            {
                                fl=fl+1;
                                bl=bl+1;
                                i=fl;
                            }
                            else
                            {
                                last=false;
                            }
                        }
                        if(ff>0)
                        {
                            if(str[ff-1]==str[bf-1])
                            {
                                ff=ff-1;
                                bf=bf-1;
                                j=bf;
                            }
                            else
                            {
                                first=false;
                            }
                        }
                        if(i-j==1)
                        {
                            ans=true;
                        }
                        else
                        {
                            p=temp;
                            q=bl+1;
                        }
                    }
                }
                else
                {
                    q=q+1;
                }

            }
            p=p+l;
        }
    }

    if(ans)
    {
        cout<<fl-ff+1<<" "<<ff<<endl;
    }
    else
    {
        cout<<"0 0"<<endl;
    }
}

