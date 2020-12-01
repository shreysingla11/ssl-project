#include<iostream>
#include<algorithm>
#include<map>
#include<fstream>
#include<vector>
using namespace std;

struct kapil
{
    int x,y;

};

bool myfunc(kapil a,kapil b)
{
    if(a.x==b.x)
    {
        return a.y<b.y;
    }
    else
    {
        return a.x<b.x;
    }

}



class distinct
{
public:
    vector<int> seq;
    vector<int> l;
    vector<vector<int> > mainarr;



    void build(int pow,vector<int> &a,vector<int> &b,vector<int> &l)
    {
        int fact;
        pow=pow*2;
        fact=l.size()/pow;
        vector<int> temp(pow),temp1(pow);
        int i,s=l.size(),k;
        for(i=0; i<pow; i++)
        {
            temp[i]=0;
            temp1[i]=-1;
        }
        for(i=0; i<s; i++)
        {
            if(l[i]==-1)
            {
                a[i]=0;
                b[i]=-1;
                continue;
            }

            k=l[i]/fact;

            k=k/2;
            a[i]=temp[2*k+1];
            if((l[i]/fact)%2==1)
            {
                a[i]++;
                b[i]=temp1[2*k];

            }
            else
            {
            b[i]=temp1[2*k+1];
            }
            k=l[i]/fact;
          // cout<<k<<endl;
            temp[k]++;
            temp1[k]=i;
           // cout<<temp[0]<<temp[1]<<temp[2]<<temp[3]<<endl;
           // cout<<temp1[0]<<temp1[1]<<temp1[2]<<temp1[3]<<endl;

        }


        for(i=0; i<s; i++)
        {
          //  cout<<a[i]<<" "<<b[i]<<endl;
        }

        return ;
    }


    distinct(vector<int> se)
    {

        vector<kapil> a(se.size());
        int i,s=se.size();
        for(i=0; i<s; i++)
        {
            seq.push_back(se[i]);
            a[i].x=seq[i];
            a[i].y=i;
        }
        sort(a.begin(),a.end(),myfunc);

        l.resize(s);
        l[0]=-1;
        for(i=1; i<s; i++)
        {
            if(a[i].x==a[i-1].x)
            {
                l[a[i].y]=a[i-1].y;
            }
            else
            {
                l[a[i].y]=-1;
            }

        }

        for(i=0; i<s; i++)
        {
           // cout<<l[i]<<" "<<l[i]<<endl;
        }

        vector<int> x(s),y(s);
        i=1;int j,h=0;
        for(i=1;i<s;)
        {
        build(i,x,y,l);
        mainarr.resize(h+2);
    for(j=0;j<s;j++)
       {
       mainarr[h].push_back(x[j]);
    mainarr[h+1].push_back(y[j]);
   //  cout<<x[j]<<" "<<y[j]<<" ";
       }
        //cout<<endl;
       h=h+2;
        i=2*i;
        }


    }




   int num_distinct(int i,int j)
   {
   int i1,count=0;
   for(i1=i;i1<=j;i1++)
   {
   if(l[i1]<i)
   {
   count++;
   }
}
   return count;



   }

};


