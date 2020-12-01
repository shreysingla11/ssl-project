#include <iostream>
using namespace std;

struct node
{
	int key_value;
	node *left;
	node *right;
};

class boolfunc
{
	private:
	
		node* root;
		
		node* copyHelper(const Node *toCopy)
		{
			if( toCopy == NULL )
			{
				return NULL;
			}
			node *copyNode = new node;
			copyNode->key_value = toCopy->key_value;
			copyNode->left = copyHelper(toCopy->left);
			copyNode->right = copyHelper(toCopy->right);
			return copyNode;
		}
		
	public:
	
		boolfunc()
		{  // the constructor does nothing here 
		}
		
		~boolfunc()
		{	// the destructor deletes the allocated memory
			boolfunc* B = new boolfunc;
			delete B; 
		}
		
		boolfunc( boolfunc const &toCopy)
		{
			root = copyHelper(toCopy.root);
		}
		
		void operator+=(boolfunc const &otherTree)
		{
			otherTree.root->key_value = root->key_value + otherTree.root->key_value;
		}
		
		void operator*=(boolfunc const &otherTree)
		{
			otherTree.root->key_value = root->key_value * otherTree.root->key_value;
		}
		
		void operator~()
		
		bool operator==(boolfunc const &otherTree)
		{
			if((root == NULL) && (otherTree.root == NULL))
			{
				return true; //two null trees are equal
			}
			else if((root != NULL) && (otherTree.root != NULL))
			{
				return ((root->key_value == otherTree.root->key_value) && (root->left == otherTree.root->left) &&
				(root->right == otherTree.root->right))
			}
			else
			{
				return false; //one tree is null the other is not
			}
		}
		
		void read()
		{
			int n;
			int x = 0;
			cin >> n;
			int y = 0;
			int A[ n ];
			int V[ 1000 ];
			for( int i = 0; i < n; i++ )
			{
				cin >> A[ i ];
				x = x + A[ i ];
				while( y < x )
				{
					cin >> V[ j ];
					y = y + 1;
				}
				
			}
				
		}
		void print()
		{
			
			
		}
		void subst(int i, bool v)
};
