#include<iostream>
#include<vector>
#include<list>

using namespace std;

class counter
{


    int number;
    vector< int > counts;
    list< list <int> > main_list;
    vector< list< list<int> >::iterator > iterators_of_list;
    vector<list<int>::iterator > iterator_of_object;

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

        main_list.push_back(temp);

        list< list<int> >::iterator temp_iterator=main_list.begin();

        for(int i=0; i<number; i++)
        {
            iterators_of_list.push_back(temp_iterator);
        }

        list<int>::iterator temp_iterator_of_object = (*(main_list.begin())).begin();

        for(int i=0; i<number; i++)
        {
            iterator_of_object.push_back(temp_iterator_of_object);
            temp_iterator_of_object++;
        }
    }

    void increment(int i)
    {
        counts[i]++;

        list<list <int> >::iterator last = main_list.end();
        last--;

        if(last != iterators_of_list[i])
        {
            if(counts[i] == counts[(*(*(++iterators_of_list[i])).begin())])
            {
                iterators_of_list[i]--;
                list<int>::iterator temp_1;
                temp_1 = iterator_of_object[i];
                (*(iterators_of_list[i])).erase(temp_1);
                iterators_of_list[i]++;
                (*(iterators_of_list[i])).push_back(i);
                list<int>::iterator temp = (*iterators_of_list[i]).end();
                temp--;
                iterator_of_object[i] = temp;
                iterators_of_list[i]--;
                if((*iterators_of_list[i]).empty())
                {
                    list<list<int> >::iterator temp_3 = iterators_of_list[i];
                    iterators_of_list[i]++;
                    main_list.erase(temp_3);
                }
                else
                {
                    iterators_of_list[i]++;
                }
            }

            else
            {
                list<int> temp_list;
                temp_list.push_back(i);
                main_list.insert(iterators_of_list[i],temp_list);
                iterators_of_list[i]--;
                iterators_of_list[i]--;
                (*iterators_of_list[i]).erase(iterator_of_object[i]);
                iterators_of_list[i]++;
                list<int>::iterator temporary_object_it = (*iterators_of_list[i]).end();
                temporary_object_it--;
                iterator_of_object[i] = temporary_object_it;
                iterators_of_list[i]--;
                if((*(iterators_of_list[i])).empty())
                {
                    iterators_of_list[i] = main_list.erase(iterators_of_list[i]);
                }
                else
                {
                    iterators_of_list[i]++;
                }
            }
        }
        else
        {
            list<int> temp_list;
            temp_list.push_back(i);
            main_list.push_back(temp_list);
            (*iterators_of_list[i]).erase(iterator_of_object[i]);
            if((*(iterators_of_list[i])).empty())
            {
                iterators_of_list[i] = main_list.erase(iterators_of_list[i]);
            }
            else
            {
                iterators_of_list[i]++;
            }
            list<int>::iterator temporary_object_it = (*iterators_of_list[i]).end();
            temporary_object_it--;
            iterator_of_object[i] = temporary_object_it;
        }

    }

    void decrement(int i)
    {
        counts[i]--;
        list<list <int> >::iterator starting_iterator = main_list.begin();
        if(starting_iterator != iterators_of_list[i])
        {
            iterators_of_list[i]--;
            if(counts[i] == counts[(*(*(iterators_of_list[i])).begin())])
            {
                iterators_of_list[i]++;
                list<int>::iterator temp_4;
                temp_4 = iterator_of_object[i];
                (*(iterators_of_list[i])).erase(temp_4);
                iterators_of_list[i]--;
                (*(iterators_of_list[i])).push_back(i);
                list<int>::iterator temp = (*iterators_of_list[i]).end();
                temp--;
                iterator_of_object[i] = temp;
                iterators_of_list[i]++;
                if((*iterators_of_list[i]).empty())
                {
                    list<list<int> >::iterator temp_5 = iterators_of_list[i];
                    iterators_of_list[i]--;
                    main_list.erase(temp_5);
                }
                else
                {
                    iterators_of_list[i]--;
                }
            }

            else
            {
                list<int> temp_list;
                temp_list.push_back(i);
                iterators_of_list[i]++;
                main_list.insert(iterators_of_list[i],temp_list);
                (*iterators_of_list[i]).erase(iterator_of_object[i]);
                iterators_of_list[i]--;
                list<int>::iterator temp_6 = (*iterators_of_list[i]).end();
                temp_6--;
                iterator_of_object[i] = temp_6;
                iterators_of_list[i]++;
                if((*(iterators_of_list[i])).empty())
                {
                    iterators_of_list[i] = main_list.erase(iterators_of_list[i]);
                    iterators_of_list[i]--;
                }
                else
                {
                    iterators_of_list[i]--;
                }
            }
        }
        else
        {
            list<int> temp_list;
            temp_list.push_back(i);
            main_list.push_front(temp_list);
            (*iterators_of_list[i]).erase(iterator_of_object[i]);
            if((*(iterators_of_list[i])).empty())
            {
                iterators_of_list[i] = main_list.erase(iterators_of_list[i]);
                iterators_of_list[i]--;
            }
            else
            {
                iterators_of_list[i]--;
            }
            list<int>::iterator temporary_object_it = (*iterators_of_list[i]).end();
            temporary_object_it--;
            iterator_of_object[i] = temporary_object_it;
        }
    }

    void reset(int i)
    {
        counts[i]=0;
        list<list <int> >::iterator beginning_iterator = main_list.begin();
        if(counts[(*(*(beginning_iterator)).begin())]==0)
        {

            list<int>::iterator temporary_object_it;
            temporary_object_it = iterator_of_object[i];
            (*(iterators_of_list[i])).erase(temporary_object_it);
            (*(beginning_iterator)).push_back(i);
            list<int>::iterator temp = (*beginning_iterator).end();
            temp--;
            iterator_of_object[i] = temp;


            if((*iterators_of_list[i]).empty())
            {
                list<list<int> >::iterator temp_6 = iterators_of_list[i];
                main_list.erase(temp_6);
            }
            iterators_of_list[i] = beginning_iterator;
        }

        else
        {
            list<int> temp_list;
            temp_list.push_back(i);
            main_list.push_front(temp_list);
            (*iterators_of_list[i]).erase(iterator_of_object[i]);
            if((*(iterators_of_list[i])).empty())
            {
                iterators_of_list[i] = main_list.erase(iterators_of_list[i]);
            }
            list<int>::iterator temp = (*(main_list).begin()).begin();
            iterator_of_object[i] = temp;
            iterators_of_list[i]=main_list.begin();
        }
    }




    int count(int i)
    {
        return counts[i];
    }

    int findMax()
    {
        list<list<int> >::iterator temp_7 = main_list.end();
        temp_7--;
        return counts[*((*(temp_7)).begin())];
    }

    int numMax()
    {
        int sizer;
        list<list<int> >::iterator temp_8 = main_list.end();
        temp_8--;
        sizer = (*(temp_8)).size();
        return sizer;
    }

    void printMax()
    {
        int sizer;
        list<list<int> >:: iterator last= main_list.end();
        last--;
        sizer = (*last).size();
        list<list<int> >::iterator temp_iterator = main_list.end();
        temp_iterator--;
        list<int>::iterator printer_pointer = ((*(temp_iterator)).begin());
        for(int i=0; i<sizer; i++)
        {
            cout<<(*printer_pointer)<<endl;
            printer_pointer++;
        }
    }

};



