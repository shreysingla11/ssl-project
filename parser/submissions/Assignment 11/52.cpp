#include <iostream>
#include <unordered_map>

using namespace std;

/*struct func{
	long long operator()(long long const i) const{
		
		return hash<long long>()
		}
	}
*/
int main(){
	
	unordered_map<long long, string> mymap ={
		{0,"a"},
		{511, "b"},
		{261632, "c"}, //10
		{262143, "d"}, //11
		{133955584, "e"}, //100
		{133956095, "f"}, //101
		{134217216,"g"}, //110
		{134217728, "h"}, //111
		{68585259008, "i"},//1000
		{68585259519, "j"}, //1001
		{68585520640, "k"}, //1010
		{68585521151, "l"}, //1011
		{68719214592, "m"}, //1100
		{68719215103, "n"}, //1101
		{68585259519, "o"}, //1010
		
		};
	
	
	}
