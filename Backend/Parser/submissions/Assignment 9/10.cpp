#include <iostream>
#include <cstdlib>
using namespace std;

class boolfunc
{
 struct tree_node
        {
           tree_node* left;
           tree_node* right;
           int data;
        };

        tree_node* root;

public:
boolfunc();// constructor that does nothing
~boolfunc()// - destructor that should free all allocated memory
{
    delete root->right;
    delete root->right;
    delete root;
}
boolfunc( boolfunc const &f)// - copy constructor
{


}
void operator+=(boolfunc const &);//- or operator
void operator*=(boolfunc const &);// - and operator
void operator~();// - not operation;
bool operator==(boolfunc const &);// - check for equality.
void read();// - reads the function in sum of products form and constructs it binary tree representation.
void print();//- prints out the function in the same format as the input.
void subst(int i, bool v);//- modifies the function by setting the value  of x_i to v
void insert(int);
void remove(int);
bool isEmpty() const { return root==NULL; }
};

// Smaller elements go left
// larger elements go right
void boolfunc::insert(int d)
{
    tree_node* t = new tree_node;
    tree_node* parent;
    t->data = d;
    t->left = NULL;
    t->right = NULL;
    parent = NULL;

    // is this a new tree?
    if(isEmpty()) root = t;
    else
    {
        //Note: ALL insertions are as leaf nodes
        tree_node* curr;
        curr = root;
        // Find the Node's parent
        while(curr)
        {
            parent = curr;
            if(t->data > curr->data) curr = curr->right;
            else curr = curr->left;
        }

        if(t->data < parent->data)
           parent->left = t;
        else
           parent->right = t;
    }
}

void boolfunc::remove(int d)
{
    //Locate the element
    bool found = false;
    if(isEmpty())
    {
            return;
    }

    tree_node* curr;
    tree_node* parent;
    curr = root;

    while(curr != NULL)
    {
         if(curr->data == d)
         {
            found = true;
            break;
         }
         else
         {
             parent = curr;
             if(d>curr->data) curr = curr->right;
             else curr = curr->left;
         }
    }
    if(!found)
		 {return;}


		 // 3 cases :
    // 1. We're removing a leaf node
    // 2. We're removing a node with a single child
    // 3. we're removing a node with 2 children

    // Node with single child
    if((curr->left == NULL && curr->right != NULL)|| (curr->left != NULL
&& curr->right == NULL))
    {
       if(curr->left == NULL && curr->right != NULL)
       {
           if(parent->left == curr)
           {
             parent->left = curr->right;
             delete curr;
           }
           else
           {
             parent->right = curr->right;
             delete curr;
           }
       }
       else // left child present, no right child
       {
          if(parent->left == curr)
           {
             parent->left = curr->left;
             delete curr;
           }
           else
           {
             parent->right = curr->left;
             delete curr;
           }
       }
     return;
    }
		 //We're looking at a leaf node
		 if( curr->left == NULL && curr->right == NULL)
    {
        if(parent->left == curr) parent->left = NULL;
        else parent->right = NULL;
		 		 delete curr;
		 		 return;
    }

    //Node with 2 children
    // replace node with smallest value in right subtree
    if (curr->left != NULL && curr->right != NULL)
    {
        tree_node* chkr;
        chkr = curr->right;
        if((chkr->left == NULL) && (chkr->right == NULL))
        {
            curr = chkr;
            delete chkr;
            curr->right = NULL;
        }
        else // right child has children
        {
            //if the node's right child has a left child
            // Move all the way down left to locate smallest element

            if((curr->right)->left != NULL)
            {
                tree_node* lcurr;
                tree_node* lcurrp;
                lcurrp = curr->right;
                lcurr = (curr->right)->left;
                while(lcurr->left != NULL)
                {
                   lcurrp = lcurr;
                   lcurr = lcurr->left;
                }
		curr->data = lcurr->data;
                delete lcurr;
                lcurrp->left = NULL;
           }
           else
           {
               tree_node* tmp;
               tmp = curr->right;
               curr->data = tmp->data;
	       curr->right = tmp->right;
               delete tmp;
           }

        }
		 return;
    }

}

int main()
{

return 0;}
