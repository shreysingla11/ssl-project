#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class boolfunc
{
    struct Node
    {
        int num;
        bool neg;
    };
    struct Tree
    {
        int node;
        Tree *L;
        Tree *R;
    };
    Tree *tree = new Tree;
    //tree = new Tree;
public:
    //boolfunc();
    //~boolfunc();
    void CreateTree(vector< queue<Node> > &Q,Tree *treePtr)
    {
        if(!Q[0].empty())
        {
            int i=0;
            int leftStart,leftEnd,RightStart,RightEnd;
            treePtr->L=new Tree;
            treePtr->R=new Tree;
            treePtr->node=Q[0].front().num;
            while(Q[i].front().neg==true && Q[i].front().num==Q[0].front().num )
            {
                if(i!=0)
                    Q[i].pop();
                i++;
                if(i==Q.size())
                    break;
            }
            leftStart=0;
            leftEnd=i-1;
            RightStart=i;
            while(Q[i].front().neg==false && Q[i].front().num==Q[0].front().num)
            {
                if(i!=0)
                    Q[i].pop();
                i++;
                if(i==Q.size())
                    break;
            }
            RightEnd=i-1;
            Q[0].pop();
            if(leftStart>leftEnd)
            {
                if(RightEnd==Q.size()-1)
                {
                    treePtr->L->node=0;
                    treePtr->L->L=NULL;
                    treePtr->L->R=NULL;
                }
                else
                {
                    vector< queue<Node> >::const_iterator first = Q.begin() + RightEnd+1;
                    vector< queue<Node> >::const_iterator last = Q.begin() + Q.size();
                    vector< queue<Node> > newVec(first, last);
                    CreateTree(newVec,treePtr->L);
                }
                vector< queue<Node> >::const_iterator first = Q.begin() + 0;
                vector< queue<Node> >::const_iterator last = Q.begin() + Q.size();
                vector< queue<Node> > newVec(first, last);
                CreateTree(newVec,treePtr->R);
            }
            else
            {
                if(RightStart>RightEnd)
                {
                    if(leftEnd==Q.size()-1)
                    {
                    treePtr->R->node=0;
                    treePtr->R->L=NULL;
                    treePtr->R->R=NULL;
                    }
                    else
                    {
                    vector< queue<Node> >::const_iterator first = Q.begin() + leftEnd+1;
                    vector< queue<Node> >::const_iterator last = Q.begin() + Q.size();
                    vector< queue<Node> > newVec(first, last);
                    CreateTree(newVec,treePtr->R);
                    }
                    vector< queue<Node> >::const_iterator first = Q.begin() + 0;
                    vector< queue<Node> >::const_iterator last = Q.begin() + Q.size();
                    vector< queue<Node> > newVec(first, last);
                    CreateTree(newVec,treePtr->L);
                }
                else
                {
                    vector< queue<Node> >::const_iterator first = Q.begin() + RightStart;
                    vector< queue<Node> >::const_iterator last = Q.begin() + Q.size();
                    vector< queue<Node> > newVec(first, last);
                    CreateTree(newVec,treePtr->R);
                    Q.erase(Q.begin()+RightStart,Q.begin()+RightEnd+1);
                    CreateTree(Q,treePtr->L);
                }
            }
        }
        else
        {
            treePtr->node=-1;
            treePtr->L=NULL;
            treePtr->R=NULL;
        }
    }
    void read()
    {
        int n;
        vector< queue<Node> > Q;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            queue<Node> q;
            int m;
            cin>>m;
            for(int j=0; j<m; j++)
            {
                int var;
                cin>>var;
                Node n;
                if(var>0)
                {
                    n.neg=false;
                    n.num=var;
                }
                else
                {
                    n.neg=true;
                    n.num=-var;
                }
                q.push(n);
            }
            Q.push_back(q);
        }
        CreateTree(Q,tree);
    }
    void print()
    {

    }
};
int main()
{
boolfunc f;
f.read();
return 0;
}
