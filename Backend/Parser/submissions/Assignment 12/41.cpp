#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int total;
    int mini=0;
    int maxi=0;
    cin>>total;
    maxi=total;
    vector<int>going;
    vector<int>nofrndsgone;
    vector<int>thrshld;
    for(int i=0; i<total; i++)
    {
        going.push_back(0);
        nofrndsgone.push_back(0);
    }
    vector<int>nofrends;
    vector<vector<bool> >myfrens(total);
    for(int j=0; j<total; j++)
    {
        int thresh;
        cin>>thresh;
        thrshld.push_back(thresh);
        int numfr;
        cin>>numfr;
        nofrends.push_back(numfr);
        int val;
        for(int j1=0; j1<numfr; j1++)
        {
            cin>>val;
            myfrens[j][val]=true;
        }
    }
    for(int k2=0; k2<total; k2++)
    {
        for(int k3=0; k3<total; k3++)
        {
            if(k2==thrshld[k3])
            {
                if(nofrndsgone[k3]>=thrshld[k3])
                {
                    going[k3]++;
                    mini++;
                    for(int aux2=0; aux2<total; aux2++)
                    {
                        if(myfrens[aux2][k3])
                        {
                            nofrndsgone[aux2]++;
                        }
                    }
                }
                else {}
            }
            else {}
        }
    }

    for(int xx=0; xx<total; xx++)
    {
        going[xx]=0;
        nofrndsgone[xx]=nofrends[xx];
        if(thrshld[xx]>(total-1))
        {
            thrshld[xx]=total;
        }
    }

    for(int xk2=total; xk2>=0; xk2--)
    {
        for(int xk3=0; xk3<total; xk3++)
        {
            if(xk2==thrshld[xk3])
            {
                if(nofrndsgone[xk3]<thrshld[xk3])
                {
                    going[xk3]++;
                    maxi--;
                    for(int xaux2=0; xaux2<total; xaux2++)
                    {
                        if(myfrens[xaux2][xk3])
                        {
                            nofrndsgone[xaux2]--;
                        }
                    }
                }
                else {}
            }
            else {}
        }
    }
    cout<<mini<<" "<<maxi<<endl;
    return 0;
}
