#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

int main()
{
	int numnodes;
	cin>>numnodes;

	vector<int> oneline(numnodes,0);
	vector< vector<int> > costgiven( numnodes, oneline);

	vector<int> distance(numnodes,0);
	for (int i = 0;i<numnodes ; i++){
		distance[i] = INT_MAX;
	}

	vector<int> mincosts(distance);

	for (int i = 0; i<numnodes;i++){
		for (int j = 0 ;j<numnodes;j++){
			cin>>costgiven[i][j];
		}
	}

	distance[0] = 0;
	vector<int> pathgoodness(numnodes, 0);
	bool check;
	int edgegoodness;
    do{
        check = false;
        for (int i=0; i<numnodes; i++){
            for(int j=0; j<numnodes; j++){
            	if(costgiven[i][j] < 0){
            		edgegoodness = 1;
            	}else{
            		edgegoodness = -1;
            	}
                if( ( ( distance[i] != INT_MAX ) && ( ( distance[i] + abs(costgiven[i][j] ) ) < distance[j] ) ) ){
                    if ( (pathgoodness[i] + edgegoodness ) < 0 ){
                    	break;
                    	// do nothing
                    }
                    else{
                        mincosts[j] = distance[i] + abs (costgiven[i][j]);
                    }

                    pathgoodness[j] = pathgoodness[i] + edgegoodness ;
                    distance[j] = distance[i] + abs (costgiven[i][j] );
                    check = true;
                }
            }
        }
    }while( check == true);

    for (int i = 0; i <numnodes ; i++)
    {
        cout<<distance[i]<<endl;
    }
    return 0;
}
