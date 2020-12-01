#include<iostream>
#include<vector>
#include<list>

using namespace std;

class value{
    private:
        int index;
        int coun;
        list<list<value> >::iterator start;

        friend class counter;

};

class counter
{
private:
    list<list<value> > bigL;
    vector<list<value>::iterator> v;
    int n;
public:
    counter()
    {
        int n =100000;
        list<value> ltemp;
        for(int i=0;i<n;i++)
        {
            value temp;
            temp.index = i;
            temp.coun = 0;
            ltemp.push_back(temp);
        }
        bigL.push_back(ltemp);
        list<list<value> >::iterator itr = bigL.begin();
        int i=0;
        for(list<value>::iterator nitr = (*itr).begin();nitr!=(*itr).end();nitr++)
        {
            v.push_back(nitr);
            nitr->start = itr;
            i++;
        }

    }
    counter(int n0)
    {
        int n =n0;
        list<value> ltemp;
        for(int i=0;i<n;i++)
        {
            value temp;
            temp.index = i;
            temp.coun = 0;
            ltemp.push_back(temp);
        }
        bigL.push_back(ltemp);
        list<list<value> >::iterator itr = bigL.begin();
        int i=0;
        for(list<value>::iterator nitr = (*itr).begin();nitr!=(*itr).end();nitr++)
        {
            v.push_back(nitr);
            nitr->start = itr;
            i++;
        }

    }
    //End of Constr
    void increment(int i)
    {
        list<value>::iterator temp = v[i];
        list<list<value> >::iterator startItr =temp->start;
        list<list<value> >::iterator next=++startItr;
        if(next != bigL.end())
        {
            if((((*next).begin())->coun)==(temp->coun)+1)
            {
                value valtemp;
                valtemp.index = temp->index;
                valtemp.coun = (temp->coun)+1;
                valtemp.start = next;
                (*next).push_back(valtemp);
                list<value>::iterator last=(*next).end();
                v[i]=--(last);
                --next;
                (*(temp->start)).erase(temp);
                if(next->size()==0){bigL.erase(next);}
            }
            else
            {
                value valtemp;
                valtemp.index = temp->index;
                valtemp.coun = (temp->coun)+1;
                list<value> lvalue;
                lvalue.push_back(valtemp);
                bigL.insert(next,lvalue);
                --next;
                ((*next).begin())->start = next;
                v[i] = (*next).begin();
                --next;
                (*(temp->start)).erase(temp);
                if(next->size()==0){bigL.erase(next);}
            }

        }
        else
        {
            value valtemp;
            valtemp.index = temp->index;
            valtemp.coun = (temp->coun)+1;
            list<value> lvalue;
            lvalue.push_back(valtemp);
            bigL.push_back(lvalue);
            list<list<value> >::iterator last=bigL.end();
            last--;
            v[i]=last->begin();
            (v[i])->start = last;
            last--;
            (*(temp->start)).erase(temp);
            if(last->size()==0){bigL.erase(last);}
        }
    }
    //End of increment
    //Start of Decrement
    void decrement(int i)
    {
        list<value>::iterator temp = v[i];
        list<list<value> >::iterator startItr =temp->start;
        if(startItr != bigL.begin())
        {
            list<list<value> >::iterator prev=startItr;
            --prev;
            if((((*prev).begin())->coun)==((temp->coun)-1))
            {
                value valtemp;
                valtemp.index = temp->index;
                valtemp.coun = (temp->coun)-1;
                valtemp.start = prev;
                (*prev).push_back(valtemp);
                list<value>::iterator last=(*prev).end();
                v[i]=--(last);
                ++prev;
                (*(temp->start)).erase(temp);
                if(prev->size()==0){bigL.erase(prev);}
            }
            else
            {
                value valtemp;
                valtemp.index = temp->index;
                valtemp.coun = (temp->coun)-1;
                list<value> lvalue;
                lvalue.push_back(valtemp);
                bigL.insert(startItr,lvalue);
                startItr--;
                ((*startItr).begin())->start = startItr;
                v[i] = (*startItr).begin();
                ++startItr;
                (*(temp->start)).erase(temp);
                if(startItr->size()==0){bigL.erase(startItr);}
            }

        }
        else
        {
            value valtemp;
            valtemp.index = temp->index;
            valtemp.coun = (temp->coun)-1;
            list<value> lvalue;
            lvalue.push_back(valtemp);
            list<list<value> >::iterator first=bigL.begin();
            bigL.insert(first,lvalue);
            first--;
            v[i]=first->begin();
            (v[i])->start = first;
            first=temp->start;
            (*(temp->start)).erase(temp);
            if(first->size()==0){bigL.erase(first);}
        }
    }
    //End of Decrement
    //numMax
    int numMax()
    {
        list<list<value> >::iterator last=bigL.end();
        --last;
        int ret = (*last).size();
        return ret;
    }
    //End of numMax
    //count
    int count(int i)
    {
        int cnt = v[i]->coun;
        return cnt;
    }
    //End of count
    //Reset
    void reset(int i)
    {
        list<value>::iterator temp = v[i];
        list<list<value> >::iterator startItr =temp->start;
        list<list<value> >::iterator first = bigL.begin();
        if((first->begin())->coun==0)
        {
            value valtemp;
            valtemp.index = temp->index;
            valtemp.coun = 0;
            (*first).push_back(valtemp);
            list<value>::iterator last=(*first).end();
            v[i]=--(last);
            last->start = first;
            (*(temp->start)).erase(temp);
            if(startItr->size()==0){bigL.erase(startItr);}
        }
        else
        {
            value valtemp;
            valtemp.index = temp->index;
            valtemp.coun = 0;
            list<value> lvalue;
            lvalue.push_back(valtemp);
            bigL.insert(first,lvalue);
            --first;
            ((*first).begin())->start = first;
            v[i] = (*first).begin();
            (*(temp->start)).erase(temp);
            if(startItr->size()==0){bigL.erase(startItr);}
        }
    }
    //End of reset
    //findMax
    int findMax()
    {
        list<list<value> >::iterator last = bigL.end();
        last--;
        return (last->begin())->coun;
    }
    //End of findMax
    //printMax
    void printMax()
    {
        list<list<value> >::iterator last = bigL.end();
        last--;
        for(list<value>::iterator itr = last->begin();itr!=last->end();itr++)
        {
            cout<<itr->index<<endl;
        }
        return;
    }
    //End of printMax

};

