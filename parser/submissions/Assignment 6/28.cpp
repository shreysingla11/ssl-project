#include <iostream>
#include <cmath>
#define min(a, b) ((a<b)?a:b)
using namespace std;

int main(){
	string s;
	cin >> s;
	int n = s.size();
	//for(int i=0; i<1000; i++) cout << s[i];
	bool sqFound = false;
	// bound is decided by 2(4*l-2) <= n --WRONG
	// bound is decided by 2(2*l-1) <= n --CORRECT
	for(int l = 1; l <= (n+2)/4; l *= 2){
		// looking for squares of length 2*l-1 to 4*l-2 (both inclusive)
		int minLength = n+1;
		int minStart = n+1;
		// blockLength = l
		// bound can be improved
		for(int blockNo = 1; blockNo <= n/l; blockNo++){
			int blockStart = l*(blockNo-1);
			int blockEnd = blockStart+l-1;
			// so the block is from s[blockStart] to s[blockEnd] (both inclusive)

			// task - find the next occurence of this block
			// at most 2 occurences wil be there
			// this 2 occurences will not overlap
			for(int checkStart = blockEnd+1; checkStart <= blockStart+4*l-2 && checkStart+l-1 < n; ){
				int i = blockStart; // first string
				int j = checkStart; // second string
				bool blockMatchfound = true;
				for(; i<=blockEnd; i++, j++){
					if(s[i] != s[j]){
						blockMatchfound = false;
						break;
					}
				}
				if(blockMatchfound){
					// blocks matched. Now check that that if a square is found
					int b1Start = blockStart;
					int b2Start = checkStart;
					int b1End = blockEnd;
					int b2End = b2Start+l-1;
					
					// go as left as you can, since we want the smallest position
					for(; b1Start>0 && b2Start>blockEnd+1; ){
						if(s[b1Start-1] == s[b2Start-1]){
							b1Start--;
							b2Start--;
						}
						else break;
					}
					if(b2Start != b1End+1){
						// sqaure not found yet, need to go right now
						for(; b2End<n-1 && b1End<b2Start-1; ){
							if(s[b1End+1] == s[b2End+1]){
								b1End++;
								b2End++;
							}
							else break;
						}
					}

					if(b1End+1 == b2Start){
						// square found
						sqFound = true;
						int length = b1End-b1Start+1;
						if(minLength > length){
							minLength = length;
							minStart = b1Start;
						}
						else if(minLength == length){
							minStart = min(minStart, b1Start); // will this case ever occur ????
						}
						// if a square is found, start looking for other blockNo, second occurence of this block will give bigger sqaure
						break; // this will not break out of blockNo loop
					}
					// if square is not formed corresponding the first blockMatch, look for second blockMatch
				}
				// j is the position of first mismatch
				checkStart = (j==checkStart)? j+1: j;
			}
		}

		if(sqFound){
			cout << minLength << " " << minStart << endl;
			break;
		}
	}

	if(!sqFound){
		cout << "0 0" << endl;
	}
	return 0;
}