#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

class point
{
    public:
        point()
        {
            side='l';
            val=0.0;
        }
        point(char c, double v)
        {
            side=c;
            val=v;
        }
        char side;
        double val;
};

class ship
{
    public:
        ship()
        {
            dir='E';
            length=0;
            pos=0;
        }
        ship(char c, int l, int p)
        {
            dir=c;
            length=l;
            pos=p;
        }
        char dir;
        int length;
        int pos;
};

bool myfunction (point a,point b)
{
    bool result=true;
    if (a.val<=b.val)
    {
        result=true;
    }
    else
    {
        result=false;
    }
    return result;
};

int main()
{
    int n, w, u, v, t1, t2, total=0;
    char c;
    cin>>n>>w>>u>>v>>t1>>t2;
    vector <int> m(n);
    vector <vector <ship> > S(n);
    ship P;
    for(int i=0;i<n;i++)
    {
        cin>>c>>m[i];
        total+=m[i];
        for (int j=0;j<m[i];j++)
        {
            int l, p;
            (S[i]).push_back(P);
            (S[i])[j].dir=c;
            cin>>l>>p;
            (S[i])[j].length=l;
            (S[i])[j].pos=p;
        }
    }
    total*=2;
    vector <point> A(total);

    int count=0;
    for(int i=0;i<n;i++)
    {
        for (int j=0;j<m[i];j++)
        {
            double left, right;
            if((S[i])[j].dir=='E')
            {
                left=(1.0)*(-(S[i])[j].pos*(1.0)/u-(1.0)*(i+1)*w/v);
                right=(1.0)*((S[i])[j].length*(1.0)/u-(S[i])[j].pos*(1.0)/u-(1.0)*i*w/v);
            }
            else
            {
                left=(1.0)*((S[i])[j].pos*(1.0)/u-(1.0)*(i+1)*w/v);
                right=(1.0)*((S[i])[j].length*(1.0)/u+(S[i])[j].pos*(1.0)/u-(1.0)*i*w/v);
            }
            A[count].val=left;
            A[count].side='l';
            count++;
            A[count].val=right;
            A[count].side='r';
            count++;
        }
    }

    sort(A.begin(),A.end(),myfunction);
    vector <int> B(total,0);
    for(count=0;count<total;count++)
    {
        if(count>0)
        {
            if(A[count].side=='l')
            {
                B[count]=B[count-1]+1;
            }
            else
            {
                B[count]=B[count-1]-1;
            }
        }
        else
        {
            B[count]=1;
        }
    }

    double temp=0.0, max=0.0;
    for(count=0;count<total;count++)
    {
        if(B[count]==0)
        {
            if(A[count].val>t1 && A[count+1].val<t2)
            {
                temp=(A[count+1].val-A[count].val);
            }
            else if (A[count].val>t1 && A[count+1].val>=t2)
            {
                temp=(t2-A[count].val);
            }
            else if (A[count].val<=t1 && A[count+1].val<t2)
            {
                temp=(A[count+1].val-t1);
            }
            else if (A[count].val<=t1 && A[count+1].val>=t2)
            {
                temp=(1.0)*(t2-t1);
            }
            else
            {
                temp=0;
            }
            if (temp>max)
            {
                max=temp;
            }
        }
    }
    printf("%0.8f\n", max);
    //cout<<(S[1])[1].pos;
    return 0;
}
