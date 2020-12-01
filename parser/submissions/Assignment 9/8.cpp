#include<iostream>
using namespace std;

//struct node{
// 	int num;
// 	node * left;
// 	node * right;
// };

class boolfunc{
    	int root;
    	boolfunc * left,* right;

    public:

    boolfunc(int n){
    	root=n;
    	left=NULL;
    	right=NULL;
    }

    boolfunc(){
    	left=NULL;
    	right=NULL;
	}

	~boolfunc(){
		if(left!= NULL)delete left;
		if(right!=NULL)delete right;
	}

	void operator+=(boolfunc const & tree){
		boolfunc temp=tree;
		if(root==0)
		{
			*this=tree;
			return;
		}

		if(tree.root==0 || root==-1)return;

		if(tree.root==-1)
		{
			root=-1;
			left=NULL;
			right=NULL;
			return;
		}

		if(root > tree.root)
		{
			*(temp.left)+=(*this);
			*(temp.right)+=(*this);
			*left=*temp.left;
			*right=*temp.right;
			return;
		}

		if(root < tree.root)
		{
			*left+=tree;
			*right+=tree;
			return;
		}

		if(root==tree.root)
		{
			*left+=*(temp.left);
			*right+=*(temp.right);
			return ;
		}
}

	void operator*=(boolfunc const & tree){
		boolfunc temp=tree;
		if(tree.root==0)
		{
			root=0;
			left=NULL;
			right=NULL;
			return;
		}

		if(root==-1)
		{
			*this=tree;
			return;
		}

		if(tree.root==-1 || root==0)return;

		if(root < tree.root)
		{
			*left*=tree;
			*right*=tree;
			return;
		}

		if(root > tree.root)
		{
			*(temp.left)*=(*this);
			*(temp.right)*=(*this);
			*left=*temp.left;
			*right=*temp.right;
			return;			
		}

		if(root == tree.root)
		{
			*left*=*(temp.left);
			*right*=*(temp.right);
			return ;
		}
	}

	void operator~(){

		if(root > 0){
			if(left != NULL){
				~(*left);
			}
			if(right != NULL){
				~(*right);
			}
		}
		else{
			if(root==-1)root=0;
			else root=-1;
		}

	}

	bool operator==(boolfunc const & tree){
		
	}

	void read(){

		int lines,terms,val;
		boolfunc * present=this;
		boolfunc tree;
		bool second=true;
		cin>>lines;
		for(int i=1;i<=lines;i++){
			
			cin>>terms;
			present->root=val;
			for(int j=1;j<=terms;j++){
				
				if(val > 0){
					present->left=new boolfunc(0);
					present->right=new boolfunc;
					present=present->right;
				}

				else{
					present->right=new boolfunc(0);
					present->left=new boolfunc;
					present=present->left;
				}
			}

			if(second==true){
				tree=(*this);
				second=false;
			}

			else{
				tree+=*this;
			}

		}

	}

	void print(){

	}

	void subst(int i, bool v){
		if(root==i)
		{
			delete left;
			delete right;
			left=right=NULL;
			if(v)
				root=-1;
			else root=0;
		}

		else
		{
			if(root>0)
			{
				(*left).subst(i,v);
				(*right).subst(i,v);
			}
			return;
		}
	}
};


