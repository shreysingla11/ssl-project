#include<unordered_map>
#include<bitset>
#include<string>
#include<cstdio>
#include<iostream>

using namespace std;
int main()
{
int n;
scanf("%d",&n);

unordered_map<string, char> schar;
string orignal[26];
//----------------------------------------
for(int i = 0; i<26;i++)
    {
    orignal[i] = bitset<5> (i).to_string();

    }
    string t="";
for(int i = 0;i<26;i++)
    {
    t = "";
        for(int j=0;j<5;j++)
        {
           t = t+ orignal[i][j] + orignal[i][j] + orignal[i][j] + orignal[i][j] + orignal[i][j] + orignal[i][j]   +orignal[i][j] + orignal[i][j] + orignal[i][j]  ;

        }
        orignal[i] = t;

        schar[orignal[i]]= i+ 'a';

}
string orignal1[5];
//-------------------------------------------------------------

for(int letter = 0 ; letter<26;letter++)
{
orignal1[0]=orignal[letter];

for(int i = 0;i<45;i++)
{
    orignal1[1] = orignal1[0];                   // the orignal array

    if(orignal1[1][i] == '1')orignal1[1][i] = '0';  // changing the one character
    else orignal1[1][i] = '1';


    schar[orignal1[1]] = letter + 'a';

	for(int j = i+1;j<45 ;j++)

	{
       orignal1[2] = orignal1[1];

       if(orignal1[2][j] == '1')orignal1[2][j] = '0';  // changing the one character
    else orignal1[2][j] = '1';


   schar[orignal1[2]] = letter + 'a';


		for(int k = j+1;k<45;k++)
		{
            orignal1[3] = orignal1[2];
            if(orignal1[3][k] == '1')orignal1[3][k] = '0';  // changing the one character
            else orignal1[3][k] = '1';


            schar[orignal1[3]] = letter + 'a';

			for(int l = k+1;l<45;l++)
			{
                orignal1[4] = orignal1[3];

                   if(orignal1[4][l] == '1')orignal1[4][l] = '0';  // changing the one character
            else orignal1[4][l] = '1';

            schar[orignal1[4]] = letter + 'a';

			}
		}


	}


}
//------------------------------------------------------
}

while(n--)
{
long long int r;
scanf("%lld",&r);

string ans = bitset<45>(r).to_string();

unordered_map<string,char>::const_iterator got = schar.find(ans);

if(got!= schar.end() )
{
printf("%c",got->second);
}
else
{
printf("?");
}

}


}
