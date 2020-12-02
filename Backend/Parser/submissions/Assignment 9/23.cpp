#include<iostream>
#include<vector>
using namespace std;
class boolfunc
{
    boolfunc* left;
    boolfunc* right;
    int data;
public:
    boolfunc() {};
    ~boolfunc() {};
    boolfunc(boolfunc const &f);
    void operator+=(boolfunc const &f)
    {
        boolfunc t;
        t.data=-1;
        if((this)->data==-1 || (f).data==-1){*this=t;return;}
        if((this)->data==0){*this=f;return;}
        if(f.data==0){return;}
        if(this->data==f.data)
        {
            *(this->left)+=*(f.left);
            *(this->right)+=*(f.right);
            return;
        }
        else
        {
            if(this->data<f.data)
            {
                *(this->left)+=f;
                *(this->right)+=f;
                return;
            }
        }
    };
    void operator*=(boolfunc const &f)
    {

    };
    void operator~();
    bool operator==(boolfunc const &f);
    void read()
    {
        int lines;
        int d,m;
        boolfunc ad;
        (ad.left)->data=0;
        (ad.right)->data=-1;
        vector<vector<boolfunc> >abstract;
        cin>>lines;
        for(int i=0; i<lines; i++)
        {
            vector<boolfunc>temp;
            cin>>m;
            for(int j=0; j<m; j++)
            {
                cin>>d;
                ad.data=d;
                temp.push_back(ad);
            }
            abstract.push_back(temp);
        }
        for(int i=0; i<abstract.size(); i++)
        {
            for(int j=1; j<abstract[i].size(); j++)
            {
                abstract[i][j]*=abstract[i][j-1];
            }
            if(i==0)
            {
                *this=abstract[i].back();
            }
            else
            {
                *this+=abstract[i].back();
            }
        }
    };
    void print(){
    }
};
int main()
{

}
