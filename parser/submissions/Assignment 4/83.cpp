#include<iostream>
#include<vector>
#include<list>

using namespace std;

class counter
{
private :
    int n;
    vector<int> mainlist_count;
    vector<list<list <int> >::iterator> mainlist_iterator;
    list<list <int> > superlist;
    list<int> newlist;
    list<int>::iterator newit;

public :
    counter(int N)
    {
        if(n<1)
        {
            cout<<"Error : Number of objects should be greater than or equal to 1"<<endl;
        }
        else
        {
            n = N;
            mainlist_count.assign(n,0);

            newlist.clear();
            for(int i=0; i<n; i++)
            {
                newlist.push_back(i);
            }

            superlist.clear();
            superlist.push_back(newlist);

            for(int i=0; i<n; i++)
            {
                mainlist_iterator.push_back(superlist.begin());
            }
        }
    }

    void increment(int i)
    {
        if(i<0 || i>n)
        {
            return ;
        }
        if(mainlist_iterator[i]==--superlist.end())
        {
            ++superlist.end();
            mainlist_count[i]++;
            (mainlist_iterator[i])->remove(i);

            newlist.clear();
            newlist.push_back(i);

            superlist.push_back(newlist);
           if((mainlist_iterator[i])->empty())
            {
               mainlist_iterator[i] = superlist.erase(mainlist_iterator[i]);
            }
            else
            {
                mainlist_iterator[i]++;
            }
        }
        else
        {
            ++superlist.end();
            mainlist_count[i]++;

            (mainlist_iterator[i])->remove(i);

            if((mainlist_count[(++mainlist_iterator[i])->front()])!=(mainlist_count[i]))
            {
                newlist.clear();
                newlist.push_back(i);
                superlist.insert(mainlist_iterator[i],newlist);
                --mainlist_iterator[i];
            }
            else
            {
                (mainlist_iterator[i])->push_back(i);
            }

            if((--mainlist_iterator[i])->empty())
            {
                mainlist_iterator[i] = superlist.erase(mainlist_iterator[i]);
            }
            else{mainlist_iterator[i]++; }
        }
    }

    void decrement(int i)
    {
        if(i<0 || i>n)
        {
            return ;
        }

            mainlist_count[i]--;

        if(mainlist_iterator[i]==superlist.begin())
        {
            (mainlist_iterator[i])->remove(i);

            newlist.clear();
            newlist.push_back(i);

            superlist.push_front(newlist);
            mainlist_iterator[i] = superlist.begin();

            if((++mainlist_iterator[i])->empty())
            {
                mainlist_iterator[i]=superlist.erase(mainlist_iterator[i]);
            }
            mainlist_iterator[i] = superlist.begin();

        }
        else
        {
           (mainlist_iterator[i])->remove(i);

           if((mainlist_count[(--mainlist_iterator[i])->front()])!=(mainlist_count[i]))
            {
                newlist.clear();
                newlist.push_back(i);
                ++mainlist_iterator[i];
                superlist.insert(mainlist_iterator[i],newlist);
                --mainlist_iterator[i];
            }
            else
            {
                (mainlist_iterator[i])->push_back(i);
            }
            if((++mainlist_iterator[i])->empty())
            {
                mainlist_iterator[i]=superlist.erase(mainlist_iterator[i]);
            }
            --mainlist_iterator[i];

        }
    }

    void reset(int i)
    {
        if(i<0 || i>n)
        {
            return ;
        }

        mainlist_count[i]=0;
        (mainlist_iterator[i])->remove(i);

        if((mainlist_iterator[i])->empty())
        {
            mainlist_iterator[i] = superlist.erase(mainlist_iterator[i]);
        }

        if((mainlist_count[(superlist.front()).front()])!=(mainlist_count[i]))
        {
            newlist.clear();
            newlist.push_back(i);
            superlist.push_front(newlist);
            mainlist_iterator[i] = superlist.begin();

        }
        else
        {
            (superlist.begin())->push_back(i);
            mainlist_iterator[i] = superlist.begin();
        }
    }

    int count(int i)
    {
        if(i<0 || i>n)
        {
            return -1;
        }
        else
        {
            return mainlist_count[i];
        }
    }

    int findMax()
    {
        return mainlist_count[(superlist.back()).front()];
    }

    int numMax()
    {
        return ((superlist.back()).size());
    }

    void printMax()
    {
        for(newit = (superlist.back()).begin(); newit != (superlist.back()).end(); newit++)
        {
            cout<<*newit<<endl;
        }
    }
};

