#include<iostream>
using namespace std;
struct point{
public:
int x,y,z;
};
int middleline(point a,point b,point setred[],point setblue[],int n,int p)
{
float m,c;
int nred=0,nblue=0,r1=0,r2=0,b1=0,b2=0;
if(a.x==b.x)
{
    c=a.x;
}
else{
m=(a.y-b.y)/(a.x-b.x);
c=m*a.x-a.y;

}
        for(int k=0;k<n;k++)
        {
            if((m*setred[k].x-setred[k].y)>c)
            {
                nred++;
            }
            if((m*setblue[k].x-setblue[k].y)>c)
            {

                nblue++;
            }

        }
        if(nred==nblue)
        {
        cout<<"indices:("<<a.z+1<<","<<b.z+1<<")"<<endl;
        point red1[nred],red2[n-nred-1],blue1[nblue],blue2[n-nblue-1];
        p++;

        for(int k=0;k<n;k++)
        {
             if((m*setred[k].x-setred[k].y)>c)
            {
                red1[r1]=setred[k];
                r1++;
            }
            if((m*setblue[k].x-setblue[k].y)>c)
            {

                blue1[r1]=setblue[k];
                b1++;
            }

             if((m*setred[k].x-setred[k].y)<c)
            {
                red2[r2]=setred[k];
                r2++;
            }
            if((m*setblue[k].x-setblue[k].y)<c)
            {

                blue2[b2]=setblue[k];
                b2++;
            }
            for(int s=0;s<nred;s++)
            {
                for(int t=0;t<nblue;t++)
                {
                    if(middleline(red1[s],blue1[t],red1,blue1,nred,p)){;}
                    else{break;}

                }
            }
            for(int s=0;s<n-nred-1;s++)
            {
                for(int t=0;t<n-nblue-1;t++)
                {
                    if(middleline(red2[s],blue2[t],red2,blue2,n-nred-1,p)){;}
                    else{break;}
                }
            }
        }

            return p;
        }
        else
        {
            false;
        }


}

int main()
{
int n;
cout<<"Give total number of points"<<endl;
cin>>n;
n=n/2;
int i=0,p=0;
point R[n],B[n];
cout<<"Give red points"<<endl;
for(i=0;i<n;i++)
{
    cout<<i+1<<"th red point  "<<endl;
    cin>>R[i].x>>R[i].y;
    R[i].z=i;
}
cout<<"Give blue points"<<endl;
for(i=0;i<n;i++)
{
    cout<<i+1<<"th blue point  "<<endl;
    cin>>B[i].x>>B[i].y;
    B[i].z=i;
}

for(int g=0;g<n;g++)
{
    for(int h=0;h<n;h++)
    {
        p=middleline(R[g],B[h],R,B,n,p);
        //cout<<p+1<<"this is p"<<endl;
    }
}
return 0;


}
