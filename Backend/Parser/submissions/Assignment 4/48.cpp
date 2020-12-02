#include<iostream>
#include<list>
#include<vector>
using namespace std;

class objPos
{
    list<list<int> > :: iterator i1;
    list<int> :: iterator i2;
    int linksCount;
    friend class counter;
};

class counter
{
    vector < objPos > v;
    list<list<int> > lists;

public:
    counter(int n)
    {
        list<int> l(n);
        list<int> :: iterator ite = l.begin();
        for(int i = 0; i<n; i++,ite++)
        {
            *ite = i;
        }
        lists.push_back(l);
        list<list<int> > :: iterator it = lists.begin();
        ite = it->begin();
        objPos temp;
        for(int i = 0; i<n; i++,ite++)
        {
            temp.i1 = it;
            temp.i2 = ite;
            temp.linksCount = 0;
            v.push_back(temp);
        }
        return;
    };

    void increment(int i)
    {
        if(v[i].i1 == lists.begin())
        {
            list<int > temp1(1,i);
            (v[i].i1)->erase(v[i].i2);
            if((v[i].i1)->empty())
            {
                lists.erase(v[i].i1);
            }
            lists.push_front(temp1);
            v[i].i1 = lists.begin();
            v[i].i2 = (v[i].i1)->begin();
            v[i].linksCount = v[i].linksCount+1;
            return;
        }
        list<list<int> > :: iterator ti1 = v[i].i1;
        ti1--;
        list<int> :: iterator ti2 = ti1->begin();
        if(v[*ti2].linksCount-v[i].linksCount == 1)
        {
            ti1->push_front(i);
            (v[i].i1)->erase(v[i].i2);
            if((v[i].i1)->empty())
            {
                v[i].i1 = lists.erase(v[i].i1);
            }
            v[i].i1--;
            v[i].i2 = (v[i].i1)->begin();
            v[i].linksCount = v[i].linksCount+1;
        }
        else
        {
            list<int > temp1(1,i);
            (v[i].i1)->erase(v[i].i2);
            list<list<int> > :: iterator ins = lists.insert(v[i].i1,temp1);
            if((v[i].i1)->empty())
            {
                lists.erase(v[i].i1);
            }
            v[i].i1 = ins;
            v[i].i2 = (v[i].i1)->begin();
            v[i].linksCount = v[i].linksCount+1;
        }
        return;

    };

    void decrement(int i)
    {
        list<list<int> > :: iterator endit = lists.end();
        endit--;
        if(v[i].i1 == endit)
        {
            list<int > temp2(1,i);
            (v[i].i1)->erase(v[i].i2);
            if((v[i].i1)->empty())
            {
                lists.erase(v[i].i1);
            }
            lists.push_back(temp2);
            v[i].i1 = lists.end();
            v[i].i1--;
            v[i].i2 = (v[i].i1)->begin();
            v[i].linksCount = v[i].linksCount-1;
            return;
        }
        list<list<int> > :: iterator ti1 = v[i].i1;
        ti1++;
        list<int> :: iterator ti2 = ti1->begin();
        if(v[*ti2].linksCount-v[i].linksCount == -1)
        {
            ti1->push_front(i);
            (v[i].i1)->erase(v[i].i2);
            if((v[i].i1)->empty())
            {
                v[i].i1 = lists.erase(v[i].i1);
            }
            else
            {
                v[i].i1++;
            }
            v[i].i2 = (v[i].i1)->begin();
            v[i].linksCount = v[i].linksCount-1;
        }
        else
        {
            list<int > temp2(1,i);
            (v[i].i1)->erase(v[i].i2);
            list<list<int> > :: iterator temp_for_insert = v[i].i1;
            temp_for_insert++;
            list<list<int> > :: iterator ins = lists.insert(temp_for_insert,temp2);
            if((v[i].i1)->empty())
            {
                lists.erase(v[i].i1);
            }
            v[i].i1 = ins;
            v[i].i2 = (v[i].i1)->begin();
            v[i].linksCount = v[i].linksCount--;
        }
        return;
    };

    void reset(int i)
    {
        list<list<int> > :: iterator endit = lists.end();
        endit--;
        list<int> :: iterator iter = endit->begin();
        if(v[*iter].linksCount == 0)
        {
            endit->push_front(i);
            (v[i].i1)->erase(v[i].i2);
            if((v[i].i1)->empty())
            {
                v[i].i1 = lists.erase(v[i].i1);
            }
            else
            {
                //skip
            }
            v[i].i1 = endit;
            v[i].i2 = (v[i].i1)->begin();
            v[i].linksCount = 0;
            return;
        }
        list<int> temp3(1,i);
        lists.push_back(temp3);
        (v[i].i1)->erase(v[i].i2);
        if((v[i].i1)->empty())
        {
            v[i].i1 = lists.erase(v[i].i1);
        }
        else
        {
            //Do nothing
        }
        endit++;
        v[i].i1 = endit;
        v[i].i2 = (v[i].i1)->begin();
        v[i].linksCount = 0;
    };

    int count(int i)
    {
        return v[i].linksCount;
    };

    int findMax()
    {
        list<list<int> > :: iterator first_i = lists.begin();
        list<int> :: iterator iter = first_i->begin();
        return v[*iter].linksCount;
    };

    void printMax()
    {
        list<list<int> > :: iterator first_i = lists.begin();
        list<int> :: iterator iter = first_i->end();
        iter--;
        while(iter!=first_i->begin())
        {
            cout<<*iter<<endl;
            iter--;
        }
        cout<<*iter<<endl;
        return;
    };

    int numMax()
    {
        list<list<int> > :: iterator first_i = lists.begin();
        return first_i->size();
    };

};
