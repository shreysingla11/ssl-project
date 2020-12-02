#include<iostream>
#include<vector>
#include <stack>
using namespace std;
int main()
{
    vector<int> * P;
    stack<int> S;
    int n,min=0,max=0,su=0;
    cin>>n;
    int *T,*N,*NOF,*NON,*BOOL,*Stackenter;
    T=new int[n];
    N=new int[n];
    NOF=new int[n];
    NON=new int[n];
    BOOL=new int[n];
    bool un[n];
    Stackenter=new int[n];
    for(int i=0; i<n; i++)
    {
        NOF[i]=0;
        NON[i]=0;
        BOOL[i]=-1;
        Stackenter[i]=0;
    }
    P=new vector<int>[n];
    for(int i=0; i<n; i++)
    {
        cin>>T[i];
        cin>>N[i];
        for(int j=0; j<N[i]; j++)
        {
            int temp;
            cin>>temp;;
            P[temp].push_back(i);
        }
    }
    for(int i=0; i<n; i++)
    {
        if(T[i]==0)
        {
            min++;max++;
            S.push(i);
            Stackenter[i]=1;
            BOOL[i]=1;
            un[i]=0;
        }else
        {
                if(T[i]>N[i])
        {
            S.push(i);
            Stackenter[i]=1;
            BOOL[i]=0;
            un[i]=0;
        }
        else{
            un[i]=1;
            su++;
        }
        }

    }
    while(S.size()!=0)
    {
        int index=S.top();
        S.pop();
        for(int i=0; i<P[index].size(); i++)
        {
            int index1=P[index][i];
            if(BOOL[index]==1)
            {
                if(Stackenter[index1]==0)
                {
                    if(un[index1]){
                    NOF[index1]++;
                    if(NOF[index1]>=T[index1])
                    {

                        S.push(index1);
                        Stackenter[index1]=1;
                        BOOL[index1]=1;
                        un[index1]=0;
                        min++;max++;su--;

                    }}
                }
            }
            else
            {
                if(Stackenter[index1]==0)
                {
                    if(un[index1])
                    {
                            NON[index1]++;
                            if(NON[index1]+T[index1]>N[index1])
                            {
                                S.push(index1);
                                Stackenter[index1]=1;
                                BOOL[index1]=0;su--;
                            }
                    }
                }
            }
        }
    }
    max=max+su;
    cout<<min<<" "<<max<<endl;
}
