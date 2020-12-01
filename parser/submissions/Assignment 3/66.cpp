#include<iostream>
#include<vector>
#include<limits>
using namespace std;
int inf=10000000;
int n,m;

int minim = inf, index =0;

vector<int> a;
vector<int> b;
vector<int> c;

int main()
{
    cin>>n>>m;

    a.resize(n);
    b.resize(m);
    c.resize(m);

    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }

    for(int i=0; i<m; i++)
    {
        cin>>b[i];
    }


    for(int row=n-1; row>=0; row--)
    {
        for(int col=0; col<m; col++)
        {
            if(row==(n-1) && col==(m-1))
            {
                if(a[row]==b[col])c[col] = 1;
                else c[col] = inf;
            }

            else if(col==(m-1))
            {
                if(a[row]==b[col])
                    {c[col] = 1;}
                else
                {c[col] = (1 + c[col]);}
            }

            else if(row==(n-1) && col!=(m-1))
            {
                c[col] = inf;
            }

            else if(a[row]==b[col])
                c[col] = 1 + c[col+1];
            else c[col] = 1 + c[col];


        }

        if(minim > c[0])
        {
            minim = c[0];
            index = row+1;
        }
    }


        cout<<minim<<" "<<index;
        return 0;
}

