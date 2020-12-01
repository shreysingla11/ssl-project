#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <string>

using namespace std;

int error_count;
std::map<string, int> map_str_int;
std::map<int , set<string> > map_int_set;


void open_ac(string name)
{
	if(!map_str_int.empty())
	{
		std::pair<std::map<string,int>::iterator,bool> ret;
		ret=map_str_int.insert(std::pair<string,int>(name,0));
		if(ret.second==false)
		{
			error_count++;
			return ;
		}
		else
		{
			std::map<int, set< string> >::iterator it1=map_int_set.find(0);
			if(it1==map_int_set.end())
			{
				set<string> nazset;
				nazset.insert(name);
				map_int_set.insert(std::pair<int,set<string> >(0,nazset));
			}
			else
			{
				it1->second.insert(name);
			}
		}		
	}
	else
	{
		set<string> nazset;
		nazset.insert(name);
		map_str_int.insert(std::pair<string,int>(name,0));
		map_int_set.insert(std::pair<int,set<string> >(0,nazset));
	}

	return;
}

void close_ac(string name)
{
	if(!map_str_int.empty())
	{
		std::map<string,int>::iterator it1=map_str_int.find(name);;
		if(it1==map_str_int.end())
		{
			error_count++;
			return;
		}
		else
		{
			int a=it1->second;
			map_str_int.erase(it1);
			std::map<int, set< string> >::iterator it2=map_int_set.find(a);
			if(it2==map_int_set.end())
			{
				cout<<"This Should not happen\n";
				return;
			}
			else
			{
				std::set<string>::iterator it3=it2->second.find(name);
				if(it3==it2->second.end())
				{
					cout<<"This Should not happen\n";
					return;
				}
				else
				{
					it2->second.erase(it3);
					if(it2->second.empty())
					{
						map_int_set.erase(it2);
					}
				}
			}
		}
	}
	else
	{
		error_count++;
	}
	return;
}

void deposit(string name, int amount)
{
	if(!map_str_int.empty())
	{
		std::map<string,int>::iterator it1=map_str_int.find(name);;
		if(it1==map_str_int.end())
		{
			error_count++;
			return;
		}
		else
		{
			std::map<int, set< string> >::iterator it2=map_int_set.find(it1->second);
			if(it2==map_int_set.end())
			{
				cout<<"This Should not happen\n";
				return;
			}
			else
			{
				std::set<string>::iterator it3=it2->second.find(name);
				if(it3==it2->second.end())
				{
					cout<<"This Should not happen\n";
					return;
				}
				else
				{
					it2->second.erase(it3);
					if(it2->second.empty())
					{
						map_int_set.erase(it2);
					}
				}
				it1->second+= amount;
				std::map<int, set< string> >::iterator it4=map_int_set.find(it1->second);
				if(it4==map_int_set.end())
				{
					set<string> nazset;
					nazset.insert(name);
					map_int_set.insert(std::pair<int,set<string> >(it1->second,nazset));
				}
				else
				{
					it4->second.insert(name);
				}
			}	 
		}
	}
	else
	{
		error_count++;
		return;
	}
}

void withdraw(string name, int amount)
{
	if(!map_str_int.empty())
	{
		std::map<string,int>::iterator it1=map_str_int.find(name);;
		if(it1==map_str_int.end())
		{
			error_count++;
			return;
		}
		else
		{
			std::map<int, set< string> >::iterator it2=map_int_set.find(it1->second);
			if(it2==map_int_set.end())
			{
				cout<<"This Should not happen\n";
				return;
			}
			else
			{
				if(it1->second - amount <0)
				{
					error_count++;
					return;
				}
				else
				{
					std::set<string>::iterator it3=it2->second.find(name);
					if(it3==it2->second.end())
					{
						cout<<"This Should not happen\n";
						return;
					}
					else
					{
						it2->second.erase(it3);
						if(it2->second.empty())
						{
							map_int_set.erase(it2);
						}	
					}
					it1->second -= amount;
					std::map<int, set< string> >::iterator it4=map_int_set.find(it1->second);
					if(it4==map_int_set.end())
					{
						set<string> nazset;
						nazset.insert(name);
						map_int_set.insert(std::pair<int,set<string> >(it1->second,nazset));
					}
					else
					{	
						it4->second.insert(name);
					}
				}
				
			}	 
		}
	}
	else
	{
		error_count++;
		return;
	}
}

void print(int low,int up)
{
	if(!map_int_set.empty())
	{
		for (std::map<int, set< string> >::iterator it_low = map_int_set.lower_bound(low); it_low !=map_int_set.upper_bound(up); ++it_low)
		{
			cout<<it_low->first;
			for (std::set<string>::iterator it = it_low->second.begin(); it != it_low->second.end(); ++it)
			{
				cout<<' '<<*it;
			}
			cout<<endl;
		}
		
	}
	else
	{
		return;
	}
}

int main()
{
	error_count = 0;
	char check;
	string inp_name;
	int amount;
	int high;
	// Input
	do
	{
		cin>>check;
		switch (check)
		{
			case 'O':
				//Work
				cin>>inp_name;
				open_ac(inp_name);
				break;
			case 'C':
				//Work
				cin>>inp_name;
				close_ac(inp_name);
				break;
			case 'W':
				//Work
				cin>>inp_name;
				cin>>amount;
				withdraw(inp_name,amount);
				break;
			case 'D':
				cin>>inp_name;
				cin>>amount;
				deposit(inp_name,amount);
				//Work
				break;
				case 'P':
					cin>>amount>>high;
					print(amount,high);
			case 'E':
				break;
			default:
				error_count++;
				break;
		}
	}
	while(check!='E');
	cout<<error_count<<endl;
}