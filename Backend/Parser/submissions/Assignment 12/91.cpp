#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

class node{
    public:
    int t,n;
    //vector<int> a;
    vector<int> b;
    int flag,fg;
    };
int main()
    {
     //cout<<1<<"\n";
     int con;
     scanf("%d",&con);
     vector<node> fri(con);
     //cout<<2<<"\n";
     int temp;
     int min=0;
     int max=0;
     for (int i=0;i<con;i++)
        {
         scanf("%d %d",&fri[i].t,&fri[i].n);
         fri[i].flag=0;
         fri[i].fg=0;
         for(int j=0;j<fri[i].n;j++)
            {
             scanf("%d",&temp);
             //fri[i].a.push_back(temp);
             fri[temp].b.push_back(i);
            }
        }
     //cout<<1<<"\n";
     vector<int> going;
     vector<int> notgoing;
     for (int i=0;i<con;i++)
        {
         if (fri[i].t==0){going.push_back(i);fri[i].flag=1;}
         else if (fri[i].t>fri[i].n){notgoing.push_back(i);fri[i].flag=2;}
        }
     //cout<<1<<"\n";
     int siz1,siz2;
     min=going.size();
     while(!going.empty())
        {
         siz1=going.size();
         temp=going[siz1-1];
         going.pop_back();
         int temp3;
         siz2=fri[temp].b.size();
         for(int i=0;i<siz2;i++)
            {
             temp3=fri[temp].b[i];
             if(fri[temp3].flag==0)
                {

                 fri[temp3].fg++;
                 if(fri[temp3].fg>=fri[temp3].t){going.push_back(temp3);fri[temp3].flag=1;min++;}
                }
            }
        }
     //cout<<1<<"\n";
     int phokat=notgoing.size();
     while(!notgoing.empty())
        {
         siz1=notgoing.size();
         temp=notgoing[siz1-1];
         notgoing.pop_back();
         //siz1--;
         int temp2;
         siz2=fri[temp].b.size();
         for(int i=0;i<siz2;i++)
            {
             temp2=fri[temp].b[i];
             if(fri[temp2].flag==0)
                {
                 fri[temp2].n--;
                 if(fri[temp2].n<fri[temp2].t){notgoing.push_back(temp2);fri[temp2].flag=2;phokat++;}
                }
            }
        }
     max=con-phokat;
     cout<<min<<" "<<max<<"\n";
    }
