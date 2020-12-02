#include<iostream>
#include<stdio.h>
#include<unordered_map>
#include<string>
#include<math.h>
#include<vector>
#include<bitset>

using namespace std;
unordered_map<long long int, char> letter;
vector<long long int> v(26);

vector<bool> bin(long long int i)
{
    vector<bool> temp(64,0);
    int j=63;
    while(i)
    {
        temp[j]=i%2;
        i/=2;
        j--;
    }
    return temp;
}
int main()
{
    long long int v_temp;
    for(int i=0;i<26;i++)
    {
        v_temp=0;
        int j=i;
        int dig=0;
        while(j>0)
        {
            if(j%2==1)
            {

                for(int k=0;k<9;k++)
                {
                    v_temp+=((long long int)pow(2,dig));
                    //v_temp+=(pow(2,dig));
                    dig++;
                }
            }
            else dig+=9;
            j=j/2;
        }
        v[i]=v_temp;
    }


    /*for(int i=0;i<26;i++)
    {
        long long int temp1,temp2,temp3,temp4;
        letter[v[i]] = (char(i+97));
        for(int j=0;j<45;j++)
        {
            temp1=v[i]^((long long int)pow(2,j));
            letter[temp1]= (char(i+97));
            for(int k=j+1;k<45;k++)
            {
                temp2=temp1^((long long int)pow(2,k));
                letter[temp2]=(char(i+97));
                for(int l=k+1;l<45;l++)
                {
                    temp3=temp2^((long long int)pow(2,l));
                    letter[temp3]=(char(i+97));
                    for(int m=l+1;m<45;m++)
                    {
                        temp4=temp3^((long long int)pow(2,m));
                        letter[temp4]=(char(i+97));
                    }
                }
            }
        }
    }*/
    for (int i = 0; i < 26; i++)
		{
			letter[v[i]]=(char(i+97));
			for (int j=0;j<45;j++)
			{
				long long int value1=v[i]^((long long int)1<<j);
				letter[value1]=(char(i+97));
				for (int k = j+1; k<45; k++)
				{
					long long int value2=v[i]^((long long int)1<<j)^((long long int)1<<k);
					letter[value2]=(char(i+97));
					for(int l = k+1; l<45; l++)
					{
						long long int value3=v[i]^((long long int)1<<j)^((long long int)1<<k)^((long long int)1<<l);
						letter[value3]=(char(i+97));
						for(int m = l+1; m<45; m++){
							long long int value4=v[i]^((long long int)1<<j)^((long long int)1<<k)^((long long int)1<<l)^((long long int)1<<m);
							letter[value4]=(char(i+97));
						}
					}
				}
			}
		}
    long long int n,temp;
    string s;
    cin>>n;
    unordered_map<long long int,char>::iterator got;
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&temp);
        got = letter.find(temp);
        if ( got == letter.end() )
            printf("?");
        else
            printf("%c",got->second);
    }
    cout<<endl;
    return 0;
}
