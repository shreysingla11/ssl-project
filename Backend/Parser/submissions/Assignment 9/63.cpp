#include<iostream>
#include<vector>
using namespace std;
class Node
{
public:
    int data;
    Node* left;
    Node* right;
    Node* formnode(list<int> li)
    {
        Node *result;
        //terminating case;
        if(li.front()>0)
        {
            result->data=v;
            dummy=new Node;
            dummy->data=0;
            dummy->left=NULL;
            dummy->right=NULL;
            result->left=dummy;
            li.pop_front();
            if(!li.empty())
            {
                result->right=formnode(li);
            }
            else
            {
                dummy=new Node;
                dummy->data=-1;
                dummy->left=NULL;
                dummy->right=NULL;
                result->right=dummy;
            }

        }
        else
        {
            result->data=v;
            dummy=new Node;
            dummy->data=0;
            dummy->left=NULL;
            dummy->right=NULL;
            result->right=dummy;
            li.pop_front();
            if(!li.empty())
            {
                result->left=formnode(li);
            }
            else
            {
                dummy=new Node;
                dummy->data=-1;
                dummy->left=NULL;
                dummy->right=NULL;
                result->left=dummy;
            }

        }
        return result;

    }
    Node* addNodes(Node* a)
    {
        if(data<a->data)
        {
            left->addNodes(a);
            right->addNodes(a);
        }
        else if(data==a->data)
        {
            left=left->addNodes(a->left);
            right=right->addNodes(a->right);
        }
        else
        {
            left=a->left->addNodes(this);
            right=a->right->addNodes(this);
        }
        return this;
    }
}
;

class boolfunc
{
public:
    Node *Tree;
public:
    boolfunc()
    {

        ;
    }
    ~boolfunc()
    {

        ;
    }
    boolfunc( boolfunc const &)
    {
        ;
    }
    void operator+=(boolfunc const &afunc)
    {
        tree = tree->addNodes(afunc->tree);
    }
    void operator*=(boolfunc const &)
    {

        ;
    }
    void operator~()
    {
        ;
    }
    bool operator==(boolfunc const &)
    {
        ;
    }
    void read()
    {
        int n,t,v;
        cin>>n;
        for(int lines=1; lines<=n; lines++)
        {
            boolfunc dummy;
            cin>>t;
            list<int> li;
            for(int i=0; i<t; i++)
            {
                boolfunc* temp = new boolfunc;
                cin>>v;
                li.push_back(v);
            }
            Node *temp = new Node;
            temp=temp.formnode(li);
            dummy->tree=temp;
            this=this+dummy;
            // boolfunc *temp
        }

        return ;
    }
    void print()
    {
        ;
    }
    void subst(int i, bool v)
    {
        ;
    }



};
