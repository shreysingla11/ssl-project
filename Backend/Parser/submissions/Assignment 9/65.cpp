#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

class boolfunc
{
private:
    class node
    {
        public:
            int data;
            node *left;
            node *right;

            node()
            {
                data = -10;
                left = NULL;
                right = NULL;
            }

            node(int val,node* l, node* r)
            {
                data = val;
                left = l;
                right = r;
            }


    };

    node *root;
    vector<vector<int> > bVector;

public:
    boolfunc() {}

    ~boolfunc()
    {
        destroy_tree(root);
    }

    boolfunc( boolfunc const &tree )
    {
        root = tree.root;
    }

    void operator+=(boolfunc const &tree)
    {


    }

    void operator*=(boolfunc const &tree)
    {


    }

    void operator==(boolfunc const &tree)
    {


    }

    void operator~()
    {


    }

    void read()
    {
        int i,j;
        int nSum;
        int nProd;
        int x;

        vector<int> sVector;

        cin >> nSum;

        for(i = 0; i < nSum ; i++)
        {
            cin >> nProd;
            sVector.clear();

            for(j = 0; j < nProd; j++)
            {
                cin >> x;
                sVector.push_back(x);
            }

            bVector.push_back(sVector);

        }

        root = convert_from_vector(bVector);

    }

    void print()
    {
       /* cout << root->data << endl;
        cout << root->left->data << endl;
        cout << root->right->data << endl;
        */
        int z = bVector.size();
        cout << z << endl;
        for(int i = 0;i < bVector.size();i++ )
        {
            int x = bVector[i].size();
            cout << x << endl;
            for (int j = 0 ; j < x ; j++ )
            {
                cout << bVector[i][j] << " " ;
            }
            cout << endl;

        }

    }

    void subst(int i, bool v)
    {


    }

private:

    node *convert_from_vector(vector<vector<int> > Vector)
    {
        int len,i;
        int var_1;
        node *Root;
        vector<vector<int> > Vec1;
        vector<vector<int> > Vec2;
        vector<vector<int> > VecC;

        if(Vector.empty())
        {
            Root = new node;
            Root->data = 0;
            // return Root;
            return NULL;
        }

        len = Vector.size();
        var_1 = (Vector.front()).front();
        Root = new node;
        Root->data = abs(var_1);

        if( len == 1 )
        {
            if( (Vector.front()).size() == 1 )
            {
                if( var_1 == Root->data )
                {
                    Root->left = new node(0,NULL,NULL);
                    Root->right = new node(-1,NULL,NULL);
                }
                else
                {
                    Root->left = new node(-1,NULL,NULL);
                    Root->right = new node(0,NULL,NULL);
                }
            }
            return Root;
        }

        for(i = 0; i < len ; i++)
        {
            if( Vector[i].front() == -1*(Root->data) )
            {
                Vector[i].erase(Vector[i].begin());
                Vec1.push_back(Vector[i]);
            }
            else
            {
                if( Vector[i].front() == Root->data )
                {
                    Vector[i].erase(Vector[i].begin());
                    Vec2.push_back(Vector[i]);
                }
                else
                {
                    VecC.push_back(Vector[i]);
                }
            }
        }
        Vec1.insert(Vec1.end(), VecC.begin(), VecC.end());
        Vec2.insert(Vec2.end(), VecC.begin(), VecC.end());

        std::sort(Vec1.begin(), Vec1.end() ,myfunc);
        std::sort(Vec2.begin(), Vec2.end() ,myfunc);


        Root->left = convert_from_vector(Vec1);
        Root->right = convert_from_vector(Vec2);

        return Root;
    }

    vector<vector<int> > convert_to_vector(node *root)
    {


    }

    void destroy_tree(node *leaf)
    {
      if(leaf!=NULL)
      {
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);
        delete leaf;
      }
    }

    static bool myfunc(const vector<int>& a, const vector<int>& b)
    {
        if(b.empty()){return true;}
        if(a.empty()){return false;}

        return a[0] < b[0];
    }

    void negation(node *leaf)
    {


    }

};

int main()
{
    boolfunc test;
    test.read();
    test.print();
    return 0;

}
