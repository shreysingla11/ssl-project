#include<iostream>
#include<string>
using namespace std;
int main()
{

    string s;
    cin>>s;
    int n=s.length();

    int l=1;
    if(n==1)
    {
        cout<<"0 0";
        return 0;
    }

    for(; ((2*l-1)<=(n/2));)
    {

        int k=n/l,p=n%l,q,r,m;

        for(int i=0; i<(n/l);)
        {

            for(int j=2*l-1; (j<4*l-1)&&(i*l+j<n);)
            {
                if(s[i*l]!=s[i*l+j])
                {
                    j++;
                }
                else
                {
                    bool check1=true,check2=true,check3=true;
                    for(m=0; (m<l)&&(i*l+j+m<n); m++)
                    {
                        if(s[i*l+m]!=s[i*l+j+m])
                        {
                            check1=false;
                        }
                    }
                    if(m!=l){check1=false;}
                    if(check1==true)
                    {
                        for(q=i*l-1; (q>=0)&&(q+j>i*l+l-1);q--)
                        {
                            if(s[q]==s[q+j])
                            {

                            }
                            else
                            {
                                check2=false;
                                break;
                            }
                        }
                        if(q==-1){if(j%2==0)if(q+j!=i*l+l-1){check2=false;}
                                  if(j%2==1)if(q+j!=i*l+l){check2=false;}
                        }



                        if(check2==false)
                        {
                            for(r=i*l+l;(r<=q+j)&&(r<n);)
                            {
                                if(s[r]==s[r+j-l+1])
                                {
                                    r++;
                                }
                                else
                                {
                                    check3=false;
                                    break;
                                }
                            }

                            if(r!=q+j){check3=false;}
                            if(check3==true)
                            {
                                if(i*l!=0){cout<<j<<" "<<q+1;
                                return 0;}
                                else{cout<<j<<" 0";return 0;}
                            }

                        }
                        else
                        {
                            cout<<j<<" "<<q+1;
                            return 0;
                        }
                    }

                    j++;
                }
            }
            i++;
        }


        l=l*2;

    }

    cout<<"0 0";
    return 0;
}
