#include <cstdio>
#include <vector>
#include <list>

using namespace std;

class counter
{
    private:
        class ind
        {
            public:
                int index;
                int page;
        };
        list<list<ind> > a;
        list<list<ind> >::iterator it;
        list<ind> ::iterator it2;
        vector<list <ind>::iterator > it2_list;
        vector<list <list <ind> >:: iterator > it_list;
        vector<list <list <ind> >:: iterator > it_list_n;
        int n;

    public:
        counter(int p)
        {
            n=p;
            a.clear();
            it_list.clear();
            it_list_n.clear();
            it2_list.clear();
            list<ind> x;
            for(int k=0;k<n;k++)
            {
                ind l;
                l.index=0;
                l.page=k;
                x.push_back(l);
            }
            a.push_back(x);
            it=a.begin();
            it_list.push_back(it);
            it2=it->begin();
            for(int k=0;k<n;k++)
            {
                it2_list.push_back(it2);
                it2++;
            }
        }

        void increment(int i)
        {
            it2=it2_list[i];
            int val=(*it2).index;
            int pag=(*it2).page;
            if(it_list.size()>val+1 && val>=0)
            {
                ind q;
                q.index=val+1;
                q.page=pag;
                it_list[val+1]->push_back(q);
                it_list[val]->erase(it2_list[i]);
                it=it_list[val+1];
                it2_list[i]=--(it->end());
            }
            else if(it_list.size()<=val+1 && val>=0)
            {
                it_list[val]->erase(it2);
                list<ind> x;
                ind q;
                q.index=val+1;
                q.page=pag;
                x.push_back(q);
                a.push_back(x);
                it=--a.end();
                it_list.push_back(it);
                it2_list[i]=(--it->end());
            }
            else if(val==-1)
            {
                ind q;
                q.index=val+1;
                q.page=pag;
                it_list[val+1]->push_back(q);
                it_list_n[-val-1]->erase(it2_list[i]);
                it=it_list[val+1];
                it2_list[i]=--(it->end());
            }
            else if(val<-1)
            {
                ind q;
                q.index=val+1;
                q.page=pag;
                it_list_n[-val]->push_back(q);
                it_list_n[-val-1]->erase(it2_list[i]);
                it=it_list_n[-val];
                it2_list[i]=--(it->end());
            }
        }

        void decrement(int i)
        {
            it2=it2_list[i];
            int val=(*it2).index;
            int pag=(*it2).page;
           if(val>=1)
           {
                ind q;
                q.index=val-1;
                q.page=pag;
                it_list[val-1]->push_back(q);
                it_list[val]->erase(it2_list[i]);
                it=it_list[val-1];
                it2_list[i]=--(it_list[val-1]->end());
            }
            else if(val==0 && it_list_n.size()>0)
            {
                ind q;
                q.index=val-1;
                q.page=pag;
                it_list_n[val]->push_back(q);
                it_list[val]->erase(it2_list[i]);
                it=it_list_n[val];
                it2_list[i]=--(it_list_n[val]->end());
            }
            else if(val==0 && it_list_n.size()==0)
            {
                ind q;
                q.index=val-1;
                q.page=pag;
                list<ind> x;
                x.push_back(q);
                a.push_front(x);
                it_list[val]->erase(it2_list[i]);
                it=a.begin();
                it_list_n.push_back(it);
                it2_list[i]=(--it->end());

            }
            else if(val<0 && it_list_n.size()<=-val)
            {
                ind q;
                q.index=val-1;
                q.page=pag;
                list<ind> x;
                x.push_back(q);
                a.push_front(x);
                it=a.begin();
                it_list_n.push_back(it);
                it2_list[i]=(--it->end());
            }
            else if(val<0 && it_list_n.size()>-val)
            {
                ind q;
                q.index=val-1;
                q.page=pag;
                it_list_n[-val]->push_back(q);
                it_list_n[-val-1]->erase(it2_list[i]);
                it=it_list_n[-val];
                it2_list[i]=--(it_list_n[-val]->end());
            }
        }


        void reset(int i)
        {
            it2=it2_list[i];
            int val=(*it2).index;
            int pag=(*it2).page;
            if(val>=0)
            {
                it_list[val]->erase(it2);
                it=it_list[0];
                ind q;
                q.index=0;
                q.page=pag;
                it->push_back(q);
                it2_list[i]=--(it->end());
            }
            else
            {
                it_list_n[-val-1]->erase(it2);
                it=it_list[0];
                ind q;
                q.index=0;
                q.page=pag;
                it->push_back(q);
                it2_list[i]==--(it->end());
            }
        }

        int count(int i)
        {
            it2=it2_list[i];
            int val=(*it2).index;
            return val;
        }

        int findMax()
        {
            it=--a.end();
            it2=it->begin();
            int val=(*it2).index;
            return val;
        }

        int numMax()
        {
            it=--a.end();
            return it->size();
        }

        void printMax()
        {
            int val=findMax();
            it=--a.end();
            it2=it->begin();
            while(it2!=it->end())
            {
                printf("%d ",(*it2).page);
                it2++;
            }
        }
};
