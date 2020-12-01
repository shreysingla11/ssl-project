#include<iostream>
using namespace std;
#include<set>
#include<list>
#include<vector>
#include<map>
#include<cmath>
#include<cmath>

/*struct node
{

};
*/
vector<int> vec;

class boolfunc
{

    //int length;
    //vector<bool> main;
    //node *tree;
public:
    int value;
    boolfunc *leftnode;
    boolfunc *rightnode;
    boolfunc()
    {
        //tree=new node;
        value=0;
        leftnode=NULL;
        rightnode=NULL;

    }
    //~boolfunc();
    int counttrue()
    {
        if (value==-1)
            return 1;
        else if(value!=0)
            return leftnode->counttrue() + rightnode->counttrue();
        else
            return 0;
    }
    int countfalse()
    {
        if (value==0)
            return 1;
        else if(value!=-1)
            return leftnode->countfalse() + rightnode->countfalse();
        else
            return 0;
    }
    boolfunc( boolfunc const &a)
    {
        //cout<<"hahahahha"<<endl;
        value=a.value;
//        length=a.length;
        if(a.leftnode!=NULL)
        {
            *(leftnode)=*(a.leftnode);
        }
        else leftnode=NULL;
        if(a.rightnode!=NULL)
        {
            *(rightnode)=*(a.rightnode);
        }
        else rightnode=NULL;
    }
    void operator=(boolfunc const &a)
    {
        //cout<<"babababa"<<endl;
        value=a.value;
//        length=a.length;
        if(a.leftnode!=NULL)
        {
            *(leftnode)=*(a.leftnode);
        }
        else leftnode=NULL;
        if(a.rightnode!=NULL)
        {
            *(rightnode)=*(a.rightnode);
        }
        else rightnode=NULL;

    }

    boolfunc operator+(boolfunc const &a)
    {
        boolfunc newtree;
        if(value==0)
            newtree=a;
        else if (a.value==0)
            newtree=*this;
        else if((value==-1)||(a.value==-1))
        {
            newtree.value=-1;
            newtree.leftnode=NULL;
            newtree.rightnode=NULL;
        }
        else
        {
            if(value<a.value)
            {
                newtree.value=value;
                *(newtree.leftnode) = *(leftnode) + a;
                *(newtree.rightnode) = *(rightnode) + a;
            }
            else if(value>a.value)
            {
                newtree.value=a.value;
                *(newtree.leftnode)=*(a.leftnode) + *this;
                *(newtree.rightnode)=*(a.rightnode) + *this;
            }
            else
            {
                newtree.value=a.value;
                *(newtree.leftnode) = *(a.leftnode) + *(leftnode);
                *(newtree.rightnode) = *(a.rightnode) + *(rightnode);
            }
        }
        return newtree;
    }
    void operator+=(boolfunc const &a)
    {
        *this=*this + a;
    }
    boolfunc operator*(boolfunc const &a)
    {
        boolfunc newtree;
        if(value==0 || a.value==0)
        {
            newtree.value=0;
            newtree.leftnode=NULL;
            newtree.rightnode=NULL;
        }
        else if(value==-1)
            newtree=*this;
        else if(a.value==-1)
            newtree=a;
        else
        {
            if(value<a.value)
            {
                newtree.value=value;
                *(newtree.leftnode) = *(leftnode) * a;
                *(newtree.rightnode) = *(rightnode) * a;
            }
            else if(value>a.value)
            {
                newtree.value=a.value;
                *(newtree.leftnode)=*(a.leftnode) * *this;
                *(newtree.rightnode)=*(a.rightnode) * *this;
            }
            else
            {
                newtree.value=a.value;
                *(newtree.leftnode) = *(a.leftnode) * *(leftnode);
                *(newtree.rightnode) = *(a.rightnode) * *(rightnode);
            }
        }
        return newtree;
    }
    void operator*=(boolfunc const &a)
    {
        *this = *this * a;
    }
    void operator~()
    {
        if(value==-1)
            value=0;
        else if (value==0)
            value=-1;
        else
        {
            ~*(leftnode);
            ~*(rightnode);
        }
    }
    bool operator==(boolfunc const &a)
    {
        return (value==a.value) && (*leftnode== *a.leftnode) && (*rightnode== *a.rightnode);
    }
    void read()
    {
        this->value=0;
        int length;
        cin>>length;
        for(int i=0;i<length;i++)
        {
            //cout<<"abcd"<<endl;
            boolfunc *temp= new boolfunc;
            temp->value=-1;
           int number;
           cin>>number;
           for(int j=0; j<number;j++)
           {
                int x;
                cin>>x;
                boolfunc *supertemp=new boolfunc;
                boolfunc *supertempleft= new boolfunc;
                boolfunc *supertempright=new boolfunc;
                supertempleft->value=0;
                supertempright->value=-1;
                supertemp->value=abs(x);
                (supertemp->leftnode) = (supertempleft);
                (supertemp->rightnode) = (supertempright);
                if(x<0)
                    ~*(supertemp);
                *temp *= *supertemp;
           }

            *this += *temp;
        }

    }
    void print1()
    {
        if(value==-1)
        {
            //cout<<vec.size()<<"gsjdv"<<endl;
            for(int i=0; i <vec.size(); i++)
            {
                cout<<vec[i]<<" ";
            }
            vec.pop_back();
            cout<<endl;
        }
        else if(value!=0)
        {
            vec.push_back(-value);
            leftnode->print1();
            vec.pop_back();
            vec.push_back(value);
            rightnode->print1();
            vec.pop_back();
        }

    }
    void print()
    {
        cout<<counttrue()<<endl;
        print1();
    }


};
