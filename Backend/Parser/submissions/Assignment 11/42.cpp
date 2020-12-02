#include <iostream>
#include <string>
#include <unordered_map>
#include <bitset>

using namespace std;

typedef unordered_map<unsigned long long int,char> stringmap;



int main ()
{
stringmap mymap;
{
	unsigned long long int twopower[45];
		twopower[44]=1;
		for(int i=43;i>=0;i--)
		{
			twopower[i]=twopower[i+1]*2;
		}


	int presChar;
	char presCharChar='a';


	
	string s;
	int tempInt;
	string initial;
	char* tempchar;
	unsigned long long int ull,tempUll;
	stringmap tempMap;

	for(;presCharChar!='{';presCharChar++)
	{

		presChar=presCharChar-'a';
		bitset<5> foo(presChar);
		std::string mystring =
	    foo.to_string<char,std::string::traits_type,std::string::allocator_type>();
		
	    s="";
		for(int i=0;i<45;i++)
		{
			tempInt=i/9;
			s+=mystring[tempInt];
		}

		initial=s;

		tempUll=0;
		for(int m=0;m<45;m++)
		{
			tempUll+=twopower[m]*(s[m]-'0');
		}

		mymap[tempUll]=presCharChar;
		//First for loop *********************************
		for(int i=0;i<45;i++)
		{
			if(s[i]=='0'){s[i]='1';tempUll+=(twopower[i]);}
			else{s[i]='0';tempUll-=(twopower[i]);}
			for (int j = i+1; j < 45; ++j)
			{
				if(s[j]=='0'){s[j]='1';tempUll+=(twopower[j]);}
				else{s[j]='0';tempUll-=(twopower[j]);}
				for (int k = j+1; k < 45; ++k)
				{
					if(s[k]=='0'){s[k]='1';tempUll+=(twopower[k]);}
					else{s[k]='0';tempUll-=(twopower[k]);}
					for (int l = k+1; l < 45; ++l)
					{
						if(s[l]=='0'){s[l]='1';tempUll+=(twopower[l]);}
						else{s[l]='0';tempUll-=(twopower[l]);}
						mymap[tempUll]=presCharChar;
						if(s[l]=='0'){s[i]='1';tempUll+=(twopower[l]);}
						else{s[l]='0';tempUll-=(twopower[l]);}
					}
					if(s[k]=='0'){s[k]='1';tempUll+=(twopower[k]);}
					else{s[k]='0';tempUll-=(twopower[k]);}
				}
				if(s[j]=='0'){s[j]='1';tempUll+=(twopower[j]);}
				else{s[j]='0';tempUll-=(twopower[j]);}
			}
			if(s[i]=='0'){s[i]='1';tempUll+=(twopower[i]);}
			else{s[i]='0';tempUll-=(twopower[i]);}
		}

		//Second For ******************************
			for (int j = 0; j < 45; ++j)
			{
				if(s[j]=='0'){s[j]='1';tempUll+=(twopower[j]);}
				else{s[j]='0';tempUll-=(twopower[j]);}
				for (int k = j+1; k < 45; ++k)
				{
					if(s[k]=='0'){s[k]='1';tempUll+=(twopower[k]);}
					else{s[k]='0';tempUll-=(twopower[k]);}
					for (int l = k+1; l < 45; ++l)
					{
						if(s[l]=='0'){s[l]='1';tempUll+=(twopower[l]);}
						else{s[l]='0';tempUll-=(twopower[l]);}

						//mymap.insert(make_pair<unsigned long long int,char>(tempUll,presCharChar));
						mymap[tempUll]=presCharChar;

						if(s[l]=='0'){s[l]='1';tempUll+=(twopower[l]);}
						else{s[l]='0';tempUll-=(twopower[l]);}
					}
					if(s[k]=='0'){s[k]='1';tempUll+=(twopower[k]);}
					else{s[k]='0';tempUll-=(twopower[k]);}
				}
				if(s[j]=='0'){s[j]='1';tempUll+=(twopower[j]);}
				else{s[j]='0';tempUll-=(twopower[j]);}
			}

		//Third for *******************************
			for (int k = 0; k < 45; ++k)
			{
				if(s[k]=='0'){s[k]='1';tempUll+=(twopower[k]);}
				else{s[k]='0';tempUll-=(twopower[k]);}
				for (int l = k+1; l < 45; ++l)
				{
					if(s[l]=='0'){s[l]='1';tempUll+=(twopower[l]);}
					else{s[l]='0';tempUll-=(twopower[l]);}

					//mymap.insert(make_pair<unsigned long long int,char>(tempUll,presCharChar));
					mymap[tempUll]=presCharChar;

					if(s[l]=='0'){s[l]='1';tempUll+=(twopower[l]);}
					else{s[l]='0';tempUll-=(twopower[l]);}
				}
				if(s[k]=='0'){s[k]='1';tempUll+=(twopower[k]);}
				else{s[k]='0';tempUll-=(twopower[k]);}
			}

		//Fourth for *******************************
			for (int l = 0; l < 45; ++l)
			{
				if(s[l]=='0'){s[l]='1';tempUll+=(twopower[l]);}
				else{s[l]='0';tempUll-=(twopower[l]);}

				//mymap.insert(make_pair<unsigned long long int,char>(tempUll,presCharChar));
				mymap[tempUll]=presCharChar;

				if(s[l]=='0'){s[l]='1';tempUll+=(twopower[l]);}
				else{s[l]='0';tempUll-=(twopower[l]);}
			}
	}
}


int n;
cin>>n;
stringmap::iterator last= mymap.end();
stringmap::iterator itrNow;
unsigned long long int now;

for(int i=0;i<n;i++)
{
	cin>>now;
	itrNow=mymap.find(now);
	if(itrNow==last)
	{
		cout<<'?';
	}
	else
	{
		cout<<itrNow->second;
	}


}



  return 0;
}
