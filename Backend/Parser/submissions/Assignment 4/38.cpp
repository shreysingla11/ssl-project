#include <iostream>
#include <vector>
#include <list>
using namespace std;
class counter
{
private:
    int n;
    list <list <int> > sorted;
    vector < int > counts;
    vector < list<int> :: iterator> objectLocation;
    vector < list <list<int> > :: iterator > listLocation;
    list <list<int> > :: iterator zeroList;

public:
    counter(int m)
    {
        n = m;

        list <int > temp;
        list <list<int> > :: iterator temp1 = sorted.insert(sorted.end(),temp);
        for (int i=0; i<n; i++)
        {
            counts.push_back(0);
            objectLocation.push_back((*temp1).insert((*temp1).end(),i));
            listLocation.push_back(temp1);
        }
        zeroList=temp1;

        return;
    }


    int count(int i)
    {
        return counts[i];
    }
    void increment(int i)
    {
        i=i+1;
        //cout<<(*(listLocation[i-1])).size()<<endl;
        counts[i-1]++;                                      //already updated the count of page
        //listLocation[i-1];
        //cout<<(*(objectLocation[i-1]))<<endl;
        //cout<<(*(listLocation[i-1])).size()<<endl;
        (*(listLocation[i-1])).erase((objectLocation[i-1]));    //erased the object from the list in which it was present

        //cout<<"erased"<<endl;
        //cout<<(*(listLocation[i-1])).size()<<endl;
        list <list<int> > :: iterator newList;
        if ((*listLocation[i-1])==(sorted.back()))      //if it was already the maximum
        {
            //cout<<"case 1 "<<endl;
            list<int> temp;

            newList = sorted.insert(sorted.end(),temp);     //newlist inserted at the end of list of lists.
            //cout<<"new higher list"<<endl;
            objectLocation[i-1] = (*newList).insert((*newList).end(),i-1);  //element added in the new list and the iterator is stored.
        }


        else
        {
            newList = ++listLocation[i-1];          //newlist is going to be at the next iterator position.
            listLocation[i-1]--;
            if (newList==zeroList)
            {
                if(counts[i-1]==0)
                {
                    objectLocation[i-1] = (*newList).insert((*newList).end(),i-1);
                }
                else
                {
                    list<int> temp4;
                    newList = sorted.insert(newList,temp4);
                    objectLocation[i-1] = (*newList).insert((*newList).end(),i-1);
                }
            }
            else
            {
                if (counts[i-1]==counts[(*newList).front()])    //if already the desired list exists.
                {
                    // cout<<"case 2 "<<endl;

                    objectLocation[i-1] = (*newList).insert((*newList).end(),i-1);
                }
                else
                {
                    // cout<<"case 3 "<<endl;            //create a newList at the next position.
                    list<int> temp4;
                    newList = sorted.insert(newList,temp4);
                    objectLocation[i-1] = (*newList).insert((*newList).end(),i-1);
                    //cout<<"new higher list"<<endl;
                }
            }
        }

        if ((*(listLocation[i-1])).begin()==(*(listLocation[i-1])).end() && listLocation[i-1]!=zeroList)       //checks if the previous list got emptied.
        {
            // cout<<"the size of sorted is "<<sorted.size()<<endl;
            //cout<<"empty list inside list of lists"<<endl;
            sorted.erase(listLocation[i-1]);
            //cout<<"the size of sorted is "<<sorted.size()<<endl;
        }
        listLocation[i-1]=newList;

        // cout<<"the size of sorted is "<<sorted.size()<<endl;
        // cout<<"--------------------------"<<endl;
        return;
    }

    void decrement(int i)
    {
        counts[i]--;

        (*(listLocation[i])).erase((objectLocation[i]));        //erase the object
        //cout<<"erased"<<endl;
        list <list<int> > :: iterator newList;
        if (listLocation[i]==(sorted.begin()))            //if the count is already minimum
        {
            list<int> temp;
            newList = sorted.insert(sorted.begin(),temp);
            //cout<<"new lower list"<<endl;
            objectLocation[i] = (*newList).insert((*newList).end(),i);  //insert object in the new list and return iterator.
        }

        else
        {
            newList = --listLocation[i];      //newList is going to be at the previous iterator position.
            listLocation[i]++;
            if (newList==zeroList)
            {
                if ((counts[i]==0))
                {
                    objectLocation[i] = (*newList).insert((*newList).end(),i);
                }
                else
                {
                    list<int> temp4;
                    newList = sorted.insert(listLocation[i],temp4);
                    objectLocation[i] = (*newList).insert((*newList).end(),i);
                }
            }
            else
            {
                if (counts[i]==counts[(*newList).front()])    //alrady the desired list exists.
                {

                    objectLocation[i] = (*newList).insert((*newList).end(),i);
                }
                else
                {

                    list<int> temp4;
                    newList = sorted.insert(listLocation[i],temp4);
                    objectLocation[i] = (*newList).insert((*newList).end(),i);
                    //cout<<"new lower list"<<endl;
                }
            }
        }
        //cout<<"inserted"<<endl;
        if ((*(listLocation[i])).empty()&& listLocation[i]!=zeroList)
        {
            sorted.erase(listLocation[i]);                //if the initial list got emptied.
        }
        listLocation[i]=newList;                          //updating the list iterator.
        //cout<<"the size of sorted is "<<sorted.size()<<endl;
        //cout<<"--------------------------"<<endl;
        return;
    }
    /*void printChildWise()
    {
        for (int i=0; i<n; i++)
        {
            cout<<"count "<<counts[i]<<endl;
            for (list<int> :: iterator j=(*(listLocation[i])).begin(); j!=(*(listLocation[i])).end(); j++)
            {
                cout <<*j<<endl;
            }
            cout<<endl;
        }
    }
    */
    /*void print()
    {
        for (list <list<int> > :: iterator k=sorted.begin(); k!=sorted.end(); k++)
        {
            cout<<"--------"<<endl;
            if (k!=zeroList)
            {
                cout<<counts[(*k).front()]<<endl;
            }
            else
            {
                cout<<0<<endl;
            }
            cout<<"---------"<<endl;
            for(list<int> :: iterator l=(*k).begin(); l!=(*k).end(); l++)
            {
                cout << *l<<endl;
            }
            cout<<endl;
        }
        return;
    }*/
    int findMax()
    {
        if ((*zeroList)==sorted.back()&& (*zeroList).empty())
        {
            zeroList--;
            return counts[(*(zeroList++)).front()];
        }
        else
        {
            return counts[(sorted.back()).front()];
        }
    }
    int numMax()
    {
        if ((*zeroList)==sorted.back()&& (*zeroList).empty())
        {
            zeroList--;
            return (*(zeroList++)).size();
        }
        else
        {
            return (sorted.back()).size();
        }
    }
    void printMax()
    {
        if ((*zeroList)==sorted.back()&& (*zeroList).empty())
        {
            list <list<int> > :: iterator k;
            k=(--zeroList);
            zeroList++;
            for(list<int> :: iterator j=(*k).begin(); j!=(*k).end(); j++)
            {
                cout<<*j<<endl;
            }

        }
        else
        {
            for(list<int> :: iterator j=(sorted.back()).begin(); j!=(sorted.back()).end(); j++)
            {
                cout<<*j<<endl;
            }
        }

        return;
    }
    void reset(int i)
    {
        if (counts[i]==0) return;
        counts[i]=0;
        (*(listLocation[i])).erase((objectLocation[i]));

        objectLocation[i] = (*zeroList).insert((*zeroList).end(),i);
        if ((*(listLocation[i])).begin()==(*(listLocation[i])).end())
        {
            sorted.erase(listLocation[i]);                //if the initial list got emptied.
        }
        listLocation[i]=zeroList;
        return;
    }
};
