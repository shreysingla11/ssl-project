#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;
int main(){
int n=1,w=1,u=1,v=1,t1=0,t2=0,t=t1;
char dir;
scanf("%d %d %d %d %d %d",&n,&w,&u,&v,&t1,&t2);
int m[n];

for(int i=0;i<n;i++){

cin>>dir;
    if(dir=='E' || dir=='W'){
        cin>>m[i];
        int l[n][m[i]],p[n][m[i]];
        for(int j=0;j<m[i];j++){
            scanf("%d %d",&l[i][j],&p[i][j]);
            //p[j]=p[j]+(u*t1);
            //cout<<n<<w<<u<<v<<endl;
        }
    }
    else{
        cout<<"Invalid input format!"<<endl;
    }
}

float ti[n];
for(int i=0;i<n;i++){
    int l[n][m[i]],p[n][m[i]];
    for(int j=0;j<m[i];j++){
        ti[i]=(l[i][j]+abs(p[i][j]))/u;
    }
}

while(t>=t1 && t<=t2){
    for(int i=0;i<n;i++){
        int l[n][m[i]],p[n][m[i]];
        if(dir=='E'){
            for(int j=0;j<m[i];j++){
                p[i][j]=p[i][j]+(u*t);
            }
        }
        else if(dir=='W'){
            for(int j=0;j<m[i];j++){
                p[i][j]=p[i][j]-(u*t);
            }
        }
        t=t+(w/v);
    }
}
return 0;
}
