#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<utility>

using namespace std;

class distinct{
    public:
//    int ans=0;
    /*struct node{
        vector<int> a1;
        vector<int> a2;
        node* next;
    };*/
  //node* start=new node();
//  node* faltu=new node();
  /*struct mem{
    int a,indexs,indexl;
   };*/
    vector<int> l;
    vector<int> sub;
    vector<pair <int,int> > vec;
//    map<int,mem> ma;
  //  map<int,mem>::iterator mait;
    int siz;
    int temp,level,big,small;


    distinct(vector<int> &v)
        {
         siz=v.size();
         for (int i=0;i<siz;i++)
            {
             vec.push_back(make_pair(v[i],i));
            }
        //cout<<7<<"\n";
         sort(vec.begin(),vec.end());

         l.resize(siz);
         l[vec[0].second]=-1;
         for (int i=1;i<siz;i++)
            {
             //cout<<5<<"\n";
             if(vec[i].first==vec[i-1].first){l[vec[i].second]=vec[i-1].second;}
             else {l[vec[i].second]=-1;}
            }
            //cout<<2<<"\n";

        /* temp=0;
         big=-1;
         small=-1;
         //cout<<1<<"\n";
         for (int i=0;i<siz;i++)
            {
             if(l[i]>=(siz/2)){temp++;start->a2.push_back(small);big=i;}
             else{start->a2.push_back(big);small=i;}
             start->a1.push_back(temp);
            }
         //cout<<2<<"\n";
         start->next=create(2);
*/
        }


    /*node * create(int i)
        {
         ma.clear();
         node *here=new node();
         //cout<<1<<"\n";
         if (pow(2,i)>siz){return NULL;}
         //int x=n/(pow(2,i-1));
         int k;
         for(int j=0;j<siz;j++)
            {
             k=l[j]*pow(2,i-1)/siz;
             //cout<<3<<"\n";
             mait=ma.find(k);
             //cout<<7<<"\n";
             if(mait!=ma.end())
                {
                 if(l[j]>=(k*siz/pow(2,i-1))+(siz/pow(2,i))){here->a2.push_back(mait->second.indexs);mait->second.a++;mait->second.indexl=j;}
                 else{here->a2.push_back(mait->second.indexl);mait->second.indexs=j;}
                 here->a1.push_back(mait->second.a);
                 //cout<<6<<"\n";
                }

            else
                {
                 ma[k].a=0;
                 ma[k].indexl=-1;
                 ma[k].indexs=-1;
                 //cout<<9<<"\n";
                 if(l[j]>=(k*siz/pow(2,i-1))+(siz/pow(2,i))){here->a2.push_back(ma[k].indexs);ma[k].a++;ma[k].indexl=j;}
                 else{here->a2.push_back(ma[k].indexl);ma[k].indexs=j;}
                 //cout<<8<<"\n";
                 int tmp=ma[k].a;
                 //cout<<5<<"\n";
                 here->a1.push_back(tmp);

                 //cout<<7<<"\n";
                }
           //     cout<<5<<"\n";
            }
         here->next=create(i+1);
         return here;

        }*/

    int num_distinct(int beg,int end)
        {
         int count=0;
         for (int i=beg;i<=end;i++)
            {
             if(l[i]>=beg){count++;}
            }
         int ans=end+1-beg-count;
         //cout<<ans<<"\n";
         return ans;

         /*ans=0;
         int mid,st,en,level;
         mid=siz/2;
         faltu=start;
         if(beg<mid)
            {
             ans=ans+faltu->a1[end];
             if(end<mid)
                {
                 num(beg,end,faltu->next,mid/2);
                }
             else
                {
                 num(beg,faltu->a2[end],faltu->next,mid/2);
                }
           }
         else
            {
             num(beg,faltu->a2[end],faltu->next,3*mid/2);
            }
         return end+1-beg-ans;*/

        }
  /*void num(int beg,int end,node *faltu,int mid)
    {
     if(end==-1){return ;}
     if(faltu->next==NULL){if(beg<mid){ans=ans+faltu->a1[end];}return ;}
     if(beg<mid)
            {
             ans=ans+faltu->a1[end];
             if(end<mid)
                {
                 num(beg,end,faltu->next,mid/2);
                }
             else
                {
                 num(beg,faltu->a2[end],faltu->next,mid/2);
                }
           }
         else
            {
             num(beg,faltu->a2[end],faltu->next,3*mid/2);
            }
    }*/


};


