#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class distinct
{
    private:
        vector<int> seq;
        vector<int> Lseq;
        vector<vector<int> > dLmat;

    public:
        distinct(vector<int> Sparam)
        {
            int n,p,i,j;
            i = 1;
            vector<int> temp;
            pair<int,int> w;
            vector<pair<int,int> > SSeq;

            n = Sparam.size();
            Lseq.assign(n,-1);

            //////// construct l array

            for(p = 0; p < n ; p++)
            {
                w.first = Sparam[p];
                w.second = p;
                SSeq.push_back(w);
            }
            sort(SSeq.begin(),SSeq.end(),comparePairs);

            for(p = 0; p < n ; p++)
            {
                if( SSeq[p].first == SSeq[p+1].first )
                {
                    Lseq[SSeq[p].second] = SSeq[p+1].second;
                }

            }

            temp.assign(n,0);

            for(i = 0 ; i < n ; i++)
            {
                for (j = i+1 ; j < n ; j++)
                {
                    if(Lseq[j] >= i)
                    {

                        temp[j] = temp[j-1] + 1;
                    }
                    else
                    {
                       temp[j] = temp[j-1];
                    }

                }
                dLmat.push_back(temp);
            }

        }

        int num_distinct(int i, int j)
        {

            return j - i + 1 - dLmat[i][j];
        }

        private:

        static bool comparePairs(const std::pair<int,int>& lhs, const std::pair<int,int>& rhs)
        {
          if( lhs.first < rhs.first ){return true;}
          if( lhs.first > rhs.first ){return false;}
          return lhs.second > rhs.second;
        }
};
