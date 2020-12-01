#include<iostream>
#include<vector>
using namespace std;
struct node
{
    int id;
    node()
    {
        id=-2;
        l=NULL;
        r=NULL;
    }
    ~node()
    {
    //delete id;
    delete l;
    delete r;

    }
    node*l;
    node*r;

    node* cop()
    {
        node* a;
        if(this==NULL)
        {
            return NULL;
        }
        a=new node;
        a->id=id;
        if(l!=NULL){
        a->l=l->cop();}
        if(r!=NULL){
        a->r=r->cop();}
        return a;
    }

    node* orfunc(node* root)
    {
        node* a;
        a=new node;
        int i,j;
        i=id;
        j=root->id;
        if((i<1)&&(j<1))
        {
            if((i==0)&&(j==0))
            {
                id=0;
                return this;
            }
            else
            {
                id=-1;
                return this;
            }
        }
        if(i>1)
        {
            if(j==0)
            {

                return this;
            }
            if(j==-1)
            {
                id=-1;
                return this;
            }
        }

        if(j>1)
        {
            if(i==0)
            {
                a=root->cop();
                return a;
            }
            if(i==-1)
            {
                id=-1;
                return this;
            }
        }

        if(i==j)
        {

            l=l->orfunc(root->l);
            r=r->orfunc(root->r);
            return this;
        }
        if(i<j)
        {
            l=l->orfunc(root);
            r=r->orfunc(root);
            return this;
        }
        node* c;
        c=this->cop();
        a->id=root->id;
        a->l=this->orfunc(root->l);
        a->r=c->orfunc(root->r);
        return a;

    }

    node* andfunc(node* root)
    {
        node* a;
        a=new node;
        int i,j;
        i=id;
        j=root->id;
        if((i<1)&&(j<1))
        {
            if((i==-1)&&(j==-1))
            {
                id=-1;
                return this;
            }
            else
            {
                id=0;
                return this;
            }
        }
        if(i>1)
        {
            if(j==-1)
            {

                return this;
            }
            if(j==0)
            {
                a->id=0;
                return this;
            }
        }

        if(j>1)
        {
            if(i==-1)
            {
                a=root->cop();
                return a;
            }
            if(i==0)
            {
                id=0;
                return this;
            }
        }

        if(i==j)
        {

            l=l->andfunc(root->l);
            r=r->andfunc(root->r);
            return this;
        }
        if(i<j)
        {

            l=l->andfunc(root);
            r=r->andfunc(root);
            return this;
        }
        node* c;
        c=this->cop();
        a->id=j;
        a->l=this->andfunc(root->l);
        a->r=c->andfunc(root->r);
        return a;

    }

    node* neg()
    {
        if(id==0)
        {
            id=1;
            return this;
        }
        if(id==1)
        {
            return this;
        }
        l=r->neg();
        r=l->neg();
        return this;

    }

    vector<vector<int> > print(vector<vector<int> > &v)
    {
    int i;
    vector<vector<int> > a,b;
    vector<int> c,d;
    if(id<1)
    {
    if(id==0)
    {
    return a;
    }
    if(id==-1)
    {
    a.push_back(c);
    return a;
    }
    }
    a=l->print(a);
    b=r->print(b);
    for(i=0;i<a.size();i++)
    {
    a[i].insert(a[i].begin(),-id);
    }
    for(i=0;i<b.size();i++)
    {
    b[i].insert(b[i].begin(),id);
    }
    a.insert( a.end(),b.begin(), b.end() );
    v=a;
    return v;
    }

};



class boolfunc
{
    node *root;

    boolfunc()
    {

    }
    ~boolfunc()
    {
     delete root;

    }

    boolfunc( boolfunc const & a)
    {
        root=a.root->cop();
        return ;
    }

    void operator+=(boolfunc const & a)
    {
        root=root->orfunc(a.root);
        return ;
    }
    void operator*=(boolfunc const & a)
    {
        root=root->andfunc(a.root);
        return ;
    }
    void operator~()
    {
        root=root->neg();
        return ;
    }
  void print()
  {int j,i;
 vector<vector<int> > v;
  root->print(v);
  cout<<v.size()<<endl;
  for(i=0;i<v.size();i++)
  {cout<<v[i].size()<<endl;
  for(j=0;j<v[i].size();j++)
  {
  cout<<v[i][j]<<" ";
  }
  cout<<endl;
  }
  return ;
  }
 void read()
 {
 boolfunc *a;

 }

};

int main()
{


return 0;
}
