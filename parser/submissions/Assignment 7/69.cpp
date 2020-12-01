#include <iostream>
#include <map>
#include <set>

using namespace std;

class bankAccounts{
public:
	map<string,int> balanceOf;
	map<int, set<string> > accountOf;

	bool delete_name_from_sets(string s, int x){
		map< int, set<string> > ::iterator it = accountOf.find(x) ;
		if(it != accountOf.end()){
			//Account exist
			set<string> :: iterator it2 = it->second.find(s);
			if(it2 == it->second.end()){
				// cout<<"set false: delete_name_from_sets"<<endl;
				return false;
			}
			else{
				it->second.erase(it2);
				// map< int, set<string> > ::iterator it = accountOf.find(x) ;
				if(it->second.empty()){
					accountOf.erase(it);
				}
			}
		}
		else{
			//Account doesnt exist!
			// cout<<"Account false: delete_name_from_sets"<<endl;
			return false;
		}
		return true;
	}
	bool add_name_to_sets(string s, int x){
		map< int, set<string> > ::iterator it = accountOf.find(x) ;
		if(it != accountOf.end()){
			//Account exist
			it->second.insert(s);
		}
		else{
			//Account doesnt exist!
			set<string> temp;
			temp.insert(s);
			accountOf[x] = temp;
			// cout<<"Account false: add_name_to_sets"<<endl;
			// return false;
		}
		return true;
		
	}


	bool deposit_to(string s, int m){
		map<string, int> ::iterator it = balanceOf.find(s) ;
		if(it != balanceOf.end()){
			int init_bal = it -> second;
			int final_bal = init_bal + m;
			it -> second = final_bal;
			delete_name_from_sets(s,init_bal);
			add_name_to_sets(s,final_bal);
		}
		else{
			//Account doesnt exist!
			// cout<<"Account false: deposit_to"<<endl;
			return false;
		}
		return true;
	}
	bool withdraw_from(string s, int m){
		map<string, int> ::iterator it = balanceOf.find(s) ;
		if(it != balanceOf.end()){
			int init_bal = it -> second;
			int final_bal = init_bal - m;
			if(final_bal < 0){
				// cout<<"Error: Negative Balance";
				// cout<<"Negative false: withdraw_from"<<endl;
				return false;
			}
			else{	
				it -> second = final_bal;
				delete_name_from_sets(s, init_bal);
				add_name_to_sets(s, final_bal);
			}
		}
		else{
			//Account doesnt exist!
			// cout<<"Account false: withdraw_from"<<endl;
			return false;
		}
		return true;
	}
	bool new_account(string s){
		map<string, int> ::iterator it = balanceOf.find(s) ;
		if(it != balanceOf.end()){
			//Account Already exists!
			// cout<<"Account false: new_account"<<endl;
			return false;
		}
		else{
			//Account doesnt exist
			balanceOf[s] = 0;
			add_name_to_sets(s, 0);
		}
		return true;
	}
	bool close_account(string s){
		map<string, int> ::iterator it = balanceOf.find(s) ;
		if(it != balanceOf.end()){
			//Account exists
			if(it -> second != 0){
				//account not empty
			// cout<<"!empty false: new_account"<<endl;
				return false;
			}
			balanceOf.erase(it);
			delete_name_from_sets(s, 0);
		}
		else{
			//Account doesnt exist!!
			// cout<<"Account false: close_account"<<endl;
			return false;
		}
		return true;
	}
	void print_range(int low, int high){
		map< int, set<string> > :: iterator it_low = accountOf.lower_bound(low);
		map< int, set<string> > :: iterator it_high = accountOf.upper_bound(high);

		for(;it_low != it_high; it_low++){

			cout<< it_low ->first; 
			set<string>::iterator small_it = it_low->second.begin();

			for(;small_it != (it_low->second).end();small_it++){
				cout<<" "<<*small_it;
			}
			cout<<endl;
		}

	}
	bankAccounts(){}

};
int main(){
	bankAccounts SBI;
	int count = 0;

	// string str;
	char command;
	while(true){
		// char cmd;
		cin>>command;
		string name;
		int value;
		switch(command){

			case 'O': 
				// name = str(1,std::npos);
				cin>> name;
				if( !SBI.new_account(name) ){
					count++;
					// cout<<"Count increased!"<<endl;
				}
				break;

			case 'C':
				// name = str(1,std::npos);
				cin>> name;
				if( !SBI.close_account(name) ){
					count++;
					// cout<<"Count increased!"<<endl;
				}
				break;

			case 'D':
				cin>> name;
				cin>> value;
				if( !SBI.deposit_to(name,value) ){
					count++;
					// cout<<"Count increased!"<<endl;
				}
				break;

			case 'W':
				cin>> name;
				cin>> value;
				if( !SBI.withdraw_from(name,value) ){
					count++;
					// cout<<"Count increased!"<<endl;
				}
				break;

			case 'P':
				int value1,value2;
				cin>> value1;
				cin>> value2;
				SBI.print_range(value1,value2);
				break;

			case 'E':
				cout<<count<<endl;
				return 0;

			default: return -1;
		}
	}
}
