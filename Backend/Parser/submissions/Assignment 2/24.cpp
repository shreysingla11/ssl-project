#include<iostream>
using namespace std;
struct point{
    int x;
    int y;
};
bool lie_on_diff_sides(point r1,point b1,point r2,point b2)
{
    int k=(b2.y-r1.y)*(b1.x-r1.x)-(b2.x-r1.x)*(b1.y-r1.y);
    int l=(r2.y-r1.y)*(b1.x-r1.x)-(r2.x-r1.x)*(b1.y-r1.y);
    //cout<<k<<endl<<l<<endl;
    if(k*l<0)
        return true;
    else
        return false;
}

bool intersects(point red1,point blue1,point red2,point blue2)
{
    if(lie_on_diff_sides(red1,blue1,red2,blue2)&&lie_on_diff_sides(red2,blue2,red1,blue1))
        return true;
    else
        return false;
}

int* check_config(int *config,int n,point *red,point *blue)
{
    int ret[2]={0};
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int k=config[i];
            int l=config[j];
            if(intersects(red[i],blue[k],red[j],blue[l])){
                ret[0]=i;
                ret[1]=j;
                return ret;
            }
        }
    }
    return ret;
}

int main()
{
    int n,i;
    cin>>n;
    if(n%2)
    {
        cout<<"Enter even value!";
        return -1;
    }
    n=n/2;
    point *red=new point[n];
    point *blue=new point[n];
    int *config=new int[n];

    for(i=0;i<n;i++){
        cin>>red[i].x>>red[i].y;
        config[i]=i;    //Initial configuration
    }
    for(i=0;i<n;i++)
        cin>>blue[i].x>>blue[i].y;

    int *val;
    while(true)
    {
        val=check_config(config,n,red,blue);
        if(!val[0]&&!val[1])
            break;
        else
            {
                i=val[0];
                int j=val[1];
                int temp=config[i];
                config[i]=config[j];
                config[j]=temp;
            }
    }
    for(i=0;i<n;i++)
        cout<<i<<" "<<config[i]<<endl;
    return 0;
}
