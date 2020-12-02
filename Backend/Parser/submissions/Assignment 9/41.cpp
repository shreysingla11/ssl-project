#include<iostream>
#include<string>
using namespace std;
class data
{
public:
    data* right;
    data* left;
    int i;
    data()
    {
        i = -6;
        right =NULL;
        left=NULL;
    }
    void operator+=(data* const &adddata)
    {
        if(this->i != -6)
        {
            if(this->i==adddata->i)
            {
                *(this->left) += adddata->left;
                *(this->right) += adddata->right;
            }
            else if(this->i > adddata->i)
            {
                data* copieddata;
                copieddata = this;
                this->i = adddata->i;
                *(this->left) += copieddata;
            }
            else if(this->i < adddata->i)
            {
                *(this->left) += adddata;
            }
        }
        else
        {
            this->i = adddata->i;
            this->left = adddata->left;
            this->right = adddata->right;
        }
    }
    data* replica(data* repdata)
    {
        data* ans;
        ans = new data;
        ans->i = repdata->i;
        ans->left = replica(repdata->left);
        ans->right = replica(repdata->right);
        return ans;
    }
    void print()
    {
        if(this->left!=NULL){this->left->print();}
        cout<<this->i<<" ";
        if(this->right!=NULL){this->right->print();}
    }
};
class boolfunc
{
public:
    data* tree = new data;
    boolfunc()
    {

    }
    boolfunc( boolfunc const &)
    {

    }
    void operator+=(boolfunc const &actual)
    {
        *(this->tree)+=actual.tree;
        //this->tree = actual.tree;
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
        int x;
        cin>>x;

        for(int i=0; i<x; i++)
        {
            int y;
            cin>>y;
            boolfunc* present;
            present = new boolfunc;
            boolfunc* actual;
            actual = present;
            for(int j=0; j<y; j++)
            {
                int k;
                cin>>k;
                if(k<0)
                {
                    present->tree->i = -k;
                    present->tree->left = new data;
                    present->tree->right= new data;
                    present->tree->right->i=0;
                    present->tree = present->tree->left;

                }
                else
                {
                    present->tree->i = k;
                    present->tree->left = new data;
                    present->tree->right= new data;
                    present->tree->left->i=0;
                    present->tree = present->tree->right;
                }

            }
            present->tree->i = -1;
            //actual->print();
            //*this += *actual;
        }

    }
    void print()
    {
         this->tree->print();
    }
    void subst(int i, bool v)
    {

    }
};
int main()
{
    boolfunc check;
    check.read();
    return 0;
}
