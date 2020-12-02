#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main()
{
    string input1;
    cin>>input1;
    int l,br=0;;
    int n=input1.length();
    for(l=1; l<=n/2; l++)
    {
        for(int i=0; i<n-2*l+1; i++)
        {
            int j=i;
            while(input1[j]==input1[j+l])
            {
                if(j==i+l-1)
                {
                    cout<<l<<" "<<i<<endl;
                    br=1;
                    break;
                }
                j++;
            }
            if(br==1)
            {
                break;
            }
        }
        if(br==1)
        {
            break;
        }
    }
    if(br!=1)
    {
        cout<<"0 0";
    }
    return 0;
}
