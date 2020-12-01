#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<list>
#include<string.h>

using namespace std;


struct node
{
  int key_value;
  node *left;
  node *right;
};

class boolfunc{
    public:
    boolfunc();
    ~boolfunc();

    int n;
    list <string> l;
    boolfunc( boolfunc const &);
    void operator+=(boolfunc const &); //OR Operator
    void operator*=(boolfunc const &); //AND Operator
    void operator~();
    bool operator==(boolfunc const &);
    void read();
    void print();
    void subst(int i, bool v);

    private:
    void destroy_tree(node *leaf);
    node *root;
    bool check_equality(node *left,node *right);
};

boolfunc::boolfunc()
{
    n=0;
    root = NULL;
}

boolfunc::~boolfunc()
{
    destroy_tree(root);
}

void boolfunc::destroy_tree(node *leaf)
{
if(leaf!=NULL)
  {
    destroy_tree(leaf->left);
    destroy_tree(leaf->right);
    delete leaf;
  }
}

bool boolfunc::check_equality(node *l,node *r)
{
    l=root->left;
    r=root->right;
    if(l->key_value == r->key_value)
    {
        destroy_tree(l);
        root=r;
        return true;
    }
    else return false;
}

bool boolfunc::operator==(boolfunc const &)
{
    if(root->left == root->right){
        return true;
    }
    else return false;
}

void boolfunc::operator*=(boolfunc const &)
{
    node *next = root;
    while((next->key_value==0) || (next->key_value==-1)){
        node *next = root->left;
        n++;
    }
}

void boolfunc::read(){

}






