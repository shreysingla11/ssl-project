#include<iostream>
//#include<algorithm>
#include<vector>

using namespace std;

bool intersect (vector<vector<int> > &redPoints , vector<vector<int> > &greenPoints,vector<int> &pairs,int i,int j)
{

    if(redPoints[i][0]==greenPoints[pairs[i]][0])
    {
        if(redPoints[j][0]==greenPoints[pairs[j]][0])
        {
            return false;
        }

        double m2 = (redPoints[j][1]-greenPoints[pairs[j]][1])*1.0/(redPoints[j][0]-greenPoints[pairs[j]][0]);
        int temp = (redPoints[j][0]-redPoints[i][0])*(greenPoints[pairs[j]][0]-redPoints[i][0]);
        if(temp >0)
        {
            return false;
        }

        int y;

        y = m2*(redPoints[i][0] - redPoints[j][0]) + redPoints[j][1];
        temp = (redPoints[i][1]- y)*(greenPoints[pairs[i]][1]- y);
        if(temp > 0)
        {
            return false;
        }
        return true;
    }

    if(redPoints[j][0]==greenPoints[pairs[j]][0])
    {
        double m1 = (redPoints[i][1]-greenPoints[pairs[i]][1])*1.0/(redPoints[i][0]-greenPoints[pairs[i]][0]);
        int temp = (redPoints[i][0]-redPoints[j][0])*(greenPoints[pairs[i]][0]-redPoints[j][0]);
        if(temp >0)
        {
            return false;
        }

        int y;

        y = m1*( redPoints[j][0] - redPoints[i][0] ) + redPoints[i][1];
        temp = (redPoints[j][1]- y)*(greenPoints[pairs[j]][1]- y);
        if(temp > 0)
        {
            return false;
        }
        return true;
    }

    float m1 = ((greenPoints[pairs[i]][1]-redPoints[i][1])*(1.0))/(greenPoints[pairs[i]][0]-redPoints[i][0]);
    float m2 = ((greenPoints[pairs[j]][1]-redPoints[j][1])*(1.0))/(greenPoints[pairs[j]][0]-redPoints[j][0]);
    float c2 = redPoints[j][1]*1.0 - m2*redPoints[j][0];
    float c1 = redPoints[i][1]*1.0 - m1*redPoints[i][0];
    float x = (c2-c1)/(m1-m2);
    float temp1 = (x-redPoints[i][0]*1.0)*(x-greenPoints[pairs[i]][0]);
    float temp2 = (x-redPoints[j][0]*1.0)*(x-greenPoints[pairs[j]][0]);
    if(temp1<0&temp2<0)
    {
        return true;
    }
    else
    {
        return false;
    }

}

int main()
{
    int n;
    cin>>n;
    n/=2;
    vector<vector<int> > redPoints(n,vector<int>(2));
    vector<vector<int> > greenPoints(n,vector<int>(2));

    vector<int> pairs(n);

    int i=0,x,y;

    while(i<n)
    {
        cin>>x>>y;
//redPoints.push_back((vector<int>(2).push_back(x)).push_back(y));
        redPoints[i][0]=x;
        redPoints[i][1]=y;
        pairs[i]=i;
        i++;
    }
    i=0;
    while(i<n)
    {
        cin>>x>>y;
        greenPoints[i][0]=x;
        greenPoints[i][1]=y;
        i++;
    }

    bool terminat = false;
    while(!terminat)
    {
        terminat = true;
        for(int i=0; i < n - 1; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                //cout<<i<<j;
                if(intersect(redPoints,greenPoints,pairs,i,j))
                {
                    //cout<<"please";
                    int temp = pairs[i];
                    pairs[i]=pairs[j];
                    pairs[j]=temp;
                    terminat=false;
                    break;
                }
                else{
                //cout<<"do";
                }
            }
            if(!terminat){
            break;
            }
        }
    }
    for(int i=0; i<n; i++)
    {
        cout<< i<<" "<<pairs[i]<<endl;
    }
}
