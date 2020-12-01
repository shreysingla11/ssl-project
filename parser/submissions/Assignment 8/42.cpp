#include<iostream>
#include<stdio.h>
#include<vector>
#include<set>
#include<utility>
#include<map>
#include<algorithm>
using namespace std;
int main()
{
    long int n,w;
    double u,v;
    double t1,t2;
    scanf("%ld",&n);
    scanf("%ld",&w);
    scanf("%lg",&u);
    scanf("%lg",&v);
    scanf("%lg",&t1);
    scanf("%lg",&t2);
    vector<char>direction;
    vector<long int>m;
    vector<pair<long double,long double> >position[n];
    char direction_temp;
    long int m_temp;
    double start_pos,end_pos,length;
    for(int i=0; i<n; i++)
    {
        scanf("%c",&direction_temp);
        scanf("%ld",&m_temp);
        direction.push_back(direction_temp);
        m.push_back(m_temp);
        for(int j=0; j<m_temp; j++)
        {
            scanf("%lg",&start_pos);
            scanf("%lg",&length);
            if(direction_temp=='E' || direction_temp=='e')
            {
                end_pos=start_pos-length;
            }
            else
            {
                end_pos=start_pos+length;
            }
            position[i].push_back(make_pair(start_pos,end_pos));
        }
        int start_temp,end_temp;
        if(direction_temp=='E' || direction_temp=='e')
        {
            end_temp=position[i][0].second;
            position[i][0].second=-1000000;
            start_temp=position[i][0].first;
            position[i][0].first=end_temp;
            for(int j=1; j<m_temp; j++)
            {
                end_temp=position[i][j].second;
                position[i][j].second=start_temp;
                start_temp=position[i][j].first;
                position[i][j].first=end_temp;
            }
            position[i].push_back(make_pair(1000000,start_temp));
            m[i]=m[i]+1;
        }
        else
        {
            start_temp=position[i][0].first;
            position[i][0].first=1000000;
            end_temp=position[i][0].second;
            position[i][0].second=start_temp;
            for(int j=1; j<m_temp; j++)
            {
                start_temp=position[i][j].first;
                position[i][j].first=end_temp;
                end_temp=position[i][j].second;
                position[i][j].second=start_temp;
            }
            position[i].push_back(make_pair(end_temp,1000000));
            m[i]=m[i]+1;
        }
    }
    vector<pair<long double,long double> >east,west,east_temp,west_temp;
    long int east_count,west_count,count,m_east,m_west;
    east_count=west_count=count=m_east=m_west=0;
    for(int i=0; i<n; i++)
    {
        if(direction[i]=='E' || direction[i]=='e')
        {
            for(int j=0; j<m[i]; j++)
            {
                east_temp.push_back(position[i][j]);
            }
            m_east+=m[i];
        }
        else
        {
            for(int j=0; j<m[i]; j++)
            {
                west_temp.push_back(position[i][j]);
            }
            m_west+=m[i];
        }
    }
    sort(east_temp.begin(),east_temp.end());
    sort(west_temp.begin(),west_temp.end());
    for(int i,j=0; i<m_west; i++)
    {
        if(west_temp[i].first<west_temp[j].second)
        {
            count+=1;
            if(west_temp[i].second>west_temp[j].second)
            {
                j=i;
            }
            if(count==n)
            {
                west.push_back(make_pair(west_temp[i].first,west_temp[j].second));
                west_count++;
                j=i;
                count=1;
            }
        }
        else
        {
            j=i;
            count=1;
        }
    }
    for(int i,j=m_east-1; i>=0; i--)
    {
        if(east_temp[i].first>east_temp[j].second)
        {
            count+=1;
            if(east_temp[i].second>east_temp[j].second)
            {
                j=i;
            }
            if(count==n)
            {
                east.push_back(make_pair(east_temp[i].first,east_temp[j].second));
                east_count++;
                j=i;
                count=1;
            }
        }
        else
        {
            j=i;
            count=1;
        }
    }
    //check for the matching intervals in both directions
    double d_covered,d_tb_covered;
    d_covered=t1*u;
    d_tb_covered=(t2-t1)*u;
    double time_required=(n*w)/v;
    int i_stop,j_stop;
    for(int i=0; i<east_count; i++)
    {
        east[i].first+=d_covered;
        east[i].second+=d_covered;
        if(east[i].second>=0)
        {
            i_stop=i;
            break;
        }
    }
    for(int j=west_count-1; j>=0; j--)
    {
        west[j].first-=d_covered;
        west[j].second-=d_covered;
        if(west[j].second<=0)
        {
            j_stop=j;
            break;
        }
    }
    long int i=0,j=west_count-1,a,b,width_a,width_b;
    double t,t_temp;
    t=0,t_temp=0;
    while(i<i_stop)
    {
        j=west_count-1;
        while(j>j_stop)
        {
            a=east[i].first;
            b=west[j].first;
            width_a=(-1*east[i].second);
            width_b=west[j].second;
            if((-1*a)<=(b+width_b) && (b<=a+width_a))
            {
                if((-1*a)<b)
                {
                    if((a+width_a)<(b+width_b))
                    {
                        t_temp=(width_a-a)/u;
                        if(t_temp+t1>t2 && t2>(b/u)+t1)
                        {
                            t_temp=t2-(b/u);
                        }
                        else if(t2>(b/u)+t1)
                        {
                            t_temp=t_temp-b/u;
                        }
                        if(t_temp>t)
                        {
                            t=t_temp;
                        }
                    }
                    else
                    {
                        t_temp=(width_b+b)/u;
                        if(t_temp+t1>t2 && t2>(b/u)+t1)
                        {
                            t_temp=t2-b/u;
                        }
                        else if(t2>(b/u)+t1)
                        {
                            t_temp=t_temp-b/u;
                        }
                        if(t_temp>t)
                        {
                            t=t_temp;
                        }
                    }
                }
                else
                {
                    if((a+width_a)<(b+width_b))
                    {
                        t_temp=(width_a-a)/u;
                        if(t_temp+t1>t2 && t2>((-1*a)/u)+t1)
                        {
                            t_temp=t2+a/u;
                        }
                        else
                        {
                            t_temp=t_temp+a/u;
                        }
                        if(t_temp>t)
                        {
                            t=t_temp;
                        }
                    }
                    else
                    {
                        t_temp=(width_b+b)/u;
                        if(t_temp+t1>t2 && t2>(-1*a)+t1)
                        {
                            t_temp=t2+a/u;
                        }
                        else
                        {
                            t_temp=t_temp+a/u;
                        }
                        if(t_temp>t)
                        {
                            t=t_temp;
                        }
                    }
                }
            }
            j--;
        }
        i++;
    }
    cout<<"The ferry can travel in the time between: "<<t-time_required<<"\n";
    return 1;
}
