#include <iostream>
#include<map>
#include<string>
#include<set>
#include<vector>
#include<algorithm>
#include<cstdio>

using namespace std;

struct SHIP
{
    //int lane;
    //char direction;
    //int length;
    //int position;
    float htf1;
    float htf2;
};

int main()
{

    int n,w,u,v,t1,t2;

    cin>>n>>w>>u>>v>>t1>>t2;

    float crossing_time = w/v;

    vector<SHIP> ship;

    for(int i=0; i<n; i++)
    {
        char Direction;
        int temp;

        cin>>Direction>>temp;

        for(int j=0; j<temp; j++)
        {
            int Position,Length;
            cin>>Length>>Position;

            float ht,lt;

            if((Direction=='E' && Position>Length)||(Direction=='W' && Position<-(Length)))
            {
                continue;
            }

            else
            {
                if((Direction=='E' && Position>0))
                {
                    ht=0.0;
                    lt=(Length-Position)/u;
                }

                if(Direction=='W' && Position<0)
                {
                    ht=0.0;
                    lt=(Length+Position)/u;
                }

                else
                {
                    if(Position<0)
                    {
                        ht=-(Position/u);
                        lt=-(Position-Length)/u;
                    }

                    else
                    {
                        ht=(Position/u);
                        lt=(Position+Length)/u;
                    }
                }
            }

            float htf,htf0;

            htf=ht-((i+1)*crossing_time);
            htf0=lt-((i)*crossing_time);

            if(htf>t2||htf0<t1)continue;

            else
            {
              if(htf0>t2) htf0=t2;

              if(htf<t1)  htf=t1;
            }

            SHIP temp1;

            temp1.htf1=htf;
            temp1.htf2=htf0;

            ship.push_back(temp1);

        }
    }

     int N=ship.size();

     vector<float> all_interval_points;
     map<float,bool> initial_time;

     for(int i=0;i<N;i++)
     {
       all_interval_points.push_back(ship[i].htf1);
       all_interval_points.push_back(ship[i].htf2);
       initial_time[ship[i].htf1]=true;
     }

     sort(all_interval_points.begin(),all_interval_points.end());

     int count=0;
     float max_interval=0;
      if(N !=0) max_interval=all_interval_points[0]-t1;

     for(int j=0;j<2*N;j++)
     {

       if(initial_time.find(all_interval_points[j])==initial_time.end())
       {
         count--;

         if(count==0 && j!=(2*N))
         {
         float temp2=all_interval_points[j+1]-all_interval_points[j];
         if(max_interval<temp2) max_interval=temp2;
         }

       }

       else count++;

     }
   if(N !=0)
   {
     if(max_interval<(t2-all_interval_points[(2*N)-1]))max_interval=(t2-all_interval_points[(2*N)-1]);
   }
   else max_interval=t2-t1;
   float final_ans=max_interval;
   printf("%0.8f \n",final_ans);
}

