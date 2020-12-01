#include <iostream>

using namespace std;


int l_finder(int *a,int *b,int i,int j,int n,int m)
{
    if(i==n)
    {
        if(j<m)
        {
            return 10000000;
        }
        else
        {
            return 1;
        }
    }
    else if(j==m)
    {
        if(a[i]==b[m])
        {
            return 1;
        }
        else
        {
            return 1 + l_finder(a,b,i+1,j,n,m);
        }
    }
    else
    {
        if(a[i]==b[j])
        {
            1+ l_finder(a,b,i+1,j+1,n,m);
        }
    }
}

void shortfunc(int *a,int *b,int &n,int &m)
{
    int min1 = 10000000;
    int r,index;
    for(int i=1;i <= n;i++)
    {
        r = l_finder(a,b,i,1,n,m);
        if(min1 >= r)
        {
            min1= r;
            index =i;
        }
    }
    if(min1>100000)
    {
        cout<<"infinity\n";
    }
    else
    {
        cout<<r<<" "<<index<<endl;
    }

}

int main()
{
    int m,n;
    int *a;
    int *b;
    cin>>m>>n;
    a= new int[n];
    b= new int[m];
    for(int i =0; i< n;i++)
    {
        cin>>a[i];
    }
    for(int i =0; i< m;i++)
    {
        cin>>b[i];
    }

    if(n < m)
    {
        cout<<"infinity\n";
    }
    else
    {
        shortfunc(a,b,n,m);
    }
}
