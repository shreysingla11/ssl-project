#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <algorithm>
#include <sstream>
#include <set>
#include <vector>

using namespace std;

class ship
{
public:
    int lane,position,length;
    char direction;
};

class intv
{
public:
    double first;
    char second;
    int collisions;

    intv()
    {
        collisions = 0;
    }

};

bool compare(intv a,intv b)
{
    return a.first < b.first ;
}

int main()
{
    string s,temp,str;
    int n,w,u,v;
    double t1,t2;
    int i,count;
    intv interval;
    vector<ship> ship_list;
    ship tempship;
    vector<intv> interval_list;
    double start,stop;
    pair<double,double> interva;
    vector< pair<double,double> > interva_list;
    double length=0;
    //input

    getline(cin,s);
    sscanf(s.c_str(),"%d %d %d %d %lf %lf",&n,&w,&u,&v,&t1,&t2);

    for(i=0; i<n; i++)
    {
        getline(cin,s);
        if(s.length()>3)
        {
            str = s.substr(4);
        }
        else
        {
            str = "";
        }
        if(s[0]=='E')
        {
            tempship.direction = 'E';
            tempship.lane = i;
            istringstream iss(str);
            count = 0;
            while (getline(iss, temp, ' '))
            {
                count++;
                if(count == 1)
                {
                    tempship.length = atoi(temp.c_str());
                }
                if(count == 2)
                {
                    tempship.position = atoi(temp.c_str());
                    if(true)
                    {
                        ship_list.push_back(tempship);
                    }
                    count = 0;
                }
            }
        }
        if(s[0]=='W')
        {
            tempship.direction = 'W';
            tempship.lane = i;
            istringstream iss(str);
            count = 0;
            while (getline(iss, temp, ' '))
            {
                count++;
                if(count == 1)
                {
                    tempship.length = atoi(temp.c_str());
                }
                if(count == 2)
                {
                    tempship.position = atoi(temp.c_str());
                    if(true)
                    {
                        ship_list.push_back(tempship);
                    }
                    count = 0;
                }
            }
        }
    }

    //input-end
    vector<ship>::iterator mit;
    for(mit = ship_list.begin(); mit != ship_list.end(); ++mit)
    {
        if(mit->direction=='E')
        {
            if(mit->position>=0)
            {
                start = t1;
                stop = (((mit->length)-(mit->position))*1.0)/u + (((mit->lane)*w*1))/v ;
            }
            else{
            start =(((abs(mit->position))*1.0)/u) - (((mit->lane+1)*w*1.0)/v);
            stop = ((abs(mit->position)+mit->length)*1.0/u) -(((mit->lane)*w*1.0)/v);

            }

            if(start<t1)
            {start=t1;}
            if(stop>t2)
            {
                stop=t2;
            }
            if(t1>stop)
            {
                start = -1;
                stop = -1;
            }
            interval.first = start;
            interval.second = 'S';
            interval_list.push_back(interval);
            interval.first = stop;
            interval.second = 'E';
            interval_list.push_back(interval);
            interva.first = start;
            interva.second = stop;
            interva_list.push_back(interva);
        }


    if(mit->direction=='W')
        {
            if(mit->position<=0)
            {
                start = t1;
                stop = (((mit->length)+(mit->position))*1.0)/u + (((mit->lane)*w*1))/v ;
            }
            else{
            start =(((abs(mit->position))*1.0)/u) - (((mit->lane+1)*w*1.0)/v);
            stop = ((abs(mit->position)+mit->length)*1.0/u) -(((mit->lane)*w*1.0)/v);

            }
            if(start<t1)
            {start=t1;}
            if(stop>t2)
            {
                stop=t2;
            }
            if(t1>stop)
            {
                start = -1;
                stop = -1;
            }
            interval.first = start;
            interval.second = 'S';
            interval_list.push_back(interval);
            interval.first = stop;
            interval.second = 'E';
            interval_list.push_back(interval);
            interva.first = start;
            interva.second = stop;
            interva_list.push_back(interva);
        }
        /*
        start =(((abs(mit->position))*1.0)/u) - (((mit->lane+1)*w*1.0)/v);
        if(start<t1)
        {
            start=t1;
        }
        interval.first = start;
        interval.second = 'S';
        interval_list.push_back(interval);
        stop = ((abs(mit->position)+mit->length)*1.0/u) -(((mit->lane)*w*1.0)/v);
        if(stop>t2)
        {
            stop=t2;
        }
        interval.first = stop;
        interval.second = 'E';
        interval_list.push_back(interval);
        interva.first = start;
        interva.second = stop;
        interva_list.push_back(interva);
        */
    }

    sort(interval_list.begin(),interval_list.end(),compare);

    if(interval_list.back().first!=t2)
    {
        interval.first = t2;
        interval.second = 'E';
        interval_list.push_back(interval);
    }

    vector<intv>::iterator mit2;
    vector<pair<double,double> >::iterator mit3;
    for(mit2 = interval_list.begin(); mit2 != interval_list.end(); ++mit2)
    {
        if(mit2->second == 'S')
        {
            if(mit2!=interval_list.begin())
            {
                mit2->collisions = (--mit2)->collisions+1;
                mit2++;
            }
            else
            {
                mit2->collisions = 1;
            }
        }
        if(mit2->second == 'E')
        {
            mit2->collisions = (--mit2)->collisions-1;
            mit2++;
        }
    }

     for(mit2 = interval_list.begin(); mit2 != interval_list.end(); ++mit2)
    {
        if(mit2->collisions==0)
        {
            if(length < ((++mit2)->first - (--mit2)->first))
            {
                length =((++mit2)->first - (--mit2)->first);
            }
        }


    }

    if(interval_list.size()>0)
    {
        printf("%.8f",length);
    }
    else
    {
        printf("%.8f",t2-t1);
    }
    return 0;
}
