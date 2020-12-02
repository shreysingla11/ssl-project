#include<iostream>
#include<vector>
#include<queue>
#include<stdio.h>

using namespace std;

vector<vector<int> >friends,pred;
vector<int> t_vec,number_of_friends;
vector<int> temp_vec,temp_pred;
queue<int> q_go;
queue<int> q_notgo;
vector<bool> decided;

int main()
{
    //Input
    int n,t,m,temp;
    cin>>n;
    int min_num=0,max_num=n;
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&t,&m);
        t_vec.push_back(t);
        number_of_friends.push_back(m);
        if(t==0)
            q_go.push(i);
        if(t>m)
            q_notgo.push(i);
        if(t==0 ||t>m)
            decided.push_back(true);
        else
            decided.push_back(false);
        for(int j=0;j<m;j++)
        {
            scanf("%d",&temp);
            temp_vec.push_back(temp);
        }
        friends.push_back(temp_vec);
        pred.push_back(temp_pred);
        temp_vec.clear();
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<friends[i].size();j++)
            pred[friends[i][j]].push_back(i);
    }
    min_num+=q_go.size();
    max_num-=q_notgo.size();

    //Process
    while(!q_notgo.empty())
    {
        int temp1=q_notgo.front();
        for(int i=0;i<pred[temp1].size();i++)
        {
            int temp2=pred[temp1][i];
            if(!decided[temp2])
            {
                number_of_friends[temp2]--;
                if(t_vec[temp2] > number_of_friends[temp2])
                {
                    decided[temp2]=true;
                    q_notgo.push(temp2);
                    max_num--;
                }
            }
        }
        q_notgo.pop();
    }
    while(!q_go.empty())
    {
        int temp1=q_go.front();
        for(int i=0;i<pred[temp1].size();i++)
        {
            int temp2=pred[temp1][i];
            if(!decided[temp2])
            {
                t_vec[temp2]--;
                number_of_friends[temp2]--;
                if(t_vec[temp2] <= 0)
                {
                    decided[temp2]=true;
                    q_go.push(temp2);
                    min_num++;
                }
            }
        }
        q_go.pop();
    }



    //Output
    cout<<min_num<<" "<<max_num<<endl;

    return 0;
}
