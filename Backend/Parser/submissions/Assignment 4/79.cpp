#include<iostream>
#include<vector>
#include<list>

using namespace std;

class counter
{
    vector<int> a;
    vector< list<int>::iterator> posc;
    vector< list<list<int> >::iterator >   posm;
    vector< list<int>::iterator >    c;
    vector< list<int>::iterator>    s;

        int N;

    list<int>::iterator  zero,zeroc,zeros;
    list<list<int> >::iterator  zerom;

    list<list<int> > L;
    list<int> co;
    list<int> siz;
public:
    counter(int n)
    {     N=n;
        a.resize(n);
        int i;
        for(i=0; i<n; i++)
        {
            a[i]=0;
        }

        list<int>  d;
        //d.push_back(n);
        for(i=0; i<=n; i++)
        {
            d.push_back(i);
        }

        L.push_back(d);
        co.push_back(0);
        siz.push_back(n+1);
        zero=((L.begin())->begin());
        zerom=L.begin();
        zeroc=co.begin();
        zeros=siz.begin();

        list<int>::iterator j;
        j=(L.begin())->begin();


        for(i=0; i<n; i++,j++)
        {
            posc.push_back(j);
            posm.push_back(L.begin());
            c.push_back(co.begin());
            s.push_back(siz.begin());
        }

        return ;
    }


    void increment(int i)
    {
        a[i]=a[i]+1;
        list<int>::iterator  opc,oc,os,npc,nc,ns,t;
        list<list<int> >::iterator  npm,opm,tp;

        opc=posc[i];
        oc=c[i];
        os=s[i];
        opm=posm[i];

        t=oc;
        (t)++;

        if(t==co.end())
        {
            list<int>  d;
            d.push_back(i);
            L.push_back(d);
            co.push_back((*oc)+1);
            siz.push_back(1);

            nc=co.end();
            (nc)--;
            ns=siz.end();
            (ns)--;
            npm=L.end();
            (npm)--;
            npc=npm->end();
            (npc)--;

            if((*os)==1)
            {
                posm[i]->erase(posc[i]);
                L.erase(posm[i]);
                co.erase(c[i]);
                siz.erase(s[i]);
                posc[i]=npc;
                posm[i]=npm;
                c[i]=nc;
                s[i]=ns;

            }
            else
            {
                posm[i]->erase(posc[i]);
                (*s[i])--;

                posc[i]=npc;
                posm[i]=npm;
                c[i]=nc;
                s[i]=ns;

            }



        }

        else
        {
            t=oc;
            t++;
            if(((*oc)+1)==*t)
            {

                tp=opm;
                (tp)++;
                tp->push_back(i);

                t=os;
                t++;
                (*t)++;

                nc=oc;
                nc++;
                ns=os;
                ns++;
                npm=opm;
                npm++;
                npc=npm->end();
                npc--;

                if((*os)==1)
                {
                    posm[i]->erase(posc[i]);
                    L.erase(posm[i]);
                    co.erase(c[i]);
                    siz.erase(s[i]);
                    posc[i]=npc;
                    posm[i]=npm;
                    c[i]=nc;
                    s[i]=ns;

                }
                else
                {
                    posm[i]->erase(posc[i]);
                    (*s[i])--;
                    posc[i]=npc;
                    posm[i]=npm;
                    c[i]=nc;
                    s[i]=ns;

                }




            }

            else
            {


                list<int>   d;
                d.push_back(i);
                tp=opm;
                (tp)++;
                L.insert(tp,d);
                t=oc;
                t++;
                co.insert(t,(*oc)+1);
                t=os;
                t++;
                siz.insert(t,1);


                nc=oc;
                nc++;
                ns=os;
                ns++;
                npm=opm;
                npm++;
                npc=npm->end();
                npc--;


                if((*os)==1)
                {
                    posm[i]->erase(posc[i]);
                    L.erase(posm[i]);
                    co.erase(c[i]);
                    siz.erase(s[i]);
                    posc[i]=npc;
                    posm[i]=npm;
                    c[i]=nc;
                    s[i]=ns;

                }
                else
                {
                    posm[i]->erase(posc[i]);
                    (*s[i])--;
                    posc[i]=npc;
                    posm[i]=npm;
                    c[i]=nc;
                    s[i]=ns;

                }




            }


        }



    }

    void decrement(int i)
    {
        a[i]=a[i]-1;
        list<int>::iterator  opc,oc,os,npc,nc,ns,t;
        list<list<int> >::iterator  npm,opm,tp;



        opc=posc[i];
        oc=c[i];
        os=s[i];
        opm=posm[i];

        t=oc;
        if(t==co.begin())
        {

            list<int>  d;
            d.push_back(i);
            L.push_front(d);
            co.push_front((*oc)-1);
            siz.push_front(1);

            nc=co.begin();

            ns=siz.begin();

            npm=L.begin();

            npc=npm->end();
            (npc)--;

            if((*os)==1)
            {
                posm[i]->erase(posc[i]);

                L.erase(posm[i]);
                co.erase(c[i]);
                siz.erase(s[i]);
                posc[i]=npc;
                posm[i]=npm;
                c[i]=nc;
                s[i]=ns;

            }
            else
            {
                posm[i]->erase(posc[i]);

                (*s[i])--;
                posc[i]=npc;
                posm[i]=npm;
                c[i]=nc;
                s[i]=ns;

            }



        }

        else
        {
            t=oc;
            t--;
            if(((*oc)-1)==*t)
            {

                tp=opm;
                (tp)--;
                tp->push_back(i);

                t=os;
                t--;
                (*t)++;

                nc=oc;
                nc--;
                ns=os;
                ns--;
                npm=opm;
                npm--;
                npc=npm->end();
                npc--;

                if((*os)==1)
                {
                    posm[i]->erase(posc[i]);
                    L.erase(posm[i]);
                    co.erase(c[i]);
                    siz.erase(s[i]);
                    posc[i]=npc;
                    posm[i]=npm;
                    c[i]=nc;
                    s[i]=ns;

                }
                else
                {
                    posm[i]->erase(posc[i]);
                    (*s[i])--;
                    posc[i]=npc;
                    posm[i]=npm;
                    c[i]=nc;
                    s[i]=ns;

                }


            }

            else
            {


                list<int>   d;
                d.push_back(i);
                tp=opm;

                L.insert(tp,d);
                t=oc;

                co.insert(t,(*oc)-1);
                t=os;

                siz.insert(t,1);


                nc=oc;
                nc--;
                ns=os;
                ns--;
                npm=opm;
                npm--;
                npc=npm->end();
                npc--;

                if((*os)==1)
                {
                    posm[i]->erase(posc[i]);

                    L.erase(posm[i]);
                    co.erase(c[i]);
                    siz.erase(s[i]);
                    posc[i]=npc;
                    posm[i]=npm;
                    c[i]=nc;
                    s[i]=ns;

                }
                else
                {
                    posm[i]->erase(posc[i]);
                    (*s[i])--;
                    posc[i]=npc;
                    posm[i]=npm;
                    c[i]=nc;
                    s[i]=ns;

                }



            }



        }


        return ;


    }


    void reset(int i)
    {
        a[i]=0;
        list<int>::iterator  opc,oc,os,npc,nc,ns,t;
        list<list<int> >::iterator  npm,opm,tp;

        opc=posc[i];
        oc=c[i];
        os=s[i];
        opm=posm[i];

        zerom->push_back(i);
        (*zeros)++;
        nc=zeroc;

        ns=zeros;

        npm=zerom;

        npc=npm->end();
        npc--;

        if((*os)==1)
        {
            posm[i]->erase(posc[i]);
            L.erase(posm[i]);
            co.erase(c[i]);
            siz.erase(s[i]);
            posc[i]=npc;
            posm[i]=npm;
            c[i]=nc;
            s[i]=ns;

        }
        else
        {
            posm[i]->erase(posc[i]);
            (*s[i])--;
            posc[i]=npc;
            posm[i]=npm;
            c[i]=nc;
            s[i]=ns;

        }


        return ;
    }

    int count(int i)
    {

        return a[i];

    }

    int findMax()
    {
        list<int>::iterator  p;
        p=co.end();
        p--;
        if(((*p)==0)&&((*zeros)==1))
        {
            p--;

            return *p;
        }
        else
        {

            return *p;
        }
    }

   int numMax()
   {
    list<int>::iterator  p,q;
        p=co.end();
        p--;
        q=siz.end();
        q--;
        if(((*p)==0)&&((*zeros)==1))
        {
            q--;

            return *q;
        }
        else
        {

           if(((*p)==0)&&((*zeros)!=1))
           {
               return (*q)-1;

           }
            return *q;

        }

   }

void printMax()
{   int i;
    list<int>::iterator  p,q,r;
    list<list<int> >::iterator  e;
    e=L.end();
    e--;
        p=co.end();
        p--;
        q=siz.end();
        q--;
        if(((*p)==0)&&((*zeros)==1))
        {
        e--;
         p=e->begin();

         for(p;p!=(e->end());p++)
         {
             cout<<(*p)<<endl;
         }
           return ;
        }
        else
        {

           if(((*p)==0)&&((*zeros)!=1))
           {
               p=e->begin();

               for(p;p!=(e->end());p++)
         {   if((*p)!=N){
             cout<<(*p)<<endl;}
         }
           return ;

           }

             p=e->begin();

               for(p;p!=(e->end());p++)
         {
             cout<<(*p)<<endl;
         }
           return ;

        }


}


};











