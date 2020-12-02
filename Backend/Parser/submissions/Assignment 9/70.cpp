#include <iostream>

using namespace std;

class boolfunc {

public:
	int value;
	boolfunc* left = NULL;
	boolfunc* right = NULL;
	int ones;

	void destroy() {
		if (left!=NULL) {
			if (left->value==0 || left->value == -1) {
				delete left;
			}
			else {
				left->destroy();
				left->value = 0;
				delete left;
			}
		}
		if (right!=NULL) {
			if (right->value==0 || right->value == -1) {
				delete right;
			}
			else {
				right->destroy();
				right->value = 0;
				delete right;
			}
		}
		//delete this;
	}



	boolfunc() {

	}

	~boolfunc() {
		destroy();
	}

	boolfunc( boolfunc const & bf) {
		value = bf.value;

		if (bf.left != NULL) {
			left = new boolfunc(*(bf.left));
		}
		else {
			left = NULL;
		}

		if (bf.right != NULL) {
			right = new boolfunc(*(bf.right));
		}
		else {
			right = NULL;
		}
	}

	void operator+=(boolfunc const & bf) {\

		if (bf.value == 0) {
			return;
		}
		if (bf.value == -1) {
			value = -1;
			left->destroy();
			right->destroy();
			delete left;
			delete right;
			return;
		}

		if (value == bf.value) {
			if (value > 0) {

				(*left) += (*bf.left);
				(*right) += (*bf.right);

			}
			else if (value == 0 || value == -1) {
				
			}

		}
		else if (value < bf.value){
			if (value > 0) {
				(*left) += bf;
				(*right) += bf;
			}
			else if (value == 0) {
				left = new boolfunc(bf);

			}
			else if (value == -1) {

			}
		}
		else if (value > bf.value){
			boolfunc* temp = this;
			value = bf.value;
			left = new boolfunc(*(bf.left));
			right = new boolfunc(*(bf.right));
			(*left) += (*temp);
			(*right) += (*temp);
			(*temp).destroy();
			delete temp;
		}

		return;

	}

	void operator*=(boolfunc const & bf) {

		if (bf.value == -1) {
			return;
		}
		if (bf.value == 0) {
			value = -1;
			left->destroy();
			right->destroy();
			return;
		}

		if (value == bf.value) {
			if (value > 0) {

				(*left) *= (*bf.left);
				(*right) *= (*bf.right);

			}
			else if (value == 0 || value == -1) {
				
			}

		}
		else if (value < bf.value){
			if (value > 0) {
				(*left) *= bf;
				(*right) *= bf;
			}
			else if (value == 0) {
				

			}
			else if (value == -1) {
				left = new boolfunc(bf);
			}
		}
		else if (value > bf.value){
			boolfunc* temp = this;
			value = bf.value;
			left = new boolfunc(*(bf.left));
			right = new boolfunc(*(bf.right));
			(*left) *= (*temp);
			(*right) *= (*temp);
			(*temp).destroy();
			delete temp;
		}

		return;

	}

	void operator~() {
		if (value == 1) {
			value = 0;
			return;
		}
		if (value == 0) {
			value = 1;
			return;
		}
		boolfunc* t1 = new boolfunc(*left);
		boolfunc* t2 = new boolfunc(*right);
		~(*t1);
		~(*t2);
		~(*left);
		~(*right);
		(*t1)*=(*t2);
		(*left)+=(*t1);
		(*right)+=(*t1);
		(*t1).destroy();
		(*t2).destroy();
		delete t1;
		delete t2;

	}

	bool operator==(boolfunc const & bf) {

	}

	void read() {
		int t, p, v;
		boolfunc* a = new boolfunc();
		a->value = 0;
		boolfunc* b, *c;
		cin>>t;
		for (int i=0; i<t; i++) {
			b = new boolfunc();
			b->value = 1;
			cin>>p;
			for (int j=0; j<p; j++) {
				cin>>v;
				c = new boolfunc();
				
				if (v < 0) {
					c->value = -v;					
					c->left = new boolfunc();
					c->right = new boolfunc();
					(*c->left).value = 1;
					(*c->right).value = 0;
				}
				else if (v > 0) {
					c->value = v;					
					c->left = new boolfunc();
					c->right = new boolfunc();
					(*c->left).value = 0;
					(*c->right).value = 1;
				}

				(*b)*=(*c);
				(*c).destroy();
				delete c;
			}
			(*a)+=(*b);
			(*b).destroy();
			delete b;
			
		}

		value = a->value;
		left = new boolfunc(*(a->left));
		right = new boolfunc(*(a->right));
		(*a).destroy();
		delete a;
	}

	void print() {
		ones = 0;
		check(*this);
		cout<<ones<<endl;
	}

	void check(boolfunc const & bf) {
		if (bf.value == 1) {
			ones++;
		}
		else if (bf.value == 0) {

		}
		else {
			check(*left);
			check(*right);
		}
	}

	void subst(int i, bool v) {

	}




};



int main() {
	
	boolfunc(b);
	b.read();
	//b.print();
	return 0;
}