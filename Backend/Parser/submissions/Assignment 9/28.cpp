#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
class nik
{
    public:
    int i;
    nik * right;
    nik * left;
    nik()
    {
        i = -5;
        left = NULL;
        right = NULL;
    }
    void operator +=(nik const & myarg)
    {
        if(i == myarg.i && i>=1)
        {
            *left += *(myarg.left);
            (*right)+=*(myarg.right);
        }
        if(i > myarg.i && i>=1)
        {

        }
    }
};
class boolfunc
{
public:
    nik * ptr;
    boolfunc()
    {

    }
    ~boolfunc()
    {

    }
    void read()
    {

        int lines;
        cin>>lines;
        int lit;
        int value;
        for(int x = 0; x<lines; x++)
        {
            boolfunc * a = new boolfunc;
            boolfunc * answer;
            answer = a;
            cin>>lit;
            for(int p = 0; p<lit; p++)
            {
                cin>>value;
                if(value <0)
                {
                    a->ptr->i = -value;
                    a->ptr->left = new nik;
                    a->ptr->right = new nik;
                    a->ptr->right->i = 0;
                    a->ptr = a->ptr->left;
                }
                if(value>0)
                {
                    a->ptr->i = value;
                    a->ptr->left = new nik;
                    a->ptr->right = new nik;
                    a->ptr->left->i = 0;
                    a->ptr = a->ptr->right;
                }
            }
            a->ptr->i = -1;
            this+=answer;
        }

    }

    void operator+=(boolfunc const & arg)
    {
        (*ptr)+=(arg.ptr);
    }
};


int main()
{


















}
