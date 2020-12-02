#include<iostream>
#include<list>
#include<vector>
using namespace std;
class counter
{
    public:
    list<list<int> > l_o_l;
    vector<int> counts;
    vector<list<list<int> >::iterator > losc;
    vector<int> position;
    counter(int n)
    {
        position.resize(n);
        for(int i=0;i<n;i++)
        {
            position[i]=i;
        }
        counts.resize(n);


        for(int i=0;i<n;i++)
        {
            counts[i]=0;
        }
        list<int> l1;
        for(int i=0;i<n;i++)
        {
            l1.push_back(i);
        }
        l_o_l.push_back(l1);
        losc.resize(n);
        for(int i=0;i<n;i++)
        {
            losc[i]=l_o_l.begin();
        }
    }
    void increment(int i)
    {
        int j=position[i];

        if((losc[i])==--l_o_l.end())
        {
            position[i]=0;
            list<int> temp;
            temp.push_back(i);
            l_o_l.push_back(temp);
            counts[i]++;

        }
        else
        {
            if(counts[*((*(++losc[i])).begin())]-counts[i]!=1)
            {
                list<int> temp;
                temp.push_back(i);
                l_o_l.insert(losc[i],temp);
                position[i]=0;
                counts[i]++;
                losc[i]=losc[i]--;
            }
            else
            {
                (*(++losc[i])).push_back(i);
                counts[i]++;
                position[i]=(*(losc[i])).size()-1;
            }
        }
        losc[i]--;
        list<int>::iterator it;

        it=(*losc[i]).begin();
        advance(it,j);

       (*(losc[i])).erase(it);

        if((*(losc[i])).empty())
        {
            list<list<int> >::iterator itr;
            itr=losc[i];
            l_o_l.erase(losc[i]);
            losc[i]=++itr;

        }
        return;
    }
    void decrement(int i)
    {
        int j=position[i];
        if((losc[i])==l_o_l.begin())
        {
            position[i]=0;
            list<int> temp;
            temp.push_back(i);
            l_o_l.insert(losc[i],temp);
            counts[i]--;
            (losc[i])==l_o_l.begin();
        }
        else
        {
            losc[i]--;
            if(counts[i]-counts[*((*(losc[i])).begin())]!=1)
            {
                losc[i]++;
                list<int> temp;
                temp.push_back(i);
                l_o_l.insert(losc[i],temp);
                position[i]=0;
                counts[i]--;
                losc[i]--;
            }
            else
            {
                (*(losc[i])).push_back(i);
                counts[i]--;
                position[i]=(*(losc[i])).size()-1;
            }
        }
        list<int>::iterator it;
        it=(*(++losc[i])).begin();
        advance(it,j);
        (*(losc[i])).erase(it);
        if((*(losc[i])).empty())
        {
            list<list<int> >::iterator itr;
            itr=losc[i];
            l_o_l.erase(losc[i]);
            losc[i]=--itr;
        }
        return;
    }
    void reset(int i)
    {
        int j=position[i];
        if(counts[(*(*(l_o_l.begin())).begin())]==0)
        {
            (*(l_o_l.begin())).push_back(i);
            position[i]=(*(l_o_l.begin())).size()-1;
        }
        else
        {
            list<int> temp;
            temp.push_back(i);
            l_o_l.insert(l_o_l.begin(),temp);
            position[i]=0;
        }
        list<int>::iterator it;
        it=(*(losc[i])).begin();
        advance(it,j);
        (*(losc[i])).erase(it);
        if((*(losc[i])).empty())
        {
            l_o_l.erase(losc[i]);
        }
        losc[i]=l_o_l.begin();
        counts[i]=0;
        return;
    }
    int count(int i)
    {
        return counts[i];
    }
    int findMax()
    {
        int maxi=counts[(*(*(l_o_l.end())).begin())];
        return maxi;
    }
    int numMax()
    {
        int numMax=(*(l_o_l.end())).size();
        return numMax;
    }
    void printMax()
    {

        list<int>::iterator itera;

        for(itera=((*(l_o_l.end())).begin());itera!=((*(l_o_l.end())).end());itera++)
        {
            cout<<*itera<<endl;

        }
        return;
    }


};

