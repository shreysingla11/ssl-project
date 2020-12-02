#include<iostream>
#include<vector>

using namespace std;

class distinct
{
public:
    vector<int> a;
    vector<int> l;
    distinct(vector<int> a)
    {
        for(int c=0; c<a.size(); c++)
        {
            l.push_back(-1);
        }
        for(int i=(a.size())-1; i>=0; i--)
        {
            for(int j=i-1; j>=0; j--)
            {
                if(a[j]==a[i])
                {
                    l[i]=j;
                    break;
                }
            }
        }
    }
    int num_distinct(int first,int last)
    {
        int k=0,p1=first,r;
        for(p1; p1<=last; p1++)
        {
            if(l[p1]>=first)k++;
        }
        r=last-first+1-k;
        return r;
    }
};
/*
int main()
{
    int n;
    cin>>n;
    vector<int> input;
    for(int i=0; i<n; i++)
    {
        int temp;
        cin>>temp;
        input.push_back(temp);
    }
    distinct p(input);
    for(int i=0; i<n; i++)
    {
        cout<<p.l[i]<<" ";
    }
    cout<<endl;
    int input1,input2,ans1;
    cin>>input1;
    cin>>input2;
    ans1=p.num_distinct(input1,input2);
    cout<<ans1<<endl;
    return 0;
}
*/