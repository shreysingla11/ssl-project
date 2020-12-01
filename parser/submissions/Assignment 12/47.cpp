#include <iostream>
#include <stack>
#include <vector>
#include <cstdio>
using namespace std;

class frnd
{
public:
    int t;
    int f;
    vector<int> predecessor;
    int g;
};

int main()
{
    int n,min=0;
    //cin>>n;
    scanf("%d",&n);
    int max= n;

    stack<int> minstack;
    stack<int> maxstack;

    frnd * A;
    A = new frnd[n];

    for (int i=0; i<n; i++)
    {
        A[i].g=0;
        scanf("%d",&(A[i].t));
        //cin>>A[i].t;
        //cin>>A[i].f;
        scanf("%d",&(A[i].f));

        if(A[i].t>A[i].f)
        {
            maxstack.push(i);
            max--;
            A[i].g=-1;
        }

        if(A[i].t==0)
        {
            minstack.push(i);
            min++;
            A[i].g=1;
        }

        for(int j=0; j<A[i].f; j++)
        {
            int k;
            scanf("%d",&k);
            A[k].predecessor.push_back(i);
        }
    }

    while(!minstack.empty())
    {
        int top = minstack.top();
        minstack.pop();
        int l=A[top].predecessor.size();
        for(int i=0; i<l; i++)
        {
            A[A[top].predecessor[i]].t-=1;
            A[A[top].predecessor[i]].f-=1;
            if(A[A[top].predecessor[i]].t==0&&A[A[top].predecessor[i]].g==0)
            {
                A[A[top].predecessor[i]].g=1;
                minstack.push(A[top].predecessor[i]);
                min++;
            }
        }
    }

    while(!maxstack.empty())
    {
        int top = maxstack.top();
        maxstack.pop();
        int l=A[top].predecessor.size();
        for(int i=0; i<l; i++)
        {
            A[A[top].predecessor[i]].f-=1;
            if(A[A[top].predecessor[i]].t>A[A[top].predecessor[i]].f)
            {
                if(A[A[top].predecessor[i]].g==0)
                {
                    A[A[top].predecessor[i]].g=-1;
                    maxstack.push(A[top].predecessor[i]);
                    max--;
                }
            }
        }
    }


    //cout<<min<<" "<<max<<endl;
    printf("%d %d\n",min,max);

    return 0;
}
