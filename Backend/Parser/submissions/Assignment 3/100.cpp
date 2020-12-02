#include<iostream>
#include<vector>
using namespace std;

int what(int i,vector<int> v,int j)
{
    int k;
    for (; k<v.size(); k++)
    {
        if (v[k]>i)
        {
            break;
        }

    }
    return (k-1);
}

int main()
{
    int n,m,*a,*b,j=0,k=0,start=0,end1=0,first=100000000,check,temp1=n,second=0;
    vector<int> v;
    cin>>n>>m;
    a=new int[n];
    b=new int[m];
    for (int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    for (int i=0; i<m; i++)
    {
        cin>>b[i];
    }
    if (n<9999)
    {
        for (int i=0; i<n-m; i++)
        {
            if (a[i]==b[0])
            {
                v.push_back(i);
            }
        }
        while (j!=v.size())
        {
            k=0;
            start=v[j]+1;
            end1=v[j]+1;
            for (int i=v[j]; i<n; i++)
            {
                if (a[i]==b[k])
                {
                    k++;
                }
                if (k==m)
                {
                    end1=i+1;
                    //  cout<<"Done  "<<end1<<endl;
                    break;
                }
            }
            temp1=end1-start+1;
            if (temp1>1&&temp1<first)
            {
                first = temp1;
                second = start;
            }
            j++;
        }
    }
    else
    {
        for (int i=0; i<((n-m)); i++)
        {
            if (a[i]==b[0])
            {
                v.push_back(i);
            }
        }
        while (j!=v.size())
        {
            k=0;
            start=v[j]+1;
            end1=v[j]+1;
            for (int i=v[j]; i<n; i++)
            {
                if (a[i]==b[k])
                {
                    if (k==1)
                    {
                        j=what(i,v,j);
                        start=v[j]+1;
                        end1=v[j]+1;
                    }
                    k++;
                }
                if (k==m)
                {
                    end1=i+1;
                    //  cout<<"Done  "<<end1<<endl;
                    break;
                }
            }
            temp1=end1-start+1;
            if (temp1>1&&temp1<first)
            {
                first = temp1;
                second = start;
            }
            j++;
        }
    }

    /*   for (int i=0;i<v.size();i++)
       {
           cout<<v[i]<<endl;
       }*/

    if (first==0)
    {
        cout<<"infinity";
    }
    else
    {
        cout<<first<<" "<<second<<endl;
    }

}
