#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
using namespace std;
queue<int>s_going;
queue<int>s_not_going;
class node
{
public:
    int threshold;
    int friends;
    int going;
    int notgoing;
    bool movie;
    bool visit;
    bool visit2;
    //vector<int> front_list;
    vector<int> reverse_list;
    node()
    {
        notgoing=0;
        going=0;
        movie=true;
    }
};
int main()
{
    int n,min=0;
    cin>>n;
    int max=n;
    vector<node *>data(n);
    for(int i=0; i<n; i++)
    {
        data[i]=new node();
    }
    for(int i=0; i<n; i++)
    {
        int a,b;
        scanf("%d",&a);
        scanf("%d",&b);
        if(a==0)
        {
            s_going.push(i);
            data[i]->visit=true;
            data[i]->visit2=false;
            data[i]->movie=true;
            min++;
        }
        else if(a<b)
        {
            s_not_going.push(i);
            data[i]->visit2=true;
            data[i]->visit=false;
            data[i]->movie=false;
            //max--;
        }
        else
        {
            data[i]->visit=false;
            data[i]->visit2=false;
        }
        data[i]->threshold=a;
        data[i]->friends=b;
        data[i]->going=0;
        data[i]->movie=true;

        for(int j=0; j<b; j++)
        {
            int f;
            scanf("%d",&f);
            (data[f]->reverse_list).push_back(i);
        }
    }
    while(!s_going.empty())
    {
        int i = s_going.front();
        s_going.pop();
        int l = (data[i]->reverse_list).size();
        data[i]->visit=true;
        for(int j=0; j<l; j++)
        {
            ((data[(data[i]->reverse_list)[j]])->going)++;
            if((data[(data[i]->reverse_list)[j]])->going >= (data[(data[i]->reverse_list)[j]])->threshold)
            {
                if(data[(data[i]->reverse_list)[j]]->visit == false)
                {
                    s_going.push((data[i]->reverse_list)[j]);
                    data[(data[i]->reverse_list)[j]]->movie=true;
                    data[(data[i]->reverse_list)[j]]->visit == true;
                    min++;
                }
            }
        }
    }
    while(!s_not_going.empty())
    {
        int i = s_not_going.front();
        s_not_going.pop();
        int l = (data[i]->reverse_list).size();
        data[i]->visit2=true;
        for(int j=0; j<l; j++)
        {
            ((data[(data[i]->reverse_list)[j]])->notgoing)++;
            if(((data[(data[i]->reverse_list)[j]])->notgoing) + ((data[(data[i]->reverse_list)[j]])->threshold) > (data[(data[i]->reverse_list)[j]])->friends)
            {
                if(data[(data[i]->reverse_list)[j]]->visit2 == false)
                {
                    s_not_going.push((data[i]->reverse_list)[j]);
                    data[(data[i]->reverse_list)[j]]->movie=false;
                    data[(data[i]->reverse_list)[j]]->visit2 == true;
                    max--;
                }
            }
        }
    }
    cout<<min<<" "<<max;
}
