#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

/*
class distinct
{
    vector<int> l;
    public:
    distinct(vector<int> v1)
    {
        int v1size = v1.size();
        for(int i=0; i<v1size; i++)
        {
            l.push_back(-1);
        }
        for(int i=0; i<v1size; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(v1[j]==v1[i])
                    l[i]=j;
            }
        }
    }

    int num_distinct(int i, int j)
    {
        int k=0;
        for(int a=i; a<=j; a++)
        {
            if(l[a]>=i)
                k++;
        }
        return (j-i+1-k);
    }
};
*/
struct elementIndex
{
    int val, index;
};

bool myfunction (elementIndex i,elementIndex j)
{
    if(i.val != j.val)
        return (i.val<j.val);
    else
        return (i.index<i.index);
}

class distinct
{
    vector<int> l;
    public:
    distinct(vector<int> v1)
    {
        int v1size = v1.size();
        for(int i=0; i<v1size; i++)
        {
            l.push_back(-1);
        }
        vector<elementIndex> v(v1size);
        for(int i=0; i<v1size; i++)
        {
            v[i].val = v1[i];
            v[i].index = i;
        }

        sort (v.begin(), v.end(), myfunction);
        for(int i=1; i<v1size; i++)
        {
            if(v[i].val == v[i-1].val)
            {
                l[v[i].index] = v[i-1].index;
            }
        }
    }

    int num_distinct(int i, int j)
    {
        int k=0;
        for(int a=i; a<=j; a++)
        {
            if(l[a]>=i)
                k++;
        }
        return (j-i+1-k);
    }
};

/*
struct elementIndex
{
    int val, index;
};

bool myfunction (elementIndex i,elementIndex j)
{
    if(i.val != j.val)
        return (i.val<j.val);
    else
        return (i.index<i.index);
}

class distinct
{
    vector<int> l;
    vector<vector<int> > level;
    public:
    distinct(vector<int> v1)
    {
        int v1size = v1.size();
        for(int i=0; i<v1size; i++)
        {
            l.push_back(-1);
        }
        vector<elementIndex> v(v1size);
        for(int i=0; i<v1size; i++)
        {
            v[i].val = v1[i];
            v[i].index = i;
        }

        sort (v.begin(), v.end(), myfunction);
        for(int i=1; i<v1size; i++)
        {
            if(v[i].val == v[i-1].val)
            {
                l[v[i].index] = v[i-1].index;
            }
        }
        for(int i=0; i<(v1size/2); i++)
        {
            vector<int> temp;
            temp.push_back(0);
        }
        level.push_back(temp);
        for(int i=(v1size/2); i<v1size; i++)
        {
            if(l[0]>=(v1size/2))
                level[0].push_back()
        }
    }

    int num_distinct(int i, int j)
    {
        int k=0;
        for(int a=i; a<=j; a++)
        {
            if(l[a]>=i)
                k++;
        }
        return (j-i+1-k);
    }
};
*/
/*
int main()
{
    vector<int> v;
    int i,j;
    i=3;j=7;
    v.push_back(1);
    v.push_back(2);
    v.push_back(1);
    v.push_back(3);
    v.push_back(2);
    v.push_back(1);
    v.push_back(1);
    v.push_back(3);
    distinct d = distinct(v);
    cout<<d.num_distinct(i,j);
    return 0;
}

*/
