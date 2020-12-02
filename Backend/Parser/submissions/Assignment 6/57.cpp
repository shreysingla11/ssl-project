#include <iostream>
#include<string>
#include<vector>
using namespace std;
vector<int> check(string A, int l, int n)
{   int i=0;
    int j;
    vector<int> C(2);
    C[0]=0;C[1]=0;
    while(i<n)
    {
        int flag1=0;
        j=2*l-1;
        int count=0;
        label:
        for(;j<=4*l-2&&i+j<n;j++)
        {
            int k=0;
            if(A[i]==A[i+j])
            {   int flag2=1;
                while(k<l&&i+j+k<n)
                {   if(A[i+k]!=A[i+j+k]) {flag2=0;break;}
                    k++;
                }
                if(flag2==1){flag1=1; break;}
                j=j+k+1;
            }
        }
        if(flag1==1) count++;
        if(count==1||count==2)
        {   int p=i, q=i+l-1, flag3=0;
            while(p+j-1!=q)
            {
                if(p>0&&A[p-1]==A[p+j-1])
                     p--;
                else if(q+j+1<n&&A[q+1]==A[q+j+1])
                     q++;
                else {break;}
            }
            if(p+j-1==q) flag3=1;
            if(flag3==1) {C[0]=q-p+1;C[1]=p;break;}
            else goto label;
        }
        i+=l;
    }
    return C;
}
int main()
{
    string A;
    cin>>A;
    int n=A.length();
    int l=1;
    vector<int>C(2);
    while(l<n)
    {
        C=check(A,l,n);
        if(C[0]!=0) break;
        l=l*2;
    }
    cout<<C[0]<<"\t"<<C[1];
    return 0;
}

