#include <iostream>

using namespace std;

class boolfunc {
private:
	int id; 
	boolfunc *left, *right;

public:
boolfunc() {
	id = -2;
	left = NULL;
	right = NULL;
}

boolfunc(int a) {
	id = a;
	left = NULL;
	right = NULL;
}

~boolfunc() {
	if (left != NULL)
		delete left;
	if (right != NULL)
		delete right;
}

boolfunc(boolfunc const & f) {
	if(left != NULL) {
		delete left;
	}
	if(right != NULL) {
		delete right;
	}
	left = new boolfunc;
	right = new boolfunc;

	id = f.id;
	left = f.left;
	right = f.right;
}

void operator+=(boolfunc const & f) {
	if(left != NULL) {
		delete left;
	}
	if(right != NULL) {
		delete right;
	}
	left = new boolfunc;
	right = new boolfunc;

	id = f.id;
	left = f.left;
	right = f.right;
}

void operator+=(boolfunc const &right) {
	if (right->id == 0) {
		return;
	}
	else if (right->id == -1) {
		id = -1;
		left = NULL;
		right = NULL;
	}
	else if (id == 0) {
		(*this) = (*right);
	}
	else if (id == -1) {
		id = -1;
		left = NULL;
		right = NULL;
	}
    else if (id == right->id) {
		*left += (*right->left);
		*right += (*right->right);
	}
	else if (id > right->id) {
		*left += (*right);
		*right += (*right);
	}
	else (id >= right->id) {
		boolfunc *temp_l = new boolfunc;
		boolfunc *temp_r = new boolfunc;

		temp_l = *this;
		temp_l += (*right.left);

		temp_r = *this;
		temp_r += (*right.right);

		if (left != NULL) {
			delete left;
		}
		left = temp_l;

		if (right != NULL) {
			delete right;
		}
		right = temp_r;
		temp.id = right->id;
	}
}

void operator*=(boolfunc const &) {
	if (right->id == 0) {
		id = 0;
		left = NULL;
		right = NULL;
	}
	else if (right->id == -1) {
		return;
	}
	else if (id == 0) {
		right = NULL;
		left = NULL;
	}
	else if (id == -1) {
		id = right.id;
		*left += (*right->left);
		*right += (*right->right);
	}
    else if (id == right->id) {
		*left *= (*right->left);
		*right *= (*right->right);
	}
	else if (id > right->id) {
		*left *= (*right);
		*right *= (*right);
	}
	else (id >= right->id) {
		boolfunc *temp_l = new boolfunc;
		boolfunc *temp_r = new boolfunc;

		temp_l = *this;
		temp_l *= (*right.left);

		temp_r = *this;
		temp_r *= (*right.right);

		if (left != NULL) {
			delete left;
		}
		left = temp_l;

		if (right != NULL) {
			delete right;
		}
		right = temp_r;
		temp.id = right->id;
	}
}

void operator~() {
	if (id > 0) {
		if (left != NULL) {
			~(*left);
		}
		if (right != NULL) {
			~(*right);
		}
	}
	else {
		id = -1 - id;
	}
}

bool operator==(boolfunc const &) {
	if(id == right.id) {

	}
	return 
} 

void read() {
	int no_of_terms, temp;
	cin >> no_of_terms;

	for (int i = 0; i < no_of_terms; i++) {
		boolfunc *temp_parent;
		boolfunc *curr;
		int n, x;
		cin >> n;
		
		if(id == -2) {
			curr = this;
			temp_parent = this;
		}
		else {
			curr = new boolfunc;
			temp_parent = curr;
		}

		for (int j = 0; j < n; j++) {
			cin >> x;
			if (x > 0) {
				curr->id = x;
				curr->left = new boolfunc(0);
				curr->right = new boolfunc;
				curr = curr->right;
			}
			else {
				curr->id = -x;
				curr->left = new boolfunc;
				curr->right = new boolfunc(0);
				curr = curr->left;
			}
		}

		curr = new boolfunc(1);
		if(temp_parent != NULL) {
			(*this) += (*temp_parent);
		}
	}
}

void print() {


}

void subst(int i, bool v) {

}

};
