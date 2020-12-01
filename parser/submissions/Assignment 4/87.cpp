#include <iostream>
#include <list>
#include <vector>

using namespace std;

/*
Below the Comment is a Template of the counter class which has the following prototypes
of the functions defined :
1. increment()
2. decrement()
3. reset()
4. numMax()
5. findMax()
6. count()
7. printMax()
*/

class counter
{
    vector<list<int>::iterator> ycoor;
    vector<int> webcount;
    list<list<int> >::iterator initmainlist;
    vector<list<list<int> >::iterator> xcoor;
    list<list<int> > imp;
    list<int> addn34;

public:
    void increment(int i);
    void decrement(int i);
    void reset(int i);
    int count(int i);
    int findMax();
    int numMax();
    void printMax();
    counter(int n)
    {
        webcount.resize(n,0);
        int j=0;
        while(j<n)
        {
            addn34.push_back(j);
            j++;
        }
        imp.push_back(addn34);
        initmainlist = imp.begin();
        list<list<int> >::iterator q = imp.begin();
        for(list<int>::iterator tempiter=(imp.front()).begin(); tempiter!=(imp.front()).end(); tempiter++)
        {
            ycoor.push_back(tempiter);
            xcoor.push_back(q);
        }
    }
};  



//This Function Is For Decreasing the Value of the Given Index by 1
//The built is functions of list ADT used in the Decrement() function are :
/*
1.erase()
2.size()
3.front()
4.push_back()
*/     
//Also the Scope Resolution operator has been used to associate the function with
//the class counter


void counter::decrement(int i)
{
    int flag=0;
    webcount[i]--;
    (*xcoor[i]).erase(ycoor[i]);
    list<list<int> >::iterator tempiter = xcoor[i];
    if(xcoor[i]==imp.begin())
    {
        list<int> addn;
        addn.push_back(i);
        imp.insert(imp.begin(),addn);
        xcoor[i]--;
        ycoor[i]=(*xcoor[i]).begin();
        flag=1;
    }
    if (flag==0)
    {
        xcoor[i]--;
        if((*tempiter).empty()&&(tempiter!=initmainlist))
        {
            imp.erase(tempiter);    
        } 
        if(webcount[(*xcoor[i]).front()]==webcount[i]||webcount[i]==0)
        {
            (*xcoor[i]).push_back(i);
            ycoor[i]=(*xcoor[i]).end();
            ycoor[i]--;
        }
        else
        {
            list<int> addn;
            addn.push_back(i);
            xcoor[i]++;
            imp.insert(xcoor[i],addn);
            xcoor[i]--;
            ycoor[i]=(*xcoor[i]).begin();
        }

    }
    


    return;
}




void counter::printMax()
{
    list<list<int> >::iterator tempiter=imp.end();
    tempiter--;
    if (tempiter==initmainlist)
    {
        if((*tempiter).size()==0)
        {
            tempiter--;   
        } 
    }
    list<int>::iterator tempiter1=(*tempiter).begin();
    while(tempiter1!=(*tempiter).end())
    {
        printf("%d\n",(*tempiter1));
        tempiter1++;
    }
    return;
}    
 




void counter::reset(int i)
{
    int flag=0;
    if(webcount[i]==0) 
    {
        flag=1;
    }
    if (flag==1)
    {
        return;
    }
    else
    {
        webcount[i]=0;
        (*xcoor[i]).erase(ycoor[i]);
        (*initmainlist).insert((*initmainlist).end(),i);
        if((*xcoor[i]).size()==0&&(xcoor[i]!=initmainlist))
        {
            imp.erase(xcoor[i]);    
        } 
        xcoor[i] = initmainlist;
        ycoor[i] = (*initmainlist).end();
        ycoor[i]--;    
    }
    
    return;
}



int counter::numMax()
{
    int xissocool=0;
    list<list<int> >::iterator tempiter=imp.end();
    tempiter--;
    if (tempiter==initmainlist)
    {
        if((*tempiter).size()==0) tempiter--;
    }
    xissocool = (*tempiter).size();
    return xissocool;
}



    
int counter::count(int i)
{

    return webcount[i];

}




int counter::findMax()
{
    list<list<int> >::iterator tempiter=imp.end();


    tempiter--; 


    return (webcount[(*tempiter).front()]);
}
    


//This Function Is For Increasing the Value of the Given Index by 1
//The built is functions of list ADT used in the Increment() function are :
/*
1.erase()
2.size()
3.front()
4.push_back()
*/     
//Also the Scope Resolution () operator has been used to associate the function with
//the class counter





void counter::increment(int i)
{
    webcount[i]++;
    (*xcoor[i]).erase(ycoor[i]);
    list<list<int> >::iterator tempiter = xcoor[i];
    xcoor[i]++;
    if((*tempiter).size()==0&&(tempiter!=initmainlist)) 
    {
        imp.erase(tempiter);
    }
    if(xcoor[i]==imp.end())
    {
        list<int> addn;
        addn.push_back(i);
        imp.insert(imp.end(),addn);
        xcoor[i]=imp.end();
        xcoor[i]--;
        ycoor[i]=(*xcoor[i]).begin();
    }
    else if(webcount[(*xcoor[i]).front()]==webcount[i])
    {
        (*xcoor[i]).push_back(i);
        ycoor[i]=(*xcoor[i]).end();
        ycoor[i]--;
    }
    else
    {
        list<int> addn;
        addn.push_back(i);
        imp.insert(xcoor[i],addn);
        xcoor[i]--;
        ycoor[i]=(*xcoor[i]).begin();
    }
    return;
}


