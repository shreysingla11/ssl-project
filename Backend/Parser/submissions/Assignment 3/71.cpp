#include<iostream>
#include<limits>
using namespace std;


int n,m,*a,*b;
int **l;

int findmatrix(int i,int j,int inf)
{
    int cal=0;
    if((i==n-1)&&(j==m-1))
    {
        if(a[i]==b[j])
        {
            return 1;
        }
        else
        {
            return inf;
        }
    }
    //l[i,m]
    if((i!=n-1)&&(j==m-1))
    {
        if(a[i]==b[j])
        {
            return 1;
        }
        else
        {
            cal=l[i+1][j];
            if(cal==inf)
                return inf;
            else
                return 1+cal;
        }
    }
    //l[n,j]
    if((i==n-1)&&(j!=m-1))
    {
        return inf;
    }
    //l[i,j]
    if((i!=n-1)&&(j!=m-1))
    {
        if(a[i]==b[j])
        {
            cal=l[i+1][j+1];
            if(cal==inf)
                return inf;
            else
                return 1+cal;
        }
        else
        {
            return 1+l[i+1][j];
            if(cal==inf)
                return inf;
            else
                return 1+cal;
        }
    }



}

int main()
{
    cin>>n>>m;
    int x=0,y=0;
    int en;
//input a,b
    a=new int[n];
    b=new int[m];
    int inf = numeric_limits<int>::max()-(n+1);
    l = new int*[n];
    for (int i = 0; i < n; i++)
        l[i] = new int[m];
    while(x!=n)
    {
        cin>>a[x];
        x++;
    }
    while(y!=m)
    {
        cin>>b[y];
        y++;
    }
    for(int q=m-1; q>=0; q--)
    {
        for(int p=n-1; p>=0; p--)
        {
            l[p][q]=findmatrix(p,q,inf);
        }
    }
    int minval=l[0][0],min_index=0;
    for(int z=0; z<n; z++)
    {
      int mass=l[z][0];
        if(mass<minval)
        {
            minval=mass;
            min_index=z+1;
        }
    }
    if(min_index==0)
     min_index++;
    if(minval==inf)
    cout<<"infinity";
    else
    cout<<minval<<" "<<min_index;

    return 0;
}
