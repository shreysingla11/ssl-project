#include<iostream>
#include<vector>
#include<list>

using namespace std;

class counter
{
    vector <int> counts;
    list<list<int> > lcount;
    vector< list<int>::iterator > var;
    vector< list<list<int> >::iterator > lvar;
    list<list<int> >::iterator row;
    list<int> ::iterator column;
    list<int> tlist;
    int n;
public:


    counter(int N)
    {
        n=N;
        counts.resize(n);
        var.resize(n);
        list<int> t;
        for(int i=0; i<n; i++)
        {
            t.push_back(i);
            counts[i]=0;
        }
        lcount.push_back(t);
        for(int i=0; i<n; i++)
        {
            lvar.push_back(lcount.begin());
        }
        var[0]=(*lvar[0]).begin();
        for(int i=1; i<n; i++)
        {
            var[i]=var[i-1];
            var[i]++;
        }
    }

    void increment(int i)
    {
        row=lcount.end();
        int ncount= ++counts[i];
        list<list<int> >::iterator nlvar= lvar[i];
        list<list<int> >::iterator olvar= lvar[i];
        int csize=(*olvar).size();
        nlvar++;
        if(nlvar!=row)
        {
            column = (*nlvar).begin();
            int element= *(column);
            int tcount= counts[element];
            if(tcount==ncount)
            {
                if(csize==1)
                {
                    (*lvar[i]).resize(0);
                    lcount.erase(lvar[i]);
                }
                else
                {
                    column =(*lvar[i]).begin();
                    if(*column==*var[i])
                    {
                        lvar[i]->pop_front();
                    }
                    else
                    {
                        (lvar[i])->erase(var[i]);
                    }
                }
                lvar[i]=nlvar;
                (*nlvar).insert((*nlvar).end(),i);
                var[i]=(*nlvar).end();
                var[i]--;
            }
            else
            {
                if(csize==1)
                {
                    (*lvar[i]).resize(0);
                    lcount.erase(lvar[i]);
                }
                else
                {
                    column =(*lvar[i]).begin();
                    if(*column==*var[i])
                    {
                        lvar[i]->pop_front();
                    }
                    else
                    {
                        (lvar[i])->erase(var[i]);
                    }
                }
                tlist.insert(tlist.end(),i);
                lcount.insert(nlvar,tlist);
                var[i]= tlist.begin();
                lvar[i]= --nlvar;
                tlist.erase(tlist.begin());
            }
        }
        else
        {
            if(csize==1)
            {
                (*lvar[i]).resize(0);
                lcount.erase(lvar[i]);
            }
            else
            {
                column =(*lvar[i]).begin();
                if(*column==*var[i])
                {
                    lvar[i]->pop_front();
                }
                else
                {
                    (lvar[i])->erase(var[i]);
                }
            }
            tlist.push_back(i);
            lcount.push_back(tlist);
            var[i]= tlist.begin();
            lvar[i]= lcount.end();
            lvar[i]--;
            tlist.erase(tlist.begin());
        }
        return ;
    }

    void decrement(int i)
    {
        row=lcount.begin();
        int ncount= --counts[i];
        list<list<int> >::iterator nlvar= lvar[i];
        int csize=(*nlvar).size();
        if(nlvar!=row)
        {
            nlvar--;
            column =(*nlvar).begin();
            int element= *(column);
            int tcount= counts[element];
            if(tcount==ncount)
            {
                if(csize==1)
                {
                    (*lvar[i]).resize(0);
                    lcount.erase(lvar[i]);
                }
                else
                {
                    column =(*lvar[i]).begin();
                    if(*column==*var[i])
                    {
                        lvar[i]->pop_front();
                    }
                    else
                    {
                        (lvar[i])->erase(var[i]);
                    }
                }
                lvar[i]=nlvar;
                (*nlvar).insert((*nlvar).end(),i);
                var[i]=(*nlvar).end();
                var[i]--;
            }
            else
            {
                nlvar++;
                tlist.insert(tlist.end(),i);
                lcount.insert(nlvar,tlist);
                nlvar--;
                if(csize==1)
                {
                    (*lvar[i]).resize(0);
                    lcount.erase(lvar[i]);
                }
                else
                {
                    column =(*lvar[i]).begin();
                    if(*column==*var[i])
                    {
                        lvar[i]->pop_front();
                    }
                    else
                    {
                        (lvar[i])->erase(var[i]);
                    }
                }
                var[i]= tlist.begin();
                lvar[i]= nlvar;
                tlist.erase(tlist.begin());
            }
        }
        else
        {
            if(csize==1)
            {
                (*lvar[i]).resize(0);
                lcount.erase(lvar[i]);
            }
            else
            {
                column =(*lvar[i]).begin();
                if(*column==*var[i])
                {
                    lvar[i]->pop_front();
                }
                else
                {
                    (lvar[i])->erase(var[i]);
                }
            }
            tlist.push_back(i);
            lcount.push_front(tlist);
            var[i]= tlist.begin();
            lvar[i]= lcount.begin();
            tlist.erase(tlist.begin());
        }
        return ;
    }

    void reset(int i)
    {
        counts[i]=0;
        list<list<int> >::iterator olvar= lvar[i];
        list<list<int> >::iterator nlvar= lcount.begin();
        column =(*nlvar).begin();
        int element= *(column);
        int tcount= counts[element];
        int csize=(*olvar).size();
        if(tcount==0)
        {
            if(csize==1)
            {
                (*lvar[i]).resize(0);
                lcount.erase(lvar[i]);
            }
            else
            {
                column =(*lvar[i]).begin();
                if(*column==*var[i])
                {
                    lvar[i]->pop_front();
                }
                else
                {
                    (lvar[i])->erase(var[i]);
                }
            }
            lvar[i]=(--nlvar);
            (*nlvar).insert((*nlvar).end(),i);
            var[i]=(*nlvar).end();
            var[i]--;
        }
        else
        {
            if(csize==1)
            {
                (*lvar[i]).resize(0);
                lcount.erase(lvar[i]);
            }
            else
            {
                column =(*lvar[i]).begin();
                if(*column==*var[i])
                {
                    lvar[i]->pop_front();
                }
                else
                {
                    (lvar[i])->erase(var[i]);
                }
            }
            tlist.insert(tlist.end(),i);
            lcount.insert(nlvar,tlist);
            var[i]= tlist.begin();
            lvar[i]= nlvar;
            tlist.erase(tlist.begin());
        }
        return;
    }

    int count(int i)
    {
        return counts[i];
    }

    int findMax()
    {
        row=lcount.end();
        row--;
        column =(*row).begin();
        int maxindex= *(column);
        int max= counts[maxindex];
        return max;
    }

    int numMax()
    {
        row=lcount.end();
        row--;
        int maxnumbers= (*row).size();
        return maxnumbers;
    }

    void printMax()
    {
        row=lcount.end();
        row--;
        column=(*row).begin();
        while(column!=(*row).end())
        {
            cout<<*column<<endl;
            column++;
        }
        return;
    }
};




