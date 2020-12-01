#include <iostream>
#include <map>
#include <set>
using namespace std;

int main()
{
	std::map<string,int> AcName;
	std::map<int, set<string> > balance;
	char operation;
	
	int countIllegal = 0;

	while (true)
	{
		cin>>operation;
		if (operation == 'E')
		{
			break;
		}
		switch (operation)
		{
			case 'O' :
				{
					string open;
					cin>>open;
					std::map<string,int >::iterator iter;
					iter = AcName.find(open);
					if (iter == AcName.end())
		            {
		                AcName[open]=0;
						balance[0].insert(open);
		            }
					else
						countIllegal++;

					break;
				}

			case 'C' :
				{
					string close;
					cin>>close;
					std::map<string,int >::iterator iter2;
					iter2 = AcName.find(close);
					if (iter2 == AcName.end())
					{
						countIllegal++;
					}
					else
					{
						if (AcName[close] == 0)
						{
							AcName.erase(close);
							balance[0].erase(close);
							if (balance[0].empty())
							{
								balance.erase(0);
							}
						}
						else
							countIllegal++;
					}
					break;
				}

			case 'D' :
				{
					string acHolder;
					int amount;
					cin>>acHolder>>amount;
					std::map<string,int >::iterator iter3;
					iter3 = AcName.find(acHolder);
					if (iter3 == AcName.end())
					{
						countIllegal++;
					}
					else
					{
						balance[AcName[acHolder]].erase(acHolder);
						if (balance[AcName[acHolder]].empty())
						{
							balance.erase(AcName[acHolder]);
						}
						AcName[acHolder]+=amount;
						balance[AcName[acHolder]].insert(acHolder);
					}
					break;
				}

			case 'W' :
				{
					string acHolder2;
					int amount;
					cin>>acHolder2>>amount;
					std::map<string,int >::iterator iter4;
					iter4 = AcName.find(acHolder2);
					if (iter4 == AcName.end())
					{
						countIllegal++;
					}
					else
					{
						if (amount <= AcName[acHolder2])
						{
							balance[AcName[acHolder2]].erase(acHolder2);
							if (balance[AcName[acHolder2]].empty())
							{
								balance.erase(AcName[acHolder2]);
							}
							AcName[acHolder2]-=amount;
							balance[AcName[acHolder2]].insert(acHolder2);
						}
						else
							countIllegal++;
					}

					break;
				}

			case 'P' :
				{
					int start,end;
					cin>>start>>end;
					std::map<int, set<string> >::iterator it;
					std::set<string >::iterator sit;
					for (it = balance.begin(); it != balance.end(); ++it)
					{
						if (it->first >=start && it->first <= end)
						{
							cout<<it->first;
							for (sit = balance[it->first].begin(); sit != balance[it->first].end(); ++sit)
							{
								cout<<" "<<*sit;
							}
							cout<<endl;
						}
					}
				}
				break;

			default:
				break;

		}
	}
	cout<<countIllegal<<endl;

	return 0;
}
