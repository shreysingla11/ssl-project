#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

struct vendice {
    int ind;
    int val;
};

struct segmentTree {
    vector<vector<int> > a1;
    vector<vector<int> > a2;
};

bool compareByVal(const vendice &x, const vendice &y) {
    return x.val < y.val;
}

class distinct {
public:
    vector<vendice> vec;
    vector<int> l;
    segmentTree disTree;

    distinct(vector<int> input){

        vendice tv;
        int n = input.size();

        for(int i=0; i<n; i++){
            tv.ind = i;
            tv.val = input[i];
            vec.push_back(tv);
        }

        sort(vec.begin(), vec.end(), compareByVal);

        l.resize(n);

        for(int i=0; i<n; i++) {
            if (i==0) l[vec[i].ind] = -1;
            else {
                if(vec[i].val == vec[i-1].val)
                    l[vec[i].ind] = vec[i-1].ind;
                else
                    l[vec[i].ind] = -1;
            }
        }
    }

    int num_distinct(int i, int j){
        int nd = 0;
        for(int m = i+1; m <= j; m++){
            if(l[m]>=i) nd++;
        }
        cout<<(j-i+1-nd);
    }
};
