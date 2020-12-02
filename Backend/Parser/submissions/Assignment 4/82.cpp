#include<iostream>
#include<vector>
#include<list>
using namespace std;
class counter
{
    vector<int> v;
    vector<list<list<int> >::iterator> vit1;
    vector<list<int>::iterator> vit2;
    list<list<int> > l;


public:
    //constructor
    counter(int n)
    {
        int i=0;
        v.resize(n,0);
        list<int> local(n);
        for(list<int>::iterator it=local.begin(); it!=local.end(); it++ , i++)
        {
            *it=i;
        }
        l.push_back(local);
        list<list<int> >::iterator localit1=l.begin();
        vit1.resize(n,localit1);
        vit2.resize(n);
        list<int>::iterator localit2=localit1->begin();
        for(int i=0; i<n; i++)
        {
            vit2[i]=localit2;
            localit2++;

        }
    }

    void increment(int i)
    {
        list<int> dummy(1,i);
        list<list<int> >::iterator copyofvit1i=vit1[i];
        (*vit1[i]).remove(*(vit2[i]));
        list<list<int> >::iterator it1=l.end();
        if(vit1[i]!=(--it1))
        {

            if(v[((*(++(vit1[i]))).front())]==(v[i]+1))
            {
                (*vit1[i]).push_back(i);
                list<int>::iterator it2;
                it2=(*vit1[i]).end();
                vit2[i]=--it2;
            }
            else
            {
                l.insert(vit1[i],dummy);
                vit1[i]--;
                vit2[i]=(vit1[i])->begin();
            }
        }
        else
        {
            l.push_back(dummy);
            vit1[i]++;
            vit2[i]=(vit1[i])->begin();
        }
        v[i]=v[i]+1;
        if((*copyofvit1i).size()==0)
        {
            l.erase((copyofvit1i));
        }
        return;

    }
    void decrement(int i)
    {
        list<int> dummy(1,i);
        list<list<int> >::iterator copyofvit1i=vit1[i];
        (*vit1[i]).remove(*(vit2[i]));
        list<list<int> >::iterator it1=l.begin();
        if(vit1[i]!=it1)
        {

            if(v[((*(--(vit1[i]))).front())]==(v[i]-1))
            {
                (*vit1[i]).push_back(i);
                list<int>::iterator it2;
                it2=(*vit1[i]).end();
                vit2[i]=--it2;
            }
            else
            {
                l.insert((++(vit1[i])),dummy);
                vit1[i]--;
                vit2[i]=(vit1[i])->begin();
            }
        }
        else
        {
            l.push_front(dummy);
            vit1[i]--;
            vit2[i]=(vit1[i])->begin();
        }
        v[i]=v[i]-1;
        if((*copyofvit1i).size()==0)
        {
            l.erase((copyofvit1i));
        }
        return;
    }
    void reset(int i)
    {
        list<int> dummy(1,i);
        list<list<int> >::iterator copyofvit1i=vit1[i];
        (*vit1[i]).remove((*vit2[i]));
        v[i]=0;
        if(v[(l.front()).front()]==0)
        {
            vit1[i]=l.begin();
            (l.begin())->push_back(1);
            list<int>::iterator it2=(*vit1[i]).end();
            vit2[i]=--it2;
        }
        else
        {
            l.insert(l.begin(),dummy);
            vit1[i]=l.begin();
            vit2[i]=vit1[i]->begin();
        }
        v[i]=0;
        if((*copyofvit1i).size()==0)
        {
            l.erase((copyofvit1i));
        }
        return;
    }
    int count(int i)
    {
        return v[i];
    }
    int findMax()
    {
        return v[(l.back()).front()];
    }
    int numMax()
    {
        return (l.back()).size();
    }
    void printMax()
    {
        for (list<int>::iterator it=((l.back()).begin()) ; it!=(l.back()).end(); it++)
        {
            cout<<*it<<endl;
        }
    }

};
