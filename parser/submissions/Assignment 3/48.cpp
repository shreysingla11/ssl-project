#include<iostream>
#include<stdio.h>
#include<vector>
#include<utility>
using namespace std;
bool find_sub(vector<int>&, vector<int>&, int, int, int&, int&);
int main()
{
    int n,m,length,index;
    scanf("%d %d",&n,&m);
    vector<int> a(n);
    vector<int> b(m);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    cout<<"got a\n";
    for(int i=0; i<m; i++)
    {
        scanf("%d",&b[i]);
    }
    cout<<"got b\n";
    length = -1;
    index = -1;
    if(find_sub(a,b,n,m,length,index))
    {
        cout<<length<<" "<<index;
    }
    return 1;
}
bool find_sub(vector<int>& a, vector<int>& b,int n, int m,int& length, int& index)
{
    vector<int> row(m);
    //intializing the vector row with all -1
    for(int j=m-1; j>=0; j--)
    {
        row[j] = -1;
    }
    if(a[n-1] == b[m-1])
    {
        row[m-1] = 1;
        if(m==1)
        {
            length=1;
            index=1;
        }
    }
    //checking for the required starting from i=n-1 to i=0
    int i,j,temp=-1,temp1;
    for(i=n-2; i>=0; i--)
    {
        //checking for the last index i.e,. j=m-1
        if(a[i] == b[m-1])
        {
            temp = row[m-1];
            row[m-1] = 1;
        }
        else
        {
            temp = row[m-1];
            if(temp != -1)
            {
                row[m-1] = temp+1;
            }
        }
        //checking for the remaining indices i.e., j=m-2 to j=0
        for(j=m-2; j>=0; j--)
        {
            if((n-i)<(m-j))
            {
                break;
            }
            else if(a[i] == b[j])
            {
                if(temp == -1)
                {
                    continue;
                }
                temp1 = row[j];
                row[j] = 1+temp;
                temp = temp1;
            }
            else
            {
                if(row[j] == -1)
                {
                    continue;
                }
                temp = row[j];
                row[j] = 1+temp;
            }
        }
        if(j==-1)
        {
            if((length==-1 && length<row[0])  || length>row[0])
            {
                length = row[0];
                index = i+1;
            }
        }
    }
    return true;
}
