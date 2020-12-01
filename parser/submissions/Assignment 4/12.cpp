#include <iostream>
#include <vector>
#include <list>
using namespace std;
class counter
{
private:
///Declared private dtat variables
    class obj
    {
    public:
        int index;
        int count;
//list < obj >:: iterator lit;
        list <list <obj> >:: iterator llit;
    };
    vector < list <obj>::iterator > vec;
    int n;
    list < list <obj> > lol;
     list <list <obj> >::iterator zero;
public:
///Constructor function to initialise n and the count to zero
    counter(int i)
    {
        n=i;
        vec.resize(n);
        lol.resize(1);
        (*lol.begin()).resize(n);
        int j=0;
        zero=lol.begin();
        for(list < obj >:: iterator it= (*lol.begin()).begin(); it!=(*lol.begin()).end(); it++)
        {
            vec[j]=it;
            (*it).llit=lol.begin();
            (*it).count=0;
            (*it).index=j;
            j++;
        }



    };
///functions on this data
    void increment(int i)
    {


        obj* o=new obj;
        o->count=(*vec[i]).count+1;
        o->index=(*vec[i]).index;
        //obj[i]++;

//lolit++;
        list <list <obj> >:: iterator lolit=((*vec[i]).llit);

        if((++lolit)==lol.end())
        {
        //cout<<"a"<<endl;

                lolit=((*vec[i]).llit);
                //cout<<"shake"<<endl;
            list <obj>* p= new list <obj> ;
            (*p).push_back(*o);
            lol.push_back(*p);
            lolit->erase(vec[i]);
            //cout<<"suiz"<<lolit->size()<<endl;
            list <list <obj> >:: iterator temp=lol.end();
            (*((lol.back()).begin())).llit=--(temp);
            vec[i]=(lol.back()).begin();
            if(lolit->empty()&&(lolit!=zero)){

            lol.erase(lolit);
            }
         delete o;
            delete p;

            }
        else
        {//cout<<"aa"<<endl;
         lolit=((*vec[i]).llit);
            lolit++;
            list <obj>:: iterator it =(*lolit).begin();

            if(lolit->empty()||(*it).count==o->count)
            {
            //cout<<"b"<<endl;
             o->llit=lolit;
                (*lolit).push_back(*o);
                list <list <obj> >:: iterator temp=((*vec[i]).llit);
                temp->erase(vec[i]);
            if(temp->empty()&&(temp!=zero)){
            lol.erase(temp);
            }
            list < obj >:: iterator temp2=lolit->end();
            vec[i]=--temp2;
            delete o;
            }
            else
            {//o->llit=lolit;
            //cout<<"c"<<endl;
            lolit=((*vec[i]).llit);
            list <list <obj> >:: iterator temp=lolit;
            ++temp;
            o->llit=temp;
                list <obj> *p= new list <obj> ;
                (*p).push_back(*o);
                lolit->erase(vec[i]);
                lol.insert(temp,*p);
                if(lolit->empty()&&(lolit!=zero)){
            lol.erase(lolit);
            }
            (temp->begin())->llit=temp;
            vec[i]=temp->begin();
            delete o;
            delete p;
            }
        }
///increment the count of ith object

               //vec[i]=(*lolit).end();
               //ve//c[i]--;
              // cout<<(*vec[i]).index<<endl;
        return;
    };


    void decrement(int i)
    {
        //obj[i]--;///decrement the count of ith object
        obj* o=new obj;
        o->count=(*vec[i]).count-1;
        o->index=(*vec[i]).index;

//lolit++;
        list <list <obj> >:: iterator lolit=((*vec[i]).llit);
        if((lolit)==lol.begin())
        {//cout<<"a"<<endl;


                //cout<<"shake"<<endl;
            list <obj>* p= new list <obj> ;
            (*p).push_back(*o);
            lol.push_front(*p);
            lolit=((*vec[i]).llit);
            lolit->erase(vec[i]);
            //cout<<"suiz"<<lolit->size()<<endl;
            //list <list <obj> >:: iterator temp=lol.end();
            ((lol.begin())->begin())->llit=lol.begin();
            vec[i]=(lol.begin())->begin();
            if(lolit->empty()&&(lolit!=zero)){

            lol.erase(lolit);
            }
         delete o;
            delete p;

            }
        else
        {   lolit=((*vec[i]).llit);
            lolit--;
            list <obj>:: iterator it =(*lolit).begin();

            if(lolit->empty()||(*it).count==o->count)
            {
            //cout<<"b"<<endl;
             o->llit=lolit;
                (*lolit).push_back(*o);
                list <list <obj> >:: iterator temp=((*vec[i]).llit);
                temp->erase(vec[i]);
            if(temp->empty()&&(temp!=zero)){
            lol.erase(temp);
            }
            list < obj >:: iterator temp2=lolit->end();
            vec[i]=--temp2;
            delete o;
            }
            else
            {//o->llit=lolit;


            //cout<<"c"<<endl;
            lolit=((*vec[i]).llit);
            list <list <obj> >:: iterator temp=lolit;
--temp;
            //o->llit=temp;
                list <obj> *p= new list <obj> ;
                (*p).push_back(*o);

                //lol.insert(lolit,*p);




            lolit=((*vec[i]).llit);
            lolit->erase(vec[i]);
            lol.insert(lolit,*p);
            ++temp;
            (temp->begin())->llit=temp;
            vec[i]=temp->begin();
            ++temp;
               if(temp->empty()&&(temp!=zero)){
            lol.erase(lolit);
            }
            delete o;
            delete p;
            }
            }
        return;
    };

    void reset(int i)
    {
     obj* o=new obj;
        o->count=0;
        o->index=(*vec[i]).index;
    o->llit=zero;
    list <list <obj> >:: iterator temp=vec[i]->llit;
    //cout<<"here"<<endl;
    temp->erase(vec[i]);
//cout<<"here"<<endl;
    if(temp->empty()&&(temp!=zero)){
    lol.erase(temp);
    }

    zero->push_back(*o);
    delete o;
    list <obj>:: iterator temp2=zero->end();
    temp2--;
    vec[i]=temp2;
        //obj[i]=0;///reset the count to zero


        return;
    }

    int count(int i)
    {
    return vec[i]->count;
        //return obj[i];///return the count of ith object
    }

    int findMax(){
    list <list <obj> >:: iterator temp=lol.end();
    --temp;
    if(temp->empty()){
    --temp;
    }
    return (temp->begin())->count;
    }

    int numMax(){
     list <list <obj> >:: iterator temp=lol.end();
    --temp;
    if(temp->empty()){
    --temp;
    }
    return temp->size();
    }

    void printMax(){
     list <list <obj> >:: iterator temp=lol.end();
    --temp;
    if(temp->empty()){
    --temp;
    }
    for(list <obj>:: iterator it= temp->begin(); it!=temp->end(); it++){
    cout<<(it->index)<<endl;

    }

      return;
    }
/*
    void print_vec()
    {
        for(int i=0; i<n; i++)
        {
            //cout<<obj[i]<<endl;
            cout<<(*vec[i]).index<<" "<<(*vec[i]).count<<endl;
        }
        return;
    }
    void print_lis(){
    for(list < list <obj> >:: iterator it= lol.begin(); it!=lol.end(); it++)
        {
        for(list < obj >:: iterator jt= (*it).begin(); jt!=(*it).end(); jt++)
        {
        cout<<(*jt).index<<" ";

    }
    cout<<endl;
    for(list < obj >:: iterator jt= (*it).begin(); jt!=(*it).end(); jt++)
        {

        cout<<(*jt).count<<" ";
    }
    cout<<endl;
    }
    return;}
*/
};

