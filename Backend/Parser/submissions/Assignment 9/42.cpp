#include <iostream>
using namespace std;
class boolfunc
{
public:
	int n;
	boolfunc *left;
	boolfunc *right;	
	boolfunc()
	{

	}
	~boolfunc()
	{
		if (n == 0 || n == -1)
		{
			return;
		}
		else
		{
			delete left;
			left = NULL;
			delete right;
			right = NULL;
		}
	}
	boolfunc(boolfunc const& f)
	{
		n = f.n;
		if (f.n == 0 || f.n == -1)
		{
			left = NULL;
			right = NULL;
		}
		else if (f.left == NULL)
		{
			right = new boolfunc(*(f.right));
			left = NULL;
		}
		else if (f.right == NULL)
		{
			left = new boolfunc(*(f.left));
			right = NULL;
		}
		else
		{
			left = new boolfunc(*(f.left));
			right = new boolfunc(*(f.right));
		}
	}
	void operator+=(boolfunc const& f)
	{
		if (f.n == 0)
		{
			return;
		}
		if (f.n == -1)
		{
			n = -1;
			delete left;
			delete right;
			return;
		}
		if (n == 0)
		{
			(*this) = f;
			return;
		}
		if (n == -1)
		{
			n = -1;
			delete left;
			delete right;
			return;
		}
		if (n == f.n)
		{
			(*left) += *(f.left);
			(*right) += *(f.right);
		}
		else if (n < f.n)
		{
			(*left) += f;
			(*right) += f;
		}
		else
		{
			boolfunc *b = new boolfunc(f);
			*(b->left) += (*this);
			*(b->right) += (*this);
			(*this)  = (*b);
			delete b;
		}
	}
	void operator*=(boolfunc const& f)
	{
		if (f.n == -1)
		{
			return;
		}
		if (f.n == 0)
		{
			n = 0;
			delete left;
			delete right;
			return;
		}
		if (n == -1)
		{
			(*this) = f;
			return;
		}
		if (n == 0)
		{
			n = 0;
			delete left;
			delete right;
			return;
		}
		if (n == f.n)
		{
			(*left) *= *(f.left);
			(*right) *= *(f.right);
		}
		else if (n < f.n)
		{
			(*left) *= f;
			(*right) *= f;
		}
		else
		{
			boolfunc *b = new boolfunc(f);
			*(b->left) *= (*this);
			*(b->right) *= (*this);
			(*this)  = (*b);
			delete b;
		}
	}
	void operator~()
	{
		if (n == 0)
		{
			n == -1;
			return;
		}
		if (n == -1) 
		{
			n = 0;
			return;
		}
		~(*left);
		~(*right);
		boolfunc *b = new boolfunc(*right);
		(*b) *= (*left);
		(*this) += (*b);
		delete b;
	}
	void operator==(boolfunc const&)
	{

	}
	void read()
	{
		int t, n;
		boolfunc *b = new boolfunc;
		boolfunc *temp = new boolfunc;
		cin >> t;
		while (t--)
		{
			cin >> n;
			if (n < 0)
			{
				temp->n = n;
				temp->left = new boolfunc;
				temp->right = new boolfunc;
				temp->left->n = -1;
				temp->right->n = 0;
				temp->left->left = temp->right->left = NULL;
				temp->left->right = temp->right->right = NULL;
			}
			else if (n > 0)
			{
				temp->n = n;
				temp->left = new boolfunc;
				temp->right = new boolfunc;
				temp->left->n = 0;
				temp->right->n = -1;
				temp->left->left = temp->right->left = NULL;
				temp->left->right = temp->right->right = NULL;
			}
		}
	}
	void print()
	{

	}
	void subst(int i, bool v)
	{

	}
};
int main()
{
	boolfunc b1;
	b1.n = -1;
	b1.left = b1.right = NULL;
	cout << "hey" << endl;
	boolfunc *b2 = new boolfunc(b1);
	b1.n = 0;
	b2->left = b2->right = NULL;
	cout << "hey1" << endl;
	b1 += *b2;
	b2->read();
	cout << b1.n << b2->n << endl;
	return 0;
}