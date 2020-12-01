#include <iostream>
#include <list>
#include <vector>
using namespace std;

struct node
{
    int th,fr;
    int g,ng;
    list<int> fl;
    node(int ith, int ifr)
    {
        th=ith;
        fr=ifr;
        g=0;
        ng=0;
    }
};

int main()
{
    vector<node*> N;
    list<int> DG;
    list<int> DNG;
    list<int> NC;
    list<int>::iterator it,it2,itt;
    int n,th,fr,inp_fr;
    int def_g=0,def_ng=0;

    cin>>n;
    N.resize(n);

    for(int i=0;i<n;i++)
    {
        cin>>th>>fr;
        N[i]=new node(th,fr);
        for(int j=0;j<fr;j++)
        {
            cin>>inp_fr;
            (N[i]->fl).push_front(inp_fr);
        }
    }
    for(int i=0;i<n;i++)
    {
        if(N[i]->th==0){DG.push_front(i);continue;}
        if(N[i]->th > N[i]->fr){DNG.push_front(i);continue;}
        else NC.push_front(i);
    }
    while(!DG.empty())
    {
        int cn=*(DG.begin());
        DG.pop_front();
        def_g++;

        for(it=NC.begin();it!=NC.end();++it)
        {
            bool b=0;
            for(it2=((N[*it])->fl).begin();it2!=((N[*it])->fl).end();it2++)
            {
                if(*it2==cn){b=1;break;}
            }

            if(b)
            {
                ((N[*it])->g)++;
                if( (N[*it])->g >= (N[*it])->th )
                {
                    DG.push_front(*it);
                    itt=it;
                    --it;
                    NC.erase(itt);
                }
            }
        }
    }
    while(!DNG.empty())
    {
        int cn=*(DNG.begin());
        DNG.pop_front();
        def_ng++;

        for(it=NC.begin();it!=NC.end();++it)
        {
            bool b=0;
            for(it2=((N[*it])->fl).begin();it2!=((N[*it])->fl).end();it2++)
            {
                if(*it2==cn){b=1;break;}
            }

            if(b)
            {
                ((N[*it])->ng)++;
                if( ( (N[*it])->fr - (N[*it])->ng ) < (N[*it])->th )
                {
                    DNG.push_front(*it);
                    itt=it;
                    --it;
                    NC.erase(itt);
                }
            }
        }
    }
    cout<<def_g<<" "<<n-def_ng;
    return 0;
}
