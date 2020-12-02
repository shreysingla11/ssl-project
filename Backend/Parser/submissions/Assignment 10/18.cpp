#include<iostream>
#include<vector>
#include <cstring>
#include <cassert>
using namespace std;
const long int nm = 1e6;
const long int sm = 2e7;
vector <int> root(nm);
vector <int> root2(nm);
vector <int> lch(sm);
vector <int> rch(sm);
vector <int> sum2(sm);
int c;
int crnode (int val)
{
    if(c < sm)
    {
    sum2[c] = val;
    return c++;
    }
}
int crnode (int l, int r, bool s)
{
    lch[c] = l;
    rch[c] = r;
    return crnode(s ? sum2[l] + sum2[r] : max(sum2[l], sum2[r]));
}

int buildtree (int b, int e)
{
    if (b == e)
        return crnode(0);

    int m = (b + e) / 2;
    return crnode(buildtree(b, m), buildtree(m + 1, e), false);
}

int update2 (int v, int b, int e, int p, int val, bool s)
{
    if (b > p || e < p)
        return v;

    if (b == e)
        return crnode(val);

    int m = (b + e) / 2;
    int l = update2(lch[v], b, m, p, val, s),
        r = update2(rch[v], m + 1, e, p, val, s);

    return crnode(l, r, s);
}

int query (int v, int b, int e, int l, int r, bool s)
{
    if (e < l || b > r)
        return 0;

    if (l <= b && e <= r)
        return sum2[v];

    int m = (b + e) / 2;

    if (s)
        return  query(lch[v], b, m, l, r, s) + query(rch[v], m + 1, e, l, r, s);
    else
        return max(query(lch[v], b, m, l, r, s), query(rch[v], m + 1, e, l, r, s));
}
int n, a[nm], next_pos[nm], forw[nm], q, l, r, last[nm];
int pos[nm];

void update (int r, int a, int b)
{
    root2[a] = update2(r, 0, nm - 1, a, b, 0);
}

int dquery (int l, int r)
{
    return query(root[r + 1], 0, nm - 1, l + 1, r + 1, 1);
}
extern class distinct
{
public:
    int n;
    distinct(vector <int> v)
    {
        n=v.size();
        for(int i=0;i<n;i++)
        {
            a[i]=v[i];
        }
    }
    int num_distinct(int i,int j)
    {
    root[0] = buildtree(0, nm- 1);
    root2[n] = buildtree(0, nm- 1);
    for (int i = 1; i <= n; ++i)
    {
        int r = root[i - 1];
        int p = a[i - 1];

        if (pos[p])
            r = update2(r, 0,nm - 1, pos[p], 0, 1);

        root[i] = update2(r, 0,nm - 1, i, 1, 1);
        pos[p] = i;
    }

    memset(forw, -1, sizeof forw);

    for (int i = n - 1; i >= 0; --i)
    {
        if (forw[a[i]] == -1)
        {
            update(root2[i + 1], i, nm - 2);
            next_pos[i] =nm - 2;
            last[i] = nm - 2;
        }
        else
        {
            int idx = forw[a[i]];
            int rot = update2(root2[i + 1], 0, nm - 1, idx, 0, 0);
            int r = next_pos[idx];
            next_pos[i] = idx;

            if (r ==nm - 2 || r - idx != idx - i)
            {
                update(rot, i, r);
                last[i] = r;
            }
            else
            {
                update(rot, i, last[idx]);
                last[i] = last[idx];
            }
        }

        forw[a[i]] = i;
    }
        int ans = dquery(i, j);
        int c = query(root2[i], 0, n - 1, l, j, 0);
        ans += c <= j;
        return ans;
    }

};

