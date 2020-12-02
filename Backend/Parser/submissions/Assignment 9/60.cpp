#include <iostream>;
using namespace std;
struct nodes
{
    nodes *left,*right;
    int i;
};
class boolfunc
{
public:
    nodes *node;
    boolfunc() {}
    ~boolfunc() {}
    boolfunc( boolfunc const &f)
    {

    }
    void operator*=(boolfunc const &f)
    {




    }
    void operator+=(boolfunc const &f)
    {
        if((this->node)->i==(f.node)->i)
        {



        }


    }
    void operator~(){}

    void read()
    {
        int n;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            int terms;
            cin>>terms;
            int *a;
            a=new int[terms];
            for(int j=0; j<terms; j++)
            {
                cin>>a[j];
            }

        }
    }
    void print(){}
    void subst(int i, bool v){}
};
/*int main()
{
    boolfunc s;
    s.read();
    return 0;
}*/
