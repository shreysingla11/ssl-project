#include <iostream>

using namespace std;

class boolfunc
{
public:
	int root;
	boolfunc *left,*right;
	boolfunc()
	{
		root=-2;
		left=NULL;
		right=NULL;
	}
	boolfunc(int a)
	{
		root=a;
		left=NULL;
		right=NULL;
	}
	void operator*=(boolfunc const & tree)
	{
		boolfunc temp=tree;
		if(root==-1)
		{
			*this=tree;
			return;
		}
		else if(tree.root==-1 || root==0)
			return;
		else if(tree.root==0)
		{
			root=0;
			left=right=NULL;
			return;
		}
		else if(root < tree.root) 
		{
			*left*=tree;
			*right*=tree;
		}
		else if(root > tree.root)
		{
			*(temp.left)*=*this;
			*(temp.right)*=*this;
			*left=*(temp.left);
			*right=*(temp.right);
		}
		else if(root = tree.root)
		{
			(*left)*=*(temp.left);
			(*right)*=*(temp.right);
		}
		return;
	}

	void operator+=(boolfunc const & tree)
	{
		boolfunc temp=tree;
		if(root==0)
		{
			*this=tree;
			return;
		}
		else if(tree.root==0 || root==-1)
			return;
		else if(tree.root==-1)
		{
			root=-1;
			left=right=NULL;
			return;
		}
		else if(root < tree.root) 
		{
			*left+=tree;
			*right+=tree;
		}
		else if(root > tree.root)
		{
			*(temp.left)+=*this;
			*(temp.right)+=*this;
			left=temp.left;
			right=temp.right;
		}
		else if(root = tree.root)
		{
			*left+=*(temp.left);
			*right+=*(temp.right);
		}
		return;

	}

	void operator~()
	{
		if(root>0)
		{
			~(*left);
			~(*right);
		}
		else if (root==-1)
			root=0;
		else
			root=-1;	
		return;
	}

	void read()
	{
		int n_terms,n_variables,var;
		boolfunc* present;
		boolfunc tree;
		bool second=true;
		cin>>n_terms;
		while(n_terms--)
		{
			cin>>n_variables;
			present=this;
			while(n_variables--)
			{
				cin>>var;
				if(var>0)
				{
					present->root=var;
					present->left=new boolfunc(0);
					present->right=new boolfunc;
					present=present->right;
				}
				else
				{
					present->root=-var;
					present->right=new boolfunc(0);
					present->left=new boolfunc;
					present=present->left;
				}
			}
			if(second)
			{
				tree=*this;
				second=false;
			}
			else
				tree+=*this;
		}
		*this=tree;
		return;
	}
	void print()
	{



	}

	void subst(int i,bool v)
	{
		if(root==i)
		{
			delete left;
			delete right;
			left=right=NULL;
			if(v)
				root=-1;
			else 
				root=0;
		}
		else if(root > 0)
		{
			(*left).subst(i,v);
			(*right).subst(i,v);
		} 
		return;
	}
};
// int main()
// {
// 	return 0;
// }
