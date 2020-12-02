#include<iostream>
#include<vector>

using namespace std;


class points
{
public:
    int x,y;


};
bool isvalid(vector<points>connect,vector<points> Red,vector<points> Blue,int i,int z);
void extend(vector<points> connect,int i,int z);
void backtrack(vector<points> connect,int i,int z);
void print(vector<points> connect,int z);
int main()
{
    int total;
    cin>>total;
    int temp=total/2,z=total/2;
    vector<points> Red(z),Blue(z),connect(z);

    while(temp>0)
    {
        cin>>Red[z-temp].x>>Red[z-temp].y;

        temp--;
    }

    while(temp<z)
    {
        cin>>Blue[temp].x>>Blue[temp].y;
        temp++;
    }
    int  i=0;
    connect[0].y=0;
    while(i<z)
    {
        if(isvalid(connect,Red,Blue,i,z))
        {
            if(i==z-1)
            {
                print(connect,z);
                break;
            }
            else
            {
                i++;
                connect[i].y=0;
            }
        }
        else
        {
            while(connect[i].y==z-1&&i>0)
            {
                i--;
            }
            connect[i].y++;
        }
    }

}

double i(points p1,points p2,points p3)
{
    double q=(p2.x-p1.x);
    double q2=(p2.x*p1.y-p1.x*p2.y);


    return p3.x*(p2.y-p1.y)-q*p3.y+q2;

}


bool intersect(points p1,points p2,points p3,points p4)
{
    if((i(p1,p2,p3)*i(p1,p2,p4)>0)||(i(p3,p4,p1)*i(p3,p4,p2)>0))
    {
        return false;
    }

    return true;
}

bool isvalid(vector<points> connect,vector<points> Red,vector<points> Blue,int i,int z)
{
    int b=0;
    while(b<i)
    {
        if(connect[b].y==connect[i].y)
        {
            return false;
        }
        if(intersect(Red[b],Blue[connect[b].y],Red[i],Blue[connect[i].y]))
        {
            return false;
        }

        b++;
    }

    return true;
}

void print(vector<points> connect,int z)
{
    int i=0;

    while(i<z)
    {
        cout<<i<<" "<<connect[i].y<<endl;
        i++;

    }
    return;
}
