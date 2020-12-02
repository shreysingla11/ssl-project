# include <iostream>
# include <vector>
# include <algorithm>
#include  <map>
using namespace std;
vector<int> ind;//to store indices

class distinct
{
    vector<int> l;
    int size;
    vector<std::vector<int> > first_arr;
    vector<std::vector<int> > second_arr;

public:
    distinct(vector<int> v)
    {

        size=v.size();
        //i=vector<int>(v.begin(),v.end());
        l=vector<int>(v.size(),-1);       //i=vector<int>(v.begin(),v.end());
        map<int,int> input;

        for(int i=0; i<v.size(); i++)
        {
            //input.insert(v[i],i);
            if(input.find(v[i])!=input.end())
            {
                l[i]=input[v[i]];
                input[v[i]]=i;
            }
            else
            {
                input.insert(std::pair<int,int>(v[i],i));
                l[i]=-1;

            }

        }

    }

    int num_distinct(int a,int b)
    {
        int result=0;
        for(int i=a; i<=b; i++)
        {
            if(l[i]>=a)
            {
                result++;
            }

        }
        return b-a+1-result;
    }


};


