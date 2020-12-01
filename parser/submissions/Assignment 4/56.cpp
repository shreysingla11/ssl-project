#include <iostream>
#include <vector>
#include <list>
using namespace std;
struct node
{
    int index;
    int count;
    list<list<node> > :: iterator ll;
    node(int i=0, int v=0)
    {
        count = v;
        index = i;
    }
};
class counter
{
    int n;
    int numCountMax;
    int isZero;
    list<list<node> > l;
    vector<list<node> :: iterator> v;
    list<list<node> > :: iterator zero;
public:
    counter(int size)
    {
        int i;
        n = size;
        l.push_back(list<node>(0));
        (l.begin())->push_back(node(0, 0));
        list<node> :: iterator it = (l.begin())->begin();
        (*it).ll = l.begin();
        v.push_back(it);
        for (i = 1; i < size; ++i)
        {
            (l.begin())->push_back(node(i, 0));
            ++it;
            (*it).ll = l.begin();
            v.push_back(it);
        }
        isZero = 0;
        zero = l.begin();
        numCountMax = n;
    }
    void increment(int i);
    void decrement(int i);
    void reset(int i);
    int count(int i);
    int findMax();
    int numMax();
    void printMax();
};
void counter::increment(int i)
{
    list<list<node> > :: iterator it = l.end();
    --it;
    node temp;
 //    // cout<<((*(it->begin())).index)<<endl;
    // // cout<<(*(v[i])).count<<endl;
    if ((*(it->begin())).count == (*(v[i])).count)
    {
        // cout<<"hey1"<<endl;
        l.push_back(list<node>(0));
        temp.index = (*(v[i])).index;
        temp.count = (*(v[i])).count + 1;
        if (temp.count == 0)
        {
            isZero = 0;
            zero = --l.end();
        }
        it->erase(v[i]);
        if (it->empty())
        {
            // cout<<"here"<<endl;
            if (zero == it)
            {
                if (temp.count > 0)
                    isZero = 1;
                else if (temp.count < 0)
                    isZero = -1;
                zero = --l.end();
            }
            l.erase(it);
        }
        it = l.end();
        temp.ll = --it;
        it->push_back(temp);
        v[i] = it->begin();
        // <<endl;
        // cout<<"index = "<<(*(it->begin())).index<<" count = "<<(*(it->begin())).count<<endl;
        numCountMax = 1;
    }
    else 
    {
        // cout<<"here1"<<endl;
        list<list<node> > :: iterator it2 = ((*v[i]).ll);
        ++it2;
        // cout<<"here2"<<endl;
        if (((*(it2->begin())).count) > ((*(v[i])).count + 1))
        {
            // cout<<"hey2"<<endl;
            it2 = l.insert(it2, list<node>(0));
            temp.index = (*(v[i])).index;
            temp.count = (*(v[i])).count + 1;
            it = (*v[i]).ll;
            if (temp.count == 0)
            {
                isZero = 0;
                zero = it2;
            }
            it->erase(v[i]);
            if (it->empty())
            {
                // cout<<"here"<<endl;
                if (zero == it)
                {
                    if (temp.count == 0)
                        isZero = 0;
                    else if (temp.count < 0)
                        isZero = -1;
                    else
                        isZero = 1;
                    zero = it2;
                }
                l.erase(it);
            }
            temp.ll = it2;
            it2->push_back(temp);
            v[i] = it2->begin();
            // <<endl;
            // cout<<"index = "<<(*(v[i])).index<<" count = "<<(*(v[i])).count<<endl;
        }
        else
        {
            // cout<<"hey3"<<endl;
            temp.index = (*(v[i])).index;
            temp.count = (*(v[i])).count + 1;
            it = (*v[i]).ll;
            if (temp.count == 0)
            {
                isZero = 0;
                zero = it2;
            }
            it->erase(v[i]);
            if (it->empty())
            {
                // cout<<"here"<<endl;
                if (zero == it)
                {
                    if (temp.count > 0)
                        isZero = 1;
                    else if (temp.count < 0)
                        isZero = -1;
                    else
                        isZero = 0;
                    zero = it2;
                }
                l.erase(it);
            }
            temp.ll = it2;
            it2->push_back(temp);
            v[i] = --(it2->end());
            // <<endl;
            // cout<<"index = "<<(*v[i]).index<<" count = "<<(*(v[i])).count<<endl;
            ++numCountMax;
        }
    }
    // cout<<"isZero = "<<isZero<<endl;
}
void counter::decrement(int i)
{
    list<list<node> > :: iterator it = l.begin();
    node temp;
    // // cout<<(*(it->begin()).index)<<" "<<*(v[i])<<endl;
    if ((*(it->begin())).count == (*(v[i])).count)
    {
        // cout<<"hey1"<<endl;
        l.push_front(list<node>(0));
        temp.index = (*(v[i])).index;
        temp.count = (*(v[i])).count - 1;
        it = l.end();
        --it;
        if ((*(it->begin())).count == (temp.count+1))
        {
            --numCountMax;
            if (numCountMax == 0)
            {
                --it;
                numCountMax = 1; 
            }
        }
        it = l.begin();
        ++it;
        if (temp.count == 0)
        {
            isZero = 0;
            zero = l.begin();
        }
        it->erase(v[i]);
        if (it->empty())
        {
            // cout<<"here"<<endl;
            if (zero == it)
            {
                if (temp.count > 0)
                    isZero = 1;
                else if (temp.count < 0)
                    isZero = -1;
                else
                    isZero = 0;
                zero = l.begin();
            }
            l.erase(it);
        }
        it = l.begin();
        temp.ll = it;
        it->push_back(temp);
        v[i] = it->begin();
        // <<endl;
        // cout<<"index = "<<(*v[i]).index<<" count = "<<(*v[i]).count<<endl;
    }
    else 
    {
        // cout<<"here1"<<endl;
        list<list<node> > :: iterator it2 = (*v[i]).ll;
        --it2;
        // cout<<"here2"<<endl;
        if ((*(it2->begin())).count < ((*(v[i])).count - 1))
        {
            // cout<<"hey2"<<endl;
            it2 = l.insert((*v[i]).ll, list<node>(0));
            temp.index = (*(v[i])).index;
            temp.count = (*(v[i])).count - 1;
            it = l.end();
            --it;
            if ((*(it->begin())).count == (temp.count+1))
            {
                --numCountMax;
                if (numCountMax == 0)
                {
                    --it;
                    numCountMax = 1; 
                }
            }
            it = (*v[i]).ll;
            if (temp.count == 0)
            {
                isZero = 0;
                zero = it2;
            }
            it->erase(v[i]);
            if (it->empty())
            {
                // cout<<"here"<<endl;
                if (zero == it)
                {
                    if (temp.count > 0)
                        isZero = 1;
                    else if (temp.count < 0)
                        isZero = -1;
                    else
                        isZero = 0;
                    zero = it2;
                }
                l.erase(it);
            }
            temp.ll = it2;
            it2->push_back(temp);
            v[i] = it2->begin();
            // <<endl;
            // cout<<"index = "<<(*(v[i])).index<<" count = "<<(*(v[i])).count<<endl;
        }
        else
        {
            // cout<<"hey3"<<endl;
            temp.index = (*(v[i])).index;
            temp.count = (*(v[i])).count - 1;
            it = l.end();
            --it;
            if ((*(it->begin())).count == (temp.count+1))
            {
                --numCountMax;
                if (numCountMax == 0)
                {
                    --it;
                    // numCountMax = 1+it->size(); 
                }
            }
            it = (*v[i]).ll;
            if (temp.count == 0)
            {
                isZero = 0;
                zero = it2;
            }
            it->erase(v[i]);
            if (it->empty())
            {
                // cout<<"here"<<endl;
                if (zero == it)
                {
                    if (temp.count > 0)
                        isZero = 1;
                    else if (temp.count < 0)
                        isZero = -1;
                    else
                        isZero = 0;
                    zero = it2;
                }
                l.erase(it);
            } 
            temp.ll = it2;
            it2->push_back(temp);
            v[i] = --(it2->end());
            // <<endl;
            // cout<<"index = "<<(*v[i]).index<<" count = "<<(*v[i]).count<<endl;
        }
    }
    // cout<<"isZero = "<<isZero<<endl;
}
void counter::reset(int i)
{
    list<list<node> > :: iterator it;
    list<list<node> > :: iterator it2 = (*v[i]).ll;
    node temp;
    if (isZero == 0)
    {
        temp.index = (*(v[i])).index;
        temp.count = 0;
        it = l.end();
        --it;
        if ((*(it->begin())).count == (*v[i]).count)
        {
            --numCountMax;
            if (numCountMax == 0)
            {
                --it;
                // numCountMax = it->size(); 
            }
        }
        it = it2;
        it->erase(v[i]);
        if (it->empty())
        {
            // cout<<"here"<<endl;
            l.erase(it);
        }
        temp.ll = zero;
        zero->push_back(temp);
        v[i] = --(zero->end());
    }
    else if (isZero == 1)
    {
        zero = l.insert(zero, list<node>(0));
        isZero = 0;
        temp.index = (*(v[i])).index;
        temp.count = 0;
        temp.ll = zero;
        zero->push_back(temp);
        it = l.end();
        --it;
        if ((*(it->begin())).count == (*v[i]).count)
        {
            if ((*v[i]).count < 0)
            {
                numCountMax = 1;
            }
            else
            {
                --numCountMax;
                if (numCountMax == 0)
                {
                    --it;
                    // numCountMax = it->size(); 
                }
            }
        }
        it = it2;
        it->erase(v[i]);
        if (it->empty())
        {
            // cout<<"here"<<endl;
            l.erase(it);
        }
        v[i] = --(zero->end());
    }
    else if (isZero == -1)
    {
        it = ++zero;
        zero = l.insert(it, list<node>(0));
        isZero = 0;
        temp.index = (*(v[i])).index;
        temp.count = 0;
        temp.ll = zero;
        zero->push_back(temp);
        it = l.end();
        --it;
        if ((*(it->begin())).count == (*v[i]).count)
        {
            if ((*v[i]).count < 0)
            {
                numCountMax = 1;
            }
            else
            {
                --numCountMax;
                if (numCountMax == 0)
                {
                    --it;
                    // numCountMax = it->size(); 
                }
            }
        }
        it = it2;
        it->erase(v[i]);
        if (it->empty())
        {
            // cout<<"here"<<endl;
            l.erase(it);
        }
        v[i] = --(zero->end());
    }
}
int counter::count(int i)
{
    return (*(v[i])).count;
}
int counter::findMax()
{
    list<list<node> > :: iterator it = l.end();
    --it;
    return (*(it->begin())).count;
}
int counter::numMax()
{
    list<list<node> > :: iterator it = l.end();
    --it;
    return it->size();
}
void counter::printMax()
{
    list<list<node> > :: iterator it = l.end();
    --it;
    for (list<node> :: iterator p = (it->begin()); p != (it->end()); ++p)
    {
        cout<<(*p).index<<" ";
    }
    cout<<endl;
}