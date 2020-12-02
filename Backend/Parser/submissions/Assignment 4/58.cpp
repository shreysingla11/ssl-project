#include <iostream>
#include <vector>
#include <list>
using namespace std;

typedef list<list<int> >::iterator itli;
typedef list<int> ::iterator iti;

class counter{
private:
	vector<int> cnt;
	list<list<int> > val;
	vector<itli> index1;
	vector<iti> index2;
	itli itze;
public:
	counter(int n)
	{
		cnt.resize(n,0);
		index2.resize(n);
		list<int> a;
		int i=0;
		for(i=0;i<n;i++)
		{
            a.push_back(i);
		}
		val.push_back(a);
		itli it1 = itze = val.begin();
		index1.resize(n,val.begin());
		i = 0;
		for(iti it = (*it1).begin();it!=(*it1).end();it++ )
		{
            index2[i++] = it;
		}
	}

    void increment(int i)
    {
        cnt[i]++;
        itli it = index1[i];
        (*it).erase(index2[i]);
        if((*it).empty() && it!= itze)
            it = val.erase(it);
        else
            it++;

        if(it == val.end()){
            val.insert(it,list<int>(1,i));
            it--;
        }
        else if((*it).empty() || cnt[(*it).front()] == cnt[i]){
            (*it).push_back(i);
        }
        else {
            val.insert(it, list<int>(1,i));
            it--;
        }
        index1[i] = it;
        index2[i] = --((*it).end());
        return;
    }
    void decrement(int i)
    {
        cnt[i]--;
        itli it = index1[i];
        (*it).erase(index2[i]);
        if((*it).empty() && it != itze){
            it = val.erase(it);
        }
        itli temp =it;
        temp--;
        if(it == val.begin()){
            val.insert(it,list<int>(1,i));
            it = val.begin();
        }

        else if( (*temp).empty() || cnt[(*temp).front()] == cnt[i]){
            (*temp).push_back(i);
            it = temp;
        }
        else{
            val.insert(it,list<int>(1,i));
            it--;
        }
        index1[i] = it;
        index2[i] = --((*it).end());
        return;
    }
	void reset(int i)
	{
	    if(cnt[i]!=0){
            cnt[i]=0;
            itli it = index1[i];
            (*it).erase(index2[i]);
            if((*it).empty() && it != itze){
                val.erase(it);
            }
            index1[i] = itze;
            (*itze).push_back(i);
            index2[i] = ((*itze).end());
            index2[i]--;
	    }
        return;
	}
	int count(int i)
	{
        return cnt[i];
	}
	int findMax()
	{
	    itli it = --(val.end());
	    if((*it).empty())
            --it;
        int x = (*it).front();
        return cnt[x];
	}
	int numMax()
	{
	    itli it = --(val.end());
        if(!(*it).empty()){
        }
        else
          it--;
        return (*it).size();
	}

	void printMax()
	{
        itli it1 = --(val.end());
        if(it1 == itze && (*itze).empty()) it1--;
        for(iti it = (*it1).begin();it!= (*it1).end();it++)
        {
            cout<<*it<<'\n';
        }
        return;
	}
};
