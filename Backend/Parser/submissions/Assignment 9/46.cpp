#include<iostream>
#include<vector>

using namespace std;
struct tree
{
    int root;
    tree *left, *right;
};
vector<int>v;
class boolfunc
{
    //int n;
    //vector<bool> arr;
    int root;
    boolfunc *left,*right;
    //tree *t=new tree;

    public:
    boolfunc()
    {
        root=0;
        left=NULL;
        right=NULL;
    }

    ~boolfunc()
    {

    }

    boolfunc( boolfunc const &b)
    {
        root=b.root;
        if(b.left!=NULL)
        {
            left=new boolfunc;
            *(left)=*(b.left);
        }
        else left=NULL;
        if(b.right!=NULL)
        {
            right=new boolfunc;
            *(right)=*(b.right);
        }
        else right=NULL;
    }

    void operator=( boolfunc const &b)
    {
        cout<<"in copy"<<endl;
        cout<<"before root"<<endl;
        cout<<b.root<<endl;
        root=b.root;
        cout<<"after root"<<endl;
        if(b.left!=NULL)
        {
            cout<<"in left"<<endl;
            left=new boolfunc;
            *(left)=*(b.left);
        }
        else left=NULL;
        if(b.right!=NULL)
        {
            cout<<"in right"<<endl;
            right=new boolfunc;
            *(right)=*(b.right);
        }
        else right=NULL;
        cout<<"out of copy"<<endl;
    }

    //void operator+=(boolfunc const &b)
    boolfunc operator+(boolfunc const &b)
    {
        boolfunc b_new;
        if(root==0)
            b_new=b;
        else if(b.root==0)
            b_new=*this;
        else if(root==-1||b.root==-1)
        {
            b_new.root=-1;
            b_new.left=NULL;
            b_new.right=NULL;
        }
        else
        {
            if(root<b.root)
            {
                b_new.root=root;
                *(b_new.left) = *(left) + (b);
                *(b_new.right) = *(right) + (b);
            }
            else if(b.root<root)
            {
                b_new.root=b.root;
                *(b_new.left) = *(b.left) + *this;
                *(b_new.right) = *(b.right) + *this;
            }
            else
            {
                b_new.root=root;
                *(b_new.left) = *(b.left) + *left;
                *(b_new.right) = *(b.right) + *right;
            }
        }
        return b_new;
    }

    void operator+=(boolfunc const &b)
    {
        *this = *this + b;
    }

    boolfunc operator*(boolfunc const &b)
    {
        boolfunc b_new;
        cout<<"in func"<<endl;
        if(root==0||b.root==0)
        {
            b_new.root=0;
            b_new.left=NULL;
            b_new.right=NULL;
        }
        else if(root==-1)
            b_new=b;
        else if(b.root==-1)
            b_new=*this;
        else
        {
            if(root<b.root)
            {
                b_new.root=root;
                *(b_new.left) = *(left) * (b);
                *(b_new.right) = *(right) * (b);
            }
            else if(b.root<root)
            {
                b_new.root=b.root;
                *(b_new.left) = *(b.left) * *this;
                *(b_new.right) = *(b.right) * *this;
            }
            else
            {
                b_new.root=root;
                *(b_new.left) = *(b.left) * *left;
                *(b_new.right) = *(b.right) * *right;
            }
        }
        cout<<"nowhere"<<endl;
        return b_new;
    }

    void operator*=(boolfunc const &b)
    {
        cout<<"entered"<<endl;
        *this = *this * b;
        cout<<"somewhere"<<endl;
    }

    void operator~()
    {
        if(this->root==-1)
            this->root=0;
        else if(this->root==0)
            this->root=-1;
        else
        {
            ~*(this->left);
            ~*(this->right);
        }
    }

    bool operator==(boolfunc const &b)
    {
        return (root==b.root) && (*left==*(b.left)) && (*right==*(b.right));
    }

    void read()
    {
        int num;
        cin>>num;
        for(int i=0;i<num;i++)
        {
            int num2;
            cin>>num2;
            boolfunc temp;
            temp.root=-1;
            while(num2--)
            {
                int num3;
                cin>>num3;
                boolfunc temp2;
                temp2.left=new boolfunc;
                temp2.right=new boolfunc;
                (temp2.left)->root=0;
                (temp2.right)->root=-1;
                if(num3<0)
                {
                    temp2.root=-num3;
                    ~temp2;
                }
                else temp2.root=num3;
                cout<<"here"<<endl;
                temp*=temp2;
            }
            *this+=temp;
        }
    }
    int countfalse()
    {
        if(root==0)
            return 1;
        else if(root==-1)
            return 0;
        else return left->countfalse()+right->countfalse();
    }
    int counttrue()
    {
        if(root==-1)
            return 1;
        else if(root==0)
            return 0;
        else return left->counttrue()+right->counttrue();
    }
    void print1()
    {
        //cout<<counttrue()<<endl;
        //int counter=counttrue()+countfalse();
        if(root==-1)
        {
            cout<<v.size()<<endl;
            for(int i=0;i<v.size();i++)
                cout<<v[i]<<" ";
            cout<<endl;
        }
        else if(root!=0)
        {
            v.push_back(-root);
            left->print1();
            v.pop_back();
            v.push_back(root);
            right->print1();
            v.pop_back();
        }
    }
    void print()
    {
        cout<<counttrue()<<endl;
        print1();
    }

};
