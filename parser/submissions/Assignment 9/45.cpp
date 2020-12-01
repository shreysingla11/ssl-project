#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int counter_ones;
vector<int> check;

//struct node
//{
//    int data;
//    node* left, right;
//}


class boolfunc
{

    int data;
    boolfunc* left;
    boolfunc* right;
    //int size_of_tree;

public:

    boolfunc()
    {
        data = 0;
        left = NULL;
        right = NULL;
    }

    ~boolfunc()
    {
        delete left;
        delete right;
    }

    boolfunc (boolfunc const& a)
    {
        //node* copyroot;
        //copyroot = new node;
        //copyroot->data = (a.root)->data;
        data = a.data;
        //size_of_tree = a.size_of_tree;
        if(a.left != NULL)
        {
            *(left) = *(a.left);
        }
        else
        {
            left = NULL;
        }
        if(a.right != NULL)
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
        boolfunc new_boolfunc;
        if(data == 0)
        {
            new_boolfunc = a;
        }
        else if(a.data == 0)
        {
            new_boolfunc = *this;
        }
        else if((a.data == -1 || data == -1))
        {
            new_boolfunc.data = -1;
            new_boolfunc.right = NULL;
            new_boolfunc.left = NULL;
        }
        else
        {
            if( data >  a.data)
            {
                new_boolfunc.data = a.data;
                *(new_boolfunc.left) = *(a.left) + *this;
                *(new_boolfunc.right) = *(a.right) + *this;
            }
            else if(data < a.data)
            {
                new_boolfunc.data = data;
                *(new_boolfunc.left) = *(left) + a;
                *(new_boolfunc.right) = *(right) + a;
            }
            else
            {
                new_boolfunc.data = a.data;
                *(new_boolfunc.left) = *(left) + *(a.left);
                *(new_boolfunc.left) = *(right) + *(a.right);
            }
        }

        return new_boolfunc;
    }


    void operator+=(boolfunc const &a)
    {
        *this = *this + a;
    }


    boolfunc operator*(boolfunc const &a)
    {
        boolfunc new_boolfunc;

        if((a.data == 0 || data == 0))
        {
            new_boolfunc.data = 0;
            new_boolfunc.right = NULL;
            new_boolfunc.left = NULL;
        }
        else if( a.data == -1 )
        {
            new_boolfunc = a;
        }
        else if( data == -1 )
        {
            new_boolfunc = *this;
        }

        else
        {
            if( data >  a.data)
            {
                new_boolfunc.data = a.data;
                *(new_boolfunc.left) = *(a.left) * *this;
                *(new_boolfunc.right) = *(a.right) * *this;
            }
            else if(data < a.data)
            {
                new_boolfunc.data = data;
                *(new_boolfunc.left) = *(left) * a;
                *(new_boolfunc.right) = *(right) * a;
            }
            else
            {
                new_boolfunc.data = a.data;
                *(new_boolfunc.left) = *(left) * *(a.left);
                *(new_boolfunc.left) = *(right) * *(a.right);
            }
        }

        return new_boolfunc;
    }

    void operator*=(boolfunc const &a)
    {
        *this = *this * a;
    }

    void operator~()
    {
        if(data == -1)
        {
            data = 0;
        }
        else if(data == 0)
        {
            data = -1;
        }
        else
        {
            ~*(left);
            ~*(right);
        }
    }

    bool operator==(boolfunc const &a)
    {
        if ( (data == a.data) && ( *(left) == *(a.left) ) && ( *(right) == *(a.right) ) )
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void read()
    {
        (*this).data = 0;
        int number_of_terms;
        cin>>number_of_terms;
        int counter2 = number_of_terms;
        while(counter2>0)
        //for(int i=0; i<number_of_terms; i++)
        {
            int number_of_variables;
            cin>>number_of_variables;
            boolfunc *main_temp = new boolfunc;
            main_temp->data = -1;
            int counter = number_of_variables;
            while(counter>0)
            //for(int j=0; j<number_of_variables; j++)
            {
                int value;
                cin>>value;
                boolfunc *temp = new boolfunc;
                boolfunc *temp_left = new boolfunc;
                boolfunc *temp_right = new boolfunc;
                temp->data = abs(value);
                temp_left->data = 0;
                temp_right->data = -1;
                //cout<<"YO1"<<endl;
                temp->left = temp_left;
                temp->right = temp_right;
                if(value < 0)
                {
                    //cout<<"Yo"<<endl;
                    ~*(temp);
                }
                //cout<<"Yo2"<<endl;
                *main_temp *= *temp;
                //cout<<"Yo1"<<endl;
                counter--;
            }

            //cout<<"Yoooo"<<endl;
            (*this) += *main_temp;
            counter2--;
        }
    }

    void re_print()
    {
        if(data == -1)
        {
            cout<<check.size()<<endl;
            for(int i=0; i<check.size(); i++)
            {
                cout<<check[i]<<" ";
            }
            check.pop_back();
            cout<<endl;
        }
        else if(data != 0)
        {
            check.push_back(-1 * data);
            left->re_print();
            check.pop_back();
            check.push_back(data);
            right->re_print();
            check.pop_back();
        }
    }

    void print()
    {
        cout<<count_ones()<<endl;
        re_print();
    }

    int count_ones()
    {
        if(data == -1)
        {
            return 1;
        }
        if(data != -1 && data != 0)
        {
            return (this->right)->count_ones() + (this->left)->count_ones();
        }
        else
        {
            return 0;
        }
    }

    int count_zeroes()
    {
        if(data == 0)
        {
            return 1;
        }
        if(data != -1 && data != 0)
        {
            return (this->right)->count_zeroes() + (this->left)->count_zeroes();
        }
        else
        {
            return 0;
        }
    }


};

/*
int main()
{
    //cout<<"Hi";
    boolfunc a;
    a.read();
    //cout<<"Yp";
    //a.print();
}

*/
