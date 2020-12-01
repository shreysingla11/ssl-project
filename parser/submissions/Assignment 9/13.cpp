#include<iostream>
using namespace std;
class boolfunc
{
private:
    boolfunc *left;
    boolfunc *right;
    int node;
public:
    //nothing constructor
    boolfunc()
    {
        left=NULL;
        right=NULL;
        //cout<<left<<" "<<right;
    }
    //destructor to free entire allocated memory
    ~boolfunc()
    {
       /* if(left!=NULL)
        {
        if(left->left==NULL&&left->right==NULL)
        {
            delete left;

        }
        else
        {
            left->~boolfunc();
            delete left;
        }
        }
        if(right!=NULL)
        {
        if(right->right==NULL&&right->left==NULL)
        {
            delete right;
        }
        else
        {
            right->~boolfunc();
            //delete right;
        }
        }*/


    }
    //copy constructor
    boolfunc( boolfunc const &a)
    {
        node=a.node;
        *left=boolfunc(*(a.left));
        *right=boolfunc(*(a.right));


    }
    //or operator
    void operator+=(boolfunc const &a)
    {
        if(a.node==node)
        {
                right->operator+=(*(a.right));
                left->operator+=(*(a.left));

        }
        if(a.node<node)
        {
            right->operator+=(a);
            left->operator+=(a);

        }
        if(a.node>node)
        {
            boolfunc * x;
            *x=boolfunc(*this);
            this->~boolfunc();
            boolfunc(*a);
            this->operator+=(*x);

        }


    }
    //and operator
    void operator*=(boolfunc const &a)
    {
        if(a.node==node)
        {
                right->operator*=(*(a.left));
                left->operator*=(*(a.right));

        }
        if(a.node<node)
        {
            right->operator*=(a);
            left->operator*=(a);

        }
        if(a.node>node)
        {
            boolfunc * x;
            *x=boolfunc(*this);
            this->~boolfunc();
            boolfunc(*a);
            this->operator*=(*x);

        }


    }
    //not operator
    void operator~()
    {


    }
    //checking equality of subtrees
    bool operator==(boolfunc const &a)
    {
        if (a.node==node)
        {
            if(left==NULL&&right==NULL&&a.left==NULL&&a.right==NULL)
            {
                return true;
            }
            else
            {
                if(left->operator==(*(a.left))&&right->operator==(*(a.right)))
                {
                    return true;
                }
                else
                {
                    return false;
                }

            }


        }
        else
        {
            return false;
        }


    }
    //to construct tree
    void read()
    {
        int num;
        cin>>num;
        while(num>0)
        {
            int lit,x;
            cin>>lit;
            boolfunc* ac;
            while(lit>0)
            {
                cin>>x;
                boolfunc *ab;
                if(x>0)
                {
                    //cout<<" "<<x;
                    ab->node=x;

                }
                else
                {
                    ab->node=-x;

                }
                //cout<<" "<<x;
                ac->operator*=(*ab);
                delete ab;
                lit --;

            }
            operator+=(*ac);
            delete ac;
            num--;

        }



    }
    //print tree in required format
    void print()
    {

    }
    //assign x_i to v which reduces func
    void subst(int i,bool v)
    {




    }




};
int main(){
boolfunc xy,f;
xy.read();
    return 0;
}
