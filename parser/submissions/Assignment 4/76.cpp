#include<iostream>
#include<vector>
#include<list>

using namespace std;
class counter
{
    int n;
    vector<int> web_count;
    list<list<int > > L;
    vector<list<int>::iterator> V;
    vector<list<list<int> >::iterator> W;
    list<list<int> >::iterator it1;
    list<int>::iterator it2;
    list<list<int> >::iterator iter;

public:
    counter(int num)
    {
        n=num;
        web_count.resize(n);
        web_count.assign(n,0);
        list<int> M;
        for(int p=0; p<n; p++)
        {
            M.push_back(p);
        }
        L.push_back(M);
        V.resize(n);
        W.resize(n);
        it1=L.begin();
        it2=it1->begin();
        for(int q=0; q<n; q++,++it2)
        {
            W[q]=it1;
            V[q]=it2;
        }
        iter=L.begin();
    }
    void increment(int i)
    {
        it1=W[i];
        it2=V[i];
        list<list<int> >::iterator temp=it1;
        list<int> M;
        if((++temp)==L.end())
        {
            M.push_back(i);
            L.push_back(M);
            W[i]=++it1;
            V[i]=(it1)->begin();
        }
        else
        {
            if(web_count[*(temp->begin())]==web_count[i]+1)
            {
                (++it1)->push_back(i);
                W[i]=it1;
                list<int>::iterator temp2=it1->end();
                V[i]=(--temp2);
            }
            else
            {
                M.push_back(i);
                it1=L.insert(++it1,M);
                W[i]=it1;
                V[i]=it1->begin();
            }
        }
        (--it1)->erase(it2);
        if(it1->empty())
        {
            L.erase(it1);
        }
        web_count[i]++;
        return ;
    }
    void decrement(int i)
    {
        it1=W[i];
        it2=V[i];
        list<list<int> >::iterator temp=it1;
        list<int> M;
        if(it1==L.begin())
        {
            M.push_back(i);
            L.push_front(M);
            W[i]=L.begin();
            V[i]=W[i]->begin();
        }
        else
        {
            if(web_count[*((--temp)->begin())]==web_count[i]-1)
            {
                temp->push_back(i);
                W[i]=temp;
                list<int>::iterator temp2=temp->end();
                V[i]=(--temp2);
            }
            else
            {
                M.push_back(i);
                it1=L.insert(it1,M);
                W[i]=it1;
                V[i]=it1->begin();
                int a=*(V[i]);
            }
        }
        it1->erase(it2);
        if(it1->empty())
        {
            L.erase(it1);
        }
        web_count[i]--;
        return ;
    }
    void reset(int i)
    {
        it1=W[i];
        it2=V[i];
        iter->push_back(i);
        W[i]=iter;
        list<int>::iterator temp=iter->end();
        V[i]=(--temp);
        it1->erase(it2);
        if(it1->empty())
        {
            L.erase(it1);
        }
        web_count[i]=0;
        return ;
    }
    int count(int i)
    {
        return web_count[i];
    }
    int findMax()
    {
        int maxcount=web_count[*((L.back()).begin())];
        return maxcount;
    }
    int numMax()
    {
        int num_pages=(L.back()).size();
        return num_pages;
    }
    void printMax()
    {
        for(list<int>::iterator it=(L.back()).begin(); it!=(L.back()).end(); ++it)
        {
            cout<<*it<<" ";
        }
        cout<<endl;
        return ;
    }
} ;
