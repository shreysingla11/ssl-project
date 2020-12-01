#include <iostream>
#include <vector>
using namespace std;

class point{
    public :
        point (int a,int b,int c){x=a; y=b;pointsto=c;}
        int x;
        int y;
        int pointsto;
        void print(){cout<< x << " "<< y <<" " << "points to" <<pointsto<<endl;}

};
class pairs{public : int first,second;};
float slope(point point1,point point2){return (point1.y-point2.y)*(1.0)/(point1.x-point2.x);}

bool intersect(point blue1, point red1,point blue2,  point red2){
    //if(slope(blue1,red1)==slope(blue2,red2)){return false;}
    float det1,det2,det3,det4;
    det1= red2.y-red1.y-(slope(blue1, red1)*(red2.x-red1.x));//corresponding to line joining (r1-b1)
    det2= blue2.y-red1.y-(slope(blue1, red1)*(blue2.x-red1.x));//corresponding to line joining (r1-b1)
    det3= red1.y-red2.y-(slope(blue2, red2)*(red1.x-red2.x)); //corresponding to line joining (r2-b2)
    det4= blue1.y-red2.y-(slope(blue2, red2)*(blue1.x-red2.x)); //corresponding to line joining (r2-b2)
    if(  ((det1>0 && det2>0) || (det1<0 && det2<0))  &&  ((det3>0 && det4>0) || (det3<0 && det4<0))  ){return false;}
    else {return true;}
}

bool conf(vector<point>&r,vector<point>&b){
    int i=0,j=0;
    while(i<r.size()/2){
        while(j<r.size()/2){
            if(intersect(r[i],b[(r[i]).pointsto],r[j],b[(r[j]).pointsto])){

            return false;}
            j++;
        }
        i++;
    }
    return true;
}

pairs config(vector<point>&r,vector<point>b){
    pairs p;

    int i=0,j=0;
    while(i<r.size()/2){
        while(j<r.size()/2){
            if(intersect(r[i],b[(r[i]).pointsto],r[j],b[(r[j]).pointsto])){
                    p.first=i;
                    p.second=j;
            return p;}
            j++;
        }
        i++;
    }
}

int main() {

//point point1(0,0);
//point point2(4,5);
//point point3(5,4);
//point point4(0,3);
//cout<< intersect(point2, point1, point4,point3);

//bool inst =1;


    vector<point> blue;
    vector<point> red;

    int N;
    int x,y;
    cin>>N;
    for (int i =0;i<(N/2);i++){
        cin>> x>>y;
        point r(x,y,i);
        red.push_back(r);
    }

    for (int j=0; j<N/2; j++){
        cin>>x>>y;
        point b(x,y,j);
        blue.push_back(b);
    }

int temp,temp1,temp2,temp3;
pairs p;
int p1,p2;
//intersect(red[k],blue[red[k].pointsto],red[l],blue[red[l].pointsto]);
while(!conf(red,blue)){
p=config(red,blue);
p1=p.first;
p2=p.second;
temp=(red[p1]).pointsto;
(red[p1]).pointsto=(red[p2]).pointsto;
(red[p2]).pointsto=temp;
}


for(int s=0;s<N/2;s++){cout<<s<<red[s].pointsto<<endl;}
return 0;}
