#include<iostream>
#include<vector>
#include<list>
using namespace std;
class counter
{
    class iterators
    {
    public:
        list<list<int> >::iterator a;
        list<int>::iterator b;
    };
    int n;
    list<list<int> > A;
    list<list<int> >::iterator p;
    list<list<int> >::iterator q;
    vector<iterators> it;
    int first_positive;
    int first_negative;
    bool flag;
public:
    counter(int N)//constructor
    {
        n=N;
        list<int> b;
        b.push_back(0);
        b.push_back(n);
        for(int i=2; i<n+2; i++)
        {
            b.push_back(i-2);
        }
        A.push_back(b);
        iterators x;
        x.a=A.begin();
        x.b=(A.begin())->begin();
        x.b++;
        x.b++;
        for(int i=0; i<n; i++)
        {
            it.push_back(x);
            x.b++;
        }
        p=A.begin();
        q=A.begin();
        first_negative=0;
        first_positive=0;
        flag=1;
    }
    void increment(int i)
    {
        list<list<int> >::iterator m;
        list<int>::iterator n,n1;
        m=it[i].a;
        n=it[i].b;
        int c=m->front();
        n1=n;
        if((++m==A.end())||(--m)->front()!=(++m)->front()-1)
        {
            list<int> newb;
            if(c+1==0)
            {
                flag=1;
            }
            A.insert(m,newb);
            m--;
            m->push_back(c+1);
            m->push_back(1);
            m->push_back(i);
            (it[i].a)++;
            (it[i].b)=--(m->end());

            if(c+1==1)
            {
                first_positive=1;
                p=m;

            }
            else
            {

            }
        }
        else
        {
            (it[i].a)++;
            m->push_back(i);
            (it[i].b)=--(m->end());
            n=m->begin();
            n++;
            *n=*n+1;
        }
        m--;
        (m)->erase(n1);
        if(m->size()==2)
        {
            if(m->front()==first_positive)
            {
                first_positive=(++m)->front();
                p=m;
                m--;
            }
            else
            {

            }
            if(m->front()==first_negative)
            {
                first_negative=(++m)->front();
                q=m;
                m--;
            }
            else
            {

            }
            if(m->front()==0)
            {
                flag=0;
            }
            A.erase(m);
        }
        else
        {
            n1=m->begin();
            n1++;
            (*n1)=(*n1)-1;
        }
    }
    void decrement(int i)
    {
        list<list<int> >::iterator m,m1;
        list<int>::iterator n,n1;
        m=it[i].a;
        n=it[i].b;
        int c=m->front();
        n1=n;
        if((--m==--A.begin())||(++m)->front()!=(--m)->front()+1)
        {
            list<int> newb;
            if(c-1==0)
            {
            flag=1;
            }
            newb.push_back(c-1);
            newb.push_back(1);
            newb.push_back(i);
            A.insert(++m,newb);
            m--;
            (it[i].a)--;
            (it[i].b)=--(m->end());
            if(c-1==-1)
            {
                first_negative=-1;
                q=m;
            }
            else
            {

            }
        }
        else
        {
            (it[i].a)--;
            m->push_back(i);
            (it[i].b)=--(m->end());
            n=m->begin();
            n++;
            *n=*n+1;
        }
        m++;
        m->erase(n1);
        if(m->size()==2)
        {
            if(m->front()==first_positive)
            {
                first_positive=(--m)->front();
                p=m;
                m++;
            }
            else
            {

            }
            if(m->front()==first_negative)
            {
                first_negative=(--m)->front();
                q=m;
                m++;
            }
            else
            {

            }
            if(m->front()==0)
            {
                flag=0;
            }
            A.erase(m);
        }
        else
        {
            n1=m->begin();
            n1++;
            (*n1)=(*n1)-1;
        }
    }
    void reset(int i)
    {
        list<list<int> >::iterator m;
        list<int>::iterator n;
        m=it[i].a;
        n=it[i].b;
        int c=m->front();
        if(c==0)
        {
            return;
        }
        if(c>0)
        {
            if(flag==0)
            {
                list<int> newb;
                newb.push_back(0);
                newb.push_back(1);
                newb.push_back(i);
                A.insert(p,newb);
                it[i].a=--p;
                p++;
                it[i].b=--((it[i].a)->end());
                flag=1;
            }
            else
            {
                list<list<int> >::iterator zero;
                zero=p;
                zero--;
                zero->push_back(i);
                it[i].a=zero;
                it[i].b=--(zero->end());
                *(++(zero->begin()))++;

            }
        }
        if(c<0)
        {
            if(flag==0)
            {
                list<int> newb;
                newb.push_back(0);
                newb.push_back(1);
                newb.push_back(i);
                if(first_positive>0)
                {
                    A.insert(p,newb);
                    it[i].a=--p;
                    p++;
                }
                else
                {
                    A.push_back(newb);
                    it[i].a=--(A.end());
                }

                it[i].b=--((it[i].a)->end());
                flag=1;
            }
        }
        m->erase(n);
        if(m->size()==2)
        {
            if(m->front()==0)
            {
                flag=0;
            }
            A.erase(m);
        }
        else
        {
            n=m->begin();
            n++;
            (*n)=(*n)-1;
        }
    }
    int count(int i)
    {
        return (it[i].a)->front();
    }

    int findMax()
    {
        return (--(A.end()))->front();;
    }

    int numMax()
    {
        return *(++((--(A.end()))->begin()));
    }
    void printMax()
    {
        list<int>::iterator n=((--A.end())->begin());
        n++;
        n++;
        while(n!=((--A.end())->end()))
        {
            cout<<*n<<" ";
            n++;
        }
        return;
    }
};

