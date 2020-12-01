#include<iostream>
#include<list>
#include<vector>
using namespace std;
class pint
{
public:
    int pagecount;
    int value;
};
class counter
{
    int i,n;
    vector<pint*>object;
    vector<list<pint>::iterator> it;
    vector<list<pint>* >countPointer;
    list< list <pint> >pages;
    list <pint> templist;
    pint temppint;

public:
    counter(int k)
    {
        n=k;
        it.resize(n);
        pages.push_back(templist);
        pint p;
        countPointer.push_back(&(pages.front()));
        for(int i=0; i<n; i++)
        {
            (pages.front()).push_back(p);
            object.push_back (&((pages.front()).back()));
            (*(object.back())).pagecount=0;
            (*(object.back())).value=i;
            it[i]=((pages.begin())->end());
            it[i]--;
            (pages.front()).back()=*object[i];

        }

    };
    void increment(int i)
    {
        if(pages.size() == (* object[i]).pagecount + 1)
        {
            pages.push_back(templist);
            countPointer.push_back(&(pages.back()));
        }
        else {}
        (*(countPointer[(*object[i]).pagecount+1])).push_back((* object[i]));
        temppint=*object[i];
        (*(countPointer[(*object[i]).pagecount])).erase(it[i]);
        object[i]=&((*(countPointer[((temppint.pagecount)+1)])).back()) ;
        it[i]=(*(countPointer[((temppint.pagecount)+1)])).end();
        it[i]--;
        ((*object[i]).pagecount++);
    };
    void decrement(int i)
    {
        if((*object[i]).pagecount==0){return;}
        (*(countPointer[(*object[i]).pagecount-1])).push_back((* object[i]));
        temppint=*object[i];
        (*(countPointer[(*object[i]).pagecount])).erase(it[i]);
        object[i]=&((*(countPointer[((temppint.pagecount)-1)])).back()) ;
        it[i]=(*(countPointer[((temppint.pagecount)-1)])).end();
        it[i]--;
        ((*object[i]).pagecount--);
        if((pages.back()).empty())
        {
            pages.pop_back();
            countPointer.pop_back();
        }
    };
    void reset(int i)
    {
        if((*object[i]).pagecount == 0)return;
        else
        {
            (*(countPointer[0])).push_back((* object[i]));
            (*(countPointer[(*object[i]).pagecount])).erase(it[i]);
            object[i]=&((*(countPointer[0])).back()) ;
            it[i]=(*(countPointer[0])).end();
            it[i]--;
            (*object[i]).pagecount=0;
            if((pages.back()).empty())
            {
                pages.pop_back();
                countPointer.pop_back();
            }
        }
    };
   int count(int i){
          return object[i]->pagecount;
   };
   int findMax(){
        return ((countPointer.size())-1);
   };
   int numMax(){
           return (pages.back()).size();
   };
    void printMax()
    {   list<pint>::iterator iter;
        iter=(pages.back()).begin();
        for( ;iter!=(pages.back()).end();iter++){cout<<(*iter).value<<"   ";}
    };
};

