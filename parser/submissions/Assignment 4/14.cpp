#include<iostream>
#include<vector>
#include<list>
using namespace std;
class triard
{
    int count;
    int object;
    list<list<triard> >:: iterator objectid;
    friend class counter;
};

class counter
{
    vector<list<triard>:: iterator> v;
    list<list<triard> > Lolist;
public:
    counter(int n)
    {
        list<triard> linit;
        for(int i=0; i<n; i++)
        {
            triard init;
            init.object= i;
            init.count=0;
            linit.push_back(init);
        }
        Lolist.push_back(linit);
        list<list<triard> > :: iterator temp= Lolist.begin();
        for(list<triard> :: iterator m=(*temp).begin(); m!=(*temp).end(); m++)
        {
            v.push_back(m);
            m->objectid=temp;
        }
    };
    //increment(i) : Increment the count for the ith object.
    void increment(int i)
    {
        list<triard> :: iterator temp =v[i];
        list<list<triard> > :: iterator mp=--(Lolist.end());
        if(temp->objectid!=mp){
                list<list<triard> > :: iterator ntemp =++(temp->objectid);
                if(((*ntemp).begin())->count==((temp->count)+1))
                    {
                    triard vtemp;
                    vtemp.object=temp->object;
                    vtemp.count=(temp->count)+1;
                    vtemp.objectid=ntemp;
                    (*ntemp).push_back(vtemp);
                    list<triard> :: iterator p=(*ntemp).end();
                    v[i]=--(p);
                    --(ntemp);
                    (*(temp->objectid)).erase(temp);
                    if(ntemp->size()==0){Lolist.erase(ntemp);}
                    }

                else
                    {
                    triard vtemp;
                    vtemp.object=temp->object;
                    vtemp.count=(temp->count)+1;
                    list<triard> lvtemp;
                    lvtemp.push_back(vtemp);
                    Lolist.insert(ntemp,lvtemp);
                    --(ntemp);
                    ((*ntemp).begin())->objectid=ntemp;
                    v[i]=(*ntemp).begin();
                    --(ntemp);
                    (*(temp->objectid)).erase(temp);
                    if(ntemp->size()==0){Lolist.erase(ntemp);}
                    }
            }
        else
        {
            triard vtemp;
            vtemp.object=temp->object;
            vtemp.count=(temp->count)+1;
            list<triard> lvtemp;
            lvtemp.push_back(vtemp);
            Lolist.push_back(lvtemp);
            list<list<triard> > :: iterator nep=(Lolist.end());
            (nep)--;
            ((*nep).begin())->objectid=nep;
            v[i]=(*nep).begin();
            --(nep);
            (*(temp->objectid)).erase(temp);
            if(nep->size()==0){Lolist.erase(nep);}
            }
    };
    //decrement(i) : Decrement the count for the ith object.
    void decrement(int i)
    {
        list<triard> :: iterator temp =v[i];
        list<list<triard> > :: iterator np =(temp->objectid);
        if(np!= Lolist.begin())
        {
            list<list<triard> > :: iterator ntemp =(temp->objectid);
            ntemp--;
            if(((*ntemp).begin())->count == ((temp->count)-1))
                {
                   triard vtemp;
                    vtemp.object=temp->object;
                    vtemp.count=(temp->count)-1;
                    vtemp.objectid=ntemp;
                    (*ntemp).push_back(vtemp);
                    list<triard> :: iterator p=(*ntemp).end();
                    v[i]=--(p);
                    ++(ntemp);
                    (*(temp->objectid)).erase(temp);
                    if(ntemp->size()==0){Lolist.erase(ntemp);}
                }
                else
                {
                    triard vtemp;
                    vtemp.object=temp->object;
                    vtemp.count=(temp->count)-1;
                    list<triard> lvtemp;
                    lvtemp.push_back(vtemp);
                    Lolist.insert(ntemp,lvtemp);
                    --(ntemp);
                    ((*ntemp).begin())->objectid=ntemp;
                    v[i]=lvtemp.begin();
                    ++(ntemp);
                    (*(temp->objectid)).erase(temp);
                    if(ntemp->size()==0){Lolist.erase(ntemp);}
                }
        }
        else
        {
            triard vtemp;
            vtemp.object=temp->object;
            vtemp.count=(temp->count)-1;
            list<triard> lvtemp;
            lvtemp.push_back(vtemp);
           list<list<triard> > :: iterator nep=(Lolist.begin());
            Lolist.insert(nep,lvtemp);
            --(nep);
            ((*nep).begin())->objectid=nep;
            v[i]=(*nep).begin();
            ++(nep);
             (*(temp->objectid)).erase(temp);
            if(nep->size()==0){Lolist.erase(nep);}
            }
    };
    //reset(i) : Reset the count of ith object to 0.
    void reset(int i)
    {
        list<triard> :: iterator temp =v[i];
        list<list<triard> > :: iterator rem=temp->objectid;
        list<list<triard> > :: iterator ntemp= Lolist.begin();
        if((*(*ntemp).begin()).count==0)
        {
            triard vtemp;
            vtemp.object=temp->object;
            vtemp.count=0;
            vtemp.objectid=ntemp;
            (*(temp->objectid)).erase(temp);
            (*ntemp).push_back(vtemp);
             list<triard> :: iterator p=((*ntemp).end());
             p--;
             v[i]=p;
             if(rem->size()==0){Lolist.erase(rem);}
        }
        else
        {
            triard vtemp;
            vtemp.object=temp->object;
            vtemp.count=0;
            vtemp.objectid=ntemp;
            list<triard> lvtemp;
            lvtemp.push_back(vtemp);
            (*(temp->objectid)).erase(temp);
            Lolist.insert(ntemp,lvtemp);
            --(ntemp);
            vtemp.objectid=ntemp;
            v[i]=lvtemp.begin();
            if(rem->size()==0){Lolist.erase(rem);}

        }
    };
    //count(i) : Return the current count of ith object.
    int count(int i)
    {
        list<triard> :: iterator temp =v[i];
        return temp->count;

    };
    //findMax() : Return the maximum count of the objects.
    int findMax()
    {
        list<list<triard> > :: iterator ntemp =(Lolist.end());
        ntemp--;
        list<triard> :: iterator temp=(*ntemp).begin();
        return temp->count;
    };
    //numMax() : Return the number of objects having maximum count.
    int numMax()
    {
        list<list<triard> > :: iterator ntemp =(Lolist.end());
        ntemp--;
        return (*ntemp).size();
    };
    //printMax() : Print the list of objects with maximum count, in the
    //            order in which they achieved that count value.
    void printMax()
    {
        list<list<triard> > :: iterator ntemp =(Lolist.end());
        ntemp--;
        for(list<triard> :: iterator temp=(*ntemp).begin(); temp!=(*ntemp).end(); temp++)
        {
            cout<<temp->object<<endl;
        }

    };
};
