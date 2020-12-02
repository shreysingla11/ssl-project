#include <iostream>
#include <set>
#include <map>
#include <string>
#include <utility>

using namespace std;

int main()
{
	map<string,int> acc;          //  account name -> current bal
	map<int, set<string> > bal;   //  balance -> set of names
	
	map<string, int>::iterator acc_it;
	map<int, set<string> >::iterator bal_it;
	set<string>::iterator it;     

	char op;
	int tmp,tmp2;
	int esc = 0;
	int invalid = 0;
	string name;
	int inp1, inp2;
	set<string> tmp_set, tmp_set2;
	pair <int, set<string> > tmp_pair;
	
	
	while(1)
	{
		cin>>op;
		switch(op)
		{
			case 'O' :       // open account
			cin>>name;
			acc_it = acc.find(name);
			if( acc_it == acc.end() )
			{
				acc[name]=0;	
				
				bal_it = bal.find(0);
				if( bal_it == bal.end() )
				{
					tmp_set.clear();
					tmp_set.insert(name);
					tmp_pair = make_pair (0, tmp_set);
					bal.insert(tmp_pair);	
				}
				else
				{
					tmp_set.clear();
					tmp_set = bal_it->second;
					tmp_set.insert(name);
					tmp_pair = make_pair (0, tmp_set);
					bal.erase(bal_it);
					bal.insert(tmp_pair);
						
				}
			}
			else invalid++;
			
			break;
			
			case 'D' :      // deposit
			cin>>name;
			cin>>inp1;
			acc_it = acc.find(name);
			if( acc_it == acc.end() )
			{
				invalid++;	
			}
			else
			{
				tmp = acc_it->second + inp1;
				tmp2 = acc_it->second;
				
				acc.erase (acc_it);
				acc[name]=tmp;
				
				bal_it = bal.find(tmp2);
				tmp_set.clear();
				tmp_set = bal_it->second;
				tmp_set.erase(name);
				tmp_pair = make_pair(tmp2, tmp_set);
				bal.erase(bal_it);
				bal.insert(tmp_pair);
				
				tmp_set.clear();
				bal_it = bal.find(tmp);
				tmp_set = bal_it->second;
				tmp_set.insert(name);
				tmp_pair = make_pair(tmp, tmp_set);
				bal.erase(bal_it);
				bal.insert(tmp_pair);
		
			}
			
			break;
			
			case 'W' :         // withdraw
			cin>>name;
			cin>>inp1;
			acc_it = acc.find(name);
			if( acc_it == acc.end() )
			{
				invalid++;	
			}
			else
			{
				if(acc_it->second >= inp1)
				{
					tmp = acc_it->second - inp1;
					tmp2 = acc_it->second;
					acc.erase (acc_it);
					acc[name]=tmp;
					
					bal_it = bal.find(tmp);
					if(bal_it == bal.end() )
					{
						tmp_set.clear();
						tmp_set.insert(name);
						tmp_pair = make_pair(tmp, tmp_set);
						bal.insert(tmp_pair);	
					}
					else
					{
						tmp_set.clear();
						tmp_set = bal_it->second;
						tmp_set.insert(name);
						tmp_pair = make_pair(tmp, tmp_set);
						bal.erase(bal_it);
						bal.insert(tmp_pair);	
					}
					
					bal_it = bal.find(tmp2);
					if( (bal_it->second).size() == 1)
					{
						bal.erase(bal_it);	
					}
					else
					{
						tmp_set.clear();
						tmp_set = bal_it->second;
						tmp_set.erase(name);
						tmp_pair = make_pair(tmp2, tmp_set);
						bal.erase(bal_it);
						bal.insert(tmp_pair);	
					}
					
				}
				else
				{
					invalid++;	
				}	
			}
			
			break;
			
			case 'C' :         // close
			cin>>name;
			acc_it = acc.find(name);
			if(acc_it == acc.end() )
			{
				invalid++;	
			}
			else
			{
				if(acc_it->second == 0)
				{
					acc.erase(acc_it);	
					
					bal_it = bal.find(0);
					if((bal_it->second).size() == 1)
					{
						bal.erase(bal_it);	
					}
					else
					{
						tmp_set.clear();
						tmp_set = bal_it->second;
						tmp_set.erase(name);
						tmp_pair = make_pair(0, tmp_set);
						bal.erase(bal_it);
						bal.insert(tmp_pair);	
					}
				}
				else
				{
					invalid++;	
				}	
			}
			
			break;
			
			case 'P' :
			cin>>inp1;
			cin>>inp2;
			bal_it = bal.begin();
			if(bal_it == bal.end())
			{
				esc = 0;
			}
			else
			{
				while(bal_it != bal.end())
				{
					if(bal_it->first >= inp1 && bal_it->first <= inp2)
					{
						cout<<bal_it->first<<" ";
						
						it = (bal_it->second).begin();
						while(it != (bal_it->second).end() )
						{
							cout<<" "<<*it;	
						}	
					}
				}	
			}
			
			break;
			
			case 'E' :
			esc = 1;
			break;
		}
		
		if(esc == 1) break;		
	}
	
cout<<endl;
cout<<invalid;
		
return 0;	
}
