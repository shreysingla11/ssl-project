#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    int l=1, k, startpos,i, counter, beg1, beg2, end1, end2;
    cin>>s;
	int final_start=0;
	int min = 1e9;
	int length=0;
	int start_index;
	bool gflag=false;
    for (l=1; l<=s.length(); l*=2){

        bool checkCompare=false;
        int bn = s.length()/l;      // block  number
        int j=2*l-1;
		int pos = 2*l-1;
         for (k=0; k<=bn; k++){
			pos = k*l + 2*l-1;
			startpos = k*l;
			//cout<<l<<endl;
			for (i=0; i<l && pos<=k*l + 4*l-2 && pos+i<s.length(); ){
                if (s[startpos]!=s[pos]){
                    pos++;
                }
                else{
                    if (s[startpos+i]!=s[pos+i]){
                        pos = pos+i;
                    }
                }

			if (i==l){
                checkCompare = true;
                break;
			  }
            }
			beg1 = startpos;
			beg2 = pos;
			//cout<<"L:ER"<<l<<endl;
			end1 = beg1+l-1;
			//cout<<end1;
			end2 = beg2 + l-1;
			//cout<<"WRE"<<beg1<<beg2<<end1<<end2<<"sdfg"<<endl;
			//cout<<"SE"<<endl;
			bool flagbeg= true;
			bool flagend=true;
			bool flag=true;
			// Indices beg1, beg2, end1, end2 to store the block ends
			while (beg2>end1){
				if (s[beg2] != s[beg1]) flagbeg=false;
				if (s[end1] !=s[end2] ) flagend=false;
				if (flagbeg==false || flagend == false) break;
                beg2--; beg1--;
				end2++; end1++;
				//cout<<"A"<<endl;
			}

			if (flagbeg==false){
				while(end1<beg2){
					if (s[end2]!= s[end1]) break;
					end2++; end1++;
				//	cout<<"B"<<endl;
				}
				if (end1 == beg2){
					length = end2-beg2-1;			//????????
					start_index = beg1+1;
					}
				else {
					flag=false;
					continue;
				}
			}
            //cout<<"C"<<endl;
			if (flagend==false){
				 while(beg2+1>end1){
					 if(s[beg2] != s[beg1]) break;
					 beg2--; beg1--;
				 }
				 if (end1 ==beg2+1){
					 length=end2-beg2-1;
					 start_index= beg1+1;
				 }
				else{
                    //cout<<"D"<<endl;
					flag=false;
					continue;
				}
			}

			if (length <min){
				min=length;
				final_start=start_index;
				gflag=true;
			}

		}

		if (gflag==true)
			break;
	}
	cout<<"0 0"<<endl;
}








