#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
using namespace std;

int number;
int width;
int speed_ship;
int speed_ferry;
int start_time;
int end_time;

struct pairs
{
    double time_reach,time_leave;
};

struct doubles
{
    double time;
    bool value;
};

bool compare (doubles first, doubles second)
{
    if( second.time > first.time) return true;
    if( first.time > second.time) return false;
    else
    {
        if( first.value > second.value ) return true;
        else return false;
    }

}

vector<doubles> position;


int main()
{
    cin>>number>>width>>speed_ship>>speed_ferry>>start_time>>end_time;
    for(int i=0; i<number; i++)
    {
        //cout<<"Hi";
        char dir;
        int number_ships;
        cin>>dir;
        if(dir=='E')
        {
            cin>>number_ships;
            for(int j=0; j < (number_ships); j++)
            {
                int l,p;
                cin>>l>>p;
                //cout<<i;
                double temp_reach = ( double(-1*p) - ( (double)(i+1) * ((double)width/speed_ferry) * (double)speed_ship) ) / (double)speed_ship;
                double temp_leave = temp_reach + ((double)l/speed_ship) + (double)width/speed_ferry;
                if(temp_reach <= start_time ) temp_reach = start_time;
                if(temp_leave >= end_time) temp_leave = end_time;
                //if(temp_leave < 0) continue;
                //else
                //{
                    doubles starter;
                    doubles ender;
                    starter.time = temp_reach;
                    starter.value = true;
                    ender.time = temp_leave;
                    ender.value = false;
                    position.push_back(starter);
                    position.push_back(ender);
                //}
                //cout<<i;
            }
        }
        else
        {
            cin>>number_ships;
            for(int j=0; j < (number_ships); j++)
            {
                int l,p;
                cin>>l>>p;
                //cout<<i;
                double temp_reach = ( double(p) - ( (double)(i+1) * ((double)width/speed_ferry) * (double)speed_ship) ) / (double)speed_ship;
                double temp_leave = temp_reach + ((double)l/speed_ship) + (double)width/speed_ferry;
                if(temp_reach <= start_time ) temp_reach = start_time;
                if(temp_leave >= end_time) temp_leave = end_time;
                //if(temp_leave < 0) continue;
                //else
                //{
                    doubles starter;
                    doubles ender;
                    starter.time = temp_reach;
                    starter.time = temp_reach;
                    starter.value = true;
                    ender.time = temp_leave;
                    ender.value = false;
                    position.push_back(starter);
                    position.push_back(ender);
                //}
            //cout<<i;
            }
        }
    }

sort(position.begin(), position.end(), compare);

//for (int i=0; i<position.size();i++)
//{
//    cout<<position[i].time<<" "<<position[i].value<<endl;
//}

int counter=0;
double maximum = -1 * INFINITY;

//if( position[0].time >= start_time  )
//{
//    if(position[0].time >= end_time)
//    {
//        maximum = end_time - start_time;
//    }
//    else
//      {
        maximum = position[0].time - start_time;
//    }
//}

for (int i=0; i<position.size();i++)
{
    if(position[i].value) counter++ ;
    else counter-- ;
    if(counter == 0)
    {
        if( i != position.size() - 1)
        {
            double next_start = position[i+1].time ;
            double current_end = position[i].time;
            //if(start_time >= current_end && next_start <= end_time)
            //{
                double time_diff = next_start - current_end;
                if(time_diff > maximum) maximum = time_diff;
            //}
//            else if(start_time >= current_end && next_start <= end_time)
//            {
//                double time_diff = next_start - start_time;
//                if(time_diff > maximum) maximum = time_diff;
//            }
//            else if(start_time >= current_end && next_start >= end_time)
//            {
//                double time_diff = end_time - current_end;
//                if(time_diff > maximum) maximum = time_diff;
//            }
//            else if(start_time <= current_end && next_start >= end_time)
//            {
//                double time_diff = end_time - start_time;
//                if(time_diff > maximum) maximum = time_diff;
//            }

        }
        else
        {
            double current_end = position[i].time;
            if (end_time > current_end)
            {
                if(start_time > current_end)
                {
                double time_diff = end_time - start_time;
                if(time_diff > maximum) maximum = time_diff;
                }
                else
                {
                double time_diff = end_time - current_end;
                if(time_diff > maximum) maximum = time_diff;
                }
            }
        }

    }

}

//cout<<((double)maximum - ((double)width/speed_ferry))<<endl;
printf("%.8lf \n",((double)maximum));
return 0;

}
