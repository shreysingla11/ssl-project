#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int i;
    Node* left;
    Node* right;
    Node* parent;
    int value;
    Node(){i=0; left=NULL; right=NULL; parent=NULL;}
};
Node* TRUE;

class boolfunc
{
    boolfunc* left;
    boolfunc* right;
   // boolfunc* parent;
    int i;
    int val;
   public:
    boolfunc(){left=NULL;right=NULL;i=0;val=-2;}
    boolfunc(int in, int a){val=a; i=in;}
    ~boolfunc()
    {  //delete left;
       //delete right;
       //delete this;
    }
    boolfunc(boolfunc const& a)
    {   val=a.val;
        i=a.i;
        if(a.left!=NULL)
            *left=*(a.left);
        else
           left=NULL;
        if(a.right!=NULL)
            *right=*(a.right);
        else
            right=NULL;
    /*    if(a.parent!=NULL)
             *parent=*(a.parent);
        else
             parent=NULL;
    */}

    void operator+=(boolfunc const& a)
    { if(i<=0)
      { boolfunc* r=new boolfunc(a);
        *this=*r;
        return;
      }

        if(i==a.i)
        { { if(left->val==-1||a.left->val==-1)
            left->val=-1;
            else if(left->val==0)
            {   boolfunc* l=new boolfunc(*a.left);
                left=l;
            }
            else
            {   *(left)+=*(a.left);
            }
          }
          { if(right->val==-1||a.right->val==-1)
                right->val=-1;
            else if(right->val==0)
            {   boolfunc* r=new boolfunc(*a.right);
                right=r;
            }
            else
            {   *(right)+=*(a.right);
            }
          }
        }

        if(i<a.i)
        {   //boolfunc *x=new boolfunc(a);
            *(left)+=a;
            *(right)+=a;
        }
        if(i>a.i)
        {   boolfunc r(a.i,a.val);
            *r.left=*this;
            *r.right=*this;
            *(r.left)+=*(a.left);
            *(r.right)+=*(a.right);
            *this=r;
        }

    }
    void operator*=(boolfunc const& a)
    {
        if(i<=0)
        { boolfunc* r=new boolfunc(a);
          *this=*r;
          return;
       //   cout<<"1"<<endl;
        }
        if(i==a.i)
        {   {   *(left)+=*(a.left);
            }
            {   *(right)+=*(a.right);
            }
        }
        if(i<a.i)
        {   //boolfunc *x=new boolfunc(a);
            *(left)+=a;
            *(right)+=a;
        }
        if(i>a.i)
        {   boolfunc r(a.i,a.val);
            *r.left=*this;
            *r.right=*this;
            *(r.left)+=*(a.left);
            *(r.right)+=*(a.right);
            *this=r;
        }
    }
    void operator~()
    { if(i<=0)
      {
        return;
      }
       if(this->left==NULL&&this->right==NULL)
        this->val=(this->val==0)?-1:0;
       else
       {  ~*(this->left);
          ~*(this->right);
       }
    }
    bool operator==(boolfunc const& a)
    {   if(i==a.i)
        {
            if(i<=0)
               return (a.val==val);
            else
               return  (*left==*a.left&&*right==*a.right);
        }
        else return false;
     }
     void read()
     {
        int n;
        cin>>n;
        boolfunc* tree=new boolfunc();
        for(int i=0;i<n;i++)
        {   int m;
            cin>>m;
            boolfunc* temp=new boolfunc();

            for(int j=0;j<m;j++)
            {   boolfunc* t=new boolfunc();
                boolfunc* l=new boolfunc();
                boolfunc* r=new boolfunc();
                t->left=l;
                t->right=r;

                int p;
                cin>>p;
                t->i=abs(p);
                t->val=-2;
                if(p<0)
                {   t->right->val=0;
                    t->left->val=-1;
                   }
                if(p>0)
                {   t->right->val=-1;
                    t->left->val=0;
                }
                (*temp)*=(*t);
            }
            (*tree)*=(*temp);
        }
        *this=*tree;
     }

};

int main()
{
    boolfunc a;//(1,0);
    boolfunc b(a);
    boolfunc c;//(2,-1);
    a.read();
   /* b+=a;
    c*=a;
    ~b;
    if(c==a)
    cout<<"yes";
    //else
    cout<<"no";*/
    return 0;
}
