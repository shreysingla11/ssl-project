#include <iostream>
#include <unordered_map>
# include <bitset>
#include <string>
#include <cstdio>
using namespace std;

string flip(string i){
	if(i=="0"){
		return "1";
	}
	else{
		return "0";
	}

}

int main(){

	int n;
	cin>>n;
	//string bit;
	long long int m;
	unordered_map< bitset<45>,char> hash_table;
	for(int i=0;i<26;i++){

		char c=i+97;
		bitset<5> bit(i);
		bitset<45> final(0);

		for(int i=0;i<5;i++){
			for(int j=0;j<9;j++){
				final.set(9*i+j,bit[i]);
				//cout<<final<<endl;
			}

		}
		hash_table[final]=c;
		//cout<<final<<endl;
		for(int i=0;i<45;i++){
			final.flip(i);
			hash_table[final]=c;

			for(int j=i+1;j<45;j++){
				final.flip(j);
				hash_table[final]=c;


				for(int k=j+1;k<45;k++){
				final.flip(k);
				hash_table[final]=c;

					for(int l=k+1;l<45;l++){
						final.flip(l);
						hash_table[final]=c;
						final.flip(l);
					}
					final.flip(k);
				}
				final.flip(j);

			}
			final.flip(i);

		}




	}

	std::unordered_map<bitset<45>,char>::iterator it;
	while(n--){
		//cin>>m;
		scanf("%lld",&m);
		bitset<45> temp(m);
		it=hash_table.find(m);
		if(it!=hash_table.end()){
			//cout<<it->secondc
			printf("%c",it->second );
		}
		else{
			printf("?");
		}


	}



}
