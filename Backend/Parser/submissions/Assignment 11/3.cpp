#include <iostream>
#include <unordered_map>
#include <string>
#include <map>


using namespace std;

int main () {
	
	int n;
	cin>>n;
	
	long long int a[n];
	for (int i=0;i<n;i++) {
		cin>>a[i];
		}
	unordered_map<char,long long int > mymap;
	
	struct Key {
    std::string first;
    std::string second;
};

struct KeyEqual {
 bool operator()(const Key& lhs, const Key& rhs) const
 {
    return lhs.first == rhs.first && lhs.second == rhs.second;
 }
};

  for (unsigned i=0; i<nbuckets; ++i) {
    std::cout << "bucket #" << i << " has " << mymap.bucket_size(i) << " elements.\n";
  }
  
const char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
for ( size_t index = 0; index < sizeof letters; ++index ) {
    numbers [ letters [ index ] ] = index + 1;
}
}
	


