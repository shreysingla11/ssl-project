#include <iostream>
#include <algorithm>
using namespace std;

struct Point
{
    int x;
    int y;
    int k;
};

int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    return (val > 0)? 1: -1;
}


void recursive(Point arr[],int n) {

if(n==2) {
cout<<arr[0].k<<" "<<arr[1].k<<endl;
return;
}

int redC,blueC,c,redAC,blueAC,ac;
int indexC[n];
int indexAC[n];

for (int i=1;i<n;i++) {
    redC=0;
    blueC=0;
    redAC=0;
    blueAC=0;
    c=0;
    ac=0;
    indexC[n]={0};
    indexAC[n]={0};

    for (int j=1; j!=i && j<n;j++) {
        if(orientation(arr[0],arr[i],arr[j])>0) {
            indexC[c]=j;
            c++;
            if(j<n/2) redC++;
            else blueC++;
            }
        if(orientation(arr[0],arr[i],arr[j])<0) {
            indexAC[ac]=j;
            ac++;
            if(j<n/2) redAC++;
            else blueAC++;
            }
            cout<<c<<" "<<ac;
        }
    if(redC==blueC && c!=0) {
        Point left[c];
        bool srch = false;
        for(int a=0;a<c;a++) {
            left[a].x = arr[indexC[a]].x;
            left[a].y = arr[indexC[a]].y;
            left[a].k = arr[indexC[a]].k;
        }
        Point right[n-c];
        int z=0;
        for (int b=0; b<n;b++) {
            for(int q=0;q<c;q++) {
                if(b==indexC[q]) {
                srch = true;
                }
            }
            if(srch==false) {
            right[z]=arr[b];
            z++;}
            }
            recursive(left,c);
            recursive(right,n-c);
            break;
        }
    if(redAC==blueAC && ac!=0) {
        Point left[ac];
        bool srch = false;
        for(int a=0;a<ac;a++) {
            left[a].x = arr[indexC[a]].x;
            left[a].y = arr[indexC[a]].y;
            left[a].k = arr[indexC[a]].k;
        }
        Point right[n-ac];
        int z=0;
        for (int b=0; b<n;b++) {
            for(int q=0;q<ac;q++) {
                if(b==indexC[q]) {
                srch = true;
                }
            }
            if(srch==false) {
            right[z]=arr[b];
            z++;}
        }
        recursive(left,ac);
        recursive(right,n-ac);
        break;
    }
}



}

int main() {

int n;
cin>>n;

Point Pts[n];

for (int i=0;i<n;i++) {
    cin>>Pts[i].x;
    cin>>Pts[i].y;
    if(i<n/2) Pts[i].k = i;
    else Pts[i].k = n/2 -i;
}

recursive(Pts,n);
return 0;
}
