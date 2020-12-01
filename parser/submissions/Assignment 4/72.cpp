/*#include<cstdio>
#include<list>
#include<vector>
using namespace std; */
class counter
{
private:

    class webpage{
    public:
    list<list<int> >::iterator main;
    list<int>::iterator self;
    int c;
    webpage(){ c = 0;}

    };

    list<list<int> > l;
    vector<webpage> w;

    list<list<int> >::iterator zero;

public:
    counter(int n) {


    list<int> temp(n,0);

    l.push_back(temp);

    list<int>::iterator p = (l.front()).begin();
        zero = l.begin();
    for(int i =0;p!=l.front().end();p++,i++)
    {
    webpage temp2;
    temp2.main = l.begin();
    temp2.self = p;
    *p =i;
    w.push_back(temp2);

    }


    }
public:
    void increment(int i)
    {

    int newcount=w[i].c+1;
    if(w[i].main == --l.end())                      //end 1element
        {
            if(w[i].main->size()==1)
                {

            w[i].c = newcount;
            if(newcount==0)
            {
                l.erase(w[i].main);
                zero->push_back(i);
                w[i].main = zero;
                w[i].self = --zero->end();
            }

            }


    else
        {
            list<int> temp;                         //end many element
            temp.push_back(i);
            l.back().erase(w[i].self);
            if(newcount!=0){
                    if(newcount<0)l.insert(zero,temp);

                    else l.push_back(temp);}
            else zero->push_back(i);
            w[i].main++;
            w[i].c = newcount;
            w[i].self = l.back().begin();}


        }


    else {
            if(w[i].main->size()==1)                                 //single but doesnt exxist
            {
                if(w[i].c +1 != w[(++w[i].main)->front()].c)
                {
                    w[i].c = newcount;--w[i].main;
                     if(newcount==0)
            {
                l.erase(w[i].main);
                zero->push_back(i);
                w[i].main = zero;
                w[i].self = --zero->end();
            }


                }

                else
                {list<list<int> >::iterator t = w[i].main ;
               (--t)->erase(w[i].self);

                if(t!= zero) l.erase(t);
                w[i].main->push_back(i);                                // single but exist
                w[i].c = newcount;
                w[i].self = --(w[i].main->end());
                }


            }
            else {
                    int index = (++(w[i].main))->front();

                if(w[i].c +1 != w[index].c)                                    //many but agla wala doenst exit
                {                                                  // empty zero
                    list<int> temp;
                    temp.push_back(i);
                    list<list<int> >::iterator t = w[i].main;
                    (--t)->erase(w[i].self);
                  if(newcount!=0){l.insert(w[i].main,temp); --w[i].main;}

                  else zero->push_back(i);

                  w[i].c = newcount;
                  w[i].self = --w[i].main->end();
                }
                else                                                                //many but agla exist
                {
                        list<list<int> >::iterator t2 = --w[i].main;
                        t2->erase(w[i].self);
                        w[i].main++;
                        w[i].main->push_back(i);
                        w[i].c = newcount;
                        w[i].self = --(w[i].main->end());
                }

            }


     }


    }


    void decrement(int i)

    {
        int newcount=w[i].c-1;
    if(w[i].main == l.begin())                      //front 1element
        {
            if(w[i].main->size()==1)
              {


            w[i].c = newcount;
            if(newcount==0)
            {
                l.erase(w[i].main);
                zero->push_back(i);
               w[i].main = zero;
                w[i].self = --zero->end();
            }

              }
    else
        {   list<int> temp;                         //front many element
            temp.push_back(i);
            l.front().erase(w[i].self);
            if(newcount!=0){l.insert(w[i].main,temp);}
            else zero->push_back(i);

            w[i].main--;
            w[i].c = newcount;
            w[i].self = --w[i].main->end();}


        }


    else {
            if(w[i].main->size()==1)                                 //single in between
            {
                if(w[i].c -1 != w[(--w[i].main)->front()].c)     // doesnt exist
                {
                    w[i].c = newcount;++w[i].main;
                    if(newcount==0)
            {
                l.erase(w[i].main);
                zero->push_back(i);
                w[i].main = zero;
                w[i].self = --zero->end();
            }


                }

                else
                { list<list<int> >::iterator t3 = w[i].main;
                      //singele but exist;
                    t3++;
                    t3->erase(w[i].self);
                if(t3!=zero)l.erase(t3);
                w[i].main->push_back(i);
                w[i].c = newcount;
                w[i].self = --(w[i].main->end());
                }

            }
            else {
                    int index = (--(w[i].main))->front();


                if(w[i].c +1 != w[index].c)                                    //many but pichla wala doenst exit
                {
                    list<int> temp;
                    temp.push_back(i);
                    list<list<int> >::iterator t = ++w[i].main;
                    (t)->erase(w[i].self);
                          if(newcount!=0){l.insert(w[i].main,temp);}

                  else zero->push_back(i);

                  --w[i].main;
                  w[i].c = newcount;
                  w[i].self = w[i].main->begin();
                }
                else                                                                //many but pichla exist
                {
                        list<list<int> >::iterator t2 = ++w[i].main;
                        t2->erase(w[i].self);
                        w[i].main--;
                        w[i].main->push_back(i);
                        w[i].c = newcount;
                        w[i].self = --(w[i].main->end());
                }

            }


     }

    }

    int count(int i)
    {
    return w[i].c;

    }

    void reset (int i)
    {

        if(w[i].main->size()==1)
        {
         w[i].main->erase(w[i].self);
         if(w[i].main!=zero)l.erase(w[i].main);
         w[i].main = zero;
         zero->push_back(i);
         w[i].c = 0;
         w[i].self = --(zero->end());
        }
        else
        {
         w[i].main->erase(w[i].self);
         zero->push_back(i);


         w[i].main = zero;
         w[i].c = 0;
         w[i].self = --(zero->end());

        }

    }



    int findMax()
    {
    list<list<int> >::iterator temp = --l.end();
    if(temp==zero&& zero->size()==0){--temp;}

    return w[temp->front()].c;
    }

    int numMax()
    {
    list<list<int> >::iterator temp = --l.end();
    if(temp==zero&& zero->size()==0){temp = --temp;}
    return temp->size();
    }

    void printMax()
    {
         list<list<int> >::iterator temp = --l.end();
        if(temp==zero&& zero->size()==0){temp = --temp;}

            for(list<int>::iterator j = temp->begin();j != temp->end();j++)
            {printf("%d ",*j);}



    }




};


