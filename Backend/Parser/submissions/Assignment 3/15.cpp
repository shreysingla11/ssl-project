#include<iostream>
#include<vector>

#include<limits>
using namespace std;

int main()
{

    long long n;
    long long m;
    cin>>n>>m;
///taking n and m as input

    vector<long long> A(n);
    vector<long long> B(m);
    for(long long i=0; i<n; i++)
    {
        cin>>A[i];
    };
    for(long long i=0; i<m; i++)
    {
        cin>>B[i];
    };
///taking the two sequences as input
    long long inf=numeric_limits<long long>::max();
    //cout<<inf<<endl;
    if(inf<5555555)
    {
        cout<<"inf not working"<<endl;
    }
///set inf variable to infinity
vector<long long> prev(n);
vector<long long> next(n);
///vector declarations
    for(long long i=m-1; i>=0; i--)
    {
        for(long long j=n-1; j>=0; j--)
        {
            if(j>=i){
            if(i==m-1)
            {
                if(j==n-1){
                    if(A[j]==B[i]){
                    prev[j]=1;
                    }
                    else{
                    prev[j]=inf;
                    }
                }
                else{
                    if(A[j]==B[i]){
                        prev[j]=1;
                        }
                        else{
                        if(prev[j+1]==inf){
                        prev[j]=inf;
                        }
                        else{
                        prev[j]=1+prev[j+1];
                        }
                        }
                }
            }
            else
            {
              //vector<long long> next(n);
               if(j==n-1){
               next[j]=inf;
               }
               else{
               if(A[j]==B[i]){
               if(prev[j+1]==inf){
               next[j]=inf;
               }
               else{
               next[j]=1+prev[j+1];
               }
               }
               else{
               if(next[j+1]==inf){
               next[j]=inf;
               }
               else{
               next[j]=1+next[j+1];
               }
               }
               }

            }
            }
        }
        if(i!=m-1){
        prev=next;
        }
    }
    long long mini=prev[0];long long min_index=0;
for(long long i=0;i<n;i++){
if(prev[i]<mini){
mini=prev[i];
min_index=i;
}
}
if(mini==inf){
cout<<"infinity"<<endl;
}
else{
cout<<mini<<" "<<min_index+1<<endl;
}
    return 0;

}
