#include<iostream>
#include<map>
#include<set>
#include<string>
using namespace std;
int main()
{
	char c;
	string name;
	int deposit,withdraw;
	int counts=0;
	int a,b;
	map<string,int> accbal;
	map<int, set<string> > balacc;
	map<int, set<string> >::iterator itlow,itup;
	cin>>c;
	while(true){
	switch(c){
		case 'O':cin>>name;
		if(accbal.count(name)==0){
			accbal[name]=0;
			balacc[0].insert(name);
		}
		else
			counts++;
		break;
		case 'C':
		cin>>name;
		if(accbal.count(name)>0){
		if(accbal[name]==0){
			accbal.erase(name);
			balacc[0].erase(name);
			if(balacc[0].size()==0){
                balacc.erase(0);
			}
		}
		else
			counts++;
		}
		else
			counts++;
		break;
		case 'D':
		cin>>name;
		cin>>deposit;
		if(accbal.count(name)>0){
			int temp=accbal[name];
			balacc[temp].erase(name);
			accbal[name]+=deposit;
			balacc[accbal[name]].insert(name);
			if(balacc[temp].size()==0){
                balacc.erase(temp);
            }
		}
		else
			counts++;
		break;
		case 'W':
		cin>>name;
		cin>>withdraw;
		if(accbal.count(name)>0){
			int temp=accbal[name];
			if(accbal[name]-withdraw<0)
				counts++;
			else{
				balacc[temp].erase(name);
				accbal[name]-=withdraw;
				balacc[accbal[name]].insert(name);
				if(balacc[temp].size()==0){
                balacc.erase(temp);
            }
			}

		}
		else{
			counts++;
		}
		break;
		case 'P':
		cin>>a>>b;
		itlow=balacc.lower_bound(a);
		itup=balacc.upper_bound(b);
		for(map<int, set<string> >::iterator it=itlow;it!=itup;it++){
			cout<<it->first<<" ";
			set<string> tep=it->second;
			for(set<string>::iterator its=tep.begin();its!=tep.end();its++)
				cout<<*its<<" ";
			cout<<endl;
		}
	}
	if(c=='E')
	break;
	cin>>c;
	}
	cout<<counts<<endl;
	return 0;
}
