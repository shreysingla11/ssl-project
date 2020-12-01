class counter
{
private :

    int n;//stores no. of objects
    vector <int> vcount;//stores count of ith object in vcount[i]
    list <list <int> > L;//list of lists
    vector <list <list<int> >::iterator> viterator;//vector to store iterators into the list of lists

public :
    counter(int m)
    {
        n=m;
        if(n>=0)
        {
            vector <int> w(n,0);
            vcount=w;

            list <int> l;//list which stores the object ids for count=0
            l.clear();

            for(int i=0; i<n; i++)
            {
                l.push_back(i);
            }

            L.clear();
            L.push_front(l);

            for(int j=0; j<n; j++)
            {
                viterator.push_back(L.begin());
            }
        }
        else
        {
            cout<<"Invalid input!!!"<<endl;
        }
    }

    void increment(int i)
    {
        if (0<=i&&i<n)
        {
            if((++viterator[i])!=L.end())
            {
                viterator[i]--;
                //*viterator[i] is not the last list in L
                if(vcount[(++viterator[i])->front()]==vcount[i]+1)
                {
                    viterator[i]--;
                    //next list corresponds to next count
                    (++viterator[i])->push_back(i);
                    viterator[i]--;
                    //erase i from *viterator[i]
                    (viterator[i])->remove(i);
                    viterator[i]++;
                }

                else
                {
                    viterator[i]--;
                    //next list does not correspond to next count
                    //new list has to be created
                    list <int> l1;
                    l1.push_back(i);
                    L.insert(++viterator[i],l1);
                    viterator[i]--;
                    //erase i from *viterator[i]-1
                    (--viterator[i])->remove(i);
                    viterator[i]++;
                }
            }
            else
            {
                viterator[i]--;
                //last list in L
                //create a new list
                list <int> l2;
                l2.clear();
                l2.push_back(i);
                L.insert(++viterator[i],l2);
                viterator[i]--;
                //erase i from *viterator[i]-1
                (--viterator[i])->remove(i);
                viterator[i]++;
            }
            //delete the list if becomes empty
            if ((--viterator[i])->empty())
            {
                L.erase(viterator[i]);
            }
            viterator[i]++;
            vcount[i]+=1;
        }
        else
        {
            cout<<"This object("<<i<<")doesn't exist!"<<endl;
        }
        return;
    }

    void decrement(int i)
    {
        if (0<=i&&i<n)
        {
            if(vcount[i]>0)
            {
                if((viterator[i])!=L.begin())
                {
                    //*viterator[i] is not the first list in L
                    if(vcount[(--viterator[i])->front()]==vcount[i]-1)
                    {
                        //prev list corresponds to prev count

                        (viterator[i])->push_back(i);
                        //erase i from *viterator[i]+1
                        (++viterator[i])->remove(i);
                        viterator[i]--;
                        //delete the list if no object is left in it
                    }
                    else
                    {
                        viterator[i]++;
                        //prev list does not correspond to prev count
                        //new list has to be created
                        list <int> l1;
                        l1.push_back(i);
                        L.insert(viterator[i],l1);


                        //erase i from *viterator[i]+1
                        (viterator[i])->remove(i);
                        viterator[i]--;
                        //delete the list if no object is left in it
                    }
                }
                else
                {
                    //first list in L
                    //create a new list
                    list <int> l2;
                    l2.push_back(i);
                    L.push_front(l2);
                    //erase i from *viterator[i]+1
                    (viterator[i])->remove(i);
                    viterator[i]--;
                    //delete the list if no object is left in it
                }

                viterator[i]++;
                if((viterator[i])->begin()==(viterator[i])->end())
                {
                    L.erase(viterator[i]);
                }
                viterator[i]--;

                vcount[i]-=1;
            }
            else
            {
                cout<<"Count for this object("<<i<<")is already 0!"<<endl;
            }
        }
        else
        {
            cout<<"This object("<<i<<")doesn't exist!"<<endl;
        }
        return;
    }

    void reset(int i)
    {
        if (0<=i&&i<n)
        {
            if (vcount[i]!=0)
            {
                //erase i from *viterator[i]
                (viterator[i])->remove(i);
                //delete the list if becomes empty
                if((viterator[i])->empty())
                {
                    L.erase(viterator[i]);
                }

                if(vcount[(L.begin())->front()]==0)
                {
                    //list corresponding to count 0 exists
                    viterator[i]=L.begin();
                    L.begin()->push_back(i);
                }
                else
                {
                    //list corresponding to count 0 has to be created
                    list <int> l0;
                    l0.push_back(i);
                    L.push_front(l0);
                    viterator[i]=L.begin();
                }

                vcount[i]=0;
            }
        }
        else
        {
            cout<<"This object("<<i<<")doesn't exist!"<<endl;
        }

        return;
    }

    int count(int i)
    {
        int temp;
        if(0<=i&&i<n)
        {
            temp=vcount[i];
        }
        else
        {
            cout<<"This object("<<i<<")doesn't exist!"<<endl;
            temp = -1;
        }
        return temp;
    }

    int findMax()
    {
        int temp;
        temp=vcount[(L.back()).front()];
        return temp;
    }

    int numMax()
    {
        int temp;
        temp=(L.back()).size();
        return temp;
    }

    void printMax()
    {
        list <int>:: iterator p,q,j;
        p=(L.back()).begin();
        q=(L.back()).end();
        for(j=p; j!=q; j++)
        {
            cout<<*(j);
        }
        return;
    }
};


