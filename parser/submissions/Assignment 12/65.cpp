#include<iostream>
#include<queue>
#include<vector>

using namespace std;

queue<int>ngo;
queue<int>pgo;
int a=0;
int b=0;
class node
{
public:
    int node_no;
    int thresh;
    int total;
    int going;
    int covered;
    vector<int>friends,inverse;
    void input(int a,int b,int num)
    {
        thresh=a;
        total=b;
        node_no=num;
        if(thresh>total)
        {
            //cout<<num<<endl;
            going=0;
            //a++;
            //cout<<a<<endl;
            ngo.push(node_no);
            covered=1;
        }
        else
        {
            covered=0;
            going=-1;
        }
        if(thresh==0)
        {
            going=1;
            b++;
            pgo.push(node_no);
            covered=1;
        }

    }

};


int main()
{
    int nodes,thresh,total,n;
    cin>>nodes;
    node x[nodes];
    for(int i=0; i<nodes; i++)
    {
        cin>>thresh;
        cin>>total;
        x[i].input(thresh,total,i);
        for(int j=0; j<total; j++)
        {
            cin>>n;
            x[i].friends.push_back(n);
            x[n].inverse.push_back(i);
        }
    }
    //cout<<ngo.size()<<endl;
    //cout<<ngo[0]<<" "<<ngo[1]<<" "<<endl;
    //queue<int>::iterator it1;
    //cout<<a<<endl;
    a=ngo.size();
    while(!ngo.empty())
    {

        int num=ngo.front();
        //cout<<num<<endl;
        vector<int>::iterator it2;
        for(it2=x[num].inverse.begin(); it2!=x[num].inverse.end(); it2++)
        {
            int beta=*it2;
            //cout<<"num,beta is:"<<num<<""<<beta<<endl;
            if(x[beta].covered!=1)
            {
                //cout<<"beta thresh,total:"<<x[beta].thresh<<" "<<x[beta].total<<endl;
                x[beta].total-=1;
               // cout<<"beta thresh,total:"<<x[beta].thresh<<" "<<x[beta].total<<endl;
                if(x[beta].thresh>x[beta].total)
                {
                   // cout<<"pushed :"<<beta<<endl;
                   a++;
                    ngo.push(beta);
                    //cout<<beta<<" "<<ngo.size()<<endl;
                    x[beta].covered=1;
                }
            }
        }
        ngo.pop();

    }
    b=pgo.size();
   while(!pgo.empty())
    {
        int num=pgo.front();
        vector<int>::iterator it2;
        for(it2=x[num].inverse.begin(); it2!=x[num].inverse.end(); it2++)
        {
            int beta=*it2;
            if(x[beta].covered!=1)
            {
                x[beta].thresh-=1;
                if(x[beta].thresh==0)
                {
                    b++;
                    pgo.push(beta);
                    x[beta].covered=1;
                }
            }
        }
        pgo.pop();
    }
    //int rem=nodes-ngo.size()-pgo.size();
    cout<<b<<" "<<nodes-a<<endl;


}
