#include<iostream>
#include<vector>

using namespace std;

bool isright(int ax,int ay,int bx,int by,int cx,int cy)
{
    return ((bx - ax)*(cy - ay) - (by - ay)*(cx - ax)) > 0;
}

int thenext(vector<int> paired)
{
    int j=0;
    for(int i=0; i<paired.size(); i++)
    {
        if (j==paired[i])
        {
            j++;
            i=0;
        }
    }
    return j;
}

int thenextnext(vector<int> &paired)
{
    int j=0,count1=0;
    for(int i=0; i<paired.size(); i++)
    {
        if (j==paired[i])
        {
            j++;
            i=0;
        }
    }
    j++;
    for(int i=0; i<paired.size(); i++)
    {
        if (j==paired[i])
        {
            j++;
            i=0;
        }
    }
    return j;
}

int orient(int ax,int ay,int bx,int by,int cx,int cy)
{
    int val = (by - ay) * (cx - bx) - (bx - ax) * (cy - by);
    return (val > 0)? 1: 2;
}


int main()
{
    int n,temp,redright=0,redleft=0,blueright=0,blueleft=0,k=0,a=0,b=0,c=0,p,q,r,s,flag=0,ite=0;
    int o1,o2,o3,o4;
    cin>>n;
    vector<int> redx,redy,bluex,bluey,bluepair;
    double m1,m2;

    for (int i=0; i<n; i++)
    {
        if (i<n/2)
        {
            cin>>temp;
            redx.push_back(temp);
            cin>>temp;
            redy.push_back(temp);
        }
        else
        {
            cin>>temp;
            bluex.push_back(temp);
            cin>>temp;
            bluey.push_back(temp);
        }
    }
    while (true)
    {
    if (n/2-k<=2)
    {
    o1=orient(redx[a],redy[a],bluex[b],bluey[b],redx[a+1],redy[a+1]);
    o2=orient(redx[a],redy[a],bluex[b],bluey[b],bluex[thenextnext(bluepair)],bluey[thenextnext(bluepair)]);
    o3=orient(redx[a+1],redy[a+1],bluex[thenextnext(bluepair)],bluey[thenextnext(bluepair)],redx[a],redy[a]);
    o4=orient(redx[a+1],redy[a+1],bluex[thenextnext(bluepair)],bluey[thenextnext(bluepair)],bluex[b],bluey[b]);
    if (o1 != o2 && o3 != o4)
        {
        cout<<a<<"  "<<thenextnext(bluepair)<<endl;
        cout<<a+1<<"  "<<b<<endl;
        }
        else
        {
        cout<<a<<"  "<<b<<endl;
        cout<<a+1<<"  "<<thenextnext(bluepair)<<endl;
        }
        break;
    }

        for (b=0; b<n/2;b++)
        {
            redleft=0;
            redright=0;
            blueleft=0;
            blueright=0;
            for (c=0; c<n/2; c++)
            {
                if (c==b)
                {
                    continue;
                }

                if(isright(redx[a],redy[a],bluex[b],bluey[b],bluex[c],bluey[c]))
                {
                    blueright++;

                }
                else
                {
                    blueleft++;

                }

            }
            for (c=0; c<n/2; c++)
            {
                if (c==b)
                {
                    continue;
                }
                if(isright(redx[a],redy[a],bluex[b],bluey[b],redx[c],redy[c]))
                {
                    redright++;
                }
                else
                {
                    redleft++;
                }

            }
            if ((redleft==blueleft)&&(redright==blueright)&&((redright>0&&redleft>0)))
            {
                bluepair.push_back(b);
                k++;
                break;
            }

        }
        a++;
        b=thenext(bluepair);
        c=0;
        if (a==n/2)
            break;
    }
    for (int i=0; i<bluepair.size(); i++)
    {
        cout<<i<<" "<<bluepair[i]<<endl;
    }
    return 0;
}

