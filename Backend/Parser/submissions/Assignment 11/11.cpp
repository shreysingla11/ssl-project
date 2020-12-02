#include <iostream>
#include <cstdio>
#include <unordered_map>
using namespace std;

typedef long long int ll; 


int main(){

	 long long int a[26];
	 long long int pow[46];
	 pow[0] = 1;
	 for (int i=1; i<=45; i++){
		pow[i] = pow[i-1]*2;
	 }
	 
	 unordered_map <long long int, char>  map;

	 for (int i=0; i<26; i++){
		a[i]=0;
		int z =i;
		int b;
		int ct =0;
		while (z>0){
			b = z%2;
			if (b==1){
				for(int j=1; j<=9; j++){
					a[i] += pow[ct];
					ct++;
				}
			}
			else
				ct+=9;

			z=z/2;
		}
		map.insert(make_pair(a[i], i+'a'));
		//cout<<a[i]<<endl;
	 }

	 

	for(int let = 0; let<=25; let++){
	  for (int i =0; i<45; i++){
	  	long long int val1 = a[let]^((ll)1<<i);
	  	map.insert(make_pair(val1, let+'a'));
	 	for (int j = i+1; j<45; j++){
	 		long long int val2 = ((a[let]^((ll)1<<i))^((ll)1<<j));
	 		map.insert(make_pair(val2, let+'a'));
	 		for (int k=j+1; k<45; k++){
	 			long long int val3 = (((a[let]^((ll)1<<i))^((ll)1<<j))^((ll)1<<k));
	 			map.insert(make_pair(val3, let+'a'));
	 			for (int l=k+1; l<45; l++){
	 				long long int val4 = ((((a[let]^((ll)1<<i))^((ll)1<<j))^((ll)1<<k))^((ll)1<<l)); 
	 				map.insert(make_pair(val4, let+'a'));
	 			}
	 		}
	 	}
	 }
 	}

 	int t;
 	scanf("%d", &t);
 	long long int n;
 	unordered_map<long long int, char>:: iterator it;
 	while(t--){
 		scanf("%lld", &n);
 		it = map.find(n);
 		if (it == map.end())
 			printf("?");
 		else
 			printf("%c", it->second);
 	}
 	printf("\n");
}

