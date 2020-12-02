#include<iostream>
#include<vector>
#include<list>
using namespace std;

class object
{
public:
    list<list<int> >::iterator it1;
    list<int>::iterator it2;
    int num;
};

class counter
{
    vector<object> webpagesList;
    list<list<int> > listoflists;

public:
    counter(int n)
    {
        list<int > temp(n);
        list<int>::iterator it=temp.begin();
        for(int i=0; it!=temp.end(); it++,i++)
        {
            *it=i;
        }
        listoflists.push_back(temp);
        list<list<int> >::iterator it1=listoflists.begin();
        it=it1->begin();
        for(int i=0; i<n; i++,it++)
        {
            object t;
            t.it1=it1;
            t.it2=it;
            t.num=0;
            webpagesList.push_back(t);
        }
    }
    void increment(int i)
    {
        if(webpagesList[i].it1==listoflists.begin())
        {
            list<int > temp(1,i);
            (webpagesList[i].it1)->erase(webpagesList[i].it2);
            if((webpagesList[i].it1)->empty())
            {
                listoflists.erase(webpagesList[i].it1);
            }
            listoflists.push_front(temp);
            webpagesList[i].it1=listoflists.begin();
            webpagesList[i].it2=(webpagesList[i].it1)->begin();
            webpagesList[i].num++;
            return;
        }
        list<list<int> >::iterator tempit=webpagesList[i].it1;
        tempit--;
        list<int>::iterator tempit2=tempit->begin();
        if(webpagesList[*tempit2].num==webpagesList[i].num+1)
        {
            tempit->push_front(i);
            (webpagesList[i].it1)->erase(webpagesList[i].it2);
            if((webpagesList[i].it1)->empty())
            {
                webpagesList[i].it1=listoflists.erase(webpagesList[i].it1);
            }
            webpagesList[i].it1--;
            webpagesList[i].it2=(webpagesList[i].it1)->begin();
            webpagesList[i].num++;
        }
        else
        {
            list<int > temp(1,i);
            (webpagesList[i].it1)->erase(webpagesList[i].it2);
            list<list<int> >::iterator rit=listoflists.insert(webpagesList[i].it1,temp);
            if((webpagesList[i].it1)->empty())
            {
                listoflists.erase(webpagesList[i].it1);
            }
            webpagesList[i].it1=rit;
            webpagesList[i].it2=(webpagesList[i].it1)->begin();
            webpagesList[i].num++;
        }
    }
    void decrement(int i)
    {
        list<list<int> >::iterator last=listoflists.end();
        last--;
        if(webpagesList[i].it1==last)
        {
            list<int > temp(1,i);
            (webpagesList[i].it1)->erase(webpagesList[i].it2);
            if((webpagesList[i].it1)->empty())
            {
                listoflists.erase(webpagesList[i].it1);
            }
            listoflists.push_back(temp);
            webpagesList[i].it1=listoflists.end();
            webpagesList[i].it1--;
            webpagesList[i].it2=(webpagesList[i].it1)->begin();
            webpagesList[i].num--;
            return;
        }
        list<list<int> >::iterator tempit=webpagesList[i].it1;
        tempit++;
        list<int>::iterator tempit2=tempit->begin();
        if(webpagesList[*tempit2].num==webpagesList[i].num-1)
        {
            tempit->push_front(i);
            (webpagesList[i].it1)->erase(webpagesList[i].it2);
            if((webpagesList[i].it1)->empty())
            {
                webpagesList[i].it1=listoflists.erase(webpagesList[i].it1);
            }
            else
            {
                webpagesList[i].it1++;
            }
            webpagesList[i].it2=(webpagesList[i].it1)->begin();
            webpagesList[i].num--;
        }
        else
        {
            list<int > temp(1,i);
            (webpagesList[i].it1)->erase(webpagesList[i].it2);
            list<list<int> >::iterator itemp=webpagesList[i].it1;
            itemp++;
            list<list<int> >::iterator rit=listoflists.insert(itemp,temp);
            if((webpagesList[i].it1)->empty())
            {
                listoflists.erase(webpagesList[i].it1);
            }
            webpagesList[i].it1=rit;
            webpagesList[i].it2=(webpagesList[i].it1)->begin();
            webpagesList[i].num--;
        }
    }
    void reset(int i)
    {
        list<list<int> >::iterator last=listoflists.end();
        last--;
        list<int> :: iterator s=last->begin();
        if(webpagesList[*s].num==0)
        {
            last->push_front(i);
            (webpagesList[i].it1)->erase(webpagesList[i].it2);
            if((webpagesList[i].it1)->empty())
            {
                listoflists.erase(webpagesList[i].it1);
            }
            webpagesList[i].it1=last;
            webpagesList[i].it2=(webpagesList[i].it1)->begin();
            webpagesList[i].num=0;
        }
        else
        {
            list<int> temp(1,i);
            listoflists.push_back(temp);
            (webpagesList[i].it1)->erase(webpagesList[i].it2);
            if((webpagesList[i].it1)->empty())
            {
                listoflists.erase(webpagesList[i].it1);
            }
            last++;
            webpagesList[i].it1=last;
            webpagesList[i].it2=(webpagesList[i].it1)->begin();
            webpagesList[i].num=0;
        }
    }
    int count(int i)
    {
        return webpagesList[i].num;
    }
    int findMax()
    {
        list<int >::iterator s=(listoflists.begin())->begin();
        return webpagesList[*s].num;
    }
    void printMax(){
        list<int >::iterator s=(listoflists.begin())->end();
        s--;
        for(;s!=(listoflists.begin())->begin();s--)
        {
        cout<<*s<<" ";
        }
        cout<<*s<<" ";
    }
    int numMax(){
    return (listoflists.begin())->size();
    }
};
