#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

class point
{
public:
    int x,y;
    point()
    {
        x=0;
        y=0;
    }
    point(int p,int q)
    {
        x=p;
        y=q;
    }
};

bool intersect(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4)
{
    int p=0,q=0,r=0,s=0,t=0;
    float a=0.0;
    t=((y2-y1)*(x4-x3))-((y4-y3)*(x2-x1));
    if(t==0)
    {
        return false;
    }
    a=0.0;
    p=y2-y1;
    q=x2-x1;
    r=y4-y3;
    s=x4-x3;
    a=((p*s*x1)-(q*r*x3)-(q*s*y1)+(q*s*y3))/((((y2-y1)*(x4-x3))-((x2-x1)*(y4-y3)))/1.0);
    if(((x1/1.0)<a)&&(a<(x2/1.0))&&(x1<x2))
    {
        return true;
    }
    if(((x2/1.0)<a)&&(a<(x1/1.0))&&(x1>x2))
    {
        return true;
    }
    return false;
}

int main()
{
    int n=0,i=0,j=0,temp=0;
    scanf("%d",&j);
    n = j/2;
    j=0;
    vector <point> red(n);
    vector <point> blue(n);
    vector <int> line(n);
    bool swap=true,inter=false;
    for(i=0; i<n; i++)
    {
        line[i] = i;
    }
    for(i=0; i<n; i++)
    {
        scanf("%d %d",&red[i].x,&red[i].y);
    }
    for(i=0; i<n; i++)
    {
        scanf("%d %d",&blue[i].x,&blue[i].y);
    }
    int e=0;
    while(1)
    {
        e=0;
        for(j=1; (swap==true); j++)
        {
            swap = false;
            for(i=0; i<n-1; i++)
            {
                int x1 = red[i].x , y1 = red[i].y;
                int x2 = blue[line[i]].x , y2 = blue[line[i]].y;
                int x3 = red[i+1].x , y3 = red[i+1].y;
                int x4 = blue[line[i+1]].x , y4 = blue[line[i+1]].y;
                inter = intersect(x1,y1,x2,y2,x3,y3,x4,y4);
                if(inter)
                {
                    swap = true;
                    temp = line[i];
                    line[i] = line[i+1];
                    line[i+1] = temp;
                }
            }
        }
        if(!swap)
        {
            for(int k=0; k<n-1; k++)
            {
                for(int l=k+1                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               ; l<n; l++)
                {
                    int x1 = red[k].x , y1 = red[k].y;
                    int x2 = blue[line[k]].x , y2 = blue[line[k]].y;
                    int x3 = red[l].x , y3 = red[l].y;
                    int x4 = blue[line[l]].x , y4 = blue[line[l]].y;
                    inter = intersect(x1,y1,x2,y2,x3,y3,x4,y4);
                    if(inter)
                    {
                        swap = true;
                        e++;
                        temp = line[k];
                        line[k] = line[l];
                        line[l] = temp;
                        break;
                    }
                }
            }
        }
        if(e==0&&!swap)
        {
            break;
        }
    }
    for(i=0; i<n; i++)
    {
        printf("%d %d\n",i,line[i]);
    }
    return 0;
}
