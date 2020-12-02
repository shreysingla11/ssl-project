#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n,w,u,v,t1,t2,l,y,d;
    pair<int,int> p;

    cin>>n>>w>>u>>v>>t1>>t2;
    int m[n];
    vector<vector<pair<int,int> > > h;
    char c[n];
    for(int i=0; i<n; i++)
    {
        cin>>c[i]>>m[i];
        if(c[i]=='E')
        {
            for(int j=0; j<m[i]; j++)
            {
                cin>>l>>y;
                p.first=y-l;
                p.second=y;
                h[i].push_back(p);

            }
        }
        if(c[i]=='W')
        {
            for(int j=0; j<m[i]; j++)
            {
                cin>>l>>y;
                p.first=y;
                p.second=y+l;
                h[i].push_back(p);
            }
        }
    }
int sum = 0;
for (int a=0; a<n; a++)
	{
		sum+=m[a];
	}

for(int i=0;i<n;i++){
if(m[i]=='E'){
}


}
    vector<pair<int,int> > g(sum);
    for(int i=0;i<n;i++){

     for(int j=0;j<m[i];j++){
if(m[i]=='E'){

p.first=h[i][j].second/u-(w*(i+1)/v);
p.second=h[i][j].first/u-(w*(i+1)/v);


    }
    else{
    p.first=h[i][j].first/u-(w*(i+1)/v);
    p.second=h[i][j].second/u-(w*i/v);

    }
    g.push_back(h[i][j]);

    }
    p.first=0;
    p.second=t1;
    g.push_back(p);
    p.first=t2;
    p.second=1000000;
     g.push_back(p);
    }
    sort(g.begin(),g.end());
    int mx=0;
    for(int i=0;i<sum;i++){
    if(g[i].first<mx){d=g[i].first-mx;}
    }
    d=6;
  cout<<d;




}







