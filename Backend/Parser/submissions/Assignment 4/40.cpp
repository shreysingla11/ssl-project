#include<iostream>
#include<list>
#include<vector>
using namespace std;
class counter
{
    class pos
    {
        list<list<int> > :: iterator i1;
        list<int> :: iterator i2;
        int nlinks;
        friend class counter;
    };
    vector < pos > v;
    list<list<int> > lists;
public:
    counter(int n)
    {
        list<int> T(n);
        list<int> :: iterator ite = T.begin();
        for(int i = 0; i<n; i++,ite++)
        {
            *ite = i;
        }
        lists.push_back(T);
        list<list<int> > :: iterator iter1 = lists.begin();
        ite = iter1->begin();
        pos temp;
        for(int i = 0; i<n; i++,ite++)
        {
            temp.i1 = iter1;
            temp.i2 = ite;
            temp.nlinks = 0;
            v.push_back(temp);
        }

        return;
    }
    void increment(int i)
    {
        if(v[i].i1 == lists.begin())
        {
            list<int > temporary(1,i);
            (v[i].i1)->erase(v[i].i2);
            if((v[i].i1)->empty())
            {
                lists.erase(v[i].i1);
            }
            lists.push_front(temporary);
            v[i].i1 = lists.begin();
            v[i].i2 = (v[i].i1)->begin();
            v[i].nlinks = v[i].nlinks+1;
            return;
        }
        list<list<int> > :: iterator ti1 = v[i].i1;
        ti1--;
        list<int> :: iterator ti2 = ti1->begin();
        if(v[*ti2].nlinks-v[i].nlinks == 1)
        {
            ti1->push_front(i);
            (v[i].i1)->erase(v[i].i2);
            if((v[i].i1)->empty())
            {
                v[i].i1 = lists.erase(v[i].i1);
            }
            v[i].i1--;
            v[i].i2 = (v[i].i1)->begin();
            v[i].nlinks = v[i].nlinks+1;
        }
        else
        {
            list<int > temporary(1,i);
            (v[i].i1)->erase(v[i].i2);
            list<list<int> > :: iterator ins = lists.insert(v[i].i1,temporary);
            if((v[i].i1)->empty())
            {
                lists.erase(v[i].i1);
            }
            v[i].i1 = ins;
            v[i].i2 = (v[i].i1)->begin();
            v[i].nlinks = v[i].nlinks+1;
        }
        return;

    }
    void decrement(int i)
    {
        list<list<int> > :: iterator endit = lists.end();
        endit--;
        if(v[i].i1 == endit)
        {
            list<int > temporary(1,i);
            (v[i].i1)->erase(v[i].i2);
            if((v[i].i1)->empty())
            {
                lists.erase(v[i].i1);
            }
            lists.push_back(temporary);
            v[i].i1 = lists.end();
            v[i].i1--;
            v[i].i2 = (v[i].i1)->begin();
            v[i].nlinks = v[i].nlinks-1;
            return;
        }
        list<list<int> > :: iterator ti1 = v[i].i1;
        ti1++;
        list<int> :: iterator ti2 = ti1->begin();
        if(v[*ti2].nlinks-v[i].nlinks == -1)
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
            v[i].nlinks = v[i].nlinks-1;
        }
        else
        {
            list<int > temporary(1,i);
            (v[i].i1)->erase(v[i].i2);
            list<list<int> > :: iterator temp_for_insert = v[i].i1;
            temp_for_insert++;
            list<list<int> > :: iterator ins = lists.insert(temp_for_insert,temporary);
            if((v[i].i1)->empty())
            {
                lists.erase(v[i].i1);
            }
            v[i].i1 = ins;
            v[i].i2 = (v[i].i1)->begin();
            v[i].nlinks = v[i].nlinks--;
        }
        return;
    }
    void reset(int i)
    {
        list<list<int> > :: iterator endit = lists.end();
        endit--;
        list<int> :: iterator iter = endit->begin();
        if(v[*iter].nlinks == 0)
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
            v[i].nlinks = 0;
            return;
        }
        list<int> temporary(1,i);
        lists.push_back(temporary);
        (v[i].i1)->erase(v[i].i2);
        if((v[i].i1)->empty())
        {
            v[i].i1 = lists.erase(v[i].i1);
        }
        else
        {
            //skip
        }
        endit++;
        v[i].i1 = endit;
        v[i].i2 = (v[i].i1)->begin();
        v[i].nlinks = 0;
    }
    int count(int i)
    {
        return v[i].nlinks;
    }
    int findMax()
    {
        list<list<int> > :: iterator firsti = lists.begin();
        list<int> :: iterator iter = firsti->begin();
        return v[*iter].nlinks;
    }
    void printMax()
    {
        list<list<int> > :: iterator firsti = lists.begin();
        list<int> :: iterator iter = firsti->end();
        iter--;
        while(iter!=firsti->begin())
        {
            cout<<*iter<<endl;
            iter--;
        }
        cout<<*iter<<endl;
    }
    int numMax()
    {
        list<list<int> > :: iterator firsti = lists.begin();
        return firsti->size();
    }
};

