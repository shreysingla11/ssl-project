#include <iostream>
#include <vector>
#include <list>
using namespace std;


class counter{

   int N;
   vector<int> vmain;
   list<list<int> > L;
   list<int> counts;
   list<int> sizes;

   //object identifiers
   vector<list<list<int> >::iterator> it1;//in L
   vector<list<int>::iterator > it2;//in L[i]
   vector<list<int>::iterator > it3;//in count
   vector<list<int>::iterator > it4;//in sizes

   list<list<int> >::iterator zeroit1;//in L
    list<int>::iterator zeroit3;//in count
   list<int>::iterator zeroit4;//in sizes

    public:

    counter(int n){
      vmain.resize(n,0);
      list<int> lst;
      N=n;

      for(int i=0;i<=n;i++){
         lst.push_back(i);
      }

      L.push_back(lst);
      counts.push_back(0);
      sizes.push_back(n+1);

      zeroit1=L.begin();
      zeroit4=sizes.begin();
      zeroit3=counts.begin();

      list<int>::iterator j;
      j=(*(L.begin())).begin();

      for(int i=0;i<n;i++,j++){
         it1.push_back(L.begin());
         it2.push_back(j);
         it3.push_back(counts.begin());
         it4.push_back(sizes.begin());
      }

      return ;

    }


    void increment(int i){
       vmain[i]++;

       list<list<int> >::iterator oldit1,newit1;
       list<int>::iterator oldit2,newit2;
       list<int>::iterator oldit3,newit3,p;
       list<int>::iterator oldit4,newit4;


       oldit1= it1[i];
       oldit2= it2[i];
       oldit3= it3[i];
       oldit4= it4[i];

       p=oldit3;
       p++;
       if(p==counts.end()){

          counts.push_back((*oldit3)+1);
          sizes.push_back(1);
          list<int> d;
          d.push_back(i);
          L.push_back(d);

          newit1= L.end();
          newit1--;
          newit2=(*newit1).end();
          newit2--;
          newit3=counts.end();
          newit3--;
          newit4=sizes.end();
          newit4--;


           if((*oldit4)==1){
            sizes.erase(oldit4);
            L.erase(oldit1);
            counts.erase(oldit3);
           }
           else{
            (*oldit1).erase(oldit2);
            (*oldit4)--;
           }

           it1[i]=newit1;
           it2[i]=newit2;
           it3[i]=newit3;
           it4[i]=newit4;
           return;

       }
       else{

          if((*p)==((*oldit3)+1)){
             newit1=oldit1;
             newit1++;
             (*newit1).push_back(i);
             newit2=(*newit1).end();
             newit2--;

             newit3=oldit3;
             newit3++;

             newit4=oldit4;
             newit4++;
             (*newit4)++;

             if((*oldit4)==1){
              sizes.erase(oldit4);
              L.erase(oldit1);
              counts.erase(oldit3);
             }
             else{
               (*oldit1).erase(oldit2);
               (*oldit4)--;
             }

             it1[i]=newit1;
             it2[i]=newit2;
             it3[i]=newit3;
             it4[i]=newit4;
             return;

          }
          else{

             list<int> l;
             list<list<int> >::iterator p=oldit1;
             p++;
             L.insert(p,l);
             newit1=oldit1;
             newit1++;
             (*newit1).push_back(i);

             newit2=(*newit1).end();
             newit2--;

             list<int>::iterator q=oldit3;
             q++;
             counts.insert(q,(*oldit3)+1);
             newit3=oldit3;
             newit3++;

             q=oldit4;
             q++;
             sizes.insert(q,1);
             newit4=oldit4;
             newit4++;

             if((*oldit4)==1){
              sizes.erase(oldit4);
              L.erase(oldit1);
              counts.erase(oldit3);
             }
             else{
               (*oldit1).erase(oldit2);
               (*oldit4)--;
             }

             it1[i]=newit1;
             it2[i]=newit2;
             it3[i]=newit3;
             it4[i]=newit4;
             return ;

          }

       }


    }


    void decrement(int i){

       vmain[i]--;

       list<list<int> >::iterator oldit1,newit1;
       list<int>::iterator oldit2,newit2;
       list<int>::iterator oldit3,newit3,p;
       list<int>::iterator oldit4,newit4;


       oldit1= it1[i];
       oldit2= it2[i];
       oldit3= it3[i];
       oldit4= it4[i];

       p=oldit3;
       p--;
       if(oldit3==counts.begin()){
          counts.push_front((*oldit3)-1);
          sizes.push_front(1);
          list<int> d;
          d.push_back(i);
          L.push_front(d);

          newit1= L.begin();
          newit2=(*newit1).end();
          newit2--;
          newit3=counts.begin();
          newit4=sizes.begin();


           if((*oldit4)==1){
            sizes.erase(oldit4);
            L.erase(oldit1);
            counts.erase(oldit3);
           }
           else{
            (*oldit1).erase(oldit2);
            (*oldit4)--;
           }

           it1[i]=newit1;
           it2[i]=newit2;
           it3[i]=newit3;
           it4[i]=newit4;
           return;
       }
       else{

          if((*p)==((*oldit3)-1)){
             newit1=oldit1;
             newit1--;
             (*newit1).push_back(i);
             newit2=(*newit1).end();
             newit2--;

             newit3=oldit3;
             newit3--;

             newit4=oldit4;
             newit4--;
             (*newit4)++;

             if((*oldit4)==1){
              sizes.erase(oldit4);
              L.erase(oldit1);
              counts.erase(oldit3);
             }
             else{
               (*oldit1).erase(oldit2);
               (*oldit4)--;
             }

             it1[i]=newit1;
             it2[i]=newit2;
             it3[i]=newit3;
             it4[i]=newit4;
             return;

          }
          else{

             list<int> l;
             list<list<int> >::iterator p=oldit1;
             L.insert(p,l);
             newit1=oldit1;
             newit1--;
             (*newit1).push_back(i);

             newit2=(*newit1).end();
             newit2--;

             list<int>::iterator q=oldit3;
             counts.insert(q,(*oldit3)-1);
             newit3=oldit3;
             newit3--;

             q=oldit4;
             sizes.insert(q,1);
             newit4=oldit4;
             newit4--;

             if((*oldit4)==1){
              sizes.erase(oldit4);
              L.erase(oldit1);
              counts.erase(oldit3);
             }
             else{
               (*oldit1).erase(oldit2);
               (*oldit4)--;
             }

             it1[i]=newit1;
             it2[i]=newit2;
             it3[i]=newit3;
             it4[i]=newit4;
             return ;

          }




       }

    }

    void reset(int i){

       vmain[i]=0;

       list<list<int> >::iterator oldit1,newit1;
       list<int>::iterator oldit2,newit2;
       list<int>::iterator oldit3,newit3,p;
       list<int>::iterator oldit4,newit4;


       oldit1= it1[i];
       oldit2= it2[i];
       oldit3= it3[i];
       oldit4= it4[i];

       (*zeroit4)++;
       (*zeroit1).push_back(i);
       newit1=zeroit1;
       newit2=(*newit1).end();
       newit2--;
       newit3=zeroit3;
       newit4=zeroit4;

           if((*oldit4)==1){
            sizes.erase(oldit4);
            L.erase(oldit1);
            counts.erase(oldit3);
           }
           else{
            (*oldit1).erase(oldit2);
            (*oldit4)--;
           }

           it1[i]=newit1;
           it2[i]=newit2;
           it3[i]=newit3;
           it4[i]=newit4;
           return;


    }


    int count(int i){

      int c;
      c=(*it3[i]);
      return c;

    }

    int findMax(){

       list<int>::iterator p;
       p=counts.end();
       p--;
       if(p==zeroit3){
           if((*zeroit4)==1){
            p--;
           }
           return (*p);
       }
       else{

         return (*p);

       }

    }

    int numMax(){

      list<int>::iterator p,q;
      p=sizes.end();
      p--;
      q=counts.end();
      q--;
      if((*q)==0){
        if((*p)>1){
            return (*p)-1;
        }
        else{
            p--;
            return (*p);
        }
      }
      else{
        return (*p);
      }

    }

    void printMax(){

      list<int>::iterator p,q;
      p=sizes.end();
      p--;
      q=counts.end();
      q--;
      if((*q)==0){
        if((*p)>1){
            list<list<int> >::iterator t = L.end();
            t--;
            p=t->begin();
            while(p!=t->end()){
              int num=(*p);
              if(num!=N){
                cout<<num<<endl;
              }
              p++;
            }
        }
        else{
            list<list<int> >::iterator t = L.end();
            t--;t--;
            p=t->begin();
            while(p!=t->end()){
               cout<<(*p)<<endl;
               p++;
            }
        }
      }
      else{
        list<list<int> >::iterator t = L.end();
        t--;
        p=t->begin();
        while(p!=t->end()){
            cout<<(*p)<<endl;
            p++;
        }
      }

    }


};


