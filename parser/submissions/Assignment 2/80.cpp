#include<iostream>
#include<vector>
using namespace std;
int f( vector<vector<int> > &B, vector<vector<int> > &R, int n)
{
    if(n<=2)
    {
        cout<<R[0][2]<<" "<<B[0][2]<<endl;
    }
    else
    {
        vector<vector<int> > PR,NR,PB,NB;
        for(int j=0; j<n/2; j++)
        {
            //vector<vector<int> > P;
            //P.push_back(R[0]);
            //P.push_back(B[j]);
            int ind1=R[0][2];
            int ind2=B[j][2];
            for(int i=1; i<n; i++)
            {
                if(i<n/2)
                {
                    if(((R[i][1]-R[0][1])*(B[j][0]-R[0][0])-(B[j][1]-R[0][1])*(R[i][0]-R[0][0]))>0)
                    {
                        PR.push_back(R[i]);
                    }
                    else
                    {
                        NR.push_back(R[i]);
                    }
                }
                else
                {
                    if((i-n/2)!=j)
                    {
                        if(((B[i-n/2][1]-R[0][1])*(B[j][0]-R[0][0])-(B[j][1]-R[0][1])*(B[i-n/2][0]-R[0][0]))>0)
                        {
                            PB.push_back(B[i-n/2]);
                        }
                        else
                        {
                            NB.push_back(B[i-n/2]);
                        }
                    }
                }
            }
            if(PB.size()!=PR.size())
            {
                j++;
            }
            else
            {
                cout<<ind1<<" "<<ind2<<endl;
                f(PB,PR,n/2);
                f(NB,NR,n/2);
            }
        }
    }
    return 0;
}
int main()
{
    int num,x,y;
    cin>>num;
    vector<vector<int> > blue,red;
    vector<int> v;
    for(int i=0; i<num; i++)
    {
        v.resize(0);
        cin>>x;
        cin>>y;
        v.push_back(x);
        v.push_back(y);
        if(i<num/2)
        {
            v.push_back(i);
            red.push_back(v);
        }
        else
        {
            v.push_back(i-num/2);
            blue.push_back(v);
        }
    }
    //cout<<red[0][0]<<red[0][1]<<red[0][2];
    f(blue,red,num);
    return 0;
}
