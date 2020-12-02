#include <iostream>
#include<vector>
#include<list>
using namespace std;

class counter{      list <list <counter> > mylist;
                    vector <list <counter> ::iterator> iters;
                    list <list <counter> > ::iterator parent;
                    list <list <counter> > ::iterator zero;
                    int id, c;
                    public:
                    counter(){}
                    counter(int n)
                    {
                        list <counter> list1;
                        mylist.push_back(list1);
                        zero=(mylist.begin());
                        counter count1;
                        for(int i=0; i<n; i++)
                        {
                            count1.id=i; count1.c=0;
                            count1.parent=zero;
                            zero->push_back(count1);
                            iters.push_back(--zero->end());
                        }
                    }
                    void increment(int i)
                    {
                            int c=(iters[i]->c);
                            if(iters[i]->parent==(--mylist.end()))
                            {   list <counter> list1;
                                mylist.push_back(list1);
                            }

                            iters[i]->parent++;
                            counter count1;
                            count1.id=i; count1.c=++c;
                            if(iters[i]->parent->begin()->c!=c&&iters[i]->parent->size()!=0)
                            {    list <counter> list1;
                                mylist.insert(iters[i]->parent,list1);
                                iters[i]->parent--;
                            }
                            iters[i]->parent--;
                            list <list <counter> > ::iterator temp=iters[i]->parent;
                            temp->erase(iters[i]);
                            count1.parent=++iters[i]->parent;
                            count1.parent->push_back(count1);
                            if(temp->size()==0&&temp!=zero) {mylist.erase(temp);}
                            iters[i]=--count1.parent->end();

                    }
                    void decrement(int i)
                    {       int c=(iters[i]->c);
                            if(iters[i]->parent==(mylist.begin()))
                            {   list <counter> list1;
                                mylist.push_front(list1);
                            }

                            iters[i]->parent--;
                            counter count1;
                            count1.id=i; count1.c=--c;
                            if(iters[i]->parent->begin()->c!=c&&iters[i]->parent->size()!=0)
                            {    list <counter> list1;
                                iters[i]->parent++;
                                mylist.insert(iters[i]->parent,list1);
                                iters[i]->parent--;
                                iters[i]->parent--;
                            }
                            iters[i]->parent++;
                            list <list <counter> > ::iterator temp=iters[i]->parent;
                            temp->erase(iters[i]);
                            count1.parent=--iters[i]->parent;
                            count1.parent->push_back(count1);
                            if(temp->size()==0&&temp!=zero) {mylist.erase(temp);}
                            iters[i]=--count1.parent->end();

                    }
                    void reset(int i)
                    {
                        int c=iters[i]->c;
                        if(c==0) return;
                        list <list <counter> > ::iterator temp=iters[i]->parent;
                        temp->erase(iters[i]);
                        counter count1;
                        count1.id=i; count1.c=0;
                        count1.parent=zero;
                        zero->push_back(count1);
                        iters[i]=--count1.parent->end();
                    }
                    int count(int i){ return (iters[i]->c);}
                    int findMax()
                    { if((--mylist.end())!=zero||zero->size()!=0)
                        return ((--mylist.end())->begin()->c);
                      else
                        return ((--(--mylist.end()))->begin()->c);
                    }
                    int numMax()
                    {  if((--mylist.end())!=zero||zero->size()!=0)
                        return ((--mylist.end())->size());
                      else
                        return ((--(--mylist.end()))->size());
                    }
                    void printMax()
                    {
                        if((--mylist.end())!=zero||zero->size()!=0)
                        {
                            list<counter> ::iterator printer=(--mylist.end())->begin();
                            for(int i=0; i<((--mylist.end())->size()); i++)
                            { cout<<(printer)->id<<"\t"; printer++;}
                            cout<<endl;
                        }
                        else
                        {
                            list<counter> ::iterator printer=(--(--mylist.end()))->begin();
                            for(int i=0; i<((--(--mylist.end()))->size()); i++)
                            { cout<<(printer)->id<<"\t"; printer++;}
                            cout<<endl;
                        }
                    }
                };

