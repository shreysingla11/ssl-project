#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <list>
#include <string>
#include <map>
#include <set>
#include <stack>
# define fr(i,n) for(int i=0;i<n;i++)
# define fr1(i,n) for(int i=1;i<=n;i++)

using namespace std;

class node{
public:
double x_cor;
double soe;
};

bool comp(node & a,node & b){
return a.x_cor<b.x_cor;
}

int main()
{
    /**Declarations**/
    char dir;
    double n,w,u,v,t1,t2,m,sign,l,p,ship_count,s,e,dist,d,shift;
    node curr;
    //node* pos;
    list <node> pos;
    /**Initializations**/

    //pos = new node [200000];
    cin>>n>>w>>u>>v>>t1>>t2;
    shift=(w*u)/v;
    fr(i,n){
    /**Inputing data of each lane**/
    cin>>dir>>m;
    if(dir=='W'){
    /**take equivalent case of all ships moving west**/
    /**sign is used for changing the positions**/
    sign=1;
    }
    else{
    sign=-1;
    }

    fr(j,m){
    /**Inputing the data of jth ship in ith row**/

    cin>>l>>p;
    curr.soe=1;
    curr.x_cor=(p*sign)-(i*shift);
    //pos[k++]=curr;
    pos.push_back(curr);
    curr.soe=-1;
    curr.x_cor=(p*sign)+l-(i*shift);
    pos.push_back(curr);
    //pos[k++]=curr;
    }
    }


    curr.soe=1;
    curr.x_cor=1000000;
    pos.push_back(curr);
    pos.sort(comp);
    /**sorting working **/

    /**finding the maximum distance inbetween the ships**/
    ship_count=0;
    //s=0;
    d=w/v;
    e=0;
    dist=0;
    //dist=(*pos.begin()).x_cor;
    for(list<node>::iterator it =pos.begin();it!=pos.end();it++){
    if(ship_count==0){
    s=(*it).x_cor/u;
    s-=d;
    /**verifying the bounds t1 and t2**/
    if(t2<s)s=t2;
    if(t1>e)e=t1;
    dist=max(dist,(s-e));
    }
    ship_count+=(*it).soe;
    if((*it).soe==-1){
    e=(*it).x_cor/u;
    }
    }
    //cout<<"dist= "<<dist<<endl;
    /**gap time = dist/u**/
    //gap_t=dist/u;
    //d=gap_t-d;
    printf("%0.9f",dist);
    cout<<endl;


    return 0;
}



//
//for(list<node>::iterator it =pos.begin();it!=pos.end();it++){
//    cout<<(*it).x_cor<<" ";
//    }
//    cout<<endl;
//    for(list<node>::iterator it =pos.begin();it!=pos.end();it++){
//    cout<<(*it).soe<<" ";
//    }

