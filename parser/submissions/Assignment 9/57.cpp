#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

class boolfunc
{
    bool x1;
    int id;
    boolfunc * left;
    boolfunc *right;

    public:
    bool getvalue()
    {
        return x1;
    }

    boolfunc()
    {
    }

    ~boolfunc()
    {
    }

    boolfunc( boolfunc &b)
    {
        x1 = b.getvalue();
    }

    void operator+=(boolfunc &b)
    {
        if(b.getvalue())
            x1 = -1;
    }

    void operator*=(boolfunc &b)
    {
        if(b.getvalue() == 0)
            x1 = 0;
    }

    void operator~()
    {
        if(x1)
            x1 = 0;
        else
            x1 = -1;
    }

    bool operator==(boolfunc &b)
    {
        if((x1!=0)&&(b.getvalue()!=0))
            return -1;
        else
        {
            if((x1==0)&&(b.getvalue()==0))
                return -1;
            else
                return 0;
        }
    }

    void read_data(vector< vector<int> > &twoDVector, boolfunc * b)
    {
        int tdsize = twoDVector.size();
        if(tdsize == 0)
            return;

        int odsize;
        int min = abs(twoDVector[0][0]);
        for(int i = 0; i<tdsize; i++)
        {
            odsize = twoDVector[i].size();
            for(int j = 0; j<odsize; j++)
            {
                if(abs(twoDVector[i][j])<min)
                    min = abs(twoDVector[i][j]);
            }
        }
        //got the min literal
        b->id = min;
        b->left = new boolfunc;
        b->right = new boolfunc;
        vector<int> c(tdsize);
        //to assign the values of c
        for(int i = 0; i<tdsize; i++)
        {
            odsize = twoDVector[i].size();
            c[i]=0;
            for(int j = 0; j<odsize; j++)
            {
                if(twoDVector[i][j]==min)
                {
                    c[i]=1;
                }
                if(twoDVector[i][j]==(-min))
                {
                    c[i]=-1;
                }
            }
        }
        //to assign the left and right subtrees of given trees
        vector<vector <int> > lTwoDVector;
        vector<vector <int> > rTwoDVector;
        for(int i = 0; i<tdsize; i++)
        {
            odsize = twoDVector[i].size();
            vector<int> lOneDVector;
            vector<int> rOneDVector;
            if(c[i]==(-1))//will go the left subtree
            {
                for(int j = 1; j<odsize; j++)
                {
                    lOneDVector.push_back(twoDVector[i][j]);
                }
                lTwoDVector.push_back(lOneDVector);
            }
            else
            {
                if(c[i]==1)//will go the right subtree
                {
                    for(int j = 1; j<odsize; j++)
                    {
                        rOneDVector.push_back(twoDVector[i][j]);
                    }
                    rTwoDVector.push_back(rOneDVector);
                }
                else//will go to both subtree
                {
                    for(int j = 0; j<odsize; j++)
                    {
                        lOneDVector.push_back(twoDVector[i][j]);
                    }
                    lTwoDVector.push_back(lOneDVector);
                    for(int j = 0; j<odsize; j++)
                    {
                        rOneDVector.push_back(twoDVector[i][j]);
                    }
                    rTwoDVector.push_back(rOneDVector);

                }
            }
        }//end of outer for loop

        read_data(lTwoDVector, b->left);
        read_data(rTwoDVector, b->right);

    }//end of read_data()

    void print_data(boolfunc * b)
    {

    }

    void print()
    {
        print_data(this);
    }

    void read()
    {
        int nterms;
        cin>>nterms;
        int nliterals;
        vector<vector <int> > twoDVector(nterms);
        int variables;
        for(int i = 0; i<nterms; i++)
        {
            cin>>nliterals;
            vector<int> oneDVector(nliterals);

            for(int j = 0; j<nliterals; j++)
            {
                cin>>oneDVector[j];
            }
            twoDVector.push_back(oneDVector);
        }
        read_data(twoDVector, this);
    }
};//end of class boolfunc
