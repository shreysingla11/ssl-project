#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct b
{
    int val;
    int ind;
};
bool myfunction(b i,b j)
{
    if(i.val==j.val)
    {
        if(i.ind<j.ind)
        {
            return true;
        }
        return false;
    }
    if(i.val>j.val)
    {
        return true;
    }
    return false;
}
class distinct
{
public:
    vector<b>seq;
    vector<int>l;
    b a;
    distinct(vector<int>v)
    {
        int n=v.size();
        for(int i=0; i<n; i++)
        {
            a.val=v[i];
            a.ind=i;
            seq.push_back(a);
        }
        sort(seq.begin(),seq.end(),myfunction);
        l.resize(n,-1);
        int j=1;
        while(j<n)
        {
            if(seq[j].val==seq[j-1].val)
            {
                l[seq[j].ind]=seq[j-1].ind;
            }
            j++;
        }
        for(j=0; j<n; j++)
        {
            cout<<l[j]<<' ';
        }
    }

    int num_distinct(int num1,int num2)
    {int count=0;
        for(int i=num1+1;i<=num2;i++)
            {if(l[i]>=num1){count++;}}
            return (num2-num1-count)+1;
    };

};
/*int main()
{
    vector<int>v(8);
    for(int i=0; i<8; i++)
    {
        cin>>v[i];
    }
    distinct lol(v);
    int n1,n2;
    cin>>n1>>n2;
    cout<<lol.num_distinct(n1,n2);
    return 0;
}*/
