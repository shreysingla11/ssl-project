#include<iostream>
#include<cstdio>
#include<vector>
#include<limits.h>
#include<stdlib.h>

using namespace std;

struct node{
    int good=INT_MAX;
    int d=INT_MAX;
    int good1, bad1,good2,bad2;
    node(){
    good1=0;
    bad1=0;
    good2=0;
    bad2=0;
    }
};

int main()
    {
     int n;
     cin>>n;
     vector<vector <int> > edge(n);
     vector<int> temp(n);
     int dis;
     for (int i=0;i<n;i++)
        {
         for (int j=0;j<n;j++)
            {
             scanf("%d",&temp[j]);
            }
         edge[i]=temp;
        }
     for (int i=1;i<n;i++)
        {
         for (int j=0;j<n;j++)
            {
             cout<<edge[i][j]<<" ";
            }
         cout<<"\n";
        }
     vector<node> mynode(n);
     mynode[0].good=0;
     mynode[0].d=0;
     for (int i=0;i<n;i++)
        {
         //cout<<"a"<<"\n";
         for (int j=0;j<n;j++)
            {
             //cout<<"b"<<"\n";
             for (int k=0;k<n;k++)
                {
                 //cout<<"m"<<"\n";
                 if(mynode[j].d!=INT_MAX)
                    {
                     cout<<"l"<<"\n";
                     cout<<edge[j][k]<<"\n";
                     if(mynode[k].d>mynode[j].d+abs(edge[j][k]))
                        {
                         cout<<1<<"\n";
                         mynode[k].d=mynode[j].d+abs(edge[j][k]);
                         if(edge[j][k]>0){mynode[k].bad2=mynode[j].bad2+1;mynode[k].good2=mynode[j].good2;cout<<2<<"\n";}
                         else if(edge[j][k]<0){mynode[k].bad2=mynode[j].bad2;mynode[k].good2=mynode[j].good2+1;cout<<3<<"\n";}
                        }
                     if(mynode[k].good>mynode[j].d+abs(edge[j][k]))
                        {
                         if(mynode[j].good2>=mynode[j].bad2+1 || (mynode[j].good2>=mynode[j].bad2-1&&edge[j][k]<0))
                            {
                             mynode[k].good=mynode[j].d+abs(edge[j][k]);
                             cout<<4<<"\n";
                             if(edge[j][k]>0){mynode[k].bad1=mynode[j].bad2+1;mynode[k].good1=mynode[j].good2;cout<<5<<"\n";}
                             else if(edge[j][k]<0){mynode[k].bad1=mynode[j].bad2;mynode[k].good1=mynode[j].good2+1;cout<<6<<"\n";}
                            }

                        }
                     else if (mynode[j].good!=INT_MAX)
                     { if (mynode[k].good>mynode[j].good+abs(edge[j][k]))
                        {
                          if(mynode[j].good1>=mynode[j].bad1+1 || (mynode[j].good1>mynode[j].bad2-1&&edge[j][k]<0))
                            {
                             mynode[k].good=mynode[j].good+abs(edge[j][k]);
                             cout<<7<<"\n";
                             if(edge[j][k]>0){mynode[k].bad1=mynode[j].bad1+1;mynode[k].good1=mynode[j].good1;cout<<8<<"\n";}
                             else if(edge[j][k]<0){mynode[k].bad1=mynode[j].bad1;mynode[k].good1=mynode[j].good1+1;cout<<9<<"\n";}
                            }
                        }}
                    }
                }
            }
        }
     for (int i=0;i<n;i++)
        {
         cout<<mynode[i].good<<"\n";
        }
    }
