#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

class cord{public:int x,y,index;};

void func(vector<cord> vred,vector<cord> vblue);
int main()
    {
     int n;
     //int temp1,temp2;
     cord t;
     cin>>n;
     vector<cord> vred;
     vector<cord> vblue;

     for(int i=0;i<(n/2);i++)
        {
         scanf("%d %d",&t.x,&t.y);
         t.index=i;

         vred.push_back(t);
        }
     for(int i=0;i<(n/2);i++)
        {
         scanf("%d %d",&t.x,&t.y);
        t.index=i;
         vblue.push_back(t);
        }
   /*for(int count=0;count<n/2;count++)
     {cout<<vred[count].x<<" "<<vred[count].y<<" "<<vred[count].index<<"\n";}
     for(int count=0;count<n/2;count++)
     {cout<<vblue[count].x<<" "<<vblue[count].y<<" "<<vblue[count].index<<"\n";}
*/
     func(vred,vblue);
    }

void func(vector<cord> vred,vector<cord> vblue)
    {
     vector<cord> vredl;
     vector<cord> vbluel;
     vector<cord> vredr;
     vector<cord> vbluer;
     vredl.clear();
     vredr.clear();
     vbluel.clear();
     vbluer.clear();
     int c1,c2;
     //vector<int> temp1r,temp2r,temp1b,temp2b;

     if(vred.empty()){return;}
     if(vred.size()==1){cout<<vred[0].index<<" "<<vblue[0].index<<"\n";return;}
     else
        {for(int i=0;i<vblue.size();i++)
        {
         c1=0;
             vbluel.clear();
             vbluer.clear();
             c2=0;
             vredl.clear();
             vredr.clear();
         for(int j=0;j<vblue.size();j++)
            {

             //temp1b.clear();
             //temp2b.clear();
             if(i==j){continue;}
             else if(((vblue[j].y-vblue[i].y)*(vblue[i].x-vred[0].x)-(vblue[i].y-vred[0].y)*(vblue[j].x-vblue[i].x))<0)
                {
                 c1++;
                 //cout<<c1;
                 vbluel.push_back(vblue[j]);
                }
             else {vbluer.push_back(vblue[j]);}
            }

         for(int j=1;j<vred.size();j++)
            {

             //temp1r.clear();
             //temp2r.clear();
             if(((vred[j].y-vblue[i].y)*(vblue[i].x-vred[0].x)-(vblue[i].y-vred[0].y)*(vred[j].x-vblue[i].x))<0)
                {
                 c2++;
                 //cout<<c2;
                 vredl.push_back(vred[j]);
                }
             else {vredr.push_back(vred[j]);}
            }

         if(c1==c2)
            {
             cout<<vred[0].index<<" "<<vblue[i].index<<"\n";
             /*for(int k=0;k<temp1r.size();k++)
                {
                 vredl.push_back(vred[temp1r[k]]);
                 vbluel.push_back(vblue[temp1b[k]]);
                }
             for(int k=0;k<temp2r.size();k++)
                {
                 vredr.push_back(vred[temp2r[k]]);
                 vbluer.push_back(vblue[temp2b[k]]);
                }*/
             i=i+1;
             break;
            }
        }

     func(vredr,vbluer);
     func(vredl,vbluel);
     return;
    }}
