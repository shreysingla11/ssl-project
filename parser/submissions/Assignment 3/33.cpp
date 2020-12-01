#include<iostream>
using namespace std;

int main()
{
    int *a , *b ,*L;
    int la,lb,j,k;
    cin>>la>>lb;
    a = new int[la+1];
    b = new int[lb+1];
    L = new int[la+1];
    for(int i=1;i<la+1;i++)
    {
        cin>>a[i];
        L[i] = 0;
    }
    for(int i=1;i<lb+1;i++)
    {
        cin>>b[i];
    }

    for(int i=1;i<la+1;i++)
    {
        if((la-i) < lb)
        {
            break;
        }
        if(a[i] != b[1])
        {
            continue;
        }
        for(j=i,k=1;(j<(la+1))&&(k<(lb+1));)
        {
            if((la-j) < (lb-k))
            {
                break;
            }
            if(a[j] == b[k])
            {
                L[i]++;
                j++;
                k++;
                continue;
            }
            else
            {
                L[i]++;
                j++;
                continue;
            }
        }
        if(k!=(lb+1))
        {
            L[i] = 0;
        }
    }

    int min,minindex;
    for(int i=1;i<la+1;i++)
    {
        if(L[i]!=0)
        {
            min = L[i];
            minindex = i;
            break;
        }
    }
    for(int i=2;i<la+1;i++)
    {
        if(L[i] == 0)
        {
            continue;
        }
        if(min > L[i])
        {
            min = L[i];
            minindex = i;
        }
    }

    if(min==0)
    {
        cout<<"infinity";
    }
    else
    {
        cout<<min<<" "<<minindex;
    }

    return 0;
}
