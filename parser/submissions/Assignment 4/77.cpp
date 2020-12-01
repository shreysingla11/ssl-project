
class counter
{
    int n;
    vector<int> v;
    list<list<int> > L;

    list<list<int> >::iterator itx;
    list<int>::iterator ity;

    vector<list<int>::iterator> y;
    vector<list<list<int> >::iterator> x;

public:
    counter (int i)
    {
        n=i;
        v.resize(n);
        x.resize(n);
        y.resize(n);
        v.assign(n,0);

        list<int> m;
        for(int i=0; i<n; i++)
        {
            m.push_back(i);

        }
        L.push_back(m);
        itx=L.begin();
        ity=itx->begin();

        for(int i=0; i<n; i++,++ity)
        {
            x[i]=itx;
            y[i]=ity;
        }
    }


    void increment(int i)
    {

        itx=x[i];
        ity=y[i];
        list<list<int> >::iterator it=itx;
        if(++it ==L.end())
        {
            list<int> m;

            m.push_back(i);
            L.push_back(m);
            x[i]= ++itx;
            y[i]=itx->begin();

        }
        else
        {
            if(v[*(it->begin())]==v[i]+1)
            {
                (++itx)->push_back(i);
                x[i]= itx;
                list<int>::iterator t=(itx)->end();
                y[i]= --t;

            }
            else
            {
                list<int> m;
                m.push_back(i);
                L.insert(++itx,m);
                x[i]= --itx;
                y[i]=itx->begin();


            }

        }

        (--itx)->erase(ity);
        if(itx->empty())
        {
            L.erase(itx);
        }
        v[i]++;
        return;
    }



    void decrement(int i)
    {
        itx=x[i];
        ity=y[i];
        list<list<int> >::iterator it=itx;
        if(--it ==L.end())
        {
            list<int> m;

            m.push_back(i);
            L.push_front(m);
            x[i]= --itx;
            y[i]=itx->begin();

        }
        else
        {
            if(v[*(it->begin())]==v[i]-1)
            {
                (--itx)->push_back(i);
                x[i]= itx;
                list<int>::iterator t=(itx)->end();
                y[i]= --t;

            }
            else
            {
                list<int> m;
                m.push_back(i);
                L.insert(--itx,m);
                x[i]= ++itx;
                y[i]=itx->begin();

            }

        }

        (++itx)->erase(ity);
        if(itx->empty())
        {
            L.erase(itx);
        }

        v[i]--;
        return;
    }
    void reset(int i)
    {

        v[i]=0;
        return;
    }
    int count(int i)
    {
        return v[i];
    }
    int findMax()
    {
        itx=L.end();
        --itx;
        return *(itx->begin());

    }
    int numMax()
    {

        itx=L.end();
        --itx;

        return itx->size();

    }

    void printMax()
    {
        itx=L.end();
        --itx;
        for(ity=itx->begin(); ity!=itx->end(); ++ity)
        {
            cout<<*ity<<"  ";
        }
        return;
    }



};


