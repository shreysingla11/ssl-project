#include<iostream>
#include<cstdio>
#include<unordered_map>
#include<vector>

using namespace std;

typedef std::unordered_map<long long int, char> Map;
typedef long long int lint;

lint toLINT(int i, lint* twop){
	lint ans=0;
	for (lint c=0; c<5; ++c){
		ans += (i%2)*(511)*twop[9*c + 1];
		i /= 2;
	}
	return ans;
}

int main(){
	lint *twop = new lint[46];
	lint p=1; twop[0]=0;
	for (int i=0; i<45; ++i, p*=2){
		twop[i+1]=p;
	}
	vector<lint> P;
	lint tmp;
	int a,b,c,d;
	for(a=-1; a<45; ++a){
	for(b=a; b<45; ++b){
	for(c=b; c<45; ++c){
	for(d=c; d<45; ++d){
		tmp = 0;
		tmp += twop[a+1];
		if (b!=a) tmp += twop[b+1];
		if (c!=b) tmp += twop[c+1];
		if (d!=c) tmp += twop[d+1];
		P.push_back(tmp);
	}
	}
	}
	}
	// cout<<P.size();
	char t;
	Map myMap;
	for (int i=0; i<26; ++i){
		t = i+97;
	// 	// cout<<t;
		for (int j=0; j<P.size(); ++j){
			tmp = toLINT(i,twop)^P[j];
			myMap[tmp] = t;
		}
	}

	int n; scanf("%d",&n);
	lint input;
	Map::const_iterator got;
	while (n--){
		scanf("%lld",&input);
		got = myMap.find(input);
		if (got==myMap.end()) printf("?");
		else printf("%c",got->second);
	}
	printf("\n");

	return 0;
}