#include<iostream>
using namespace std;

struct point
{
    int x,y;
    int isleft=0;

};

int n,N;
int num=1;
bool checkequalrab(point red[],point blue[],int n,int p,int q,int k);
void findcombination(point red[],point blue[],int n,int k,int l,int m);

bool checkequalrab(point red[],point blue[],int n,int p,int q,int k)
{
    int num=blue[q].y-red[p].y;
    int den=blue[q].x-red[p].x;
    int rl=0,rr=0,bl=0,br=0;
    int f,g;
    point nred[n],nblue[n];
    int c=0;
    while(c!=0)
    {
        nred[c].x=red[c].x;
        nred[c].y=red[c].y;
        nred[c].isleft=red[c].isleft;
        nblue[c].x=blue[c].x;
        nblue[c].y=blue[c].y;
        nblue[c].isleft=blue[c].isleft;
    }
    for(f=0; f<n,f!=p; f++)
    {
        if((num*(red[f].x-red[p].x)-(den*(red[f].y-red[p].y)))>0)
        {
            if(red[f].isleft==k)
                red[f].isleft=1;
            rl++;
        }
        else
        {
            if(red[f].isleft==k)
                red[f].isleft=0;
            rr++;
        }
    }
    for(g=0; g<n,g!=q; g++)
    {
        if((num*(blue[g].x-blue[q].x)-(den*(blue[g].y-blue[q].y)))>0)
        {
            if(blue[g].isleft==k)
                blue[g].isleft=1;
            bl++;
        }
        else
        {
            if(blue[g].isleft==k)
                blue[g].isleft=0;
            br++;
        }
    }
    if(rl==bl&&rr==br)
    {
        if(num==n)
        return true;
        cout<<p<<" "<<q<<endl;
        red[p].isleft=2;
        blue[q].isleft=2;
        num++;
        return true;
    }
    else
    {
        int c=0;
        while(c!=0)
        {
            red[c].isleft=nred[c].isleft;
            blue[c].isleft=nblue[c].isleft;
        }

        return false;
    }

}

void findcombination(point red[],point blue[],int n,int k,int l,int m)
{
    int q=0,p=0;
    for(p=0; p<n,p!=l; p++)
    {
        for(q=0; q<n,q!=m; q++)
        {

            if(checkequalrab(red,blue,n,p,q,k))
            {

                findcombination(red,blue,n,1,p,q);
                findcombination(red,blue,n,0,p,q);
            }

        }
    }
    return ;
}

int main()
{
    int i,x,y;
    cin>>N;
    n=N/2;
    point red[n], blue[n];
    for(i=0; i<N; i++)
    {
        cin>>x>>y;
        if(i<n)
        {
            red[i].x=x;
            red[i].y=y;
        }
        else
        {
            blue[i-n].x=x;
            blue[i-n].y=y;
        }
    }
    findcombination(red,blue,n,0,n,n);

    return 0;
}
