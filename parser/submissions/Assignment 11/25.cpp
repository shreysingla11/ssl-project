#include <cstdio>
#include <unordered_map>
#include <iostream>
#include <bitset>
using namespace std;

unordered_map<long long, char> map;
unordered_map<long long, char>::iterator it;
long long pow2[47];


void construct_map(){
	long long num = 0;
	bool isSet[45];

	for(int alpha=0; alpha<26; alpha++){
		/////////////////////////////////////
		bitset<5> x(alpha);
		int z = 0;
		for(int j=4; j>=0; j--){
			int cnt=9;
			while(cnt--) isSet[z++] = x[j];
		}
		// for(int q=0; q<45; q++) cout<<isSet[q];
		// cout << endl;
		////////////////////////////////////
		num = 0;
		for(int i=0; i<45; i++) if(isSet[i]) num += pow2[44-i];
		////////////////////////////////////
		// no error
		map[num] = 'a'+alpha;
		///////////////////////////////////
		// 1 error
		for(int pos1 = 0; pos1<45; pos1++){
			if(isSet[pos1]) num -= pow2[44-pos1];
			else num += pow2[44-pos1];
			//cout << num << endl;
			//cout << alpha << endl;
			map[num] = 'a'+alpha;
			if(isSet[pos1]) num += pow2[44-pos1];
			else num -= pow2[44-pos1];
		}
		//return;
		///////////////////////////////////
		// 2 error
		for(int pos1 = 0; pos1<45; pos1++){
			if(isSet[pos1]) num -= pow2[44-pos1];
			else num += pow2[44-pos1];

			for(int pos2 = pos1+1; pos2<45; pos2++){
				if(isSet[pos2]) num -= pow2[44-pos2];
				else num += pow2[44-pos2];
				map[num] = 'a'+alpha;
				if(isSet[pos2]) num += pow2[44-pos2];
				else num -= pow2[44-pos2];
			}

			if(isSet[pos1]) num += pow2[44-pos1];
			else num -= pow2[44-pos1];
		}
		///////////////////////////////////
		// 3 error
		for(int pos1 = 0; pos1<45; pos1++){
			if(isSet[pos1]) num -= pow2[44-pos1];
			else num += pow2[44-pos1];

			for(int pos2 = pos1+1; pos2<45; pos2++){
				if(isSet[pos2]) num -= pow2[44-pos2];
				else num += pow2[44-pos2];
				
				for(int pos3 = pos2+1; pos3<45; pos3++){
					if(isSet[pos3]) num -= pow2[44-pos3];
					else num += pow2[44-pos3];
					map[num] = 'a'+alpha;
					if(isSet[pos3]) num += pow2[44-pos3];
					else num -= pow2[44-pos3];
				}
				
				if(isSet[pos2]) num += pow2[44-pos2];
			 	else num -= pow2[44-pos2];
			}

			if(isSet[pos1]) num += pow2[44-pos1];
			else num -= pow2[44-pos1];
		}
		/////////////////////////////////////
		// 4 error
		for(int pos1 = 0; pos1<45; pos1++){
			if(isSet[pos1]) num -= pow2[44-pos1];
			else num += pow2[44-pos1];

			for(int pos2 = pos1+1; pos2<45; pos2++){
				if(isSet[pos2]) num -= pow2[44-pos2];
				else num += pow2[44-pos2];
				
				for(int pos3 = pos2+1; pos3<45; pos3++){
					if(isSet[pos3]) num -= pow2[44-pos3];
					else num += pow2[44-pos3];
					
					for(int pos4 = pos3+1; pos4<45; pos4++){
						if(isSet[pos4]) num -= pow2[44-pos4];
						else num += pow2[44-pos4];
						map[num] = 'a'+alpha;
						if(isSet[pos4]) num += pow2[44-pos4];
						else num -= pow2[44-pos4];
					}

					if(isSet[pos3]) num += pow2[44-pos3];
					else num -= pow2[44-pos3];
				}
				
				if(isSet[pos2]) num += pow2[44-pos2];
				else num -= pow2[44-pos2];
			}

			if(isSet[pos1]) num += pow2[44-pos1];
			else num -= pow2[44-pos1];
		}
	}
}

int main(){
	//cout <<"here"<<endl;
	pow2[0] = 1;
	for(int i=1; i<47; i++) pow2[i] = pow2[i-1]*2;
	construct_map();
//cout <<"here"<<endl;
	int n;
	scanf("%d", &n);
	while(n--){
		long long i;
		scanf("%lld", &i);
		it = map.find(i);
		if(it != map.end()){
			putchar_unlocked(it->second);
		}
		else{
			putchar_unlocked('?');	
		}
	}
	return 0;
}