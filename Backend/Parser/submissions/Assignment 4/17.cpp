#include<iostream>
#include<vector>
#include<list>
using namespace std;

class count_all
{
    int n;
    vector<int> a;
    vector<list<int> ::iterator> sub;
    list<list<int> > count_ListAll;
    vector<list<list<int> > ::iterator> main;

public:
    count_all(int m)
    {
        n=m;
        list<list<int> >::iterator it0;
        list<int>::iterator it1;
        it0=count_ListAll.begin();
        list<int> l;
        for(int i=0;i<n;i++)
        {
            a.push_back(0);
            l.push_back(0);
            sub[i]=--l.end();
        }
        count_ListAll.push_back(l);
        main.push_back(count_ListAll.begin());
    }


public:
    void increment(int i)
    {

        (*main[i]).erase(sub[i]);
        main[i]++;
        if(main[i]!=count_ListAll.end())
        {
            int j=*((*main[i]).begin());
            if(a[j]==a[i]+1)
            {
                (*main[i]).push_back(i);
                sub[i]=--((*main[i]).end());
            }
            else
            {
                list<int>new_list;
                new_list.push_back(i);
                sub[i]=new_list.begin();
                count_ListAll.insert(main[i],new_list);
                main[i]--;
            }
        }
        else
        {
            list<int>new_list;
            new_list.push_back(i);
            sub[i]=new_list.begin();
            count_ListAll.push_back(new_list);

        }
    };
    void decrement(int i)
    {
        a[i] -= 1;
    };
    void reset(int i)
    {
        a[i] = 0;
    };
    int count(int i)
    {
        return a[i];
    };
    int findMax()
    {
        int k = a[i];
        return count_all[k];
    };
    int numMax()
    {
        int k = a[i];
        return count_all[k];
    };
    void printMax()
    {
        
    };
};









int main()
{



    return 0;
}

