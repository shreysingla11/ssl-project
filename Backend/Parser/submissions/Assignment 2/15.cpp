#include<iostream>
#include<cmath>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int orientation(int fx,int fy,int sx,int sy,int tx,int ty)
{
    int val = (sy - fy) * (tx - sx) -
              (sx - fx) * (ty - sy);
    return (val > 0)? 1: 2; // clock or counterclock wise
}
bool doIntersect(int fix,int fiy,int sx,int sy,int tx,int ty,int fox,int foy)
{
    // Find the four orientations
    int o1 = orientation(fix,fiy,sx,sy,tx,ty);
    int o2 = orientation(fix,fiy,sx,sy,fox,foy);
    int o3 = orientation(tx,ty,fox,foy,fix,fiy);
    int o4 = orientation(tx,ty,fox,foy,sx,sy);
    if (o1 != o2 && o3 != o4)
        return true;
    else{return false;}
    }

int main()
{
    int n=0;
    cin>>n;
    n=n/2;
    vector<int> redx(n);
    vector<int> redy(n);
    vector<int> bluex(n);
    vector<int> bluey(n);
    vector<int> record;
    for(size_t i=0; i<redx.size(); i++)
    {
        cin>>redx[i]>>redy[i];
    }
    for(size_t i=0; i<bluex.size(); i++)
    {
        cin>>bluex[i]>>bluey[i];
    }
    for(int i=0;i<=(n-1);i+=2){
     if(i==n-1){ record.push_back(i);
     record.push_back(i);}
     else{
    if (doIntersect(redx[i],redy[i],bluex[i],bluey[i],redx[i+1],redy[i+1],bluex[i+1],bluey[i+1]))
    {
    record.push_back(i);
    record.push_back(i+1);
    record.push_back(i+1);
    record.push_back(i);

    }
    else
    {
    record.push_back(i);
    record.push_back(i);
    record.push_back(i+1);
    record.push_back(i+1);
    }}

   }

   for(int i=0;i<(2*n-1);i+=2){
   cout<<record[i]<<" "<<record[i+1]<<endl;}

}




//vector<vector<int> >red(n,vector<int>(2));
//vector<vector<int> >blue(n,vector<int>(2));



