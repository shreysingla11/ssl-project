/*#include <iostream>
#include <vector>
using namespace std;
*/
class distinct
{
private:
public:
    vector <int> seq;//to store the given sequence
    vector <int> l;//l(i) is the largest j such that j<i and a_j=a_i
    /*vector <int> b1;//b1[j]=no. of numbers from l[0] to l[j] which are >=n/2
    vector <int> b2;//merged array
    vector <int> b3;//third array
    vector <vector <int> > level;//2 arrays for each level
    */
    distinct(vector <int> v)
    {
        //initialisation
        seq=v;
        int p=0,q=0,n=0;
        n=v.size();
        /*for (int i=0;i<n;i++)
        {
            b1.push_back(-1);
        }
        b2=b1;
        b3=b1;

        //to form l in O(n^2)
        for(p=0;p<n;p++)
        {
            for(q=p-1;q>=0;q--)
            {
                if(seq[q]==seq[p])
                {
                    l.push_back(q);
                    break;
                }
                else
                {
                    continue;
                }
            }
            if(q==-1)
            {
                l.push_back(-1);
            }
        }
        //to form b1 in O(n)
        b1[0]=0;
        int count0=0;//#numbers>=n/2
        for (p=1;p<n;p++)
        {
            if(l[p]>=n/2)
            {
                count0++;
            }
            else
            {

            }
            b1[p]=count0;
        }
        //to form b2 in O(n)
        b2[0]=0;
        int count1=0;//no. of numbers in l >=3n/4
        int count2=0;//no. of numbers in l >=n/4 & <=n/2-1
        for (p=1;p<n;p++)
        {
            if(l[p]>=3*n/4)
            {
                count1++;
            }
            if(l[p]>=n/4&&l[p]<=n/2-1)
            {
                count2++;
            }
            if(l[p]>=n/2)
            {
                b2[p]=count1;
            }
            else
            {
                b2[p]=count2;
            }
        }
        //to form b3
        int prev_index=-1, next_index=-1;
        b3[0]=-1;
        for(p=1;p<n;p++)
        {
            for(q=p-1;q<=0;q--)
            {
                if(l[q]<n/2)
                {
                    prev_index=q;
                    break;
                }
            }

            if(q==-1)
            {
                prev_index=-1;
            }

            for(q=p-1;q<=0;q--)
            {
                if(l[q]>=n/2)
                {
                    next_index=q;
                    break;
                }
            }

            if(q==-1)
            {
                next_index=-1;
            }

            if(l[p]>=n/2)
            {
                b3[p]=prev_index;
            }
            else
            {
                b3[p]=next_index;
            }
        }*/
    }

    int num_distinct(int i, int j)
    {
        int n=seq.size();
        vector <int> vec(n+1,0);
        int result=0;
        for(int p=i;p<=j;p++)
        {
            vec[seq[p]]+=1;
        }
        for(int p=0;p<n+1;p++)
        {
            if(vec[p]!=0)
            {
                result++;
            }
        }
        return result;
    }
};
