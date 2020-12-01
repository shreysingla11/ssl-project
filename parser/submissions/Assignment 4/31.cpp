#include<vector>
#include<list>
#include<iostream>

using namespace std;

class main_node{
public:
    list< int > small_list;
	int count;
	main_node(){
		count =0;
	}
};
class counter
{
//Variables
    list < main_node > m_list;
    vector< list< int > :: iterator > iterator_object;
    vector< list< main_node >::iterator > iterator_list;
    list < main_node > :: iterator next(list < main_node > ::iterator i){
        return ++i;
    }
    list < main_node > :: iterator prev(list < main_node > ::iterator i){
        return --i;
    }
    list < int > :: iterator next(list < int > ::iterator i){
        return ++i;
    }
    list < int > :: iterator prev(list < int > ::iterator i){
        return --i;
    }
//Functions
    public:
    //Constructor
    counter(int n)
    {
        main_node temp;
        for(int i = 0; i < n; i++)
        {
            temp.small_list.push_back(i);
        }
        m_list.push_back(temp);

        
        list<int>::iterator temp_iterator_object = m_list.back().small_list.begin();
        for(int i = 0; i <n;i++)
        {
            iterator_object.push_back(temp_iterator_object);
			temp_iterator_object++;
        	iterator_list.push_back(m_list.begin());
        }

    }
    //Fuctions
    void increment(int i)
    {
        // data[i]++;
        list <main_node> :: iterator big_iterator = iterator_list[i];
        list <main_node> :: iterator next_big_iterator = next(big_iterator);
        list < int > :: iterator small_iterator = iterator_object[i];
        if( --m_list.end() != big_iterator) 
        {
            if( big_iterator -> count + 1 == next(big_iterator) -> count)
            {
                big_iterator->small_list.erase(small_iterator);
                if(big_iterator->small_list.empty())
                {
                    big_iterator = m_list.erase(big_iterator);
                }
                next_big_iterator->small_list.push_back(i);
                small_iterator = prev(next_big_iterator->small_list.end());
            }
            else
            {
                main_node temp;
                temp.count = big_iterator -> count + 1;
                temp.small_list.push_back(i);
                next_big_iterator = m_list.insert(next_big_iterator,temp);

                big_iterator->small_list.erase(small_iterator);
                if(big_iterator->small_list.empty())
                {
                    big_iterator = m_list.erase(big_iterator);
                }

                small_iterator = prev(next_big_iterator->small_list.end());
            }
        }
        else
        {
            main_node temp;
            temp.count = big_iterator -> count + 1;
            temp.small_list.push_back(i);
            next_big_iterator = m_list.insert(next_big_iterator,temp);

            big_iterator->small_list.erase(small_iterator);
            if(big_iterator->small_list.empty())
            {
                big_iterator = m_list.erase(big_iterator);
            }


            small_iterator = prev(next_big_iterator->small_list.end());
        }
        iterator_list[i] = next_big_iterator;
        iterator_object[i] = small_iterator;
    }
    void decrement(int i)
    {   
        list <main_node> :: iterator big_iterator = iterator_list[i];
        list <main_node> :: iterator prev_big_iterator = prev(big_iterator);
        list < int > :: iterator small_iterator = iterator_object[i];
        if( m_list.begin() != big_iterator) 
        {
            if( big_iterator -> count - 1 == prev(big_iterator) -> count)
            {
                big_iterator->small_list.erase(small_iterator);
                if(big_iterator->small_list.empty())
                {
                    big_iterator = m_list.erase(big_iterator);
                }
                prev_big_iterator->small_list.push_back(i);
                small_iterator = prev(prev_big_iterator->small_list.end());
            }
            else
            {
                main_node temp;
                temp.count = big_iterator -> count - 1;
                temp.small_list.push_back(i);
                prev_big_iterator = m_list.insert(big_iterator,temp);

                big_iterator->small_list.erase(small_iterator);
                if(big_iterator->small_list.empty())
                {
                    big_iterator = m_list.erase(big_iterator);
                }
                small_iterator = prev(prev_big_iterator->small_list.end());
            }
        }
        else
        {
            main_node temp;
            temp.count = big_iterator -> count - 1;
            temp.small_list.push_back(i);
            m_list.push_front(temp);
            prev_big_iterator = m_list.begin();
            big_iterator->small_list.erase(small_iterator);
            if(big_iterator->small_list.empty())
            {
                big_iterator = m_list.erase(big_iterator);
            }
            small_iterator = prev(prev_big_iterator->small_list.end());
        }
        iterator_list[i] = prev_big_iterator;
        iterator_object[i] = small_iterator;
    }
    void reset(int i)
    {
        list <main_node> :: iterator big_iterator = iterator_list[i];
        list <main_node> :: iterator next_big_iterator = m_list.begin();
        list < int > :: iterator small_iterator = iterator_object[i];
        if( next_big_iterator -> count == 0)
        {
            big_iterator->small_list.erase(small_iterator);
            if(big_iterator->small_list.empty())
            {
                big_iterator = m_list.erase(big_iterator);
            }
            next_big_iterator->small_list.push_back(i);
            small_iterator = prev(next_big_iterator->small_list.end());
        }
        else
        {
            main_node temp;
            temp.count = 0;
            temp.small_list.push_back(i);
            m_list.push_front(temp);
            big_iterator->small_list.erase(small_iterator);
            if(big_iterator->small_list.empty())
            {
                big_iterator = m_list.erase(big_iterator);
            }


            small_iterator = prev(next_big_iterator->small_list.end());
        }
        iterator_list[i] = next_big_iterator;
        iterator_object[i] = small_iterator;
    }
    int count(int i)
    {
        list <main_node> :: iterator big_iterator = iterator_list[i];
        return big_iterator->count;
    }
    int findMax()
    {
        list <main_node> :: iterator big_iterator = prev(m_list.end());
        return big_iterator->count;
        
    }
    int numMax()
    {
        return m_list.back().small_list.size();
    }
    int printMax()
    {
        // cout<<"Print Max"<<endl;
        for(list<int>::iterator it= (m_list.back().small_list.begin());it != m_list.back().small_list.end(); it++)
        {
        	cout<<*it<<endl;
        }
        // cout<<"Print Max end"<<endl;

    }
};