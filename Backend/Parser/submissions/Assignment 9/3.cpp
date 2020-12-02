#include<iostream>
using namespace std;

class boolfunc {
	public:
	
	int data;
	
	 boolfunc(); //constructor
	 
	~boolfunc(); //destructor
	
	boolfunc( boolfunc const &) ; //copy 
	
	void operator += (boolfunc const &) ; // or operator
	
	void operator*=(boolfunc const &); //and operator
	
	void operator~(); //  not operation
	
	bool operator==(boolfunc const &); //  check for equality.
	
	void read() {
		
		 int n,m,x;
			  
			  cin>>n
			  
			  
			  for(int i=0;i<n;++){
			  
			  cin>>m;
			  
			  for(int i=0;i<m;i++){
			  
			  cin>>x;
			  
			  cout<<"x_"<<abs(x);
			  if(x<0){cout<<"'";}
			  
			  }
			  
			  if(i<n-1){
			  cout<<"+";}
			  
			  }
		
		
		
		
		
		};
	void print();
	void subst(int i, bool v);
	
	
	void insert (int val);
	boolfunc::boolfunc() {
		root=NULL;
		}
		
		
		void boolfunc::insert(int val) {
			if (root!=NULL)
			insert (val,root);
			else
			{root=new node ;
				root->data=val;
				root->left=NULL;
				root->right=NULL;
			
			
			}
		}
	
	private:
	   class node {
		 int data;
		 node *left;
		 node *right;
		   };
		   
 void boolfunc::destroy_tree(node *leaf) // function to destroy tree
{
  if(leaf!=NULL)
  {
    destroy_tree(leaf->left);
    destroy_tree(leaf->right);
    delete leaf;
  }
}   
		
		
		void copytree () {}  // copy the  binary tree
	// function to check if trees are equal or not	
		bool tree_compare (const node* t1, const node* t2) {

  if (t1 == t2)  return true;

  if ((t1 == NULL) || (t2 == NULL))  return false;

  // Do data checks and recursion of tree
  return ((t1->data == t2->data) && 
  tree_compare (t1->left,  t2->left ) && 
  tree_compare (t1->right, t2->right));
}
	};
