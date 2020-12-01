#include <iostream>
#include <vector>

using namespace std;


class boolfunc
{
	public:
	int var; // 0 is 0 // -1 is 1 // rest are var nums
	boolfunc* left; boolfunc* right; //left is x_var' and right is x_var

	boolfunc()
	{
		left = NULL; right = NULL;
	}
	boolfunc(int a)
	{
		var = a;
		left = NULL; right = NULL;
	}

	~boolfunc()
	{
		if(left != NULL)
			delete left;
		if(right != NULL)
			delete right;
	}

	boolfunc(boolfunc const & doosraf)
	{
		var = doosraf.var;

		if(doosraf.left != NULL)
			left = new boolfunc(*(doosraf.left));
		if(doosraf.right != NULL)
			right = new boolfunc(*(doosraf.right));
	}

	void operator=(boolfunc const & doosraf)
	{
		var = doosraf.var;

		if(doosraf.left != NULL)
			left = new boolfunc(*(doosraf.left));
		if(doosraf.right != NULL)
			right = new boolfunc(*(doosraf.right));
	}

	void operator+=(boolfunc const & doosraf)
	{
		//basecases
		if(doosraf.var == 0)
			return;

		else if(var == -1 || doosraf.var == -1)
		{
			var = -1;
			delete right; delete left;
			return;
		}
		else if (var == 0)
		{
			*this = doosraf; //copy constructor?
			return;
		}

		//recursion
		if(var == doosraf.var)
		{
			*left += *(doosraf.left);
			*right += *(doosraf.right);
		}
		else if (var < doosraf.var)
		{
			*left += doosraf;
			*right += doosraf;
		}
		else
		{
			boolfunc * newfunc = new boolfunc;
			boolfunc * newfunc2 = new boolfunc;
			newfunc->var = var; newfunc->left = left; newfunc->right = right;
			newfunc2->var = var; newfunc2->left = left; newfunc2->right = right;
			var--; delete left; delete right;
			left = newfunc; right = newfunc;

			*this += doosraf;
		}
	}

	void operator*=(boolfunc const & doosraf)
	{
		//basecases
		if(doosraf.var == -1)
			return;

		else if(var == 0 || doosraf.var == 0)
		{
			var = 0;
			delete right; delete left;
			return;
		}
		else if (var == -1)
		{
			*this = doosraf; //copy constructor?
			return;
		}

		//recursion
		if(var == doosraf.var)
		{
			*left *= *(doosraf.left);
			*right *= *(doosraf.right);
		}
		else if (var < doosraf.var)
		{
			*left *= doosraf;
			*right *= doosraf;
		}
		else
		{
			boolfunc * newfunc = new boolfunc;
			newfunc-> var = var; newfunc->left = left; newfunc->right = right;
			var--; delete left; delete right;
			left = newfunc; right = newfunc;

			*this *= doosraf;
		}
	}

	bool operator==(boolfunc const & doosraf)
	{
		if(var == 0 && doosraf.var == 0)
			return true;
		if(var == -1 && doosraf.var == -1)
			return true;

		if(var == doosraf.var)
			return (*left == *doosraf.left) && (*right == *doosraf.right);
		else
			return false;
	}

	void operator~()
	{
		if(var > 0)
		{
			if(left != NULL)
				~(*left);
			if(right != NULL)
				~(*right);
		}
		else if (var == 0)
			var = -1;
		else
			var = 0;
	}

	void read()
	{
		int N, M, x; cin>>N;
		boolfunc* curr; boolfunc* head;

		for (int i = 0; i < N; ++i)
		{
			cin>>M;
			head = new boolfunc;
			curr = head;

			for (int j = 0; j < M; ++j)
			{
				cin>>x;
				if(x > 0)
				{
					curr->var = x;
					curr->left = new boolfunc(0);
					curr->right = new boolfunc();
					curr = curr->right;
				}
				else
				{
					//cout<<"asd";
					curr->var = -x;
					curr->right = new boolfunc(0);
					curr->left = new boolfunc();
					curr = curr->left;
				}
			}
			curr->var = -1;
			//*this += *head;

			delete head;
		}
	}

	void print()
	{
		// FIND n
		vector<int> x;
		printx(x);
	}

	void printx(vector<int> &x)
	{
		if((left->var == 0 || left->var == -1) || (right->var == 0 || right->var == -1))
		{
			x.push_back(var);
			cout<<x.size()<<endl;
			for (int i = 0; i < x.size(); ++i)
			{
				cout<<x[i]<<" ";
			}
			cout<<endl;

			return;
		}

		if(left != NULL)
		{
			x.push_back(-var);
			left->printx(x);
		}
		x.pop_back();

		if(right != NULL)
		{
			x.push_back(var);
			right->printx(x);
		}
		x.pop_back();

	}

	void subst(int i, bool v)
	{
		if(var == i)
			if (v)
				var = -1;
			else
				var = 0;

		if(left != NULL)
			left->subst(i,v);
		if(right != NULL)
			right->subst(i,v);
	}

};

int main()
{
    boolfunc A;
    A.read();
    cout<<"Printing"<<endl;
    A.print();
	return 0;
}
