#include<iostream>
using namespace std;
int main (){
int n,m,c1,c2;
cin>>n>>m;
int a[n],b[m],l[n];
for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    for(int i=0; i<m; i++)
    {
        cin>>b[i];
    }
    if(a[n-1]==b[m-1])
    {
        l[n-1]=1;
    }
    else
    {
        l[n-1]=2147480000;
    }
    c2=l[n-1];
     for(int i=n-2; i>=0; i--)
    {
        if(a[i]==b[m-1])
        {
            l[i]=1;
        }
        else
        {
            l[i]=1+l[i+1];
        }
    }
    if(n>1){
    l[n-1]=2147480000;
    }
        for(int j=m-2; j>=0; j--)
    {
        for(int i=n-2; i>=0; i--)
        {
        c1=l[i];
            if(b[j]==a[i])
            {

                l[i]=1+c2;
            }
            else
            {
                {
                    l[i]=1+l[i+1];
                }
            }
            c2=c1;
        }
    }
int min=l[0],s=0;
for(int i=n-2;i>=0;i--){
if(l[i]<=min){min=l[i];
s=i;
}
}
s++;
if(min>2147470000){
cout<<"infinity";
}
else{
cout<<min<<" "<<s;
}
return 0;
}
