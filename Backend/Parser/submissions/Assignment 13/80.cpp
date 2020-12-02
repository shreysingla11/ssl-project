#include<iostream>
#include<cstdio>
#include<vector>
#include<limits.h>
#include<stdlib.h>

using namespace std;

class graph{
    public:
    int good=INT_MAX;
    int d=INT_MAX;
    int ngood1=0;
    int nbad1=0;
    int ngood2=0;
    int nbad2=0;
    int parent=-9;
};

int main()
    {
     int n;
     cin>>n;
     vector<vector <int> > ad(n);
     vector<int> temp(n);
     int dis;
     for (int i=0;i<n;i++)
        {
         for (int j=0;j<n;j++)
            {
             scanf("%d",&temp[j]);
            }
         ad[i]=temp;
        }
     /*for (int i=1;i<n;i++)
        {
         for (int j=0;j<n;j++)
            {
             cout<<ad[i][j]<<" ";
            }
         cout<<"\n";
        }*/
     vector<graph> vec(n);
     vec[0].good=0;
     vec[0].d=0;
     for (int i=0;i<n;i++)
        {
         //cout<<"a"<<"\n";
         for (int j=0;j<n;j++)
            {
             //cout<<"b"<<"\n";
             for (int k=0;k<n;k++)
                {
                 //cout<<"m"<<"\n";
                 if(vec[j].d!=INT_MAX)
                    {
                     //cout<<"l"<<"\n";
                     //cout<<ad[j][k]<<"\n";
                     if(vec[k].d>vec[j].d+abs(ad[j][k]))
                        {
                         //cout<<1<<"\n";
                         vec[k].d=vec[j].d+abs(ad[j][k]);
                         vec[k].parent=j;
                         if(ad[j][k]>0){vec[k].nbad2=vec[j].nbad2+1;vec[k].ngood2=vec[j].ngood2;}
                         else if(ad[j][k]<0){vec[k].nbad2=vec[j].nbad2;vec[k].ngood2=vec[j].ngood2+1;}
                        }
                     if(vec[k].good>vec[j].d+abs(ad[j][k]))
                        {
                         if(vec[j].ngood2>=vec[j].nbad2+1 || (vec[j].ngood2>=vec[j].nbad2-1&&ad[j][k]<0))
                            {
                             vec[k].good=vec[j].d+abs(ad[j][k]);
                             //cout<<4<<"\n";
                             if(ad[j][k]>0){vec[k].nbad1=vec[j].nbad2+1;vec[k].ngood1=vec[j].ngood2;}
                             else if(ad[j][k]<0){vec[k].nbad1=vec[j].nbad2;vec[k].ngood1=vec[j].ngood2+1;}
                            }

                        }
                     else if (vec[j].good!=INT_MAX)
                     { if (vec[k].good>vec[j].good+abs(ad[j][k]))
                        {
                          if(vec[j].ngood1>=vec[j].nbad1+1 || (vec[j].ngood1>vec[j].nbad2-1&&ad[j][k]<0))
                            {
                             vec[k].good=vec[j].good+abs(ad[j][k]);
                             //cout<<7<<"\n";
                             if(ad[j][k]>0){vec[k].nbad1=vec[j].nbad1+1;vec[k].ngood1=vec[j].ngood1;}
                             else if(ad[j][k]<0){vec[k].nbad1=vec[j].nbad1;vec[k].ngood1=vec[j].ngood1+1;}
                            }
                        }}
                    }
                }
            }
        }


     for (int i=0;i<n;i++)
        {
         if (vec[i].good!=INT_MAX)
         {cout<<vec[i].good<<"\n";}
         else {cout<<"infinity";}
        }
    }
