#include <iostream>
#include <vector>
#include <list>

using namespace std;

class counter
{
    long n;
    vector <long> counts;
    list<list<long>> l;
    vector<list<long>::iterator> index;
    vector<list<list<long>>::iterator> count_value;
    //constructor
    counter(long a);

}

counter(long a)
{
    n=a;
    //intialize counts
    for(int i=0;i<n;i++)
    {
        counts.push_back(0);
    }
    for(int i=0;i<n;i++)
    {

    }

}
