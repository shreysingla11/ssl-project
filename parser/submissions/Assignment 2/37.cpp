#include <iostream>
#include <vector>
using namespace std;

struct point
{
    int x;
    int y;
    int id;
};

vector< vector< point> > divide(point start,point ending,vector<point> &red,vector <point>&blue)
{
    vector<vector<point> > division(4);
    for (int k=0; k<red.size(); k++)
    {
        if ((red[k].y)*(start.x-ending.x)-(red[k].x)*(start.y-ending.y)+(start.y)*(ending.x)-(start.x)*(ending.y)<0)
        {
            division[2].push_back(red[k]);
        }
        else if ((red[k].y)*(start.x-ending.x)-(red[k].x)*(start.y-ending.y)+(start.y)*(ending.x)-(start.x)*(ending.y)>0)
        {
            division[3].push_back(red[k]);
        }

    }
    for (int k=0; k<blue.size(); k++)
    {
        if ((blue[k].y)*(start.x-ending.x)-(blue[k].x)*(start.y-ending.y)+(start.y)*(ending.x)-(start.x)*(ending.y)<0)
        {
            division[0].push_back(blue[k]);
        }
        else if ((blue[k].y)*(start.x-ending.x)-(blue[k].x)*(start.y-ending.y)+(start.y)*(ending.x)-(start.x)*(ending.y)>0)
        {
            division[1].push_back(blue[k]);
        }

    }
    return division;
}

void findline(vector <point> &red,vector<point> &blue,vector<point> &Redpaired ,vector<point> &Bluepaired  )
{
    if (red.size()==1)
    {

        Redpaired.push_back(red[0]);
        Bluepaired.push_back(blue[0]);
        return;
    }
    vector <point> LeftBlue,RightBlue,LeftRed,RightRed;
    vector<vector<point> > division(4);

    
    for (int j=0; j<blue.size(); j++)
    {
        division=divide(red[0],blue[j],red,blue);

        LeftBlue= division[0];

        RightBlue=division[1];
        LeftRed=division[2];
        RightRed=division[3];
        if (LeftBlue.size()==LeftRed.size())
        {

            Redpaired.push_back(red[0]);
            Bluepaired.push_back(blue[j]);
            break;

        }
    }


    if (LeftBlue.size()!=0)findline(LeftRed,LeftBlue,Redpaired,Bluepaired);
    if (RightBlue.size()!=0)findline(RightRed,RightBlue,Redpaired,Bluepaired);
}
int main()
{
    int twoN;
    cin >> twoN;
    int n = twoN/2;
    vector <point> red(n);
    vector <point> blue(n);
    for (int i=0; i<n; i++)
    {
        cin>>red[i].x;
        cin>>red[i].y;
        red[i].id=i;
    }
    for (int i=0; i<n; i++)
    {
        cin>>blue[i].x;
        cin>>blue[i].y;
        blue[i].id=i;
    }

    vector<point> Redpaired;
    vector<point> Bluepaired;
    findline(red,blue,Redpaired,Bluepaired);
    for (int i=0; i<n; i++)
    {
        cout<<Redpaired[i].id<<" "<<Bluepaired[i].id<<endl;
    }
}