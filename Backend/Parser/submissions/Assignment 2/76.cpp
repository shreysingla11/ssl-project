#include <iostream>
using namespace std;

struct point {
int x; int y;
int index;
};

double slope(point a, point b);
int linecheck(point a, point b, point c);
void linefind(point red[], point blue[], int n);

int main() {

int n;
cin>>n;

point red[n/2];
point blue[n/2];

int i,j,k;

for (i=0;i<n/2;i++) {
    cin>>red[i].x; cin>>red[i].y; red[i].index=i;
    }

for (i=0;i<n/2;i++) {
    cin>>blue[i].x; cin>>blue[i].y; blue[i].index=i;
    }
linefind(red,blue,n);
}

double slope(point a, point b) {
if((b.x-a.x)!=0) return ((b.y-a.y)/(b.x-a.x));
else return 9999999;
}

int linecheck(point a, point b, point c) {
double m=slope(a,b);
double line;
if (m!=9999999) line=m*c.x-c.y+a.y-a.x;
else line=c.y;

if(line>0) return 1;
else return 0;
}

void linefind(point red[], point blue[], int n) {
int rlcount=0, rrcount=0, blcount=0, brcount=0;
int i,j,k,l;
int liner,lineb;
    for(i=0;i<n/2;i++) {
        for (j=0;j<n/2;j++) {
            for(k=0;k<i;k++) {
                if((linecheck(red[i],blue[j],red[k]))==1) {rrcount=rrcount+1;}
                else {rlcount=rlcount+1;}
                }
            for(k=i+1;k<(n/2)-1;k++) {
                if((linecheck(red[i],blue[j],red[k]))==1) {rrcount=rrcount+1;}
                else {rlcount=rlcount+1;}
                //cout<<rrcount<<" "<<rlcount<<endl;
                    }
            for(k=0;k<j;k++) {
                if((linecheck(red[i],blue[j],blue[k]))==1) {brcount=brcount+1;}
                else {blcount=blcount+1;}
                }
            for(k=j+1;k<(n/2)-1;k++) {
                if((linecheck(red[i],blue[j],blue[k]))==1) {brcount=brcount+1;}
                else {blcount=blcount+1;}
                //cout<<brcount<<" "<<blcount<<endl;
                    }
                  // cout<<rrcount<<" "<<rlcount<<" "<<brcount<<" "<<blcount<<endl;
                if (rrcount==brcount&&(rrcount+rlcount)==(n/2)-1) {
                    liner=red[i].index; lineb=blue[j].index;
                    cout<<liner<<" "<<lineb<<endl;
                    for(l=i;l<(n/2)-1;l++){
                    red[l]=red[l+1];
                    }
                    for(l=j;l<(n/2)-1;l++){
                    blue[l]=blue[l+1];
                    }
                    linefind(red,blue,n-2);
                   break;
                }
                else continue;
        }
    }
}
