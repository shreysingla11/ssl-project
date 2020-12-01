#include <iostream>

#define Infinty 10000000
using namespace std;
void computecol (int** l, int*a, int*b,int n,int currcol )
{
    l[n-1][0] =n+1;
    for (int i=n-2; i>=0; i--)
    {
        if (a[i]==b[currcol]) l[i][0] = 1+l[i+1][1];
        else l[i][0] = 1+ l[i+1][0];
    }
    for (int i=0; i<n; i++) l[i][1]=l[i][0];//copying into 2nd col
}
int main()
{
    int n,m,i,currcol;
    cin>>n;
    cin>>m;
    int*a;
    int*b;
    int**l;
    a = new int[n];
    b= new int[m];
    for (i=0; i<n; i++)
    {
        cin>>a[i];
    }
    for (i=0; i<m; i++)
    {
        cin>>b[i];
    }

    l =new int* [n];
    for(int i=0; i<n; i++)
    {
        l[i]=new int [2];
    }


    if (a[n-1]==b[m-1])
    {

        l[n-1][1] = 1;
    }
    else l[n-1][1] = n+1;

    for(int i=n-2; i>=0; i--)
    {
        if (a[i]==b[m-1])l[i][1]=1;
        else l[i][1] = 1+l[i+1][1];

    }

    for(currcol=m-2; currcol>=0; currcol--)
    {
        computecol(l,a,b,n,currcol);
        //for (int i =0; i<n;i++) {cout <<l[i][1]<<endl;}

    }

    int start=-1;
    int minLength=n+1;
    for (i=0; i<n; i++)
    {
        if (l[i][1]<minLength)
        {
            minLength = l[i][1];
            start=i;
        }
    }
    start=start+1;
    if (start==0) cout<<"infinity"<<endl;
    else cout<<minLength<<" "<<start<<endl;

    return 0;
}
