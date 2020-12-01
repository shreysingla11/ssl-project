#include <iostream>
#include <queue>
#include <vector>
#include <stack> 
using namespace std;

class node{
public:
int num;
int t_i;
int nof;
vector<int> a;
vector<int> pred;
bool decided;
int nofg;
int nofng;
node(){
	nofg=0;
	nofng=0;
	decided=false;
}
};



int main()
{
 int non=0;
 int min=0,max=0;int test;
 cin>>non;
 int noud=0;
 node* add[non];
 stack<int> qu;
 stack<int> que;
 for(int i=0;i<non;i++)
 {
 	add[i]=new node;
 }
 for(int i=0;i<non;i++)
 {
 	add[i]->num=i;
 	cin>>add[i]->t_i;
 	cin>>add[i]->nof;
 	for(int j=0;j<add[i]->nof;j++)
 	{
 		int r;cin>>r;
 		add[i]->a.push_back(r);
        add[r]->pred.push_back(i);
 	}
 	if(add[i]->t_i==0){qu.push(i);add[i]->decided=true;}
 	else if(add[i]->t_i > add[i]->nof){que.push(i);add[i]->decided=true;}
 	else{noud++;}
 }

 while(!qu.empty() || !que.empty())
 {
 	if(!qu.empty())
 	{
 	test=qu.top();
 	qu.pop();
 	min++;max++;
 	for(int i=0;i<(add[test]->pred).size();i++)
 	{
 		int pre=(add[test]->pred)[i];
 		if(!add[pre]->decided)
 		{
 		 add[pre]->nofg++;
 		 if(add[pre]->t_i <= add[pre]->nofg){qu.push(pre);add[pre]->decided=true;noud--;}
 		}
 	}
 	}
 	if(!que.empty())
 	{
 		test=que.top();
 		que.pop();
 		for(int i=0;i<(add[test]->pred).size();i++)
 	{
 		int pre=(add[test]->pred)[i];
 		if(!add[pre]->decided)
 		{
 		 add[pre]->nofng++;
 		 if((add[pre]->t_i) >((add[pre]->nof)-(add[pre]->nofng))){que.push(pre);add[pre]->decided=true;noud--;}
 		}
 	}
 	}
 

 }
 max=max+noud;
 cout<<min<<" "<<max<<endl;


}