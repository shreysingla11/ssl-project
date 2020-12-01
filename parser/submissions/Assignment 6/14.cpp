#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int N=s.size();
    int l=1;
    int i=0;
    bool ffound=false;
    for( l=1; l<(N+1)/2; l++)
    {//cout<<"l "<<l<<endl;
        ffound=false;
        for( i=0; (i+l+l)<=N; i++)
        {//cout<<"i "<<i<<endl;
            bool found=true;
            for(int k=0; k<l; k++)
            { //cout<<"here2"<<endl;
            //cout<<s[i+k]<<" "<<s[i+l+k]<<endl;
                if(s[i+k]!=s[i+l+k])
                {
                    found=false;
                    //cout<<"here"<<endl;
                    break;

                }
            }
            if(found)
            {
                ffound=true;
                break;
            }
        }
        if(ffound)
        {
            break;
        }
    }
    if(ffound==false)
    {
        l=0;
        i=0;
    }
    cout<<l<<" "<<i<<endl;
    return 0;
}
