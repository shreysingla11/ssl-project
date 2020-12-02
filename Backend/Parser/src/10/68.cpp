#include<cstdio>
#include<utility>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
class distinct
{

vector<pair <int, int> > p;
vector<int> l;
public:
 distinct(vector<int> given)
 {
    int siz = given.size();
    for(int i =0;i<siz;i++)
    {
     p.push_back(make_pair(given[i],i));



    }
     sort(p.begin(),p.end());
     l.resize(siz,-1);
     l[0]=-1;
     for(int i =1;i<siz;i++)
     {

     if(p[i].first==p[i-1].first)
        {
        l[p[i].second]=p[i-1].second;

        }
        else {
        l[p[i].second] = -1;

        }
     }



 }

int num_distinct(int i , int j)
{
int countd=0;
for( int  k = i;k<=j;k++)
{

if(l[k]>=i)countd++;
}
return j-i+1-countd;

}



};
/*
int main()
{
int n;
scanf("%d",&n);
vector<int> h(n);
for(int i = 0;i<n;i++)
{
scanf("%d",&h[i]);

}
distinct a(h);
int q;
scanf("%d",&q);
for(int i =0;i<q;i++)
{
int x , b;
scanf("%d %d",&x, &b);
a.num_distinct(x,b);

}





	return 0;
}
*/
