#include<iostream>
#include<vector>
#include<list>
using namespace std;

class counter
{


    int number;
    vector< int > counts;
    list< list <int> > data;
    vector< list< list<int> >::iterator > iterators;
    vector<list<int>::iterator > position;

public :

    counter(int n)
    {
        number = n;
        counts.resize(number,0);
        list<int> temp;
        for(int i=0 ; i<number; i++)
        {
            temp.push_back(i);
        }
        data.push_back(temp);
        list< list<int> >::iterator temp_iterator=data.begin();
        for(int i=0; i<number; i++)
        {
            iterators.push_back(temp_iterator);
        }
        list<int>::iterator temp_position = (*(data.begin())).begin();
        for(int i=0; i<number; i++)
        {
            position.push_back(temp_position);
            temp_position++;
        }
    }

    void increment(int i)
    {
        counts[i]++;
        list<list <int> >::iterator last = data.end();
        last--;
        if(last != iterators[i])
        {
            iterators[i]++;
            if(counts[i] == counts[(*(*(iterators[i])).begin())])
            {
                iterators[i]--;
                list<int>::iterator t_1;
                t_1 = position[i];
                (*(iterators[i])).erase(t_1);
                iterators[i]++;
                (*(iterators[i])).push_back(i);
                list<int>::iterator temp = (*iterators[i]).end();
                temp--;
                position[i] = temp;
                iterators[i]--;
                if((*iterators[i]).empty())
                {
                    list<list<int> >::iterator t_i = iterators[i];
                    iterators[i]++;
                    data.erase(t_i);
                }
                else
                {
                    iterators[i]++;
                }

            }

            else
            {
                list<int> temp_list;
                temp_list.push_back(i);
                data.insert(iterators[i],temp_list);
                iterators[i]--;
                iterators[i]--;
                (*iterators[i]).erase(position[i]);
                iterators[i]++;
                list<int>::iterator temp = (*iterators[i]).end();
                temp--;
                position[i] = temp;
                iterators[i]--;
                if((*(iterators[i])).empty())
                {
                    iterators[i] = data.erase(iterators[i]);
                }
                else
                {
                    iterators[i]++;
                }
            }
        }
        else
        {
            list<int> temp_list;
            temp_list.push_back(i);
            data.push_back(temp_list);
            (*iterators[i]).erase(position[i]);
            if((*(iterators[i])).empty())
            {
                iterators[i] = data.erase(iterators[i]);
            }
            else
            {
                iterators[i]++;
            }
            list<int>::iterator temp = (*iterators[i]).end();
            temp--;
            position[i] = temp;
        }

    }

    void decrement(int i)
    {
        counts[i]--;
        list<list <int> >::iterator first = data.begin();
        if(first != iterators[i])
        {
            iterators[i]--;
            if(counts[i] == counts[(*(*(iterators[i])).begin())])
            {
                iterators[i]++;
                list<int>::iterator t_1;
                t_1 = position[i];
                (*(iterators[i])).erase(t_1);
                iterators[i]--;
                (*(iterators[i])).push_back(i);
                list<int>::iterator temp = (*iterators[i]).end();
                temp--;
                position[i] = temp;
                iterators[i]++;
                if((*iterators[i]).empty())
                {
                    list<list<int> >::iterator t_i = iterators[i];
                    iterators[i]--;
                    data.erase(t_i);
                }
                else
                {
                    iterators[i]--;
                }

            }

            else
            {
                list<int> temp_list;
                temp_list.push_back(i);
                iterators[i]++;
                data.insert(iterators[i],temp_list);
                (*iterators[i]).erase(position[i]);
                iterators[i]--;
                list<int>::iterator temp = (*iterators[i]).end();
                temp--;
                position[i] = temp;
                iterators[i]++;
                if((*(iterators[i])).empty())
                {
                    iterators[i] = data.erase(iterators[i]);
                    iterators[i]--;
                }
                else
                {
                    iterators[i]--;
                }
            }
        }
        else
        {
            list<int> temp_list;
            temp_list.push_back(i);
            data.push_front(temp_list);
            (*iterators[i]).erase(position[i]);
            if((*(iterators[i])).empty())
            {
                iterators[i] = data.erase(iterators[i]);
                iterators[i]--;
            }
            else
            {
                iterators[i]--;
            }
            list<int>::iterator temp = (*iterators[i]).end();
            temp--;
            position[i] = temp;
        }
    }

    void reset(int i)
    {
        counts[i]=0;
        list<list <int> >::iterator first = data.begin();
        if(counts[(*(*(first)).begin())]==0)
        {

            list<int>::iterator t_1;
            t_1 = position[i];
            (*(iterators[i])).erase(t_1);
            (*(first)).push_back(i);
            list<int>::iterator temp = (*first).end();
            temp--;
            position[i] = temp;
            if((*iterators[i]).empty())
            {
                list<list<int> >::iterator t_i = iterators[i];
                data.erase(t_i);
            }
            iterators[i]=first;
        }

        else
        {
            list<int> temp_list;
            temp_list.push_back(i);
            data.push_front(temp_list);
            (*iterators[i]).erase(position[i]);
            if((*(iterators[i])).empty())
            {
                iterators[i] = data.erase(iterators[i]);
            }
            list<int>::iterator temp = (*(data).begin()).begin();
            position[i] = temp;
            iterators[i]=data.begin();
        }
    }

    int count(int i)
    {
        return counts[i];
    }

    int findMax()
    {
        return counts[*((*(--data.end())).begin())];
    }

    int numMax()
    {
        int length;
        length = (*(--data.end())).size();
        return length;
    }

    void printMax()
    {
        int length;
        list<list<int> >:: iterator last= data.end();
        last--;
        length = (*last).size();
        list<list<int> >::iterator temp_it = data.end();
        temp_it--;
        list<int>::iterator index = ((*(temp_it)).begin());
        for(int i=0; i<length; i++)
        {
            cout<<(*index)<<endl;
            index++;
        }
    }

};
