#include<iostream>
#include<vector>
using namespace std;

struct Point
{
    int x;
    int y;
    int index;
};

int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    return (val > 0)? 1: -1;
}

bool doIntersect(Point a, Point b, Point c, Point d)
{
    int o1 = orientation(a, b, c);
    int o2 = orientation(a, b, d);
    int o3 = orientation(c, d, a);
    int o4 = orientation(c, d, b);

    if ((o1*o2)<0 && (o3*o4)<0)
        return true;

    return false;
}

void printpairs(Point abcd[],int num_points)
{
    if(num_points==2)
    {
        cout<<abcd[0].index-1<<" "<<abcd[1].index-1<<"\n";
        return ;
    }

    int index[num_points];
    int indexac[num_points];
    int cred=0;
    int cblue=0;
    int c=0;
    int acred=0;
    int acblue=0;
    int ac=0;
    Point newarray[ac];
    Point newarray1[c];
    Point remaining[num_points];
    for(int i=1; i<=num_points; i++)
    {
        int cred=0;
        int cblue=0;
        int c=0;
        index[num_points]={0};
        indexac[num_points]={0};
        int acred=0;
        int acblue=0;
        int ac=0;
        for(int j=1; j!=0 && j<=num_points; j++)
        {
            if (orientation(abcd[0],abcd[i],abcd[j])>0)
            {
                index[c]=j;
                c++;
                if(j<=(num_points/2)) cred++;
                else  cblue++;
            }
            if (orientation(abcd[0],abcd[i],abcd[j])<0)
            {
                index[ac]=j;
                ac++;
                if(j<=(num_points/2)) acred++;
                else  acblue++;
            }

        }
        if(cred==cblue)
        {   bool clockwise=false;
            for(int i=0; i<c; i++)
            {
                newarray1[i].x=abcd[index[i]].x;
                newarray1[i].y=abcd[index[i]].y;
                newarray1[i].index=abcd[index[i]].index;
            }
            int z=0;
            for(int i=0; i<=num_points; i++)
            {
                for(int j=0; j<=c; j++)
                {
                    if (i!=index[j])
                    {
                        clockwise=true;
                    }
                    if(clockwise=false)
                    {
                        remaining[z]=abcd[i];
                        z++;
                    }
                }
            }
            break;
        }
        if(acred==acblue)
        {   bool anticlockwise=false;
            for(int i=0; i<ac; i++)
            {
                newarray[i].x=abcd[index[i]].x;
                newarray[i].y=abcd[index[i]].y;
                newarray[i].index=abcd[index[i]].index;

            }
            int z=0;
            for(int i=0; i<=num_points; i++)
            {
                for(int j=0; j<=ac; j++)
                {
                    if (i==index[j])
                    {   anticlockwise=true;
                    }
                    if (anticlockwise=false)
                    {
                        remaining[z]=abcd[i];
                        z++;
                    }
                }
            }
            break;
        }

    if(cred==cblue)
    {
        printpairs(newarray1,c);
        printpairs(remaining,num_points-c);
        return;
    }
    if(acred==acblue)
    {
        printpairs(newarray,ac);
        printpairs(remaining,num_points-ac);
        return;
    }

    }

}


int main()
{
    int num_points ;
    cin>>num_points;
    Point abcd[num_points];
    for(int i=0; i<num_points; i++ )
    {
        cin>> abcd[i].x;
        cin>> abcd[i].y;
    }
    for(int i=0; i<(num_points/2); i++)
    {
        abcd[i].index=i+1;
    }
    for(int i=(num_points/2);i<=num_points; i++)
    {
        abcd[i].index=1+i-num_points/2;

    }

    printpairs(abcd,num_points);
    return 0;
}
