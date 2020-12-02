#include <iostream>
#include <string>
#include <cstdio>
#include <unordered_map>
using namespace std;

int main()
{
	int n,k,temp;
	unordered_map<long long, char> decode;
	unordered_map<long long, char>::iterator it;
	long long exactcode, errorcode ,inputcode;
	char character;
	string bitcode;
	long long power2[45];
	long long sumpower2=0;
	power2[0]=1;
	for(int i=1;i<45;i++)
	{
		power2[i]=2*power2[i-1];
	}
	for(int i=0;i<9;i++)
	{
		sumpower2+=power2[i];
	}
	
	for(int num =0;num<26;num++)
	{
		exactcode = 0;
		k=0;
		temp = num;
		bitcode="00000";
		while(temp>0)
		{
			if(temp%2==1)
			{
				exactcode+=power2[9*k]*sumpower2;
				bitcode[4-k]='1';
			}
			temp/=2;
			k++;

		}
		//cout<<num<<" "<<exactcode<<" "<<bitcode<<endl;
		character = 'a'+num;
		decode.insert(pair<long long, char>(exactcode,character));
		for(int i=0;i<45;i++)
		{
			for(int j=i+1;j<45;j++)
			{
				for(int k=j+1;k<45;k++)
				{
					for(int l=k+1;l<45;l++)
					{
						errorcode = exactcode;
						if(bitcode[4-i/9]=='0')
							errorcode += power2[i];
						else
							errorcode -= power2[i];
						if(bitcode[4-j/9]=='0')
							errorcode += power2[j];
						else
							errorcode -= power2[j];
						if(bitcode[4-k/9]=='0')
							errorcode += power2[k];
						else
							errorcode -= power2[k];
						if(bitcode[4-l/9]=='0')
							errorcode += power2[l];
						else
							errorcode -= power2[l];
						decode.insert(pair<long long, char>(errorcode,character));
					}
				}
			}
		}
		for(int i=0;i<45;i++)
		{
			for(int j=i+1;j<45;j++)
			{
				for(int k=j+1;k<45;k++)
				{
					errorcode = exactcode;
					if(bitcode[4-i/9]=='0')
						errorcode += power2[i];
					else
						errorcode -= power2[i];
					if(bitcode[4-j/9]=='0')
						errorcode += power2[j];
					else
						errorcode -= power2[j];
					if(bitcode[4-k/9]=='0')
						errorcode += power2[k];
					else
						errorcode -= power2[k];
					decode.insert(pair<long long, char>(errorcode,character));
		
				}
			}
		}
		for(int i=0;i<45;i++)
		{
			for(int j=i+1;j<45;j++)
			{
				errorcode = exactcode;
				if(bitcode[4-i/9]=='0')
					errorcode += power2[i];
				else
					errorcode -= power2[i];
				if(bitcode[4-j/9]=='0')
					errorcode += power2[j];
				else
					errorcode -= power2[j];
				decode.insert(pair<long long, char>(errorcode,character));
			}
		}
		for(int i=0;i<45;i++)
		{
			errorcode = exactcode;
			if(bitcode[4-i/9]=='0')
				errorcode += power2[i];
			else
				errorcode -= power2[i];
			decode.insert(pair<long long, char>(errorcode,character));
		}
	}

	scanf("%d",&n);
	while(n>0)
	{
		scanf("%lld",&inputcode);
		it = decode.find(inputcode);
		if(it==decode.end())
		{
			printf("?");
		}
		else
		{
			printf("%c",it->second);
		}
		n--;
	}
	return 0;
}