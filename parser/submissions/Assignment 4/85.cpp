#include<iostream>
#include<cstdio>
#include<vector>
#include<list>
#include<cstddef>
using namespace std;
class counter
    {
     class wp
        {
         public:
         int n;
         int count;
        };
     list <list<wp> > l;
     list <list<wp> > lwaste;

     list<list<wp> >::iterator nil=lwaste.begin();
     list<wp> l1;
     vector<list <list<wp> >::iterator> v;
    vector<list <list<wp> >::iterator> vneg;
     vector<list<wp>::iterator> v1;
     public:
     counter(int n)
        {
        for (int i=0;i<n;i++)
        {
         wp temp;
         temp.n=i;
         temp.count=0;
         l1.push_back(temp);
        }
     l.push_back(l1);
     l1.clear();
     list<list<wp> >::iterator p=l.begin();
     v.push_back(p);
     vneg.push_back(p);
     list<wp>::iterator p1=p->begin();
     for (int i=0;i<n;i++)
        {
         v1.push_back(p1);
         p1++;
        }
       }

     void increment(int i)
     {

     int t=v1[i]->count;
     if(t>0)
     {
     if((t+1)>=v.size())
        {
         l1.clear();
         wp temp;
         temp.count=t+1;
         temp.n=i;
         l1.push_back(temp);
         l.push_back(l1);
         l1.clear();
         v.push_back((--l.end()));
         v[t]->erase(v1[i]);
         v1[i]=(--v[t+1]->end());
         if(v[t]->empty())
            {
             l.erase(v[t]);
             v[t]=nil;
            }
        }
     else if (v[t+1]==nil)
        {
         v[t]++;
         l1.clear();
         wp temp;
         temp.n=i;
         temp.count=t+1;
         l1.push_back(temp);
         l.insert(v[t],l1);
         l1.clear();
         v[t]--;
         v[t+1]=v[t];
         v[t]--;
         v[t]->erase(v1[i]);
         v1[i]=(--v[t+1]->end());
         if(v[t]->empty())
            {
             l.erase(v[t]);
             v[t]=nil;
            }
        }

    else
        {
         wp temp;
         temp.n=i;
         temp.count=t+1;
         v[t+1]->push_back(temp);
         v[t]->erase(v1[i]);
         v1[i]=(--v[t+1]->end());
       if(v[t]->empty())
        {
             l.erase(v[t]);
             v[t]=nil;
            }
        }
        }

if(t==0)
     {
     if((t+1)>=v.size())
        {
         l1.clear();
         wp temp;
         temp.count=t+1;
         temp.n=i;
         l1.push_back(temp);
         l.push_back(l1);
         l1.clear();
         v.push_back((--l.end()));
         v[t]->erase(v1[i]);
         v1[i]=(--v[t+1]->end());

        }
     else if (v[t+1]==nil)
        {
         v[t]++;
         l1.clear();
         wp temp;
         temp.n=i;
         temp.count=t+1;
         l1.push_back(temp);
         l.insert(v[t],l1);
         l1.clear();
         v[t]--;
         v[t+1]=v[t];
         v[t]--;
         v[t]->erase(v1[i]);
         v1[i]=(--v[t+1]->end());

        }

    else
        {
         wp temp;
         temp.n=i;
         temp.count=t+1;
         v[t+1]->push_back(temp);
         v[t]->erase(v1[i]);
         v1[i]=(--v[t+1]->end());

        }
        }

if(t<-1)
    {
     t=-t;
     if (vneg[t-1]==nil)
        {
         vneg[t]++;
         l1.clear();
         wp temp;
         temp.n=i;
         temp.count=-(t-1);
         l1.push_back(temp);
         l.insert(vneg[t],l1);
         l1.clear();
         vneg[t]--;
         vneg[t-1]=vneg[t];
         vneg[t]--;
         vneg[t]->erase(v1[i]);
         v1[i]=(--vneg[t-1]->end());
         if(vneg[t]->empty())
            {
             l.erase(vneg[t]);
             vneg[t]=nil;
            }
        }

    else
     {
         wp temp;
         temp.n=i;
         temp.count=-(t-1);
         vneg[t-1]->push_back(temp);
         vneg[t]->erase(v1[i]);
         v1[i]=(--vneg[t-1]->end());
         if(vneg[t]->empty())
            {
             l.erase(vneg[t]);
             vneg[t]=nil;
            }
        }

    }

if (t==-1)
    {
     t=-t;
     wp temp;
     temp.n=i;
     temp.count=t-1;
     vneg[t-1]->push_back(temp);
     vneg[t]->erase(v1[i]);
     v1[i]=(--vneg[t-1]->end());
     if(vneg[t]->empty())
         {
          l.erase(vneg[t]);
          vneg[t]=nil;
         }
   }
   }


     void decrement(int i)
         {
     int t=v1[i]->count;
     if(t>1)
     {
      if (v[t-1]==nil)
        {
         l1.clear();
         wp temp;
         temp.n=i;
         temp.count=t-1;
         l1.push_back(temp);
         l.insert(v[t],l1);
         l1.clear();
         v[t]--;
         v[t-1]=v[t];
         v[t]++;
         v[t]->erase(v1[i]);
         v1[i]=(--v[t-1]->end());
         if(v[t]->empty())
            {
             l.erase(v[t]);
             v[t]=nil;
            }
        }
    else
     {
         wp temp;
         temp.n=i;
         temp.count=t-1;
         v[t-1]->push_back(temp);
         v[t]->erase(v1[i]);
         v1[i]=(--v[t-1]->end());
         if(v[t]->empty())
            {
             l.erase(v[t]);
             v[t]=nil;
            }
        }
     }
 if(t==1)
    {
     wp temp;
     temp.n=i;
     temp.count=t-1;
     v[t-1]->push_back(temp);
     v[t]->erase(v1[i]);
     v1[i]=(--v[t-1]->end());
     if(v[t]->empty())
        {
         l.erase(v[t]);
         v[t]=nil;
        }
    }
if(t==0)
    {
     if((t+1)>=vneg.size())
      {
       l1.clear();
       wp temp;
       temp.count=t-1;
       temp.n=i;
       l1.push_back(temp);
       l.push_front(l1);
       l1.clear();
       vneg.push_back((l.begin()));

       vneg[t]->erase(v1[i]);

       v1[i]=(--vneg[t+1]->end());

      }
     else if (vneg[t+1]==nil)
        {
         l1.clear();
         wp temp;
         temp.n=i;
         temp.count=t-1;
         l1.push_back(temp);
         l.insert(vneg[t],l1);
         l1.clear();
         vneg[t]--;
         vneg[t+1]=vneg[t];
         vneg[t]++;
         vneg[t]->erase(v1[i]);
         v1[i]=(--vneg[t+1]->end());
        }

    else
        {
         wp temp;
         temp.n=i;
         temp.count=t-1;
         vneg[t+1]->push_back(temp);
         vneg[t]->erase(v1[i]);
         v1[i]=(--vneg[t+1]->end());
       }
    }
if (t<0)
    {
     t=-t;
     if((t+1)>=vneg.size())
        {
         l1.clear();
         wp temp;
         temp.count=-(t+1);
         temp.n=i;
         l1.push_back(temp);
         l.push_front(l1);
         l1.clear();

         vneg.push_back((l.begin()));
         vneg[t]->erase(v1[i]);
         v1[i]=(--vneg[t+1]->end());

         if(vneg[t]->empty())
            {
             l.erase(vneg[t]);
             vneg[t]=nil;
            }

        }
     else if (vneg[t+1]==nil)
        {
         l1.clear();
         wp temp;
         temp.n=i;
         temp.count=-(t+1);
         l1.push_back(temp);
         l.insert(vneg[t],l1);
         l1.clear();
         vneg[t]--;
         vneg[t+1]=vneg[t];
         vneg[t]++;
         vneg[t]->erase(v1[i]);
         v1[i]=(--vneg[t+1]->end());
         if(vneg[t]->empty())
            {
             l.erase(vneg[t]);
             vneg[t]=nil;
            }
        }

    else
        {
         wp temp;
         temp.n=i;
         temp.count=-(t+1);
         vneg[t+1]->push_back(temp);
         vneg[t]->erase(v1[i]);
         v1[i]=(--vneg[t+1]->end());
       if(vneg[t]->empty())
        {
             l.erase(vneg[t]);
             vneg[t]=nil;
            }
        }
    }
    }

     void reset(int i)
           {
     int t=v1[i]->count;
     if(t>0)
     {
      wp temp;
      temp.n=i;
      temp.count=0;
      v[0]->push_back(temp);
      v[t]->erase(v1[i]);
      v1[i]=(--v[0]->end());
      if(v[t]->empty())
         {
          l.erase(v[t]);
          v[t]=nil;
         }
       }
 if(t<0)
    {
     t=-t;
     wp temp;
     temp.n=i;
     temp.count=0;
     vneg[0]->push_back(temp);
     vneg[t]->erase(v1[i]);
     v1[i]=(--vneg[0]->end());
     if(vneg[t]->empty())
         {
          l.erase(vneg[t]);
          vneg[t]=nil;
         }
    }
    }

     int count(int i)
         {
           int t= v1[i]->count;
           return t;
         }
     int findMax()
        {
      list <list<wp> >::iterator p4=(--l.end());
      list< wp >::iterator p5=p4->begin();
      int t=p5->count;
      if(t==0&&p4->empty())
        {
         --p4;
         p5=p4->begin();
         t=p5->count;
        }
      return t;
    }

     int numMax()
        {
     list <list<wp> >::iterator p4=(--l.end());
     list< wp >::iterator p5=p4->begin();
     int u=p5->count;
     int t=p4->size();
     if (t==0&&u==0)
        {
         --p4;
         t=p4->size();
        }
     return t;
    }
     void printMax()
        {
     list <list<wp> >::iterator p4=(--l.end());
     list< wp >::iterator p5=p4->begin();
     if(p4->empty()&&p5->count==0)
        {
         --p4;
         p5=p4->begin();
        }
      for (;p5!=p4->end();p5++)
            {
             printf("%d ",p5->n);
             //cout<<p5->n<<" ";
            }

    }

    };


