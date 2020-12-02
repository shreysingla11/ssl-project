#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n,m;
    cin>>n;
    cin>>m;
    int * a = new int[n];
    int * b = new int[m];
    for(int i = 0; i<n; i++)
    {
        cin>>a[i];
    }
    for(int i = 0; i<m; i++)
    {
        cin>>b[i];
    }
    vector< int > curr(n,-1);
    vector< int > prev(n,-1);
    if(a[n-1] == b[m-1])
    {
        curr[n-1] = 1;
    }
    for(int j = m-1; j>=0; j--)
    {
        if(j!=m-1)
        {
        curr[n-m+j+1] = -1;
        }
        for(int i = n-m+j; i>=0; i--)
        {

            if(j==m-1)
            {
                if(a[i] == b[j])
                {
                    curr[i] = 1;
                }
                else if(curr[i+1] != -1)
                {
                    curr[i] = curr[i+1]+1;
                }
                //cout<<"hsdcbjdfsddk2"<<endl;
                continue;
            }
            if(a[i] == b[j])
            {
                if(prev[i+1]!=-1)
                {
                    curr[i] = prev[i+1]+1;
                }
                else
                {
                    curr[i] = -1;
                }

            }
            else
            {
                if(curr[i+1]!=-1)
                {
                    curr[i] = curr[i+1]+1;
                }
                else
                {
                    curr[i] = -1;
                }
            }
        }
        //cout<<"dhdusdh"<<endl;

       /* for(int my = n-1; my>=0; my--)
        {
            // cout<<curr[my]<<" "<<prev[my];
        }*/
        prev = curr;
        //curr[n-1] = -1;
        /* for(int k = 0; k<n; k++)
         {
             curr[k] = -1;
         }*/

        //cout<<"dhdusdh222222222222222"<<endl;        //cout<<"dhdusdh"<<endl;

    }
    //cout<<"Shit is real"<<endl;
    int mini = n+m+1,min_index = n;
    for(int index = n-1; index>=0; index--)
    {
        //cout<<prev[index]<<endl;
        if(prev[index]<=mini&&prev[index]>-1)
        {
            mini = prev[index];
            min_index = index;
        }
    }
    if(mini<=n+m+1)
    {
        cout<<mini<<" "<<min_index+1;
    }
    return 0;
}
