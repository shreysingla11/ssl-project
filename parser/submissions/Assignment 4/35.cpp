#include<iostream>
#include<list>
#include<vector>
using namespace std;

struct objlist
{
    int count1;
    list<int> sublist;
    objlist(int c)
    {
        count1=c;
    }
};

class counter
{
    list<objlist*> mainlist;
    list<objlist*>::iterator main_it;
    list<int>::iterator msub_it;
    vector<list<objlist*>::iterator> obj_it;
    vector<list<int>::iterator> str_it;

    public:
    counter()
    {
        int n=100000;
        obj_it.resize(n);
        str_it.resize(n);
        objlist *Ol=new objlist (0);
        mainlist.push_back(Ol);
        main_it=mainlist.begin();
        for(int i=0;i<n;i++)
        {
            (*main_it)->sublist.push_back(i);
            msub_it=(*main_it)->sublist.end();
            --msub_it;
            str_it[i]=msub_it;
        }
        for(int i=0;i<n;i++)
        {
            obj_it[i]=main_it;
        }
    }
    counter(int n)
    {
        obj_it.resize(n);
        str_it.resize(n);
        objlist *Ol=new objlist (0);
        mainlist.push_back(Ol);
        main_it=mainlist.begin();
        for(int i=0;i<n;i++)
        {
            (*main_it)->sublist.push_back(i);
            msub_it=(*main_it)->sublist.end();
            --msub_it;
            str_it[i]=msub_it;
        }
        for(int i=0;i<n;i++)
        {
            obj_it[i]=main_it;
        }
    }
    void increment(int i)
    {
        main_it=obj_it[i];
        ++main_it;
        if((*main_it)->count1!=(*obj_it[i])->count1+1)
        {
            objlist *Ol=new objlist ((*obj_it[i])->count1+1);
            mainlist.insert(main_it,Ol);
            --main_it;
        }
        (*obj_it[i])->sublist.erase(str_it[i]);
        if((*obj_it[i])->sublist.size()==0)
        {
            objlist *Od=(*obj_it[i]);
            delete Od;
            mainlist.erase(obj_it[i]);
        }
        obj_it[i]=main_it;
        (*obj_it[i])->sublist.push_back(i);
        msub_it=(*obj_it[i])->sublist.end();
        --msub_it;
        str_it[i]=msub_it;
    }
    void decrement(int i)
    {
        main_it=obj_it[i];
        --main_it;
        if((*main_it)->count1!=(*obj_it[i])->count1-1)
        {
            objlist *Ol=new objlist ((*obj_it[i])->count1-1);
            mainlist.insert(obj_it[i],Ol);
            ++main_it;
        }
        (*obj_it[i])->sublist.erase(str_it[i]);
        if((*obj_it[i])->sublist.size()==0)
        {
            objlist *Od=(*obj_it[i]);
            delete Od;
            mainlist.erase(obj_it[i]);
        }
        obj_it[i]=main_it;
        (*obj_it[i])->sublist.push_back(i);
        msub_it=(*obj_it[i])->sublist.end();
        --msub_it;
        str_it[i]=msub_it;
    }
    void reset(int i)
    {
        main_it=mainlist.begin();
        if((*main_it)->count1!=0)
        {
            objlist *Ol=new objlist (0);
            mainlist.insert(main_it,Ol);
            --main_it;
        }
        (*obj_it[i])->sublist.erase(str_it[i]);
        if((*obj_it[i])->sublist.size()==0)
        {
            objlist *Od=(*obj_it[i]);
            delete Od;
            mainlist.erase(obj_it[i]);
        }
        obj_it[i]=main_it;
        (*obj_it[i])->sublist.push_back(i);
        msub_it=(*obj_it[i])->sublist.end();
        --msub_it;
        str_it[i]=msub_it;
    }
    int count(int i)
    {
        return (*obj_it[i])->count1;
    }
    int findMax()
    {
        main_it=mainlist.end();
        --main_it;
        return (*main_it)->count1;
    }
    int numMax()
    {
        main_it=mainlist.end();
        --main_it;
        return (*main_it)->sublist.size();
    }
    void printMax()
    {
        main_it=mainlist.end();
        --main_it;
        for(msub_it=(*main_it)->sublist.begin();msub_it!=(*main_it)->sublist.end();++msub_it)
        {
        cout<<*msub_it<<" ";
        }
    }
};
