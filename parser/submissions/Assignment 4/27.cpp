#include<iostream>
#include<vector>
#include<list>
using namespace std;
class counter
{
    list<list<int> >l;
    list<int>::iterator lit;        //for initialization of vector v1
    list<list<int> >::iterator litv;
    vector<list<list<int> >::iterator>v;
    vector<list<list<int> >::iterator>vneg;
    vector<list<int>::iterator >v1;
    list<int>l1;        //To push a list into the list of lists
    vector<int> county;
public:
    counter(int n)
    {
        l.clear();
        v.clear();
        v1.clear();
        for(int i=0;i<n;i++)
        {
            l1.push_back(i);
        }
        l.push_back(l1);
        litv = l.begin();
        for(lit=litv->begin();lit!=litv->end();lit++)

        {
            v1.push_back(lit);
        }
        v.push_back(litv);
        county.resize(n,0);
        vneg.resize(0);
        l1.clear();
    }
    void increment(int i);
    void decrement(int i);
    void reset(int i);
    int count(int i);
    int findMax();
    int numMax();
    void printMax();

};

void counter::increment(int i)          //Increment the count for the ith object
{
    if(county[i]>=0)
    {
        if(v.size()<=(county[i]+1))       //Needs push back in vector v
        {
            l1.push_back(*(v1[i]));
            l.push_back(l1);        //made new
            litv = l.end();
            litv--;
            v.push_back(litv);
            v[county[i]]->erase(v1[i]);
            v1[i]=litv->begin();
            l1.clear();
            county[i]++;
        }
        else
        {
            v[county[i]+1]->push_back(*v1[i]);
            v[county[i]]->erase(v1[i]);
            county[i]++;
            lit=v[county[i]]->end();
            lit--;
            v1[i]=lit;
        }
    }
    else
    {
        if(county[i]==-1)
        {
            v[county[i]+1]->push_back(*v1[i]);
            vneg[-1-county[i]]->erase(v1[i]);
            county[i]++;
            lit=v[county[i]]->end();
            lit--;
            v1[i]=lit;

        }
        else
        {
            vneg[-2-county[i]]->push_back(*v1[i]);
            vneg[-1-county[i]]->erase(v1[i]);
            county[i]++;
            lit=vneg[-1-county[i]]->end();
            lit--;
            v1[i]=lit;
        }
    }
}

void counter::decrement(int i)          //Decrement the count for the ith object
{
    if(county[i]>0)
    {
        v[county[i]-1]->push_back(*v1[i]);
        v[county[i]]->erase(v1[i]);
        lit=v[county[i]-1]->end();
        lit--;
        v1[i]=lit;

        if(county[i]+1==v.size() && v[county[i]]->size()==0)
        {
            v.resize(v.size()-1);
        }
        county[i]--;
    }
    else
    {
        if(vneg.size()<=(-county[i]))
        {
            l1.push_back(*(v1[i]));
            l.push_front(l1);
            litv = l.begin();
            vneg.push_back(litv);

            if(county[i]==0)
            {
                v[county[i]]->erase(v1[i]);
            }
            else
            {
                vneg[-1-county[i]]->erase(v1[i]);
            }
            v1[i]=litv->begin();
            l1.clear();
            county[i]--;
        }

        else
        {
            vneg[-county[i]]->push_back(*v1[i]);
            if(county[i]!=0)
            {
                vneg[-1-county[i]]->erase(v1[i]);
            }
            else
            {
                v[county[i]]->erase(v1[i]);
            }
            county[i]--;
            lit=vneg[-1-county[i]]->end();
            lit--;
            v1[i]=lit;
        }
    }
}

void counter::reset(int i)          //Reset the count of ith object to 0
{
    if(county[i]==0)
    {return;}
    v[0]->push_back(*v1[i]);

    if(county[i]>0)
        v[county[i]]->erase(v1[i]);
    else
        vneg[-1-county[i]]->erase(v1[i]);

    lit=v[0]->end();
    lit--;
    v1[i]=lit;

    if(county[i]+1==v.size() && v[county[i]]->empty())
    {
        v.resize(v.size()-1);
    }
    county[i]=0;
}

int counter::count(int i)       //Return the current count of ith object
{
    return county[i];
}


int counter::findMax()      //Return the maximum count of the objects
{
    int a = v.size();
    int b = vneg.size();
    if(a == 1 && v[0]->empty())
    {
        for(int i=0;i<b;i++)
        {
            if(!vneg[i]->empty())
            return (-1-i);
        }
    }

    else
    {
        return (a-1);
    }
}

int counter::numMax()       //Return the number of objects having maximum count
{
    int a = findMax();
    if(a < 0)
    {
        a = -1-a;
        return vneg[a]->size();
    }
    else
    {
        return v[a]->size();
    }
}

void counter::printMax()
{
    int a = findMax();
    if(a<0)
    {
        a=-1-a;
        for(lit = vneg[a]->begin();lit!=vneg[a]->end();lit++)
        {
            cout<<*lit<<endl;
        }
    }

    else
    {
        for(lit = v[a]->begin();lit!=v[a]->end();lit++)
        {
            cout<<*lit<<endl;
        }
    }
}


