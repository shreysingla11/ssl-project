#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

int main(){
	map<string,int>:: iterator it;
	map<int,set<string> >:: iterator sal;
	map<string,int> alpha;
	set<string> acc_name;
	set<string> tempo;
	set<string>:: iterator rat;
	map<int,set<string> > beta;
	int count=0;
	string s =" ";
	string s1;
	int s2;
	int min=0; int max=0;
	while(s[0]!='E'){
			count++;
			cin >> s;
			if((s[0]!='E')&&(s[0]!='P'))
			cin >> s1;
			if(s[0]=='P')
			cin >> min;
			if((s[0]=='D')||(s[0]=='W')||(s[0]=='P')){ 
				//cout<<"D/W/P"<<endl;
				cin >> s2;
				}
			if((s[0]=='O')&&(acc_name.find(s1)==acc_name.end()) ){
				acc_name.insert(s1);
				alpha[s1]=0;
				if(beta.find(0)==beta.end()){
					tempo.insert(s1);
					beta[0]=tempo;
					tempo.erase(tempo.begin(),tempo.end());
				}
				else{
					tempo=beta[0];
					tempo.insert(s1);
					beta[0]=tempo;
					tempo.erase(tempo.begin(),tempo.end());
					}
					
				count--;
				
				//cout<<"New element added"<<endl;
				}
			if((s[0]=='D')&&(acc_name.find(s1)!=acc_name.end())){
				alpha[s1]=alpha[s1]+s2;
				//cout<<"amount added"<<endl;
				tempo=beta[alpha[s1]];
				tempo.insert(s1);
				beta[alpha[s1]]=tempo;
				tempo.erase(tempo.begin(),tempo.end());
				
				tempo=beta[alpha[s1]-s2];
				tempo.erase(s1);
				beta[alpha[s1]-s2]=tempo;
				tempo.erase(tempo.begin(),tempo.end());
				count--;
				}
			if((s[0]=='W')&&(alpha[s1]>=s2)&&(acc_name.find(s1)!=acc_name.end())){
				alpha[s1]=alpha[s1]-s2;
				//cout<<"amount withdrawn"<<endl;
				tempo=beta[alpha[s1]];
				tempo.insert(s1);
				beta[alpha[s1]]=tempo;
				tempo.erase(tempo.begin(),tempo.end());
				
				tempo=beta[alpha[s1]+s2];
				tempo.erase(s1);
				beta[alpha[s1]+s2]=tempo;
				tempo.erase(tempo.begin(),tempo.end());
				count--;
				
				}
			if((s[0]=='C')&&(acc_name.find(s1)!=acc_name.end())&&(alpha[s1]==0)){
				acc_name.erase(s1);
				alpha.erase(s1);
				
					tempo=beta[0];
					tempo.erase(s1);
					beta[0]=tempo;
					tempo.erase(tempo.begin(),tempo.end());
				
				count--;
				
				
				//cout<<"closed"<<endl;
				}
				if(s[0]=='P'){
					max=s2;
					count--;
					}
		}
	 
	 //for(it=alpha.begin();it!=alpha.end();it++){
		//	cout<< it->first << "  " << it->second <<endl;
		//}
		
		
	for(sal=beta.begin();sal!=beta.end();sal++){
			if(((sal->first) <= max)&&((sal->first)>=min)&&(!((sal->second).empty()))){
			cout<< sal->first << "  " ;
			for(rat=(sal->second).begin(); rat!=(sal->second).end();rat++ ){
				cout<<" "<< *rat;
				}
				cout<<endl;}
		}
	
	//cin>>s; cin>>s1;cin>>s2; cin>>s3;cin>>s4; cin>>s5; 
	//cout<<s<<s1<<s2<<s3<<s4<<s5;
cout<<count-1<<endl; //case of E is ignored
}
