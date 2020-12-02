#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str;

    cin>>str;

    int n=str.length();
    int l,w=0,pos=0,minw=n+1,minpos=0;
    int i,j,k;
    bool found=false;
    for(l=1;2*l<=n/2+1;l*=2)
    {


        for(i=0;i<n-1;i+=l)//Comparing elements for each block
        {
            k=2*l-1;//length of w being compared

            while(k<=4*l-2)
            {

                j=i;

                while(j+k<=n&&str[j]==str[j+k]&&(j-i)<k){
                    j++;

                }
                if(j-i>=k){

                    found=true;
                    w=k;
                    pos=i;
                    break;
                    }
                k++;
            }
            if(w<minw&&w){

                minw=w;
                minpos=pos;
            }
        }
    }
    if(found)
    cout<<minw<<" "<<minpos;
    else
    cout<<"0 0";
}
