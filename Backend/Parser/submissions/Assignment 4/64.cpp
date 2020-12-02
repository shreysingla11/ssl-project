#include<iostream>
#include<list>
#include<vector>
using namespace std;

class counter
{
    private:

struct page
{
    int count;
    list< list<int> >::iterator it1;
    list<int>::iterator it2;
};
    list< list<int> > parent;
    vector<page> web;
    list< list<int> >::iterator start;
    public:
    counter(int n)
    {
        list<int> child;
       for(int i=0;i<n;i++)
     {
            child.push_back(i);
     }
        parent.push_back(child);
        list<int>::iterator temp = (*(parent.begin())).begin();
        page x;
        for(int i=0;i<n;i++)
        {
            x.count=0;
            x.it1=parent.begin();
            x.it2=temp;
            web.push_back(x);
            temp++;
        }
        start=parent.begin();
    }
    void increment(int i)
    {
        list<list<int> >::iterator temp;
        temp=parent.end();
        list< list<int> >::iterator t1;
        list< int >::iterator t2;
        t1=web[i].it1;
        t2=web[i].it2;
        temp--;
        if(t1==temp)
        {
		if((*t1).size()==1)
			web[i].count++;
		else{
            list<int>child;
            child.push_back(i);
            parent.push_back(child);
            t1++;
            (*(web[i].it1)).erase(web[i].it2);
             if((*(web[i].it1)).size()==0 && web[i].count!=0)
            {
                parent.erase(web[i].it1);
            }
            web[i].it1=t1;
            web[i].it2=(*(web[i].it1)).begin();
            web[i].count++;
	}
        }
        else
        {
          ++t1;
         if(((*t1).begin()==(*t1).end())||web[*((*t1).begin())].count==(web[i].count+1))
         {
            (*(web[i].it1)).erase(web[i].it2);
            if((*(web[i].it1)).size()==0&&web[i].count!=0)
            {
                parent.erase((web[i].it1));
            }
            web[i].it1=t1;
            (*(web[i].it1)).push_back(i);
            list<int>::iterator temp;
            temp=(*(web[i].it1)).end();
            temp--;
            web[i].it2=temp;
            web[i].count++;
         }
         else
         {
		if((*t1).size()==1)
			web[i].count++;
		else{
            list<int>child;
            child.push_back(i);
            
            (*(web[i].it1)).erase(web[i].it2);
            if((*(web[i].it1)).size()==0&&web[i].count!=0)
            {
                parent.erase((web[i].it1));
            }
            parent.insert(t1,child);
            --t1;
            web[i].it1=t1;
            web[i].it2=(*(web[i].it1)).begin();
           
            web[i].count++;
		}
         }

        }

    }
    void decrement(int i)
    {
        list<list<int> >::iterator temp;
        temp=parent.begin();
        list< list<int> >::iterator t1;
        list< int >::iterator t2;
        t1=web[i].it1;
        t2=web[i].it2;
        if(t1==temp)
        {
		if((*t1).size()==1)
			web[i].count--;
	else{
            list<int>child;
            child.push_back(i);
            parent.push_front(child);
            t1--;
            (*(web[i].it1)).erase(web[i].it2);
             if((*(web[i].it1)).size()==0 && web[i].count!=0)
            {
                parent.erase(web[i].it1);
            }
            web[i].it1=t1;
            web[i].it2=(*(web[i].it1)).begin();
            web[i].count--;}
        }
        else
        {
          --t1;
         if(web[*((*t1).begin())].count==(web[i].count-1)||((*t1).begin()==(*t1).end()))
         {
            (*(web[i].it1)).erase(web[i].it2);
            if((*(web[i].it1)).size()==0&&web[i].count!=0)
            {
                parent.erase((web[i].it1));
            }
            web[i].it1=t1;
            (*(web[i].it1)).push_back(i);
            list<int>::iterator temp;
            temp=(*(web[i].it1)).end();
            temp--;
            web[i].it2=temp;
            web[i].count--;
         }
         else
         {
		if((*t1).size()==1)
			web[i].count--;
		else{
            list<int>child;
            child.push_back(i);
            
            (*(web[i].it1)).erase(web[i].it2);
            if((*(web[i].it1)).size()==0&&web[i].count!=0)
            {
                parent.erase((web[i].it1));
            }
            ++t1;
            parent.insert(t1,child);  
            --t1;
            web[i].it1=t1;
            web[i].it2=(*(web[i].it1)).begin();
            
            web[i].count--;
         }
      		}

        }

    }
    void reset(int i)
    {
        list< list<int> >::iterator t1;
        t1=web[i].it1;
       
        (*(web[i].it1)).erase(web[i].it2);
        if((*(web[i].it1)).size()==0&&web[i].count!=0)
        {
            parent.erase((web[i].it1));
        }
        (*start).push_back(i);
        list<int>::iterator temp;
        temp=(*start).end();
        temp--;
        web[i].it1=start;
        web[i].it2=temp;
        web[i].count=0;
    }
    int count(int i)
    {
        return web[i].count;
    }
    int findMax()
    {
      list< list<int> >::iterator temp=parent.end();
      temp--;
      if((*temp).begin()==(*temp).end())
        temp--;
      list<int>tempo;
      tempo=*(temp);
      int c;
      c=*(tempo.begin());
      return web[c].count;
    }
    int numMax()
    {
      list< list<int> >::iterator temp=parent.end();
      temp--;
      list<int>tempo;
      if((*temp).begin()==(*temp).end())
        temp--;
      tempo=*(temp);
      return tempo.size();
    }
    void printMax()
    {
      list< list<int> >::iterator temp=parent.end();
      temp--;
      list<int>tempo;
      if((*temp).begin()==(*temp).end())
        temp--;
      tempo=*(temp);
      for(list<int>::iterator i=tempo.begin();i!=tempo.end();i++)
      {
        int d=*i;
        cout<<d<<" ";
      }
      cout<<endl;
    }
};

