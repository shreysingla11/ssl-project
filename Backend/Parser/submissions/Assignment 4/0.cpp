#include <iostream>
#include <list>
#include <vector>
using namespace std;
class node
{
    int i;
    int count;
    list <list<node*> > ::iterator self;
    node(int n)
    {
        i=n;
        count=0;
    }
    friend class counter;
};
class counter
{
    int n;
    list <list<node*> > A;
    vector <node*> B;
    list< list<node*> >::iterator zeroit;
public:
    counter(int n)
    {
        list <node*> firstlist;
        /*
        list <node*> ::iterator u = firstlist.begin();
        lol.push_back(u);
        */
        for(int i=0; i<n; i++)
        {
            //nodev.push_back(new node(i));
            B.push_back(new node(i) );
            firstlist.push_back(B[i]);
            B[i]->self=A.begin();
        }
        A.push_back(firstlist);
        for(int i=0; i<n; i++)
        {
            B[i]->self=A.begin();
        }
        zeroit=A.begin();
    }
    void increment(int i)
    {
        bool doit=false;
        (*(B[i]->self)).remove(B[i]);
        if((*(B[i]->self)).empty())
        {
            if(B[i]->count==0)
            {
                doit=true;
            }
            if(B[i]->self==A.begin())
            {
                A.erase(B[i]->self);
                B[i]->count++;
                list <node*> tmplist;
                tmplist.push_back(B[i]);
                A.push_front(tmplist);
                B[i]->self=A.begin();
                if(B[i]->count==0){zeroit=B[i]->self;}

            }
            else
            {

                B[i]->count++;
                list <list<node*> >::iterator bter=B[i]->self;
                list <list<node*> >::iterator gter=B[i]->self;
                if((*((*(--bter)).begin()))->count==B[i]->count)
                {
                (*(bter)).push_back(B[i]);
                B[i]->self=bter;
                }
                else
                {
                 list <node*> tmplist;
                tmplist.push_back(B[i]);
                B[i]->self=A.insert(++bter,tmplist);
                }
                A.erase(gter);
                if(B[i]->count==0){zeroit=B[i]->self;}
            }
            /*
            list <list<node*> >::iterator iter=A.begin();
            iter++;
            for(;iter!=A.end();iter++)
            {
            list<node*>jter=(*iter).begin();
            for(;jter!=(*iter).end();jter++)
            {

            }
            }
            */
            if(doit)
            {
                zeroit=B[i]->self;
            }
            return;
        }
        list <list<node*> >::iterator ite=A.begin();


        if(B[i]->self==ite)
        {
            B[i]->count++;
            list <node*> tmplist;
            tmplist.push_back(B[i]);
            A.push_front(tmplist);
            B[i]->self=A.begin();
            if(B[i]->count==0)
            {
                zeroit=B[i]->self;
            }


        }
        else
        {
            B[i]->count++;
            (B[i]->self)--;
            //(*((B[i]->self))).push_back(B[i]);

            if((*((*(B[i]->self)).begin()))->count==(B[i]->count))
            {
                (*((B[i]->self))).push_back(B[i]);
            }
            else
            {
                list <node*> tmplist;
                tmplist.push_back(B[i]);
                B[i]->self=A.insert(++B[i]->self,tmplist);
                if(B[i]->count==0)
                {
                    zeroit=B[i]->self;
                }

            }
        }
    }
    void decrement(int i)
    {
        bool doit=false;
        (*(B[i]->self)).remove(B[i]);
        if((*(B[i]->self)).empty())
        {
            if(B[i]->count==0)
            {
                doit=true;
            }
            if(B[i]->self==A.end()--)
            {
                //list<list<node*> >D=A;
                A.pop_back();
                B[i]->count--;
                list <node*> tmplist;
                tmplist.push_back(B[i]);
                A.push_back(tmplist);
                B[i]->self=A.end()--;
                if(B[i]->count==0){zeroit=B[i]->self;}
                /*
                list <list<node*> >::iterator iter=A.end()--;
                list <list<node*> >::iterator iter2=D.end()--;
                iter2--;
                iter--;
                for(; ++iter!=A.begin(); iter--,iter2--)
                {
                    iter--;
                    if((*((*iter).begin()))->count==0)
                    {
                        zeroit=iter;
                    }
                    list <node*> :: iterator iter3 = (*iter2).begin();
                    for(; iter3!=(*iter2).end(); iter3++)
                    {
                        (*iter3)->self=iter;
                    }
                }
                */
            }

            else
            {

                B[i]->count--;
                list <list<node*> >::iterator bter=B[i]->self;
                list <list<node*> >::iterator gter=B[i]->self;
                if((*((*(++bter)).begin()))->count==B[i]->count)
                {
                (*(bter)).push_back(B[i]);
                B[i]->self=bter;
                }
                else
                {
                 list <node*> tmplist;
                tmplist.push_back(B[i]);
                B[i]->self=A.insert(bter,tmplist);
                }
                A.erase(gter);
                if(B[i]->count==0){zeroit=B[i]->self;}
            }
            if(doit)
            {
                zeroit=B[i]->self;
            }
            return;
        }
        list <list<node*> >::iterator ite=A.end();
//here were the
        B[i]->count--;
        if(B[i]->self==ite--)
        {
            list <node*> tmplist;
            tmplist.push_back(B[i]);
            A.push_back(tmplist);
            B[i]->self=ite;
            if(B[i]->count==0)
            {
                zeroit=B[i]->self;
            }


        }
        else
        {
            (B[i]->self)++;
            if((*((*(B[i]->self)).begin()))->count==(B[i]->count))
            {
                (*((B[i]->self))).push_back(B[i]);
            }
            else
            {
                list <node*> tmplist;
                tmplist.push_back(B[i]);
                B[i]->self=A.insert(B[i]->self,tmplist);
                if(B[i]->count==0)
                {
                    zeroit=B[i]->self;
                }

            }

        }
    }
    void reset(int i)
    {
        list <list<node*> >::iterator ite=zeroit;
        if(B[i]->count==0)
        {
            return;
        }

        (*(B[i]->self)).remove(B[i]);

        if(((*(B[i]->self))).empty())
        {
            /*

                   list <list<node*> >::iterator iter=A.end()--;
                   list <list<node*> >::iterator iter2=D.end()--;
                   iter2--;
                   iter--;
                   for(; ++iter!=A.begin(); iter--,iter2--)
                   {
                       iter--;
                       if((*((*iter).begin()))->count==0){zeroit=iter;}
                       list <node*> :: iterator iter3 = (*iter2).begin();
                       for(; iter3!=(*iter2).end(); iter3++)
                       {
                           (*iter3)->self=iter;
                       }
                   }
            */if(zeroit==B[i]->self){
            zeroit=A.erase(B[i]->self);
            }
            else{A.erase(B[i]->self);}
        }

        B[i]->count=0;

        if((*((*(ite)).begin()))->count!=0)
        {
            list <node*> tmplist;
            tmplist.push_back(B[i]);
            if((*((*(ite)).begin()))->count>0)
            {
                if(ite==A.end()--)
                {
                    A.push_back(tmplist);
                    zeroit++;
                }
                else
                {
                    zeroit=A.insert(zeroit++,tmplist);
                    zeroit--;
                }
            }
            else
            {
                if(ite==A.begin())
                {
                    A.push_front(tmplist);
                    zeroit--;
                }
                else
                {
                    zeroit=A.insert(zeroit,tmplist);
                    zeroit--;
                }
            }
        }
        else
        {
            (*(ite)).push_back(B[i]);


        }
        B[i]->self=zeroit;
    }
    int count(int i)
    {
        return B[i]->count;
    }
    int findMax()
    {
        list <list<node*> >::iterator ite=A.begin();
        list<node*>::iterator jte = (*(ite)).begin();
        return((*jte)->count);
    }

    int numMax()
    {
        list <list<node*> >::iterator ite=A.begin();
        return((*ite).size());
    }
    void printMax()
    {
        list <list<node*> >::iterator ite=A.begin();
        list<node*>::iterator jte = ((*ite).begin());
        for(; jte!=((*ite).end()); jte++)
        {
            cout<<((*jte)->i)<<" ";
        }
    }
};

