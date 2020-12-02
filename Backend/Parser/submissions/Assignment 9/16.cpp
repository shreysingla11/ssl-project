#include<iostream>
#include<queue>
#include<cmath>
using namespace std;

class boolfunc{
struct node{
int val;
node*p;
node* left;
node* right;
};
node* root;
void build(vector<queue>& input);
public:
void read();
};

void boolfunc::read()
{

vector<queue> input;

int num_terms;
cin>>num_terms;

for(int i=0;i<num_terms;i++)
    {
        queue<int> term;
        int size=0;
        cin>>size;
        int num=0;
        for(int i=0;i<size;i++)
        {
        cin>>num;
        term.push(num);
        }
        input.push_back(term);
    }

    build(input);
}

node* build(vector<queue>&input)
{

    vector<queue> in=input;
    int num_terms=input.size();
    int min=abs(input[i].front());
    int min_index=0;
    for(int i=0;i<num_terms;i++)
        {
            if(abs(input[i].front()<min)
            {
                min=abs(input[i].front();
                min_index=i;
            }
        }
    node * n=new node;
    for(int i=0;i<num_terms;i++)
    {
        if(min==abs(in[i].front()))
        {
            if(in[i].front()<0)
            {
                in[i].pop();

            }
            else
            {
            in.erase(in.begin()+i)
            }
        }
    }
    n->val=min;
    n->left=build(in);
    in=input;
for(int i=0;i<num_terms;i++)
    {
        if(min==abs(in[i].front()))
        {
            if(input[i].front()>0)
            {
                in[i].pop();
                if(in[i].empty())
                {
                    n->val=-1;
                }

            }
            else
            {
            in.erase(in.begin()+i)
            }
        }
    }
    n->right=build(in);

return n;

}

