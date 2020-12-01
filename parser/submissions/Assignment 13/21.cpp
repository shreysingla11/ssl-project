#include<iostream>
#include<vector>
#include<queue>
#include <limits>



int inf = std::numeric_limits<int>::max();
using namespace std;
class node
    {
        public:
        int name;
        int val;
        int type;
        int shortest;
    };
int main()
{
int n;
queue <node> q;
cin>>n;
vector <node> row(n);
vector <vector <node> > matrix(n);
node first;
first.val=0;
first.type=0;
first.name=0;
q.push(first);
for(int i=0;i<n;i++)
{
    vector <node> temp(n);
    for(int j=0;j<n;j++)
        {
            int newval;
            cin>>newval;
           /* if(i==j && newval>0)
                {
                    temp[j].val=temp[j].type=0;
                    temp[j].name=i;
                }
            else{*/
            if(newval>0)
                {
                    temp[j].val=newval;
                    temp[j].type=-1;
                    temp[j].name=i;

                }
            else
                {
                    temp[j].val=-newval;
                    temp[j].type=1;
                    temp[j].name=i;
                    if(i==0 && j!=0 || i!=0)
                    q.push(temp[j]);
                }
                temp[j].shortest=inf;

            //cout<<temp[j];
            //}
        }
    matrix[i]=temp;
}
matrix[0][0].shortest=0;
/*for(int i=0;i<n;i++)
{

    for(int j=0;j<n;j++)
        {
            node print=matrix[i][j];
            cout<<print.val<<' ';
            cout<<print.type<<"  ";

        }
        cout<<endl;
}*/
vector <int> shortest(n);
vector <int> goodness(n);
for(int i=1;i<n;i++)
    {

        shortest[i]=matrix[0][i].val;
        goodness[i]=matrix[0][i].type;
    }
/*for(int i=1;i<n;i++)
    {

        shortest[i]=inf;
        goodness[i]=matrix[0][i].type;
    }*/





/*for(int i=0;i<n;i++)
    {
        q.push(matrix[i][0]);
    }*/
//q.push(matrix[0][0]);
while(!q.empty())
    {
        node v=q.front();
        q.pop();
        //cout<<"considering parent "<<v.name<<endl;

        for(int i=0;i<n;i++)
            {
               //cout<<matrix[v.name][i].val<<' '<<matrix[v.name][i].type<<endl;
                if(i!=v.name)
                    {
                        //cout<<"considering successor "<<i<<endl;
                        //cout<<shortest[i]<<' '<<goodness[i]<<endl;

                        if(goodness[i]<0)
                            {
                                //cout<<"into negative goodness "<<i<<endl;
                                if(goodness[v.name]+matrix[v.name][i].type>=0)
                                    {
                                        //cout<<"goodness improving\n";
                                        shortest[i]=shortest[v.name]+matrix[v.name][i].val;
                                        goodness[i]=goodness[v.name]+matrix[v.name][i].type;
                                        q.push(matrix[v.name][i]);
                                    }
                            }
                        else if(shortest[v.name]+matrix[v.name][i].val<=shortest[i] && goodness[v.name]+matrix[v.name][i].type>=0)
                            {
                                shortest[i]=shortest[v.name]+matrix[v.name][i].val;
                                goodness[i]=goodness[v.name]+matrix[v.name][i].type;
                                q.push(matrix[i][v.name]);
                                //cout<<"pushed in "<<i<<endl;
                            }
                    }

            }
    }

    for(int i=0;i<n;i++)
        {
            if(goodness[i]>=0)
                {
                    cout<<shortest[i]<<endl;
                }
            else
                {
                    cout<<"infinity"<<endl;
                }
        }
}
