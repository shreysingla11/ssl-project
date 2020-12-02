#include<iostream>
#include<vector>
#include<list>
using namespace std;
class counter{
vector<int>V;
list< list<int> > L;
vector< list<int> :: iterator >Vi;
vector< list< list<int> > :: iterator >Vl;
public:
counter(int n){V.resize(n,0);
              list<int>l;int i;


                for(i=0;i<n;i++){

                                  l.insert(l.begin(),i);

                                  Vi.push_back(l.begin());


                                     }
              L.insert(L.begin(),l);
             Vl.resize(n,L.begin());


                              }

void increment(int i){
       V[i]=V[i]+1;// cout<<" rame gg "<<i<<endl;

     (*Vl[i]).remove(i);//delete elem from inner list
       // cout<<"                     "<<(*Vl[i]).empty()<<endl;
     if((*Vl[i]).empty()){L.erase(Vl[i]);  }

      list< list<int> > :: iterator ite ,nxlist;
      ite=Vl[i];
      nxlist=ite++;

          if(ite == L.end())  {     //if its the last list create new list and append;
             // cout<<"one list is last"<<endl;
            list<int>m;
            m.insert(m.begin(),i);
             Vi[i]=m.begin();

             L.push_back(m);
                Vl[i]=--L.end();


                                           }

       else            {//if the present list is not end one
                               // cout<<"current count "<<V[i]<<" nexts count  "<<*((*(ite)).begin())<<endl;
                            if(V[i]==V[*((*(ite)).begin())])   {//if next list is of one larger count

                                                (*ite).push_back(i);
                                                Vi[i]= --((*ite).end());
                                                 Vl[i]= ite;
                                                                     }


                      else      {                  //if not create a list and insert bwn list and nextlist
                                  list<int>l;
                                  l.insert(l.begin(),i);
                                  Vi[i]=l.begin();
                                L.insert(ite,l);
                                     ite--;
                                 Vl[i]= ite;

                                  }

                         }

      //   cout<<"size is  "<<L.size()<<endl;
                       }


void decrement(int i){
                  V[i]=V[i]-1;// cout<<" rame decri "<<i<<endl;

     (*Vl[i]).remove(i);//delete elem from inner list
       // cout<<"                     "<<(*Vl[i]).empty()<<endl;
     if((*Vl[i]).empty()){L.erase(Vl[i]);  }

      list< list<int> > :: iterator ite ,prlist;
      ite=Vl[i];
     // prlist=ite--;

          if(ite == L.begin())  {     //if its the last list create new list and append;
             // cout<<"this list is first"<<endl;
            list<int>m;
            m.insert(m.begin(),i);
             Vi[i]=m.begin();

             L.push_front(m);
                Vl[i]=L.begin();


                                           }


       else            {//if the present list is not end one
                            ite--;
                              //  cout<<"current count "<<V[i]<<" nexts count  "<<*((*(ite)).begin())<<endl;
                            if(V[i]==V[*((*(ite)).begin())])   {//if next list is of one larger count

                                                (*ite).push_back(i);
                                                Vi[i]= --((*ite).end());
                                                 Vl[i]= ite;
                                                                     }


                      else      {                  //if not create a list and insert bwn list and nextlist
                                  list<int>l;
                                  l.insert(l.begin(),i);
                                  Vi[i]=l.begin();
                                  ite++;
                                L.insert(ite,l);
                                     ite--;
                                 Vl[i]= ite;

                                  }

                         }

      //   cout<<" dec size is  "<<L.size()<<endl;




                       }

void  reset(int i) {
             V[i]=0;// cout<<" reset "<<i<<endl;

     (*Vl[i]).remove(i);//delete elem from inner list
       // cout<<"        in reset             "<<(*Vl[i]).empty()<<endl;
     if((*Vl[i]).empty()){L.erase(Vl[i]);  }

            list< list<int> > :: iterator ite ,nxlist;
               if(V[*((*(L.begin())).begin())]==0){//if beginning is still 0 insert in first list itself
                              ( *(L.begin())).push_back(i);
                                   Vi[i]= --((*(L.begin())).end());
                                   Vl[i]=L.begin();
                                                  }
                else{            //else create new list and add at beginning;
                   list<int>l;
                                  l.insert(l.begin(),i);
                                  Vi[i]=l.begin();
                                L.push_front(l);
                                 Vl[i]= L.begin();
                     }

                            }

int count(int i) {return V[i];}

int findMax(){
            list< list<int> > :: iterator ite;
            ite=L.end();
            ite--;

           return V[(*(*(ite)).begin())];
              }

int numMax() {
              list< list<int> > :: iterator ite;
            ite=L.end();
             ite--;
             return (*(ite)).size();
               }
void printMax(){
          list< list<int> > :: iterator ite;
           list<int> :: iterator  i;
              ite=L.end();ite--;
          for(i=(*ite).begin();i!=(*ite).end();i++)  {

                                   cout<<*i<<" ";

                                                        } cout<<endl;

                                  }
             };
