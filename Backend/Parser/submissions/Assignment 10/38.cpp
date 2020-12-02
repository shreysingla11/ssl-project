#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
class distinct
{
public:
    vector<vector<int> > a;
    vector<vector<int> > b;
    vector<int> l;
    distinct(vector<int> v )
    {
        int length = v.size();
        for(int i = 0; i<length ; i++)
        {
            int j = i-1;
            for(; j>=0; j--)
            {
                if(v[j] == v[i])
                {
                    break;
                }

            }
            l.push_back(j);

        }


        /* Better solution
        for(int level = 1,twopower = 1; level<=log2(length); level++,twopower*=2)
           {
               vector<int> first;
               vector<int> second;
               vector<int> number(twopower,0);
               vector<int> left(twopower,-1);
               vector<int> right(twopower,-1);
               for(int j = 0; j<length ; j++)
               {
                   int k = l[j]*twopower/length;
                   int low = k*length/twopower+length/(2*twopower);
                   int high = (k+1)*length/twopower;

                   if(l[j]>=low && l[j]<high)
                   {
                       number[k]++;
                       second.push_back(left[k]);
                       right[k] = j;
                   }
                   else
                   {
                       second.push_back(right[k]);
                       left[k] = j;
                   }
                   first.push_back(number[k]);
               }
               a.push_back(first);
               b.push_back(second);
           }*/
    }
    int num_distinct(int i , int j )
    {
        int pook = 0;
        for(int x = i; x<=j; x++)
        {
            if(l[x]>=i)
            {
                pook++;
            }
        }
        return j-i+1-pook;
    }
};

