#include <iostream>;
#include <list>;
#include <vector>;
using namespace std;
class counter
{
    int n;
    vector<int> vec;
    vector<list<list<int> >::iterator> ve;
    vector<list<int>::iterator> v;
    list<list<int> > lis;
public:
    counter(int a)
    {
        n = a;
        list<int> li;
        for(int i=0; i<n; i++)
        {
            vec.push_back(0);
            li.push_back(i);
        }

        lis.push_back(li);
        list<list<int> >::iterator u = lis.begin();
        list<int>::iterator t=(*u).begin();
        for(int i=0; i<n; i++)
        {
            ve.push_back(u);
            v.push_back(t);
            t++;
        }

    }
    void increment(int a)
    {
        list<list<int> >::iterator u = ve[a];
        u++;
        if(!(u==lis.end()))
        {
            if(vec[*((*u).begin())]==vec[a]+1)
            {
                (u)->push_back(a);
                u--;
                u->erase(v[a]);
                u++;
                ve[a] = u;
                v[a] = (*u).end();
                v[a]--;
                vec[a]++;
                u--;
                if(u->empty())
                {
                    lis.erase(u);
                }
            }
            else
            {
                list<int> temp;
                temp.push_back(a);
                u = lis.insert(u,temp);
                u--;
                (*u).erase(v[a]);
                u++;
                ve[a] = u;
                v[a] = (*u).begin();
                vec[a]++;
                u--;
                if(u->empty())
                {
                    lis.erase(u);
                }
            }
        }
        else
        {
            u--;
            u->erase(v[a]);
            if(u->size()==0)
            {
                lis.erase(u);
            }
            list<int> temp;
            temp.push_back(a);
            u = lis.insert(lis.end(),temp);
            ve[a] = u;
            v[a] = (*u).begin();
            vec[a]++;
        }
    }
    void decrement(int a)
    {
        list<list<int> >::iterator u = ve[a];
        if(!(u==lis.begin()))
        {
            u--;

            if(vec[*((*u).begin())]==vec[a]-1)
            {
                (*u).push_back(a);
                u++;
                (*u).erase(v[a]);
                u--;
                ve[a] = u;
                v[a] = (*u).end();
                v[a]--;
                vec[a]--;
                u++;
                if(u->empty())
                {
                    lis.erase(u);
                }
            }
            else
            {
                u++;
                list<int> temp;
                temp.push_back(a);
                u = lis.insert(u,temp);
                u++;
                (*u).erase(v[a]);
                u--;
                ve[a] = u;
                v[a] = (*u).begin();
                vec[a]--;
                u++;
                if(u->empty())
                {
                    lis.erase(u);
                }

            }
        }
        else
        {
            list<int> temp;
            temp.push_back(a);
            u = lis.insert(u,temp);
            u++;
            (*u).erase(v[a]);
            u--;
            ve[a] = u;
            v[a] = (*u).begin();
            vec[a]--;
            u++;
            if(u->empty())
            {
                lis.erase(u);
            }
        }


    }
    void reset(int a)
    {
        if(vec[*((*(lis.begin())).begin())]==0)
        {
            list<list<int> >::iterator u = lis.begin();
            (*u).push_back(a);
            (*ve[a]).erase(v[a]);
            ve[a] = u;
            v[a] = (*u).end();
            v[a]--;
            vec[a]=0;
        }
        else
        {
            list<int> temp;
            temp.push_back(a);
            lis.insert(lis.begin(),temp);
            (*ve[a]).erase(v[a]);
            ve[a] = lis.begin();
            v[a] = (*(lis.begin())).begin();
            vec[a]=0;
        }

    }
    int count(int a)
    {
        return vec[a];
    }
    int findMax()
    {
        list<list<int> >::iterator k  = --lis.end();
        return vec[*((*k).begin())];
    }
    int numMax()
    {
        return  (*(--lis.end())).size();
    }
    void printMax()
    {
        list<list<int> >::iterator k  = lis.end();
        k--;
        list<int>::iterator l = (*k).begin();
        while(!(l==(*k).end()))
        {
            cout<<*l<<" ";
            l++;
        }
    }
};







