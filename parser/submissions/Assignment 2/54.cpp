#include <iostream>
using namespace std;
struct point{
    int x;
    int y;
};
double eq(point a,point b,point c){
    return ((c.x-a.x)*(b.y-a.y)-(c.y-a.y)*(b.x-a.x));
}
bool check(point m,point n,int k[],int l[],point r[],point b[],int p){
    int i=0,j=0,numb1=0,numb2=0;
    while(i<p){
        if(eq(m,n,r[k[i]])>0){
            numb1++;
        }
        i++;
    }
    while(j<p){
        if(eq(m,n,b[l[j]])>0){
            numb2++;
        }
        j++;
    }
    return numb1==numb2;
}
void func(int k[],int l[],point r[],point b[],int n){
    if(n==0){
        return;
    }
    else{
        int j=0;
        int k1[n],l1[n],k2[n],l2[n];
        while(j<n){
            if(check(r[k[0]],b[l[j]],k,l,r,b,n)){
                break;
            }
            j++;
        }
        cout<<k[0]<<' '<<l[j]<<endl;
        int w=0,z=0,numb1=0,numb2=0;

        while(numb1<n){
            if(eq(r[k[0]],b[l[j]],r[k[w]])>0){w++;}
            if(eq(r[k[0]],b[l[j]],r[k[z]])<0){z++;}
            cout<<(eq(r[k[0]],b[l[j]],r[k[w]])==0)<<endl;
            numb1++;
        }
        int e=0,f=0,g=0,h=0;
        while(e<n){
            if(eq(r[k[0]],b[l[j]],r[k[e]])>0){k1[g]=k[e];g++;}
            e++;
        }
        while(f<n){
            if(eq(r[k[0]],b[l[j]],b[l[f]])>0){l1[h]=l[f];h++;}
            f++;
        }
        e=0,f=0,g=0,h=0;
        while(e<n){
            if(eq(r[k[0]],b[l[j]],r[k[e]])<0){k2[g]=k[e];g++;}
            e++;
        }
        while(f<n){
            if(eq(r[k[0]],b[l[j]],b[l[f]])<0){l2[h]=l[f];h++;}
            f++;
        }
        func(k1,l1,r,b,w);

        func(k2,l2,r,b,z);

    }
}
int main (){
    point r[2500],b[2500];
    int m,n;
    cin>>m;
    n=m/2;
    int k[n],l[n];
    for(int i=0;i<n;i++){
        point p;
        r[i]=p;
        cin>>r[i].x>>r[i].y;
        k[i]=i;

    }
    for(int j=0;j<n;j++){
        point p;
        b[j]=p;
        cin>>b[j].x>>b[j].y;
        l[j]=j;
    }
    func(k,l,r,b,n);
    return 0;
}




















