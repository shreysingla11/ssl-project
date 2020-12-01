#include <iostream>
#include <list>
#include <vector>
using namespace std;

class body
{
public:
    int c;
    list<list<int> > ::iterator a;
    list<int>::iterator b;
    body(int n)
    {
        c = n;
    }
};

class counter
{
public:
    vector<body> objects;
    list<list<int> > counts;
    list<list<int> >::iterator it1;
    list<int>::iterator it2;

    counter(int n)
    {
        it1 = counts.begin();
        it2 = (*it1).begin();
        list<int> numbers;
        for(int i=0; i<n; i++)
        {
            numbers.push_back(i);
        }
        counts.push_back(numbers);
        it1 = counts.begin();
        it2 = (*it1).begin();
        for(int i=0; i<n; i++,++it2)
        {
            objects.push_back(body(0));
            objects[i].a = it1;
            objects[i].b = it2;
        }
        it2 = (*it1).begin();
        return;
    }

    void increment(int i)
    {
        it1 = counts.begin();
        it2 = (*it1).begin();

        objects[i].c++;
        it1 = objects[i].a;
        it2 = objects[i].b;
        list<int>::iterator it3 = it1->end();
        list<int>::iterator it5;
        ++it1;
        list<list<int> >::iterator it4 = it1;
        --it1;

        bool single = false,last = false,gap = false,neighbour = false;
        if(it4==counts.end())
        {
            last = true;
            gap = false;
            neighbour = false;
        }
        else
        {
            it5 = it4->end();
            --it5;
            if(objects[(*it5)].c ==objects[i].c)
            {
                neighbour = true;
                gap = false;
                last = false;
            }
            else
            {
                gap = true;
                last = false;
                neighbour = false;
            }
            ++it5;
        }

        --it3;
        if((it2==it3)&&(it2==it1->begin()))
        {
            single = true;
        }
        else
        {
            single = false;
        }
        ++it3;

        if(single)
        {
            if(gap||last)
            {
                return;
            }
            else
            {
                it4->push_back(i);
                it1 = counts.erase(it1);
                objects[i].a = it1;
                it2 = it1->end();
                --it2;
                objects[i].b = it2;
                return;
            }
        }
        else
        {
            if(gap||last)
            {
                list<int> temp;
                temp.push_back(i);
                it2 = it1->erase(it2);
                counts.insert(it4,temp);
                ++it1;
                it2 = it1->end();
                --it2;
                objects[i].a = it1;
                objects[i].b = it2;
                return;
            }
            else
            {
                it2 = it1->erase(it2);
                it4->push_back(i);
                it5 = it4->end();
                --it5;
                objects[i].a = it4;
                objects[i].b = it5;
                return;
            }
        }
    }
    void decrement(int i)
    {
        it1 = counts.begin();
        it2 = (*it1).begin();

        objects[i].c--;
        it1 = objects[i].a;
        it2 = objects[i].b;
        list<int>::iterator it3 = it1->end();

        --it1;
        list<list<int> >::iterator it4 = it1;
        ++it1;

        list<int>::iterator it5 = it4->end();
        bool single = false,gap = false,neighbour = false;
        --it5;
        if(objects[(*it5)].c ==objects[i].c)
        {
            neighbour = true;
            gap = false;
        }
        else
        {
            gap = true;
            neighbour = false;
        }
        ++it5;


        --it3;
        if((it2==it3)&&(it2==it1->begin()))
        {
            single = true;
        }
        else
        {
            single = false;
        }
        ++it3;

        if(single)
        {
            it2 = it1->erase(it2);
            it1 = counts.erase(it1);
            it4->push_back(i);
            it5 = it4->end();
            --it5;
            objects[i].a = it4;
            objects[i].b = it5;
            return;
        }
        else
        {
            if(neighbour)
            {
                it2 = it1->erase(it2);
                it4->push_back(i);
                it5 = it4->end();
                --it5;
                objects[i].a = it4;
                objects[i].b = it5;
                return;
            }
            else
            {
                it2 = it1->erase(it2);
                list<int> temp;
                temp.push_back(i);
                counts.insert(it1,temp);
                --it1;
                it2 = it1->end();
                --it2;
                objects[i].a = it1;
                objects[i].b = it2;
                return;
            }
        }
    }
    void reset(int i)
    {
        objects[i].c = 0;
        it1 = objects[i].a;
        it2 = objects[i].b;
        list<int>::iterator it3 = it1->end();

        --it3;
        if((it2==it3)&&(it2==it1->begin()))
        {
            it2 = it1->erase(it2);
            it1 = counts.erase(it1);
            it1 = counts.begin();
            it2 = it1->end();
            --it2;
            objects[i].a = it1;
            objects[i].b = it2;
            return;
        }
        else
        {
            it2 = it1->erase(it2);
            it1 = counts.begin();
            it2 = it1->end();
            --it2;
            objects[i].a = it1;
            objects[i].b = it2;
            return;
        }
    }
    int count(int i)
    {
        return objects[i].c;
    }
    int findMax()
    {
        it1 = counts.end();
        --it1;
        it2 = it1->end();
        --it2;
        return objects[(*it2)].c;
    }
    int numMax()
    {
        int num=0;
        it1 = counts.end();
        --it1;
        it2 = it1->begin();
        while(it2!=(it1->end()))
        {
            ++num;
            ++it2;
        }
        return num;
    }
    void printMax()
    {
        it1 = counts.end();
        --it1;
        it2 = it1->begin();
        while(it2!=(it1->end()))
        {
            cout<<*(objects[(*it2)].b)<<endl;
            ++it2;
        }
        return;
    }
};
