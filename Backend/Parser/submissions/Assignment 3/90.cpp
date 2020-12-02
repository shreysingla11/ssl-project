#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
int main()
{

    int n,m,i,j;

cin>>n>>m;

    vector<int> a(n+1);
    vector<int> b(m+1);

    for(i=1; i<=n; i++)
    {
        cin>>a[i];

    }

    for(j=1; j<=m; j++)
    {
        cin>>b[j];
    }

    int check,l=n+1,p;
    for(i=1; i<=n; i++)
    {
        if(a[i]==b[1])
        {
            check=2;
            for(j=i+1; j<=n; j++)
            {  // cout<<j<<" "<<i<<" "<<check<<endl;


                if(a[j]==b[check])
                {
                   if(check==m)
                   {
                   if(l>(j-i))
                   {
                   l=j-i;
                   p=i;
                   }
                   break;
                   }

                    check++;

                }


            }
            if(check<m)
            {
            break;
            }

        }


        else
        {
            continue;
        }

    }
     if(l>n)
        {
        cout<<"infinity"<<endl;
        return 0;
        }

    cout<<(l+1)<<" "<<p<<endl;

    return 0;
}

