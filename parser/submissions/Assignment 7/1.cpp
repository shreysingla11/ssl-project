#include<iostream>
#include<set>
#include<string>
#include<map>


using namespace std;
class account
{
	int acno;
	char name[50];
	int deposit; //DEPOSITD
	char type;
public:
	void O();	////OPEN ACCOUNTfunction to get data from use
	void D(int);	//function to accept amount and add to balance amount
	void W(int);	//function to accept amount and subtract from balance amount
    void delete_account(int);	//function to delete record of file
};

void account::O()
{

	cin>>acno;

	cin.ignore();
	cin.getline(name,50);
	cin>>type;
	type=toupper(type);
	cin>>deposit;

}
void account::D(int x)
{
	deposit+=x;
}

void account::W(int x)
{
	deposit-=x;
}
void O();	////OPEN ACCOUNTfunction to get data from use
	void D(int,int);	//function to accept amount and add to balance amount
	void W(int,int);


int main()
{


std::map<string,int>ac_no;
std::map<int,set<string> >a_balance;


	char ch;
	int num;

	do
	{


		cin>>ch;

		switch(ch)
		{
		case '1':
             O(  );
			break;
		case '2':
            cin>>num;
			D(num, 1);
			break;
		case '3':

			W(num, 2);
			break;
		 default :cout<<"\a";
		}
		cin.ignore();
		cin.get();
	}while(ch!='8');
	return 0;
	cout<<1<<endl;
}

