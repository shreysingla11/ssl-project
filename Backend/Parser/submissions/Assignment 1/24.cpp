#include<iostream>
#include<cmath>
using namespace std;
extern double f(long long int n);
int main()
{
    int N;
    cout<<"Give the number n :"<<endl;
    cin>>N;
    double m=0,q=0,max_a=0,prev=f(1),next;
    for(int n=1; n<N; n++)
    {
        next=f(n+1);
        double a=prev-next;
        prev=next;
        if(max_a<a) max_a=a;
        if(a>=0)
        {
            q=q+a;
            if(m<=q)    m=q;
        }
        else            q=0;
    }
    cout<<m<<endl<<max_a;
    return 0;
}
