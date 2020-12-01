#include<iostream>
#include <list>
#include<vector>
using namespace std;

class counter
{
private :
//    int n;
    vector<int> c;
    list<list<int> > ans;
    vector<list<int> ::iterator > a;
    vector<list<list<int> >::iterator > b;

public:
    counter(int n)
    {

        list<int> temp;

        for(int i=0; i<n; i++)
        {
            c.push_back(0);
            temp.push_back(i);
        }

        ans.push_back(temp);

        list<int>::iterator it;
        it=(ans.front()).begin();

        for(int i=0; i<n; i++)
        {
            b.push_back(ans.begin());
            a.push_back(it);
            ++it;
        }
        return ;
    }

    // increment(i) : Increment the count for the ith object.
    void increment(int i)
    {
        c[i]++;

        list<list<int> >::iterator d;
        d=b[i];
        if(b[i]!=--(ans.end()) )
        {
            b[i]->erase(a[i]);
            ++b[i];
            if(c[i]-c[b[i]->front()]==0)
            {
                b[i]->push_back(i);
                a[i]=--(b[i]->end());
            }
            else
            {
                list<int> temp;
                temp.push_back(i);
                ans.insert(b[i],temp);
                --b[i];
                a[i]=(b[i])->begin();
            }
        }
        else
        {
            b[i]->erase(a[i]);
            list<int> temp;
            temp.push_back(i);
            ans.push_back(temp);
            ++b[i];
            a[i]=(b[i]->begin());
        }
        if(d->empty())
        {
            ans.erase(d);
        }
        return ;
    }

    // decrement(i) : Decrement the count for the ith object.
    void decrement(int i)
    {
        c[i]--;
        list<list<int> >::iterator d;
        d=b[i];

        if(b[i]!=ans.begin())
        {
            b[i]->erase(a[i]);
            --b[i];
            if(c[i]-c[b[i]->front()]==0)
            {
                b[i]->push_back(i);
                a[i]=--(b[i]->end());
            }
            else
            {
                ++b[i];
                list<int> temp;
                temp.push_back(i);
                ans.insert(b[i],temp);
                --b[i];
                a[i]=b[i]->begin();
            }
        }
        else
        {
            b[i]->erase(a[i]);
            list<int> temp;
            temp.push_back(i);
            ans.insert(b[i],temp);
            --b[i];
            a[i]=b[i]->begin();
        }

        if(d->empty())
        {
            ans.erase(d);
        }
        return ;
    }
    //reset(i) : Reset the count of ith object to 0.
    void reset (int i)
    {


        list<list<int> >::iterator d;
        d=b[i];

        if(c[(ans.front()).front()]==0)
        {
            b[i]->erase(a[i]);
            b[i]=ans.begin();
            b[i]->push_back(i);
            a[i]=--(b[i]->end());
        }
        else
        {
            b[i]->erase(a[i]);
            list<int> temp;
            temp.push_back(i);
            ans.push_front(temp);
            b[i]=ans.begin();
            a[i]=--(b[i]->end());
        }

        c[i]=0;

        if(d->empty())
        {
            ans.erase(d);
        }
        return;
    }
    // count(i) : Return the current count of ith object.
    int count(int i)
    {
        return c[i];
    }

    //findMax() : Return the maximum count of the objects.
    int findMax()
    {
// max count
        list<list<int> >::iterator s;
        s=--ans.end();
        return c[s->front()];
    }
    //numMax() : Return the number of objects having maximum count
    int numMax()
    {
// should use size
        list<list<int> >::iterator s;
        s=--ans.end();
        return s->size();
    }
    //printMax() : Print the list of objects with maximum count, in the
    //             order in which they achieved that count value.

    void printMax()
    {
        list<list<int> >::iterator s=ans.end();
        --s;
        for(list<int>::iterator p=s->begin(); p!=s->end(); ++p)
        {
            cout<<*p<<endl;

        }
        return;
    }
};


