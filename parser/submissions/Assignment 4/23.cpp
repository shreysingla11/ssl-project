#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;
struct Mainblock;
struct Webpage
{
    int index;
    list<Webpage>::iterator sub;
    list<Mainblock>::iterator main;
};
struct Mainblock
{
    int count;
    list<Webpage> Subblock;
};
class counter
{
    int n;
    list<Mainblock>::iterator Start;
    vector<Webpage> Mainvector;
    list<Mainblock> Mainlist;
    public:
    counter(int n)
        {
        if(n<0)
        return;
        Mainvector.resize(n);
        //cout<<"mainvector resized\n";
        this->n=n;
        Mainlist.resize(1);
        Start=Mainlist.begin();
        //To initialize counts to zero? all vectors have zero length
        (*Mainlist.begin()).count=0;
        //(*(++Mainlist.begin())).count=1;
        for(int i=0;i<n;i++)
        {
        Mainvector[i].index=i;
        //cout<<"into i="<<i<<endl;
        Mainvector[i].main=Mainlist.begin();
        Mainvector[i].sub=(*Mainlist.begin()).Subblock.end();
        (*Mainlist.begin()).Subblock.push_back(Mainvector[i]);
        }

        }

void increment(int i) //: Increment the count for the ith object.
    {
         if(i>=n||i<0)
        return;
        //cout<<"into increment of i="<<i<<"\n";
      list<Mainblock>::iterator from;
      from=Mainvector[i].main;
      list<Mainblock>::iterator next=++from;
      from--;

      if(((*(next)).count==(*(from)).count+1)&&Mainlist.end()!=next)
            {
                //cout<<"higher mainblock exists\n";

                Mainvector[i].main=next;
                Mainvector[i].sub=(*next).Subblock.end();
                (*(from)).Subblock.pop_back();
                (*next).Subblock.push_back(Mainvector[i]);
                //cout<<"next subblock element"<<(*next).Subblock.front().index<<endl;
                if((*from).Subblock.size()==0&&from!=Start)
                {
                    //cout<<"node in mainlist erased\n";
                    Mainlist.erase(from);
                }
            }
    else
        {
            //cout<<"higher main block not present\n";
            Mainblock toinsert;
            Mainlist.insert(next,toinsert);
            next=++from;from--;
            (*next).count=(*(from)).count+1;
            //cout<<"(*from).count+1"<<" "<<(*from).count+1<<endl;

            Mainvector[i].main=next;
            Mainvector[i].sub=(*next).Subblock.begin();
            (*next).Subblock.push_back(Mainvector[i]);
            //cout<<(*next).Subblock.front().index<<endl;
            (*(from)).Subblock.pop_back();
            //cout<<"previous thing popped off\n";
             if((*from).Subblock.size()==0&&from!=Start)
                {
                    //cout<<"subblock erased\n";
                    Mainlist.erase(from);
                }

        }
    }
void decrement(int i) //: Decrement the count for the ith object.
    {
        if(i>=n||i<0)
        return;
        //cout<<"into decrement of i="<<i<<endl;
        list<Mainblock>::iterator from;
        from=Mainvector[i].main;
        list<Mainblock>::iterator prev=--from;
        from++;

      if(((*(prev)).count==(*(from)).count-1)&&(from!=Mainlist.begin()))
            {
                //cout<<"previous node exists\n";
                Mainvector[i].main=prev;
                Mainvector[i].sub=(*prev).Subblock.end();
                (*from).Subblock.pop_back();
                (*prev).Subblock.push_back(Mainvector[i]);
                 if((*from).Subblock.size()==0&&from!=Start)
                {
                    //cout<<"node erased after decrement\n";
                    Mainlist.erase(from);
                }
            }
    else
        {
            //cout<<"previous node does not exist\n";
            Mainblock toinsert;
            Mainlist.insert(++prev,toinsert);
            prev=--from;
            from++;
            (*prev).count=(*from).count-1;
            Mainvector[i].main=prev;
            Mainvector[i].sub=(*prev).Subblock.begin();
            (*prev).Subblock.push_back(Mainvector[i]);
            //cout<<"push_back to prev\n";
            (*(from)).Subblock.pop_back();
            //cout<<"element from 'from' popped off\n";
             if((*from).Subblock.size()==0&&from!=Start)
                {
                    //cout<<"Erase during decrement\n";
                    Mainlist.erase(from);
                }
        }


    }
void reset(int i) //: Reset the count of ith object to 0.
    {
        if(i>=n||i<0)
        return;

        list<Mainblock>::iterator from;
        from=Mainvector[i].main;
        Mainvector[i].main=Start;
        Mainvector[i].sub=(*Start).Subblock.end();
        (*from).Subblock.pop_back();
         if((*from).Subblock.size()==0&&from!=Start)
                {

                    Mainlist.erase(from);
                }
        (*Start).Subblock.push_back(Mainvector[i]);
    }
int count(int i) //: Return the current count of ith object.
    {
    if(i>=n||i<0)
    return 0;
    return((*Mainvector[i].main).count);
    }
int findMax() //: Return the maximum count of the objects.
    {
        return((*(--Mainlist.end())).count);
    }
int numMax() //: Return the number of objects having maximum count.
    {
        return((*(--Mainlist.end())).Subblock.size());
    }
void printMax() //: Print the list of objects with maximum count, in the
                //order in which they achieved that count value.

    {
    list<Webpage>::iterator it;

    for(it=(*(--Mainlist.end())).Subblock.begin();it!=(*(--Mainlist.end())).Subblock.end();it++)
            {
            cout<<(*it).index<<" ";
            }
            cout<<endl;
    }
/*void funprint()
{
    cout<<"\n\n executing funprint\n\n";
    list<Mainblock>::iterator it;
    for(it=Mainlist.begin();it!=Mainlist.end();it++)
    {
        cout<<(*it).count<<" is count value and "<<(*it).Subblock.size()<<"is subblock size\n";
    }
    cout<<"findmax and nummax="<<findMax()<<" "<<numMax()<<endl;
}*/


};
/*int main()
{
counter mycounter(100);
for(int i=0;i<100;i++)
{
    //cout<<"loop 1 i="<<i<<"\n";
    mycounter.decrement(i);
    mycounter.decrement(i);
}
mycounter.reset(42);
mycounter.reset(6);
for(int i=0;i<8;i++)
{
    mycounter.decrement(80);
    mycounter.decrement(78);
    mycounter.decrement(46);
}
mycounter.reset(150);
mycounter.reset(-1);
mycounter.increment(100);
mycounter.increment(-90);
mycounter.decrement(-400);
cout<<mycounter.count(-9)<<endl;
cout<<mycounter.findMax()<<endl;
cout<<mycounter.numMax()<<endl;
//mycounter.funprint();
mycounter.printMax();
}*/

