#include<iostream>
using namespace std;
class boolfunc
{
    int r;
    boolfunc *f1;
    boolfunc *f2;
public:
    boolfunc()
    {
        f1=NULL;
        f2=NULL;
    }
    ~boolfunc()
    {
        delete f1;
        delete f2;
    }
    boolfunc( boolfunc const & temp)
    {
        r=temp.r;
        if(temp.f1!=NULL)
        {
            f1=new boolfunc(*(temp.f1));
        }
        else
        {
            f1=NULL;
        }
        if(temp.f2!=NULL)
        {
            f2=new boolfunc(*(temp.f2));
        }
        else
        {
            f2=NULL;
        }
    }
    void operator+=(boolfunc const &temp)
    {
        if(r==0)
        {
            if(temp.r==-1)
            {
                r=-1;
                return;
            }
            if(temp.r==0)
            {
                return;
            }
            r=temp.r;
            f1=new boolfunc(*temp.f1);
            f2=new boolfunc(*temp.f2);
            return;
        }
        if(r==-1)
        {
            return;
        }
        if(temp.r==0)
        {
            return;
        }

        if(temp.r==-1)
        {
            r=-1;
            delete f1;
            delete f2;
            f1=NULL;
            f2=NULL;
            return;
        }
        if(temp.r==r)
        {
            if(temp.f1!=NULL)
            {
                if(f1==NULL)
                {
                    f1=new boolfunc(*temp.f1);
                }
                else
                {
                    (*f1)+=*(temp.f1);
                }
            }
            if(temp.f2!=NULL)
            {
                if(f2==NULL)
                {
                    f2=new boolfunc(*temp.f2);
                }
                else
                {
                    (*f2)+=*(temp.f2);
                }
            }
        }
        else if(temp.r>r)
        {
            (*f1)+=temp;
            (*f2)+=temp;
        }
        else if(temp.r<r)
        {
            boolfunc *dummy=new boolfunc(*this);
            r=temp.r;
            delete f1;
            delete f2;
            f1=new boolfunc(*(temp.f1));
            f2=new boolfunc(*(temp.f2));
            *f1+=*(dummy);
            *f2+=*(dummy);
            delete dummy;
        }
    }
    void operator*=(boolfunc const &temp)
    {
        if(r==-1)
        {
            if(temp.r==-1)
            {
                return;
            }
            if(temp.r==0)
            {
                r=0;
                return;
            }
            r=temp.r;
            f1=new boolfunc(*temp.f1);
            f2=new boolfunc(*temp.f2);
            return;
        }
        if(r==0)
        {
            return;
        }
        if(temp.r==-1)
        {
            return;
        }
        if(temp.r==0)
        {
            r=0;
            delete f1;
            delete f2;
            f1=NULL;
            f2=NULL;
            return;
        }
        if(temp.r==r)
        {
            (*f1)*=*(temp.f1);
            (*f2)*=*(temp.f2);
        }
        else if(temp.r>r)
        {
            (*f1)*=temp;
            (*f2)*=temp;
        }
        else if(temp.r<r)
        {
            boolfunc *dummy=new boolfunc(*this);
            r=temp.r;
            delete f1;
            delete f2;
            f1=new boolfunc(*(temp.f1));
            f2=new boolfunc(*(temp.f2));
            *f1*=*(dummy);
            *f2*=*(dummy);
            delete dummy;
        }
    }
    void operator~()
    {
        if(f1==NULL)
        {
            if(r==0)
            {
                r=-1;
            }
            else
            {
                r=0;
            }
            return;
        }
        boolfunc *t1;
        ~(*f1);
        ~(*f2);
        t1=new boolfunc(*f1);
        (*t1)*=*f2;
        *this+=*t1;
        delete t1;
    }
    bool operator==(boolfunc const &temp)
    {
        if(r==0)
        {
            if(temp.r==0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        if(r==-1)
        {
            if(temp.r==-1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        if(r==temp.r)
        {
            return (f1==temp.f1)&&(f2==temp.f2);
        }
        else
        {
            return false;
        }
    }
    void read()
    {
        int terms;
        cin>>terms;
        int prod;
        //boolfunc result;
        r=0;
        for(int i=0; i<terms; i++)
        {
            boolfunc iter;
            cin>>prod;
            cin>>iter.r;
            if(iter.r<0)
            {
                iter.r=-iter.r;
                iter.f1=new boolfunc();
                iter.f1->r=-1;
                iter.f2=new boolfunc();
                iter.f2->r=0;
            }
            else
            {
                iter.f1=new boolfunc();
                iter.f1->r=0;
                iter.f2=new boolfunc();
                iter.f2->r=-1;
            }
            for(int j=1; j<prod; j++)
            {
                boolfunc temp;
                cin>>temp.r;
                if(temp.r<0)
                {
                    temp.r=-temp.r;
                    temp.f1=new boolfunc();
                    temp.f1->r=-1;
                    temp.f2=new boolfunc();
                    temp.f2->r=0;
                }
                else
                {
                    temp.f1=new boolfunc();
                    temp.f1->r=0;
                    temp.f2=new boolfunc();
                    temp.f2->r=-1;
                }
                iter*=temp;
            }
            (*this)+=iter;
        }
    }
    void print()
    {

    }
    void subst(int i, bool v)
    {

    }
};
