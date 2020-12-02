#include<iostream>
#include<vector>
using namespace std;
class node
{
    public:
        bool val;
        node* left;
        node* right;
        node* p;
        bool v;
        node()
        {
            left=NULL;right=NULL;p=NULL;
            v=0;
        }
};
class boolfunc
{
    private:
    node* root;
    int t, d;
    public:
    boolfunc()
    {   root=new node;
        root->left=new node; root->right=new node;
        root->left->val=false;root->left->p=root;
        root->right->val=true;root->right->p=root;
    }
    boolfunc(boolfunc const & func2)
    {
        this->root=func2.root;
    }
    void operator+=(boolfunc const& func2)
    {
        node* temp=this->root;
        while(temp!=NULL)
        {

                if(temp->left==NULL&&temp->right==NULL&&temp->val==false)
                {
                    if(temp==temp->p->left) temp->p->left=func2.root;
                    else temp->p->right=func2.root;
                    func2.root->p=temp->p;
                    delete temp;
                    temp=func2.root->p;
                    temp->v++;
                }
                else if(temp->left==NULL&&temp->right==NULL&&temp->val==true)
                {
                    temp=temp->p;
                    temp->v++;
                }
                else if(temp->v==0)
                {
                    temp=temp->left;
                }
                else if(temp->v==1)
                {
                    temp=temp->right;
                }
                else if(temp->v==2)
                {
                    temp->v=0; temp=temp->p;
                }

        }
    }
    void operator*=(boolfunc const& func2)
    {
        node* temp=this->root;
        while(temp!=NULL)
        {

                if(temp->left==NULL&&temp->right==NULL&&temp->val==true)
                {
                    if(temp==temp->p->left) temp->p->left=func2.root;
                    else temp->p->right=func2.root;
                    func2.root->p=temp->p;
                    delete temp;
                    temp=func2.root->p;
                    temp->v++;
                }
                else if(temp->left==NULL&&temp->right==NULL&&temp->val==false)
                {
                    temp=temp->p;
                    temp->v++;
                }
                else if(temp->v==0)
                {
                    temp=temp->left;
                }
                else if(temp->v==1)
                {
                    temp=temp->right;
                }
                else if(temp->v==2)
                {
                    temp->v=0; temp=temp->p;
                }

        }

    }
    void operator~()
    {
        node* temp=this->root;
        while(temp!=NULL)
        {

                if(temp->left==NULL&&temp->right==NULL&&temp->val==false)
                {
                    temp->val=true;
                    temp=temp->p;
                    temp->v++;
                }
                else if(temp->left==NULL&&temp->right==NULL&&temp->val==true)
                {
                    temp->val=false;
                    temp=temp->p;
                    temp->v++;
                }
                else if(temp->v==0)
                {
                    temp=temp->left;
                }
                else if(temp->v==1)
                {
                    temp=temp->right;
                }
                else if(temp->v==2)
                {
                    temp->v=0; temp=temp->p;
                }

        }
    }
    ~boolfunc(){ delete root; root=NULL;}
    void read()
    {

        cin>>t;
        int i, j, k;
        vector<int> temp2;
        for(i=0;i<t;i++)
        {
            boolfunc* term = new boolfunc;
            cin>>k;
            for(j=0;j<k;j++)
            {
            cin>>d;
            boolfunc* temp=new boolfunc; temp->root=new node;
            temp->root->val=d;
            if(d<0) {~(*temp); d=0-d;}
            *(term)*=*(temp);
            }
            if(root==NULL) *this=*term;
            else *this+=*term;
        }
    }
    void print()
    {
        node* temp=this->root;
        int n=0,count=0;
        while(true)
        {
            if(temp->left->val==0||temp->left->val==-1) temp=temp->right;
            else if(temp->right->val==0||temp->right->val==-1) {temp=temp->left;n++;}
            else break;
        }
        cout<<n<<endl;
        node* head=this->root;
        node* tail=this->root;
        while(n>0)
        {
            count=0;
            temp=head;
            while(true)
            {
                if(temp->left->val==0||temp->left->val==-1) {temp=temp->right;count++;}
                else {tail=temp;break;}
            }
            cout<<count<<endl;
            temp=head;
            while(count>0)
            {
                cout<<temp->val<<"\t";
            }
            head=tail->left;cout<<endl;
            n--;
        }
    }
};

