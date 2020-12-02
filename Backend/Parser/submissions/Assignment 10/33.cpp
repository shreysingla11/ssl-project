#include<iostream>
#include<vector>
#include<map>
using namespace std;
//class tree
//{
//public:
//    vector<int> a;
//    tree *left;
//    tree *right;
//    tree()
//    {
//        left=NULL;
//        right=NULL;
//    }
//};
class distinct
{
public:
    //vector<int> b;
    vector<int> l;
    int n;
    vector<vector<int> >first;
    vector<vector<int> >second;
    distinct(vector<int> &a)
    {
        l.resize(a.size());
        n=a.size();
        map<int,int> re;
        for(int i=0; i<n; i++)
        {
            if(re.count(a[i])>0)
            {
                l[i]=re[a[i]];
                re[a[i]]=i;
            }
            else
            {
                l[i]=-1;
                re[a[i]]=i;
            }
        }
        re.clear();
        vector<int> f(n,0);
        vector<int> s(n,0);
        int num=1;
        int x=n;

        while(x!=1)
        {
            vector<int> intervals(num,0);
            vector<int> intervalsl(num,0);
            vector<int> intervalsr(num,0);

            for(int j=0; j<n; j++)
            {
                if(l[j]==-1)
                {
                    f[j]=0;
                    s[j]=0;
                    continue;
                }
                int k=l[j]*num/n;
                int test=((k*n)/num)+n/(num*2);
                if(l[j]>=test)
                {
                    intervals[k]++;
                    intervalsl[k]=j;
                    s[j]=intervalsr[k];
                }
                else
                {
                    intervalsr[k]=j;
                    s[j]=intervalsl[k];
                }
                f[j]=intervals[k];
            }
            x=x/2;
            num*=2;
            first.push_back(f);
            second.push_back(s);
        }
    }
    int num_distinct(int i,int j)
    {
        int result=0;
        int level=1;
        int levexp=1;
        int mid=n/2;
        //int x=0,y=n-1;
        while(levexp<n)
        {
            if(i<(n/2))
            {
                if(l[j]!=-1)
                {
                    result+=first[level-1][j];
                }
                if(l[j]>=mid)
                {
                    j=second[level-1][j];
                }
                mid=mid-(n/levexp*2);
            }
            else
            {
                if(l[j]<mid)
                {
                    j=second[level-1][j];
                }
                j=second[level-1][j];
            }
            level++;
            levexp*=2;
        }
        return j-i+1-result;
    }
};
//int main(){
//vector<int> x;
//x.push_back(1);
//x.push_back(2);
//x.push_back(1);
//x.push_back(3);
//x.push_back(2);
//x.push_back(1);
//x.push_back(1);
//x.push_back(3);
//distinct temp(x);
//temp.print();
//}
