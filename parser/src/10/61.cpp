#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class distinct{
private:
        int n;
        vector<int> l;
        vector<vector<int> > K;
        vector < pair<int, int> >A;

    public:
        distinct(vector<int> V){
            n=V.size();
            pair<int,int> tem;
            for(int i=0; i <n ; i++){
                tem.first=V[i];
                tem.second=i;
                A.push_back(tem);
            }
            sort(A.begin(),A.end());
            l.assign(n,-1);
            l[A[0].second]=-1;
            for(int i =1; i<n ; i++){
                if(A[i].first==A[i-1].first){
                    l[A[i].second]=A[i-1].second;
                }
                else{
                    l[A[i].second]=-1;
                }
            }
            vector<int> temp(n,0);
            K.assign(n,temp);
            for(int i=0; i <n ; i++){
                for(int j=i+1; j<n; j++){
                    K[i][j]= (l[j]>=i)? K[i][j-1]+1 : K[i][j-1] ;
                }

            }
        }
        int num_distinct(int i,int j){
            return j-i+1-K[i][j];
        }
};
