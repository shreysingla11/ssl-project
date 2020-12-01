#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class distinct
{
public:
    vector<int> l;
    /*vector<vector<int> > segfirst;
    vector<vector<int> > segsecond;*/

    distinct(vector<int> a)
    {
        /*vector<int> l(a.size(),-1);
        for(int i=1;i<a.size();i++)
        {
            for(int j=i-1;j>0;j--)
            {
                if(a[j]==a[i])
                {
                    l[i]=j;
                    break;
                }
            }
        }*/
        bool var=0;
        int levels;
        int n = a.size();
        double logparam = a.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(a[j]==a[i])
                {
                    l.push_back(j);
                    var = 1;
                    break;
                }
            }
            if(var==0)
            {
                l.push_back(-1);
            }
            var = 0;
        }

        /*levels = ceil(log(logparam)/log(2));

        for(int i=1;i<levels+1;i++)
        {
            int temp = pow(2,i-1);
            vector<int> temporary(temp);
            vector<int> left(temp);
            vector<int> right(temp);
            vector<int> first(n);
            vector<int> second(n);
            for(int j=0;j<n;j++)
            {
                int k = floor(l[j]*temp/(n));
                //first.push_back(temporary[k]);
                first[j] = temporary[k];
                //cout<<first[j];

                if(l[j] >= (k*(n)/(temp)) + ((n)/(2*temp)))
                {
                    temporary[k]++;
                    second[j] = left[k];
                    right[k] = j;
                }
                else
                {
                    second[j] = right[k];
                    left[k] = j;
                }
                //cout<<" "<<second[j]<<" ";
            }
            //cout<<endl;
            segfirst.push_back(first);
            segsecond.push_back(second);
        }*/

    };

    int num_distinct(int i,int j)
    {
        int count=0;
        for(int k=i;k<=j;k++)
        {
            if(l[k]>=i)
            {
                count++;
            }
        }
        count = j - i + 1 - count;
        return count;
    };

};

/*int main()
{
    vector<int> a;
    for(int i=0;i<100000;i++)
    {
        a.push_back(i);
    }
    a.push_back(1);
    a.push_back(2);
    a.push_back(1);
    a.push_back(3);
    a.push_back(2);
    a.push_back(1);
    a.push_back(1);
    a.push_back(3);
    distinct test(a);
    cout<<test.num_distinct(5,7)<<endl;
    return 0;
}*/
