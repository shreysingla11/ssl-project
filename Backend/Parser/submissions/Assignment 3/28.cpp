#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int m,n;
    int i,j;

    //////////////Input
    cin>>n>>m;
    vector<int> a(n,0);
    vector<int> b(m,0);
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<m;i++)
        cin>>b[i];
    ////////////////////

    n--;m--;
    vector<int> L(n+1,0);

    L[n]=(a[n]==b[m])? 1:0;
    //cout<<L[n][m];
    int val=0;
    for(i=n;i>=0;i--){////Filling up the last column
           if(a[i]==b[m]){
           val=1;
           L[i]=val;
           continue;
           }
           if(val!=0)
                L[i]=++val;
            else
            L[i]=0;
        }
    /*for(i=0;i<=n;i++){
        cout<<L[i]<<" ";
        }
    cout<<endl;*/
    if(L[0]==0)//b[m] was not found
        {cout<<"Infinity";return -1;}
    bool firstOcc;
        int k=n;
        for(j=m-1;j>=0;j--){
                i=k;

                firstOcc=false;
                while(a[i-1]!=b[j]){
                    L[i]=0;
                    if(i==0)
                    {cout<<"Infinity";return -1;}
                    i--;

                }

                for(;i>=1;i--){
                    if(a[i-1]==b[j]){
                        if(!firstOcc){
                        k=i;firstOcc=true;}
                         L[i-1]=L[i]+1;
                         L[i]=(L[i+1])? L[i+1]+1:0;
                         i--;
                         }
                    else
                        L[i]=L[i+1]+1;
                }
                k--;
        /*for(i=0;i<=n;i++){
        cout<<L[i]<<" ";
        }
    cout<<endl;*/
}



    int pos,min=n+1;
    for(i=0;i<=n-m;i++)
        if(L[i]<min&&L[i]>0){
            min=L[i];
            pos=i;
        }
    cout<<min<<" "<<pos+1;
}

