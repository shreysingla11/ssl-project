#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    long n, w, u, v, t1, t2;

    cin>>n>>w>>u>>v>>t1>>t2;

    vector <char> direction(n);
    vector<long> m(n);


    vector<vector <long> > l(n);
    vector<vector <long> > p(n);
    vector<vector <double> > tStart(n);
    vector<vector <double> > tEnd(n);

    double tStartTemp, tEndTemp;

    char directionTemp;
    long mTemp, lTemp, pTemp, totalShips;
    totalShips=0;
    vector<double> tStart1;
    vector<double> tEnd1;

    //cout<<"loop started";
    for(long i =0; i<n; i++)
    {
        cin>>directionTemp;
        direction[i]=directionTemp;

        cin>>mTemp;
        m[i]=mTemp;
        //cout<<"mtemp inputed\n";
        vector<double> tStartEmpty(mTemp, 0);
        vector<double> tEndEmpty(mTemp, 0);
        vector<long> lEmpty(mTemp, 0);
        vector<long> pEmpty(mTemp, 0);
        tStart[i]=tStartEmpty;
        tEnd[i]=tEndEmpty;
        l[i]=lEmpty;
        p[i]=pEmpty;


        for(long j=0; j<mTemp; j++)
        {
            vector<long> lEmpty(mTemp);
            vector<long> pEmpty(mTemp);

            cin>>lTemp>>pTemp;
            l[i][j]=lTemp;
            p[i][j]=pTemp;


            if(directionTemp=='E')
            {
                tStartTemp=(-pTemp)/(double)u;
                tEndTemp=(-pTemp + lTemp)/(double)u;
            }
            else
            {
                tStartTemp=(pTemp)/(double)u;
                tEndTemp=(pTemp + lTemp)/(double)u;
            }

            tStart[i][j]=tStartTemp;
            tEnd[i][j]=tEndTemp;
            tStart1.push_back(tStartTemp);
            tEnd1.push_back(tEndTemp);
            totalShips=totalShips + 1;

        }

    }//end of outer for loop

    //cout<<"Input successful";

    vector<double> tFreeStart;
    vector<double> tFreeEnd;
    vector<long> c1(totalShips,0);
    vector<long> c2(totalShips,0);

    for(long i =0; i<n; i++)
    {
        for(long j=0; j<m[i]; j++)
        {
            for(long k=0; k<totalShips; k++)
            {
                if((tStart[i][j]<tStart1[k])&&(tEnd[i][j]>tStart1[k]))//Startpoint overlaps with a interval
                {
                    c1[k]=1;
                }
            }

            for(long k=0; k<totalShips; k++)
            {
                if((tStart[i][j]<tEnd1[k])&&(tEnd[i][j]>tEnd1[k]))//Endpoint overlaps with a interval
                {
                    c2[k]=1;
                }
            }
        }
    }//end of outer for loop

    for(long k=0; k<totalShips; k++)
    {
        if(c1[k]==0)
        {
            tFreeEnd.push_back(tStart1[k]);
        }
        if(c2[k]==0)
        {
            tFreeStart.push_back(tEnd1[k]);
        }
    }

    //vectors tFreeEnd and tFreeStart store end points and start points of some free intervals

    sort (tFreeEnd.begin(), tFreeEnd.end());//sort the end points in ascending order

    vector<double> tFree;// to store the free intervals
    double tFreeTemp;

    long tFreeStartSize = tFreeStart.size();
    long tFreeEndSize = tFreeEnd.size();

    for (long i=0; i<tFreeStartSize; i++)
    {
        long j=0;
        for(j=0; j<tFreeEndSize; j++)
        {
            if(tFreeEnd[j]>tFreeStart[i])
            {
                if(((tFreeStart[i]>=t1)&&(tFreeStart[i]<=t2))&&((tFreeEnd[j]>=t1)&&(tFreeEnd[j]<=t2)))
                {
                    tFreeTemp=tFreeEnd[j] - tFreeStart[i] ;
                    tFree.push_back(tFreeTemp);
                }
            }
        }
    }

    sort (tFree.begin(), tFree.end());
    double tMax;
    tMax=tFree.back();

    double d;

    d = tMax - ((n*w)/(double)v);
    cout<<v;

    return 0;
}
