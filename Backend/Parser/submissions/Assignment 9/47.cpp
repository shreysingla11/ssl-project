#include<iostream>
#include<vector>
#include<stdio.h>
#include<cmath>
using namespace std;
struct Node
{
    int val;
    Node *left;
    Node *right;
};
vector<int> v;
class boolfunc
{
public:

    int val;
    boolfunc* left;
    boolfunc* right;

    boolfunc()
    {
        val= 0;
        left = NULL;
        right = NULL;
    }
    ~boolfunc()
    {
        delete left;
        delete right;
    }
    boolfunc( boolfunc const & a)
    { //cout<<"fdbfbdf"<<endl;
        val=a.val;

        if(a.left!=NULL)
        {
            *(left)=*(a.left);
        }
        else
        {
            left=NULL;
        }
        if(a.right!=NULL)
        {
            *(right) = *(a.right);
        }
        else
        {
            right = NULL;
        }
    }
    boolfunc operator+(boolfunc const &a)
    {
        boolfunc treecopy;
        if(val==0)
            treecopy = a;
        else if (a.val == 0)
            treecopy = *this;
        else if ((val==-1)||(a.val==-1))
        {
            treecopy.val = -1;
            treecopy.right = NULL;
            treecopy.left = NULL;
        }
        else
        {
            if(val<a.val)
            {
                treecopy.val = val;
                *(treecopy.left) = *(left) + a;
                *(treecopy.right) = *(right) + a;
            }
            else if (val>a.val)
            {
                treecopy.val = a.val;
                *(treecopy.left) = *(left) + *this;
                *(treecopy.right) = *(right) + *this;
            }
            else
            {
                treecopy.val=a.val;
                *(treecopy.right) = *(right) + *(a.right);
                *(treecopy.left) = *(left) + *(a.left);

            }
        }
        return treecopy;
    }
    void operator+=(boolfunc const &a)
    {
        *this = *this + a;
    }
    boolfunc operator*(boolfunc const &a)
    {
         boolfunc treecopy;
        if(val==0||a.val == 0)
        {
            treecopy.val = 0;
            treecopy.right = NULL;
            treecopy.left = NULL;
        }
        else if (val == -1)
            treecopy = *this;
        else if (a.val ==-1)
            treecopy = a;
        else
        {
            if(val<a.val)
            {
                treecopy.val = val;
                *(treecopy.left) = *(left) * a;
                *(treecopy.right) = *(right) * a;
            }
            else if (val>a.val)
            {
                treecopy.val = a.val;
                *(treecopy.left) = *(left) * *this;
                *(treecopy.right) = *(right) * *this;
            }
            else
            {
                treecopy.val=a.val;
                *(treecopy.right) = *(right) * *(a.right);
                *(treecopy.left) = *(left) * *(a.left);

            }
        }
        return treecopy;
    }
    void operator*=(boolfunc const &a)
    {
        *this = *this * a;
    }
    void operator~()
    {
        if(val==-1)
            val=0;
        else if(val==0)
            val= -1;
        else
        {
            ~*(left);
            ~*(right);
        }
    }
    bool operator==(boolfunc const &a)
    {
        return (val==a.val) && (*left==*a.left) && (*right==*a.right);
    }
    void read()
    {
        int len;
        scanf("%d",&len);

        for (int i=0;i<len;i++)
        {
            boolfunc *tem= new boolfunc;
            tem->val=-1;
            int num;
            scanf("%d",&num);
            for (int j=0;j<num;j++)
            {
                int r;
                scanf("%d",&r);
                boolfunc *tem2=new boolfunc;
                boolfunc *tem_left = new boolfunc;
                boolfunc *tem_right = new boolfunc ;
                tem2->val=abs(r);
                tem_left->val = 0;
                tem_right->val=-1;
                (tem2->left) = (tem_left);
                (tem2->right) = (tem_right);
                if(r<0)
                {
                    //cout<<"gvdfdd"<<endl;
                    ~*(tem2);
                }
                //cout<<"gvdfdd"<<endl;
                *tem *= *tem2;
            }
            //cout<<"gvdfdd"<<endl;
            *this += *tem;
        }
    }
    int countt()
    {
        if(val == -1)
            return 1;
        else if(val!=0)
        {
            return left->countt() + right->countt();
        }
        else
            return 0;
    }
     int countf()
    {
        if(val == 0)
            return 1;
        else if(val!=-1)
        {
            return left->countf() + right->countf();
        }
        else
            return 0;
    }
    void print_recur()
    {
        if(val==-1)
        {
            cout<<v.size()<<endl;
            for(int i=0;i<v.size();i++)
            {
                cout<<v[i]<<" ";
            }
            v.pop_back();
            cout<<endl;
        }
        else if(val!=0)
        {
            v.push_back(-val);
            left->print_recur();
            v.pop_back();
            v.push_back(val);
            right->print_recur();
            v.pop_back();
        }
    }
    void print()
    {
        cout<<countt()<<endl;
        print_recur();
    }
};/*
int main()
{
    boolfunc temp;
    temp.read();
}
*/
