#include <iostream>
#include <vector>

using namespace std;

class point
{
public :
    int id;
    int x;
    int y;


};

class line
{
public :

    point p1;       //red
    point p2;

    void setp1(point p)
    {
        p1.x=p.x;
        p1.y=p.y;
        p1.id=p.id;
    }          //blue
    void setp2(point p)
    {
        p2.x=p.x;
        p2.y=p.y;
        p2.id=p.id;
    }
};

bool is_Right(line l, point p);
vector<line> master(vector<point> &red_points, vector<point> &blue_points);
int main()
{
    int n;
    cin>>n;
    n=n/2;
    vector<point> red(n);
    vector<point> blue(n);
    for(int i=0; i<2*n ; i++)
    {
        if(i<n)
        {
            cin>>red[i].x>>red[i].y;
            red[i].id = i;
        }
        else
        {
            cin>>blue[i-n].x>>blue[i-n].y;
            blue[i-n].id = i-n;
        }
    }
    vector<line> l = master(red,blue);
    for(int i=0; i<l.size(); i++)
    {
        cout<<l[i].p1.id<<" "<<l[i].p2.id<<endl;
    }
    return 0;
}

vector<line> master(vector<point> &red_points, vector<point> &blue_points)
{
    vector<point> points_left_red;
    vector<point> points_right_red;
    vector<point> points_left_blue;
    vector<point> points_right_blue;
    vector<line> lines;
    int count_right_red=0;
    int count_right_blue=0;
    line l;
    int i = 0;
    l.setp1(red_points[0]);
    if(red_points.size()==1)
    {
        l.setp1(red_points[0]);
        l.setp2(blue_points[0]);
        lines.push_back(l);
        return lines;
    }
    for(i=0; i<blue_points.size(); i++)
    {
        l.setp2(blue_points[i]);
        points_left_red.clear();
        points_right_red.clear();
        points_left_blue.clear();
        points_right_blue.clear();
        for(int j=1; j<red_points.size(); j++)
        {
            if(is_Right(l, red_points[j]))
            {
                count_right_red ++;
                points_right_red.push_back(red_points[j]);
            }
            else
            {
                points_left_red.push_back(red_points[j]);
            }
        }
        for(int j=0; (j<blue_points.size()); j++)
        {
            if(j==i)
            {
                continue;
            }

            if(is_Right(l, blue_points[j]))
            {
                count_right_blue ++;
                points_right_blue.push_back(blue_points[j]);
            }
            else
            {
                points_left_blue.push_back(blue_points[j]);
            }
        }
        if( (count_right_red==count_right_blue))
        {
            break;
        }
    }


    lines.push_back(l);

    if((points_left_red.size()!=0)&&(points_left_blue.size()!=0))
    {
        vector<line> l1 = master(points_left_red,points_left_blue);
        lines.insert(lines.end(), l1.begin(), l1.end());
    }

    if((points_right_red.size()!=0)&&(points_right_blue.size()!=0))
    {
        vector<line> l2 = master(points_right_red,points_right_blue);
        lines.insert(lines.end(), l2.begin(), l2.end());
    }
    return lines;
}

bool is_Right(line l, point p)
{
    if(((p.y - l.p1.y)*(l.p2.x - l.p1.x) - (p.x - l.p1.x)*(l.p2.y - l.p1.y)) >0 )
        return true;
    else
        return false;
}
