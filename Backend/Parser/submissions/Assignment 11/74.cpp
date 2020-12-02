#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <stdio.h>
#include <cstdio>
using namespace std;

unordered_map<long long int, char> charMap;

int change(int a) {
if (a==0) return 1;
else if (a==1) return 0;
}

void print(vector<int> L) {
for(int i=0;i<5;i++) {
    cout<<L[i];
}
cout<<endl;
}

long long int binToInt(vector<int> L) {

long long int temp = 0;
for(int i=44;i>=0;i--) {
    temp = temp + L[44-i]*pow(2,i);
}
return temp;
}


int main() {

vector<int> binary45(45);
vector<int> binary5;
long long int dec;
long int cou =0;
long long int arr1[26];

for(int a=0;a<26;a++) {

binary5.resize(5,0);
int ind = 4;
int copy1 = a;

while(copy1 != 0) {
    binary5[ind] = copy1%2;
    copy1 = copy1/2;
    ind--;
}

for(int i=0; i<5; i++) {
    for(int j=0;j<9;j++) {
        binary45[9*i + j] = binary5[i];
    }
}

arr1[a] = binToInt(binary45);
}

    //    long long int val=dec;
for (int i = 0; i < 26; ++i)
		{
			charMap[arr1[i]]=(char(i+97));
			for (int j=0;j<45;++j)
			{
				long long int value1=arr1[i]^((long long int)1<<j);
				charMap[value1]=(char(i+97));
				for (int k = j+1; k<45; ++k)
				{
					long long int value2=arr1[i]^((long long int)1<<j)^((long long int)1<<k);
					charMap[value2]=(char(i+97));
					for(int l = k+1; l<45; ++l)
					{
						long long int value3=arr1[i]^((long long int)1<<j)^((long long int)1<<k)^((long long int)1<<l);
						charMap[value3]=(char(i+97));
						for(int m = l+1; m<45; ++m){
							long long int value4=arr1[i]^((long long int)1<<j)^((long long int)1<<k)^((long long int)1<<l)^((long long int)1<<m);
							charMap[value4]=(char(i+97));
							// if()
						}
					}
				}
			}
		}
//cout<<cou<<endl;
long long int var;
unordered_map<long long int, char>::iterator it;
int t;
scanf("%d",&t);

while(t>0) {

scanf("%lld",&var);
it = charMap.find(var);
if(it == charMap.end()) {
    printf("%c",'?');
}
else printf("%c",it->second);
t--;
}

return 0;
}
