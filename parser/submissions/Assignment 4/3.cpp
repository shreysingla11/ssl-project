#include <iostream>
#include<list>
#include<vector>

using namespace std;

class counter
{
    
    
    int n;
    list<list<int> > a;
    vector<int> counts;
    vector<list<int>::iterator> ity;
    vector<list<list<int> >::iterator> itx;
    list<list<int> >::iterator zeroList;

public :
    counter(int size)
    {
        if(size<0)
        {
            return;
        }
        n = size;
        counts.resize(n,0);
        list<int> l;
        for(int i=0; i<size; i++)
        {
            l.push_back(i);
        }
        a.push_back(l);
        list<int>::iterator it;
        for(it=(a.front()).begin(); it!=(a.front()).end(); it++)
        {
            ity.push_back(it);
            itx.push_back(a.begin());
        }
        zeroList = a.begin();
    }
    
    void increment(int i)
    {
        if(i<0)
        {
            return ;
        }
        counts[i]++;
        (*itx[i]).erase(ity[i]);
        list<list<int> >::iterator temp = itx[i];
        itx[i]++;
        if((*temp).empty()&&(temp!=zeroList)) a.erase(temp);
        if(itx[i]==a.end())
        {
            list<int> l;
            l.push_back(i);
            a.push_back(l);
            itx[i]=a.end();
            itx[i]--;
            ity[i]=(*itx[i]).begin();
            return;
        }
        else if((counts[i]==0)||counts[(*itx[i]).front()]==counts[i])
        {
            (*itx[i]).push_back(i);
            ity[i]=(*itx[i]).end();
            ity[i]--;
        }
        else
        {
            list<int> l;
            l.push_back(i);
            a.insert(itx[i],l);
            itx[i]--;
            ity[i]=(*itx[i]).begin();
        }
        return;
    }
    
    void decrement(int i)
    {
        if(i<0)
        {
            return ;
        }
        counts[i]--;
        (*itx[i]).erase(ity[i]);
        list<list<int> >::iterator temp = itx[i];
        if(itx[i]==a.begin())
        {
            list<int> l;
            l.push_back(i);
            a.push_front(l);
            itx[i]--;
            ity[i]=(*itx[i]).begin();
            return;
        }
        itx[i]--;
        if((counts[i]==0)||counts[(*itx[i]).front()]==counts[i])
        {
            (*itx[i]).push_back(i);
            ity[i]=(*itx[i]).end();
            ity[i]--;
        }
        else
        {
            list<int> l;
            l.push_back(i);
            itx[i]++;
            a.insert(itx[i],l);
            itx[i]--;
            ity[i]=(*itx[i]).begin();
        }
        if((*temp).empty()&&(temp!=zeroList)) a.erase(temp);
        return;
    }
    
    
    void reset(int i)
    {
        if(i<0)
        {
            return ;
        }
        if(counts[i]==0) return;
        counts[i]=0;
        (*itx[i]).erase(ity[i]);
        (*zeroList).push_back(i);
        if((*itx[i]).empty()&&(itx[i]!=zeroList)) a.erase(itx[i]);
        itx[i] = zeroList;
        ity[i] = (*zeroList).end();
        ity[i]--;
        return;
    }
    
    int count(int i)
    {
        if(i<0)
        {
            return -130;
        }
        return counts[i];
    }

    int findMax()
    {
        list<list<int> >::iterator temp=a.end();
        temp--;
        if (temp==zeroList)        
        {
            if((*temp).empty()) temp--;
        }
        return(counts[(*temp).front()]);

    }
    
    int numMax()
    {
        int x=0;
        list<list<int> >::iterator temp=a.end();
        temp--;
        if (temp==zeroList)
        {
            if((*temp).empty()) temp--;
        }
        x = (*temp).size();
        return x;
    }
    void printMax()
    {
        list<list<int> >::iterator temp=a.end();
        temp--;
        if (temp==zeroList)
        {
            if((*temp).empty()) temp--;
        }
        list<int>::iterator temp1=(*temp).begin();
        for(; temp1!=(*temp).end(); temp1++)
        {
            cout<<*temp1<<endl;
        }
        return;
    }
};

int main()
{
    int n;
    cout<<"Enter n: ";
    cin>>n;
    counter A(n);
    int x,y;
    cin>>x;
    while(0<x && x<8)
    {
        if(x<=4)
        {   cin >>y;
            if(x==1){
            A.increment(y);
            }
            else if(x==2){
            A.decrement(y);
            }
            else if (x==3){
                A.reset(y);
            }
            else{
            cout << A.count(y)<<endl;
        }
        }
        else if(x==5)
        {
            cout <<"Max"<<A.findMax()<<endl;
}
    else if(x==6){
        cout <<"Num"<<A.numMax()<<endl;
        }
        else{
            A.printMax();
    }
        cin>>x;
}
    return 0;
}