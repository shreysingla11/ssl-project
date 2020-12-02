#include<iostream>
#include<vector>
#include<list>
using namespace std;
class cnt
{
public:
  int index;
  int cont;
  list<list<cnt> >::iterator cntitr;
  cnt()
  {
   index=0;
   cont=0;

  }
};

class counter
{
  //declaring variables
  int n;
  //vector<int> v;
  list<list<cnt> > l;
  vector<list<cnt>::iterator> itr;

public:
  //constructor
  counter(int n1)
  {
   int i=0;n=n1;
   cnt ptemp;
   list<cnt> temp;
   list<list<cnt> >::iterator itr1;

   //initializing the first list as list of all objects

   while(i<n)
   {
    //v.push_back(0);
    ptemp.index = i;
    ptemp.cont = 0;
    temp.push_back(ptemp);
    i++;
   }
   l.push_back(temp);
   itr1 = l.begin();

   for(list<cnt>::iterator foritr = (*itr1).begin();foritr != (*itr1).end(); foritr++)
   {
     (*foritr).cntitr = l.begin();    //storing the iterator of each node of the main list
     itr.push_back(foritr);          //intializing the vector that contains pointer to object
   }
  }

  //functions
  void increment(int i)
  {
    list<cnt>::iterator temp = itr[i];
    list<list<cnt> >::iterator ltemp;
    cnt ctemp;
    ctemp.index=i;
    ctemp.cont=(*temp).cont + 1;
    ltemp = (*temp).cntitr;
    ltemp++;
    if(ltemp == l.end())
     {
       ltemp--;
       temp = (*ltemp).erase(temp);
       if((*ltemp).empty()){l.pop_back();ltemp--;}
       list<cnt> cntt;
       cntt.push_back(ctemp);
       l.push_back(cntt);
       ltemp++;
       itr[i] = (*ltemp).begin();
       temp = itr[i];
       (*temp).cntitr = ltemp;
     }
    else
       {
         temp = (*ltemp).begin();
         if((*temp).cont == ctemp.cont)
          {
           ltemp--;
           temp = itr[i];
           temp=(*ltemp).erase(temp);
           if((*ltemp).empty()){ltemp=l.erase(ltemp);}
           else{
           ltemp++;}
           ctemp.cntitr = ltemp;
           (*ltemp).push_back(ctemp);
           temp = (*ltemp).end();
           temp--;
           itr[i]=temp;

          }
          else
          {
          ltemp--;
          temp = itr[i];
          temp=(*ltemp).erase(temp);
          list<cnt> cntt;
          cntt.push_back(ctemp);
          if((*ltemp).empty()){ltemp=l.erase(ltemp);}
         else{ ltemp++;}
          l.insert(ltemp,cntt);
          ltemp--;
          temp = (*ltemp).begin();
          itr[i]=temp;
          (*temp).cntitr=ltemp;
          }


        }

  }

  void decrement(int i)
  {
    list<cnt>::iterator temp = itr[i];
    list<list<cnt> >::iterator ltemp;
    cnt ctemp;
    ctemp.index=i;
    ctemp.cont=(*temp).cont - 1;
    ltemp = (*temp).cntitr;
    if(ltemp==l.begin())
    {
      temp=(*ltemp).erase(temp);
      if((*ltemp).empty()){ltemp=l.erase(ltemp);}
      list<cnt> cntt;
      cntt.push_back(ctemp);
      l.push_front(cntt);
      ltemp--;
      itr[i] = (*ltemp).begin();
      temp = itr[i];
      (*temp).cntitr = ltemp;
    }

  else
  {
    ltemp--;
    temp=(*ltemp).begin();
    if((*temp).cont==ctemp.cont)
    {
      temp=itr[i];
      ltemp++;
      temp=(*ltemp).erase(temp);
      if((*ltemp).empty()){ltemp=l.erase(ltemp);}
      ltemp--;
      ctemp.cntitr=ltemp;
      (*ltemp).push_back(ctemp);
      temp=(*ltemp).end();temp--;
      itr[i]=temp;
    }
    else
    {
     temp=itr[i];
     ltemp++;
     list<cnt> cntt;
     cntt.push_back(ctemp);
     temp=(*ltemp).erase(temp);
     if((*ltemp).empty()){ltemp=l.erase(ltemp);}
     l.insert(ltemp,cntt);
     ltemp--;
     temp = (*ltemp).begin();
     itr[i]=temp;
     (*temp).cntitr=ltemp;
    }
  }
  }



  void reset(int i)
  {
    list<cnt>::iterator temp;
    list<list<cnt> >::iterator ltemp;
    temp = itr[i];
    ltemp = (*temp).cntitr;
    (*ltemp).erase(temp);
    if((*ltemp).size()==0){l.erase(ltemp);}
    ltemp = l.begin();
    cnt ctemp;
    ctemp.index=i;
    ctemp.cont=0;
    ctemp.cntitr=l.begin();
    (*ltemp).push_back(ctemp);
    temp = (*ltemp).end();
    temp--;
    itr[i] = temp;
  }

  int count(int i)
  {
    list<cnt>::iterator temp;
    temp = itr[i];
    return (*temp).cont;
  }

  int findMax()
  {
    list<list<cnt> >::iterator temp;
    temp = l.end();temp--;
    list<cnt>::iterator temp1;
    temp1=(*temp).begin();
    return count((*temp1).index);
  }
  int numMax()
  {
   list<list<cnt> >::iterator temp;
    temp = l.end();temp--;
    return (*temp).size();
  }
  void printMax()
  {
   list<list<cnt> >::iterator temp;
    temp = l.end();temp--;
    for(list<cnt>::iterator litr=(*temp).begin();litr != (*temp).end();litr++)
    {
      cout<<(*litr).index<<endl;
    }
  }

};

