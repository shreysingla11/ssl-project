#include<iostream>
#include<vector>
#include<list>

using namespace std;

class counter
{
    vector< int > _count;
    list< list <int> > _main_list;
    vector< list< list<int> >::iterator > it_of_list;
    vector<list<int>::iterator > it_of_object;
public :
    counter(int n)
    {
        _count.resize(n,0);

        list<int> temp_vec;
        for(int i=0 ; i<n; i++)
            temp_vec.push_back(i);

        _main_list.push_back(temp_vec);

        for(int i=0; i<n; i++)
             it_of_list.push_back(_main_list.begin());


        list<int>::iterator temp_it_of_object = _main_list.begin()->begin();
        for(int i=0; i<n; i++)
        {
            it_of_object.push_back(temp_it_of_object);
            temp_it_of_object++;
        }
    }

   void increment(int i)
    {
        _count[i]++;
        list<list <int> >::iterator last_list = _main_list.end();
        last_list--;
        if(last_list != it_of_list[i])
        {
            it_of_list[i]++;
            if(_count[i] == _count[*(it_of_list[i]->begin())])
            {
                it_of_list[i]--;
                it_of_list[i]->erase(it_of_object[i]);
                it_of_list[i]++;
                it_of_list[i]->push_back(i);
                list<int>::iterator temp_it = it_of_list[i]->end();
                temp_it--;
                it_of_object[i] = temp_it;
                it_of_list[i]--;

                if(it_of_list[i]->empty())
                {
                    _main_list.erase(it_of_list[i]);
                }
                it_of_list[i]++;
            }
            else
            {
                list<int> temp_list;
                temp_list.push_back(i);
                _main_list.insert(it_of_list[i],temp_list);
                it_of_list[i]--;
                it_of_list[i]--;
                it_of_list[i]->erase(it_of_object[i]);
                it_of_list[i]++;
                list<int>::iterator temp_it = it_of_list[i]->end();
                temp_it--;
                it_of_object[i] = temp_it;
                it_of_list[i]--;
                if(it_of_list[i]->empty())
                {
                    it_of_list[i] = _main_list.erase(it_of_list[i]);
                }
                it_of_list[i]++;
            }
        }
        else
        {
            list<int> temp_list;
            temp_list.push_back(i);
            _main_list.push_back(temp_list);
            it_of_list[i]->erase(it_of_object[i]);
            if(it_of_list[i]->empty())
            {
                it_of_list[i] = _main_list.erase(it_of_list[i]);
            }
            else
            {
                it_of_list[i]++;
            }
            list<int>::iterator temp_it = it_of_list[i]->end();
            temp_it--;
            it_of_object[i] = temp_it;
        }

    }

    void decrement(int i)
    {
        _count[i]--;
        list<list <int> >::iterator first_list = _main_list.begin();

        if(first_list != it_of_list[i])
        {
            it_of_list[i]--;
            if(_count[i] == _count[*(it_of_list[i]->begin())])
            {
                it_of_list[i]++;
                it_of_list[i]->erase(it_of_object[i]);

                it_of_list[i]--;
                it_of_list[i]->push_back(i);
                list<int>::iterator temp_it = (*it_of_list[i]).end();
                temp_it--;
                it_of_object[i] = temp_it;
                it_of_list[i]++;
                if(it_of_list[i]->empty())
                {
                    _main_list.erase(it_of_list[i]);
                }
                    it_of_list[i]--;
            }
            else
            {
                list<int> temp_list;
                temp_list.push_back(i);
                it_of_list[i]++;
                _main_list.insert(it_of_list[i],temp_list);
                it_of_list[i]->erase(it_of_object[i]);
                it_of_list[i]--;
                list<int>::iterator temp_it = it_of_list[i]->end();
                temp_it--;
                it_of_object[i] = temp_it;
                it_of_list[i]++;
                if(it_of_list[i]->empty())
                {
                    it_of_list[i] = _main_list.erase(it_of_list[i]);
                    it_of_list[i]--;
                }
                else
                {
                    it_of_list[i]--;
                }
            }
        }
        else
        {
            list<int> temp_list;
            temp_list.push_back(i);
            _main_list.push_front(temp_list);
            it_of_list[i]->erase(it_of_object[i]);
            if(it_of_list[i]->empty())
            {
                it_of_list[i] = _main_list.erase(it_of_list[i]);
            }
            it_of_list[i]--;

            list<int>::iterator temp_it = (*it_of_list[i]).end();
            temp_it--;
            it_of_object[i] = temp_it;
        }
    }

    void reset(int i)
    {
        _count[i]=0;
            list<list <int> >::iterator first = _main_list.begin();
            if(_count[(*(*(first)).begin())]==0)
            {
                list<int>::iterator t_1;
                t_1 = it_of_object[i];
                it_of_list[i]->erase(t_1);
                (first)->push_back(i);
                list<int>::iterator temp_it = first->end();
                temp_it--;
                it_of_object[i] = temp_it;


                if(it_of_list[i]->empty())
                {
                    _main_list.erase(it_of_list[i]);
                }
                it_of_list[i]=first;
            }
            else
            {
                list<int> temp_list;
                temp_list.push_back(i);
                _main_list.push_front(temp_list);
                it_of_list[i]->erase(it_of_object[i]);
                if(it_of_list[i]->empty())
                {
                   it_of_list[i] = _main_list.erase(it_of_list[i]);
                }
                it_of_object[i] = _main_list.begin()->begin();
                it_of_list[i]=_main_list.begin();
            }
    }
    int count(int i)
    {
        return _count[i];
    }

    int findMax()
    {
        list<list<int> >:: iterator it =_main_list.end();
        it--;
        return _count[*(it->begin())];
    }

    int numMax()
    {
        list<list<int> >:: iterator it =_main_list.end();
        it--;
        return it->size();
    }

    void printMax()
    {
        list<list<int> >::iterator temp_it = _main_list.end();
        temp_it--;
        list<int>::iterator it_list ;
        for( it_list= temp_it->begin(); it_list!= temp_it->end(); it_list++)
        {
            cout<<*it_list<<endl;
        }
    }

};
