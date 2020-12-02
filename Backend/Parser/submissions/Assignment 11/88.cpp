#include <iostream>
#include <unordered_map>
#include <bitset>

using namespace std;


int main()
{
	unsigned long long int temp1;
	bitset<45> res,temp;
	unordered_map<unsigned long long int, char> mainmap;
	int n,g,tempval,val;
	char alpha;
	for (int i=0;i<26;i++)
	{
		alpha = i + 97;
		bitset<5> temp12(i);
		for (int j=0;j<5;j++)
		{
			for (int k=9*j;k<9*(j+1);k++)
			{
				res[k] = temp12[j];
			}
		}
		//cout<<res<<endl;
		temp1 = res.to_ullong();
		mainmap[temp1] = alpha;

		temp = res;
		//cout<<temp<<endl;
		for (int j=0;j<45;j++)
		{
			temp[j].flip();
			temp1 = temp.to_ullong();
			mainmap[temp1] = alpha;
			for (int k=j+1;k<45;k++)
			{
				temp[k].flip();
				temp1 = temp.to_ullong();
				mainmap[temp1] = alpha;
				for (int t=k+1;t<45;t++)
				{
					temp[t].flip();
					temp1 = temp.to_ullong();
					mainmap[temp1] = alpha;
					for (int h=t+1;h<45;h++)
					{
						temp[h].flip();
						temp1 = temp.to_ullong();
						mainmap[temp1] = alpha;
						temp[h].flip();
					}
					temp[t].flip();
				}
				temp[k].flip();
			}
			temp[j].flip();
		}
	}

	scanf("%d",&n);
	unordered_map<unsigned long long int, char>::iterator got ;
	for (int i=0;i<n;i++)
	{
		scanf("%d",&g);
		bitset<45> tempnew(g);
		temp1 = tempnew.to_ullong();
		//cout<<tempnew;
		//cout<<temp;
		got = mainmap.find(temp1);
		if (got != mainmap.end())
		{
			printf("%c", got->second);
		}
		else
			printf("?");
	}
	printf("\n");
}