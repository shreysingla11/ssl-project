#include <iostream>
#include <vector>
#include <list>
using namespace std;
class counter
{
    list<list<int> > main;
    list<list<int> >::iterator mainiter;
    int n;
    vector<int> values;
    vector<list<list<int> >::iterator > points;
    vector<list<int>::iterator> rowpoint;
public:
    counter(int x)
    {
        n=x;
        values.resize(n,0);
        points.resize(n);
        rowpoint.resize(n);
        list<int> m;
        for(int i=0; i<n; i++)
        {
            m.push_back(i);
        }
        main.push_back(m);
        list<list<int> >::iterator a=main.begin();
        for(int j=0; j<n; j++,++a)
        {
            points[j]=main.begin();
        }
        list<int>::iterator b;
        a=main.begin();
        b=a->begin();
        for(int k=0;k<n;k++)
        {
            rowpoint[k]=b;
        }
    }

    void increment(int i)
    {
        list<list<int> >::iterator s;
        list<list<int> >::iterator t;
        list<list<int> >::iterator r=points[i];
        s=main.end();
        --s;
        t=points[i];
        ++t;
        if(r==s)
        {
            list<int> b;
            b.push_back(i);
            ++values[i];
            main.push_back(b);
            ++points[i];
            rowpoint[i]=points[i]->begin();
        }
        else
        {
            if(values[*(t->begin())]-1>values[i])
            {
                ++points[i];
                list<int> c;
                c.push_back(i);
                main.insert(points[i],c);
                rowpoint[i]=points[i]->begin();
                values[i]++;
            }
            else
            {
                values[i]++;
                points[i]->erase(rowpoint[i]);
                ++points[i];
                points[i]->push_back(i);
                rowpoint[i]=points[i]->end();
                --rowpoint[i];
            }
        }
        if(r->empty())
        {
            main.erase(r);
        }
      return;
    }
    void decrement(int i)
    {
        list<list<int> >::iterator s;
        list<list<int> >::iterator t;
        list<list<int> >::iterator r=points[i];
        list<int>::iterator p;
        s=main.begin();
        t=points[i];
        --t;
        p=t->end();
        --p;
        if(r==s)
        {
            list<int> b;
            b.push_back(i);
            --values[i];
            main.push_front(b);
            rowpoint[i]=points[i]->begin();
        }
        else
        {
            if((values[*p]+1)<values[i])
            {
                list<int> c;
                c.push_back(i);
                main.insert(points[i],c);
                --points[i];
                rowpoint[i]=points[i]->begin();
                --values[i];
            }
            else
            {
                --values[i];
                points[i]->erase(rowpoint[i]);
                --points[i];
                points[i]->push_back(i);
                rowpoint[i]=points[i]->end();
                --rowpoint[i];
            }
        }
        if(r->empty())
        {
            main.erase(r);
        }
      return;
    }
    void reset(int i)
    {
        points[i]->erase(rowpoint[i]);
        points[i]=main.begin();
        rowpoint[i]=(main.begin())->end();
        --rowpoint[i];
        values[i]=0;
    }
    int count(int i)
    {
        return values[i];
    }
    int findMax()
    {
        list<list<int> >::iterator n;
        n=main.end();
        --n;
        int g=values[(*n->begin())];
        return g;
    }
    int numMax()
    {
        list<list<int> >::iterator n;
        n=main.end();
        --n;
        int g;
        g=n->size();
        return g;
    }
    void printMax()
    {
        list<list<int> >::iterator m;
        m=main.end();
        --m;
        list<int>::iterator n;
        n=m->begin();
        for(int j=0;n!=m->end();++n)
        {
            cout<<*n<<endl;
        }
        return;
    }
};
