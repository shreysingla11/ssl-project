#include<iostream>
using namespace std;

struct points
{
    int x;
    int y;
    int colour;
};

void recur(points p[],int n,int A[],int in,int Right[],int Left[])
{
    for(int i=0; i<n-1; i++)
    {
    int ch=0;
    int L[n/2],R[n/2];
        int r=0,b=0,le=0,ri=0;
        for(int j=0; j<n-1; j++)
        {
            int e1;
            e1=((((p[A[n-1]].y)-(p[A[i]].y))/((p[A[n-1]].x)-(p[A[i]].x)))*((p[A[j]].x)-(p[A[i]].x)))- ((p[A[j]].y)-(p[A[i]].y));
               if(e1>0)
            {
                L[le]=A[j];
                le++;
                if(p[A[j]].colour==1)
                {
                    r++;
                }
            }
            else
            {
                R[ri]=A[j];
                ri++;
                if(p[A[j]].colour==0)
                {
                    b++;
                }
            }
        }


        if(r==b && r>0)
        {
            if(n==4)
            {
            if (p[A[n-1]].colour==1){
            Left[]=A[n-1];
            Left[]=L[0];
            Right[]=R[0];
            Right[]=R[A[i]];
            ch=1;
            break;
            }
            else{


            }
            }
            else
            {
//l
            recur(p[in],((n/2)-1),L[le],in,Right[],Left[]);
//r
            recur(p[in],((n/2)-1),R[ri],in,Right[],Left[]);
            }
            break;
        }
        if(ch==1){break;}
    }
}
int main()
{
    int in1;
    cin>>in1;
    points p[in1];

    for(int i=0; i<(in1/2); i++)
    {
        cin>>p[i].x;
        cin>>p[i].y;
        p[i].colour=1;
    }
    for(int i=in1/2; i<(in1); i++)
    {
        cin>>p[i].x;
        cin>>p[i].y;
        p[i].colour=0;
    }
    int A[in1],Right[in1/2],Left[in1/2];
    for(int i=0; i<in1; i++)
    {
        A[in1]=in1;
    }
    recur(p[in1],in1,A[in1],in1,Right[in1/2],Left[in1/2]);

    return 0;
}

