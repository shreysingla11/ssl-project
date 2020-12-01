#include <iostream>
#include <vector>
using namespace std;
class boolfunc
{
private:
  	int key_value;
  	boolfunc *left;
  	boolfunc *right;
  	boolfunc *fc;
public:
	vector<vector<int> > k;
	int terms,literals,A,B;
	boolfunc();
	~boolfunc();
	boolfunc( boolfunc const &f){
		fc=f.fc;
	}// - copy constructor
	void operator+=(boolfunc const &f){
/*		if(fc.key_value<=f.key_value){
			fc.left->key_value += f.left->key_value;
			fc.right->key_value += f.right->key_value;
		}
		else if(fc.key_value>f.key_value){
			fc.left;
		}*/
	}
	//- or operator
	void operator*=(boolfunc const &);// - and operator
	void operator~();// - not operation
	bool operator==(boolfunc const &){}
	// - check for equality.
	void read(){
		cin>>terms;
		k.resize(terms);
		for(int i=0;i<terms;i++){
			cin>>literals;
			k[i].resize(literals);
			for(int j=0;j<literals;j++){
				cin>>k[i][j];
			}
		}
	}/* - reads the function in sum of products form and
              constructs it binary tree representation.
			  You can read from cin.
			  The input format will be as follows.
			  The first line will give the number of terms.
			  For each term, the first line will give the
			  number of literals in the term.
			  The second line of a term will contain the
			  numbers of the variables that appear in the
			  term, in increasing order of number. If a
			  variable is in complemented form, it will
			  be represented by a negative number.
			  For example:
			  2
			  2
			  -1 2
			  2
			  1 -3
			  denotes the function x_1'x_2 + x_1x_3'

              The ordering of the terms should be the lexicographic
			  ordering of the literals in the terms (Terms including
			  x_1' should come  before terms including x_1). You need not
			  do any minimization of the formula.*/


	void print(){
		cout<<terms<<endl;
		for(int i=0;i<terms;i++){
			literals=k[i].size();
			cout<<literals<<endl;
			for(int j=0;j<literals;j++){
				cout<<k[i][j];
			}
			cout<<endl;
		}
	}// - prints out the function in the same format as the input.
	void subst(int i, bool v){}//- modifies the function by setting the value of x_i to v. This will be a new function independent of x_i.


};

