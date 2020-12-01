#include<iostream>
#include<cmath>
#include<cstdio>
#include<vector>
using namespace std;

struct point
{
    int x_coordinate,y_coordinate,index;
};

void requiredpoints(vector<point> A,int start,int totalPoints)
{
    int c=0;
    if(totalPoints<2)
    {
        return;
    }
    if(totalPoints == 2)
    {
        cout<<A[start].index<<" "<<A[start+1].index<<endl;
        return;
    }
    int leftredpoints=0,rightredpoints=0,leftbluepoints=0,rightbluepoints=0,j,i,count=0;
    vector<point> leftpoint,rightpoint;
    //double slope;
    for(j =totalPoints/2; j<totalPoints; j++)
    {
        //slope = (A[j].y_coordinate - A[start].y_coordinate) / (A[j].x_coordinate - A[start].x_coordinate);
        for(i=0; i<totalPoints/2; i++)
        {
            if(i == start)
            {
                continue;
            }

            if((A[i].y_coordinate - A[j].y_coordinate)*(A[j].x_coordinate - A[start].x_coordinate) < (A[i].x_coordinate - A[j].x_coordinate)*(A[j].y_coordinate - A[start].y_coordinate))
            {
                leftpoint.push_back(A[i]);
                leftredpoints++;
            }

            if((A[i].y_coordinate - A[j].y_coordinate)*(A[j].x_coordinate - A[start].x_coordinate) > (A[i].x_coordinate - A[j].x_coordinate)*(A[j].y_coordinate - A[start].y_coordinate))
            {
                rightpoint.push_back(A[i]);
                rightredpoints++;
            }

        }

        for(i=totalPoints/2; i<totalPoints; i++)
        {
            if(i == j)
            {
                continue;
            }

            if((A[i].y_coordinate - A[j].y_coordinate)*(A[j].x_coordinate - A[start].x_coordinate) < (A[i].x_coordinate - A[j].x_coordinate)*(A[j].y_coordinate - A[start].y_coordinate))
            {
                leftpoint.push_back(A[i]);
                leftbluepoints++;
            }

            if((A[i].y_coordinate - A[j].y_coordinate)*(A[j].x_coordinate - A[start].x_coordinate) > (A[i].x_coordinate - A[j].x_coordinate)*(A[j].y_coordinate - A[start].y_coordinate))
            {
                rightpoint.push_back(A[i]);
                rightbluepoints++;
            }

        }

        count++;

        if(leftredpoints == leftbluepoints)
        {
            //cout<<leftredpoints<<endl<<rightredpoints;
            //cout<<"Hai"<<endl;
            c=1;
            break;
        }
        leftredpoints = 0;
        rightredpoints = 0;
        leftbluepoints = 0;
        rightbluepoints = 0;
        leftpoint.clear();
        rightpoint.clear();
    }
    if((count == totalPoints/2)&&(c!=1))
    {
        start++;
        requiredpoints(A,start,totalPoints);
        return;
    }
    //cout<<start<<endl;
    cout<<A[start].index<<" "<<A[j].index<<endl;
    start = 0;
    /*for(int k =0;k<rightredpoints;k++)
    {
        cout<<rightpoint[k].x_coordinate<<" "<<rightpoint[k].y_coordinate<<endl;
    }*/
    requiredpoints(leftpoint,start,leftredpoints+leftbluepoints);
    requiredpoints(rightpoint,start,rightredpoints+rightbluepoints);
    return;
};

int main()
{
    int totalPoints;
    cin>>totalPoints;
    vector <point> A;
    for(int i=0; i<totalPoints; i++)
    {
        point P;
        cin>>P.x_coordinate>>P.y_coordinate;
        if(i<totalPoints/2)
        {
            P.index = i;
        }
        else
        {
            P.index = i - (totalPoints/2);
        }
        A.push_back(P);
    }

    requiredpoints(A,0,totalPoints);
    /*for(int i =0;i<totalPoints;i++)
    {
        cout<<A[i].x_coordinate<<" "<<A[i].y_coordinate<<endl;
    }*/
    return 0;
}
