#include <iostream>
#include <vector>

using namespace std;

class node
{
public:
	int variable;
	node *left;
	node *right;
	node()
	{
		variable =0;
	}
	~node()
	{
		if(left!=NULL)
		{
			delete left;
		}
		if (right!=NULL)
		{
			delete right;
		} 
	}
	node( node const &a)
	{
		variable = a.variable;
		left = a.left;
		right = a.right;
	}
	node* mult_op(node * brother)
	{
		if(variable==-1) 
			return brother;
		if(variable == 0)
			return this;
		if(brother->variable==0)
			return brother;
		if(brother->variable==-1)
			return this;
		if(brother->variable == variable)
		{
			left = mult_op(brother->left);
			right = mult_op(brother->right);
			return this;
		}
		else if(brother->variable > variable)
		{
			node* tempNode1 = new node;
			node* tempnode2 = new node;
		}
		else
		{
			left = mult_op(brother);
			right = mult_op(brother);
			return this;
		}
	}

	node* add_op(node * brother)
	{
		if(variable==-1)
			return brother;
		if(variable == 0)
			return this;
		if(brother->variable==0)
			return brother;
		if(brother->variable==-1)
			return this;
		if(brother->variable == variable)
		{

		}
		else if(brother->variable > variable)
		{

		}
		else
		{

		}
	}
};






class boolfunc
{
public:
	node* root;
private:
	node* copy(const node* toCopy)
	{
		if (toCopy==NULL)
		{
			return NULL;
		}
		else
		{
			node* newNode = new node;
			newNode->variable = toCopy->variable;	
			newNode->left = copy(toCopy->left);
			newNode->right = copy(toCopy->right);
			return newNode;
		}
	}
	void ReverseTree(node* root)
	{
		node* tmp = root->left;
		root->left = root->right;
		root->right = tmp;

	    if(root->left != null)
	    	ReverseTree(root->left);
	    if(root->right != null)
	    	ReverseTree(root->light);
	}
	void snub(node* mynode,int i,bool v)
	{
		if(mynode==NULL)
		{
			return;
		}
		else
		{
			if(mynode->left!=NULL)
			{
				if(mynode->left->variable == i)
				{
					if(v)
					{
						mynode = mynode->left->left;
					}
					else
					{
						mynode = mynode->left->right;
					}
				}
				else
				{
					snub(mynode->left,i,v);
				}
			}
			if (mynode->right!=NULL)
			{
				if(mynode->right->variable == i)
				{
					if (v)
					{
						mynode = mynode->right->left;
					}
					else
					{
						mynode = mynode->right->right;
					}
				}
				else
				{
					snub(mynode->right,i,v);
				}
			}
		}
	}
	bool check(const node* toCheck,const node* tocompare)
	{
		if(toCheck==NULL || tocompare == NULL)
		{
			if(toCheck==NULL && tocompare == NULL)
				return true;
			else
				return false;
		}
		else
		{
			if(toCheck->variable==tocompare->variable)
			{
				return (check(toCheck->left,tocompare->left) && check(toCheck->right,tocompare->right))
			}
			else
			{
				return false;
			}
		}
	}
	std::vector<int> printhelp();
public:
	boolfunc();
	~boolfunc()
	{
		if(root != NULL)
		{
			delete root;
		}
	}
	boolfunc( boolfunc const &a)
	{
		if(a == NULL)
		{
			root = NULL;
		}
		root = copy(a.root);
	}
	void operator+=(node const &a)
	{
		return;
	}
	void operator*=(boolfunc const &a)
	{

		return;
	}
	void operator~()
	{
		ReverseTree(root);
		return;
	}
	bool operator==(boolfunc const &a)
	{
		return check(a.root,root);
	}
	void read()
	{
		int terms;
		int no_terms,temp;
		cin>>terms;
		std::vector<int> temp_v;
		std::vector<std::vector<int> > v;
		for (int i = 0; i < terms; ++i)
		{
			cin>>no_terms;
			for (int j = 0; j < no_terms; ++j)
			{
				cin>>temp;
				temp_v.push_back(temp);
			}
			v[i].push_back(temp_v);
		}

	}
	void print()
	{

	}
	void subst(int i, bool v)
	{

	}
};