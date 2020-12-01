#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
int n_lanes,speed_ship,speed_ferry,width_lane;double t_1,t_2;
vector <pair<double,double> > forbidden_interval;
bool lessthan(pair<double,double> p1,pair<double,double> p2)
{
 if(p1.first<p2.first)return true;else return false;
}
struct lane
{
    int lane_no;
    char direction;
    int no_of_ships;
    double *position;
    double *length;
    void get_positions_and_length()
    {
        position = new double [no_of_ships];
        length = new double [no_of_ships];
        for(int i=0; i<no_of_ships; i++)
        {
            cin>>length[i]>>position[i];
        }
        return;
    }
    void get_forbidden_interval()
    {
      if(direction=='E')
      {
      for(int i=0; i<no_of_ships; i++)
        {
          pair<double,double> interval;
          double time,time1,time2;
          time = width_lane/speed_ferry;
          time1= (-(speed_ship*time)-position[i])/speed_ship;
          time2= (length[i]-position[i])/speed_ship;
          interval.first = (time1 - (lane_no*time));
          interval.second = (time2 - (lane_no*time));
          forbidden_interval.push_back(interval);
        }
      }
      else
      {
       for(int i=0; i<no_of_ships; i++)
        {
          pair<double,double> interval;
          double time,time1,time2;
          time = width_lane/speed_ferry;
          time1= (-(speed_ship*time)+position[i])/speed_ship;
          time2= (length[i]+position[i])/speed_ship;
          interval.first = (time1 - (lane_no*time));
          interval.second = (time2 - (lane_no*time));
          forbidden_interval.push_back(interval);

        }

      }

    }

};
int main()
{
   double maximum=0;
    cin>>n_lanes>>width_lane>>speed_ship>>speed_ferry>>t_1>>t_2;
    lane *A = new lane[n_lanes];
    for(int i=0; i<n_lanes; i++)
    {
        cin>>A[i].direction>>A[i].no_of_ships;
           A[i].get_positions_and_length();
           A[i].lane_no=i;
           A[i].get_forbidden_interval();
    }
   sort(forbidden_interval.begin(),forbidden_interval.end(),lessthan);
    for(int i=0;i<forbidden_interval.size();i++)
        {
         int j=i+1;double max_interval=forbidden_interval[i].second;
         //cout<<"hello "<<forbidden_interval[i].first<<" "<<forbidden_interval[i].second<<endl;
         while((forbidden_interval[j].first<=max_interval)&&(j<forbidden_interval.size()))
         {
          if(max_interval<forbidden_interval[j].second)max_interval=forbidden_interval[j].second;
          //cout<<"hello "<<forbidden_interval[j].first<<" "<<forbidden_interval[j].second<<endl;
          j++;
         }
         //i=j;
         if((forbidden_interval[j].first>=t_1)&&(max_interval<=t_2))
        if(maximum<(forbidden_interval[j].first-max_interval))maximum=forbidden_interval[j].first-max_interval;
        }
    printf("%.8f \n",maximum);
    //for(int i=0;i<forbidden_interval.size();i++)
    //cout<<forbidden_interval[i].first<< " "<<forbidden_interval[i].second<<endl;
    return 0;
}







