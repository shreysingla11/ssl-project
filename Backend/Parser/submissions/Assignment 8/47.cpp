#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;

struct se{
	double tim;
	bool f=true;
};
bool compare(se c,se d){
    if(c.tim==d.tim){
        if(c.f==true)
            return c.tim<d.tim;
        else
            return c.tim>d.tim;
    }
    return c.tim<d.tim;

}
int main(int argc, char const *argv[])
{
	double n,w,u,v,t1,t2,off=0,l,p,m;
	se x,y;
	vector<se> startend;
	cin>>n>>w>>v>>u>>t1>>t2;
	for (int i = 1; i <= n; ++i)
	{
		char d;
		cin>>d;
		if(d=='E'){
			cin>>m;
			for (int i = 1; i <= m; ++i)
			{
				cin>>l>>p;
				p=-p;
			x.tim=((p/v)-(w/u)-off);
			y.tim=(((p+l)/v)-off);
			y.f=false;
			if(x.tim>t2||y.tim<t1){
                continue;
			}
			if(x.tim<t1){
                x.tim=t1;

			}
			if(y.tim>t2){
                y.tim=t2;

			}
			startend.push_back(x);
            startend.push_back(y);
            }
		}
		else{
			cin>>m;
			for (int i = 1; i <= m; ++i)
			{
                cin>>l>>p;
			x.tim=((p/v)-(w/u)-off);
			y.tim=(((p+l)/v)-off);
			y.f=false;
			if(x.tim>t2||y.tim<t1){
                continue;
			}
			if(x.tim<t1){
                x.tim=t1;

			}
			if(y.tim>t2){
                y.tim=t2;

			}

			startend.push_back(x);
            startend.push_back(y);
            }
		}
		off=off+(w/u);
	}
	sort(startend.begin(),startend.end(),compare);
	int counts=0;double maxi=0;double temp;
	maxi=startend[0].tim-t1;
	for(int i=0;i<startend.size()-1;i++){
        if(startend[i].f==true){
            counts++;
        }
        else
        counts--;
        if(counts ==0)
        {
            temp=startend[i+1].tim-startend[i].tim;
            if(temp>maxi)
            maxi=temp;
        }
	}
	if(t2-startend[startend.size()-1].tim>maxi){
        maxi=t2-startend[startend.size()-1].tim;
	}
	printf("%.8f",maxi);
	cout<<endl;

	return 0;
}
