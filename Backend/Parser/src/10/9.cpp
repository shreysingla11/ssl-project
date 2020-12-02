#include <iostream>
#include <vector>
#include <map>
#include <math.h>
using namespace std;

void print (vector < int > a)
{
    for(int i=0; i<a.size(); i++)
    {
        cout<<a[i]<<" ";
    }

}

class distinct
{
public:
    int n;
    vector <int> a;
    vector <int> l;
    vector < vector <int> > first;
    vector < vector <int> > second;


    void createfirst()
    {
        vector <int> temp1(n);
        vector <int> temp2(n);

        for(int power=2; power<=n; power=power*2)
        {
            vector <int> index(power,-1);
            vector <int> counts(power,0);
            int k;



            for(int j=0; j<n; j++)
            {

                if(l[j]>=0)
                {
                    k=l[j]/(n/power);
                    counts[k]++;

                    if(k%2==1)
                    {
                        temp1[j]=counts[k];
                        temp2[j]=index[k-1];
                    }

                    else
                    {
                        temp1[j]=counts[k+1];
                        temp2[j]=index[k+1];
                    }

                    index[k]=j;
                }

                else
                {
                    temp1[j]=0;
                    temp2[j]=-1;
                }

            }
            first.push_back(temp1);
            second.push_back(temp2);

        }

        // pair< vector<int> ,vector<int> > temp(temp1,temp2);
        return ;
    }




    distinct(vector <int> temp)
    {
        n=temp.size();
        a.resize(temp.size());
        l.resize(temp.size());
        //pair< vector<int> ,vector<int> > aaa;
        a=temp;
        map <int, int> counter;
        for(int i=0; i<temp.size(); i++)
        {
            if(counter.count(a[i])>0)
            {
                l[i]=counter[a[i]];
                counter[a[i]]=i;
            }

            else
            {
                l[i]=-1;
                counter[a[i]]=i;
            }
        }
        //print(l);
        createfirst();

    }


    int finals(int i,int j)
    {
        int I=i,J=j;
        int counts=0;
        int level=0;
        int exp=4;
        int mid=n/2;

        if(i==j)return 1;

        if(i>j)return J-I+1-0;

        while(true)
        {
            if(i==mid)
            {
                if(first[level][j]>0)
                {
                    counts+=first[level][j];
                }
                break;
            }

            if(i>mid)
            {
                if(l[j]<mid)
                {
                    j=second[level][j];
                }

                mid+=n/exp;
                level++;
            }

            else
            {
                if(first[level][j]>0)
                {
                    counts+=first[level][j];
                }

                if(l[j]>=mid)
                {
                    j=second[level][j];
                }
                if(j<0)break;
                mid-=n/exp;
                level++;

            }


            exp*=2;
            if(expo>n)break;
        }
        return J-I+1-counts;
    }

};

