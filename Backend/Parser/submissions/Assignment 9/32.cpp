#include<iostream>
#include<vector>
using namespace std;

class myNode
{
    public:
        int i;
        myNode *left,*right;
        myNode()
        {
            i=-2;
            right=NULL;
            left=NULL;
        }
        void operator+=(myNode const &inp)
        {

            if(i==inp.i && (i>=1))
            {
                *left+=*(inp.left);
                *right+=*(inp.right);
            }
            else if((i<inp.i)&&(i>=1))
            {
                *left+=inp;
                *right+=inp;
            }
            else if((i>inp.i)&&(i>=1))
            {
                myNode* temp=createdupe(*this);
                this->i=inp.i;
                *(inp.left)+=*temp;
                this->left=inp.left;
                *(inp.right)+=*temp;
                this->right=inp.right;
            }
            else if(i==0)
            {
                //do nothing
            }
            else if(i==-1)
            {
                myNode* temp=createdupe(inp);
                i=temp->i;
                left=temp->left;
                right=temp->right;
            }
        }
        myNode* createdupe(myNode const &inp)
        {
            myNode* ret=new myNode;
            ret->i=inp.i;
            ret->left=(createdupe(*(inp.left)));
            ret->right=(createdupe(*(inp.right)));
            return ret;
        }
};

class boolfunc
{
private:
    myNode* here;
public:
    boolfunc()
    {

    }
    ~boolfunc()
    {

    }
    boolfunc( boolfunc const &inp)
    {

    }
    void operator+=(boolfunc const &inp)
    {
        *here+=*(inp.here);
    }
    void operator*=(boolfunc const &)
    {

    }
    void operator~()
    {

    }
    bool operator==(boolfunc const &)
    {

    }
    void read()
    {

    }
    void print()
    {

    }
    void subst(int i, bool v)
    {

}
};


int main()
{

}
