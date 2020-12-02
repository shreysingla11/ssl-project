#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

struct pairs{
    int val;
    int pos;
};

bool compare(pairs a, pairs b){
    if (a.val > b.val) return true;
    else if (b.val> a.val) return false;
    else{
        if (a.pos > b.pos) return false;
        else return true;
    }
}

class distinct{

    vector<int>p;
    vector<int>l;

    public:
        distinct(vector<int> m){
            p = m;
            pairs temp;
            temp.pos = 0;
            temp.val = 0;
            vector<pairs>tmp;
            tmp.resize(m.size(), temp);
            l.resize(p.size(), -1);
            for (int i=0; i<p.size(); i++){
                tmp[i].val = p[i];
                tmp[i].pos = i;
            }
            sort(tmp.begin(), tmp.end(), compare);
            for (int i=1; i<p.size(); i++){
                if (tmp[i].val == tmp[i-1].val){
                            l[tmp[i].pos] = tmp[i-1].pos;

                 }
            }

            int num = log2(l.size());
            vector<int>ser[num];
            vector<int>second[num];
            vector<int> tempe;
            int count=0;
            tempe.resize(l.size(), 0);
            /*for (int i=0; i<l.size(); l++){
                if (l[i] >= l.size()/2){
                    count++;
                }
                ser[0].push_back(count);
            }*/

            for (int i=0; i<num; i++){
                vector<int>counter(l.size(), 0);
                int ll=-1;
                int rr =-1;
                for (int j=0; j<l.size(); j++){
                    int k = l[j]*pow(2, i-1)/l.size();
                    if (l[j] >= k*l.size()/pow(2, i-1) + l.size()/pow(2, i) && l[j] < (k+1)*l.size()/pow(2, i-1)){
                        counter[j]++;
                    }
                    ser[i].push_back(counter[j]);

                    /*** Now calculating the second array **/
                    if (l[j] >= k*l.size()/pow(2, i) + l.size()/pow(2, i+1) && l[j] < (k+1)*l.size()/pow(2, i)){
                        second[i].push_back(ll);
                        rr = j;
                    }
                    else {
                        second[i].push_back(rr);
                        ll=j;
                    }
            }
        }

    }
};

