#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
using namespace std;

int main(){

  vector<vector<int> > G;
  vector<int> t;//threshold
  vector<int> p;//possible going friends
  vector<int> g;//going friends
  vector<int> qsta;//0-> not been to Q, 1-> been to Q , 2-> present in Q
  vector<int> sta;//0->dont know, 1->going , 2-> not going
  //vector<int> nofn;//no of friends
  int going=0, notgoing=0;
  int n,a,b,temp,k;
  //cin>>n;
  scanf("%d",&n);//no of nodes
  G.resize(n);
  t.resize(n);p.resize(n);g.resize(n);qsta.resize(n);sta.resize(n);
  for(int i=0;i<n;i++){
    //cin>>t[i];
    scanf("%d",&temp);
    t[i]=temp;
    int tmp;
    //cin>>tmp;
    scanf("%d",&tmp);
    p[i]=tmp;
    for(int j=0;j<tmp;j++){
      //cin>>b;
      scanf("%d",&b);
      G[b].push_back(i);
    }
    qsta[i]=0;
    sta[i]=0;
  }
  for(int i=0;i<n;i++){
    g[i]=0;
  }

  queue<int> Q;
  for(int i=0;i<n;i++){
    if(t[i]<=0){
      sta[i]=1;
      qsta[i]=2;
      Q.push(i);
      //cout<<i<<" going"<<endl;
    }
    else{
      if(p[i]<t[i]){
        sta[i]=2;
        qsta[i]=2;
        Q.push(i);
        //cout<<i<<" not going"<<endl;
      }
    }
  }

  int num,tar;
  while(!Q.empty()){
    num=Q.front();
    if(sta[num]==1){
      k=G[num].size();
      for(int i=0;i<k;i++){
        g[G[num][i]]++;
        if(g[G[num][i]]>=t[G[num][i]]&&qsta[G[num][i]]==0){
          sta[G[num][i]]=1;
          qsta[G[num][i]]=2;
          Q.push(G[num][i]);
        }
      }
      Q.pop();
      qsta[num]=1;
      going++;
    }
    else{
      k=G[num].size();
      for(int i=0;i<k;i++){
        p[G[num][i]]--;
        if(p[G[num][i]]<t[G[num][i]]&&qsta[G[num][i]]==0){
          sta[G[num][i]]=2;
          qsta[G[num][i]]=2;
          Q.push(G[num][i]);
        }
      }
      Q.pop();
      qsta[num]=1;
      notgoing++;
    }
  }

  //cout<<going<<" "<<n-notgoing<<endl;
  int res=n-notgoing;
  printf("%d %d \n",going,res);

  return 0;
}
