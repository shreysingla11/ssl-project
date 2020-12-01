#include <iostream>
#include <list>
#include <vector>
using namespace std;

class counter
{
    private:
        int no;
        vector<int> webpg;
        list < list<int> > L;
        vector<list<int>::iterator > it2;
        vector<list< list<int> >::iterator > it;
    public:
        counter(int n)
        {
            no=n;
            webpg.resize(n,0);
            it2.resize(n);
            it.resize(n);
            list<int> Lt;
            for (int i=0;i<n;i++)
            {
                Lt.push_back(i);
                it2.at(i)=(--(Lt.end()));
            }
            L.push_back(Lt);
            for (int i=0;i<n;i++)
            {
                it.at(i)=(L.begin());
            }

        }
        void increment(int i)
        {



            /*webpg[i]++;
            list< list<int> >::iterator Lt;
            list<int>::iterator Lt2;
            Lt=L.end();
            Lt--;
            Lt2=(*Lt).end();
            if (it[i]==Lt)
            {
                cout << "asd";
                list<int> t(1,i);
                Lt=L.end();
                L.insert(Lt,t);

                Lt--;
                Lt2=(*Lt).begin();
            }
            else
            {
                if (webpg[i]==webpg[((*Lt).front())])
                {
                    Lt=it[i];
                    Lt++;
                    (*Lt).push_back(i);
                }
                else
                {
                    Lt=it[i];
                    Lt++;
                    list<int> t(1,i);
                    L.insert(Lt,t);
                }
            }
            if ((*it[i]).front()==(*it[i]).back())
            {

                Lt=L.erase(it[i]);
                Lt=L.end();
                Lt--;
                it[i]=Lt;
            }
            else
            {

                (*it[i]).erase(it2[i]);
            }

            it2[i]=Lt2;
        }*/

        webpg[i]++;
        list< list<int> >::iterator Lt;
        list<int>::iterator Lt2;
        Lt=L.end();
        Lt--;
        cout << (*it[i]).front() << (*it[i]).back();
        if ((*it[i]).front()==(*it[i]).back())
        {
            Lt=L.erase(it[i]);
            it[i]=Lt;
            if (it[i]==L.end())
            {
                list<int> t;
                t.push_back(i);
                it2[i]=t.begin();
                L.push_back(t);
                it[i]--;
            }
            else
            {
                if (webpg[i]==webpg[((*Lt).front())])
                {
                    (*it[i]).push_back(i);
                    it2[i]=((*it[i]).end());
                    it2[i]--;
                }
                else
                {
                    list<int> t;
                    t.push_back(i);
                    it2[i]=t.begin();
                    L.insert(it[i],t);
                    it[i]--;
                }
            }
        }
        else
        {

            (*it[i]).erase(it2[i]);
            it2[i]=Lt2;
            Lt=L.end();
            Lt--;
            if (it[i]==Lt)
            {
                list<int> t;
                t.push_back(i);
                it2[i]=t.begin();
                L.insert(L.end(),t);
                it[i]++;
            }
            else
            {
                if (webpg[i]==webpg[((*Lt).front())])
                {
                    (*it[i]).push_back(i);
                    it2[i]=((*it[i]).end());
                    it2[i]--;
                }
                else
                {
                    list<int> t;
                    t.push_back(i);
                    it2[i]=t.begin();
                    L.insert(it[i],t);
                    it[i]--;
                }
            }
        }
}
        void decrement(int i)
        {
            webpg[i]--;
            list< list<int> >::iterator Lt;
            Lt=it[i];

            if ((*it[i]).size()==1)
            {
                L.erase(it[i]);
            }
            else
            {
                (*it[i]).pop_back();
            }

            Lt--;

            if ((webpg[i]==webpg[((*Lt).front())])&&((*Lt).empty()==false))
            {
                it[i]--;
                (*it[i]).push_back(i);
            }
            else
            {
                it[i]--;
                (*it[i]).push_back(i);
            }
            it2[i]=(*it[i]).end();
            it2[i]--;
        }

        void reset(int i)
        {
            webpg[i]=0;
            if ((*it[i]).size()==1)
            {
                L.erase(it[i]);
            }
            else
            {
                (*it[i]).pop_back();
            }

            if(webpg[((*L.begin()).front())]==0)
            {
                it[i]=L.begin();
                (*it[i]).push_back(i);
            }
            else
            {
                list<int> Lt;
                Lt.push_back(0);
                L.push_front(Lt);
                it[i]=L.begin();
                it2[i]=(*it[i]).begin();
            }
        }

        int count (int i)
        {
            return webpg[i];
        }

        int findMax()
        {
            list<list<int> >::iterator Lt;
            Lt=L.end();
            Lt--;
            return webpg[(*Lt).front()];
        }

        int numMax()
        {
            list<list<int> >::iterator Lt;
            Lt=L.end();
            Lt--;
            return (*Lt).size();
        }

        void printMax()
        {
            list<list<int> >::iterator Lt2;
            Lt2=L.end();
            Lt2--;
            list<int>::iterator Lt;
            for (Lt=(*Lt2).begin();Lt!=(*Lt2).end();Lt++)
            {
                cout << *Lt;

            }
            return;
        }


};
