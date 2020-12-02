#include<iostream>
// #include<cstdio.h>
#include<algorithm>
#include<map>
#include<vector>
#include<set>
#include<cmath>
using namespace std;
struct sequence{
    int value;
    int index;
};
struct nodes{
    vector<int> arr1;
    vector<int> arr2;
};
bool compare(sequence x,sequence y){
    if(x.value==y.value)
        return x.index<y.index;
    else
        return x.value<y.value;
}
class distinct{
public:
    
    distinct(){}
    distinct(vector<int> a)
    {
        vector<int> l(a.size());
        vector<sequence> s(a.size());
        int n=a.size();
        for (int i = 0; i < a.size(); ++i)
        {
            s[i].value=a[i];
            s[i].index=i;
        }
        sort(s.begin(),s.end(),compare);
        for (int i = 0; i < a.size(); ++i)
        {
            if(i>0&&s[i].value==s[i-1].value){
                l[s[i].index]=s[i-1].index;
            }
            else
                l[s[i].index]=-1;
            
        }
        for (int i = 0; i < a.size(); ++i)
        {
            cout<<l[i]<<" ";
        }
        int counts=0;
        vector<nodes> tree(log2(n));
        for (int i = 0; i < n; ++i)
        {   
            if(l[i]>=n/2){
                counts++;
                tree[0].arr1.push_back(counts);
            }
            else
                tree[0].arr1.push_back(counts);
        }
        for (int i = 0; i < n; ++i)
        { 
            cout<<tree[0].arr1[i]<<endl;
        }
        
    }
    int num_distinct(int i,int j){

    }
};
