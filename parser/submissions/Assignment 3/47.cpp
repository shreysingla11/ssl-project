#include <iostream>
#include <list>
#include <limits>
using namespace std;
int inf;


int func (list<int> &L, list<int> &a, list<int> &b,list<int>::iterator i, list<int>::iterator j)
{
    int f;
    if (i==a.begin())
    {
        if (j==b.begin())
        {
            if (*i==*j)
            {
                L.push_front(1);
                return 1;
            }
            else
            {
                L.push_front(inf);
                cout << "inf";
                return inf;
            }

        }
        else
        {
            L.push_front(inf);
            return inf;
        }
    }
    else
    {

        if (j==b.begin())
        {
            if (*i==*j)
            {
                L.push_front(1);
                return 1;
            }
            else
            {
                i--;
                f = 1 + func(L,a,b,i,j);
                L.push_front(f);
                cout << "Y" << endl;
                return f;
            }
        }
        else
        {
            if (*i==*j)
            {
                i--;
                j--;
                f = 1 + func(L,a,b,i,j);
                L.push_front(f);
                return f;cout << "X" << endl;

            }
            else
            {
                i--;
                f = 1 + func(L,a,b,i,j);

                L.push_front(f);
                return f;

            }
        }
    }
}

int main()
{
    int n,m,k,val;
    cin >> n >> m;
    inf=n+1;
    list<int> a, b, L;
    list<int>::iterator i,j;

    a.resize(n);
    b.resize(m);
    L.resize(n);

    for (k=1;k<=n;k++)
    {
        cin >> val;
        a.push_back(val);
    }

    for (k=1;k<=m;k++)
    {
        cin >> val;
        b.push_back(val);
    }

    i=a.begin();
    j=b.begin();

    int minL, minI, minIt;
    func(L,a,b,i,j);
    cout << "func" << endl;
    list<int>::iterator It;
    minIt=1;
    minL=inf;
    for (It=L.begin(),minIt=1;It!=L.end();It++,minIt++)
    {
        if (*It<minL)
        {
            minL=*It;
            minI=minIt;
        }
    }

    if (minL>=inf)
        cout << "\n" << "infinity  " << minI;
    else
        cout << "\n" << minL << "  " << minI;
    return 0;
}
