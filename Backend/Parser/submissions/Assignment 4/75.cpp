#include <iostream>
#include <vector>
#include <list>

using namespace std;

class counter
{
    long n;
    vector <long> counti;//to store count of every object
    list<list<long> > l;//list of lists
    vector<list<long>::iterator> pos;//denotes the position in a column
    vector<list<list<long> >::iterator> cvalue;//denotes count values

    list<long>::iterator null1;
    list<list<long> >::iterator null2;

    public:

    counter(long n1)//constructor
    {
        n=n1;

        for(long i=1; i<=n; i++)//count of all elements is 0
        {
            counti.push_back(0);
        }
        list<long> temp1;
        l.push_back(temp1);
        cvalue.push_back(l.begin());

        for(long i=1; i<=n; i++)
        {
            (*cvalue[0]).push_back(i);
        }//place all objects in the first list to denotes count=0

        list<long>::iterator temp2;
        temp2=(*cvalue[0]).begin();

        for(long i=1;i<=n; i++)//initializing the first column
        {
            pos.push_back(temp2);
            temp2++;
        }


    }//end of counter()

    void increment(long i)
    {
        long col1=counti[i];//initial column number of object i
        counti[i]=counti[i]+1;

        //end of list l
        list<list<long> >::iterator it=cvalue[col1];
        list<list<long> >::iterator end1=l.end();
        end1--;
        if(end1==it)//one empty column needs to be added
        {
            list<long> temp1;//an empty list
            l.push_back(temp1);
            it++;
            cvalue.push_back(it);
        }


        //absense of next list
        if((cvalue[counti[i]])==null2)
        {
            list<long> temp1;
            list<list<long> >::iterator tempit=cvalue[(counti[i]+1)];
            l.insert(tempit,temp1);
            tempit--;
            cvalue[counti[i]]==tempit;
        }

        list<long>::iterator tempit1=(*cvalue[col1]).begin();
        if(tempit1==pos[i])//only one element was in previous list hance delete it
        {
            (*cvalue[col1]).erase(pos[i]);
            cvalue[col1]=null2;

        }
        else
        {
            (*cvalue[col1]).erase(pos[i]);//delete element from previous column
        }


        (*cvalue[counti[i]]).push_back(i);

        tempit1=(*cvalue[counti[i]]).end();
        tempit1--;

        pos[i]=tempit1;

        return;
    }//end of increment()

    void decrement(long i)
    {
        long col1=counti[i];//initial column number of object i
        counti[i]=counti[i]-1;

        //absense of previous list
        if(cvalue[counti[i]]==null2)
        {
            list<long> temp1;
            list<list<long> >::iterator tempit=cvalue[(counti[i]+1)];
            l.insert(tempit,temp1);
            tempit--;
            cvalue[counti[i]]==tempit;
        }

        list<long>::iterator tempit1=(*cvalue[col1]).begin();

        if(tempit1==pos[i])//only one element was in previous list hence delete it
        {
            list<list<long> >::iterator tempit2=l.end();
            tempit2--;
            if(tempit2==cvalue[col1])//previous list was the last element of mahalist
            {
                cvalue.pop_back();
                l.pop_back();
            }
            else
            {
                (*cvalue[col1]).erase(pos[i]);
                cvalue[col1]=null2;
            }

        }
        else
        {
            (*cvalue[col1]).erase(pos[i]);//delete element from previous column
        }

        (*cvalue[counti[i]]).push_back(i);

        tempit1=(*cvalue[counti[i]]).end();
        tempit1--;

        pos[i]=tempit1;

        return;
    }//end of decrement()

    void reset(long i)
    {
        long col1=counti[i];//initial column number of object i
        counti[i]=0;

        list<long>::iterator tempit1=(*cvalue[col1]).begin();
        if(tempit1==pos[i])//only one element was in previous list hance delete it
        {
            (*cvalue[col1]).erase(pos[i]);
            cvalue[col1]=null2;

        }
        else
        {
            (*cvalue[col1]).erase(pos[i]);//delete element from previous column
        }

        (*cvalue[counti[i]]).push_back(i);

        tempit1=(*cvalue[counti[i]]).end();
        tempit1--;

        pos[i]=tempit1;

        return;
    }//end of reset()

    long count(long i)
    {
        return counti[i];
    }

    long findMax()
    {
        return (l.size());
    }

    long numMax()
    {
        list<list<long> >::iterator temp=l.end();
        temp--;
        long num=(*temp).size();
        return (num);
    }

    void printMax()
    {
        list<list<long> >::iterator temp=l.end();
        temp--;
        list<long>::iterator temp1=(*temp).begin();
        for(;temp1!=(*temp).end();temp++)
        {
            cout<<" "<<(*temp1);
        }

        return;
    }
};
