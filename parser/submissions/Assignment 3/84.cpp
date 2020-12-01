#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n,m;

    cin>>n>>m;

    vector <int> a(n);
    vector <int> b(m);

    for(int k=0; k<n; k++)
    {
        cin>>a[k];
    }

    for(int k=0; k<m; k++)
    {
        cin>>b[k];
    }

    vector <int> L(n);
    int p= (n-1);
    int c=0;
    //for column m

    if(a[n-1]==b[m-1])
        {
            L[n-1]=1;
            if(c==0)
            {
                p=n-1;
                c=1;
            }
        }
    else
        L[n-1]=n+1;

    for(int k=(n-2); k>=0 ; k--)
    {
        if(a[k]==b[m-1])
            {
                L[k]=1;
                if(c==0)
                {
                    p=k;
                    c=1;
                }
            }
        else
            L[k]=1+L[k+1];
    }

    L.erase (L.begin()+(p+1),L.end());
    vector <int> Lnext(p+1);
    L.swap(Lnext);


    //for other columns

    for(int j=(m-2); j>=0; j--)
    {
        L[p]=n+1;
        c=0;

        for(int k=(p-1); k>=0; k--)
        {
            if(a[k]==b[j])
                {
                    L[k]= 1 + Lnext[k+1];
                    if(c==0)
                    {
                        p=k;
                        c=1;
                    }
                }
            else
                L[k]= 1 + L[k+1];
        }

        L.erase (L.begin()+(p+1),L.end());
        Lnext.erase (Lnext.begin()+(p+1),Lnext.end());
        L.swap(Lnext);
    }

    int min=0;
    for(int k=1; k<(p+1); k++)
    {
        if(L[k]<L[min])
            min=k;
    }

    if(L[min]>=(n+1))
        cout<<"infinity";

    else
        cout<<L[min]<<" "<<(min+1);


    return 0;
}
