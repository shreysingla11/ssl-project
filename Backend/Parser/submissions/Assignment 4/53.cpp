#include<iostream>
#include<vector>
#include<list>
using namespace std;
class counter
{

    vector<int>count1;
    list<list<int> >l;
    vector<list<list<int> >::iterator>pos1;
    vector<list<int>::iterator>pos2;
public:
counter(int n)
    {
        count1.resize(n,0);
        int i=0;
        list<int>m;
        list<int>::iterator it2;
        list<list<int> >::iterator it1;
        l.push_back(m);
        it1=l.begin();
        pos1.push_back(it1);
        it1->push_back(0);
        it2=it1->begin();
        pos2.push_back(it2);
        for(i=1;i<n;i++)
        {

         it1->push_back(i);
         it2++;
         pos2.push_back(it2);
         pos1.push_back(it1);

         }

    };



void increment(int i)
    {
        list<int>m;
        list<int>::iterator it2;
        list<list<int> >::iterator it1;
        list<int>::iterator it22;
        list<list<int> >::iterator it11;
        list<int>::iterator it;
        it=pos1[i]->end();
        it1=l.end();
         count1[i]=count1[i]+1;
         it11=pos1[i];
            it22=pos2[i];
            if(pos2[i]!=--it)
            { it22=it11->erase(it22);
              pos2[*it22]=it22;

             }
             else{it22=it11->erase(it22);}
         if(pos1[i]==--it1)
           {
            l.push_back(m);
             it1=l.end();
             pos1[i]=--it1;
             it1->push_back(i);
             it2=it1->begin();
             pos2[i]=it2;

            }
         else
         {

            it1=pos1[i];
            it1++;
            it2=it1->begin();
            if(count1[*it2]==count1[i])
               {
                 it1->push_back(i);
                 it2=it1->end();
                 pos2[i]=--it2;
                 pos1[i]=it1;

                 }
            else
                {

                 l.insert(it1,m);
                 --it1;
                 it1->push_back(i);
                 it2=it1->begin();
                 pos1[i]=it1;
                 pos2[i]=it2;

                 }

           }
         if(it11->size()==0)
            {
                if(it11==l.end())
                {

                    it11=l.erase(it11);
                }
                else
                 {
                    it11=l.erase(it11);
                    it2=it11->begin();
                for(it2;it2!=it11->end();it2++)
                    {
                      {pos1[*it2]=it11;}

                    }

                  }
             }

   return;
    };



void decrement(int i)
    {
        list<int>m;
        list<int>::iterator it2;
        list<list<int> >::iterator it1;
        list<int>::iterator it22;
        list<list<int> >::iterator it11;
        list<int>::iterator it;
        it=pos1[i]->end();
        count1[i]=count1[i]-1;
        it11=pos1[i];
            it22=pos2[i];
            if(pos2[i]!=--it)
            { it22=it11->erase(it22);
              pos2[*it22]=it22;
             }
             else{it22=it11->erase(it22);}
        it1=pos1[i];
        it1--;
        if(count1[*it1->begin()]==count1[i])
               {
                 it1->push_back(i);
                 it2=it1->end();
                 pos2[i]=--it2;
                 pos1[i]=it1;


                 }
            else
                {
                  it1++;
                  l.insert(it1,m);
                  --it1;
                  it1->push_back(i);
                  it2=it1->begin();
                  pos1[i]=it1;
                  pos2[i]=it2;

                 }
            if(it11->size()==0)
                 {
                   if(it11==l.end())
                      {
                         it11=l.erase(it11);}
                    else
                      {
                        it11=l.erase(it11);
                        it2=it11->begin();
                        for(it2;it2!=it11->end();it2++)
                          {
                             {
                                pos1[*it2]=it11;
                             }
                          }
                     }
                  }
                return;

    };



void reset(int i)
    {
        if(count1[i]==0){return;}
        count1[i]=0;
        list<int>m;
        list<int>::iterator it2;
        list<list<int> >::iterator it1;
        list<int>::iterator it22;
        list<list<int> >::iterator it11;
        list<int>::iterator it;
        it=pos1[i]->end();
        it1=pos1[i];
        it2=pos2[i];
        it11=l.begin();
        it22=it11->begin();
        if(pos2[i]!=it--)
        {
           it2=pos1[i]->erase(it2);
            pos2[*it2]=it2;}
            else{it2=pos1[i]->erase(it2);}
        if(count1[*it22]==0)
           {
             pos1[i]=pos1[*it22];
             it11->push_back(i);
             it22= it11->end();
             pos2[i]=--it22;

           }
            else
            {
              l.push_front(m);
              it11=l.begin();
              it11->push_back(i);
              it2=it11->begin();
              pos2[i]=it2;
              pos1[i]=it11;

             }
             if(it1->size()==0)
             {
               if(it1==l.end())
                 {
                   it1=l.erase(it1);
                 }
               else
                 {
                   it1=l.erase(it1);
                   it2=it1->begin();
                    for(it2;it2!=it1->end();it2++)
                       {
                         {
                           pos1[*it2]=it1;
                         }
                       }
                 }
             }
        return;
      };



int count(int i)
     {
       return count1[i];
     };


int findMax()
     {
        list<int>::iterator it2;
        list<list<int> >::iterator it1;
        it1=l.end();
        --it1;
        it2=it1->begin();
        return *it2;
     };



int numMax()
    {
      list<int>::iterator it2;
      list<list<int> >::iterator it1;
      it1=l.end();
      it1--;
      return it1->size();
    };



void printMax()
    {
        list<int>::iterator it2;
        list<list<int> >::iterator it1;
        it1=l.end();
        --it1;
        it2=it1->begin();
        for(it2;it2!=it1->end();it2++)
          {
           cout<<*it2<<' ';
          }

          return ;
    };

};


