#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Point{
    int x,y, id;
    Point()
    {}
    Point(int X, int Y, int i)
    {
        x=X;
        y=Y;
        id=i;
    }
};

bool CompF(Point X, Point Y)
{
    return (X.x<Y.x);
}

struct Line{
    double a,b,c;
    Line(Point P1, Point P2)
    {
                a=P1.y-P2.y;
                b=(P1.x-P2.x)*(-1);
                c=P1.x*P2.y-P2.x*P1.y;
    }
    int sign(Point X)
    {
        if(a*X.x+b*X.y+c>0)
            return 1;
        else
            return -1;
    }
    bool oppSide(Point X, Point Y)
    {
        if(sign(X)*sign(Y)<0)
            return true;
        else
            return false;
    }
};
void findPair(Point R[], Point B[], int beginB, int endB , int A[])
{  int posR=0, posB=0, negB=0, negR=0, i, j;
   if(endB==beginB&&endB>=0)
   { A[R[beginB].id]=B[beginB].id;
     return;
   }
   if(endB<beginB)
     return;

   Point Rp[endB-beginB+1], Bp[endB-beginB+1], Rn[endB-beginB+1], Bn[endB-beginB+1];


   //cout<<beginB<<' '<< endB<<endl;

   for(i=beginB; i<=endB; i++)
   {    Line L(B[(beginB+endB)/2],R[i]);
        posR=posB=negR=negB=0;
        for(j=beginB; j<=endB; j++)
        {
           // cout<<j;
            if(j!=i)
            { if(L.sign(R[j])>0)
              {
                Rp[posR]=R[j];
                posR++;
              }
              else
                Rn[negR++]=R[j];
            }
            if(j!=(beginB+endB)/2)
            {
              if(L.sign(B[j])>0)
                 Bp[posB++]=B[j];

              else
                 Bn[negB++]=B[j];
            }
        }
        if(posB==posR)
        {   A[R[i].id]=B[(beginB+endB)/2].id;
            break;
        }
    }


   findPair(Rp,Bp, beginB, posR+beginB-1,A);
   findPair(Rn,Bn, beginB, negR+beginB-1,A);

}

int main()
{
    int n=0, x, y;
    Point P;
    cin>>n;
    Point Red[n/2], Blue[n/2];
    for(int i=0; i<n/2; i++)
    {   Red[i].id=i;
        cin>>Red[i].x>>Red[i].y;
    }
    for(int i=0; i<n/2; i++)
    {   Blue[i].id=i;
        cin>>Blue[i].x>>Blue[i].y;
    }
//    cout<<x;

  //  sort(Red.begin(), Red.end(), CompF);
   // sort(Blue.begin(), Red.end(), CompF);
    int A[n/2];
    for(int i=0; i<n/2; i++)
        A[i]=i;

    findPair(Red, Blue, 0,n/2-1, A);

    for(int i=0; i<n/2; i++)
    {
       cout<<i<<' '<<A[i]<<"\n";
    }
    return 0;
}
