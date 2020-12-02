#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

class distinct
{
    vector<int> larray;
public:
    distinct(vector<int> &input)
    {
        //int size=input.size();
        int j=0;
        int n=input.size();
        for(size_t i=0; i<n; i++)
        {
            for(j=i-1; j>=0; j--)
            {
                if(input[j]==input[i])
                {
                    break;
                }
            }
            larray.push_back(j);
            //if(j==-1){larray.push_back(-1);}
            //else{larray.push_back(j);}
        }
        /*
        //creating the tree of vectors
        vector<vector<int> > seqf( log2(n));
        vector<vector<int> > seqs( log2(n));
        seqf[0].resize(n);
        seqs[0].resize(n);
        double k=0;
        int count1=0;
        long long int power;
        for(size_t i=1; i<log2(n); i++)
        {
            power=pow(2,i-1);
            //creating 1st array
            seqf[i].resize(n);
            for(int j=0; j<n; j++)
            {
                k=(larray[j]*power*1.0)/n;
                count1=0;
                if(k>=0 && k<power)
                {
                    for(int a=0; a<j; a++)
                    {
                        if(larray[a]>=(larray[j] + n/power*2) && larray[a]<(larray[j] + n/power))
                        {
                            count1++;
                        }
                    }
                    seqf[i][j]=count1;
                }
            }
            //creating second array
            seqs[i].resize(n);
            for(int j=0; j<n; j++)
            {
                if(larray[j]>=((k*n*1.0)/power + n/power*2) && larray[j]<(larray[j] + n/power))
                {}}
        }*/



    };
    int num_distinct(int i,int j)
    {
        int k=0;
        for(int m=i; m<=j; m++)
        {
            if(larray[m]>=i)
            {
                k++;
            }
        }
        return j-i+1-k;
    };
};

