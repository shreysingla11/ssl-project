#include <iostream>
#include <stack>
#include <vector>
#include <list>

using namespace std;

int main()
{
    long n;
    cin>>n;
    long inp;
    vector<vector<long> > fri(n);
    vector<long> t(n);
    vector<long> nf(n);
    vector<bool> pg(n, false);//pakka going
    vector<bool> png(n, false);//pakka not going
    vector<bool> fdone(n, false);
    vector<bool> rdone(n, false);
    vector<long> npg(n, 0);//no. of friends pakka going
    vector<long> npng(n, 0);//no. of friends pakka not going
    vector<list<long> > rev(n);
    stack<long> s1;
    stack<long> s2;
    long pgc, pngc;//count of pakka going and pakka not going
    pgc=0;pngc=0;

    for (long i=0; i<n; i++)
    {
        cin>>inp;
        t[i] = inp;
        if(t[i]==0)
        {
            pg[i] = true;
            s1.push(i);
            pgc++;
        }
        cin>>inp;
        nf[i] = inp;
        if(t[i]>nf[i])
        {
            png[i] = true;
            s2.push(i);
            pngc++;
        }
        fri[i].resize(nf[i]);
        for (long j=0; j<nf[i]; j++)
        {
            cin>>inp;
            fri[i][j] = inp;
            rev[inp].push_back(i);
        }

    }

    long t1;

    while(!s1.empty())
    {
        //cout<<"s1 is not empty";
        t1 = s1.top();
        s1.pop();
        for(list<long>::iterator it=rev[t1].begin(); it != rev[t1].end(); ++it)
        {
            npg[*it]++;
            if((npg[*it]>=t[*it])&&(pg[*it]==false))
            {
                pg[*it] = true;
                s1.push(*it);
                pgc++;
            }
        }
    }
    while(!s2.empty())
    {
        t1 = s2.top();
        s2.pop();
        for(list<long>::iterator it=rev[t1].begin(); it != rev[t1].end(); ++it)
        {
            npng[*it]++;
            if((npng[*it]>(nf[*it]-t[*it] ) )&&(png[*it]==false))
            {
                png[*it] = true;
                s2.push(*it);
                pngc++;
            }
        }
    }

    cout<<pgc<<" "<<(n-pngc);

    /*for(long i=0; i<n; i++)
    {
        for(list<long>::iterator it=rev[i].begin(); it != rev[i].end(); ++it)
        {
            cout<<*it<<" ";
        }
        cout<<endl;
    }*/
    /*
    for(long i=0; i<n; i++)
    {
        for(long j=0; j<nf[i]; j++)
        {
            cout<<fri[i][j]<<" ";
        }
        cout<<endl;
    }*/
    return 0;
}
