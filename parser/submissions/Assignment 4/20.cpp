#include<iostream>
#include<vector>
#include<list>
using namespace std;
class counter
{
    int n;
    vector<int> c;
    vector<list<list<int> >::iterator> it1;
    list< list<int> >::iterator big_iter;
    vector<list<int>::iterator> it2;
    list<list<int> > l;
public:
    counter(int x)
    {
        n=x;
        list<int> m;
        c.resize(n);
        it1.resize(n);
        it2.resize(n);
        for(int i=0; i<n; i++)
        {
            c[i]=0;
            m.push_back(i);
        }
        l.push_back(m);
        big_iter = l.begin();
        list<int>::iterator y=l.begin()->begin();
        for(int j=0; j<n; j++,++y)
        {
            it1[j]=big_iter;
            it2[j]=y;
        }
    }
    void increment(int i)
    {
        c[i]++;
        it1[i]->erase(it2[i]);
        list< list<int> >::iterator temp_iter=it1[i];
        list< list<int> >::iterator x=it1[i];
        ++temp_iter;
        list<int> m;
        if(temp_iter==l.end())
        {
            m.push_back(i);
            l.push_back(m);
            ++it1[i];
            it2[i]=it1[i]->begin();
        }
        else if(c[i]==0)
        {
            temp_iter->push_back(i);
            list<int>::iterator t=temp_iter->end();
            --t;
            it2[i]=t;
            ++it1[i];
        }
        else if(temp_iter->empty())
        {
            m.push_back(i);
            it1[i]=l.insert(temp_iter,m);
            it2[i]=it1[i]->begin();
        }
        else if(c[*(temp_iter->begin())]==c[i])
        {
            temp_iter->push_back(i);
            list<int>::iterator t=temp_iter->end();
            --t;
            it2[i]=t;
            ++it1[i];
        }
        else
        {
            m.push_back(i);
            it1[i]=l.insert(temp_iter,m);
            it2[i]=it1[i]->begin();
        }
        if((x->begin()==x->end())&&(x!=big_iter))
        {
            l.erase(x);
        }
        return;
    }
    void decrement(int i)
    {
        c[i]--;
        it1[i]->erase(it2[i]);
        list< list<int> >::iterator temp_iter=it1[i];
        list< list<int> >::iterator x=it1[i];
        --temp_iter;
        list<int> m;
        if(it1[i]==l.begin())
        {
            m.push_back(i);
            l.push_front(m);
            --it1[i];
            it2[i]=it1[i]->begin();
        }
        else if(c[i]==0)
        {
            temp_iter->push_back(i);
            list<int>::iterator t=temp_iter->end();
            --t;
            it2[i]=t;
            --it1[i];
        }
        else if(temp_iter->empty())
        {
            m.push_back(i);
            it1[i]=l.insert(temp_iter,m);
            it2[i]=it1[i]->begin();
        }
        else if(c[*(temp_iter->begin())]==c[i])
        {
            temp_iter->push_back(i);
            list<int>::iterator t=temp_iter->end();
            --t;
            it2[i]=t;
            --it1[i];
        }
        else
        {
            m.push_back(i);
            l.insert(it1[i],m);
            --it1[i];
            it2[i]=it1[i]->begin();
        }
        if((x->begin()==x->end())&&(x!=big_iter))
        {
            l.erase(x);
        }
        return;
    }
    void reset(int i)
    {
        c[i]=0;
        list< list<int> >::iterator temp_iter = it1[i];
        it1[i]->erase(it2[i]);
        big_iter->push_back(i);
        it2[i]=big_iter->end();
        --it2[i];
        it1[i]=big_iter;
        if(temp_iter->begin()==temp_iter->end())
        {
            l.erase(temp_iter);
        }
        return;
    }
    int count(int i)
    {
        return c[i];
    }
    int findMax()
    {
        list< list<int> >::iterator t=l.end();
        --t;
        if((t==big_iter)&&(big_iter->empty()))
        {
            --t;
        }
        return c[*((t)->begin())];
    }
    int numMax()
    {
        list< list<int> >::iterator t=l.end();
        --t;
        if((t==big_iter)&&(big_iter->empty()))
        {
            --t;
        }
        return t->size();
    }
    void printMax()
    {
        list< list<int> >::iterator t=l.end();
        --t;
        if((t==big_iter)&&(big_iter->empty()))
        {
            --t;
        }
        list<int>::iterator j=t->begin();
        while(j!=t->end())
        {
            cout<<*j<<" ";
            ++j;
        }
        cout<<endl;
        return;
    }
};

