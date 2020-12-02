#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
struct in
{
    int val;
    int pos;
};
struct nod
{
    vector<int> ar;
    vector<int> ind;
};
bool compare(in a,in b)
{
    if(a.val<b.val)
        return true;
    else if (a.val>b.val)
        return false;
    else
    {
        if(a.pos<b.pos)
            return true;
        else
            return false;
    }

}
class distinct
{
    public:
    vector<int> l;
    distinct(vector<int> a)
    {
       vector<in> temp; in t;
       for(int i=0;i<a.size();i++)
       {
            t.val = a[i];
            t.pos = i;
            temp.push_back(t);
            l.push_back(-1);
       }
       sort(temp.begin(),temp.end(),compare);
       for(int i=0;i<a.size()-1;i++)
       {
            if(temp[i].val==temp[i+1].val)
                l[temp[i+1].pos]=temp[i].pos;
       }
//       for(int i=0;i<a.size();i++)
//       {
//            printf("%d ", l[i]);
//        }
//        cout<<endl;
        int n=a.size();
        vector<nod> seg_tree(int(log2(a.size())));
        int flag=0;
        int log_2=log2(a.size());
        for(int i=0;i<log_2;i++)
        {
            //vector<int> seg_tree_temp;
            vector<int> k_1(a.size(),0);
            int l_l=-1,r_r=-1;
            for(int j=0;j<a.size();j++)
            {
                int z=l[j]*(int(pow(2,i))/n);
                if(l[j]>=z*n/int(pow(2,i)) + n/int(pow(2,i+1)) && l[j]<(z+1)*n/int(pow(2,i)))
                    k_1[z]++;
                (seg_tree[i].ar).push_back(k_1[z]);

                if(z*n/int(pow(2,i)) + n/int(pow(2,i+1))<=l[j] && l[j]<(z+1)*n/int(pow(2,i)))
                {
                    (seg_tree[i].ind).push_back(l_l);
                    r_r=j;
                }
                else
                {
                    (seg_tree[i].ind).push_back(r_r);
                    l_l=j;
                }
            }
        }
//        for(int i=0;i<n;i++)
//        {
//            cout<<seg_tree[1].ar[i]<<" ";
//        }
//        cout<<endl;
//        for(int i=0;i<n;i++)
//        {
//            cout<<seg_tree[1].ind[i]<<" ";
//        }
//        cout<<endl;

    }
    int num_distinct(int i,int j)
    {
        return 0;
    }


};
