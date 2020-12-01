#include<iostream>
#include<vector>
#include<list>
using namespace std;
class position
{
    friend class counter;
    list< list<int> > :: iterator itlist;
    list<int>:: iterator inlist;
    int countn;
};
class counter
{
    list< list<int> > A;
    list< list<int> > :: iterator it1,it2,it3,it4;
    list<int> :: iterator iter1,iter2;
    list< list<int> > :: iterator itlistp,itlistk,itlists;
    vector<position> pos;
    int n;
public:
    counter(int p)
    {
        n=p;
        list<int> a;
        for(int i=0; i<n; i++)
        {
            a.push_back(i);
        }
        A.push_back(a);
        it1=A.begin();
        iter1=(*it1).begin();
        pos.resize(n);
        for(int i=0; i<n; i++)
        {
            pos[i].countn=0;
            pos[i].itlist=it1;
            pos[i].inlist=iter1;
            iter1++;
        }
    }
    void increment(int i)
    {
        it2=pos[i].itlist;
        if(it2==A.begin())
        {
            list<int> a;
            A.insert(A.begin(),a);
        }
        else
        {
            int q=pos[i].countn;
            itlistk=it2;
            itlistp=it2;
            itlistp--;
            iter2=(*(itlistp)).begin();
            int r=pos[(*(iter2))].countn;
            if(q!=r-1)
            {
                list<int> a;
                A.insert(it2,a);
            }
        }
        pos[i].itlist--;
        (*(pos[i].itlist)).push_back(i);
        iter1=pos[i].inlist;
        pos[i].inlist=(*(pos[i].itlist)).end();
        pos[i].inlist--;
        pos[i].countn++;
        if((*(it2)).size()==1)
        {
            A.erase(it2);
        }
        else
        {
            ((*(it2)).remove(*iter1));
        }
    };
    void decrement(int i)
    {
        it3=pos[i].itlist;
        it3++;
        if(it3==A.end())
        {
            list<int> a;
            A.insert(it3,a);
            it3--;
        }
        else
        {
            it3--;
            int q=pos[i].countn;
            itlistk=it3;
            itlists=it3;
            itlists++;
            iter2=(*(itlists)).begin();
            int r=pos[(*(iter2))].countn;
            if(q!=r+1)
            {
                it3++;
                list<int> a;
                A.insert(it3,a);
                it3--;
            }
        }
        pos[i].itlist++;
        (*(pos[i].itlist)).push_back(i);
        iter1=pos[i].inlist;
        pos[i].inlist=(*(pos[i].itlist)).end();
        pos[i].inlist--;
        pos[i].countn--;
        it3=pos[i].itlist;
        it3--;
        if((*(it3)).size()==1)
        {
            A.erase(it3);
        }
        else
        {
            ((*(it3)).remove(*iter1));
        }
    };
    void reset(int i)
    {
        it4=pos[i].itlist;
        itlists=A.end();
        itlists--;
        iter2=((*itlists).begin());
        int r=pos[(*(iter2))].countn;
        if(r!=0)
        {
            list<int> a;
            A.insert(A.end(),a);
            itlists++;
        }
        pos[i].itlist=itlists;
        (*(pos[i].itlist)).push_back(i);
        pos[i].inlist=(*(pos[i].itlist)).end();
        pos[i].inlist--;
        pos[i].countn=0;
        if((*(it4)).size()==1)
        {
            A.erase(it4);
        }
        else
        {
            ((*(it4)).remove(*iter1));
        }
    };
    int count(int i)
    {
        return pos[i].countn;
    };
    int findMax()
    {
        it1=A.begin();
        iter1=(*it1).begin();
        int r=pos[*(iter1)].countn;
        return r;
    };
    int numMax()
    {
        it1=A.begin();
        int r = (*it1).size();
        return r;
    };
    void printMax()
    {
        it1=A.begin();
        iter1=(*it1).begin();
        for(; iter1!=((*it1).end()); iter1++)
        {
            cout<<(*iter1)<<endl;
        }
    };
};

