#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<vector<int> > C(n);
    vector<int> node(n);
    for (int i=0; i<n; i++)
    {
        C[i].resize(n);
        for (int j=0; j<n; j++)
        {
            cin>>C[i][j];
        }
    }
    //cout<<"Input Finish"<<endl;

    vector<int> S(n);
    vector<int> S1(n);
    vector<int> goodness(n, 0);
    for (int i = 0; i < n; i++)//Initialize all min costs to infinity
        S[i]   = INT_MAX;
    S[0] = 0;

    for (int i = 0; i < n; i++)//Initialize all min costs to infinity
        S1[i]   = INT_MAX;
    S1[0] = 0;

    int c = 1;
    int good = 0;
    int breaked = 0;
    while(c == 1)
    {
        c = 0;
        for (int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(C[i][j] < 0)
                    good = 1;
                else
                    good = -1;
                if( ( S[i] != INT_MAX ) && ( ( S[i] + abs(C[i][j] ) ) < S1[j] ) )
                {
                    if ( (goodness[i] + good ) >= 0 )//the path is good
                    {
                        S1[j] = S[i] + abs (C[i][j] );
                        breaked = 0;
                    }
                    else
                    {
                        breaked =1;
                        break;
                    }
                    if(breaked == 0)
                    {
                        goodness[j] = goodness[i] + good ;
                        S[j] = S[i] + abs (C[i][j] );
                    }
                    c = 1;
                }
            }
        }
    }

    for (int v=0; v<n; v++)//to go from node 0 to node v
    {
        if(S1[v] == INT_MAX)
        cout<<"infinity"<<endl;
        else
        cout<<S1[v]<<endl;
    }

    return 0;
}
