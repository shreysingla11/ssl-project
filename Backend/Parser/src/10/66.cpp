#include<bits/stdc++.h>
using namespace std;
vector<int> s1;
bool compare(int i, int j)
    {   if(s1[i]<s1[j])
            return true;
        else if(s1[i]==s1[j])
            return i<j;
        else
            return false;
    }
struct Node
{
    vector<int> arry;
    vector<int> index;
};

class distinct
{  vector<int> l;

   public:

    distinct( vector<int> seq)
    {   vector<int> temp_index;
        int n=0;
        for(n=0;n<seq.size();n++)
        {   s1.push_back(seq[n]);
            temp_index.push_back(n);
        }
        sort(temp_index.begin(),temp_index.end(),compare);
        l.resize(n,-1);
        l[temp_index[0]]=-1;
        for(int j=1;j<n;j++)
        {   if(seq[temp_index[j-1]]==seq[temp_index[j]])
                l[temp_index[j]]=temp_index[j-1];
        }
       /* for(int j=0;j<n;j++)
        { cout<<l[j];
        }*/

        int c=0;

        int sizeT=log2(n);
        vector<Node > Tree(sizeT);
        for(int i=0;i<sizeT;i++)
        {
           /* for(int j=0;j<n;j++)
            {
                if(l[j]>=k*n/pow(2,i))
                {
                }
             }*/
            vector<int> vk(n,0);
            int ll=-1,rr=-1;
            for(int j=0;j<n;j++)
            {
                int k=l[j]*(int(pow(2,i))/n);
                if(l[j]>=k*n/int(pow(2,i)) + n/int(pow(2,i+1)) && l[j]<(k+1)*n/int(pow(2,i)))
                    vk[k]++;
                (Tree[i].arry).push_back(vk[k]);

                if(k*n/int(pow(2,i)) + n/int(pow(2,i+1))<=l[j] && l[j]<(k+1)*n/int(pow(2,i)))
                {   (Tree[i].index).push_back(ll);
                    rr=j;
                }
                else
                {  (Tree[i].index).push_back(rr);
                    ll=j;
                }
            }
        }
       /* for(int i=0;i<n;i++)
        {
            cout<<Tree[0].arry[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<Tree[0].index[i]<<" ";
        }
        cout<<endl;*/
    }
    int num_distinct(int i, int j)
    {  ;
    }
};
/*
int main()
{   vector<int> s;
    s.resize(8);
    s[0]=1;
    s[1]=2;
    s[2]=1;
    s[3]=3;
    s[4]=2;
    s[5]=1;
    s[6]=1;
    s[7]=3;

    distinct d(s);

}

*/
