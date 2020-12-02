#include<iostream>
#include<cstdio>
using namespace std;
// will check for goodness
int s(int i,int j,int k,int ** c)
{
    int g=0;
    if(k==0)
    {
        if(i==j)
        {
            return 0;
        }
        else
        {
            if(c[i][j]>0)
            {
                return c[i][j];
            }
            else
            {
                return -c[i][j];
            }
        }
    }
    else
    {
//
        if(i==j)
        {
            return 0;
        }
//
        int min,a,b;
        a = s(i,j,k-1,c);
        b = s(i,k-1,k-1,c)+s(k-1,j,k-1,c);
        if(a>b)
        {
            min = b;
        }
        else
        {
            min = a;
        }
        return min;
    }
}
//
int gs(int i,int j,int k,int ** c)
{
    if(k==0)
    {
        if(i==j)
        {
            return 0;
        }
        else
        {
            if(c[i][j]>0)
            {
                //check for c[i][i]
                if(c[i][i]>0&&c[j][j]>0)
                {
                    return 100000;
                }


                if(c[i][i]>0&&c[j][j]<0)
                {
                    return c[i][j]-c[j][j];
                }
                if(c[i][i]<0&&c[j][j]>0)
                {
                    return c[i][j]-c[i][i];
                }
                if(c[i][i]<0&&c[j][j]<0)
                {
                    if(c[i][i]>c[j][j])
                    {
                        return c[i][j]-c[i][i];
                    }
                    else
                    {
                        return c[i][j]-c[j][j];
                    }
                }
            }

            else
            {
                return -c[i][j];
            }
        }
    }
    else
    {
//
        if(i==j)
        {
            return 0;
        }
//
        int min,a,b;
        a = gs(i,j,k-1,c);
        //total path should be good.
        b = gs(i,k-1,k-1,c)+ gs(k-1,j,k-1,c);
        if(a>b)
        {
            min = b;
        }
        else
        {
            min = a;
        }
        return min;
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    int ** c;
    c = new int*[n];
    for(int i=0; i<n; i++)
    {
        c[i]=new int[n];
        for(int j=0; j<n; j++)
        {
            scanf("%d",&(c[i][j]));
        }
    }
    printf("%d\n",0);
    for(int j=1; j<n; j++)
    {
        int a = gs(0,j,n,c);
        if(a<100000){printf("%d\n",a);}
        else{printf("infinity\n");}
    }
    return 0;
}
