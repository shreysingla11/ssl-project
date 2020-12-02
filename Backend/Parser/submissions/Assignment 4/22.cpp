// program works only for non negative counts.For -ve counts behaviour is not determined.
#include<iostream>
#include<vector>
#include<list>
using namespace std;
class counter
{
    int n;
    vector<int> countervector;
public:
    vector<list<int>::iterator> object_iterator;
    vector<list< list<int> >::iterator> list_iterator;
    list<list<int> > list_of_lists;
    counter(int k)
    {
        list<int> temp;
        n=k;
        countervector.resize(n);
        object_iterator.resize(n);
        list_iterator.resize(n);
        for(int i=0; i<n; i++)
        {
            countervector[i]=0;
            temp.push_back(i);
        }
        list_of_lists.push_back(temp);
        list <int> ::iterator itr=(list_of_lists.begin())->begin();
        for(int i=0; i<n; i++)
        {
            list_iterator[i]=list_of_lists.begin();
            object_iterator[i]=itr;
            itr++;
        }
    }
    void increment(int i)
    {

        list< list<int> >::iterator temp =list_iterator[i];
        list< list<int> >::iterator temp2 =list_iterator[i];
        list<int>::iterator temp1 = object_iterator[i];
        if((++temp)==(list_of_lists.end()))
        {
            list<int> temporary;
            temporary.splice(temporary.begin(),(*list_iterator[i]),object_iterator[i]);
            list_of_lists.push_back(temporary);
            temp2 = list_iterator[i];
            list_iterator[i] = --list_of_lists.end();
            object_iterator[i] = list_iterator[i]->begin();
        }
        else
        {
            temp--;
            if(countervector[(*(++temp)).front()] == countervector[i]+1)
            {
                (*(temp)).splice(((*(temp)).end()),(*list_iterator[i]),object_iterator[i]);
                temp2 = list_iterator[i];
                list_iterator[i] = temp;
                object_iterator[i] = (--(temp->end()));
            }
            else
            {
                --temp;

                list<int> temporary;
                temporary.splice(temporary.begin(),(*list_iterator[i]),object_iterator[i]);
                temp2 = list_iterator[i];
                temp++;
                list_iterator[i] = list_of_lists.insert(temp,temporary);
                object_iterator[i] = list_iterator[i]->begin();
            }
            --temp;
        }
        if((temp2)->empty())
        {
            list_of_lists.erase(temp2);
        }
        countervector[i]++;
        return;
    }
    void decrement( int i)
    {
        list< list<int> >::iterator temp2 =list_iterator[i];
        list< list<int> >::iterator temp =list_iterator[i];
        list<int>::iterator temp1 = object_iterator[i];

        if((temp)==(list_of_lists.begin()))
        {
            list<int> temporary;
            temporary.splice(temporary.begin(),(*list_iterator[i]),object_iterator[i]);
            temp2 = list_iterator[i];
            list_of_lists.push_front(temporary);
            list_iterator[i] = list_of_lists.begin();
            object_iterator[i] = list_iterator[i]->begin();
        }
        else
        {
            if(countervector[(*(--temp)).front()] == countervector[i]-1)
            {
                (*(temp)).splice(((*(temp)).end()),(*list_iterator[i]),object_iterator[i]);
                temp2  = list_iterator[i];
                list_iterator[i] = temp;
                object_iterator[i] = (--(temp->end()));
            }
            else
            {
                list<int> temporary;
                temporary.splice(temporary.begin(),(*list_iterator[i]),object_iterator[i]);
                temp2 = list_iterator[i];
                list_iterator[i]  =  list_of_lists.insert(++temp,temporary);
                object_iterator[i] = list_iterator[i]->begin();
            }
        }
        if((temp2)->empty())
            list_of_lists.erase(temp2);

        countervector[i]--;
        return;
    }
    void reset( int i)
    {
        list< list<int> >::iterator temp2 =list_iterator[i];
        list< list<int> >::iterator temp =list_iterator[i];
        list<int>::iterator temp1 = object_iterator[i];
        if(countervector[(list_of_lists.front()).front()]==0)
        {
    (list_of_lists.front()).splice((list_of_lists.front()).end(),*list_iterator[i],object_iterator[i]);
            temp2 = list_iterator[i];
            list_iterator[i] = list_of_lists.begin();
            object_iterator[i] = --list_iterator[i]->end();
        }
        else
        {
            list<int> temporary;
    temporary.splice(temporary.begin(),(*list_iterator[i]),object_iterator[i]);
              temp2 = list_iterator[i] ;
            list_of_lists.push_front(temporary);
            list_iterator[i] = list_of_lists.begin();
            object_iterator[i] = list_iterator[i]->begin();
        }
        if((temp2)->empty())
        {
            list_of_lists.erase(temp2);
        }
        countervector[i] = 0;
        return;
    }
    int count(int i)
    {
        return countervector[i];
    }
    int findMax()
    {
        return countervector[(list_of_lists.back()).front()];
    }
    int numMax()
    {
        return (list_of_lists.back()).size();
    }
    void printMax()
    {
        for(list<int>::iterator itr = ((list_of_lists.back()).begin()); itr != ((list_of_lists.back()).end()); itr++)
        {
            cout<<(*itr)<<endl;
        }
    }

};

