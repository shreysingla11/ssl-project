


class pos
{
public:
    int value;
    list<list<int> >::iterator it;
    list<int>::iterator it1;
};
class counter
{
private:
    list<list<int> > a;
    list<int> l;

    list<list<int> >::iterator it2;
    vector<pos> v;
     vector<int> p;
public:

    counter(int n)
    {
        p.resize(n,0);
        p[0]=n;
        list<int> t;
        for(int i=0; i<n; i++)
        {
            t.push_back(i);
        }
        a.push_back(t);
        v.resize(n);
        for(int i=0; i<n; i++)
        {
            v[i].it=a.begin();
            if(i==0)
            {
                v[0].it1=(*(v[0].it)).begin();
            }
            if(i>0)
            {
                v[i].it1=v[i-1].it1;
                v[i].it1++;
            }
            v[i].value=0;

        }
        it2=a.begin();
    }


    void increment(int i)
    {
        (*(v[i].it)).erase(v[i].it1);
        if(p[v[i].value]==1)
        {
            it2=v[i].it;
            it2++;
            a.erase(v[i].it);

            p[v[i].value]--;
            p.push_back(0);
        }
        else
        {
            it2=v[i].it;
            it2++;

            p[v[i].value]--;
             p.push_back(0);
        }
        if(it2==a.end())
        {

            a.push_back(l);
            p[(v[i].value)+1]++;
             p.push_back(0);
            v[i].it=a.end();
            v[i].it--;

        }
        else
        {
            if(v[*((*(it2)).begin())].value!=v[i].value+1)
            {


                a.insert(it2,l);
                v[i].it=--it2;
                p[(v[i].value)+1]++;
                 p.push_back(0);

            }
            else
            {
                v[i].it=it2;
                p[(v[i].value)+1]++;
                 p.push_back(0);
            }
        }

        (*(v[i].it)).push_back(i);
        v[i].it1=(*(v[i].it)).end();
        v[i].it1--;
        v[i].value++;
    }


    void decrement(int i)
    {

        if(v[i].it!=a.begin())
        {

            (*(v[i].it)).erase(v[i].it1);

            if(p[v[i].value]==1)
            {
                a.erase(v[i].it);
            }

            it2=v[i].it;
            p[v[i].value]--;

            if(v[*((*(--it2)).begin())].value!=v[i].value-1)
            {
                a.insert(it2,l);
            }
            else
            {
                v[i].it--;
            }

            p[v[i].value-1]++;
            (*(v[i].it)).push_back(i);

            v[i].it1=(*(v[i].it)).end();
            v[i].it1--;
            v[i].value--;
        }
        else
        {
            (*(v[i].it)).erase(v[i].it1);
            if(p[v[i].value]==1)
            {
                a.erase(v[i].it);
            }
            p[v[i].value]--;
            if(v[i].value!=0)
            {
                a.push_front(l);
                v[i].it=a.begin();
                it2=a.begin();
                (*(v[i].it)).push_back(i);
                p[v[i].value-1]++;
                v[i].it1=(*(v[i].it)).end();
                v[i].it1--;
                v[i].value--;
            }
        }

    }


    int count(int i)
    {
        return v[i].value;
    }


    int reset(int i)
    {
        if(v[i].it!=a.begin())
        {
            if(v[*((*(a.begin())).begin())].value==0)
            {
                if(p[v[i].value]==1)
                {
                    it2=v[i].it;
                    a.erase(it2);
                }
                else
                {
                    (*(v[i].it)).erase(v[i].it1);
                }
                p[v[i].value]--;
                (*(a.begin())).push_back(i);
                v[i].it=a.begin();
                v[i].value=0;
                p[v[i].value]++;
            }
            else
            {
                if(p[v[i].value]==1)
                {
                    it2=v[i].it;
                    a.erase(it2);
                }
                else
                {
                    (*(v[i].it)).erase(v[i].it1);
                }
                p[v[i].value]--;
                a.insert(a.begin(),l);
                (*(a.begin())).push_back(i);
                v[i].it=a.begin();
                v[i].value=0;
                p[v[i].value]++;
            }
        }
        else
        {
            if(v[*((*(a.begin())).begin())].value!=0)
            {
                if(p[v[i].value]==1)
                {
                    it2=v[i].it;
                    a.erase(it2);
                }
                else
                {
                    (*(v[i].it)).erase(v[i].it1);
                }
                p[v[i].value]--;
                a.insert(a.begin(),l);
                (*(a.begin())).push_back(i);
                v[i].it=a.begin();
                v[i].value=0;
                p[v[i].value]++;
            }
        }
    }

    int findMax()
    {
        return v[*((*(--a.end())).begin())].value;
    }
    int numMax()
    {
        return p[v[(*((*(--a.end())).begin()))].value];
    }
    void printMax()
    {
        it2= a.end();
        it2--;
        for(list<int>::iterator it3=(*it2).begin(); it3!=(*it2).end(); it3++)
        {
            cout<<*it3<<" ";
        }
    }
};
