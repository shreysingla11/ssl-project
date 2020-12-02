#include<iostream>
#include<vector>
#include <algorithm>
#include<cstdio>
using namespace std;
bool myfunc(const vector<double> &a, const vector<double> &b)
{
    return(a[0]<b[0]);
}
int main()
{
    int n, w, u, v, t1, t2;
    cin>>n>>w>>u>>v>>t1>>t2;
    vector<vector<double> > interval;
    for(int i=0; i<n; i++)
    {
        char d;
        cin>>d;
        int m;
        cin>>m;

        for(int j=0; j<m; j++)
        {
            int l,p;
            cin>>l>>p;
            double s,e;
            double temp = (i)*(w*1.0)/v;
            if(d == 'E')
            {
                p=-1*p;
                e = (p+l)*1.0/u-temp;
                s = (p*1.0/u)-temp-(w*1.0)/v;
                if(s<t1)
                {

                    if(e<t1)
                    {
                        e=t1;
                    }
                    s=t1;
                }

                if(e>t2)
                {

                    if(s>t2)
                    {
                        s=t2;
                    }
                    e=t2;
                }
            }
            else
            {
                s = (p*1.0/u)-temp-(w*1.0)/v;
                e = (p+l)*1.0/u-temp;
                if(s<t1)
                {
                    if(e<t1)
                    {
                        e=t1;
                    }
                    s=t1;
                }

                if(e>t2)
                {
                    if(s>t2)
                    {
                        s=t2;
                    }
                    e=t2;
                }
            }
            vector<double> temp2;


            temp2.push_back(s);
            temp2.push_back(e);

            interval.push_back(temp2);
        }
        if(interval.empty())
        {
             vector<double> temp2;
             temp2.push_back(t1);
             temp2.push_back(t1);
             interval.push_back(temp2);
        }

    }
    sort(interval.begin(),interval.end(),myfunc);
    int len = interval.size();
    double max =0;
    if(max<interval[0][0]-t1)
    {
        max=interval[0][0]-t1;
    }
    for(int i=0; i<len-1; i++ )
    {
        double k = interval[i+1][0]-interval[i][1];
        if (max<k)
        {
            max=k;
        }

    }

    if(max<t2-interval[len-1][1])
    {
        max=t2-interval[len-1][1];
    }

    printf("%0.8f\n",max);
}

