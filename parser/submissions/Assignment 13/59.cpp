#include <iostream>
#include <vector>
#include <limits.h>
#include <cmath>

using namespace std;

int main()
{
    int vertices;
    cin>>vertices;
    vector<vector<int> > cost(vertices);
    vector<int> node(vertices);
    for (int i=0; i<vertices; i++)
    {
        cost[i].resize(vertices);
        for (int j=0; j<vertices; j++)
        {
            cin>>cost[i][j];
        }
    }
    vector<int> cost_of_path(vertices);
    vector<int> cost_of_path_2(vertices);
    vector<int> goodness(vertices, 0);
    for (int i = 0; i < vertices; i++)
    {
        cost_of_path[i]   = INT_MAX;
    }
    cost_of_path[0] = 0;

    for (int i = 0; i < vertices; i++)
    {
        cost_of_path_2[i]   = INT_MAX;
    }
    cost_of_path_2[0] = 0;

    bool for_saturation = true;
    int check_good = 0;
    bool p=false;
    while(for_saturation == true)
    {
        for_saturation = false;
        for (int i=0; i<vertices; i++)
        {
            for(int j=0; j<vertices; j++)
            {
                if(cost[i][j] < 0)
                    check_good = 1;
                else
                    check_good = -1;
                if( ( ( cost_of_path[i] + abs(cost[i][j] ) ) < cost_of_path_2[j] ) && ( cost_of_path[i] != INT_MAX ) )
                {
                    if ( (goodness[i] + check_good ) >= 0 )
                    {
                        p = false;
                        cost_of_path_2[j] = cost_of_path[i] + abs (cost[i][j] );

                    }
                    else
                    {
                        p =true;
                        break;
                    }
                    if(p == false)
                    {
                        cost_of_path[j] = cost_of_path[i] + abs (cost[i][j] );
                        goodness[j] = goodness[i] + check_good ;
                    }
                    for_saturation = true;
                }
            }
        }
    }

    for (int i=0; i<vertices; i++)
    {
        if(cost_of_path_2[i] == INT_MAX){cout<<"infinity"<<endl;}
        else{
        cout<<cost_of_path_2[i]<<endl;
    }
    }
    return 0;
}
