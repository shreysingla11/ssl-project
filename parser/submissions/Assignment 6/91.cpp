#include <iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    getline(cin,s);
    size_t n=s.size();
    int l=1;
    int lengthw=n;
    int positionw=0;
    bool foundsquare=true;
    while(l<=n)
    {
        int k=(n/l);
        for(int i=0; i<k; i++)
        {
            int y=0;
            for(int x=0; x<l && (l*i+2*l-1+y)<n && y<(3*l) ; x++ , y++)
            {
                if(s[l*i+x]!=s[l*i+2*l-1+y])
                {
                    x=-1;
                    y=y-1;
                    continue;
                }
                else
                {
                    if(x==l-1)
                    {
                        if(lengthw>(2*l-1+y-x))
                        {
                            foundsquare=true;
                            int xl,yl;
                            for(xl=0; (l*i-xl)>=0; xl++)
                            {
                                if(s[l*i-xl]!=s[l*i+l+y-xl])
                                    break;
                            }
                            if((l*i-xl)==-1)xl--;
                            yl=y-xl;
                            for(int a=0; a<yl && (l*i+2*l+y+a)<n ; a++)
                            {
                                if(s[l*i+l+a]!=s[l*i+2*l+y+a])
                                {
                                    foundsquare=false;
                                    break;
                                }
                            }
                            if(foundsquare==true)
                            {
                                lengthw=2*l-1+y-x;
                                positionw=l*i-xl;
                            }
                        }

                    }
                }
            }


        }
        if(lengthw!=n)
        {
            cout<<lengthw<<" "<<positionw<<endl;
            return 0;
        }
        lengthw=n;
        l=l*2;
    }
    cout<<"0 0"<<endl;

}
