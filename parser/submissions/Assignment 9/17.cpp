#include<iostream>
#include<cstddef>
#include<vector>
#include<stack>
using namespace std;
/*struct node
{
    char var;
    node* rt;
    node* lt;
};*/
class boolfunc
{
    int var;
    boolfunc* lt;
    boolfunc* rt;
    //node* root;
public:
    boolfunc()
    {}
    ~boolfunc()
    {
        if(lt==NULL&&rt==NULL)
            {
                delete this;
            }
        else if(lt==NULL)
            {
                (*rt).~boolfunc();
                delete this;
            }
        else if(rt==NULL)
            {
                (*lt).~boolfunc();
                delete this;
            }
        else
        {
        (*rt).~boolfunc();
        (*lt).~boolfunc();
        delete this;
        }
    }
    boolfunc (boolfunc const &a)
    {
        this->rt=a.rt;
        this->lt=a.lt;
        this->var=a.var;
    }

    void operator+=(boolfunc const &a) //OR operator
    {/*
        if(a.var==var&&a.var>0)
            {
                a.firsttrue*(a.rt+rt);
            }
        if(lt==NULL&&rt==NULL)
            {
                delete this;
            }
        else if(lt==NULL)
            {
                (*rt).~boolfunc();
                delete this;
            }
        else if(rt==NULL)
            {
                (*lt).~boolfunc();
                delete this;
            }
        else
        {
        (*rt).~boolfunc();
        (*lt).~boolfunc();
        delete this;
        }*/
    }

    void operator*=(boolfunc const &) //AND operator
    {


    }

    void operator~()
    {
        if(lt==NULL&&rt==NULL)
            {
                if(var==0) var=-1;
                else var=0;
            }
        else
        {
        ~(*rt);
        ~(*lt);
        }
    }

    bool operator==(boolfunc const &) //check equality
    {

    }

    /*void read()
    {
        vector<vector <int> > expression;
        int number_of_terms,number_of_literals;
        cin>>number_of_terms;
        for(int i=0;i<number_of_terms;i++)
            {
                cin>>number_of_literals;
                vector <int> temp;
                for(int j=0;j<number_of_literals;j++)
                    {
                        int temp_var;
                        cin>>temp_var;
                        temp.push_back(temp_var);
                    }
                expression.push_back(temp);
            }
        construct(expression);
    }

    void construct(vector<vector <int> > expr)
    {// true==-1?
        if(expr.size()==1)
        {
            vector <int> temp=expr[0];
            if(temp.size()==1)
                {
                    var=temp[0];
                    if(temp[0]<0)
                        {
                            this->rt->var=0;
                            this->lt->var=1;

                        }
                    if(temp[0]>0)
                        {
                            this->rt->var=1;
                            this->lt->var=0;
                        }
                    rt->rt=NULL;
                    rt->lt=NULL;
                    lt->rt=NULL;lt->lt=NULL;
                    return;

                }
            else
                {
                    var=temp[0];
                    if(temp[0]<0)
                        {
                            temp.erase(temp.begin());
                            vector< vector <int> > newtemp;
                            newtemp.push_back(temp);
                            (*(this->lt)).construct(newtemp);
                            this->rt->var=0;
                            rt->rt=NULL;rt->lt=NULL;

                        }
                    if(temp[0]>0)
                        {
                            temp.erase(temp.begin());
                            vector< vector <int> > newtemp;
                            newtemp.push_back(temp);
                            (*(this->rt)).construct(newtemp);
                            this->lt->var=0;
                            lt->rt=NULL;lt->lt=NULL;
                        }
                }
        }

        else
            {   set< set <int> > newtemp1,newtemp2,newtemp3;
                set< set <int> > ::iterator it=expr.begin();
                //for(it=expr.begin();it!=expr.end();it++)
                    {
                        while((*it).first==(*(++it)).first<0)
                        {
                            newtemp1.push_back((*(--it)).erase((*it).begin()));
                        //return((*it).first+(*it).erase((*it).begin()));

                        }
                        if((*it).first==-(*(--it)).first)
                        {
                        newtemp1.push_back((*(it)).erase((*it).begin()));
                        it++;

                        while((*it).first==(*(++it)).first>0)
                        {
                            newtemp2.push_back((*(--it)).erase((*it).begin()));
                        //return((*it).first+(*it).erase((*it).begin()));

                        }
                        while(it!=expr.end())
                        {
                            newtemp3.push_back(*it);
                        }
                        }
                        else
                        {
                           while(it!=expr.end())
                        {
                            newtemp3.push_back(*it);
                        }
                        }
                    }

            }
    }*/

void print()
    {
        int totalnodes=0;
        if(lt==NULL&&rt==NULL)
            {
                //cout<<totalnodes<<endl;
                if(var==1) totalnodes++;

            }
        else
        {
            stack <int> mystack1,mystack2;
            {
                mystack1.push(-var);
                (*lt).print();
                mystack2.push(var);
                (*rt).print();
                while (!mystack1.empty())
                {
                    cout << ' ' << mystack1.top();
                    mystack1.pop();
                }
                 while (!mystack2.empty())
                {
                    cout << ' ' << mystack2.top();
                    mystack2.pop();
                }

            }
        }
    }
private:

boolfunc firsttrue(boolfunc const & a)
    {
        boolfunc first;
        first.var=a.var;
        first.rt->var=1;
        first.lt->var=0;
        first.rt->rt=NULL;first.rt->lt=NULL;
        first.lt->rt=NULL;first.lt->lt=NULL;
    }
boolfunc firstfalse(boolfunc const & a)
    {
        boolfunc first;
        first.var=a.var;
        first.rt->var=0;
        first.lt->var=1;
        first.rt->rt=NULL;first.rt->lt=NULL;
        first.lt->rt=NULL;first.lt->lt=NULL;
    }

};
