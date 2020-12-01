#include<iostream>
#include<vector>
using namespace std;
class boolfunc{
    class node{
        public:
        int x;
        node *left, *right;
        node()
        {
            x=0;
            left=right=NULL;
        }
    };
    node *root;
    vector<vector<int> > V;
    node* convert_to_tree(vector<vector<int> > &V,int min)
    {
        node *ptr;
        if(V.empty())
            {
                ptr->x=0;
                ptr->left=NULL;
                ptr->right=NULL;
                return ptr;
            }
        vector<vector<int> > Vleft,Vright;
        vector<int> vleft,vright;
        int i,j,minl=0,minr=0;
        bool left_tree=false,right_tree=false;
        for(i=0;i<V.size();i++)
        {

            if(V[i][0]==min){
                if(V[i].size()==1)
                    right_tree=true;
                if(V[i][1]<minr||minr==0)
                    minr=V[i][1];
                for(j=1;j<V[i].size();j++)
                    vright.push_back(V[i][j]);
                if(vright.size())
                    Vright.push_back(vright);
            }
            else if(V[i][0]==-min){
                if(V[i].size()==1)
                    left_tree=true;
                if(V[i][1]<minl||minl==0)
                    minl=V[i][1];
                for(j=1;j<V[i].size();j++)
                    vleft.push_back(V[i][j]);
                if(vleft.size())
                    Vleft.push_back(vright);
            }
            else{
                if(V[i][1]<minr||minr==0)
                    minr=V[i][1];
                for(j=1;j<V[i].size();j++)
                    vright.push_back(V[i][j]);
                if(vright.size())
                    Vright.push_back(vright);
                if(V[i][1]<minr||minr==0)
                    minr=V[i][1];
                for(j=1;j<V[i].size();j++)
                    vright.push_back(V[i][j]);
                if(vright.size())
                    Vright.push_back(vright);
            }
        }
        if(left_tree&&right_tree)
            return NULL;
        else if(left_tree)
            {
                ptr->x=min;
                node *ptr1;
                ptr1->x=-1;
                ptr1->left=ptr1->right=NULL;
                ptr->left=ptr1;
                ptr->right=convert_to_tree(Vright,minr);
                return ptr;
            }
        else if(right_tree)
            {
                ptr->x=min;
                node *ptr1;
                ptr1->x=-1;
                ptr1->left=ptr1->right=NULL;
                ptr->right=ptr1;
                ptr->left=convert_to_tree(Vleft,minl);
                return ptr;
            }
        ptr->x=min;
        ptr->left=convert_to_tree(Vleft,minl);
        ptr->right=convert_to_tree(Vright,minr);
        return ptr;
    }
    void delete_tree(node *root)
    {
        if(!root)
            return;
        delete_tree(root->left);
        delete_tree(root->right);
        delete root;
        return;
    }
    public:
    boolfunc(){
        root=NULL;
    }
    boolfunc(boolfunc const &f){
        root=f.root;
    }
    boolfunc(node *r){
        root=r;
    }
    ~boolfunc(){
        delete_tree(root);
    }
    void read(){
        int n,m,data;
        cin>>n;
        //cout<<"Read";
        for(int i=0;i<n;i++)
        {
            vector<int> v;
            cin>>m;
            for(int j=0;j<m;j++)
            {
                cin>>data;
                v.push_back(data);
            }
            //cout<<"Read";
            V.push_back(v);
            v.clear();
        }

        root=convert_to_tree(V,1);
    }
    bool operator==(boolfunc const &f){
        if(root->x==(f.root)->x)
            return (root->left==(f.root)->left)&&(root->right==(f.root)->right);
        else
            return false;
    }
    void operator+=(boolfunc const &f){
        if(root->x==(f.root)->x){
            boolfunc(root->left)+=boolfunc((f.root)->left);
            boolfunc(root->right)+=boolfunc((f.root)->right);
            }
        else if(root->x<(f.root)->x){
            boolfunc(root->left)+=boolfunc(f.root);
            boolfunc(root->right)+=boolfunc(f.root);
            }
        else{
            boolfunc(root->left)+=boolfunc(f.root);
            boolfunc(root->right)+=boolfunc(f.root);
            }
    }
    void operator*=(boolfunc const &f){
        if(root->x==(f.root)->x){
            boolfunc(root->left)*=boolfunc((f.root)->left);
            boolfunc(root->right)*=boolfunc((f.root)->right);
            }
        else if(root->x<(f.root)->x){
            boolfunc(root->left)*=boolfunc(f.root);
            boolfunc(root->right)*=boolfunc(f.root);
            }
        else{
            boolfunc(root->left)*=boolfunc(f.root);
            boolfunc(root->right)*=boolfunc(f.root);
            }
    }
    vector<vector<int> > get_vector(node *root)
    {
        vector<vector<int> > v,vleft,vright;
        vector<int> temp;
        int i;
        if(root->left->x==0&&root->right->x==-1)
            {temp.push_back(root->x);v.push_back(temp);return v;}
        else if(root->left->x==-1&&root->right->x==0)
            {temp.push_back(-root->x);v.push_back(temp);return v;}
        vleft=get_vector(root->left);
        vright=get_vector(root->right);
        for(i=0;i<vleft.size();i++)
        {
            vleft[i].insert(vleft[i].begin(),-root->x);
            v.push_back(vleft[i]);
        }
        for(i=0;i<vright.size();i++)
        {
            vright[i].insert(vright[i].begin(),root->x);
            v.push_back(vright[i]);
        }
    }
    void print(){
        //cout<<"Print";
        vector<vector<int> > output=get_vector(root);
        int i,j;
        cout<<output.size()<<endl;
        for(i=0;i<output.size();i++)
        {
            cout<<output[i].size()<<endl;
            for(j=0;j<output[i].size();j++)
                cout<<output[i][j]<<' ';
            cout<<endl;
        }
    }
};
int main()
{
    boolfunc f;
    f.read();
    f.print();
}
