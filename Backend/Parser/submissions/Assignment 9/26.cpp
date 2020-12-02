#include <iostream>
#include<vector>
using namespace std;

struct node
{
    int id;
    node* left;
    node* right;
    node* copyit()
    {
        node* result = new node;
        result->id = id;
        if (left!=NULL&&right!=NULL)
        {
            result->left = left->copyit();
            result->right = right->copyit();
        }
        else
        {
            result->left = NULL;
            result->right = NULL;
        }
        return result;
    }
    ~node()
    {
        delete left;
        delete right;
    }
    node* add(node* x)
    {
        if (id<=0)
        {
            if((x->id)<=0)
            {
                if (id==0&&x->id == 0) id = 0;
                else id =-1;
                left = NULL;
                right = NULL;
            }
            else
            {
                if (id == -1)
                {
                    id = -1;
                    left = NULL;
                    right = NULL;
                }
                else
                {
                    id = x->id;
                    left = x->left;
                    right = x->right;
                }

            }


        }
        else if ((x->id)<=0)
        {
            if ((x->id)==-1)
            {
                id = -1;
                left = NULL;
                right = NULL;
            }
            else
            {
                //do nothing
            }
        }
        else if (id == x->id)
        {
            left = left->add(x->left);
            right = right->add(x->right);
        }
        else if (id < (x->id))
        {
            left = left->add(x);
            right = right->add(x);
        }
        else
        {

            node* first = copyit();
            node* second = copyit();
            first->id = id;
            first->left = left;
            first->right = right;
            second->id = id;
            second->left = left;
            second->right = right;
            left = first->add(x->left);
            right = second->add(x->right);
        }
        return this;

    }
    node* multiply(node* x)
    {
        if (id<=0)
        {
            if((x->id)<=0)
            {
                if (id==-1&&x->id == -1) id = -1;
                else id =0;
                left = NULL;
                right = NULL;
            }
            else
            {
                if (id == 0)
                {
                    id = 0;
                    left = NULL;
                    right = NULL;
                }
                else
                {
                    id = x->id;
                    left = x->left;
                    right = x->right;
                }

            }


        }
        else if ((x->id)<=0)
        {
            if ((x->id)==0)
            {
                id = 0;
                left = NULL;
                right = NULL;
            }
            else
            {
                //do nothing
            }
        }
        else if (id == x->id)
        {
            left = left->multiply(x->left);
            right = right->multiply(x->right);
        }
        else if (id < (x->id))
        {
            left = left->multiply(x);
            right = right->multiply(x);
        }
        else
        {

            node* first = copyit();
            node* second = copyit();
            first->id = id;
            first->left = left;
            first->right = right;
            second->id = id;
            second->left = left;
            second->right = right;
            left = first->multiply(x->left);
            right = second->multiply(x->right);
        }
        return this;

    }
    void invert()
    {
        if (left!=NULL&&right!=NULL)
        {
            left->invert();
            right->invert();
        }
        return;
    }
    vector<vector <int> > getNumbers()
    {   vector<vector<int> > ::iterator it;
        vector<vector<int> > l,r;
        if (id>0){

        l = left->getNumbers();
        r = right->getNumbers();
        for (it = l.begin();it!=l.end();it++){
            (*it).insert((*it).begin(),-id);
        }
        for (it = r.begin();it<r.end();it++){
            (*it).insert((*it).begin(),id);
        }
        l.insert(l.end(),r.begin(),r.end());}
        else if (id==-1){
            vector<int> a;
            l.push_back(a);
        }
        return l;
    }
    void print(vector<vector <int > >printable)
    {
        cout<<printable.size();
    }
};

class boolfunc
{

    node* root;
    boolfunc()
    {
    }
    boolfunc (boolfunc const& a)
    {
        root = (a.root)->copyit();
    }

    void operator +=(boolfunc const & a)
    {

        root = root->add(a.root);

    }
    void operator *= (boolfunc const &a)
    {
        root = root->multiply(a.root);
    }
    ~boolfunc()
    {
        delete root;
    }
    void operator~()
    {
        root->invert();
    }
    void print()
    {   vector<vector <int > > printable;
        printable = root-> getnumbers();
        root->print(printable);
    }

};
int main()
{
    return 0;
}
