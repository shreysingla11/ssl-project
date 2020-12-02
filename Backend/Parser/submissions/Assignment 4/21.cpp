
//#include<iostream>
//#include<list>
//#include<vector>
//using namespace std;
class counter{

struct webpage{
int count;
list<int>::iterator it_sub;                     //list inside list
list<list<int> >::iterator it_main;             //main list

};

int n;
list<list<int> > mainlist;
vector<webpage> data;
list<list<int> >::iterator zero;

public:
counter(int m);
void increment(int i);
void decrement(int i);
void reset(int i);
int count(int i);
int findMax();
int numMax();
void printMax();

};

counter::counter(int m)
{
n=m;
list<int> l;
for(int i=0;i<n;i++)
    l.push_back(i);
mainlist.push_back(l);
list<int>::iterator temp;
temp=(*(mainlist.begin())).begin();
for(int i=0;i<n;i++)
    {
    data.push_back(webpage());
    data[i].count=0;
    data[i].it_main=mainlist.begin();
    data[i].it_sub=temp;
    temp++;

    }
zero =mainlist.begin();
}

void counter::increment(int i)
{
data[i].count++;
list<list<int> >::iterator tmp;
tmp=data[i].it_main;
data[i].it_main++;
if( ((*(tmp)).size()==1) &&  ((data[i].it_main)==mainlist.end()) )              ///single element at the end
    {   if(tmp==zero)
        {
        data[i].it_sub=(*(tmp)).erase(data[i].it_sub);
        list<int> l;
        l.push_back(i);
        mainlist.push_back(l);
        tmp++;
        data[i].it_sub=(*tmp).begin();
        data[i].it_main=tmp;
        }
        else
        data[i].it_main--;
    }
else
    {   data[i].it_main--;
        data[i].it_sub=(*(data[i].it_main)).erase(data[i].it_sub);
        tmp=data[i].it_main;
        data[i].it_main++;
        if(data[i].it_main==mainlist.end())                                       ///at the end
        {
        list<int> l;
        l.push_back(i);
        mainlist.push_back(l);
        tmp++;
        data[i].it_sub=(*tmp).begin();
        data[i].it_main=tmp;
        }
        else
        {   int c=0;
            data[i].it_main--;
            tmp++;
            if((*data[i].it_main).empty())                                       ///single element
            {
                if(data[i].it_main!=zero)
                {
                mainlist.erase(data[i].it_main);
                data[i].it_main=tmp;
                }
                else
                {
                data[i].it_main++;
                }
            c=1;
            }
            if(data[i].count==0)                                                    ///count is zero
            {
                tmp=zero;
                (*(tmp)).push_back(i);
                list<int>::iterator  temp=(*(tmp)).end();
                temp--;
                data[i].it_sub=temp;
                data[i].it_main=zero;
            }
            else
            {

                if(data[*((*tmp).begin())].count==data[i].count)                    ///count+1 exists
                {
                if(c!=1)data[i].it_main++;
                (*(tmp)).push_back(i);
                list<int>::iterator  temp=(*(tmp)).end();
                temp--;
                data[i].it_sub=temp;
                }
                else                                                                ///insert count + 1
                {

                    list<int>l;
                    l.push_back(i);
                    if(c!=1)data[i].it_main++;
                    mainlist.insert(data[i].it_main,l);
                    tmp--;
                    data[i].it_main=tmp;
                    data[i].it_sub=((*tmp).begin());
                }
            }

        }
    }
}

void counter::decrement(int i)
    {
data[i].count--;
list<list<int> >::iterator tmp;
tmp=data[i].it_main;
//data[i].it_main--;

if( ((*(tmp)).size()==1) &&  ((tmp)==mainlist.begin()) )              ///single element at the beginning
    {
        if(tmp==zero)
        {
        data[i].it_sub=(*(tmp)).erase(data[i].it_sub);
        list<int> l;
        l.push_back(i);
        mainlist.push_front(l);
        tmp--;
        data[i].it_sub=(*tmp).begin();
        data[i].it_main=tmp;
        }
        else;
    }
else
    {   //data[i].it_main++;

        data[i].it_sub=(*(data[i].it_main)).erase(data[i].it_sub);
        tmp=data[i].it_main;
        //data[i].it_main++;
        if(data[i].it_main==mainlist.begin())                                       ///at the beginning
        {
        list<int> l;
        l.push_back(i);
        mainlist.push_front(l);
        tmp--;
        data[i].it_sub=(*tmp).begin();
        data[i].it_main=tmp;
        }
        else
        {   int c=0;
            //data[i].it_main++;
            tmp--;
            if((*data[i].it_main).empty())                                       ///single element
            {
                 if(data[i].it_main!=zero)
                {
                mainlist.erase(data[i].it_main);
                data[i].it_main=tmp;
                }
                else data[i].it_main--;
                c=1;
            }
            if(data[i].count==0)
            {
                tmp=zero;
                (*(tmp)).push_back(i);
                list<int>::iterator  temp=(*(tmp)).end();
                temp--;
                data[i].it_sub=temp;
                data[i].it_main=zero;
            }
            else
            {

            if(data[*((*tmp).begin())].count==data[i].count)                    ///count-1 exists
            {
            if(c!=1)data[i].it_main--;
            (*(tmp)).push_back(i);
            list<int>::iterator  temp=(*(tmp)).end();
            temp--;
            data[i].it_sub=temp;
            }
            else                                                                ///insert count - 1
            {
            list<int>l;
            l.push_back(i);
            if(c==1)data[i].it_main++;
            mainlist.insert(data[i].it_main,l);
            tmp++;
            data[i].it_main=tmp;
            data[i].it_sub=((*tmp).begin());
            }

            }
        }
    }
}

int counter::count(int i)
    {
    return data[i].count;
    }

void counter::reset(int i)
    {

        if(data[i].it_main==zero)//data[i].count==0)
        {
        (*data[i].it_main).erase(data[i].it_sub);
        (*zero).push_back(i);
        data[i].it_main=zero;
        list<int>::iterator temp;
        temp=(*zero).end();
        temp--;
        data[i].it_sub=temp;

        }
        else
        {
        data[i].count=0;
        data[i].it_sub=(*(data[i].it_main)).erase(data[i].it_sub);
            if((*data[i].it_main).empty())
            {
            mainlist.erase(data[i].it_main);
            }
        data[i].it_main=zero;
        (*(zero)).push_back(i);
        list<int>::iterator  temp=(*(zero)).end();
        temp--;
        data[i].it_sub=temp;

        }


    }
int counter::findMax()
{
    list<list<int> >::iterator max;
    max=mainlist.end();
    max--;
    if((*max).empty())
    {
     max--;
     return(data[*((*max).begin())].count);

    }
    else
        return(data[*((*max).begin())].count);
}

int counter::numMax()
{
    list<list<int> >::iterator max;
    max=mainlist.end();
    max--;
    if((*max).empty())
    {
     max--;
     return((*max).size());

    }
    else
        return((*max).size());
}


void counter::printMax()
{
    list<list<int> >::iterator max;
    max=mainlist.end();
    max--;
    if((*max).empty())
    {
     max--;
        for(list<int>::iterator i=(*max).begin();i!=(*max).end();i++)
        {
            cout<<*i<<" ";
        }

    }
    else
    {
        for(list<int>::iterator i=(*max).begin();i!=(*max).end();i++)
        {
            cout<<*i<<" ";
        }
    }

}



