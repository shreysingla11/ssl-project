#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;

class boolfunc{
public:
//int num;
//vector<queue<int> > input(num)
class node{
    public:
    node *left;
    node *right;
    node *parent;
    int value;
};
node* start= new node();

int val;
boolfunc(){}
~boolfunc()
{}
node* build(vector<queue <int> > &input,int num,node *par)
    {
     node*ret=new node();
     cout<<2<<"\n";

     ret->parent=par;

     if (input.empty()){ret->value=0;ret->left=NULL;ret->right=NULL;cout<<4<<"\n";return ret;}
     bool check=false;
     for(int i=0;i<num;i++)
        {
         if (input[i].empty()==true){check=true;cout<<8<<"\n";break;}
         else {cout<<10<<"\n";}
        }
     if (check==true){ret->value=-1;ret->left=NULL;ret->right=NULL;cout<<5<<"\n";return ret;}
     vector<queue <int> > a;
     vector<queue <int> > b;

     int j=0;
     int k=0;
     val=input[0].front();
     for (int i=1;i<num;i++)
        {
         int y=abs(input[i].front());
         if(y<val){val=y;}
        }
     for(int i=0;i<num;i++)
        {
         if (input[i].front()==(-val)){a.push_back(input[i]);a[j].pop();j++;}
         if (input[i].front()==(val)){b.push_back(input[i]);b[k].pop();k++;}
         else {a.push_back(input[i]);b.push_back(input[i]);j++;k++;}
        }
     ret->value=val;
     ret->left=build(a,j,ret);
     ret->right=build(a,k,ret);
     a.clear();
     b.clear();
     cout<<7<<"\n";
     return ret;



    }
void operator+(const boolfunc &b)
    {

    }


void read()
    {
     int num;
     cin>>num;
     vector<queue <int> > input(num);
     int temp;
     int temp1;
     for (int i=0;i<num;i++)
        {
         cin>>temp;
         for(int j=0;j<temp;j++)
            {
             cin>>temp1;
             input[i].push(temp1);
            }
        }
     //val=1;
     cout<<1<<"\n";
     start=build(input,num,NULL);
    }

};

int main()
    {
     boolfunc a;
     a.read();
     return 0;
    }
