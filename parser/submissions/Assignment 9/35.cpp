#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<queue>
#include<cmath>


using namespace std;

class boolfunc
{
    public:
        vector<queue<int> > v;
        struct node
        {
            int x;
            node *l;
            node *r;
            node *p;
        };
        node *n = new node();

        boolfunc() {}

        ~boolfunc()
        {
            delete n;
        }

        boolfunc( boolfunc const &obj)
        {
            n = new node;
            *n = *obj.n;
        }

        void operator+=(boolfunc const &obj)
        {
            delete n;
            node *nx =new node();
            vec
        }

        void operator*=(boolfunc const &obj)
        {
            node *nx =new node();

        }

        node * tree(vector<queue<int> > &vec,int n,node *p)
        {
            node *nx = new node();
            nx->p=p;
            if(n>0)
            {
                bool c=false;
                int x,y;
                if(vec[0].empty()==true){c=true;}
                else{ x=abs(vec[0].front());}
                for(int s=0;s<n;s++)
                {
                    if(vec[s].empty()==true){c=true;break;}
                    else
                    {y=abs(vec[s].front());x=min(x,y);}
                }
                if(c==true)
                {
                    nx->x=-1;
                    nx->l = NULL;
                    nx->r = NULL;
                    return nx;
                }
                nx->x = x;
                vector<queue<int> > a;
                vector<queue<int> > b;
                int i=0,j=0,k=0;
                while(i<n)
                {
                    if(vec[i].front()==-x){a.push_back(vec[i]);a[j].pop();j++;}
                    else if(vec[i].front()==x ){b.push_back(vec[i]);b[k].pop();k++;}
                    else {a.push_back(vec[i]);b.push_back(vec[i]);j++;k++;}
                    i++;
                }
                //cout<<"fd"<<endl;
                nx->l = new node;
                nx->r = new node;
                //cout<<"fd"<<endl;
                nx->l = tree(a,j,nx);
                nx->r = tree(b,k,nx);
                //cout<<"fd"<<endl;
                return nx;
            }
            else
            {
                nx -> x=0;
                nx -> l=NULL;
                nx -> r=NULL;
                return nx;
            }

        }

        void read()
        {
            int n,m,t;
            cin>>n;
            vector<queue<int> > vec(n);
            v.resize(n);
            for(int i=0;i<n;i++)
            {
                cin>>m;
                for(int j=0;j<m;j++) {cin>>t;vec[i].push(t);v[i].push(t);}
            }
            n=tree(vec,n,NULL);
        }

        void print()
        {
            vector<queue<int> > qq;

        }
};

int main()
{
    boolfunc a;
    a.read();
}
