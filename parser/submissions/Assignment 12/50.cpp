#include<iostream>
#include<vector>
#include<stdio.h>
#include<queue>
#include<list>
using namespace std;
int going;
int notgoing;
struct vertices{
public:
	int t;
	int ns;
	int pos;
	vertices(){}
	vertices(int ti,int ni){
		t=ti;
		ns=ni;
		if(t==0){
			pos=1;
			going++;
		}
		else if(t>ns){
			pos=-1;
			notgoing++;
		}
		else
			pos=0;
	}
};

 vector<vertices> all;
 queue<int> suregoing;
 queue<int> surenotgoing;
 vector<vector<int> > pre;
int main(int argc, char const *argv[]){
	int n,a,b,c;
	scanf("%d",&n);
	all.resize(n);
	pre.resize(n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&a);
		scanf("%d",&b);
		 all[i]= vertices(a,b);
		if(all[i].pos==1)
			suregoing.push(i);
		else if(all[i].pos==-1)
			surenotgoing.push(i);
		for (int j = 0; j < b; ++j)
		{
			scanf("%d",&c);
			pre[c].push_back(i);
		}
	}
	while(!suregoing.empty()){

        int n=suregoing.front();
        for(int i=0;i<pre[n].size();i++){
            if(all[pre[n][i]].pos==0){
                all[pre[n][i]].ns--;
                all[pre[n][i]].t--;
                if(all[pre[n][i]].t==0){
                    all[pre[n][i]].pos=1;
                    suregoing.push(pre[n][i]);
                    going++;
                }
            }
        }
        suregoing.pop();
	}
	while(!surenotgoing.empty()){
		int n=surenotgoing.front();
		for(int i=0;i<pre[n].size();i++){
            if(all[pre[n][i]].pos!=0)
                continue;
            all[pre[n][i]].ns--;
            if(all[pre[n][i]].t>all[pre[n][i]].ns){
                all[pre[n][i]].pos=-1;
                surenotgoing.push(pre[n][i]);
                notgoing++;
            }


		}
		surenotgoing.pop();
	}

	notgoing=n-notgoing;
	printf("%d %d\n" ,going,notgoing);
}
