#include<iostream>
#include<vector>
#include<list>

using namespace std;

class counter{
   vector <int> pcount;
   list<list<int> > inds;
   vector< list<int>::iterator > ite;
   vector< list<list<int> >::iterator > lite;
   list<list<int> >::iterator p;
   int n;
 public:

   int count(int i){
      return pcount[i];
   }
   void reset(int i){
      list<list<int> >::iterator olite= lite[i];
      list<list<int> >::iterator nlite= inds.begin();
      int tele= *((*nlite).begin());
      int tcount= pcount[tele];
      int csize=(*olite).size();
      if(tcount==0){
            int t=i;
            if(csize==1){
                (*lite[i]).resize(0);
                inds.erase(lite[i]);
            }
            else{
                if(*(*lite[i]).begin()==*ite[i]){
                    lite[i]->pop_front();
                }
                else{
                    (lite[i])->erase(ite[i]);
                }
            }
            lite[i]=(nlite);
            (*nlite).insert((*nlite).end(),t);
            ite[i]=(*nlite).end();
            ite[i]--;
         }
      else{
            list<int> tlist;
            int t=i;
            if(csize==1){
                (*lite[i]).resize(0);
                inds.erase(lite[i]);
            }
            else{
                if(*(*lite[i]).begin()==*ite[i]){
                    lite[i]->pop_front();
                }
                else{
                    (lite[i])->erase(ite[i]);
                }
            }
            tlist.insert(tlist.end(),t);
            inds.insert(nlite,tlist);
            ite[i]= tlist.begin();
            lite[i]= (--nlite);
         }
      pcount[i]=0;
      return;
   }
   counter(int N){
      n=N;
      pcount.resize(n);
      ite.resize(n);
      list<int> t;
      for(int i=0;i<n;i++){
         t.push_back(i);
         pcount[i]=0;
      }
      inds.push_back(t);
      for(int i=0;i<n;i++){
         lite.push_back(inds.begin());
      }
      ite[0]=(*lite[0]).begin();
       for(int i=1;i<n;i++){
         ite[i]=ite[i-1];
         ite[i]++;
      }
   }
   int findMax(){
      p=inds.end();
      p--;
      int M= *((*p).begin());
      int max= pcount[M];
      return max;
   }
   int numMax(){
      p=inds.end();
      p--;
      int Msize= (*p).size();
      return Msize;
   }
   void printMax(){
      p=inds.end();
      p--;
      list<int>::iterator tp;
      for(tp=(*p).begin();tp!=(*p).end();tp++){
        cout<<*tp<<endl;
      }
      return;
   }
   void increment(int i){
      p=inds.end();
      int ele= i;
      int ncount= pcount[ele];
      list<list<int> >::iterator nlite= lite[i];
      list<list<int> >::iterator olite= lite[i];
      int csize=(*olite).size();
        /*int csize;
         list<int>::iterator x= (*lite[i]).begin();
         list<int>::iterator y= (*lite[i]).end();
         y--;
         if((*x)==(*y)) {csize=1;}
         else{csize=2;}*/
      nlite++;
      if(nlite!=p){
         int tele= *((*nlite).begin());
         int tcount= pcount[tele];
         if(tcount==(ncount+1)){
            int t=ele;
            if(csize==1){
                (*lite[i]).resize(0);
                inds.erase(lite[i]);
            }
            else{
                if(*(*lite[i]).begin()==*ite[i]){
                    lite[i]->pop_front();
                }
                else{
                    (lite[i])->erase(ite[i]);
                }
            }
            lite[i]=nlite;
            (*nlite).insert((*nlite).end(),t);
            ite[i]=(*nlite).end();
            ite[i]--;
         }
         else{
            list<int> tlist;
            int t=ele;
            if(csize==1){
                (*lite[i]).resize(0);
                inds.erase(lite[i]);
            }
            else{
                if(*(*lite[i]).begin()==*ite[i]){
                    lite[i]->pop_front();
                }
                else{
                    (lite[i])->erase(ite[i]);
                }
            }
            tlist.insert(tlist.end(),t);
            inds.insert(nlite,tlist);
            ite[i]= tlist.begin();
            lite[i]= --nlite;
         }
      }
      else{
            list<int> tlist;
            int t=ele;
            if(csize==1){
                (*lite[i]).resize(0);
                inds.erase(lite[i]);
            }
            else{
                if(*(*lite[i]).begin()==*ite[i]){
                    lite[i]->pop_front();
                }
                else{
                    (lite[i])->erase(ite[i]);
                }
            }
            tlist.push_back(t);
            inds.push_back(tlist);
            ite[i]= tlist.begin();
            lite[i]= inds.end();
            lite[i]--;
      }
      ++pcount[ele];
      return ;
   }

   void decrement(int i){
      p=inds.begin();
      int ele= i;
      int ncount= pcount[ele];
      list<list<int> >::iterator nlite= lite[i];
      int csize=(*nlite).size();
      if(nlite!=p){
         nlite--;
         int tele= *((*nlite).begin());
         int tcount= pcount[tele];
         if(tcount==(ncount-1)){
            int t=ele;
            if(csize==1){
                (*lite[i]).resize(0);
                inds.erase(lite[i]);
            }
            else{
                if(*(*lite[i]).begin()==*ite[i]){
                    lite[i]->pop_front();
                }
                else{
                    (lite[i])->erase(ite[i]);
                }
            }
            lite[i]=nlite;
            (*nlite).insert((*nlite).end(),t);
            ite[i]=(*nlite).end();
            ite[i]--;
         }
         else{
            list<int> tlist;
            int t=ele;
            nlite++;
            tlist.insert(tlist.end(),t);
            inds.insert(nlite,tlist);
            nlite--;
            if(csize==1){
                (*lite[i]).resize(0);
                inds.erase(lite[i]);
            }
            else{
                if(*(*lite[i]).begin()==*ite[i]){
                    lite[i]->pop_front();
                }
                else{
                    (lite[i])->erase(ite[i]);
                }
            }
            ite[i]= tlist.begin();
            lite[i]= nlite;
         }
      }
      else{
            list<int> tlist;
            int t=ele;
            if(csize==1){
                (*lite[i]).resize(0);
                inds.erase(lite[i]);
            }
            else{
                if(*(*lite[i]).begin()==*ite[i]){
                    lite[i]->pop_front();
                }
                else{
                    (lite[i])->erase(ite[i]);
                }
            }
            tlist.push_back(t);
            inds.push_front(tlist);
            ite[i]= tlist.begin();
            lite[i]= inds.begin();
      }
      --pcount[ele];
      return ;
   }
};

int main(){
  counter c(5);
  c.increment(1);
  c.increment(3);
  c.increment(2);
  cout<<"page values:"<<endl;
  for(int k=0;k<5;k++){
  cout<<c.count(k)<<endl;}
  cout<<c.findMax()<<endl;
  cout<<c.numMax()<<endl;
  c.printMax();
  cout<<endl<<endl;
  c.increment(0);
  c.increment(4);
  c.increment(4);
  c.increment(0);
  cout<<"page values:"<<endl;
  for(int k=0;k<5;k++){
  cout<<c.count(k)<<endl;}
  cout<<c.findMax()<<endl;
  cout<<c.numMax()<<endl;
  c.printMax();
  cout<<endl<<endl;
  c.reset(3);
  cout<<"page values:"<<endl;
  for(int k=0;k<5;k++){
  cout<<c.count(k)<<endl;}
  cout<<c.findMax()<<endl;
  cout<<c.numMax()<<endl;
  c.printMax();
  cout<<endl<<endl;
  c.reset(0);
  cout<<"page values:"<<endl;
  for(int k=0;k<5;k++){
  cout<<c.count(k)<<endl;}
  cout<<c.findMax()<<endl;
  cout<<c.numMax()<<endl;
  c.printMax();
  cout<<endl<<endl;
  c.decrement(4);
  cout<<"page values:"<<endl;
  for(int k=0;k<5;k++){
  cout<<c.count(k)<<endl;}
  cout<<c.findMax()<<endl;
  cout<<c.numMax()<<endl;
  c.printMax();
  cout<<endl<<endl;
  c.decrement(4);
  cout<<"page values:"<<endl;
  for(int k=0;k<5;k++){
  cout<<c.count(k)<<endl;}
  cout<<c.findMax()<<endl;
  cout<<c.numMax()<<endl;
  c.printMax();
  cout<<endl<<endl;
  c.decrement(2);
  cout<<"page values:"<<endl;
  for(int k=0;k<5;k++){
  cout<<c.count(k)<<endl;}
  cout<<c.findMax()<<endl;
  cout<<c.numMax()<<endl;
  c.printMax();
  cout<<endl<<endl;
  c.decrement(1);
  cout<<"page values:"<<endl;
  for(int k=0;k<5;k++){
  cout<<c.count(k)<<endl;}
  cout<<c.findMax()<<endl;
  cout<<c.numMax()<<endl;
  c.printMax();
  cout<<endl<<endl;
  return 0;
  }
