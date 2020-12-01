#include<iostream>
#include<cstdlib>
using namespace std;
class node
{public:
    int index;
    bool value;
    node()
    {
        value = false;
    }
};
class boolfunc
{
    //int n;
//int t;
    node root;
    boolfunc* left;
    boolfunc* right;

public :
    boolfunc()
    {
        left=NULL;
        right=NULL;

    } ///- constructor that does nothing
    ~boolfunc()
    {
        delete left;
        delete right;
    } ///- destructor that should free all allocated memory
    boolfunc( boolfunc const & a)
    {

        root = a.root;
        if(a.left == NULL)
        {
            return ;
        }
        left = new boolfunc(*left);
        right = new boolfunc(*right);
           return ;
    } ///- copy constructor
    void operator+=(boolfunc const & a)
    {
        boolfunc * temp =left;

        if(left==NULL && a.left == NULL)
        {
            root.value = (root.value || (a.root).value);
            return;
        }
        if(a.left==NULL || a.right == NULL)
        {

            if(!(a.root).value)
            {


            }
            else
            {
                root = a.root;
                left =  new boolfunc(*(a.left));
                right =  new boolfunc(*(a.right));
                //left= new boolfunc(*left);
                //right = new boolfunc(*right);

            }

            return;
        }
        if(left  == NULL || right == NULL )
        {


            if(root.value)
            {

            }
            else
            {

                 root = a.root;
                left =  new boolfunc(*(a.left));
                right =  new boolfunc(*(a.right));

            }


            return;
        }
        if(root.index == (a.root).index)
        {
            (*left)+=*(a.left);
            (*right)+=*(a.right);
            return;
        }
        else
        {
            if(root.index > (a.root).index)
            {
                (*left)+=a;
                (*right)+=a;
                return;
            }
            else
            {
                boolfunc * temp = new boolfunc(a);
                *(temp->left)+=(*this);
                *(temp->right)+=(*this);
                root = temp->root;
                left = new boolfunc(*(temp->left));
                right = new boolfunc(*(temp->right));
                delete temp;
            }

        }
        }
///- or operator
        void operator*=(boolfunc const & a)
        {
            boolfunc * temp =left;

            if(left==NULL && a.left == NULL)
            {
                root.value = (root.value && (a.root).value);
                return;
            }
            if(a.left==NULL || a.right == NULL)
            {

                if(!(a.root).value)
                {
                    root = a.root;
                left = new boolfunc(*(a.left));
                right =  new boolfunc(*(a.right));

                }
                else
                {

                    //left= new boolfunc(*left);
                    //right = new boolfunc(*right);

                }

                return;
            }
            if(left  == NULL || right == NULL )
            {


                if(root.value)
                {
                    root = a.root;
                left =  new boolfunc(*(a.left));
                right =  new boolfunc(*(a.right));
                }
                else
                {


                }


                return;
            }
  if(root.index == (a.root).index)
        {
            (*left)*=*(a.left);
            (*right)*=*(a.right);
            return;
        }
        else
        {
            if(root.index > (a.root).index)
            {
                (*left)*=a;
                (*right)*=a;
                return;
            }
            else
            {
                boolfunc * temp = new boolfunc(a);
                *(temp->left)*=(*this);
                *(temp->right)*=(*this);
                root = temp->root;
                left = new boolfunc(*(temp->left));
                right = new boolfunc(*(temp->right));
                delete temp;
            }

        }

        } ///- and operator
        void operator~()
        {
        boolfunc* temp1 =  left;
            boolfunc* temp2 = right;
        boolfunc* a= new boolfunc;
        boolfunc* b= new boolfunc;
        a->root = root;
        b->root = root;
        a->right = new boolfunc(~(*temp1));
        a->left = new boolfunc(~(*temp2));
        a*=b;
        root = a.root;
        left = new boolfunc(*(a->left));
        right = new boolfunc(*(a->right));
            delete temp1;
            delete temp2;
            delete a;
            delete b;
            return;
        }
///- not operation
        bool operator==(boolfunc const &a)
        {
         if(a.left == NULL){
         if(left == NULL){
         if(root.value== )
         }
         }
        } ///- check for equality.
        void read()
        {
            int t;
            cin>>t;
            for(int i=0; i<t; i++)
            {
                int n;
                cin>>n;
                int temp;
                for(int j=0; j<n; j++)
                {
                    cin>>temp;

                }
            }
        }
        void print()
        {
        } ///- prints out the function in the same format as the input.
        void subst(int i, bool v)
        {
        }///- modifies the function by setting the value of x_i to v. This will be a new function independent of x_i.



    };
    int main()
    {
        return 0;
    }
