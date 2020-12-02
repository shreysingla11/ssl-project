#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
using namespace std;




class boolfunc
{

    public:

    struct node{

        int value;
        node* left;
        node* right;

        };
        node *nx = new node();



        node* buildtree(vector<queue<int> > &term , int numterm)
    {

            node *x=new node();

            if(term.empty())
                {
                x->value = 0;
                x->left =NULL;
                x->right = NULL;
                return x;
            }





        vector< queue<int> > l;
        vector< queue <int> > r;

        int leftnum,rightnum;
    //check for min
        int frontmin= 101000;

        bool check = false;
        for(int z=0;z<numterm;z++)
        {
            if(term[z].empty()){check = true;break;}
            if(abs(term[z].front())<frontmin)frontmin=term[z].front();


        }

        if(check == true)
        {
        x->value =-1;
        x->left =NULL;
        x->right = NULL;
        return x;
        }

        for( int k = 0;k<numterm;k++)
        {
            if(term[k].front()==-frontmin){l.push_back(term[k]);l[leftnum].pop() ;leftnum++;}
            else if(term[k].front()==frontmin){l.push_back(term[k]);r[rightnum].pop() ;rightnum++;}
            else {
                r.push_back(term[k]);
                l.push_back(term[k]);
                leftnum++;
                rightnum++;

            }
        }
        x->left = new node();
        x->right = new node();
        x->left = buildtree(l , leftnum);
        x->right =buildtree(r,rightnum);
        return x;

    }



        boolfunc(){};
        ~boolfunc(){};

        void read()
        {
            int numterm;
            cin>>numterm;
            vector<queue<int> > term(numterm);
            for(int i =0;i<numterm;i++)
            {
                int numlit;
                cin>>numlit;
                int temp;
                for(int k=0;k<numlit;k++)
                    {
                       cin>>temp;
                        term[i].push(temp);

                    }

            }




            nx=buildtree(term, numterm);


        }


};


int main()
{
boolfunc h;
h.read();

}
