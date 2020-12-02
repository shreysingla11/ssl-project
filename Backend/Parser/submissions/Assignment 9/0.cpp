#include <iostream>
using namespace std;

class boolfunc
{
    bool value;
    int id=0;
    boolfunc* left = NULL;
    boolfunc* right= NULL;
~boolfunc()
{
delete left;
delete right;
}
/*
    void read()
    {
        int t;
        int nl;
        int v;
        int min;
        int count=0;
        boolfunc* nextl;
        boolfunc* nextp;
        cin>>t;

        for(int i=0; i<t; i++)
        {
            cin>>nl;
               for(int j=0; j<nl; j++)
            {
                cin>>v;
                if(count==0){
                if(v<0)
                {
                min=-1*v;
                id=min;
                nextl=right;
                nextp=left;
                }
                else
                {
                min=v;
                id=min;
                nextl=left;
                nextp=right;
                }
                count++;
                }
                else
                {
                nextp= new boolfunc();
                nextl=new boolfunc();
                nextl->value=false;
                if(v<0)
                {
                nextp->id=-1*v;
                nextp=nextp->left;
                }
                else
                {
                nextp->id=v;
                nextp=nextp->right;
                }
                }

            }
        }
    }
    */
    boolfunc( boolfunc const & v)
    {
    this->id=v.id;
    this->value=v.value;
    this->left=v.left;
    this->right=v.right;
    }
/*
    void operator+=(boolfunc const &v)
    {
    if(this->id==0){if(this->value==false){*this=v;}}
    boolfunc left += (*(this->left));
this->left=&left;
 boolfunc right += (*(this->right))+v;
this->right=&right;
    }
*/
};
int main()
{

}
