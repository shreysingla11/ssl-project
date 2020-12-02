#include<iostream>
#include<vector>
#include<list>
using namespace std;
class counter
{
    int n,i,j;
    vector<list<list<int> >::iterator >v1;
    vector<list<int>::iterator >v2;
    list<list<int> >::iterator l1;
    list<int>::iterator l2;
    list<int>x;
    list<list<int> >y;
    vector<int>count1;
    int findiny(int z)
    {
        for(int i=0; i<y.size(); i++)
        {
            if(count1[z]==i)
            {
                return i;
            }
        }
        return -1;

    }
public:
    counter(int p)
    {
        n=p;
        int q=0;
        count1.resize(n,0);
        x.push_back(0);
        l2=x.begin();
        v2.push_back(l2);
        for(i=1; i<n; i++)
        {
            x.push_back(i);
            l2++;
            v2.push_back(l2);
        }
        y.push_back(x);
        l1=y.begin();
        v1.push_back(l1);
        for(int i=0; i<n; i++)
        {
            count1.push_back(0);
        }

    }
    void increment(int p)
    {
        list<list<int> >::iterator l1;
        list<int>::iterator l2;
        list<int>x;
        list<list<int> >y;
        count1[p]++;
        int x=*v2[p];
        cout<<x<<endl;
        int it=findiny(p);
        if(it==-1)
        {
            list<int>temp;
            temp.push_back(x);
            y.push_back(temp);
            l1++;
            v1.push_back(l1);
        }
        else
        {
            *.push_back(p);

        }




    }

    void decrement(int p)
    {
        list<list<int> >::iterator l1;
        list<int>::iterator l2;
        list<int>x;
        list<list<int> >y;
        count1[p]--;
        int x=*v2[p];
        cout<<x<<endl;
        int it=findiny(p);
        if(it==-1)
        {
            list<int>temp;
            temp.push_back(x);
            y.push_back(temp);
            l1++;
            v1.push_back(l1);
        }
        else
        {
            *.push_back(p);

        }




    }

    void reset(int i)
    {
        count1[i]=0;
    }
    void findMax(int i)
    {
    }
    void numMax(int i)
    {

    }
    void counts(int i)
    {

        cout<<count1[i]<<endl;
    }

};

