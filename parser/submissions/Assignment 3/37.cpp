#include<iostream>
#include<vector>
//#include<list>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int *first=new int[n],*second=new int[m];
    for(int i=0; i<n; i++)
    {
        cin>>first[i];
    }
    for(int i=0; i<m; i++)
    {
        cin>>second[i];
    }
    vector<int> current(n,-1);
    vector<int> computed(n,-1);
    if(first[n-1]==second[m-1])
    {
        current[n-1] = 1;
    }
    for(int i=n-2; i!=-1; i--)
    {
        if(first[i]==second[m-1])
        {
            current[i] = 1;//if a_i == b_m otherwise it is 1+L[i+1,m], for 1 <= i < n;
        }
        else
        {
            if(current[i+1]!=-1)
            {
                current[i]=1+current[i+1];
            }
        }
    }
    for(int j=m-2; j>-1; j--)
    {
        computed=current;
        current[n-m+j+1]=-1;
        for(int i=n-m+j; i>-1; i--)
        {
            if(first[i]==second[j])
            {
                if(computed[i+1]!=-1)
                {
                    current[i] = 1 + computed[i+1];
                }
                else
                {
                    current[i]=-1;
                }
            }
            else
            {
                if(current[i+1]!=-1)
                {
                    current[i] = 1 + current[i+1];
                }
                else
                {
                    current[i]=-1;
                }
            }
        }
    }
    int ans=current[0],index=0;
    for(int i=1; i<n; i++)
    {
        if(current[i]<ans&&current[i]!=-1)
        {
            ans=current[i];
            index=i;
        }
    }
    if(ans!=-1){
    cout<<ans<<" "<<index+1;
    }
    else{
    cout<<"infinity";
    }
}
