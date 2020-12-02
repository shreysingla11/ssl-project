#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<cmath>
using namespace std;

struct point
{
    int x;
    int y;
    bool color;
    int index;
};
struct output
{
    int index1;
    int index2;
};
vector<output> out;
output tempo;
bool compare(output a,output b)
{
    return a.index1<b.index1?1:0;
}

void seperate(vector<point> &input,int n)
{
    int nr=0,nb=0;
    int pos;
    vector<point>temp1,temp2;
    if(n<2)
        return;
    if(n==2)
    {
       if(input[0].color==0)
        {
           tempo.index1=input[0].index;
           tempo.index2=input[1].index;
        }
        else
        {
           tempo.index1=input[1].index;
           tempo.index2=input[0].index;
        }
        out.push_back(tempo);
    }
    else {
    for(int i=1;i<n;i++)
    {
        nr=0;nb=0;
        temp1.clear();temp2.clear();
        if(input[i].x!=input[0].x)
        {

            for(int j=1;j<n;j++)
            {
                if(j!=i)
                {
                    if(input[j].x!=input[0].x)
                    {
                        pos=((input[i].x-input[0].x)*(input[j].y-input[0].y)-(input[i].y-input[0].y)*(input[j].x-input[0].x));
                        if(pos>0)
                        {
                               if(input[j].color==1)
                                    nb++;
                               else
                                    nr++;
                                temp1.push_back(input[j]);
                         }
                        else
                            temp2.push_back(input[j]);
                    }
                    else
                    {
                        if(input[j].y>input[0].y)
                        {
                                if(input[j].color==1)
                                    nb++;
                                else
                                    nr++;
                                temp1.push_back(input[j]);

                        }
                        else
                             temp2.push_back(input[j]);
                    }

                }
            }
        }
        else
        {   nr=0;nb=0;
            for(int j=1;j<n;j++)
            {
                if(j!=i)
                {
                    if(input[j].x>input[i].x)
                    {
                                if(input[j].color==1)
                                    nb++;
                                else
                                    nr++;
                                temp1.push_back(input[j]);
                    }
                    else
                        temp2.push_back(input[j]);

                }

            }

        }
        if(nr==0)
        {
        if(input[i].x!=input[0].x)
        {

            for(int j=1;j<n;j++)
            {
                if(j!=i)
                {
                    if(input[j].x!=input[0].x)
                    {
                        pos=((input[i].x-input[0].x)*(input[j].y-input[0].y)-(input[i].y-input[0].y)*(input[j].x-input[0].x));
                        if(pos<0)
                        {
                               if(input[j].color==1)
                                    nb++;
                               else
                                    nr++;
                                temp1.push_back(input[j]);
                         }
                        else
                            temp2.push_back(input[j]);
                    }
                    else
                    {
                        if(input[j].y<input[0].y)
                        {
                                if(input[j].color==1)
                                    nb++;
                                else
                                    nr++;
                                temp1.push_back(input[j]);

                        }
                        else
                             temp2.push_back(input[j]);
                    }

                }
            }
        }
        else
        {   nr=0;nb=0;
            for(int j=1;j<n;j++)
            {
                if(j!=i)
                {
                    if(input[j].x<input[i].x)
                    {
                                if(input[j].color==1)
                                    nb++;
                                else
                                    nr++;
                                temp1.push_back(input[j]);
                    }
                    else
                        temp2.push_back(input[j]);

                }

            }

        }
        }
        if(nr==nb&&nr!=0)
            {
                seperate(temp1,temp1.size());
                temp2.push_back(input[i]);
                temp2.push_back(input[0]);
                seperate(temp2,temp2.size());
                return ;
            }

    }
    }

}
int main()
{
    int N,a,b;
    point temp;
    vector<point> points;

    scanf("%d", &N);
    for (int i=0;i<N/2;i++)
    {
        scanf("%d",&a);
        scanf("%d",&b);
        temp.x=a;
        temp.y=b;
        temp.color=0;
        temp.index=i;
        points.push_back(temp);
    }
    for (int i=0;i<N/2;i++)
    {
        scanf("%d",&a);
        scanf("%d",&b);
        temp.x=a;
        temp.y=b;
        temp.color=1;
        temp.index=i;
        points.push_back(temp);
    }
    seperate(points,N);
    sort(out.begin(),out.end(),compare);
    for(int i=1;i<out.size();i++)
    {
        if(out[i].index1==out[i-1].index1)
        {
        while(i<out.size()&&out[i].index1==out[i-1].index1&&out[i].index2==out[i-1].index2)
            {out.erase(out.begin()+i-1);
            i++;}
        }
    }
    for(int i=1;i<out.size();i++)
    {
        if(out[i].index1==out[i-1].index1)
        {
        for(int j=i-1;j<N;j++){
            if(i!=j&&out[i-1].index2==out[j].index2&&out[i].index1==out[i-1].index1)
                {out.erase(out.begin()+i-1);
                break;}
            else if(i!=j&&out[i].index2==out[j].index2&&out[i].index1==out[i-1].index1)
                {out.erase(out.begin()+i); break;}

            }
        }
    }
    for(int i=0;i<out.size();i++)
    {
        cout<<out[i].index1<<" "<<out[i].index2;
        cout<<endl;
    }


}
