#include<iostream>
#include<vector>
using namespace std;


class distinct
{
vector<int> lVec;
vector< vector<int> > arr1,arr2;
int siz;

public:

    distinct(){}

    distinct(vector<int>inp)
    {
        siz=inp.size();
        for(int i=0;i<siz;i++)
        {
            int j=i-1;
            while(j>-1)
            {
                if(inp[j]==inp[i]){break;}
                j--;
            }
            lVec.push_back(j);
            //cout<<j<<endl;
        }

        for(int twopow=1,level=1;(siz/twopow)!=0;twopow*=2,level++)
        {
            int k;
            vector<int>first(siz,0),second(siz,0),temp1(twopow,0),temp2(twopow,-1),temp3(twopow,-1);
            for(int j=0;j<siz;j++)
            {
                int myCount=0,m;
                k=(lVec[j]/siz)*twopow;
                int a= k*(siz/twopow)+siz/(twopow*2),b=(k+1)*(siz/twopow),c=(k)*(siz/twopow);

                if(a<=lVec[j]&&lVec[j]<b)
                {
                    temp1[k]++;
                    second[j]=(temp2[k]);
                    temp3[k]=j;
                }
                else
                {
                    second[j]=temp3[k];
                    temp2[k]=j;
                }
                first[j]=temp1[k];
            }
            arr1.push_back(first);
            arr2.push_back(second);
        }
    }
    int num_distinct(int i,int j)
    {
        if(lVec[j]==-1)
        {
            int p;
            for(p=siz-1;p>0;p--)
            {
                if(p>0){break;}
            }
            j=p;
        }
        int myCount=0;
        for(int k=i;k<=j;k++)
        {
            if(lVec[k]>=i){myCount++;}
        }
        return j-i+1-myCount;

    }



};

