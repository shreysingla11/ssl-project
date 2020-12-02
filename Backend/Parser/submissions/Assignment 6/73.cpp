#include <iostream>
// #include <algorithm>
#include <vector>
#include <string>
#include <limits>

using namespace std;

# define INF 10000000
// void check_reverse_iterate(string S, int W1_start, int W1_end, int W2_start){

// }


//Size,index
pair<int, int> check_one_block(string S, int N, int l, int start){
	int ptr1 = start;
	int ptr2 = start + 2*l - 1;
	int part_2_start = ptr2;
	int cases = 0; // 0 = match_till 4l_2 ; 1 = match_till string end
	
	// cout<<"S : "<<S<<" n: "<<N<<" l: "<<l<<" start: "<<start<<endl;

	for (; (ptr1 < start + l);){
		// cout<<"Loop Small 1"<<endl;
		if(ptr2 >= N + 1 - l || (ptr2 > ptr1 + 4*l - 2) || (ptr2 > start + 5*l - 2)){
			cases = -1;
			break;
		}
		else
		if(S[ptr1] == S[ptr2]){
			ptr1++;
			ptr2++;
		}
		else{
			if(ptr1 == start){
				ptr2++;
				part_2_start = ptr2;
			}
			else{
				ptr1=start;
				part_2_start = ptr2;
			}
		}
	}

	if(cases == -1){
		//No Matching Block
		// cout<<"return pt1"<<endl;
		return make_pair(-1,0);	
	}
	
	//Found Matching Block\
	//start,part_2_start
	ptr1 = start - 1;
	ptr2 = part_2_start - 1;

	cases = 0;
	while( ptr1 >= 0 ){
		// cout<<"Loop Small 2"<<endl;

		if( S[ptr1] == S[ptr2] ){

			ptr1--;
			ptr2--;
		}
		else{
			break;
		}

		if( ptr2 <= start + l - 1){
			cases = -1;
			break;
		}
	}

	if(cases == -1){
		/// Found!! W1 : ptr1+1,start+l-1

		// cout<<"return pt2"<<endl;
		return make_pair(start + l - (ptr1+1), ptr1+1);
	}

	int W1_start = ptr1 + 1;
	int W2_start = ptr2 + 1;

	ptr1 = start + l;
	ptr2 = part_2_start + l;

	if(ptr1 == part_2_start){

		// cout<<"return pt2.5"<<endl;
		// cout<<part_2_start - W1_start<<" "<<W1_start<<endl;
			return make_pair(part_2_start - W1_start, W1_start);
		}

	for (; (ptr2 < N) && (ptr1 < part_2_start);){

		// cout<<"Loop Small 3"<<endl;

		if(S[ptr1] == S[ptr2]){
	
			ptr1++;
			ptr2++;

			if(ptr1 == part_2_start){
			// cout<<"return pt3"<<endl;
				return make_pair(part_2_start - W1_start, W1_start);
			}
		}
		else{
			return make_pair(-1,0);
		}
	}

		// cout<<"return pt4"<<endl;
	return make_pair(-1,0);	
}

pair<int, int>  check_all_blocks(string S, int N, int l){

	pair<int, int> min_pair = make_pair( INF, INF);

	for(int start = 0; start + l < N; start = start + l){
		// cout<<"Loop check_all_blocks"<<endl;

		pair<int, int> temp = check_one_block(S, N, l, start);

		if(temp.first != -1){
			if(temp.first < min_pair.first){

				min_pair = temp;
			}
			else if(temp.first == min_pair.first){

				if(temp.second < min_pair.second){

					min_pair = temp;
				}
			}
		}
	}
	return min_pair;

}


int main(){
	string S;
	cin>>S;
	int N =S.length();

	for(int l =1; 2*l<=N ; l=2*l)
	{
		// cout<<"Loop Main"<<endl;
		pair<int, int> square= check_all_blocks(S,N,l);
		// cout<<square.first<<" "<<square.second<<endl;
		if( square.first > 0 && square.first < INF){
			cout<<square.first<<" "<<square.second<<endl;
			return 0;
		}
	}

	cout<<0<<" "<<0<<endl;
	return 0;
}
