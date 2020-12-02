#include <iostream>
#include <vector>
using namespace std;

class boolfunc;

class node
{
    public : int index;
	public : boolfunc *left, *right;

	node(int index, boolfunc *left, boolfunc *right)
	{
		this->index = index;
		this->left = left;
		this->right = right;
	}

	node()
	{
        node(-2, NULL, NULL);
	}
};

node zeroNode(0, NULL, NULL);
/*zeroNode.index = 0;
zeroNode.left = NULL;
zeroNode.right = NULL;*/

node oneNode(0, NULL, NULL);
/*oneNode.index = -1;
oneNode.left = NULL;
oneNode.right = NULL;*/
node createTree (int n, vector<int> literals, vector< vector<int> > treein, int index);

class boolfunc
{
public : node root;
	//int n;
	void read ()
	{
		int n;
		cin>>n;
		vector< vector<int> > treein;
		vector<int> literals;
		treein.resize(n);
		literals.resize(n);
		for (int i=0; i<n; i++)
		{
			cin>>literals[i];
			treein[i].resize(literals[i]);
			for (int j=0; j<literals[i]; j++)
			{
				cin>>treein[i][j];
			}
		}

		root = createTree(n, literals, treein, 1);
	};

	void printTree()
	{
		//cout<<n<<endl;

	};

    boolfunc()
    {

    }

	boolfunc(boolfunc &g)
	{
		(this->root).index = (g.root).index;

		delete (this->root).left;
		delete (this->root).right;
		((this->root).left)= new boolfunc (*((g.root).left));
		((this->root).right)= new boolfunc (*((g.root).right));
	}

	~boolfunc()
	{
		delete (this->root).left;
		delete (this->root).right;
	}

	void operator=(boolfunc &g)
	{
		(this->root).index = (g.root).index;

		delete (this->root).left;
		delete (this->root).right;
		((this->root).left)= new boolfunc (*((g.root).left));
		((this->root).right)= new boolfunc (*((g.root).right));

	}

	void operator+=(boolfunc const & g)
	{
		if ((g.root).index == 0)
		{
			return;
		}
		else if ((g.root).index == -1)
		{
			(this->root).index = -1;
			((this->root).left) = NULL;
			((this->root).right) = NULL;
			return;
		}

		else if ((this->root).index == -1)
		{
			return;
		}

		else if ((this->root).index == -1)
		{

		}

		else if ((this->root).index == (g.root).index )
		{
			*((this->root).left)+=*((g.root).left);
			*((this->root).right)+=*((g.root).right);
		}

		else if ((this->root).index < (g.root).index)
		{
			*((this->root).left)+=g;
			*((this->root).right)+=g;
		}

		else
		{
			boolfunc temp = *(this);
			(this->root).index = (g.root).index;
			*((this->root).left) = temp;
			*((this->root).right) = temp;
			*((this->root).left)+=*((g.root).left);
			*((this->root).right)+=*((g.root).right);

		}
	}

	void operator*=(boolfunc const &g)
	{
		
	}

	void operator~()
	{
		if (root.index == -1)
		{
			root.index = 0;
		}
		else if (root.index == 0)
		{
			root.index = -1;
		}

		else
		{
			~(*(root.left));
			~(*(root.right));
		}
	};
};

node createTree (int n, vector<int> literals, vector< vector<int> > treein, int index)
{
	node N;
	N.index = index;
	N.left = new boolfunc;
	N.right = new boolfunc;
	vector< vector<int> > treeLeft;
	vector< vector<int> > treeRight;
	vector<int> literalsLeft;
	vector<int> literalsRight;
	int countLeft;
	int countRight;
	bool flagLeft = false;
	bool flagRight = false;
	for (int i=0; i<n; i++)
	{
		if (treein[i][0] != index)
		{
			if (treein[i][0] == -1*index)
			{
				vector<int>::iterator it;
  				it=treein[i].begin()+1;

  				if (it != treein[i].end())
				{
					vector<int> temp;
					for (it; it!= treein[i].end(); it++)
					{
						temp.push_back(*it);
					}
					treeLeft.push_back(temp);
					literalsLeft.push_back(literals[i]-1);
				}
				else
				{
					//*(N.left) = oneNode;
					flagLeft = true;
				}
			}
			else
			{
				treeLeft.push_back(treein[i]);
				literalsLeft.push_back(literals[i]);
			}
			countLeft++;
		}

		if (treein[i][0] != -1*index)
		{
			if (treein[i][0] == index)
			{
				vector<int>::iterator it;
  				it=treein[i].begin()+1;

				if (it != treein[i].end())
				{	vector<int> temp;
					for (it; it!= treein[i].end(); it++)
					{
						temp.push_back(*it);
					}
					treeLeft.push_back(temp);
					literalsLeft.push_back(literals[i]-1);
				}
				else
				{
					flagRight = true;
				}
			}
			else
			{
				treeLeft.push_back(treein[i]);
				literalsLeft.push_back(literals[i]);
			}
			countRight++;
		}
	}

	if (flagLeft)
	{
		(*(N.left)).root = oneNode;
	}

	else if (countLeft == 0)
	{
		(*(N.left)).root = zeroNode;
	}

	else
		(*(N.left)).root = createTree(countLeft, literalsLeft, treeLeft, index+1);

	if (flagRight)
	{
		(*(N.right)).root = oneNode;
	}

	else if (countRight == 0)
	{
		(*(N.right)).root = zeroNode;
	}

	else
		(*(N.right)).root = createTree(countRight, literalsRight, treeRight, index+1);

	return N;
}
