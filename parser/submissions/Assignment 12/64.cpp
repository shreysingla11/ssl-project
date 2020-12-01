#include<iostream>
#include<stdio.h>
#include<stack>
#include<queue>

using namespace std;
vector<vector<int> > li;
vector<int> t;
vector<int> n;
queue<int> f_go;
queue<int> f_not_go;
vector<int> decide;
 vector<int> tt;
int main()
{
    int N,temp_1,temp_2,count_min=0,count_max=0;
    scanf("%d",&N);
    count_max=N;
//    for(int i=0;i<N;i++)
//    {
//        li.push_back(tt);
//        decide.push_back(0);
//    }
li.resize(N,tt);
decide.resize(N,0);
    for(int i=0;i<N;i++)
    {
        scanf("%d %d",&temp_1,&temp_2);
        //  cin>>temp_1>>temp_2;
        t.push_back(temp_1);
        n.push_back(temp_2);
        if(temp_1==0)
        {
            f_go.push(i);
            count_min++;
            decide[i]=1;
        }
        else if(temp_2<temp_1)
        {
            f_not_go.push(i);
            count_max--;
            decide[i]=-1;
        }
        for(int j=0;j<temp_2;j++)
        {
            int temp;
            scanf("%d",&temp);
            li[temp].push_back(i);
        }
       // cout<<"A"<<endl;
    }
//    for(int i=0;i<N;i++)
//    {
//        for(int j=0;j<li[i].size();j++)
//            cout<<li[i][j];
//        cout<<endl;
//    }
    while(!f_not_go.empty())
    {
        int check= f_not_go.front();
        f_not_go.pop();
        for(int i=0;i<li[check].size();i++)
        {
          int k =li[check][i];
            if(decide[k]!=0)
                continue;
            else
            {
                if(n[k]<t[k]+1)
                {
                    f_not_go.push(k);
                    decide[k]=-1;
                    count_max--;
                }
                else
                {
                    n[k]--;
                }
            }
        }
    }
    while(!f_go.empty())
    {
        int check= f_go.front();
        f_go.pop();

        for(int i=0;i<li[check].size();i++)
        {
        int k =li[check][i];
            if(decide[k]!=0)
                continue;
            else
            {
                if(t[k]==1)
                {
                    f_go.push(k);
                    decide[k]=1;
                    count_min++;
                }
                else
                {
                    t[k]--;
                }
            }
        }
    }
    printf("%d %d\n",count_min,count_max);


}
