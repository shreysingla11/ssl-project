#include <iostream>
using namespace std;
int A[1050000];
long long ans[1050000];
bool B[1050000];
     long long ans3[1050000];
 long long ans2[1050000];
void func(int st,int endt){
    if(st==endt){
    ans[st]=A[st];
    return; }
    int mid=(st+endt)/2;
    func(st,mid);
    func(mid+1,endt);
    int con=st-mid-1;
    for(int i=mid+1;i<=endt;i++){
        ans[i]+=ans[i+con];
    }
    return;
}

void func1(int A1[],bool B1[],int n,long long ans1[]){
    if(n==1){
    ans1[0]=A1[0];
    return; }
    int m=n/2;
    int a1[m];
    int a2[m];
    bool b2[m];
    bool b1[m];
    long long an1[m];
    long long an2[m];
    for(int i=0;i<m;i++){
        a1[i]=A1[i];
        b1[i]=B1[i];
        
    }
      for(int i=m;i<n;i++){
        a2[i-m]=A1[i];
        b2[i-m]=B1[i];
        
    }

    func1(a1,b1,m,an1);
    for(int i=m;i<n;i++){ 
        if(B1[i])
        a2[i-m]=A1[i]-an1[i-m];
        else
        a2[i-m]=A1[i];
    }
        func1(a2,b2,m,an2);
        for(int i=0;i<m;i++)
        ans1[i]=an1[i];
           for(int i=m;i<n;i++){
        ans1[i]=an1[i-m]+an2[i-m];
    }
    return;
}

void func4(long long A1[],int n,long long ans1[]){
    if(n==1){
    ans1[0]=A1[0];
    return; }
    int m=n/2;
    long long a1[m];
    long long a2[m];
    long long an1[m];
    long long an2[m];
    for(int i=0;i<m;i++){
        a1[i]=A1[i];
    }
      for(int i=m;i<n;i++){
        a2[i-m]=A1[i];
        
    }
  for(int i=0;i<m;i++){ 
        a2[i]=a2[i]-a1[i];
    }
    func4(a1,m,an1);
        func4(a2,m,an2);
        for(int i=0;i<m;i++)
        ans1[i]=an1[i];
         for(int i=m;i<=n;i++)
        ans1[i]=an2[i-m];
        
    
    return;
}
int main() {
    ios_base::sync_with_stdio(false);
     cin.tie(NULL);
    int n;
    cin>>n;
    
    int ct=(1<<n);
   
    for(int i=0;i<ct;i++)
    {cin>>A[i];
ans[i]=0;}
    for(int i=0;i<ct;i++){ int bt;
    cin>>bt;
    if(bt)
    B[i]=true;
        else
        B[i]=false; 
    }
   /* ans[0]=A[0];
 // ans[0]=A[0];*/

    func(0,ct-1);
    for(int i=0;i<ct;i++)
    cout<<ans[i]<<" ";
    cout<<endl; 
    for(int i=0;i<ct;i++)
    {ans2[i]=0;
    ans[i]=0;}
    
     func1(A,B,ct,ans2);
    func4(ans2,ct,ans3);
     for(int i=0;i<ct;i++){
              if(B[i])
     cout<<ans3[i]<<" ";
     else
    cout<<ans2[i]<<" ";
      }
    
    cout<<endl;
  
	// your code goes here
	return 0;
}
