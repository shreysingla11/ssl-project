#include<iostream>
#include<cstdio>
#include<vector>
#include<sstream>
#include<algorithm>
using namespace std;

class point
{
public:
    int id;
    bool is_red;
    int x;
    int y;
    double theta;
    void enter_details(int a , int ex, int ey, bool v)
    {
        id = a;
        x = ex;
        y = ey;
        is_red = v;
    }
    void calculate_slope(int a_x , int b_y)
    {
        //<<"x: "<<x<<"y: "<<y<<"tx: "<<a_x<<"ty:"<<b_y<<endl;
        if(x!=a_x)
        {
            theta = (b_y-y)/((a_x-x*1.0)*1.0);
        }
        else
        {
            if(b_y<y)
            {
                theta = 200000;
            }
            else
            {
                theta = -200000;
            }
        }
        //<<"theta calc: "<<theta<<endl;
    }
    // point(bool v):is_red(v);
};

// class line{
// 	point *red;
// 	point *blue;
// };
//void sort_point(vector<point>&points, int begin, int end){
//
//}

bool comp(point a , point b)
{
    return (a.theta<b.theta);
}

string connect(vector<point>&points, int begin, int end)
{
    int len = end - begin;
    //<<"len : "<<len<<endl;//
    if (len<2)
    {
        //<<"\nERROR : len : "<<len<<endl;
        return "wtf";
    }
    if(len==2)
    {
        stringstream str;
        if(points[begin].is_red)
        {
            str<<printf("%d %d", points[begin].id, points[begin + 1].id);
        }
        else
        {
            str<<printf("%d %d", points[begin+1].id, points[begin].id);
        }
        return str.str();
    }

    int index_left=begin;
    for(int i = begin ; i < end ; i++)
    {
        if( points[i].x < points[index_left].x )
        {
            index_left = i;
        }
    }
    int i = index_left;
    //<<"LeftIndex:"<<points[i].id<<": "<<points[i].x<<" "<<points[i].y<<" "<<points[i].is_red<<endl;

////////////////////
    int tempx = points[index_left].x;
    int tempy = points[index_left].y;
    for(int i = begin ; i < end ; i++)
    {
        points[i].calculate_slope(tempx , tempy );
        //<<"temp:"<<tempx<<" "<<tempy<<endl;
        int j = i;
        //<<"Theta:"<<points[j].id<<": "<<points[j].x<<" "<<points[j].y<<" "<<points[j].is_red<<" "<<points[j].theta<<endl;

    }
    points[index_left].theta = -200005;

    vector<point>::iterator it1 = points.begin() + begin;
    vector<point>::iterator it2 = points.begin() + end;
    sort(it1 , it2 , comp);

    int num_b=0,num_r=0;
    int gf;
    if(points[begin].is_red)
    {
        //<<"red end:"<<end<<endl;//
        for( gf = end-1; gf>begin;)
        {
            if(points[gf].is_red)
            {
                num_r++;
            }
            else
            {
                num_b++;
            }
            gf--;
            if(num_b==num_r)
            {
                break;
            }
        }
        int i = gf;
        //<<"gf:"<<points[i].id<<": "<<points[i].x<<" "<<points[i].y<<" "<<points[i].is_red<<endl;


        stringstream str;
        str<<connect(points , begin , gf+1)<<endl;
        str<<connect(points , gf , end);

        cout<<str.str()<<endl;

        return str.str();
    }
    else
    {
        //<<"blue"<<endl;//
        for( gf = end-1; gf>begin;)
        {
            if(points[gf].is_red)
            {
                num_r++;
            }
            else
            {
                num_b++;
            }
            gf--;
            if(num_b==num_r)
            {
                break;
            }
        }

        stringstream str;
        str<<connect(points , begin , gf + 1)<<endl;
        str<<connect(points , gf , end);

        cout<<str.str()<<endl;
        return str.str();
    }


}

int main()
{
    int n;
    cin>>n;
    vector<point> all_points(n);
    n=n/2;
    for(int i =0 ; i<n ; i++)
    {
        int x,y;
        cin>>x>>y;
        all_points[i].enter_details(i,x,y,true);
    }
    for(int i =n ; i<2*n ; i++)
    {
        int x,y;
        cin>>x>>y;
        all_points[i].enter_details(i-n,x,y,false);
    }

    for(int i =0 ; i<2*n ; i++)
    {
        //<<all_points[i].id<<": "<<all_points[i].x<<" "<<all_points[i].y<<" "<<all_points[i].is_red<<endl;
    }

    //<<"OUTPUT:\n"<<endl;

    string output = connect(all_points, 0, all_points.size());
    cout<<output;

    return 0;
}
