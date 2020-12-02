/*

1. increment(i) : Increment the count for the ith object.
2. decrement(i) : Decrement the count for the ith object.
3. reset(i) : Reset the count of ith object to 0.
5. count(i) : Return the current count of ith object.
4. findMax() : Return the maximum count of the objects.
5. numMax() : Return the number of objects having maximum count.
6. printMax() : Print the list of objects with maximum count, in the
            order in which they achieved that count value.
*/
#include<iostream>
#include<vector>
#include<list>
using namespace std;

class counter
{
private:
    int n;
    list< list<int> > l;
    vector<int> v;
    vector< list<int>::iterator >  itin;
    vector< list<list<int> >::iterator > itout;
    list<list<int>  >::iterator it0;
public:
    counter(int a)
    {
        n=a;
        list<int> temp;
        for(int i=0; i<n; i++)
        {
            temp.push_back(i);
            v.push_back(0);
        }

        l.push_back(temp);
        it0=l.begin();


        for(int i=0; i<n; i++)
        {
            itout.push_back(l.begin());
        }
        list<int>::iterator it=(l.begin())->begin();

        for(int i=0; i<n; i++,it++)
        {
            itin.push_back(it);

        }
        return ;
    }
    void increment(int i)
    {
        list<list<int> >::iterator d=itout[i];
        if(v[i] == -1)
        {
            itout[i]->erase(itin[i]);
            it0->push_front(i);
            itout[i]=it0;
            itin[i]=itout[i]->begin();
            v[i]++;
            if((d->empty())&&(d!=it0))
            {
                l.erase(d);
            }
            return;
        }
        v[i]++;
        list<list<int> >::iterator it=l.end();
        it--;
        if(itout[i]==it)
        {

            itout[i]->erase(itin[i]);
            list<int> temp;
            temp.push_back(i);
            l.push_back(temp);
            itout[i]=l.end();
            itout[i]--;
            itin[i]=itout[i]->begin();
        }
        else

        {
            itout[i]++;
            if(itout[i]!=it0)
            {
                if(v[itout[i]->front()]==v[i])
                {
                    itout[i]--;
                    itout[i]->erase(itin[i]);
                    itout[i]++;
                    itout[i]->push_front(i);
                    itin[i] = itout[i]->begin();
                }

            else
            {
                itout[i]--;
                itout[i]->erase(itin[i]);
                list<int> temp;
                temp.push_back(i);
                itout[i]++;
                itout[i]=l.insert(itout[i],temp);
                itin[i]=itout[i]->begin();


            }
            }
            else
            {
                itout[i]--;
                itout[i]->erase(itin[i]);
                list<int> temp;
                temp.push_back(i);
                itout[i]++;
                itout[i]=l.insert(itout[i],temp);
                itin[i]=itout[i]->begin();


            }

        }

        if((d->empty())&&(d!=it0))
        {
            l.erase(d);
        }
        return ;
    }

    void decrement(int i)
    {
        list<list<int> >::iterator d=itout[i];
        if(v[i]==1)
        {
            itout[i]->erase(itin[i]);
            it0->push_front(i);
            itout[i]=it0;
            itin[i]=itout[i]->begin();
            v[i]--;
            if((d->empty())&&(d!=it0))
            {
                l.erase(d);
            }
            return;
        }
        v[i]--;

        if(itout[i]==l.begin())
        {
            itout[i]->erase(itin[i]);
            list<int> temp;
            temp.push_back(i);
            l.push_front(temp);
            itout[i]=l.begin();
            itin[i]=itout[i]->begin();
         }
        else
        {
            list<list<int> >::iterator it=itout[i];
            itout[i]->erase(itin[i]);
            itout[i]--;
            if(itout[i]!=it0)
           {
            if(v[itout[i]->front()]==v[i])
            {
                itout[i]->push_front(i);
                itin[i]=itout[i]->begin();
            }

            else
            {
                list<int> temp;
                temp.push_back(i);
                itout[i]++;
                itout[i]=l.insert(itout[i],temp);
                itin[i]=itout[i]->begin();

            }
            }
             else
            {
                list<int> temp;
                temp.push_back(i);
                itout[i]++;
                itout[i]=l.insert(itout[i],temp);
                itin[i]=itout[i]->begin();

            }


        }
        if(((d->empty())&&(d!=it0)))
        {
            l.erase(d);
        }

        return ;
    }
    void reset(int i)
    {
        list<list<int> >::iterator d=itout[i];
        itout[i]->erase(itin[i]);
        it0->push_front(i);
        itout[i]=it0;
        itin[i]=itout[i]->begin();

        if(d->empty()&& (d!=it0) )
        {
            l.erase(d);
        }
        return ;
    }
    int count(int i)
    {
        return v[i];
    }
    int  findMax()
    {
        list<list<int> >::iterator it = l.end();
        it--;
        if(it==it0&&it0->empty())
        {
        it--;
        }
        return v[it->front()];
    }
    int numMax()
    {
        list<list<int> >::iterator it = l.end();
        it--;
        if(it==it0&&it0->empty())
        {
        it--;
        }
        return (it)->size();
    }
    void printMax()
    {
        list<list<int> >::iterator it = l.end();
        it--;
        if(it==it0&&it0->empty())
        {
        it--;
        }
        for(list<int>::iterator i = it->end(); i != (it->begin()); )
        {
            i--;
            cout<<(*i)<<" ";
        }
        cout<<endl;
        return ;
    }
};



