#include<iostream>
using namespace std;
/*int[] d2b(long long int n){
//long long int ans = 0 ;
int A[45];
//int k=1;
int x=0;
while(n>0){
//int r;
//r=n%2;
A[x]=n%2;
//r*=k;
//ans+=r;
//k=k*10;
x++;
n=n/2;
}
return A[];
}
*/
int main()
{
    int t;
    cin>>t;
    while(t>0)
    {
        long long int n;
        cin>>n;
        int A[45]= {0};
        int x=0;
        while(n>0)
        {
            A[x]=n%2;
            x++;
            n=n/2;
        }

        int error_count=0;
        x=0;
        int ans[5];
        for(int i=1; i<6; i++)
        {
            int num_1=0;
            for(int j=x; j<x+9; j++)
            {
                if(A[j]==1)
                {
                    num_1++;
                }
            }
            if(num_1>4)
            {   //cout<<"1 "<<num_1<<endl;
                error_count+=9-num_1;
                ans[i-1]=1;
            }
            else{
                //cout<<"0 "<<num_1<<endl;
                error_count+=num_1;
                ans[i-1]=0;
            }
            x=x+9;
        }
        //cout<<error_count<<endl;
        if (error_count>4){
        cout<<"?";
        t--;
        continue;
        }
        int q=16,dec=0;
        for(int p=4;p>=0;p--){
        dec+=ans[p]*q;
        q=q/2;
        }
        char c;
        c='a'+dec;
        cout<<c;
        t--;
    }
    return 0;
}
