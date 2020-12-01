#include<iostream>
#include<list>
#include<vector>
using namespace std;
const int N=1000;   //No. of elements
class counter{
    vector<int> v;  //Stores count value for nth object
    list<list<int> > l; //Stores list of indices with count value n.
                        //First element stores the common count value
    vector<list<int>::iterator > p; //Stores iterator to list with count value n
    vector<list<list<int> >::iterator > lit; //Stores iterator to first element of the list
    public:
    counter(int n=N)
    {
        vector<int> w(n,0);
        list<int> m;
        v=w;
        m.push_back(0);

        for(int i=0;i<n;i++)
            {
                m.push_back(i); //All vectors have initially 0 count
            }
        l.push_back(m);

        list<int>::iterator it=++(l.front()).begin();

        for(int i=0;i<n;i++)
        {
            lit.push_back(l.begin());
            p.push_back(it);
            it++;
        }
    }
    void increment(int i);
    void decrement(int i);
    void reset(int i);
    int count(int i);
    int findMax();
    int numMax();
    void printMax();
};

void counter::increment(int i)
{

    if(i>=v.size()){
        cout<<"Index does not exist...";
        return;
        }

    v[i]++;

    lit[i]->erase(p[i]);//Deleting the data from the list
    list<list<int> >::iterator temp=lit[i];

    //Check if a list corresponding to the new count value exists
    list<int> next_list;

    if(*(lit[i])!=l.back()){
        next_list=*(++lit[i]);
        --lit[i];
    }
    if(*(lit[i])==l.back()||next_list.front()!=v[i]){
        list<int> lnew;
        lnew.push_back(v[i]);
        lnew.push_back(i);
        l.insert(++lit[i],lnew);
        --lit[i];
        p[i]=++(lit[i]->begin());
    }
    else{
        lit[i]++;
        lit[i]->push_back(i);
        p[i]=--(lit[i]->end());

    }
    if(temp->size()==1){
        //List is empty
        l.erase(temp);
    }
    return;
}

void counter::decrement(int i)
{
    if(i>=v.size()){
        cout<<"Index does not exist...";
        return;
        }
    v[i]--;

    (*lit[i]).erase(p[i]);
    list<list<int> >::iterator temp=lit[i];

    //Check if a list corresponding to the new count value exists
    list<int> prev_list;

    if(lit[i]!=l.begin()){
        prev_list=*(--lit[i]);
        lit[i]++;
    }
    if(lit[i]==l.begin()||prev_list.front()!=v[i]){
        list<int> lnew;
        lnew.push_back(v[i]);
        lnew.push_back(i);
        l.insert(lit[i],lnew);
        lit[i]--;
        p[i]=++(lit[i]->begin());
    }
    else{
        lit[i]--;
        lit[i]->push_back(i);
        p[i]=--(lit[i]->end());
    }
    if(temp->size()==1){
        //List is empty
        l.erase(temp);
    }
    return;
}

void counter::reset(int i)
{
    if(i>=v.size()){
        cout<<"Index does not exist...";
        return;
        }
    v[i]=0;
    (*lit[i]).erase(p[i]);
    list<list<int> >::iterator temp=lit[i];


    list<int> first=*l.begin();
    if((l.front()).front()!=0)
    {
        list<int> lnew;
        lnew.push_back(0);
        lnew.push_back(i);
        l.push_front(lnew);
        lit[i]=l.begin();
        p[i]=++(l.front()).begin();
    }
    else
    {
        (l.front()).push_back(i);
        p[i]=--(*l.begin()).end();
        lit[i]=l.begin();
    }
    if(temp->size()==1){
        //List is empty
        l.erase(temp);
    }
    return;
}

int counter::count(int i)
{
    return v[i];
}

int counter::findMax()
{
    return (l.back()).front();
}

int counter::numMax()
{
    return (l.back()).size()-1;
}

void counter::printMax()
{
    list<int> max=l.back();
    for(list<int>::iterator it=++max.begin();it!=max.end();it++)
        cout<<*it<<endl;
    //cout<<endl;
}

