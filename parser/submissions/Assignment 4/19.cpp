#include <iostream>
#include <vector>
#include <list>
using namespace std;
class object
{   public:
    list<list<int> >::iterator it1;
    list<int>::iterator it2;
    int count;

};

class counter
{

     list<list<int> > l;
	 vector<object> v;

public:
 counter(int n)
    {
        list<int> t(n);
        list<int> :: iterator r = t.begin();
        for(int i = 0; i<n; i++,r++)
        {
            *r = i;
        }
        l.push_back(t);
        list<list<int> > :: iterator i1 = l.begin();
        r = i1->begin();
        object o;
        for(int i = 0; i<n; i++,r++)
        {
            o.it1 = i1;
            o.it2 = r;
            o.count = 0;
            v.push_back(o);
        }
        return;
    }
void increment(int i)
{
    list<list<int> >::iterator temp=l.end();
    temp--;
    if(v[i].it1==temp)
    {
        list<int>t(1,i);
        l.push_back(t);
        (v[i].it1)->erase(v[i].it2);
		if(v[i].it1->empty())
		{
			l.erase(v[i].it1);
		}
		v[i].it1=temp;
		v[i].it2=temp->begin();
		v[i].count++;
		return;
    }
    
    list<list<int> >::iterator i1=v[i].it1;
    i1++;
    list<int>::iterator i8=i1->begin();
    
    if(v[*i8].count-v[i].count==1)
    {
    	
    	(v[i].it1)->erase(v[i].it2);
		list<list<int> >::iterator t4=v[i].it1;
    	v[i].it1++;
    	v[i].it2=(v[i].it1)->end();
    	if(t4->empty())
		{
			l.erase(t4);
		}
    	v[i].it2--;
    	v[i].count++;
    	
	}
	else
	{
		list<int>t(1,i);
		(v[i].it1)->erase(v[i].it2);
	
		list<list<int> >::iterator i2=l.insert(v[i].it1,t);
			if(v[i].it1->empty())
		{
			l.erase(v[i].it1);
		}
		v[i].it1=i2;
		v[i].it2=(v[i].it1)->begin();
		v[i].count++;
	}
	return;
}
void decrement(int i)
{
	list<list<int> >::iterator temp=l.begin();
	if(v[i].it1==temp)
	{
		list<int>t(1,i);
        l.push_back(t);
        (v[i].it1)->erase(v[i].it2);
		if(v[i].it1->empty())
		{
			l.erase(v[i].it1);
		}
		v[i].it1=temp;
		v[i].it2=temp->begin();
		v[i].count--;
		return;
	}
	list<list<int> >::iterator i1=v[i].it1;
    i1--;
    list<int>::iterator i8=i1->begin();
    if(v[*i8].count-v[i].count==-1)
    {
    	
    	(v[i].it1)->erase(v[i].it2);
		if(v[i].it1->empty())
		{
			l.erase(v[i].it1);
		}
    	v[i].it1--;
    	v[i].it2=(v[i].it1)->end();
    	v[i].it2--;
    	v[i].count--;
    	
	}
	else
	{
		list<int>t(1,i);
		(v[i].it1)->erase(v[i].it2);
		
		list<list<int> >::iterator i2=l.insert(v[i].it1,t);
		if(v[i].it1->empty())
		{
			l.erase(v[i].it1);
		}
		v[i].it1=i2;
		
		v[i].it2=(v[i].it1)->begin();
		v[i].count++;
	}
	return;
}
void reset(int i)
{
	list<list<int> >::iterator tr=l.begin();
	list<int>::iterator tp=tr->begin();
	if(v[*tp].count==0)
	{
		tr->push_back(i);
		v[i].it1->erase(v[i].it2);
		if(v[i].it1->empty())
		{
			l.erase(v[i].it1);
		}
		v[i].it1=tr;
		v[i].it2=tr->end();
		v[i].it2--;
		v[i].count=0;
		
	}
	else
	{
		list<int>t(1,i);
		l.push_front(t);
		v[i].it1->erase(v[i].it2);
		if((v[i].it1)->empty())
		{
			l.erase(v[i].it1);
		}
		v[i].it1=l.begin();
		v[i].it2=(v[i].it1)->begin();
		v[i].count=0;
		
	}
	return;
}

int count(int i)
{
	return v[i].count;
}

int findMax()
{
	list<list<int> >::iterator i=l.end();
	i--;
	list<int>::iterator j=i->begin();
	return v[*j].count;
}

int numMax()
{
	list<list<int> >::iterator i=l.end();
	i--;
	return i->size();
}

void printMax()
{
	list<list<int> >::iterator i=l.end();
	i--;
	list<int>::iterator j=i->begin();
	for(;j!=i->end();j++)
	{
		cout<<*j<<endl;
	}
	return;
}
};


