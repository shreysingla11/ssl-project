#include<iostream>
#include<vector>
#include<list>

using namespace std;

struct in_list{
    int num;
    list<int> child;
};
struct in_main_vec{
    int count1;
    list<int>::iterator it;
    list<in_list>::iterator begin_it;
};
class counter
{
    int n,maximum;
    vector<in_main_vec> main_vec;
    list<in_list> parent;
    list<in_list>::iterator zero;

    public:
    counter(int m)
    {
        n=m;
        maximum=0;
        main_vec.resize(n);
        in_list temp_child; temp_child.num=0;

        in_main_vec temp_main_vec; temp_main_vec.count1=0;
        parent.push_back(temp_child);
        for(int i=0;i<n;i++)
        {
            main_vec[i].begin_it=parent.begin();
        }
        for(int i=0;i<n;i++)
        {
            main_vec[i].it=(*parent.begin()).child.insert((*parent.begin()).child.end(),i);
            main_vec[i].count1=0;
        }
        zero=parent.begin();


    }

    void increment(int i)
    {
        if(i<n)
        {

            list<int>::iterator tempit1=((*(main_vec[i].begin_it)).child).erase(main_vec[i].it);


            list<in_list>::iterator temp_begin_it = main_vec[i].begin_it;

            if(main_vec[i].begin_it!=(--parent.end()))
            {
                (main_vec[i].begin_it)++;
            }
            if((*(main_vec[i].begin_it)).num==(main_vec[i].count1+1))
            {
               main_vec[i].it=((*main_vec[i].begin_it).child).insert(((*main_vec[i].begin_it).child).end(),i);
            }
            else
            {
                in_list temp_in_list; temp_in_list.num=main_vec[i].count1 + 1;
                main_vec[i].begin_it=parent.insert(++temp_begin_it,temp_in_list);
                (*(main_vec[i].begin_it)).num = main_vec[i].count1 + 1;
                main_vec[i].it=(*main_vec[i].begin_it).child.insert((*main_vec[i].begin_it).child.end(),i);
            }
            (main_vec[i].count1)++;
            temp_begin_it--;
            temp_begin_it--;
            if( (*(temp_begin_it)).child.empty() )
            {
                parent.erase(temp_begin_it);
            }
        }
    }
    void decrement(int i)
    {
        if(i<n)
        {

            ((*main_vec[i].begin_it).child).erase(main_vec[i].it);

            list<in_list>::iterator temp_begin_it = main_vec[i].begin_it;

            if(main_vec[i].begin_it!=parent.begin())
                main_vec[i].begin_it--;

            if((*main_vec[i].begin_it).num==main_vec[i].count1-1)
            {
               main_vec[i].it=((*main_vec[i].begin_it).child).insert(((*main_vec[i].begin_it).child).end(),i);
            }
            else
            {
                in_list temp_in_list; temp_in_list.num=main_vec[i].count1-1;
                    main_vec[i].begin_it=parent.insert(temp_begin_it,temp_in_list);
                (*(main_vec[i].begin_it)).num = main_vec[i].count1 - 1;

                main_vec[i].it=(*main_vec[i].begin_it).child.insert((*main_vec[i].begin_it).child.end(),i);
            }

            (main_vec[i].count1)--;
            if((*temp_begin_it).child.empty())
            {
                parent.erase(temp_begin_it);
            }
        }
    }

    void reset(int i)
    {
        if(main_vec[i].count1!=0)
        {
            ((*main_vec[i].begin_it).child).erase(main_vec[i].it);

            main_vec[i].count1=0;
            list<in_list>::iterator temp_begin_it = main_vec[i].begin_it;
            if((*temp_begin_it).child.empty())
            {
                parent.erase(temp_begin_it);
            }
            main_vec[i].begin_it=zero;
            main_vec[i].it=((*main_vec[i].begin_it).child).insert(((*main_vec[i].begin_it).child).end(),i);
        }
    }

    int count(int i)
    {
        return main_vec[i].count1;
    }

    int findMax()
    {
        list<in_list>::iterator temp_begin_it=parent.end();
        temp_begin_it--;
        return (*temp_begin_it).num;
    }

    int numMax()
    {
        list<in_list>::iterator temp_begin_it=parent.end();
        temp_begin_it--;
        return (*temp_begin_it).child.size();
    }

    void printMax()
    {
        list<in_list>::iterator temp_begin_it=parent.end();
        temp_begin_it--;
        list<int>::iterator temp_it=(*temp_begin_it).child.begin();
        while(temp_it!=(*temp_begin_it).child.end())
        {
            cout<<*temp_it<<endl;
            temp_it++;
        }
    }

};
