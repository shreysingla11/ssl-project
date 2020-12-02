#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

void Msort (vector <vector <double> > l, vector <vector <double> > l2, int i, int j)
{
    vector <double> v1,v2;
    int mid = (i+j)/2;
    if (i==j)
    {
        return ;
    }
    else
    {
        Msort(l,l2,i,mid);
        Msort(l,l2,mid+1,j);

        int x=i,y=mid+1,z=i;
        for (;z<=j;z++)
        {
            if (x==mid+1&&y==j+1)
            {
                return;
            }
            else if (x==mid+1)
            {
                l2[z]=l[y];
                y++;
            }
            else if (y==j+1)
            {
                l2[z]=l[x];
                x++;
            }
            else if (l[x][0]<=l[y][0])
            {
                l2[z] = l[x];
                x++;
            }
            else if (l[x][0]>l[y][0])
            {
                l2[z] = l[y];
                y++;
            }
        }
    }
}
int main()
{
    int n,w,u,v,t1,t2;
    cin >> n >> w >> u >> v >> t1 >> t2;
    // n : no. of lanes
    // w : width of lanes
    // u : speed of ships
    // v : speed of ferry
    // t1 : earliest start time
    // t2 : latest start time
    int i,j;
    char *dir = new char [n]; // E or W
    int *m = new int [n]; // no. of ships in a lane
    int **l = new int *[n]; // length of a ship
    int **p = new int *[n]; // position of a ship
    int siz=0;
    vector <vector <double> > t;

    for (i=1;i<=n;i++)
    {
        cin >> dir[i-1] >> m[i-1];
        l[i-1] = new int [m[i-1]];
        p[i-1] = new int [m[i-1]];
        for (j=1;j<=m[i-1];j++)
        {
            cin >> l[i-1][j-1] >> p[i-1][j-1];
            double strt=-1,en=-1;
            if (dir[i-1]=='E')
            {
                if ((p[i-1][j-1]<=l[i-1][j-1])&&(p[i-1][j-1]>=0))
                {
                    strt = 0;
                    en = abs((p[i-1][j-1] - l[i-1][j-1])/u);
                    en-= w*(i-1)/v;
                }
                else if (p[i-1][j-1]<0)
                {
                    strt = abs ((-p[i-1][j-1])/u);
                    en = abs ((l[i-1][j-1]-p[i-1][j-1])/u);
                    strt-= w*(i-1)/v;
                    en-= w*(i-1)/v;
                }
                if (strt<0)
                    strt=0;
                if (en<0)
                    en=0;
            }
            else if (dir[i-1]=='W')
            {
                if ((p[i-1][j-1]>=-l[i-1][j-1])&&(p[i-1][j-1]<=0))
                {
                    strt = 0;
                    en = abs((p[i-1][j-1] + l[i-1][j-1])/u);
                    en-= w*(i-1)/v;
                }
                else if (p[i-1][j-1]>0)
                {
                    strt = ((p[i-1][j-1])/u);
                    en = abs ((l[i-1][j-1]-p[i-1][j-1])/u);
                    strt-= w*(i-1)/v;
                    en-= w*(i-1)/v;
                }
                if (strt<0)
                    strt=0;
                if (en<0)
                    en=0;
            }
            vector<double> temp;
            if (strt==-1||en==-1)
                continue;
            temp.push_back(strt);
            temp.push_back(en);
            t.push_back(temp);
            siz++;
        }
    }
    vector <double> temp;
    temp.clear();
    vector <vector <double> > tp;
    tp.resize(siz);
    Msort(t,tp,0,siz-1);
    t=tp;
    tp.clear();
    vector <double>::iterator ts,te,sts,ste;
    vector <vector <double> >::iterator lli;
    lli = t.begin();
    ts = (*lli).begin();
    te = ts;
    te++;
    vector <vector <double> > s;
    vector <vector <double> >::iterator si;
    vector <double> tmp;
    tmp.push_back(*ts);
    tmp.push_back(*te);
    s.push_back(tmp);
    si=s.begin();
    sts = (*si).begin();
    ste=sts;
    ste++;
    lli++;
    for (;lli!=t.end();lli++)
    {
        tmp.clear();
        ts = (*lli).begin();
        te = ts;
        te++;
        sts = (*si).begin();
        ste = sts;
        ste++;
        if ((*ts)<=(*ste))
        {
            if ((*te)<=(*ste))
            {
                continue;
            }
            else
            {
                (*ste)=(*te);
            }
        }
        else
        {
            tmp.push_back(*ts);
            tmp.push_back(*te);
            s.push_back(tmp);
            si++;
        }
    }
    tmp.clear();
    t.clear();
    si = s.begin();
    sts = (*si).begin();
    ste = sts;
    ste++;
    if ((*sts)==0)
    {
        tmp.push_back(*ste);
        si++;
        sts = (*si).begin();
        ste = sts;
        ste++;
        tmp.push_back(*sts);
    }
    else
    {
        tmp.push_back(0);
        tmp.push_back(*sts);
    }
    t.push_back(tmp);
    lli=t.begin();
    while(true)
    {
        tmp.push_back(*ste);
        si++;
        if (si==s.end())
            break;
        sts = (*si).begin();
        ste = sts;
        ste++;
        tmp.push_back(*sts);
        t.push_back(tmp);
    }
    lli=t.begin();
    int k=0;
    double d;
    for (;lli!=t.end();lli++)
    {
        ts = (*lli).begin();
        te = ts;
        te++;
        if ((*ts>=t1)&&(*ts<=t2))
        {
            if (k==0)
            {
                d = (*te) - (*ts);
                k++;
            }
            double h = (*te) - (*ts);
            if (h>d)
            {
                d=h;
            }
        }
    }
    cout << setprecision(8) << fixed << d;
    return 0;
}
