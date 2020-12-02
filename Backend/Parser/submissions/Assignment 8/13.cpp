#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

class interval
{
public:
    double start,end;
    interval(double a,double b)
    {
        start = a;
        end = b;
        return;
    }
};

bool myBool(interval const &lhs,interval const &rhs)
    {
        if (lhs.start<rhs.start)
        {
            return true;
        }
        else if (rhs.start<lhs.start)
        {
            return false;
        }
        else
        {
            if (lhs.end<rhs.end)
            {
                return true;
            }
            else if (rhs.end<lhs.end)
            {
                 return false;
            }
        }
    }


int main()
{
    int n,w,u,v,t1,t2,i=0,j=0,k=0;
    cin>>n>>w>>u>>v>>t1>>t2;
    double temp1=0.0,temp=0.0;
    char* direction = new char [n];
    int* nships = new int [n];
    vector<interval> forbidden;
    vector<interval> feasible;

    for(k=0;k<n;k++)
    {
        cin>>direction[k]>>nships[k];
        int* position = new int [nships[k]];
        int* length = new int [nships[k]];
        for(j=0;j<nships[k];j++)
        {
            cin>>length[j]>>position[j];
            if(direction[k]=='E')
            {
                position[j]=(-1)*(position[j]);
            }
            temp1 = ((length[j]*(1.0))/u) + (((w)*(1.0))/v);
            temp = ((position[j]*(1.0))/u) - (((k+1)*w)*(1.0))/v;

            if((temp>=t1)&&((temp+temp1)<=t2))
            {forbidden.push_back(interval(temp,temp1+temp));}
            else if ((temp>=t1)&&((temp+temp1)>=t2)&&(temp<=t2))
            {forbidden.push_back(interval(temp,t2));}
            else if ((temp<=t1)&&((temp+temp1)<=t2)&&((temp+temp1)>=t1))
            {forbidden.push_back(interval(t1,temp1+temp));}
            else if ((temp<=t1)&&((temp+temp1)<=t1)){}
            else if ((temp>=t2)&&((temp+temp1)>=t2)){}
            else if ((temp<=t1)&&((temp+temp1)>=t2))
            {forbidden.push_back(interval(t1,t2));}
        }
        delete[] position;
        delete[] length;
    }
    sort(forbidden.begin(), forbidden.end(),myBool);
    double max=0;

    if((forbidden[0].start-t1)>=max)
    {
        max = forbidden[0].start-t1;
    }

    for(i=0;i<(forbidden.size())-1;i++)
    {
        if((forbidden[i+1].start-forbidden[i].end)>max)
        {max = forbidden[i+1].start-forbidden[i].end;}
    }

    if((t2-forbidden[i].end)>max)
    {
        max=t2-forbidden[i].end;
    }
    printf("%.8f ",max);
    cout<<endl;
    delete[] direction;
    delete[] nships;
    return 0;
}
