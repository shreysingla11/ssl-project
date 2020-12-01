#include <iostream>
#include <vector>
#include <list>

using namespace std;

int orientation(vector<int> a,vector<int> b,vector<int> c)
{
    int value=(b[1]-a[1])*(c[0]-b[0])-(b[0]-a[0])*(c[1]-b[1]);

    if(value > 0)
    {
        return 1;//clockwise
    }
    else
    {
        return 2;//anti-clockwise
    }
}//end of orientation()

int doIntersect(vector<int> p1, vector<int> q1, vector<int> p2, vector<int> q2)
{
    if( (orientation(p1,q2,q1)!=orientation(p1,p2,q1)) && ((orientation(p2,q1,q2)!=orientation(p2,p1,q2))) )
    {
        return 1;//the two lines intersect
    }
    else
    {
        return 0;//the two lines don't intersect
    }
}//end of doIntersect()

int position(vector<int> a, vector<int> b, vector<int> m)
{
    int val=(b[0]-a[0])*(m[0]-a[1]) - (b[1]-a[1])*(m[0]-a[0]);

    if(val>0)//lie on one side
    {
        return 1;
    }
    else//lie on second side
    {
        return 0;
    }
}//end of position()


void display(vector<vector <int> > &r, vector<vector <int> > &b, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        cout<<i<<" "<<r[i][2]<<endl;
    }
}//end of display()

int RlEqualsBl(vector<vector <int> > &r, vector<vector <int> > &b, int n, int i, int k, vector<vector <int> > &r1, vector<vector <int> > &b1, vector<vector <int> > &r2, vector<vector <int> > &b2, int nrl)//to check whether no. of red points on left are equal to no. of blue points on left
{
    int j,nbl;
    nbl=0;

    if(k<n)//k refers to red point
    {

    for(j=0;j<n;j++)
    {
        if(j==i)
        continue;

        if( position(r[i], r[k], r[j]) == 1)
        {
            nrl++;

            vector <int> p(3,0);
            p=r[j];
            r1.push_back(p);
        }

        else
        {
            vector <int> p(3,0);
            p=r[j];
            r2.push_back(p);
        }
    }

    for(j=0;j<n;j++)
    {
        if(j==r[i][2])
        continue;

        if( position(r[i], r[k], b[j]) == 1)
        {
            nbl++;
            vector <int> p(2,0);
            p=b[j];
            b1.push_back(p);
        }

        else
        {
            vector <int> p(2,0);
            p=b[j];
            b2.push_back(p);
        }

    }

    if(nrl==nbl)//no. of red points on left = no. of blue points on left
    {
        return 1;
    }

    else
    {
        return 0;
    }


            vector <int> p(3,0);
            p=r[i];

    r2.push_back(p);
            p=r[k];
    r2.push_back(p);

    }

    else//other point of line is blue point
    {
        int k1=k-n;
        for(j=0;j<n;j++)
        {
            if(j==i)
            continue;

            if( position(r[i], b[k1], r[j]) == 1)
            {
                nrl++;
                vector <int> p(3,0);
                p=r[j];
                r1.push_back(p);
            }

            else
            {
                vector <int> p(3,0);
                p=r[j];
                r2.push_back(p);
            }
        }

        for(j=0;j<n;j++)
        {
            if(j==r[i][2])
            continue;

            if( position(r[i], b[k1], b[j]) == 1)
            {
                nbl++;
                vector <int> p(2,0);
                p=b[j];
                b1.push_back(p);
            }

            else
            {
                vector <int> p(2,0);
                p=b[j];
                b2.push_back(p);
            }
        }

        if(nrl==nbl)//no. of red points on left = no. of blue points on left
        {
            return 1;
        }

        else
        {
            return 0;
        }

        vector <int> p(3,0);
            p=r[i];

    r2.push_back(p);

            vector <int> q(2,0);
            q=b[k1];
    b2.push_back(q);
    }

}//end of RlEqualsBl()

void solution2(vector<vector <int> > &r, vector<vector <int> > &b, int n)
{

int k;

    for(k=0;k<(2*n);k++)
    {
        vector<vector <int> > r1;
        vector<vector <int> > b1;

        vector<vector <int> > r2;
        vector<vector <int> > b2;

        int nrl=0;
        if( RlEqualsBl( r, b, n, 1, k, r1, b1, r2, b2, nrl) == 1)//no. of red points on left = no. of blue points on left
        {
            do
            {
            int nrl=0;
            solution2(r1, b1, nrl);
            solution2(r2, b2, (n-nrl));
            }
            while( (r1.size()==0) && (r2.size()==0) );
        }
    }
}

void solution1(vector<vector <int> > &r, vector<vector <int> > &b, int n)
{
    int i,j,c;

    for(i=0;i<n;i++)//connect all ith red points with ith blue points
    {
        r[i][2]=i;
    }
    //r[i][2] represents the element of the b vector to which it is connected

    c=1;
    while(c!=0)
    {
    c=0;
    for(i=0;i<n;i++)//loop to check every two lines
    {
        for(j=i+1;j<n;j++)
        {
            if(doIntersect(r[i],b[i],r[j],b[j])==1)//if intersect then exchange the corresponding b elements to which they point
            {
                c=1;
                {//swapping r[i][2] and r[j][2]
                    int temp;
                    temp=r[i][2];
                    r[i][2]=r[j][2];
                    r[j][2]=temp;
                }
            }
        }
    }

    }//c=0 implies no two lines intersect

    display(r, b, n);
}//end of solution()


int main()
{
    int n,i;
    cin>>n;
    vector <int> p(3,0);//(0,0,0)
    vector <int> q(2,0);//(0,0)
    vector<vector <int> > r((n/2),p);
    vector<vector <int> > b((n/2),q);

    for(i=0;i<(n/2);i++)
    {
        cin>>r[i][0]>>r[i][1];
    }

    for(i=0;i<(n/2);i++)
    {
        cin>>r[i][0]>>r[i][1];
    }

    solution1(r,b,(n/2));//solve by method one

    solution2(r, b, (n/2));//solve by recursive way

    return 0;
}
