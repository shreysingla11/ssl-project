#include<iostream>
#include<vector>
#include<list>
using namespace std;
class counter
{
public:
    int n;
    list < list<int> > mainlist;
    vector<int>A;
    vector<int>ncount;
    list < list<int> >::iterator it1;
    list < list<int> >::iterator tempit1;
    list<int>::iterator it2;
    list<int>::iterator tempit2;
    vector<list < list<int> >::iterator >Iterator1;
    vector<list<int>::iterator>Iterator2;
public:
    counter()
    {
        n=100000;
        A.assign(n,0);
        list<int>lnew;
        Iterator1.assign(n,it1);
        Iterator2.assign(n,it2);
        lnew.push_back(1);
        Iterator2[1]=lnew.begin();
        for(int i=2;i<=n;i++)
        {
        lnew.push_back(i);
        Iterator2[i]=++Iterator2[i-1];
        //cout<<i<<*Iterator2[i]<<endl;
        //cout<<*Iterator2[i];
        }
        mainlist.push_back(lnew);
        for(int i=1;i<=n;i++)
        {
        Iterator1[i]=mainlist.begin();
        }
    }
    counter(int x)
    {
        n=x;
        A.assign(n,0);
        list<int>lnew;
        Iterator1.assign(n,it1);
        Iterator2.assign(n,it2);
        for(int i=1;i<=n;i++)
        {
        lnew.push_back(i);
        Iterator2[i]=--lnew.end();
        cout<<*Iterator2[i];
        }
        mainlist.push_back(lnew);

        for(int i=1;i<=n;i++)
        {
        Iterator1[i]=mainlist.begin();
        }
    }


    void  increment(int i)
    {
        if(Iterator1[i]==--mainlist.end())
        {
        //cout<<"i";
        tempit1=Iterator1[i];
        tempit2=Iterator2[i];
        it2=tempit2;
        (*tempit1).remove(i);
        if((*tempit1).empty())
        {
        mainlist.erase(tempit1);
        }
        list<int>lnew;
        lnew.push_back(i);
        Iterator2[i]=lnew.begin();
        mainlist.push_back(lnew);
        Iterator1[i]=--mainlist.end();
        A[i]++;
        }
        else
        {
        it1=Iterator1[i];
        ++it1;
        tempit1=Iterator1[i];
        tempit2=Iterator2[i];
        (*tempit1).remove(i);
        if((*tempit1).empty())
        {
        mainlist.erase(tempit1);
        }
        if(A[(*((*it1).begin()))]==A[i]+1)
        {
        (*it1).push_back(i);
        Iterator1[i]=it1;
        Iterator2[i]=--(*it1).end();
        A[i]++;
        }
        else
        {
        list<int>lnew;
        lnew.push_back(i);
        mainlist.insert(it1,lnew);
        --it1;
        Iterator1[i]=it1;
        Iterator2[i]=--((*it1).end());
        A[i]++;
        }
        }
    }
    void decrement(int i)
    {

        if(Iterator1[i]==mainlist.begin())
        {
        //cout<<"i";
        tempit1=Iterator1[i];
        tempit2=Iterator2[i];
        it2=tempit2;
        (*tempit1).remove(i);
        if((*tempit1).empty())
        {
        mainlist.erase(tempit1);
        }
        list<int>lnew;
        lnew.push_back(i);
        Iterator2[i]=lnew.begin();
        mainlist.push_front(lnew);
        Iterator1[i]=mainlist.begin();
        A[i]--;
        }
        else
        {
        it1=Iterator1[i];
        --it1;
        tempit1=Iterator1[i];
        tempit2=Iterator2[i];
        it2=tempit2;
        (*tempit1).remove(i);
        if((*tempit1).empty())
        {
        mainlist.erase(tempit1);
        }
        if(A[(*((*it1).begin()))]==A[i]-1)
        {
        (*it1).push_back(i);
        Iterator1[i]=it1;
        Iterator2[i]=--(*it1).end();
        A[i]--;
        }
        else
        {
        list<int>lnew;
        lnew.push_back(i);
        ++it1;
        mainlist.insert(it1,lnew);
        --it1;
        Iterator1[i]=it1;
        Iterator2[i]=--((*it1).end());
        A[i]--;
        }
        }
    }
    int count(int i)
    {
        return A[i];
    }
    void reset(int i)
    {
        A[i]=0;
        //delete the Iterator 2 corresponding to it  and if now list is empty , erase Iterator1
        tempit1=Iterator1[i];
        tempit2=Iterator2[i];
        it2=tempit2;
        (*tempit1).erase(it2);
        if((*tempit1).empty())
        {
        mainlist.erase(tempit1);
        }
        Iterator1[i]=mainlist.begin();
        tempit1=Iterator1[i];
        Iterator2[i]=--((*tempit1).end());
        return;
    }
    int numMax()
    {
        tempit1=--mainlist.end();
        return ((*tempit1).size());
    }
    int findMax()
    {
        tempit1=--mainlist.end();
        tempit2=(*tempit1).begin();
        return A[*tempit2];
    }
    void printMax()
    {
    tempit1=--mainlist.end();
    for(tempit2=(*tempit1).begin();tempit2!=(*tempit1).end();tempit2++)
    {
    cout<<*tempit2;
    }
    }
};


